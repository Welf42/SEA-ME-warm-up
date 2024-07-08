#include "phonebook.h"
#include "ui_phonebook.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QIcon>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QRegularExpression>
#include <QDialogButtonBox>

AddContactDialog::AddContactDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Add Contact");

    nameEdit = new QLineEdit(this);
    nicknameEdit = new QLineEdit(this);
    phoneNumberEdit = new QLineEdit(this);

    auto layout = new QFormLayout(this);
    layout->addRow("Name:", nameEdit);
    layout->addRow("Nickname:", nicknameEdit);
    layout->addRow("Phone Number:", phoneNumberEdit);

    auto buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

Phonebook::Phonebook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Phonebook)
{
    ui->setupUi(this);

    contactModel = new QStandardItemModel(this);
    ui->listView_contact->setModel(contactModel);

    connect(ui->listView_contact, &QListView::clicked, this, &Phonebook::on_listView_contact_clicked);
    connect(ui->lineEdit_filter, &QLineEdit::textChanged, this, &Phonebook::on_lineEdit_filter_textChanged);

    QPixmap pix(":/img/img/seame.png");
    ui->label_seame->setPixmap(pix);
    int width = ui->label_seame->width();
    int height = ui->label_seame->height();
    ui->label_seame->setPixmap(pix.scaled(width, height, Qt::KeepAspectRatio));

    loadSampleContacts();
    updateContactList();
}

Phonebook::~Phonebook()
{
    delete ui;
}

void Phonebook::loadSampleContacts()
{
    addContact("John Doe", "Johnny", "1234567890", true);
    addContact("Jane Smith", "Janie", "9876543210", false);
    addContact("Alice Johnson", "Ali", "5551234567", true);
    addContact("Bob Williams", "Bobby", "4447890123", false);
    addContact("Charlie Brown", "Chuck", "7778889999", true);
}

bool Phonebook::addContact(const QString &name, const QString &nickname, const QString &number, bool isBookmarked)
{
    if (!isValidName(name)) {
        QMessageBox::warning(this, "Invalid Input", "Name must contain only alphabetic characters.");
        return false;
    }

    if (!isValidPhoneNumber(number)) {
        QMessageBox::warning(this, "Invalid Input", "Phone number must contain only digits.");
        return false;
    }

    if (isDuplicatePhoneNumber(number)) {
        QMessageBox::warning(this, "Duplicate Entry", "A contact with this phone number already exists.");
        return false;
    }

    QStandardItem *item = new QStandardItem(name);
    item->setData(nickname, Qt::UserRole);
    item->setData(number, Qt::UserRole + 1);
    item->setData(isBookmarked, Qt::UserRole + 2);
    if (isBookmarked) {
        item->setIcon(QIcon(":/img/img/star.png"));
    }
    allContacts.append(item);
    return true;
}

void Phonebook::on_pushButton_add_clicked()
{
    AddContactDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        QString nickname = dialog.getNickname();
        QString number = dialog.getPhoneNumber();

        if (addContact(name, nickname, number, false)) {
            updateContactList();
        }
    }
}

void Phonebook::on_pushButton_bookmark_clicked()
{
    QModelIndex currentIndex = ui->listView_contact->currentIndex();
    if (currentIndex.isValid()) {
        QStandardItem *item = contactModel->itemFromIndex(currentIndex);
        bool isCurrentlyBookmarked = item->data(Qt::UserRole + 2).toBool();
        updateBookmarkStatus(currentIndex, !isCurrentlyBookmarked);
    }
}

void Phonebook::on_pushButton_details_clicked()
{
    QModelIndex currentIndex = ui->listView_contact->currentIndex();
    if (currentIndex.isValid()) {
        displayContactDetails(currentIndex);
    }
}

void Phonebook::on_pushButton_remove_clicked()
{
    QModelIndex currentIndex = ui->listView_contact->currentIndex();
    if (currentIndex.isValid()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Remove Contact", "Are you sure you want to remove this contact?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            QStandardItem *item = contactModel->itemFromIndex(currentIndex);
            QStandardItem *allContactsItem = findItemInAllContacts(item);

            if (allContactsItem) {
                allContacts.removeOne(allContactsItem);
                delete allContactsItem;
            }

            contactModel->removeRow(currentIndex.row());
        }
    }
}

void Phonebook::on_pushButton_allContacts_clicked()
{
    updateContactList();
}

void Phonebook::on_pushButton_bookmarks_clicked()
{
    updateContactList(true);
}

void Phonebook::on_lineEdit_filter_textChanged(const QString &text)
{
    updateContactList(false, text);
}

void Phonebook::on_listView_contact_clicked(const QModelIndex &index)
{
    displayContactDetails(index);
}

void Phonebook::updateContactList(bool bookmarksOnly, const QString& filter)
{
    contactModel->clear();
    for (QStandardItem *item : allContacts) {
        QString name = item->text();
        bool isBookmarked = item->data(Qt::UserRole + 2).toBool();

        if ((bookmarksOnly && isBookmarked) || !bookmarksOnly) {
            if (filter.isEmpty() || name.contains(filter, Qt::CaseInsensitive)) {
                contactModel->appendRow(item->clone());
            }
        }
    }
}

void Phonebook::displayContactDetails(const QModelIndex &index)
{
    if (index.isValid()) {
        QStandardItem *item = contactModel->itemFromIndex(index);
        ui->textBrowser_name->setText(item->text());
        ui->textBrowser_nickname->setText(item->data(Qt::UserRole).toString());
        ui->textBrowser_phonenumber->setText(item->data(Qt::UserRole + 1).toString());
    }
}

void Phonebook::updateBookmarkStatus(const QModelIndex &index, bool isBookmarked)
{
    if (index.isValid()) {
        QStandardItem *item = contactModel->itemFromIndex(index);
        item->setData(isBookmarked, Qt::UserRole + 2);

        if (isBookmarked) {
            item->setIcon(QIcon(":/img/img/star.png"));
        } else {
            item->setIcon(QIcon());
        }

        // Update the corresponding item in allContacts
        QStandardItem *allContactsItem = findItemInAllContacts(item);
        if (allContactsItem) {
            allContactsItem->setData(isBookmarked, Qt::UserRole + 2);
            allContactsItem->setIcon(item->icon());
        }
    }
}

QStandardItem* Phonebook::findItemInAllContacts(const QStandardItem* item)
{
    for (QStandardItem *allItem : allContacts) {
        if (allItem->text() == item->text() &&
            allItem->data(Qt::UserRole) == item->data(Qt::UserRole) &&
            allItem->data(Qt::UserRole + 1) == item->data(Qt::UserRole + 1)) {
            return allItem;
        }
    }
    return nullptr;
}

bool Phonebook::isValidName(const QString &name) const
{
    QRegularExpression re("^[A-Za-z\\s]+$");
    return re.match(name).hasMatch();
}

bool Phonebook::isValidPhoneNumber(const QString &number) const
{
    QRegularExpression re("^\\d+$");
    return re.match(number).hasMatch();
}

bool Phonebook::isDuplicatePhoneNumber(const QString &number) const
{
    for (const QStandardItem *item : allContacts) {
        if (item->data(Qt::UserRole + 1).toString() == number) {
            return true;
        }
    }
    return false;
}

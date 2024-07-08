#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <QListView>
#include <QTextBrowser>
#include <QStandardItemModel>
#include <QDialog>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class Phonebook; }
QT_END_NAMESPACE

class AddContactDialog : public QDialog
{
    Q_OBJECT

public:
    AddContactDialog(QWidget *parent = nullptr);
    QString getName() const { return nameEdit->text(); }
    QString getNickname() const { return nicknameEdit->text(); }
    QString getPhoneNumber() const { return phoneNumberEdit->text(); }

private:
    QLineEdit *nameEdit;
    QLineEdit *nicknameEdit;
    QLineEdit *phoneNumberEdit;
};

class Phonebook : public QMainWindow
{
    Q_OBJECT

public:
    Phonebook(QWidget *parent = nullptr);
    ~Phonebook();

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_bookmark_clicked();
    void on_pushButton_details_clicked();
    void on_pushButton_remove_clicked();
    void on_pushButton_allContacts_clicked();
    void on_pushButton_bookmarks_clicked();
    void on_lineEdit_filter_textChanged(const QString &text);
    void on_listView_contact_clicked(const QModelIndex &index);

private:
    Ui::Phonebook *ui;
    QStandardItemModel *contactModel;
    QList<QStandardItem*> allContacts;

    void updateContactList(bool bookmarksOnly = false, const QString& filter = QString());
    void displayContactDetails(const QModelIndex &index);
    void updateBookmarkStatus(const QModelIndex &index, bool isBookmarked);
    void loadSampleContacts();
    bool addContact(const QString &name, const QString &nickname, const QString &number, bool isBookmarked);
    QStandardItem* findItemInAllContacts(const QStandardItem* item);
    bool isValidName(const QString &name) const;
    bool isValidPhoneNumber(const QString &number) const;
    bool isDuplicatePhoneNumber(const QString &number) const;
};

#endif // PHONEBOOK_H

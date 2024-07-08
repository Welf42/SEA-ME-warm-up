/********************************************************************************
** Form generated from reading UI file 'phonebook.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEBOOK_H
#define UI_PHONEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Phonebook
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_header;
    QSpacerItem *horizontalSpacer_header;
    QLabel *label_seame;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_commands;
    QPushButton *pushButton_add;
    QPushButton *pushButton_remove;
    QPushButton *pushButton_bookmark;
    QLabel *label_details;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QTextBrowser *textBrowser_name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_phonenumber;
    QTextBrowser *textBrowser_phonenumber;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_nickname;
    QTextBrowser *textBrowser_nickname;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_contact_list;
    QLineEdit *lineEdit_filter;
    QPushButton *pushButton_allContacts;
    QPushButton *pushButton_bookmarks;
    QListView *listView_contact;
    QPushButton *pushButton_quit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Phonebook)
    {
        if (Phonebook->objectName().isEmpty())
            Phonebook->setObjectName(QString::fromUtf8("Phonebook"));
        Phonebook->resize(800, 600);
        Phonebook->setMinimumSize(QSize(0, 100));
        centralwidget = new QWidget(Phonebook);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_header = new QLabel(centralwidget);
        label_header->setObjectName(QString::fromUtf8("label_header"));
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        label_header->setFont(font);

        horizontalLayout_2->addWidget(label_header);

        horizontalSpacer_header = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_header);

        label_seame = new QLabel(centralwidget);
        label_seame->setObjectName(QString::fromUtf8("label_seame"));
        label_seame->setMinimumSize(QSize(300, 200));
        label_seame->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(label_seame);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_commands = new QLabel(centralwidget);
        label_commands->setObjectName(QString::fromUtf8("label_commands"));
        label_commands->setMinimumSize(QSize(0, 50));
        label_commands->setBaseSize(QSize(0, 50));
        QFont font1;
        font1.setPointSize(15);
        label_commands->setFont(font1);

        verticalLayout->addWidget(label_commands);

        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        verticalLayout->addWidget(pushButton_add);

        pushButton_remove = new QPushButton(centralwidget);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));

        verticalLayout->addWidget(pushButton_remove);

        pushButton_bookmark = new QPushButton(centralwidget);
        pushButton_bookmark->setObjectName(QString::fromUtf8("pushButton_bookmark"));

        verticalLayout->addWidget(pushButton_bookmark);

        label_details = new QLabel(centralwidget);
        label_details->setObjectName(QString::fromUtf8("label_details"));
        label_details->setMinimumSize(QSize(0, 50));
        label_details->setBaseSize(QSize(0, 50));
        label_details->setFont(font1);

        verticalLayout->addWidget(label_details);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(label_name);

        textBrowser_name = new QTextBrowser(centralwidget);
        textBrowser_name->setObjectName(QString::fromUtf8("textBrowser_name"));
        textBrowser_name->setMinimumSize(QSize(0, 25));
        textBrowser_name->setMaximumSize(QSize(16777215, 30));
        textBrowser_name->setBaseSize(QSize(0, 30));

        horizontalLayout->addWidget(textBrowser_name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_phonenumber = new QLabel(centralwidget);
        label_phonenumber->setObjectName(QString::fromUtf8("label_phonenumber"));
        label_phonenumber->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(label_phonenumber);

        textBrowser_phonenumber = new QTextBrowser(centralwidget);
        textBrowser_phonenumber->setObjectName(QString::fromUtf8("textBrowser_phonenumber"));
        textBrowser_phonenumber->setMinimumSize(QSize(0, 25));
        textBrowser_phonenumber->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(textBrowser_phonenumber);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_nickname = new QLabel(centralwidget);
        label_nickname->setObjectName(QString::fromUtf8("label_nickname"));
        label_nickname->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(label_nickname);

        textBrowser_nickname = new QTextBrowser(centralwidget);
        textBrowser_nickname->setObjectName(QString::fromUtf8("textBrowser_nickname"));
        textBrowser_nickname->setMinimumSize(QSize(0, 25));
        textBrowser_nickname->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(textBrowser_nickname);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_contact_list = new QLabel(centralwidget);
        label_contact_list->setObjectName(QString::fromUtf8("label_contact_list"));
        label_contact_list->setMinimumSize(QSize(0, 50));
        label_contact_list->setBaseSize(QSize(0, 50));
        label_contact_list->setFont(font1);

        verticalLayout_4->addWidget(label_contact_list);

        lineEdit_filter = new QLineEdit(centralwidget);
        lineEdit_filter->setObjectName(QString::fromUtf8("lineEdit_filter"));
        lineEdit_filter->setAutoFillBackground(false);
        lineEdit_filter->setEchoMode(QLineEdit::Normal);
        lineEdit_filter->setClearButtonEnabled(true);

        verticalLayout_4->addWidget(lineEdit_filter);

        pushButton_allContacts = new QPushButton(centralwidget);
        pushButton_allContacts->setObjectName(QString::fromUtf8("pushButton_allContacts"));

        verticalLayout_4->addWidget(pushButton_allContacts);

        pushButton_bookmarks = new QPushButton(centralwidget);
        pushButton_bookmarks->setObjectName(QString::fromUtf8("pushButton_bookmarks"));

        verticalLayout_4->addWidget(pushButton_bookmarks);

        listView_contact = new QListView(centralwidget);
        listView_contact->setObjectName(QString::fromUtf8("listView_contact"));
        listView_contact->setMinimumSize(QSize(0, 150));

        verticalLayout_4->addWidget(listView_contact);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        pushButton_quit = new QPushButton(centralwidget);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));

        verticalLayout_2->addWidget(pushButton_quit);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_2);

        Phonebook->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Phonebook);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Phonebook->setMenuBar(menubar);
        statusbar = new QStatusBar(Phonebook);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Phonebook->setStatusBar(statusbar);

        retranslateUi(Phonebook);
        QObject::connect(pushButton_quit, &QPushButton::clicked, Phonebook, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(Phonebook);
    } // setupUi

    void retranslateUi(QMainWindow *Phonebook)
    {
        Phonebook->setWindowTitle(QCoreApplication::translate("Phonebook", "Phonebook", nullptr));
        label_header->setText(QCoreApplication::translate("Phonebook", "Phonebook", nullptr));
        label_seame->setText(QCoreApplication::translate("Phonebook", "TextLabel", nullptr));
        label_commands->setText(QCoreApplication::translate("Phonebook", "Contact commands", nullptr));
        pushButton_add->setText(QCoreApplication::translate("Phonebook", "Add", nullptr));
        pushButton_remove->setText(QCoreApplication::translate("Phonebook", "Remove", nullptr));
        pushButton_bookmark->setText(QCoreApplication::translate("Phonebook", "Bookmark", nullptr));
        label_details->setText(QCoreApplication::translate("Phonebook", "Contact details", nullptr));
        label_name->setText(QCoreApplication::translate("Phonebook", "Name                ", nullptr));
        label_phonenumber->setText(QCoreApplication::translate("Phonebook", "Phonenumber", nullptr));
        label_nickname->setText(QCoreApplication::translate("Phonebook", "Nickname        ", nullptr));
        label_contact_list->setText(QCoreApplication::translate("Phonebook", "Contact list", nullptr));
        lineEdit_filter->setInputMask(QString());
        lineEdit_filter->setText(QCoreApplication::translate("Phonebook", "Filter", nullptr));
        pushButton_allContacts->setText(QCoreApplication::translate("Phonebook", "Show All Contacts", nullptr));
        pushButton_bookmarks->setText(QCoreApplication::translate("Phonebook", "Show Bookmarks", nullptr));
        pushButton_quit->setText(QCoreApplication::translate("Phonebook", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Phonebook: public Ui_Phonebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEBOOK_H

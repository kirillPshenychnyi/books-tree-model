#include "GUI/addbookdialog.hpp"
#include <QLineEdit>
#include <QLabel>
#include <QIcon>
#include <QHBoxLayout>
AddBookDialog::AddBookDialog() : AddDialog()
{

    QLabel * author = new QLabel("&Author");
    m_authorField = new QLineEdit;
    author->setBuddy(m_authorField);

    QVBoxLayout * layout = new QVBoxLayout;

    layout->addWidget(author);
    layout->addWidget(m_authorField);

    setWindowIcon(QIcon("Book.png"));
    setWindowTitle("Add new book");
    addWidget(layout);

}

void AddBookDialog::validate() {

    AddDialog::validate();

    if(m_authorField->text().isEmpty())
    {
        sendErrorMessage();
        emit reject();
    }
    else emit accept();
}



QString AddBookDialog:: getAuthor() const {

    return m_authorField->text();
}

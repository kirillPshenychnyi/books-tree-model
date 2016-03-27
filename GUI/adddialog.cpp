#include "adddialog.hpp"
#include <QMessageBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

AddDialog::AddDialog()
{

    m_layout = new QVBoxLayout;
    QLabel * title = new QLabel("Title");
    m_titleField = new QLineEdit;
    m_layout->addWidget(title);
    m_layout->addWidget(m_titleField);

    setModal(true);

}

void AddDialog:: sendErrorMessage ()
{

    QMessageBox::critical(0, "error", "Not all fields has been field");
}


void AddDialog::addWidget(QBoxLayout *_layout)
{


    QPushButton * ok = new QPushButton("&Ok");
    QPushButton * cancel = new QPushButton("&Cancel");

    connect(ok , SIGNAL(clicked(bool)), SLOT(validate()));
    connect(cancel , SIGNAL(clicked(bool)), SLOT(reject()));

    QHBoxLayout * buttons = new QHBoxLayout;
    buttons->addWidget(ok);
    buttons->addWidget(cancel);

    m_layout->addLayout(_layout);
    m_layout->addLayout(buttons);

    setLayout(m_layout);


}

void AddDialog::validate()
{
    if(m_titleField->text().isEmpty())
    {
        sendErrorMessage();
        emit reject();
    }
    else emit accept();
}

QString AddDialog::getTitle() const {

    return m_titleField->text();

}

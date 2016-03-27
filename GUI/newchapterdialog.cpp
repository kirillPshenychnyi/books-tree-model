#include "GUI/newchapterdialog.hpp"
#include <QLabel>
#include <QSpinBox>
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QMessageBox>

NewChapterDialog::NewChapterDialog() : AddDialog()

{

    QLabel * pages = new QLabel("&Pages");
    m_pages = new QSpinBox;
    m_pages->setMinimum(1);
    pages->setBuddy(m_pages);


    QVBoxLayout * layout = new QVBoxLayout;

    layout->addWidget(pages);
    layout->addWidget(m_pages);

    setWindowIcon(QIcon("chapter.png"));
    setWindowTitle("Adding new Chapter");
    addWidget(layout);
}




int NewChapterDialog:: getPages () const
{

    return m_pages->value();

}


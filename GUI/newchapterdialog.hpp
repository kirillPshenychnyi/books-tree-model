#ifndef NEWCHAPTERDIALOG_HPP
#define NEWCHAPTERDIALOG_HPP
#include "adddialog.hpp"


class QSpinBox;
class QLineEdit;


class NewChapterDialog : public AddDialog
{

    QSpinBox * m_pages;

public:

    NewChapterDialog();

    int getPages() const ;


};

#endif // NEWCHAPTERDIALOG_HPP

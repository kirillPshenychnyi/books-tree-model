#ifndef ADDBOOKDIALOG_HPP
#define ADDBOOKDIALOG_HPP
#include "adddialog.hpp"


class QLineEdit;

class AddBookDialog : public AddDialog
{

private:

    QLineEdit * m_authorField;

public:

    AddBookDialog();

    QString getAuthor() const;

protected slots:
    void validate() override;
};

#endif // ADDBOOKDIALOG_HPP

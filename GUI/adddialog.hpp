#ifndef ADDDIALOG_HPP
#define ADDDIALOG_HPP
#include <QDialog>

class QLineEdit;
class QBoxLayout;

class AddDialog:public QDialog
{
    Q_OBJECT

    QLineEdit * m_titleField;

    QBoxLayout * m_layout;
public:

    AddDialog();

    QString getTitle () const;

    void addWidget(QBoxLayout * _widget);

    static void sendErrorMessage ();

protected slots:

    virtual void validate();
};

#endif // ADDDIALOG_HPP

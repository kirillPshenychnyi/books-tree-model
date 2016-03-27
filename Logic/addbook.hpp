#ifndef ADDBOOK_HPP
#define ADDBOOK_HPP

#include <QUndoCommand>
class Book;
class Controller;

class AddBook:public QUndoCommand
{

   Controller & m_controller;

   Book * m_book ;

public:
    AddBook(Controller & _cont, QString const & _title, QString const & _author);

    virtual void redo();

    virtual void undo();

};




#endif // INSERTACTIONS_HPP

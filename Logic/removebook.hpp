#ifndef REMOVEBOOK_HPP
#define REMOVEBOOK_HPP
#include <QUndoCommand>
#include <QModelIndex>


class Book;
class Controller;

class RemoveBook : public QUndoCommand
{
    Controller & m_controller;

    Book & m_book;

    const QModelIndex m_previousPos;

public:
    RemoveBook(Controller & _cont,  Book & _book , const QModelIndex _pos);

    void undo();

    void redo();
};

#endif // REMOVEBOOK_HPP

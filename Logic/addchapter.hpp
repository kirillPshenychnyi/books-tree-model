#ifndef ADDCHAPTER_HPP
#define ADDCHAPTER_HPP

#include <QUndoCommand>
#include <QModelIndex>

class Book;
class Chapter;
class Controller;

class AddChapter:public QUndoCommand
{
    Chapter * m_chapter;

    Controller & m_controller;

    const QModelIndex m_position;

    Book & m_book;

public:

    AddChapter(Controller & _cont, Book & _book , const QModelIndex _position, QString const & _title , int pages);

    void redo();

    void undo();

};

#endif // ADDCHAPTER_HPP

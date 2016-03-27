#ifndef REMOVECHAPTER_HPP
#define REMOVECHAPTER_HPP
#include <QModelIndex>
#include <QUndoCommand>

class Book;
class Chapter;
class Controller;

class RemoveChapter : public QUndoCommand
{
    Book & m_book;

    const Chapter & m_chapter;

    Controller & m_controller;

    const QModelIndex m_parent;

    const int m_position;

public:

    RemoveChapter(Controller &_cont, Book &_book, const Chapter &  _chapter , QModelIndex _parent , int position);

    void redo();

    void undo();

};

#endif // REMOVECHAPTER_HPP

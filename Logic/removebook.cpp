#include "Logic/removebook.hpp"
#include "Logic/controller.hpp"
#include "Logic/book.hpp"
#include "Logic/chapter.hpp"

RemoveBook::RemoveBook(Controller &_cont,  Book &_book, const QModelIndex _pos):
   m_controller(_cont),
   m_book(_book),
   m_previousPos(_pos)
{
    setText("Removing book");

}

void RemoveBook ::redo()
{
    m_controller.removeBook(m_book.getTitle(),m_previousPos.row());

}


void RemoveBook ::undo() {

    m_controller.addBook(&m_book , m_previousPos.row());

    if(m_book.getChapterAmount())
    {

        for(const auto * pChapter : m_book.getIterator())
            m_controller.addChapter(pChapter->getTitle(),m_previousPos , pChapter->getPagesAmount());
    }



}

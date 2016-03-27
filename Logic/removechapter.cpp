#include "Logic/removechapter.hpp"
#include "Logic/controller.hpp"
#include "Logic/chapter.hpp"
#include "Logic/book.hpp"

RemoveChapter::RemoveChapter(Controller & _cont, Book & _book ,
                             const Chapter & _chapter ,
                             QModelIndex _parent ,int position):
    m_book(_book),
    m_chapter (_chapter),
    m_parent(_parent),
    m_controller(_cont),
    m_position(position)

{
    setText("Chapter removed");

}

void RemoveChapter:: redo ()
{
    m_controller.removeChapter(m_parent,m_position);
    m_book.removeChapter(m_chapter.getTitle());
}


void RemoveChapter:: undo ()
{
    m_controller.addChapter(m_chapter.getTitle(), m_parent, m_chapter.getPagesAmount() ,m_position);
    m_book.addChapter( & m_chapter);
}

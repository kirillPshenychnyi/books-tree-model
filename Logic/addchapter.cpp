#include "Logic/addchapter.hpp"
#include "Logic/book.hpp"
#include "Logic/chapter.hpp"
#include "Logic/controller.hpp"

AddChapter::AddChapter(Controller & _cont, Book & _book ,const QModelIndex _position,
                       QString const & _title ,int pages):
    m_controller(_cont),
    m_position(_position),
    m_book(_book)


{
     m_chapter = new Chapter(_title , pages);
     m_book.addChapter(m_chapter);
     setText("Adding new chapter");
}

void AddChapter::redo()
{

    m_controller.addChapter(m_chapter->getTitle(),m_position, m_chapter->getPagesAmount());

}


void AddChapter::undo()
{

    m_controller.removeChapter(m_position);

}

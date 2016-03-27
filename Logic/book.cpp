#include "book.hpp"
#include "chapter.hpp"
Book::Book(const QString &_title , const QString & _author):m_title(_title), m_author(_author)
{

}

Book::~Book(){

   foreach (const Chapter * _chapter, m_chapters)
        delete _chapter;

}

const Chapter & Book::removeChapter(QString const & _title){

   return * m_chapters.take(_title);

}

void Book::addChapter(const Chapter *_chapter) {

    m_chapters.insert(_chapter->getTitle(),_chapter);

}

int Book :: getPages () const {

    int total = 0;

    foreach(const Chapter * ch,  m_chapters)
    total+= ch->getPagesAmount();

    return total;
}

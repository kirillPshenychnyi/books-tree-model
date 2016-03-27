#ifndef BOOK_HPP
#define BOOK_HPP
#include <QHash>

class Chapter;



class Book
{
    QString const m_title;

    QString const m_author;

    QHash <QString ,const Chapter * > m_chapters;

public:

    Book(QString const & _title , QString const & _author);

    Book (const Book & ) = delete;

    Book & operator = (const Book &) = delete;

    ~Book();

    void addChapter (const Chapter * _chapter);

    const Chapter & removeChapter(const QString &_title);

    QString const & getTitle () const;

    QString const & getAuthor () const;

    int getChapterAmount() const;

    int getPages () const;

    typedef QHash <QString, const Chapter * >::const_iterator ChapterIT;

    class ChaptersIterator {

        ChapterIT m_begin;

        ChapterIT m_end;

    public:

        ChaptersIterator(ChapterIT _begin , ChapterIT _end): m_begin(_begin), m_end(_end)
        {}

        ChapterIT begin ()const  {return m_begin;}

        ChapterIT end () const {return m_end;}
    };

    ChaptersIterator getIterator () const;

};


inline QString const & Book:: getTitle () const {

    return m_title;
}

inline QString const & Book::getAuthor () const {

    return m_author;
}

inline int Book :: getChapterAmount() const {

    return m_chapters.size();
}

inline Book::ChaptersIterator Book:: getIterator () const{

    return ChaptersIterator(m_chapters.begin() , m_chapters.end());

}


#endif // BOOK_HPP

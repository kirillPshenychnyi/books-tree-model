#ifndef CHAPTER_HPP
#define CHAPTER_HPP

#include <QString>

class Chapter
{
    const QString m_title;

    const int m_nPages;

public:
    Chapter(QString const & _title , int _pages);

    Chapter (const Chapter & ) = delete;

    Chapter & operator = (const Chapter &) = delete;

    int getPagesAmount() const;

    QString const & getTitle() const;

};

inline int Chapter:: getPagesAmount() const {

    return m_nPages;

}


inline QString const & Chapter :: getTitle () const {

    return m_title;

}

#endif // CHAPTER_HPP

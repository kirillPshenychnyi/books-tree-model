#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <QObject>
#include <QHash>
#include <QUndoStack>
#include <QVector>
#include <QStandardItemModel>


class Book;
class QTreeView;
class QStandardItemModel;
class QUndoView;

class Controller : public QObject

{
   Q_OBJECT

private:

    QTreeView & m_view;

    QHash <QString , Book * > m_books;

    QStandardItemModel * m_model;

    QUndoStack m_commands;

public:

    Controller(QTreeView & m_view , QUndoView & _view);

    void removeBook (const QString &_title, int row = -1);

    void addBook(Book * book , int row = -1);

    void addChapter(QString const & _title, QModelIndex const & _index, int pages, int pos = -1);

    void removeChapter(const QModelIndex & _index , int pos = -1);

private:

    int getPages (const QModelIndex & _index) const;

    void setPages (const QModelIndex & _index, int amount);

public slots:

    void addBook();

    void removeBook();

    void addChapter();

    void removeChapter();

    void undo();

    void redo();

};


#endif // CONTROLLER_HPP

#include "Logic/controller.hpp"
#include "Logic/book.hpp"
#include "Logic/chapter.hpp"
#include "GUI/addbookdialog.hpp"
#include <QTreeView>
#include "GUI/newchapterdialog.hpp"
#include "Logic/addbook.hpp"
#include "Logic/removebook.hpp"
#include "Logic/addchapter.hpp"
#include "Logic/removechapter.hpp"
#include <QUndoView>
#include <QMessageBox>

Controller:: Controller(QTreeView & _view, QUndoView & _stackView):m_view(_view)
{
    _stackView.setStack(&m_commands);
    m_model = new QStandardItemModel(0,2);

    m_model-> setHeaderData(0 , Qt::Horizontal, "Book");
    m_model-> setHeaderData(1 , Qt::Horizontal, "Pages");

    m_view.setModel(m_model);
    m_view.setEditTriggers(QAbstractItemView::NoEditTriggers);


}



void Controller::addBook(){

   AddBookDialog * dialog = new AddBookDialog;

   dialog->show();

   if(dialog->exec() == QDialog::Accepted)
  {

     QString title = dialog->getTitle();
     QString author = dialog->getAuthor();
     m_commands.push(new  AddBook( *this, title, author ));

  }

   delete dialog;
}


void Controller :: addBook(Book * book , int row)
{
    int count = m_model->rowCount();
    if(row != -1)
    {
        m_model->insertRow(row);
        m_model->setData(m_model->index(row,0),book->getTitle());
        m_model->setData(m_model->index(row,1),book->getPages());
    }

else
    {
        m_model->insertRow(count);
        m_model->setData(m_model->index(count,0),book->getTitle());
        m_model->setData(m_model->index(count,1),book->getPages());
    }


    m_books.insert(book->getTitle(), book);
}


void Controller::removeBook(QString const & _title , int row)
{
    m_books.take(_title);
    int rows = m_model->rowCount();
    (row != -1) ? m_model->removeRow(row) : m_model->removeRow(rows-1);


}


void Controller::removeBook() {

    QModelIndex index = m_view.currentIndex();
    int row = index.row();
    if(row == -1)
        return ;

    QString _title = m_model->data(index).toString();
    m_commands.push(new RemoveBook(*this, *m_books.value(_title),index));


}

void Controller::removeChapter()
{

   QModelIndex current = m_view.currentIndex();

   if(current.parent().row() == -1)
      return;

   QString title = m_model->data(current).toString();
   QModelIndex parent = current.parent();
   QString bookTitle = m_model->data(parent).toString();



   Book * book = m_books.value(bookTitle);
   Chapter const & chapter = book->removeChapter(title);

   m_commands.push(new RemoveChapter(*this, *book , chapter, parent, current.row()));

}


void Controller:: removeChapter(const QModelIndex & _index , int pos )
{
    int rows = m_model->rowCount(_index);

   if (pos == -1)
   {
      int ChapterPages = m_model->data(m_model->index(rows-1,1,_index)).toInt();
      m_model->removeRow(rows-1,_index);
      Q_ASSERT(ChapterPages);

      setPages(_index, -ChapterPages);

   }
   else
   {   int ChapterPages = m_model->data(m_model->index(pos,1,_index)).toInt();
       m_model->removeRow(pos, _index);
       setPages(_index,-ChapterPages);
   }
}


void Controller :: addChapter(QString const & _title,QModelIndex const & _index, int pages, int pos)
{
    if(!m_model->columnCount(_index))
    {
        m_model->insertColumns(0 , 2 ,_index);
    }

    if (pos != -1)
    {
        m_model->insertRow(pos, _index);
        m_model->setData(m_model->index(pos, 0, _index),_title);
        m_model->setData(m_model->index(pos,1, _index),pages);

    }
    else
    {
        int rows = m_model->rowCount(_index);
        m_model->insertRow(rows,_index);
        m_model->setData(m_model->index(rows,0,_index),_title);
        m_model->setData(m_model->index(rows,1, _index),pages);
    }


    setPages(_index,pages);
}


void Controller::addChapter(){

    QModelIndex parent = m_view.currentIndex();
    NewChapterDialog * dialog = new NewChapterDialog;
    QString bookTitle = m_model->data(parent).toString();
    Book * book = m_books.value(bookTitle);

    if(dialog->exec())
    {
        QString title = dialog->getTitle();
        int pages = dialog->getPages();
        m_commands.push(new AddChapter(*this,*book,parent, title, pages ));

    }

    delete dialog;
}


int Controller::getPages(const QModelIndex &_index) const
{
    return m_model->data (m_model->index(_index.row(),1,_index.parent())).toInt();

}

void Controller::setPages(const QModelIndex &_index, int amount)
{
    QModelIndex target = m_model->index(_index.row(),1,_index.parent());
    int current = m_model->data(target).toInt();

    current+=amount;
    m_model->setData(target,current);
}

void Controller::undo() {

    m_commands.undo();

}


void Controller::redo() {

    m_commands.redo();

}







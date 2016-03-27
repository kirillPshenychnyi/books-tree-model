#include "addbook.hpp"
#include "book.hpp"
#include "Logic/controller.hpp"
#include <qDebug>


 AddBook::AddBook(Controller & _cont, QString const & _title, QString const & _author): m_controller(_cont) {

    m_book  = new Book(_title , _author);
    setText("Adding new book");
}

 void AddBook::redo() {

    m_controller.addBook(m_book);

}

 void AddBook::undo(){

    m_controller.removeBook(m_book->getTitle());

}


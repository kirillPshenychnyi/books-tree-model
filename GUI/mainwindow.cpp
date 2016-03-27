
#include "GUI/mainwindow.hpp"
#include <QTreeView>
#include <QStandardItemModel>
#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <QHBoxLayout>
#include "Logic/controller.hpp"
#include <QUndoView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    setWindowIcon(QIcon("icon.png"));

    QMenuBar * menu = new QMenuBar;
    QTreeView * m_view = new QTreeView;

    QUndoView * _undoStack = new QUndoView;
    Controller * cont = new Controller(*m_view , * _undoStack);

    QHBoxLayout * layout= new QHBoxLayout;
    QWidget * m_central = new QWidget;

    QMenu * Book = new QMenu("Book");
    Book->addAction("Add book" , cont, SLOT(addBook()));
    Book->addAction("Remove book" , cont , SLOT(removeBook()));

    QMenu * actions = new QMenu("Actions");
    actions->addAction("Undo", cont , SLOT(undo()));
    actions->addAction("Redo", cont , SLOT(redo()));

    ChapterMenu = new QMenu("Chapter");
    ChapterMenu->addAction("Add Chapter" , cont , SLOT(addChapter()));
    ChapterMenu->addAction("Remove Chapter" , cont , SLOT(removeChapter()));
    ChapterMenu->setDisabled(true);


    menu->addMenu(Book);
    menu->addMenu(ChapterMenu);
    menu->addMenu(actions);

    connect(m_view , SIGNAL(clicked(QModelIndex)), SLOT(Enable(QModelIndex)));

    setMenuBar(menu);

    layout->addWidget(m_view);
    layout->addWidget(_undoStack);
    m_central->setLayout(layout);

    setCentralWidget(m_central);

}

void MainWindow::Enable(const QModelIndex &_index){

    static QAction * add =  ChapterMenu->actions().at(0);
    ChapterMenu->setEnabled(true);

    (_index.parent().row() == -1) ? add->setEnabled(true):
                                    add->setEnabled(false);

}




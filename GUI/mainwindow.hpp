#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>


class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:


    QMenu * ChapterMenu;


public slots:

    void Enable (const QModelIndex & _index);


};




#endif // MAINWINDOW_HPP

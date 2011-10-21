#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
    QObject::connect(this, SIGNAL(dataSetChanged(vito::DataSet::ptr)),
                     ui->datasetSelector, SLOT(displayDataset(vito::DataSet::ptr)));
    QObject::connect(this, SIGNAL(dataSetSelectionChanged(std::vector<const vito::DataPoint *>)),
                     ui->imagesdisplay, SLOT(adjustView(std::vector<const vito::DataPoint *>)));
    QPixmap *image = new QPixmap("/Users/mauricemulder/workspace/Vito/radialgrad.png");
    std::cout << "image depth: " << image->depth() << std::endl;
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsPixmapItem *it = new QGraphicsPixmapItem(*image);
}

MainWindow::~MainWindow()
{
    delete ui;
}
#include <iostream>
void MainWindow::on_actionOpen_Database_triggered()
{

}


void MainWindow::on_pushButton_clicked()
{
    on_actionOpen_Database_triggered();
}

void MainWindow::on_loadDatasetButton_clicked()
{

}
void MainWindow::promptDataSet(){
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::Directory);
    std::string ds = dialog.getExistingDirectory().toStdString();
    emit dataSetChanged(loadDataset(ds));
}

void MainWindow::on_datasetSelector_itemChanged(QTreeWidgetItem *item, int column)
{
    std::cout << "item type:" << item->type() << "endl" << std::endl;
    if(item->type() == 3)
        for(int i =0; i < item->childCount(); i++)
            item->child(i)->setCheckState(0, item->checkState(0));
    if(item->type() == 7)
        setCategoryActivity(item->parent()->text(0).toStdString(),
                            item->text(0).toStdString(),
                            item->checkState(0));
    if(item->type() == 7 || item->type() == 3)
        emit dataSetSelectionChanged(getActivePoints());
}

void MainWindow::on_datasetSelector_itemActivated(QTreeWidgetItem *item, int column)
{
    std::cout << item->text(0).toStdString() << "is the new item "  << std::endl;
}

void MainWindow::on_datasetSelector_itemClicked(QTreeWidgetItem *item, int column)
{
}



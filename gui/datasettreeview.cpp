#include "datasettreeview.h"
#include <QStandardItemModel>

#include <QTreeWidget>

#include <iostream>
#include <QPushButton>

using std::vector;
using vito::Category;

DatasetTreeView::DatasetTreeView(QWidget *parent) :
    QTreeWidget(parent)
{
}

void DatasetTreeView::displayDataset( vito::DataSet::ptr ds){
    std::cout << "in displaydset" << std::endl;
    QTreeWidgetItem *dsitem = new QTreeWidgetItem(this,3);
    dsitem->setText(0,QString::fromStdString(ds->getDataSetName()));
    dsitem->setFlags(dsitem->flags() | Qt::ItemIsUserCheckable);
    dsitem->setCheckState(0, Qt::Unchecked);
    const std::map<std::string, Category> * cats = ds->getCategories();
    for( std::map<std::string, Category>::const_iterator i = cats->begin(); i != cats->end(); ++i){
        std::cout << "aa:" << i->second.getName() << std::endl;
        QTreeWidgetItem *catitem = new QTreeWidgetItem(dsitem, 7);
        catitem->setText(0,QString::fromStdString(i->second.getName()));
        catitem->setFlags(catitem->flags() | Qt::ItemIsUserCheckable);
        catitem->setCheckState(0, Qt::Unchecked);
    }
   this->show();
}

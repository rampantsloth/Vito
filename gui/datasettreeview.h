#ifndef DATASETTREEVIEW_H
#define DATASETTREEVIEW_H

#include <QTreeWidget>
#include "DataSet.h"

class DatasetTreeView : public QTreeWidget
{
    Q_OBJECT
public:
    explicit DatasetTreeView(QWidget *parent = 0);

signals:

public slots:
    void displayDataset(vito::DataSet::ptr);


};

#endif // DATASETTREEVIEW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "VitoApplication.h"
#include <QTreeWidgetItem>
#include "DataSet.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public vito::VitoApplication
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_actionOpen_Database_triggered();
    void on_pushButton_clicked();
    void on_loadDatasetButton_clicked();

    void on_datasetSelector_itemChanged(QTreeWidgetItem *item, int column);

    void on_datasetSelector_itemActivated(QTreeWidgetItem *item, int column);

    void on_datasetSelector_itemClicked(QTreeWidgetItem *item, int column);

public slots:
    void promptDataSet();

private:
    Ui  ::MainWindow *ui;

signals:
    void dataSetChanged(vito::DataSet::ptr);
    void dataSetSelectionChanged(std::vector<const vito::DataPoint *>);
};

#endif // MAINWINDOW_H

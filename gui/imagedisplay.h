#ifndef IMAGEDISPLAY_H
#define IMAGEDISPLAY_H

#include <QWidget>
#include "DataSet.h"
#include <QGraphicsView>

class ImageDisplay : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    int page;
    int kImagePerPage;
public:
    explicit ImageDisplay(QWidget *parent = 0);
    ~ImageDisplay();

signals:

public slots:
    void adjustView(std::vector<const vito::DataPoint *> points);
};

#endif // IMAGEDISPLAY_H

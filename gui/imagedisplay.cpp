#include "imagedisplay.h"
#include <iostream>

#include <QGraphicsView>
#include <QLabel>
#include <QGridLayout>
#include <QGraphicsPixmapItem>


using std::vector;
using namespace vito;



ImageDisplay::ImageDisplay(QWidget *parent) :
    QGraphicsView(parent),
    scene(0)
{

}

ImageDisplay::~ImageDisplay(){
    if(scene) { delete scene; scene = 0;}
}

void ImageDisplay::adjustView(std::vector<const DataPoint *> points){
    std::cout << "hallo in adjustview" << std::endl;
    std::cout << points.size() << " del scene"<< std::endl;
    if(scene) {delete scene; scene = 0;}
    scene = new QGraphicsScene();
    typedef std::vector<const DataPoint *> dpvec;
    int hscale = 4; // means 4 images per row;
    int yposition = 0;
    int x = 0;
    const int width = this->width();
    const int height = this->height();
    int margin = 2;
    double square_size = (double) width / 4.0;

    for(dpvec::const_iterator i = points.begin(); i != points.end() &&
        i != points.begin() + 100; ++i){
        QPoint topleft( square_size * x,
                       yposition * square_size );
        QPoint botright( square_size * (x + 1),
                       (yposition + x)* square_size );
        QSize size(10, 10);
        QGraphicsPixmapItem *pitem= new QGraphicsPixmapItem(QPixmap(QString::fromStdString( (*i)->getURL() )));
        std::cout << "pushing back: " << pitem << std::endl;
        double scale =  (double) square_size / (double) pitem->pixmap().width();

        QTransform tr;
        tr.translate(topleft.x(),topleft.y());
        tr.scale(scale, scale);
        pitem->setTransform(tr);

        //pitem->setOffset(topleft);

        x++;
        if(x >= hscale){
            x = 0;
            yposition++;
        }
        scene->addItem(pitem);
    }
    this->setScene(scene);
}



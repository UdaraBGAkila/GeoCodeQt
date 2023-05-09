#include "widget.h"
#include "ui_widget.h"
#include "qfile.h"
#include "qexception.h"
#include "qdialog.h"
#include "qmessagebox.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{   //Below Code display a google Map
    ui->setupUi(this);

    ui->map->settings()->setAttribute( QWebEngineSettings::JavascriptEnabled, true);
    QString fileName = qApp->applicationDirPath() + "/html/map.html";
    if( !QFile(fileName).exists() ) {
        qDebug() << "File not found:" << fileName;
        QMessageBox::warning(
            this,
            tr("GeoCode"),
            tr("File not found") );
    }

    QUrl url = QUrl::fromLocalFile( fileName );
    ui->map->load(url);

    connect(ui->leftBtn, SIGNAL(clicked()), this, SLOT(goLeft()) );
    connect(ui->rightBtn, SIGNAL(clicked()), this, SLOT(goRight()) );
    connect(ui->upBtn, SIGNAL(clicked()), this, SLOT(goUp()) );
    connect(ui->downBtn, SIGNAL(clicked()), this, SLOT(goDown()) );
    connect(ui->homeBtn, SIGNAL(clicked()), this, SLOT(goHome()) );
    connect(ui->zoomInBtn,SIGNAL(clicked()),this,SLOT(zoomIn()));
    connect(ui->zoomOutBtn,SIGNAL(clicked()),this,SLOT(zoomOut()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget:: moveDxDy( qint32 dx, qint32 dy ) {
    ui->map->page()->runJavaScript(QString("map.panBy(%1, %2);").arg(dx).arg(dy) );//function to move the map
}

void Widget:: zoomFx(qint32 dz)
{
    ui->map->page()->runJavaScript(QString("map.setZoom(map.getZoom()+%1)").arg(dz));//function to zoom the map
}


void Widget::goUp(){ moveDxDy(0, -10);}

void Widget::goDown(){ moveDxDy(0, +10);}

void Widget::goLeft(){ moveDxDy(-10, 0);}

void Widget::goRight(){moveDxDy(+10, 0);}

void Widget::goHome(){ui->map->page()->runJavaScript( "map.panTo(myLatlng);" );}//gets map to the first position

void Widget::zoomIn(){

    zoomFx(1);
}

void Widget::zoomOut(){zoomFx(-1);}



void Widget::on_geocodeBtn_clicked()
{//gecoding is done here
    ui->map->settings()->setAttribute( QWebEngineSettings::JavascriptEnabled, true);
    QString fileName = qApp->applicationDirPath() + "/html/mapgeocode.html";
    if( !QFile(fileName).exists() ) {
        qDebug() << "File not found:" << fileName;
        QMessageBox::warning(
            this,
                    tr("GeoCode"),
                    tr("File not found") );

    }

    QUrl url = QUrl::fromLocalFile( fileName );
    ui->map->load(url);
}

void Widget::on_reverseGeocodeBtn_clicked()
{//reverse geocoding done here
    ui->map->settings()->setAttribute( QWebEngineSettings::JavascriptEnabled, true);
    QString fileName = qApp->applicationDirPath() + "/html/mapreversegeocode.html";
    if( !QFile(fileName).exists() ) {
        qDebug() << "File not found:" << fileName;
        QMessageBox::warning(
            this,
                    tr("GeoCode"),
                    tr("File not found") );

    }

    QUrl url = QUrl::fromLocalFile( fileName );
    ui->map->load(url);
}

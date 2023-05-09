#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWebEngineView>
#include <QWebEngineSettings>

#include <QFloat16>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


public slots:
    void goLeft();
    void goRight();
    void goUp();
    void goDown();
    void goHome();
    void zoomIn();
    void zoomOut();


private slots:
    void on_geocodeBtn_clicked();

    void on_reverseGeocodeBtn_clicked();

private:
    Ui::Widget *ui;
    void moveDxDy( qint32 dx, qint32 dy );
    void zoomFx(qint32 dz);

};

#endif // WIDGET_H

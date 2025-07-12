#include "plotter.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <algorithm>

Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{

}

void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    std::vector<double> y, t;
    int ymax, ymin;
    long tmax, tmin;
    int len = data.size();

    brush.setColor(QColor(255,255,100));
    brush.setStyle(Qt::SolidPattern);
    pen.setColor(QColor(255,0,0));
    pen.setWidth(2);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width(),height());

    if (len < 2 || time.size() < 2) {
        qDebug() << "poucos pontos";
        return;
    }

    ymax = *std::max_element(data.begin(), data.end());
    ymin = *std::min_element(data.begin(), data.end());
    tmax = time.back();
    tmin = time.front();

    qDebug() << "tmin=" << tmin << "tmax=" << tmax << "ymin=" << ymin << "ymax=" << ymax;

    if (ymax == ymin || tmax == tmin) {
        qDebug() << "escala inválida";
        return;
    }

    for (int i = 0; i < len; i++)
    {
        double x_norm = double(time[i] - tmin) / double(tmax - tmin);
        double y_norm = double(data[i] - ymin) / double(ymax - ymin);

        t.push_back(x_norm * width());
        y.push_back(height() - (y_norm * height()));
    }

    pen.setColor(QColor(0,0,255));
    painter.setPen(pen);
    for (int i = 0; i < len - 1; i++)
    {
        painter.drawLine(t[i], y[i], t[i+1], y[i+1]);
    }

    qDebug() << "plotter desenhou" << len << "pontos";
    qDebug() << "timesize=" << time.size() << " datasize=" << data.size();

}

void Plotter::setData(std::vector<long long> time, std::vector<int> data)
{
    this->time = time;
    this->data = data;
    repaint();
}

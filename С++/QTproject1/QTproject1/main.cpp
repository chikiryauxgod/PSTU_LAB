#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>

class MyGraphicsView : public QGraphicsView {
public:
    MyGraphicsView(QWidget* parent = nullptr) : QGraphicsView(parent) {
        setRenderHint(QPainter::Antialiasing);
        setWindowTitle("Перемещение точки");
        setFixedSize(400, 400);

        scene = new QGraphicsScene(this);
        setScene(scene);

        point = new QGraphicsEllipseItem(-5, -5, 10, 10);
        point->setPos(200, 200);
        point->setBrush(Qt::red);
        scene->addItem(point);
    }

protected:
    void mouseMoveEvent(QMouseEvent* event) override {
        QGraphicsView::mouseMoveEvent(event);
        QPointF pointPos = mapToScene(event->pos());
        point->setPos(pointPos);
    }

private:
    QGraphicsScene* scene;
    QGraphicsEllipseItem* point;
};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MyGraphicsView view;
    view.show();
    return a.exec();
}

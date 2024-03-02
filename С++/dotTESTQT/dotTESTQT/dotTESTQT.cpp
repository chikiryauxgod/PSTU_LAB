#include <QApplication> // Подключаем заголовочный файл QApplication для создания приложения
#include <QWidget> // Подключаем заголовочный файл QWidget для создания пользовательского виджета
#include <QGraphicsScene> // Подключаем заголовочный файл QGraphicsScene для работы с графической сценой
#include <QGraphicsView> // Подключаем заголовочный файл QGraphicsView для отображения графической сцены
#include <QGraphicsEllipseItem> // Подключаем заголовочный файл QGraphicsEllipseItem для создания эллипса
#include <QGraphicsLineItem> // Подключаем заголовочный файл QGraphicsLineItem для создания линии
#include <QLineEdit> // Подключаем заголовочный файл QLineEdit для создания поля ввода
#include <QPushButton> // Подключаем заголовочный файл QPushButton для создания кнопки
#include <QVBoxLayout> // Подключаем заголовочный файл QVBoxLayout для управления вертикальным расположением виджетов
#include <QLabel> // Подключаем заголовочный файл QLabel для отображения текста
#include <QMatrix3x3> // Подключаем заголовочный файл QMatrix3x3 для работы с матрицами 3x3
#include <QVector3D> // Подключаем заголовочный файл QVector3D для работы с трехмерными векторами
#include <qmath.h> // Подключаем заголовочный файл qmath.h для математических операций

class PointWidget : public QWidget { // Объявляем пользовательский виджет PointWidget, который наследуется от QWidget
public:
    PointWidget(QWidget *parent = nullptr) : QWidget(parent) { // Конструктор класса PointWidget с параметром parent, который по умолчанию равен nullptr
        setFixedSize(1080, 1080); // Устанавливаем фиксированный размер виджета

        scene = new QGraphicsScene(this); // Создаем новую графическую сцену и привязываем ее к текущему виджету
        scene->setSceneRect(-540, -540, 1080, 1080); // Устанавливаем прямоугольную область графической сцены

        QGraphicsLineItem *xAxis = new QGraphicsLineItem(-540, 0, 540, 0); // Создаем ось X
        QGraphicsLineItem *yAxis = new QGraphicsLineItem(0, -540, 0, 540); // Создаем ось Y
        xAxis->setPen(QPen(Qt::black, 2)); // Устанавливаем перо для отрисовки оси X
        yAxis->setPen(QPen(Qt::black, 2)); // Устанавливаем перо для отрисовки оси Y
        scene->addItem(xAxis); // Добавляем ось X на графическую сцену
        scene->addItem(yAxis); // Добавляем ось Y на графическую сцену

        view = new QGraphicsView(scene, this); // Создаем вид для отображения графической сцены и привязываем его к текущему виджету
        view->setFixedSize(1080, 1080); // Устанавливаем фиксированный размер виджета отображения

        point = new QGraphicsEllipseItem(-5, -5, 10, 10); // Создаем точку (эллипс)
        point->setBrush(Qt::red); // Устанавливаем кисть точки в красный цвет
        scene->addItem(point); // Добавляем точку на графическую сцену

        coordinatesLabel = new QLabel(this); // Создаем метку для отображения координат и привязываем ее к текущему виджету
        coordinatesLabel->setGeometry(10, 10, 200, 20); // Устанавливаем геометрию метки
        coordinatesLabel->setText("X: 0, Y: 0"); // Устанавливаем начальный текст метки

        yEdit =

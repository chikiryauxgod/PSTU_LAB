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

        yEdit = new QLineEdit(this); // Создаем поле ввода для координаты Y и привязываем его к текущему виджету
        xEdit = new QLineEdit(this); // Создаем поле ввода для координаты X и привязываем его к текущему виджету
        QPushButton *moveButton = new QPushButton("Move Point", this); // Создаем кнопку для перемещения точки и привязываем ее к текущему виджету

        QVBoxLayout *layout = new QVBoxLayout(this); // Создаем вертикальный компоновщик и привязываем его к текущему виджету
        layout->addWidget(yEdit); // Добавляем поле ввода координаты Y в компоновщик
        layout->addWidget(xEdit); // Добавляем поле ввода координаты X в компоновщик
        layout->addWidget(moveButton); // Добавляем кнопку перемещения точки в компоновщик
        layout->addWidget(coordinatesLabel); // Добавляем метку с координатами в компоновщик
        layout->addWidget(view); // Добавляем вид для отображения графической сцены в компоновщик

        connect(moveButton, &QPushButton::clicked, this, &PointWidget::movePoint); // Соединяем сигнал нажатия кнопки со слотом перемещения точки
    }

private slots:
    void movePoint() { // Слот для перемещения точки
        qreal y = -yEdit->text().toDouble(); // Получаем координату Y из поля ввода и изменяем знак для корректного отображения на экране
        qreal x = xEdit->text().toDouble(); // Получаем координату X из поля ввода

        QMatrix3x3 rotationMatrix = calculateRotationMatrix(270, k, n, l); // Вычисляем матрицу поворота для заданного угла

        QVector3D transformedPoint = multiplyMatrixVector(rotationMatrix, QVector3D(x, y, 1)); // Перемножаем матрицу поворота и вектор координат точки

        point->setPos(transformedPoint.x(), transformedPoint.y()); // Устанавливаем новое положение точки на графической сцене

        coordinatesLabel->setText(QString("X: %1, Y: %2").arg(transformedPoint.x()).arg(transformedPoint.y())); // Обновляем текст метки с текущими координатами точки
    }

private:
    QGraphicsScene *scene; // Графическая сцена
    QGraphicsView *view; // Вид для отображения графической сцены
    QGraphicsEllipseItem *point; // Точка (эллипс)
    QLineEdit *xEdit; // Поле ввода для координаты X
    QLineEdit *yEdit; // Поле ввода для координаты Y
    QLabel *coordinatesLabel; // Метка для отображения координат
    qreal k = 0.0; // Параметр матрицы поворота
    qreal n = 0.0; // Параметр матрицы поворота
    qreal l = 1.0; // Параметр матрицы поворота

    QMatrix3x3 calculateRotationMatrix(qreal angleDegrees, qreal k, qreal n, qreal l) { // Функция для вычисления матрицы поворота
        qreal radians = qDegreesToRadians(angleDegrees); // Переводим угол из градусов в радианы

        QMatrix3x3 rotationMatrix; // Создаем матрицу поворота
        rotationMatrix(0, 0) = qCos(radians) + k; // Заполняем элементы матрицы
        rotationMatrix(0, 1) = qSin(radians) + n;
        rotationMatrix(0, 2) = 0;
        rotationMatrix(1, 0) = -qSin(radians);
        rotationMatrix(1, 1) = qCos(radians);
        rotationMatrix(1, 2) = 0;
        rotationMatrix(2, 0) = l * qCos(radians) + k;
        rotationMatrix(2, 1) = l * qSin(radians) + n;
        rotationMatrix(2, 2) = 1;

        return rotationMatrix; // Возвращаем полученную матрицу
    }

    QVector3D multiplyMatrixVector(const QMatrix3x3 &matrix, const QVector3D &vector) { // Функция для умножения матрицы на вектор
        qreal x = matrix(0, 0) * vector.x() + matrix(0, 1) * vector.y() + matrix(0, 2) * vector.z(); // Вычисляем новые координаты
        qreal y = matrix(1, 0) * vector.x() + matrix(1, 1) * vector.y() + matrix(1, 2) * vector.z();
        qreal z = matrix(2, 0) * vector.x() + matrix(2, 1) * vector.y() + matrix(2, 2) * vector.z();
        return QVector3D(x, y, z); // Возвращаем новый вектор
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Создаем объект приложения
    PointWidget w; // Создаем экземпля

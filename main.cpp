#include <iostream>
#include <chrono>
#include <limits>


#include "Tests/PtrWrapperTest.h"
#include "Tests/DynamicArrayTest.h"
#include "Tests/SequenceTest.h"
#include "Tests/ComparatorTest.h"
#include "Tests/SortersTest.h"

#include "Utility/Sequence.h"
#include "Utility/ProductClass.h"
#include "Utility/Generator.h"


#include "Sort/QuickSorter.h"
#include "Sort/ShellSorterHib.h"
#include "Sort/Comparator.h"

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QStackedWidget>
#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QLineEdit>
#include <QIntValidator>
#include <QComboBox>


/*
#include <qapplication.h>
//#include <qapplicationstatic.h>
#include <qwidget.h>
#include <qpushbutton.h>
#include <QVBoxLayout>
#include <qmessagebox.h>
#include <qstackedwidget.h>
#include <qmainwindow.h>
#include <qlabel.h>
#include <qfiledialog.h>
#include <qlineedit.h>
*/

/*
#include <iostream>
#include <chrono>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QStackedWidget>
#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QLineEdit>
*/



QString filePath;


ISorter<Product>* ptrSorter;

int (*cmp)(const Product&, const Product&);

QuickSorter<Product> quickSorter;
ShellSorterHib<Product> shellSorter;
int cnt = 16;


void runAllTests() {
    UsualProductCompareTest();
    DynamicArrayTest();
    PtrWrapperTest();
    ArraySequenceTest();
    SortersWorkTest();
}

void thirdBtnClick() {
    QMessageBox msgBox;
    runAllTests();
    msgBox.setText("Успешно выполнены");
    msgBox.exec();
}

QWidget* createFirstWindow(QStackedWidget* stackedWidget) {
    QWidget* widget = new QWidget;

    widget->setWindowTitle("SecondLab");
    widget->setMinimumWidth(450);
    widget->setMinimumHeight(300);

    auto* layout = new QVBoxLayout(widget);

    auto* btn1 = new QPushButton("Сортировка файла", widget);
    auto* btn2 = new QPushButton("Генератор файла", widget);
    auto* btn3 = new QPushButton("Запустить тесты", widget);
    auto* btn4 = new QPushButton("Кликер", widget);

    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    layout->addWidget(btn4);

    widget->setStyleSheet(R"(
        QWidget {
            background-color: lightGray; 
        }
        QPushButton {
            background-color: #2e7d32;  
            color: white;               
            border: 2px solid #1b5e20;  
            padding: 20px 40px;         
            font-size: 16px;            
            border-radius: 5px;         
        }
        QPushButton:hover {
            background-color: #388e3c;  
        }
        QPushButton:pressed {
            background-color: #1b5e20;  
        }
    )");

    QObject::connect(btn1, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(1); });
    QObject::connect(btn2, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(2); });
    QObject::connect(btn3, &QPushButton::clicked, thirdBtnClick);
    QObject::connect(btn4, &QPushButton::clicked, [btn4]() mutable {
        static int cnt = 0;
        btn4->setText(QString::number(++cnt));
    });

    return widget;
}



QWidget* createSecondWindow(QStackedWidget* stackedWidget) {
    QWidget* widget = new QWidget;
    widget->setMinimumWidth(450);
    widget->setMinimumHeight(300);

    auto* layout = new QVBoxLayout(widget);
    auto* label = new QLabel("Сортировка файлов", widget);
    label->setAlignment(Qt::AlignHCenter);

    auto* fileLabel = new QLabel("Файл не выбран", widget);
    fileLabel->setStyleSheet("color: green; font-size: 14px;");
    fileLabel->setWordWrap(true);

    auto* sortComboBox = new QComboBox(widget);
    sortComboBox->addItem("Quick sort");
    sortComboBox->addItem("Shell sort");

    auto* compareFuncComboBox = new QComboBox(widget);
    compareFuncComboBox->addItem("По имени продукта (алф)");
    compareFuncComboBox->addItem("По имени ведущего (алф)");
    compareFuncComboBox->addItem("Страна производитель (алф)");
    compareFuncComboBox->addItem("Город производства (алф)");
    compareFuncComboBox->addItem("email магазина (алф)");
    compareFuncComboBox->addItem("Основная торговая площадка (алф)");
    compareFuncComboBox->addItem("Время доставки (возр)");
    compareFuncComboBox->addItem("Оставшиеся копии (возр)");
    compareFuncComboBox->addItem("Проданные копии (возр)");
    compareFuncComboBox->addItem("Длительность трансляции (возр)");
    compareFuncComboBox->addItem("Скидка (возр)");
    compareFuncComboBox->addItem("Длительность скидки (возр)");
    compareFuncComboBox->addItem("Рейтинг продукта (возр)");
    compareFuncComboBox->addItem("Цена (возр)");

    auto* btn1 = new QPushButton("Сортировка", widget);
    auto* returnBtn = new QPushButton("Назад", widget);
    auto* fileBtn = new QPushButton("Выбрать файл", widget);

    layout->addWidget(label);
    layout->addWidget(fileLabel);
    layout->addWidget(fileBtn);
    layout->addWidget(sortComboBox);
    layout->addWidget(compareFuncComboBox);
    layout->addWidget(btn1);
    layout->addWidget(returnBtn);

    QObject::connect(btn1, &QPushButton::clicked, [=]() {
        if (filePath.isEmpty() || filePath == "") {
            QMessageBox::warning(widget, "Ошибка", "Неверный файл!");
            return;
        }

        QString sortMethod = sortComboBox->currentText();
        QString compareFunc = compareFuncComboBox->currentText();

        if (sortMethod == "Quick sort") {
            ptrSorter = &quickSorter;
        } else {
            ptrSorter = &shellSorter;
        }

        if (compareFunc == "По имени продукта (алф)") {
            cmp = ProductNameCompareFunc;
        } 
        else if (compareFunc == "По имени ведущего (алф)") {
            cmp = ShowHostCompareFunc;
        } else {
            cmp = DeliveryTimeCompareFunc;
        }

        ArraySequence<Product> arr;
        LoadProductsFromFile(filePath.toStdString(), arr);

        ptrSorter->Sort(arr, cmp);
        SaveProductsToFile(filePath.toStdString(), arr);

        // Здесь можно реализовать логику сортировки, основываясь на выбранных значениях.
        // Например:
        QMessageBox::information(widget, "Сортировка", 
            QString("Файл отсортирован!\nМетод сортировки: %1\nФункция сравнения: %2")
            .arg(sortMethod, compareFunc));
    });

    QObject::connect(returnBtn, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(0); });

    QObject::connect(fileBtn, &QPushButton::clicked, [=]() {
        filePath = QFileDialog::getOpenFileName(widget, "Выбор файла");
        fileLabel->setText(filePath.isEmpty() ? "Файл не выбран" : filePath);
    });

    return widget;
}


/*
QWidget* createSecondWindow(QStackedWidget* stackedWidget) {
    QWidget* widget = new QWidget;
    widget->setMinimumWidth(450);
    widget->setMinimumHeight(300);

    auto* layout = new QVBoxLayout(widget);
    auto* label = new QLabel("Генерация файлов", widget);
    label->setAlignment(Qt::AlignHCenter);

    auto* fileLabel = new QLabel("Файл не выбран", widget);
    fileLabel->setStyleSheet("color: green; font-size: 14px;");
    fileLabel->setWordWrap(true);

    auto* btn1 = new QPushButton("Сортировка", widget);
    auto* returnBtn = new QPushButton("Назад", widget);
    auto* fileBtn = new QPushButton("Выбрать файл", widget);


    layout->addWidget(label);
    layout->addWidget(fileLabel);
    layout->addWidget(fileBtn);
    layout->addWidget(btn1);
    layout->addWidget(returnBtn);

    QObject::connect(btn1, &QPushButton::clicked, [=]() {
        if (filePath.isEmpty() || filePath == "") {
            QMessageBox::warning(widget, "Ошибка", "Неверный файл!");
            return;
        }

        QMessageBox::information(widget, "Генератор", "Файл отсортирован!");

    });

    QObject::connect(returnBtn, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(0); });

    QObject::connect(fileBtn, &QPushButton::clicked, [=]() {
        filePath = QFileDialog::getOpenFileName(widget, "Выбор файла");
        fileLabel->setText(filePath.isEmpty() ? "Файл не выбран" : filePath);
    });

    return widget;
}
*/

QWidget* createThirdWindow(QStackedWidget* stackedWidget) {
    QWidget* widget = new QWidget;
    widget->setMinimumWidth(450);
    widget->setMinimumHeight(300);

    auto* layout = new QVBoxLayout(widget);
    auto* label = new QLabel("Генерация файлов", widget);
    label->setAlignment(Qt::AlignHCenter);

    auto* fileLabel = new QLabel("Файл не выбран", widget);
    fileLabel->setStyleSheet("color: green; font-size: 14px;");
    fileLabel->setWordWrap(true);

    auto* btn1 = new QPushButton("Генерация", widget);
    auto* returnBtn = new QPushButton("Назад", widget);
    auto* fileBtn = new QPushButton("Выбрать файл", widget);

    auto* numberInput = new QLineEdit(widget);
    numberInput->setPlaceholderText("Число генерируемых объектов");
    numberInput->setValidator(new QIntValidator(1, INT_MAX, numberInput));
    numberInput->setStyleSheet("font-size: 14px;");

    layout->addWidget(label);
    layout->addWidget(fileLabel);
    layout->addWidget(fileBtn);
    layout->addWidget(numberInput);
    layout->addWidget(btn1);
    layout->addWidget(returnBtn);

    QObject::connect(btn1, &QPushButton::clicked, [=]() {
        // Проверяем введенное число
        bool ok;
        int number = numberInput->text().toInt(&ok);

        if (!ok || number <= 0) {
            QMessageBox::warning(widget, "Ошибка", "Введите положительное число!");
            return;
        }

        if (number > 10000000) {
            QMessageBox::warning(widget, "Ошибка", "Слишком большое число!");
            return;
        }

        if (filePath.isEmpty() || filePath == "") {
            QMessageBox::warning(widget, "Ошибка", "Неверный файл!");
            return;
        }

        GenerateFileProduct(filePath.toStdString(), number);
        QMessageBox::information(widget, "Генератор", "Файл создан!");

    });

    QObject::connect(returnBtn, &QPushButton::clicked, [=]() { stackedWidget->setCurrentIndex(0); });

    QObject::connect(fileBtn, &QPushButton::clicked, [=]() {
        filePath = QFileDialog::getOpenFileName(widget, "Выбор файла");
        fileLabel->setText(filePath.isEmpty() ? "Файл не выбран" : filePath);
    });

    return widget;
}

int main(int argc, char* argv[]) {
    try {
        QApplication app(argc, argv);

        auto* mainWindow = new QWidget;
        auto* stackedWidget = new QStackedWidget(mainWindow);

        stackedWidget->addWidget(createFirstWindow(stackedWidget));
        stackedWidget->addWidget(createSecondWindow(stackedWidget));
        stackedWidget->addWidget(createThirdWindow(stackedWidget));

        auto* mainLayout = new QVBoxLayout(mainWindow);
        mainLayout->addWidget(stackedWidget);

        mainWindow->setLayout(mainLayout);
        mainWindow->resize(450, 300);
        mainWindow->show();

        return app.exec();
    } catch (const std::exception& ex) {
        qCritical() << "Exception: " << ex.what();
        return -1;
    } catch (...) {
        qCritical() << "Unknown exception occurred!";
        return -1;
    }
}



/*
const unsigned int cnt = 1000000;
int main() {
    const std::string filename = "random_products_1.txt";
    const std::string filename_2 = "sorted_product.txt";
    try {

        SortersWorkTest();

        GenerateFileProduct(filename, cnt);
        auto begin = std::chrono::steady_clock::now();

        ArraySequence<Product> a(cnt);
        QuickSorter<Product> sorter;

        LoadProductsFromFile(filename, a);
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "The time: " << elapsed_ms.count() << " ms\n";


        begin = std::chrono::steady_clock::now();
        sorter.Sort(a, DurationCompareFunc);

        end = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "The time: " << elapsed_ms.count() << " ms\n";
        
        begin = std::chrono::steady_clock::now();

        SaveProductsToFile(filename_2, a);

        end = std::chrono::steady_clock::now();
        elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << "The time: " << elapsed_ms.count() << " ms\n";

        

    } catch(...) {
        exit(1);
    }
    return 0;
}

*/
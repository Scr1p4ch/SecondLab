#include <iostream>
#include <chrono>

#include "out/build/default/SecondLabCmake_autogen/include/main.moc"

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

//#include <QApplication>
//#include <QPushButton>
//#include <QVBoxLayout>
//#include <QWidget>

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

/*class MainWindow : public QWidget {
public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Тесты функций");
        auto *layout = new QVBoxLayout(this);

        // Создание кнопок
        auto *btnPtrWrapperTest = new QPushButton("Запустить PtrWrapperTest", this);
        auto *btnArraySequenceTest = new QPushButton("Запустить ArraySequenceTest", this);
        auto *btnSortersWorkTest = new QPushButton("Запустить SortersWorkTest", this);
        auto *btnUsualProductCompareTest = new QPushButton("Запустить UsualProductCompareTest", this);
        auto *btnDynamicArrayTest = new QPushButton("Запустить DynamicArrayTest", this);

        // Подключение кнопок к функциям
        connect(btnPtrWrapperTest, &QPushButton::clicked, []() { PtrWrapperTest(); });
        connect(btnArraySequenceTest, &QPushButton::clicked, []() { ArraySequenceTest(); });
        connect(btnSortersWorkTest, &QPushButton::clicked, []() { SortersWorkTest(); });
        connect(btnUsualProductCompareTest, &QPushButton::clicked, []() { UsualProductCompareTest(); });
        connect(btnDynamicArrayTest, &QPushButton::clicked, []() { DynamicArrayTest(); });

        // Добавление кнопок в макет
        layout->addWidget(btnPtrWrapperTest);
        layout->addWidget(btnArraySequenceTest);
        layout->addWidget(btnSortersWorkTest);
        layout->addWidget(btnUsualProductCompareTest);
        layout->addWidget(btnDynamicArrayTest);

        // Установка макета
        setLayout(layout);
        resize(300, 250);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
*/

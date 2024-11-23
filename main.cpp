#include <iostream>
#include <chrono>

#include "Tests/PtrWrapperTest.h"
#include "Tests/DynamicArrayTest.h"
#include "Tests/SequenceTest.h"
#include "Tests/ComparatorTest.h"
#include "Utility/Sequence.h"
#include "Utility/ProductClass.h"
#include "Utility/Generator.h"


#include "Sort/QuickSorter.h"
#include "Sort/ShellSorterHib.h"
#include "Sort/Comparator.h"

const unsigned int cnt = 2000;


int main() {

    DynamicArrayTest();
    PtrWrapperConstructTest();
    ArraySequenceTest();
    UsualProductCompareTest();

    const std::string filename = "test200.csv";
    const std::string filename_2 = "sorted_product.csv";

    try {

        using Time = std::chrono::time_point<std::chrono::high_resolution_clock>;
        using Diff = std::chrono::milliseconds;


        Time t1 = std::chrono::high_resolution_clock::now();

        GenerateFileProduct(filename, cnt);
        ArraySequence<Product> a(cnt);
        ShellSorterHib<Product> sorter;

        LoadProductsFromFile(filename, a);
       
        sorter.Sort(&a, DurationCompareFunc);
        
        SaveProductsToFile(filename_2, a);

        Time t2 = std::chrono::high_resolution_clock::now();
        Diff diff = std::chrono::duration_cast<Diff>(t2 - t1);
        std::cout << diff.count() << " ms" << std::endl;

    } catch(...) {
        exit(1);
    }

    return 0;
}
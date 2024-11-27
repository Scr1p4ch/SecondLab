#ifndef _TESTS_SORTERTEST_H_
#define _TESTS_SORTERTEST_H_

#include <string>
#include <assert.h>

#include "../Utility/Generator.h"
#include "../Utility/ProductClass.h"
#include "../Sort/Comparator.h"
#include "../Sort/QuickSorter.h"
#include "../Sort/ShellSorterHib.h"



void QuickSortTest(unsigned int cnt) {
    const std::string filename = "TestQuick" + std::to_string(cnt) + ".csv";
    const std::string filename_2 = "SortedTestQuick" + std::to_string(cnt) + ".csv";

    GenerateFileProduct(filename, cnt);
    ArraySequence<Product> a(cnt);
    QuickSorter<Product> sorter;
    LoadProductsFromFile(filename, a);
       
    sorter.Sort(a, DurationCompareFunc);
        
    SaveProductsToFile(filename_2, a);
}

void ShellSortTest(unsigned int cnt) {
    const std::string filename = "TestShell" + std::to_string(cnt) + ".csv";
    const std::string filename_2 = "SortedTestShell" + std::to_string(cnt) + ".csv";

    GenerateFileProduct(filename, cnt);
    ArraySequence<Product> a(cnt);
    ShellSorterHib<Product> sorter;
    LoadProductsFromFile(filename, a);
       
    sorter.Sort(a, DurationCompareFunc);
        
    SaveProductsToFile(filename_2, a);
}

void SortersWorkTest() {
    const std::string filename = "TestQuickWork" + std::to_string(200) + ".csv";
    const std::string filename_2 = "TestShellWork" + std::to_string(200) + ".csv";

    GenerateFileProduct(filename, 200);
    GenerateFileProduct(filename_2, 200);

    ArraySequence<Product> a(200);
    ArraySequence<Product> b(200);

    QuickSorter<Product> sorter_1;
    ShellSorterHib<Product> sorter_2;
    
    LoadProductsFromFile(filename, a);
    LoadProductsFromFile(filename_2, b);
       
    sorter_1.Sort(a, DurationCompareFunc);
    sorter_2.Sort(b, DurationCompareFunc);


    for (int i = 0; i < 199; ++i) {
        assert(DurationCompareFunc(a[i], a[i + 1]) != 1);
        assert(DurationCompareFunc(b[i], b[i + 1]) != 1);
    }   

    SaveProductsToFile("sorted" + filename, a);
    SaveProductsToFile("sorted" + filename_2, b);
    
}

#endif
#include <iostream>

#include "Tests/PtrWrapperTest.h"
#include "Tests/DynamicArrayTest.h"
#include "Tests/SequenceTest.h"
#include "Utility/Sequence.h"
#include "Utility/ProductClass.h"
#include "Utility/Generator.h"

#include "Sort/QuickSorter.h"
#include "Sort/Comparator.h"

const unsigned int cnt = 20000;


int main() {

    const std::string filename = "random_products_1.txt";
    const std::string filename_2 = "sorted_product.csv";

    try {

        GenerateFileProduct(filename, cnt);
        ArraySequence<Product> a(cnt);
        QuickSorter<Product> sorter;

        LoadProductsFromFile(filename, a);
        sorter.Sort(&a, SoldCopCompareFunc);

        SaveProductsToFile(filename_2, a, FileFormat::CSV);

    } catch(...) {
        exit(1);
    }

    return 0;
}
#include <iostream>
#include <chrono>

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

int main() {

    DynamicArrayTest();
    PtrWrapperConstructTest();
    ArraySequenceTest();
    UsualProductCompareTest();

    //SortersWorkTest();

    

    

    return 0;
}
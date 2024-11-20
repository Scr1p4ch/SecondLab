#include "Utility/ProductClass.h"

void SaveProductsToFile(const std::string& filename, ArraySequence<Product>& products, FileFormat format) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    for (int i = 0; i < products.getSize(); ++i) {
        Serialize(products[i], outFile, format);
    }

    outFile.close();
}

void LoadProductsFromFile(const std::string & filename, ArraySequence<Product>& products, FileFormat format) {
    std::ifstream inFile(filename);

    if (!inFile) {
        throw std::ios_base::failure("Failed to open file for reading");
    }

    Product tmp;
    std::string delimiter;
    
    while (true) {
        Deserialize(tmp, inFile, format);
        
        if (!inFile) break;
        products.append(tmp);
    }

    inFile.close();

}
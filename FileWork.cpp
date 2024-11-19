#include "Utility/ProductClass.h"

void SaveProductsToFile(const std::string& filename, ArraySequence<Product>& products) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    for (int i = 0; i < products.getSize(); ++i) {
        products[i].Serialize(outFile);
    }

    outFile.close();
}

void LoadProductsFromFile(const std::string & filename, ArraySequence<Product>& products) {
    std::ifstream inFile(filename);

    if (!inFile) {
        throw std::ios_base::failure("Failed to open file for reading");
    }

    Product tmp;
    std::string delimiter;
    
    while (true) {
        tmp.Deserialize(inFile);
        
        if (!inFile) break;

        std::getline(inFile, delimiter);
        if (delimiter != "===" && !inFile.eof()) {
            throw std::runtime_error("Invalid file format");
        }

        products.append(tmp);
    }

    inFile.close();

}
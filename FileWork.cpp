#include "Utility/ProductClass.h"

void SaveProductsToFile(const std::string& filename, ArraySequence<Product>& products) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    size_t idx = filename.find('.');
    std::string form = filename.substr(idx + 1);

    FileFormat format;

    if ("txt" == form) {
        format = FileFormat::TXT;
    } 
    else if ("csv" == form) {
        format = FileFormat::CSV;
        outFile << "name,shopHost,countryOfFactory,shopCountry,shopCity,emailOfShop,mainMarketplace,deliveryTimeDays,copLeft,soldCopK,durationOfStream,sale,daysOfSale,rating,priceInDollars\n";
    } else {
        throw std::invalid_argument("Invalid File Format");
    }
    
    for (int i = 0; i < products.getSize(); ++i) {
        Serialize(products[i], outFile, format);
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

    size_t idx = filename.find('.');
    std::string form = filename.substr(idx + 1);

    FileFormat format;

    if ("txt" == form) {
        format = FileFormat::TXT;
    } 
    else if ("csv" == form) {
        format = FileFormat::CSV;
        inFile.ignore(300, '\n');
    } else {
        throw std::invalid_argument("Invalid File Format");
    }

    

    while (true) {
        Deserialize(tmp, inFile, format);
        
        if (!inFile) break;
        products.append(tmp);
    }

    inFile.close();

}
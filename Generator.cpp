#include <ctime>

#include "Utility/ProductClass.h"
#include "Utility/Glossary.h"

enum class FileFormat;


void GenerateFileProduct(const std::string& filename,const int & cnt, const FileFormat format) {
    std::ofstream outFile(filename);

    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    std::srand(std::time(nullptr));

    std::string name, productCountry, productHost;
    double soldCopK;
    unsigned int duration, sale;

    for (int i = 0; i < cnt; ++i) {
        name = name_1[std::rand() % 10] + name_2[std::rand() % 10];
        productCountry = country[std::rand() % 5];
        productHost = host[std::rand() % 6];
        soldCopK = 50.0 + static_cast<double>(std::rand() & 9901) + static_cast<double>(std::rand() % 100) / 100;
        duration = 30 + std::rand() % 150;
        sale = std::rand() % 20;

        Product a(name, productCountry, productHost, soldCopK, duration, sale);
        Serialize(a, outFile, format);
    }

    outFile.close();
}
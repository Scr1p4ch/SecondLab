#include <ctime>

#include "Utility/ProductClass.h"
#include "Utility/Glossary.h"

enum class FileFormat : short;


void GenerateFileProduct(const std::string& filename,const int & cnt) {
    std::ofstream outFile(filename);

    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    std::srand(std::time(nullptr));

    std::string name, showHost, countryOfFactory, shopCountry, shopCity, emailOfShop, mainMarketplace;
    double soldCopK, rating, priceInDollars;
    unsigned int deliveryTimeDays, copLeft, durationOfStream, sale, daysOfSale;
    unsigned int country_idx;

    size_t idx = filename.find('.');
    std::string form = filename.substr(idx + 1);

    FileFormat format;

    if ("txt" == form) {
        format = FileFormat::TXT;
    } 
    else if ("csv" == form) {
        format = FileFormat::CSV;
        outFile << "name,shopHost,countryOfFactory,shopCountry,shopCity,emailOfShop,mainMarketplace,deliveryTimeDays," << 
        "copLeft,soldCopK,durationOfStream,sale,daysOfSale,rating,priceInDollars\n";
    } else {
        throw std::invalid_argument("Invalid File Format");
    }


    for (int i = 0; i < cnt; ++i) {
        name = name_1[std::rand() % 10] + name_2[std::rand() % 10];
        showHost = host[std::rand() % 6];
        countryOfFactory = country[std::rand() % 5];

        country_idx = std::rand() % 8;
        shopCountry = country[country_idx];
        shopCity =cities[country_idx][std::rand() % 5];

        emailOfShop = mailNames[std::rand() % 16] + mail[std::rand() % 8];

        mainMarketplace = marketplace[std::rand() % 11];


        deliveryTimeDays = 14 + std::rand() % 60;
        copLeft = 6000 + std::rand() % 20000;
        soldCopK = 50.0 + static_cast<double>(std::rand() % 1500) + static_cast<double>(std::rand() % 100) / 100;
        durationOfStream = 30 + std::rand() % 150;
        sale = std::rand() % 67;
        daysOfSale = 15 + std::rand() % 45;

        rating = 4.0 + static_cast<double>(std::rand() % 10) / 10;
        priceInDollars = 15.0 + static_cast<double>(std::rand() % 90);

        Product a(name, showHost, countryOfFactory, shopCountry, shopCity, emailOfShop,
            mainMarketplace, deliveryTimeDays, copLeft, soldCopK, durationOfStream, sale, daysOfSale,
                rating, priceInDollars);
        Serialize(a, outFile, format);
    }

    outFile.close();
}
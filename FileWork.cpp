#include "Utility/ProductClass.h"
#include <iostream>
#include <sstream>

void SaveProductsToFile(const std::string& filename, ArraySequence<Product>& products) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    size_t idx = filename.find('.');
    std::string form = filename.substr(idx + 1);

    //FileFormat format;

    if ("txt" == form) {
        //format = FileFormat::TXT;
    } 
    else if ("csv" == form) {
        //format = FileFormat::CSV;
        outFile << "name,shopHost,countryOfFactory,shopCountry,shopCity,emailOfShop,mainMarketplace,deliveryTimeDays,copLeft,soldCopK,durationOfStream,sale,daysOfSale,rating,priceInDollars\n";
    } else {
        throw std::invalid_argument("Invalid File Format");
    }
    
    for (int i = 0; i < products.getSize(); ++i) {
        if (products[i].GetName() != "") {
            Serialize(products[i], outFile);
        }
    }

    outFile.close();
}

void LoadProductsFromFile(const std::string & filename, ArraySequence<Product>& products) {
    std::ifstream inFile(filename);

    if (!inFile) {
        throw std::ios_base::failure("Failed to open file for reading");
    }

    Product pr;
    std::string delimiter;

    size_t idx = filename.find('.');
    std::string form = filename.substr(idx + 1);

    //FileFormat format;

    if ("txt" == form) {
        //format = FileFormat::TXT;
    } 
    else if ("csv" == form) {
        //format = FileFormat::CSV;
        inFile.ignore(300, '\n');
    } else {
        throw std::invalid_argument("Invalid File Format");
    }

    
    std::string line;
    std::string tmp;
    while (std::getline(inFile, line)) {
        std::istringstream stream(line);

        std::getline(stream, tmp, ',');
        pr.SetName(tmp);

        std::getline(stream, tmp, ',');
        pr.SetShowHost(tmp);

        std::getline(stream, tmp, ',');
        pr.SetCountryOfFactory(tmp);

        std::getline(stream, tmp, ',');
        pr.SetShopCounty(tmp);

        std::getline(stream, tmp, ',');
        pr.SetShopCity(tmp);

        std::getline(stream, tmp, ',');
        pr.SetEmailfOfShop(tmp);

        std::getline(stream, tmp, ',');
        pr.SetMainMarketPlace(tmp);

        std::getline(stream, tmp, ',');
        pr.SetDeliveryTimeDays(std::stoi(tmp));

        std::getline(stream, tmp, ',');
        pr.SetCopLeft(std::stoi(tmp));

        std::getline(stream, tmp, ',');
        pr.SetSoldCopK(std::stod(tmp));
        
        std::getline(stream, tmp, ',');
        pr.SetDurationOfStream(std::stoi(tmp));

        std::getline(stream, tmp, ',');
        pr.SetSale(std::stoi(tmp));

        std::getline(stream, tmp, ',');
        pr.SetDaysOfSale(std::stoi(tmp));

        std::getline(stream, tmp, ',');
        pr.SetRating(std::stod(tmp));

        std::getline(stream, tmp);
        pr.SetPriceInDollars(std::stod(tmp));

        products.append(pr);
    }

    inFile.close();

}

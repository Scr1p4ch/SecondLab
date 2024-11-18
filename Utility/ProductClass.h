#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include <fstream>
#include "FirstLabUtility/Move.h"

// тут продукты телемагазина, которые запускают на стрим бесконечной длительности

class Product {
    std::string name;
    std::string country;
    std::string showHost;
    double soldCopK;
    unsigned int duration; //in minutes;

public: 
    Product() = default;

    Product(std::string _name, std::string _country, std::string _showHost, 
    double _soldCopK, unsigned int _duration)
     : name(_name), country(_country), showHost(_showHost), soldCopK(_soldCopK), duration(_duration) {}

    
    Product(const Product & other) = default;
    Product& operator=(const Product & other) = default;


    Product(Product && other) noexcept : name(Move(other.name)), country(Move(other.country)),
        showHost(Move(other.showHost)), soldCopK(other.soldCopK), duration(other.duration) {}

    Product & operator=(Product && other) noexcept {
        if (this != &other) {
            name = Move(other.name);
            country = Move(other.country);
            showHost = Move(other.showHost);
            soldCopK = other.soldCopK;
            duration = other.duration;
        }

        return *this;
    }

    void Serialize(std::ofstream & out) const {
        out << name << '\n' << country << '\n' << showHost << '\n'
            << soldCopK << '\n' << duration << '\n';
        out << "===\n";
    }

    void Deserialize(std::ifstream & in) {
        std::getline(in, name);
        std::getline(in, country);
        std::getline(in, showHost);
        in >> soldCopK >> duration;
        in.ignore();
    }

    std::string GetName() const { return name; }
    std::string GetCountry() const { return country; }
    double GetSoldCopK() const { return soldCopK; }
    unsigned int GetDuration() const { return duration; }
};

void SaveProductsToFile(ArraySequence<Product>& products, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    for (int i = 0; i < products.getSize(); ++i) {
        products[i].Serialize(outFile);
        outFile << "===" << '\n';
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

/*void SwapProduct(Product & t1, Product & t2) {
    Product tmp = Move(t1);
    t1 = Move(t2);
    t2 = Move(tmp);
}
*/

#endif
#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include <fstream>
#include "FirstLabUtility/Move.h"
#include "Sequence.h"
#include "FileFormat.h"

// тут продукты телемагазина, которые запускают на стрим бесконечной длительности

class Product {
    std::string name;
    std::string country;
    std::string showHost;
    double soldCopK;
    unsigned int duration;
    unsigned int sale;

public: 
    Product() = default;

    Product(std::string _name, std::string _country, std::string _showHost, 
    double _soldCopK, unsigned int _duration, unsigned int _sale)
     : name(_name), country(_country), showHost(_showHost), soldCopK(_soldCopK), duration(_duration), sale(_sale) {}

    
    Product(const Product & other) = default;
    Product& operator=(const Product & other) = default;


    Product(Product && other) noexcept : name(Move(other.name)), country(Move(other.country)),
        showHost(Move(other.showHost)), soldCopK(other.soldCopK), duration(other.duration), sale(other.sale) {}

    Product & operator=(Product && other) noexcept {
        if (this != &other) {
            name = Move(other.name);
            country = Move(other.country);
            showHost = Move(other.showHost);
            soldCopK = other.soldCopK;
            duration = other.duration;
            sale = other.sale;
        }

        return *this;
    }


    std::string GetName() const { return name; }
    std::string GetCountry() const { return country; }
    double GetSoldCopK() const { return soldCopK; }
    unsigned int GetDuration() const { return duration; }
    unsigned int GetSale() const { return sale; }


    friend void Serialize(const Product& prod, std::ofstream & out, FileFormat format);
    friend void Deserialize(Product& prod, std::ifstream & in, FileFormat format);
};



void SaveProductsToFile(const std::string& filename, ArraySequence<Product>& products);
void LoadProductsFromFile(const std::string & filename, ArraySequence<Product>& products);

#endif
#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include "FirstLabUtility/Move.h"

// тут продукты телемагазина, которые запускают на стрим бесконечной длительности

class Product {
    std::string name;
    std::string ownerCompany;
    std::string showHost;
    double soldCopK;
    unsigned int duration; //in minutes;

public: 
    Product() = default;

    Product(std::string _name, std::string _ownerCompany, std::string _showHost, 
    double _soldCopK, unsigned int _duration)
     : name(_name), ownerCompany(_ownerCompany), showHost(_showHost), soldCopK(_soldCopK), duration(_duration) {}


    Product(Product && other) noexcept : name(Move(other.name)), ownerCompany(Move(other.ownerCompany)),
        showHost(Move(other.showHost)), soldCopK(other.soldCopK), duration(other.duration) {}

    Product & operator=(Product && other) noexcept {
        if (this != &other) {
            name = Move(other.name);
            ownerCompany = Move(other.ownerCompany);
            showHost = Move(other.showHost);
            soldCopK = other.soldCopK;
            duration = other.duration;
        }

        return *this;
    }
};

void SwapProduct(Product & t1, Product & t2) {
    Product tmp = Move(t1);
    t1 = Move(t2);
    t2 = Move(tmp);
}


#endif
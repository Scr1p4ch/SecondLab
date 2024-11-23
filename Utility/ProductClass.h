#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include <fstream>
#include "FirstLabUtility/Move.h"
#include "Sequence.h"
#include "FileFormat.h"

// тут продукты телемагазина, которые запускают на стрим произвольной длительности

class Product {
    std::string name;
    std::string showHost;

    std::string countryOfFactory;
    std::string shopCountry;
    std::string shopCity;

    std::string emailOfShop;

    std::string mainMarketplace;

    unsigned int deliveryTimeDays;

    unsigned int copLeft;
    double soldCopK;
    unsigned int durationOfStream;
    unsigned int sale;
    unsigned int daysOfSale;

    double rating;

    double priceInDollars;



public: 
    Product() = default;

    Product(std::string _name, std::string _showHost, std::string _countryOfFactory,
        std::string _shopCountry, std::string _shopCity, std::string _emailOfShop,
            std::string _mainMarketPlace, unsigned int _deliveryTimeDays,
                unsigned int _copLeft, double _soldCopK, unsigned int _durationOfStream, unsigned int _sale,
                    unsigned int _daysOfSale, double _rating, double _priceInDollars) : 
        name(_name), showHost(_showHost), countryOfFactory(_countryOfFactory), shopCountry(_shopCountry), shopCity(_shopCity), 
            emailOfShop(_emailOfShop), mainMarketplace(_mainMarketPlace), deliveryTimeDays(_deliveryTimeDays), copLeft(_copLeft), 
                soldCopK(_soldCopK), durationOfStream(_durationOfStream), sale(_sale), daysOfSale(_daysOfSale), rating(_rating), priceInDollars(_priceInDollars) {}

    
    Product(const Product & other) = default;
    Product& operator=(const Product & other) = default;


    Product(Product && other) noexcept : name(Move(other.name)), showHost(Move(other.showHost)), countryOfFactory(Move(other.countryOfFactory)), shopCountry(Move(other.shopCountry)),
        shopCity(Move(other.shopCity)), emailOfShop(Move(other.emailOfShop)), mainMarketplace(Move(other.mainMarketplace)), deliveryTimeDays(other.deliveryTimeDays),
            copLeft(other.copLeft), soldCopK(other.soldCopK), durationOfStream(other.durationOfStream), sale(other.sale), daysOfSale(other.daysOfSale), rating(other.rating), priceInDollars(other.priceInDollars) {}

    Product & operator=(Product && other) noexcept {
        if (this != &other) {
            name = Move(other.name);
            showHost = Move(other.showHost);
            countryOfFactory = Move(other.countryOfFactory);
            shopCountry = Move(other.shopCountry);
            shopCity = Move(other.shopCity);
            emailOfShop = Move(other.emailOfShop);
            mainMarketplace = Move(other.mainMarketplace);

            deliveryTimeDays = other.deliveryTimeDays;
            copLeft = other.copLeft;
            durationOfStream = other.durationOfStream;
            sale = other.sale;
            daysOfSale = other.daysOfSale;
            rating = other.rating;
            priceInDollars = other.priceInDollars;
        }

        return *this;
    }


    std::string GetName() const { return name; }
    std::string GetShowHost() const { return showHost; }
    std::string GetCountryOfFactory() const { return countryOfFactory; }
    std::string GetShopCountry() const { return shopCountry; }
    std::string GetShopCity() const { return shopCity; }
    std::string GetEmailOfShop() const { return emailOfShop; }
    std::string GetMainMarketName() const { return mainMarketplace; }

    unsigned int GetDeliveryTimeDays() const { return deliveryTimeDays; }
    unsigned int GetCopLeft() const { return copLeft; }
    double GetSoldCopK() const { return soldCopK; }
    unsigned int GetDurationOfStream() const { return durationOfStream; }
    unsigned int GetSale() const { return sale; }
    unsigned int GetDaysOfSale() const { return daysOfSale; }
    double GetRating() const { return rating; }
    double GetPriceInDollars() const { return priceInDollars; }



    friend void Serialize(const Product& prod, std::ofstream & out, FileFormat format);
    friend void Deserialize(Product& prod, std::ifstream & in, FileFormat format);
};



void SaveProductsToFile(const std::string& filename, ArraySequence<Product>& products);
void LoadProductsFromFile(const std::string & filename, ArraySequence<Product>& products);

#endif
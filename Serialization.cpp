#include "Utility/ProductClass.h"

void Serialize(const Product& prod, std::ofstream & out) {
    out << prod.name << ',' << prod.showHost << ',' << prod.countryOfFactory << ',' 
        << prod.shopCountry << ',' << prod.shopCity << ',' << prod.emailOfShop << ',' 
            << prod.mainMarketplace << ',' << prod.deliveryTimeDays << ',' << prod.copLeft << ','
                << prod.soldCopK << ',' << prod.durationOfStream << ',' << prod.sale << ','
                    << prod.daysOfSale << ',' << prod.rating << ',' << prod.priceInDollars << '\n';

}

void Deserialize(Product& prod, std::ifstream & in) {

    std::getline(in, prod.name, ',');
    std::getline(in, prod.showHost, ',');
    std::getline(in, prod.countryOfFactory, ',');
    std::getline(in, prod.shopCountry, ',');
    std::getline(in, prod.shopCity, ',');
    std::getline(in, prod.emailOfShop, ',');
    std::getline(in, prod.mainMarketplace, ',');



    in >> prod.deliveryTimeDays;
    in.ignore(1);
    in >> prod.copLeft;
    in.ignore(1);
    in >> prod.soldCopK;
    in.ignore(1);
    in >> prod.durationOfStream;
    in.ignore(1);
    in >> prod.sale;
    in.ignore(1);
    in >> prod.daysOfSale;
    in.ignore(1);
    in >> prod.rating;
    in.ignore(1);
    in >> prod.priceInDollars;
    in.ignore(1);
}
#include "Utility/ProductClass.h"

void Serialize(const Product& prod, std::ofstream & out, FileFormat format) {
    out << prod.name << ',' << prod.country << ',' << prod.showHost << ','
            << prod.soldCopK << ',' << prod.duration << ',' << prod.sale << '\n';
}

void Deserialize(Product& prod, std::ifstream & in, FileFormat format) {

    std::getline(in, prod.name, ',');
    std::getline(in, prod.country, ',');
    std::getline(in, prod.showHost, ',');
    in >> prod.soldCopK;
    in.ignore(1);
    in >> prod.duration;
    in.ignore(1);
    in >> prod.sale;
    in.ignore();
    
}
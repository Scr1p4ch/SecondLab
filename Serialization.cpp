#include "Utility/ProductClass.h"

void Serialize(const Product& prod, std::ofstream & out) {
        out << prod.name << '\n' << prod.country << '\n' << prod.showHost << '\n'
            << prod.soldCopK << '\n' << prod.duration << '\n' << prod.sale << '\n';
        out << "===\n";
}

void Deserialize(Product& prod, std::ifstream & in) {
    std::getline(in, prod.name);
    std::getline(in, prod.country);
    std::getline(in, prod.showHost);
    in >> prod.soldCopK >> prod.duration >> prod.sale;
    in.ignore();
}
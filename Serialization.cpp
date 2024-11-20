#include "Utility/ProductClass.h"

void Serialize(const Product& prod, std::ofstream & out, FileFormat format) {
    out << prod.name << ',' << prod.country << ',' << prod.showHost << ','
            << prod.soldCopK << ',' << prod.duration << ',' << prod.sale << '\n';
}

void Deserialize(Product& prod, std::ifstream & in, FileFormat format) {
    if (format == FileFormat::CSV) {
        in.ignore('\n');
    }
    std::getline(in, prod.name, ',');
    std::getline(in, prod.country, ',');
    std::getline(in, prod.showHost, ',');
    in >> prod.soldCopK;
    in.ignore();
    in >> prod.duration;
    in.ignore();
    in >> prod.sale;
    in.ignore();
}
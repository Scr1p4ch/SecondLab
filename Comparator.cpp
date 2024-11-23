#include "Utility/ProductClass.h"

int IntCompareFunc(int & a, int & b) {
    return (a < b) ? -1 : (a > b) ? 1 : 0;
}

int ProductNameCompareFunc(const Product & a, const Product & b) {
    std::string s1 = a.GetName(), s2 = b.GetName(); 
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int ShowHostCompareFunc(const Product & a, const Product & b) {
    std::string s1 = a.GetShowHost(), s2 = b.GetShowHost();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int ShopCountryCompareFunc(const Product & a, const Product & b) {
    std::string s1 = a.GetShopCountry(), s2 = b.GetShopCountry();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int ShopCityCompareFunc(const Product & a, const Product & b) {
    std::string s1 = a.GetShopCity(), s2 = b.GetShopCity();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int EmailOfShopCompareFunc(const Product & a, const Product & b) {
    std::string s1 = a.GetEmailOfShop(), s2 = b.GetEmailOfShop();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int MainMarketplaceCompareFunc(const Product & a, const Product & b) {
    std::string s1 = a.GetMainMarketName(), s2 = b.GetMainMarketName();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int DeliveryTimeCompareFunc(const Product & a, const Product & b) {
    unsigned int s1 = a.GetDeliveryTimeDays(), s2 = b.GetDeliveryTimeDays();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int CopLeftCompareFunc(const Product& a, const Product& b) {
    unsigned int s1 = a.GetCopLeft(), s2 = b.GetCopLeft();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int SoldCopKCompareFunc(const Product& a, const Product& b) {
    double s1 = a.GetSoldCopK(), s2 = b.GetSoldCopK();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int DurationCompareFunc(const Product& a, const Product& b) {
    unsigned int s1 = a.GetDurationOfStream(), s2 = b.GetDurationOfStream();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int SaleCompareFunc(const Product & a, const Product & b) {
    unsigned int s1 = a.GetSale(), s2 = b.GetSale();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int DaysOfSaleCompareFunc(const Product & a, const Product & b) {
    unsigned int s1 = a.GetDaysOfSale(), s2 = b.GetDaysOfSale();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int ProductRatingCompareFunc(const Product & a, const Product & b) {
    double s1 = a.GetRating(), s2 = b.GetRating();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}

int ProductPriceCompareFunc(const Product & a, const Product & b) {
    double s1 = a.GetPriceInDollars(), s2 = b.GetPriceInDollars();
    return (s1 < s2) ? -1 : (s1 > s2) ? 1 : 0;
}
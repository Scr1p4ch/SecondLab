#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_

#include "../Utility/ProductClass.h"


int IntCompareFunc(int & a, int & b);

int ProductNameCompareFunc(const Product & a, const Product & b);
int ShowHostCompareFunc(const Product & a, const Product & b);
int ShopCountryCompareFunc(const Product & a, const Product & b);
int ShopCityCompareFunc(const Product & a, const Product & b);
int EmailOfShopCompareFunc(const Product & a, const Product & b);
int MainMarketplaceCompareFunc(const Product & a, const Product & b);

int DeliveryTimeCompareFunc(const Product & a, const Product & b);
int CopLeftCompareFunc(const Product & a, const Product & b);
int SoldCopKCompareFunc(const Product& a, const Product& b);
int DurationCompareFunc(const Product & a, const Product & b);
int SaleCompareFunc(const Product & a, const Product & b);
int DaysOfSaleCompareFunc(const Product & a, const Product & b);
int ProductRatingCompareFunc(const Product & a, const Product & b);
int ProductPriceCompareFunc(const Product & a, const Product & b);


#endif
#ifndef _TESTS_COMPARATORTEST_H_
#define _TESTS_COMPARATORTEST_H_


#include <assert.h>
#include <string>
#include "../Sort/Comparator.h"


void UsualProductCompareTest() {
    std::string st1 = "aaa", st2 = "bbb";
    unsigned int num1 = 1, num2 = 2;
    double d1 = 1.0, d2 = 2.0;

    Product a(st1, st1, st1, st1, st1, st1, st1,
        num1, num1, d1, num1, num1, num1, d1, d1);

    Product b(st2, st2, st2, st2, st2, st2, st2,
        num2, num2, d2, num2, num2, num2, d2, d2);

    Product c(st1, st1, st1, st1, st1, st1, st1,
        num1, num1, d1, num1, num1, num1, d1, d1);



    assert(st1 == a.GetName());
    assert(st1 == a.GetShowHost());
    assert(st1 == a.GetShopCountry());
    assert(st1 == a.GetShopCity());
    assert(st1 == a.GetEmailOfShop());
    assert(st1 == a.GetMainMarketName());

    assert(num1 == a.GetDeliveryTimeDays());
    assert(num1 == a.GetCopLeft());
    assert(d1 = a.GetSoldCopK());
    assert(num1 == a.GetDurationOfStream());
    assert(num1 == a.GetSale());
    assert(num1 == a.GetDaysOfSale());
    assert(d1 == a.GetRating());
    assert(d1 == a.GetPriceInDollars());

    assert(-1 == ProductNameCompareFunc(a, b));
    assert(0 == ProductNameCompareFunc(a, c));
    assert(1 == ProductNameCompareFunc(b, a));

    assert(-1 == ShowHostCompareFunc(a, b));
    assert(0 == ShowHostCompareFunc(a, c));
    assert(1 == ShowHostCompareFunc(b, a));

    assert(-1 == ShopCountryCompareFunc(a, b));
    assert(0 == ShopCountryCompareFunc(a, c));
    assert(1 == ShopCountryCompareFunc(b, a));

    assert(-1 == ShopCityCompareFunc(a, b));
    assert(0 == ShopCityCompareFunc(a, c));
    assert(1 == ShopCityCompareFunc(b, a));

    assert(-1 == EmailOfShopCompareFunc(a, b));
    assert(0 == EmailOfShopCompareFunc(a, c));
    assert(1 == EmailOfShopCompareFunc(b, a));

    assert(-1 == MainMarketplaceCompareFunc(a, b));
    assert(0 == MainMarketplaceCompareFunc(a, c));
    assert(1 == MainMarketplaceCompareFunc(b, a));

    assert(-1 == DeliveryTimeCompareFunc(a, b));
    assert(0 == DeliveryTimeCompareFunc(a, c));
    assert(1 == DeliveryTimeCompareFunc(b, a));

    assert(-1 == CopLeftCompareFunc(a, b));
    assert(0 == CopLeftCompareFunc(a, c));
    assert(1 == CopLeftCompareFunc(b, a));

    assert(-1 == SoldCopKCompareFunc(a, b));
    assert(0 == SoldCopKCompareFunc(a, c));
    assert(1 == SoldCopKCompareFunc(b, a));

    assert(-1 == DurationCompareFunc(a, b));
    assert(0 == DurationCompareFunc(a, c));
    assert(1 == DurationCompareFunc(b, a));

    assert(-1 == SaleCompareFunc(a, b));
    assert(0 == SaleCompareFunc(a, c));
    assert(1 == SaleCompareFunc(b, a));

    assert(-1 == DaysOfSaleCompareFunc(a, b));
    assert(0 == DaysOfSaleCompareFunc(a, c));
    assert(1 == DaysOfSaleCompareFunc(b, a));

    assert(-1 == ProductRatingCompareFunc(a, b));
    assert(0 == ProductRatingCompareFunc(a, c));
    assert(1 == ProductRatingCompareFunc(b, a));

    assert(-1 == ProductPriceCompareFunc(a, b));
    assert(0 == ProductPriceCompareFunc(a, c));
    assert(1 == ProductPriceCompareFunc(b, a));

}

#endif
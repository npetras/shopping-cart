//
// Created by Nicolas Petras on 30/05/2022.
//

#include <string>


using namespace std;


#ifndef INC_7_SHOPPING_CART_CLION_PROJ_PRODUCT_H
#define INC_7_SHOPPING_CART_CLION_PROJ_PRODUCT_H

class Product {
    static int IDcount;
    int id;
    string name;
    int price;
    int categoryId;
public:
    Product(string name, int price, int categoryId);

    friend ostream &operator<<(ostream &os, const Product &dt);

    int getId() const;


    const string &getName() const;

    void setName(const string &name);

    int getPrice() const;

    void setPrice(int price);

    int getCategoryId() const;

    void setCategoryId(int categoryId);

};

#endif //INC_7_SHOPPING_CART_CLION_PROJ_PRODUCT_H

//
// Created by Nicolas Petras on 30/05/2022.
//

#include <string>
using namespace std;


#ifndef INC_7_SHOPPING_CART_CLION_PROJ_PRODUCT_H
#define INC_7_SHOPPING_CART_CLION_PROJ_PRODUCT_H

class Product{
    int id;
    string name;
    int price;
    int categoryId;
public:
    Product(int id, string name, int price, int categoryId) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->categoryId = categoryId;
    }
    friend ostream& operator<<(ostream& os, const Product& dt);

    int getId() const;

    void setId(int id);

    const string &getName() const;

    void setName(const string &name);

    int getPrice() const;

    void setPrice(int price);

    int getCategoryId() const;

    void setCategoryId(int categoryId);

};

void printTrolley();

ostream& operator<<(ostream& os, const Product& p) {
    os << p.id << "\t" << p.name << "\t" << p.price << "\t";
    return os;
}

int Product::getId() const {
    return id;
}

void Product::setId(int id) {
    Product::id = id;
}

const string &Product::getName() const {
    return name;
}

void Product::setName(const string &name) {
    Product::name = name;
}

int Product::getPrice() const {
    return price;
}

void Product::setPrice(int price) {
    Product::price = price;
}

int Product::getCategoryId() const {
    return categoryId;
}

void Product::setCategoryId(int categoryId) {
    Product::categoryId = categoryId;
}

#endif //INC_7_SHOPPING_CART_CLION_PROJ_PRODUCT_H

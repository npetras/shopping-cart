//
// Created by Nicolas Petras on 31/05/2022.
//
#include "iostream"
#include <iomanip>

#include "Product.h"
int Product::IDcount = 1;

Product::Product(string name, int price, int categoryId) {
    this->id = Product::IDcount;
    ++Product::IDcount;
    this->name = name;
    this->price = price;
    this->categoryId = categoryId;
}

ostream &operator<<(ostream &os, const Product &p) {
    os << p.id  << setw(15) << p.name << setw(5) <<  p.price;
    return os;
}

int Product::getId() const {
    return id;
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
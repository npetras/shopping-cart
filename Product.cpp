//
// Created by Nicolas Petras on 31/05/2022.
//
#include "Product.h"

Product::Product(int id, string name, int price, int categoryId) {
    this->id = id;
    this->name = name;
    this->price = price;
    this->categoryId = categoryId;
}

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
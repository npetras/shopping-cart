#pragma once

#include "Product.h"
#include "Category.h"
#include <vector>

class Admin {
private:
    std::vector<Category> categories;
    std::vector<Product> products;
public:
    void addProduct();

    void addCategory();

    void printProducts();

    void printRange(int lower, int upper);

    std::vector<Product> getByName(string catName);

    std::vector<Product> getFromRange(int lower, int upper);

    const vector<Category> &getCategories() const;

    const vector<Product> &getProducts() const;

    Category findCategory(int id);
};
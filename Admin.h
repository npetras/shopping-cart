#pragma once

#include "Product.h"
#include "Category.h"
#include <vector>

class Admin
{
private:
    std::vector<Category> categories;
    std::vector<Product> products;
public:
    void addProducts(Product item);
    void addCategories(Category newCat);
    std::vector<Product> getByName(string catName);
    std::vector<Product> getFromRange(double lower, double upper);
};
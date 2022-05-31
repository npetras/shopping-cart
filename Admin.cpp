#include "Admin.h"

void Admin::addProducts(Product item) {
    products.push_back(item);
}

void Admin::addCategories(Category newCat) {
    categories.push_back(newCat);
}

std::vector<Product> Admin::getByName(string catName) {
    std::vector<Product> found;
    Category match;
    for (Category cat: categories)
        if (cat.catName == catName) {
            match = cat;
            break;
        }
    for (Product p: products) if (p.getCategoryId() == match.catID) found.push_back(p);
    return found;
}

std::vector<Product> Admin::getFromRange(double lower, double upper) {
    vector<Product> foundProds;
    for (Product p: products)
        if (lower <= p.getPrice() && p.getPrice() <= upper) {
            foundProds.push_back(p);
        }
    return foundProds;
}
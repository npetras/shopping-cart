#include "iostream"

#include "Admin.h"


void Admin::addProducts() {
    string name;
    int price;
    int catId;

    cout << "Please provide product details" << endl;
    cout << "Product name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Product price: ";
    cin >> price;
    cout << "Category Id: ";
    cin >> catId;

    Product item(name, price, catId);
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

const vector<Category> &Admin::getCategories() const {
    return categories;
}

const vector<Product> &Admin::getProducts() const {
    return products;
}

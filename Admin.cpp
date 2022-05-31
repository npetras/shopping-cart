#include "iostream"

#include "Admin.h"
#include "User.h"


void Admin::addProduct() {
    string name;
    int price;
    int catId;

    cout << "Please provide product details" << endl;
    cout << "Product name: ";
    cin.ignore();
    getline(cin, name);
    getline(cin, name);
    cout << "Product price: ";
    cin >> price;
    cout << "Category Id: ";
    cin >> catId;

    Product item(name, price, catId);
    products.push_back(item);
}

void Admin::addCategory() {
    string name;
    string description;

    cout << "Please provide category details" << endl;
    cout << "Category name: " << endl;
    getline(cin, name);
    getline(cin, name);
    cout << "Category description: " << endl;
    getline(cin, description);

    Category newCat(name, description);
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

std::vector<Product> Admin::getFromRange(int lower, int upper) {
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

void Admin::printAllProducts() {
    cout << "ID\tName\tPrice\tCategory\tDescription" << endl;
    for (auto &product: this->products) {
        Category category = findCategory(product.getCategoryId());
        cout << product << category;
        cout << endl;
    }
}

Category Admin::findCategory(int id) {
    for (Category c: categories) {
        if (id == c.getCatId()) {
            return c;
        }
    }
    Category blank;
    return (blank);
}

void Admin::printRange(int lower, int upper) {
    vector<Product> rangeProducts = getFromRange(lower, upper);

    cout << "ID\tName\tPrice\tCategory\tDescription" << endl;
    for (auto &product: rangeProducts) {
        Category category = findCategory(product.getCategoryId());
        cout << product << category << endl;
    }
}

void Admin::printCategory(string name) {
    vector<Product> categoryProducts = getByName(name);

    cout << "ID\tName\tPrice\tCategory\tDescription" << endl;
    for (auto &product: categoryProducts) {
        Category category = findCategory(product.getCategoryId());
        cout << product << category << endl;
    }
}

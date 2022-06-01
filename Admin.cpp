#include "iostream"

#include "Admin.h"
#include "User.h"

void Admin::addProduct() {
    string name;
    int price;
    int catId;
    bool validCatId = false;

    cout << "Please provide product details" << endl;
    cout << "Product name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Product price: ";
    cin >> price;
    while (!validCatId) {
        
       
        cout << "Available Ids:\n";
        for (const Category& c : categories) {
            cout << c.getCatId() << " Name: " << c.getCatName() << endl;
        }
        cout << "Category Id:\n";
        cin >> catId;
        for (const Category& c : categories) {
            if (c.getCatId() == catId) validCatId = true;
        }
    }

    Product item(name, price, catId);
    products.push_back(item);
}

void Admin::addCategory() {
    string name;
    string description;

    cout << "Please provide category details" << endl;
    cout << "Category name: " << endl;
    cin.ignore();
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

        if (stringToLower(cat.catName) == stringToLower(catName)) {
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

void Admin::initialise() {
    Category food("Food", "Something to eat");
    Category electronics("Electronics", "Gadgets, computers, phones, etc.");
    categories.push_back(food);
    categories.push_back(electronics);

    Product digestives("Digestives", 10, 1);
    Product jaffaCakes("Jaffa Cakes", 11, 1);
    Product xbox("Xbox One", 100, 2);
    Product samsungS22("Samsung S22", 150, 2);
    products.push_back(digestives);
    products.push_back(jaffaCakes);
    products.push_back(xbox);
    products.push_back(samsungS22);
}

std::string Admin::stringToLower(string str)
{
    string allLower = str;
    for (int i = 0; i < str.size(); i++)
    {
        allLower[i] = tolower(str[i]);
    }
    return allLower;
}
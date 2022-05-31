//
// Created by Nicolas Petras on 31/05/2022.
//

#include "iostream"
#include "User.h"

Category User::findCategory(int id, const vector<Category> &categories) {

    for (Category c: categories) {
        if (id == c.getCatId()) {
            return c;
        }
    }
    Category blank;
    return (blank);
}

void User::printTrolley(const vector<Category> &categories) {

    cout << "ID\tName\tPrice\tCategory\tDescription\tQuantity" << endl;
    for (auto &product: this->trolley) {
        Category category = findCategory(product.getCategoryId(), categories);

        cout << product << category << "\t" << productQuantity[product.getId()];
    }
}

void User::addItem(vector<Product> &products) {
    int givenID;
    cout << "Search for product ID: ";
    cin >> givenID;

    for (Product &p: products) {
        if (givenID == p.getId()) {
            if (productQuantity[p.getId()] == 0) {
                this->trolley.push_back(p);
            }
            auto mapIt = productQuantity.find(p.getId());

            if (mapIt == productQuantity.end()) {
                productQuantity.insert({p.getId(), 1});
            } else {
                productQuantity[p.getId()] = productQuantity[p.getId()] + 1;
            }
        }
    }
}

void User::removeItem() {
    int givenID;
    cout << "Remove product ID: ";
    cin >> givenID;

    for (int i = 0; i < trolley.size(); i++) {
        if (givenID == trolley.at(i).getId()) {
            trolley.erase(trolley.begin() + i);
        }
    }
}

void User::clearCart() {
    char ch;
    cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    cout << "\nThis will clear all items in the cart. Proceed? (y/n)";
    cin >> ch;

    while (1) {
        if (ch == 'y') {
            trolley.clear();
            productQuantity.clear();
            break;
        } else if (ch == 'n') {
            break;
        } else {
            cout << "\nPlease enter valid choice. (y/n)";
            cin >> ch;
        }
    }
}
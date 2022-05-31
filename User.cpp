//
// Created by Nicolas Petras on 31/05/2022.
//

#include "iostream"
#include "User.h"

void User::addItem() {

}

Category User::findCategory(int id, vector<Category> categories) {
    for (Category &c : categories) {
        if (id == c.getCatId()) {
            return c;
        }
    }
}

void User::printTrolley(const vector<Category>& categories) {
    cout << "ID\tName\tPrice\tCategory\tDescription" << endl;
    for (auto & product : trolley) {
        Category category = findCategory(product.getCategoryId(), categories);
        cout << product << category;
    }
}
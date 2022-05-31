#include <iostream>
#include <vector>
#include <unordered_map>

#include "Category.h"
#include "Product.h"
#include "User.h"
#include "Admin.h"

void userChoices(int ch, vector<Product> &products, const vector<Category> &categories, User *user);

using namespace std;


int main() {
    int ch;
    int userCh;

    vector<Product> products;
    vector<Category> categories;

    // choose between User and Admin
    User *user = new User();
    Admin admin;

    while (1) {

        cout << "Select User" << endl;
        cout << "1. Admin 2. Shopper" << endl;

        switch (userCh) {
            case 1:
                adminChoices();
            case 2:
                products = admin.getProducts();
                userChoices(ch, products, categories, user);
        }



    }
}

void userChoices(int ch, vector<Product> &products, const vector<Category> &categories, User *user) {
    user->printTrolley(categories);

    cout << "\nWhat do you want to do?";
    cout << "1. Add Items  2. Remove from Trolley";
    cin >> ch;

    switch (ch) {
        case 1:
            user->addItem(products);
            break;
        case 2:
            user->removeItem();
            break;
        default:
            cout << "Invalid choice" << endl;
    }
}
#include <iostream>
#include <vector>
#include <unordered_map>

#include "Category.h"
#include "Product.h"
#include "User.h"
#include "Admin.h"

void userChoices(vector<Product> &products, const vector<Category> &categories, User *user);

void adminChoices(Admin admin);

using namespace std;


int main() {
    int userCh;

    vector<Product> products;
    vector<Category> categories;

    // choose between User and Admin
    User *user = new User();
    Admin admin;

    while (1) {

        cout << "Select User" << endl;
        cout << "1. Admin 2. Shopper" << endl;
        cin >> userCh;

        switch (userCh) {
            case 1:
                adminChoices(admin);
                break;
            case 2:
                products = admin.getProducts();
                categories = admin.getCategories();
                userChoices(products, categories, user);
                break;
        }
    }
}

void adminChoices(Admin admin) {
    int ch;
    do {
        cout << "What do you want to do?" << endl;
        cout << "1. Add Products  2. Add Categories 3. See all Records 4. Exit" << endl;
        cin >> ch;

        Product digestives("digestives", 100, 1);

        switch (ch) {
            case 1:
                admin.addProducts();
                break;
            case 4:
                cout << "Returning to user selection" << endl;
            default:
                cout << "Invalid choice" << endl;
        }
        cout << admin.getProducts().at(0);
    } while (ch != 4);

}

void userChoices(vector<Product> &products, const vector<Category> &categories, User *user) {
    int ch;
    cout << "Trolley:" << endl;
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
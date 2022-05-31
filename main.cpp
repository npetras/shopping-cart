#include <iostream>
#include <vector>
#include <unordered_map>

#include "Category.h"
#include "Product.h"
#include "User.h"

using namespace std;


int main() {
    int ch;
    vector<Product> products;
    vector<Category> categories;
    //vector<Product> trolley;
    //unordered_map<int, int> productQuantity;

    Category soap("soap", "For cleaning", 1);
    Category food("food", "For eating", 2);
    Category sweets("sweets", "For eating too", 3);

    categories.push_back(soap);
    categories.push_back(food);
    categories.push_back(sweets);

    Product digestives(1, "Digestives", 10, 2);
    products.push_back(digestives);

    // choose between User and Admin

    while (1) {
        cout << "Trolley" << endl;
        User *user = new User();

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
        }
    }
}

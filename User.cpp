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
    int totalCost = 0;
    cout << "\nID\tName\tPrice\tCategory\tDescription\tQuantity" << endl;
    for (auto &product: this->trolley) {
        Category category = findCategory(product.getCategoryId(), categories);
        cout << product << "\t" << category << "\t" << productQuantity[product.getId()];
        cout << endl;
        totalCost += product.getPrice();
    }
    cout << "Total trolley cost: " << totalCost << endl << endl;
}

void User::addItem(vector<Product> &products) {
    int givenID;
    int givenQty;
    bool isFound = false;
    //char userCh;
    cout << "\nSearch for product ID: ";
    cin >> givenID;

    do 
    {
        for (Product &p: products) 
        {
            if (givenID == p.getId()) 
            {
                isFound = true;
                cout << "\nProduct " << p.getName() << " found. Enter the quantity of the product you want: ";
                cin >> givenQty;

                if (givenQty < 1)
                {
                    cout << "\nInvalid quantity.";
                    return;
                }

                if (productQuantity[p.getId()] == 0) 
                {
                    this->trolley.push_back(p);
                }
                
                auto mapIt = productQuantity.find(p.getId());
                if (mapIt == productQuantity.end()) {
                    productQuantity.insert({p.getId(), givenQty }); // Put the quantity of the item in the trolley
                } else {
                    productQuantity[p.getId()] = productQuantity[p.getId()] + givenQty; // If it already exists add the quantity
                }
            }
    
        }
        if (!isFound)
        {
            cout << "\nProduct with ID " << givenID << " was not found. Please enter a valid ID: ";
            cin >> givenID;
        }
    } while (!isFound);
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
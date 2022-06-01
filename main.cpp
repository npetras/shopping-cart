#include <iostream>
#include <vector>

#include "Category.h"
#include "Product.h"
#include "User.h"
#include "Admin.h"

void userChoices(vector<Product> &products, const vector<Category> &categories, User *user, Admin &admin);

void adminChoices(Admin &admin);

void printingChoices(Admin &admin);

void printCategory(Admin &admin);

void printRange(Admin &admin);

void printProductsForUser(Admin &admin);

using namespace std;

int main() {
    int userCh;

    vector<Product> products;
    vector<Category> categories;

    // choose between User and Admin
    User *user = new User();
    Admin admin;
    admin.initialise();

    while (1) {

        cout << "Select User" << endl;
        cout << "1. Admin 2. Shopper" << endl;
        cin >> userCh;

        switch (userCh) {
            case 1:
                adminChoices(admin);
                break;
            case 2:
                // get latest products and categories added by the Admin
                products = admin.getProducts();
                categories = admin.getCategories();
                userChoices(products, categories, user, admin);
                break;
        }
    }
}

void adminChoices(Admin &admin) {
    int ch;
    do {
        cout << "\nWhat do you want to do?" << endl;
        cout << "1. Add Products  2. Add Categories 3. See Records 4. Exit" << endl;
        cin >> ch;

        switch (ch) {
            case 1:
                admin.addProduct();
                break;
            case 2:
                admin.addCategory();
                break;
            case 3:
                printingChoices(admin);
                break;
            case 4:
                cout << "Returning to user selection" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 4);

}

void printingChoices(Admin &admin) {
    int printCh;
    cout << "How do you want to see the product records?" << endl;
    cout << "1. Category name 2. Price range 3. All products: ";
    cin >> printCh;
    switch (printCh) {
        case 1:
            printCategory(admin);
            break;
        case 2:
            printRange(admin);
            break;
        case 3:
            admin.printAllProducts();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}

void printRange(Admin &admin) {
    int lower;
    int upper;
    cout << "Provide the range" << endl;
    cout << "Lower bound: ";
    cin >> lower;
    cout << "Upper bound: ";
    cin >> upper;
    admin.printRange(lower, upper);
}

void printCategory(Admin &admin) {
    string categoryName;
    cout << "Enter the category name: " << endl;
    getline(cin, categoryName);
    getline(cin, categoryName);
    admin.printCategory(categoryName);
}

void userChoices(vector<Product> &products, const vector<Category> &categories, User *user, Admin &admin) {
    int ch;
    do {
        cout << "Trolley:" << endl;
        user->printTrolley(categories);

        cout << "What do you want to do?" << endl;
        cout << "1. Print Products 2. Add Items  3. Remove item from Trolley  4. Clear cart  5. Exit to User Selection" << endl;
        cin >> ch;

        switch (ch) {
            case 1:
                printProductsForUser(admin);
                break;
            case 2:
                user->addItem(products);
                break;
            case 3:
                user->removeItem();
                break;
            case 4:
                user->clearCart();
                break;
            case 5:
                cout << "Returning to user selection" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 5);
}

void printProductsForUser(Admin &admin) {
    int ch;
    cout << "\n1. Print all 2. Print based on category name" << endl;
    cin >> ch;

    switch (ch) {
        case 1:
            cout << "Available Products: " << endl;
            admin.printAllProducts();
            break;
        case 2:
            cout << "Available Products: " << endl;
            printCategory(admin);
            break;
        default:
            cout << "\nInvalid choice" << endl;
    }
}

//
// Created by Nicolas Petras on 31/05/2022.
//

#ifndef INC_7_SHOPPING_CART_CLION_PROJ_USER_H
#define INC_7_SHOPPING_CART_CLION_PROJ_USER_H


#include <vector>
#include <unordered_map>
#include "Product.h"
#include "Category.h"

class User {

    unordered_map<int, int> productQuantity;

    static Category findCategory(int id, const vector<Category> &categories);

public:
    vector<Product> trolley;

    void printTrolley(const vector<Category> &categories);

    void addItem(vector<Product> &products);

    void removeItem();

    void clearCart();
};


#endif //INC_7_SHOPPING_CART_CLION_PROJ_USER_H

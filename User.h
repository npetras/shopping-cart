//
// Created by Nicolas Petras on 31/05/2022.
//

#ifndef INC_7_SHOPPING_CART_CLION_PROJ_USER_H
#define INC_7_SHOPPING_CART_CLION_PROJ_USER_H


#include <vector>
#include "Product.h"
#include "Category.h"

class User {
    vector<Product> trolley;

    Category findCategory(int id, vector<Category> categories);
public:
    void addItem();
    void printTrolley(const vector<Category>& categories)
};


#endif //INC_7_SHOPPING_CART_CLION_PROJ_USER_H

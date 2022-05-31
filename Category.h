//
// Created by Nicolas Petras on 30/05/2022.
//

#ifndef INC_7_SHOPPING_CART_CLION_PROJ_CATEGORY_H
#define INC_7_SHOPPING_CART_CLION_PROJ_CATEGORY_H

#include <string>

using namespace std;

class Category
{
public:
    string catName;
    unsigned int catID;
    string catDesc;

    Category();
    Category(string catName, string catDesc, unsigned int catID);
    friend ostream& operator<<(ostream& ob, Category a);
    const string &getCatName() const;
    void setCatName(const string &catName);
    unsigned int getCatId() const;
    void setCatId(unsigned int catId);
    const string &getCatDesc() const;
    void setCatDesc(const string &catDesc);

};

#endif //INC_7_SHOPPING_CART_CLION_PROJ_CATEGORY_H

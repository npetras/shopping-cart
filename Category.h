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

    Category()
    {
        this->catName = "";
        this->catID = 0;
        this->catDesc = "";
    }

    Category(string catName, string catDesc, unsigned int catID)
    {
        this->catName = catName;
        this->catID = catID;
        this->catDesc = catDesc;
    }

    friend ostream& operator<<(ostream& ob, Category a);

    const string &getCatName() const;

    void setCatName(const string &catName);

    unsigned int getCatId() const;

    void setCatId(unsigned int catId);

    const string &getCatDesc() const;

    void setCatDesc(const string &catDesc);

};

ostream& operator<<(ostream& ob, Category a)
{
    ob << a.catName << "\t" << a.catDesc;
    return ob;
}

const string &Category::getCatName() const {
    return catName;
}

void Category::setCatName(const string &catName) {
    Category::catName = catName;
}

unsigned int Category::getCatId() const {
    return catID;
}

void Category::setCatId(unsigned int catId) {
    catID = catId;
}

const string &Category::getCatDesc() const {
    return catDesc;
}

void Category::setCatDesc(const string &catDesc) {
    Category::catDesc = catDesc;
}

#endif //INC_7_SHOPPING_CART_CLION_PROJ_CATEGORY_H

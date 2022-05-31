//
// Created by Nicolas Petras on 31/05/2022.
//

#include "Category.h"

ostream& operator<<(ostream& ob, Category a)
{
    ob << a.catName << "\t" << a.catDesc;
    return ob;
}

Category::Category()
{
    this->catName = "";
    this->catID = 0;
    this->catDesc = "";
}

Category::Category(string catName, string catDesc, unsigned int catID)
{
    this->catName = catName;
    this->catID = catID;
    this->catDesc = catDesc;
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
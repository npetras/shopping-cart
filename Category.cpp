//
// Created by Nicolas Petras on 31/05/2022.
//

#include "Category.h"
#include <iostream>
#include <iomanip>
unsigned int Category::catIDcount =  1;

ostream &operator<<(ostream &ob, Category a) {
    ob << setw(15) << a.catName << setw(20) << a.catDesc;
    return ob;
}

Category::Category() {
    this->catName = "";
    this->catID = 0;
    this->catDesc = "";
}

Category::Category(string catName, string catDesc) {
    this->catName = catName;
    this->catID = Category::catIDcount;
    ++Category::catIDcount;
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


const string &Category::getCatDesc() const {
    return catDesc;
}

void Category::setCatDesc(const string &catDesc) {
    Category::catDesc = catDesc;
}

string Category::trunStr(string str)
{
    string tempStr;
    if (str.length() > MAX_STR_LEN)
    {
        tempStr = str.substr(0, 7);
        tempStr += "...";
    }
    return tempStr;
}
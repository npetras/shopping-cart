#include <iostream>
#include <vector>
#include <unordered_map>

#include "Category.h"
#include "Product.h"

using namespace std;

void addItem(vector<Product> products, vector<Product> &trolley, unordered_map<int, int> productQuantity)
{
    int givenID;
    cout << "Search for product ID: ";
    cin >> givenID;

    for (Product &p : products)
    {
        if (givenID == p.getId()) {
            trolley.push_back(p);
            auto mapIt = productQuantity.find(p.getId());

            if (mapIt == productQuantity.end()) {
                productQuantity.insert({p.getId(), 0});
            } else {
                productQuantity[p.getId()] = productQuantity[p.getId()] + 1;
            }
        }
    }
}

void removeItem(vector<Product> &trolley)
{
    int givenID;
    cout << "Remove product ID: ";
    cin >> givenID;

    for (int i = 0; i < trolley.size(); i++)
    {
        if (givenID == trolley[i].getId()) {
            trolley.erase(trolley.begin()+i);
        }
    }
}

Category findCategory(int id, vector<Category> categories) {
    for (Category &c : categories) {
        if (id == c.getCatId()) {
            return c;
        }
    }
}

void printTrolley(const vector<Product>& products, const vector<Category>& categories) {
    cout << "ID\tName\tPrice\tCategory\tDescription" << endl;
    for (auto & product : products) {
        Category category = findCategory(product.getCategoryId(), categories);
        cout << product << category;
    }
}

int main()
{
    int ch;
    vector<Product> products;
    vector<Category> categories;
    vector<Product> trolley;
    unordered_map<int, int> productQuantity;

    Category soap("soap", "For cleaning", 1);
    Category food("food", "For eating", 2);
    Category sweets("sweets", "For eating too", 3);

    categories.push_back(soap);
    categories.push_back(food);
    categories.push_back(sweets);

    Product digestives(1, "Digestives", 10, 2);
    products.push_back(digestives);

    while (1)
    {
        cout << "Trolley" << endl;
        printTrolley(trolley, categories);

        cout << "\nWhat do you want to do?";
        cout << "1. Add Items  2. Remove from Trolley";
        cin >> ch;



        switch (ch)
        {
            case 1:
                addItem(products, trolley, productQuantity);
                break;

            case 2:
                removeItem(trolley);
                break;
        }
    }


}

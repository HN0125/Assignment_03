#include <iostream>
#include "Product.h"
using namespace std;


int Product::totalProducts = 0;

void Product::copyName(const char name[])
{
    int i = 0;

    while (name[i] != '\0' && i < 49)
    {
        productName[i] = name[i];
        i++;
    }

    productName[i] = '\0';
}

void Product::copyCategory(const char category[])
{
    int i = 0;

    while (category[i] != '\0' && i < 29)
    {
        this->category[i] = category[i];
        i++;
    }

    this->category[i] = '\0';
}

Product::Product(int productID, const char productName[],
    const char category[], double price, int quantity)
    : productID(productID)
{
    copyName(productName);
    copyCategory(category);

    this->price = price;
    this->quantity = quantity;

    totalProducts++;
}

Product::~Product()
{
    totalProducts--;
}

int Product::getProductID() const
{
    return productID;
}

double Product::getPrice() const
{
    return price;
}

int Product::getQuantity() const
{
    return quantity;
}

void Product::display() const
{
    cout << "Product ID: " << productID;
    cout << "Name: " << productName;
    cout << "Category: " << category;
    cout << "Price: Rs. " << price;
    cout << "Quantity: " << quantity << std::endl;
}

int Product::operator+(const Product& other) const
{
    if (productID == other.productID)
    {
        return quantity + other.quantity;
    }

    cout << "Cannot combine products with different IDs."
        << std::endl;

    return -1;
}

bool Product::operator==(const Product& other) const
{
    return productID == other.productID;
}

bool Product::operator>(const Product& other) const
{
    return price > other.price;
}

Product& Product::operator++()
{
    quantity++;
    return *this;
}

Product Product::operator++(int)
{
    Product temp(*this);
    quantity++;
    return temp;
}

void Product::showTotalProducts()
{
    cout << "Total Products: " << totalProducts << endl;
}

std::ostream& operator<<(std::ostream& out, const Product& product)
{
    out << "Product ID: " << product.productID;
    out << "Name: " << product.productName;
    out << "Category: " << product.category;
    out << "Price: Rs. " << product.price;
    out << "Quantity: " << product.quantity << endl;

    return out;
}
void ResourceManager::updateStock(Product& product, int amount)
{
    if (amount > 0)
    {
        product.quantity += amount;

        std::cout << "Stock updated successfully" << endl;
    }
    else
    {
        std::cout << "Invalid quantity" << endl;
    }
}

void ResourceManager::displayInventory(Product* products[], int count)
{
    std::cout << "Complete Inventory" << endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << *products[i];
    }
}

void updateProductStock(Product* product, int amount)
{
    if (product != nullptr && amount > 0)
    {
        // Using the public getter is not enough to update private stock.
        // ResourceManager performs the actual update.
        ResourceManager manager;
        manager.updateStock(*product, amount);
    }
}


#pragma once
class Product
{
private:
    const int productID;
    char productName[50];
    char category[30];
    double price;
    int quantity;

    static int totalProducts;

    void copyName(const char name[]);
    void copyCategory(const char category[]);

public:
    Product(int productID, const char productName[],
        const char category[], double price, int quantity);

    ~Product();

    int getProductID() const;
    double getPrice() const;
    int getQuantity() const;

    void display() const;

    int operator+(const Product& other) const;
    bool operator==(const Product& other) const;
    bool operator>(const Product& other) const;

    Product& operator++();
    Product operator++(int);

    static void showTotalProducts();

    friend class ResourceManager;

    friend std::ostream& operator<<(std::ostream& out,
        const Product& product);
};

class ResourceManager
{
public:
    void updateStock(Product& product, int amount);
    void displayInventory(Product* products[], int count);
};

void updateProductStock(Product* product, int amount);


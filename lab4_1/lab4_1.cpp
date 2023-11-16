#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;
    bool onPromotion;

    Product(const string& n, double p, bool promo) {
        this->name = n;
        this->price = p;
        this->onPromotion = promo;
    }
    string getName() const
    {
        return name;
    }
    double getPrice() const
    {
        return price;
    }
    bool isOnPromotion() const
    {

        return onPromotion;
    }


    void setPrice(double newPrice) {
        price = newPrice;
    }
    void setPromotion(bool promotionStatus)
    {
        onPromotion = promotionStatus;
    }
};

class Category
{


public:
    string name;
    vector<Product> products;
    string getName() const
    {
        return name;
    }
    Category(const string& n)
    {
        this->name = n;
    }
    const vector<Product>& getProducts() const {
        return products;
    }

    void addProduct(const Product& product) {
        products.push_back(product);
    }
    void removeProduct(const string& productName) {
        for (int i = 0; i < products.size(); ++i) {
            if (products[i].name == productName) {
                cout << productName << " has been removed from the category" << endl;
                products.erase(products.begin() + i);
                return;
            }
        }
    }
    void updateProduct(const string& productName, double newPrice, bool onPromotion) {
        for (int i = 0;i < products.size();++i)
        {
            if (products[i].name == productName)
            {
                products[i].price = newPrice;
                products[i].onPromotion = onPromotion;
                return;

            }
        }


    }
};
class OnlineShop {
public:
    vector<Category> categories;

    void addCategory(Category& category) {
        categories.push_back(category);
    }
    void addProductToCategory(const string& categoryName, const Product& product) {
        for (size_t i = 0; i < categories.size(); ++i) {
            if (categories[i].getName() == categoryName) {
                categories[i].addProduct(product);
                return;
            }
        }
        cout << "Category not found. Product not added." << endl;
    }
    void displayAllProducts() const {
        std::cout << "All Products in the Shop:" << std::endl;
        for (size_t i = 0; i < categories.size(); ++i) {
            const Category& category = categories[i];
            const std::vector<Product>& products = category.getProducts();  
            for (size_t j = 0; j < products.size(); ++j) {
                const Product& product = products[j];
                std::cout << "Category: " << category.getName() << ", Product: " << product.getName()
                    << ", Price: " << product.getPrice() << ", Promotion: " << (product.isOnPromotion() ? "Yes" : "No")
                    << std::endl;
            }
        }
    }

    void searchProductsByName(const string& productName) {
        cout << "Search Results for Product Name '" << productName << "':" << endl;
        for (int i = 0; i < categories.size(); ++i) {
            Category& category = categories[i];
            for (int j = 0; j < category.products.size(); ++j) {
                Product& product = category.products[j];
                if (product.name == productName) {
                    cout << "Category: " << category.name << ", Product: " << product.name
                        << ", Price: " << product.price << ", Promotion: ";
                    if (product.onPromotion) {
                        cout << "Yes";
                    }
                    else {
                        cout << "No";
                    }
                    cout << endl;
                }
            }
        }
    }
    void removeCategory(string& categoryName) {
        for (int i = 0; i < categories.size(); ++i) {
            if (categories[i].name == categoryName) {
                cout << categoryName << " has been removed from the OnlineShop" << endl;
                categories.erase(categories.begin() + i);
                return;
            }
        }
    }
    void removeProductFromCategory(const string& categoryName, const string& productName) {
        for (size_t i = 0; i < categories.size(); ++i) {
            if (categories[i].getName() == categoryName) {
                categories[i].removeProduct(productName);
                return;
            }
        }
        cout << "Category not found. Product not removed." << endl;
    }
    void displayPromotionalProducts() const {
        cout << "Promotional Products in the Shop:" << endl;
        for (size_t i = 0; i < categories.size(); ++i) {
            const Category& category = categories[i];
            for (size_t j = 0; j < category.products.size(); ++j) {
                const Product& product = category.products[j];
                if (product.onPromotion) {
                    cout << "Category: " << category.name << ", Product: " << product.name
                        << ", Price: " << product.price << endl;
                }
            }
        }
    }

    void searchProductsByName(const string& productName) const {
        cout << "Search Results for Product Name '" << productName << "':" << endl;
        for (size_t i = 0; i < categories.size(); ++i) {
            const Category& category = categories[i];
            for (size_t j = 0; j < category.products.size(); ++j) {
                const Product& product = category.products[j];
                if (product.name == productName) {
                    cout << "Category: " << category.name << ", Price: " << product.price
                        << ", Promotion: " << (product.onPromotion ? "Yes" : "No") << endl;
                }
            }
        }
    }

    void searchProductsByPrice(double maxPrice) const {
        cout << "Search Results for Products with Price <= " << maxPrice << ":" << endl;
        for (size_t i = 0; i < categories.size(); ++i) {
            const Category& category = categories[i];
            for (size_t j = 0; j < category.products.size(); ++j) {
                const Product& product = category.products[j];
                if (product.price <= maxPrice) {
                    cout << "Category: " << category.name << ", Product: " << product.name
                        << ", Promotion: " << (product.onPromotion ? "Yes" : "No") << endl;
                }
            }
        }
    }

    void searchProductsByCategory(const string& categoryName) const {
        cout << "Search Results for Products in Category '" << categoryName << "':" << endl;
        for (size_t i = 0; i < categories.size(); ++i) {
            const Category& category = categories[i];
            if (category.name == categoryName) {
                for (size_t j = 0; j < category.products.size(); ++j) {
                    const Product& product = category.products[j];
                    cout << "Product: " << product.name << ", Price: " << product.price
                        << ", Promotion: " << (product.onPromotion ? "Yes" : "No") << endl;
                }
                return;
            }
        }
        cout << "Category not found." << endl;
    }
    void updateProductInCategory(const string& categoryName, const string& productName, double newPrice, bool onPromotion) {
        for (size_t i = 0; i < categories.size(); ++i) {
            if (categories[i].getName() == categoryName) {
                categories[i].updateProduct(productName, newPrice, onPromotion);
                return;
            }
        }
        cout << "Category not found. Product not updated." << endl;
    }
};

int main() {
    
    OnlineShop myShop;

    
    Category electronics("Electronics");
    Category clothing("Clothing");

    myShop.addCategory(electronics);
    myShop.addCategory(clothing);

  
    Product laptop("Laptop", 1200.0, true);
    Product tshirt("T-Shirt", 20.0, false);

   
    electronics.addProduct(laptop);
    clothing.addProduct(tshirt);

    myShop.addProductToCategory("Electronics", laptop);
    myShop.addProductToCategory("Clothing", tshirt);

    
    myShop.displayAllProducts();

  
    myShop.displayPromotionalProducts();

    
    myShop.searchProductsByName("T-Shirt");

    
    myShop.searchProductsByPrice(1000.0);

    
    myShop.searchProductsByCategory("Electronics");

    electronics.updateProduct("Laptop", 1500.0, false);

    myShop.removeProductFromCategory("Clothing", "T-Shirt");
    
    myShop.updateProductInCategory("Electronics", "Laptop", 1500.0, false);

   
    myShop.displayAllProducts();


    return 0;
}
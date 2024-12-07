#include <iostream>
using namespace std;

class Product {
private:
    string name;
    int amount;
    double price;

public:
    explicit Product(const string name, const int amount, const double price) {
        if(name.empty())
            throw invalid_argument("You can not have an empty name for a product!\n");
        if(amount < 0)
            throw invalid_argument("You can not have a negative amount of items for a product's stock!\n");
        if(price < 0)
            throw invalid_argument("You can not have a negative price for a product!\n");

        this->name = name;
        this->amount = amount;
        this->price = price;
    }

    double get_price(int amountToBuy) {
        double discount;
        if(amount < 10) {
            discount = 0.0;
        } else if (amount < 100) {
            discount = 0.1;
        } else {
            discount = 0.2;
        }

        return (1.0 - discount) * price * double(amountToBuy);
    }

    void make_purchase(int amountToBuy) {
        if(amountToBuy > this->amount) {
            throw invalid_argument("You can not buy more products than current stock! \n");
        }

        this->amount -= amountToBuy;
        cout << amountToBuy << " " << this->name << " successfully bought.\n";
        cout << "Stock amount left: " << this->amount << endl;
    }
};

int main() {
    // Product product("", 10, 20);

    Product product("Play-Station 4", 100, 329.99);
    cout << "Price for 10 Play-Station 4: " << product.get_price(10) << endl;
    cout << "Price for 200 Play-Station 4: " << product.get_price(200) << endl;
    // product.make_purchase(200);
    product.make_purchase(10);
}
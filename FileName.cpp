#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Product {
    string name;
    double price;
    Product() : price(0) {}
};
class Market
{
protected:
    int NumOfProduct;
    string Marketname;
    string regular;
    double Total;
    double Returnamount;
    double cash;
    int NumOfCustomerProducts;
    Product newProduct;
public:
    Market() : NumOfCustomerProducts(0) {}
    void getMarketName();
    void getProductinfo();
    void confirmMarket();
    void bill(const string& customerName, const string& customerAddress, const string& customerPhoneNumber);
    string CustomerProducts[250];
    int CustomerQuantity[250];
    double CustomerTotal[250];
    string ProductsNames[250];
    double ProductsPrice[250];
    void addNewProduct(vector<Product>& products);
};

class Customer : public Market
{
private:
    string CustomerName;
    string CustomerAddress;
    string CustomerPhoneNumber;

public:
    void askCustomer();
};

void Market::bill(const string& customerName, const string& customerAddress, const string& customerPhoneNumber)
{
    Total = 0;
    cout << "\n\n\nCustomer Name: " << customerName << endl;
    cout << "Customer Address: " << customerAddress << endl;
    cout << "Customer Phone: " << customerPhoneNumber << endl;
    cout << "\n\nProducts\t" << "Quantity\t" << "Price" << endl;
    for (int counter = 0; counter < NumOfCustomerProducts; counter++)
    {
        cout << CustomerProducts[counter] << "\t\t" <<
            CustomerQuantity[counter] << "\t\t" << CustomerTotal[counter] << "\n" << endl;
        Total += CustomerTotal[counter];
    }
    cout << "Total: " << Total << endl;
    cout << "enter your cash" << endl;
    cin >> cash;
    Returnamount = cash - Total;
    cout << "Returnamount:" << Returnamount << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////\n";
}

void Market::getMarketName()
{
    cout << "Hello, welcome to bill management system...\n\nPlease enter your market name: ";
    cin.ignore();
    getline(cin, Marketname);
}

void Market::getProductinfo()
{
    cout << "\nHow many Products do have in your Market: ";
    cin >> NumOfProduct;
    cin.ignore(); // Clear input buffer
    cout << "\nplease, Enter the name of products" << endl;

    for (int counter = 0; counter < NumOfProduct; counter++)
    {
        cout << "Enter product " << counter + 1 << " name: ";
        getline(cin, ProductsNames[counter]);

        cout << "Enter (" << ProductsNames[counter] << ") price: ";
        cin >> ProductsPrice[counter];
        cin.ignore(); // Clear input buffer
    }
}

void Market::confirmMarket()
{
    cout << "\nBill System Configured successfully...\n\n\n\n";
    cout << "\nHello, welcome to " << Marketname << " market...\n" << endl;
}

void Customer::askCustomer()
{
    cout << "\nare you a regular customer? (yes or no)" << endl;
    getline(cin, regular);

    if (regular == "yes")
    {
        cout << "Please enter your name :";
        getline(cin, CustomerName);
        cout << "\nPlease enter your Address :";
        getline(cin, CustomerAddress);
        cout << "\nPlease enter your phone number:";
        getline(cin, CustomerPhoneNumber);

        cout << "\nEnter the name of product or (print) to show the bill: ";
        cin >> CustomerProducts[NumOfCustomerProducts];
        cin.ignore(); // Clear input buffer

        while (CustomerProducts[NumOfCustomerProducts] != "print")
        {
            cout << "\nEnter quantity:";
            cin >> CustomerQuantity[NumOfCustomerProducts];
            cin.ignore();

            for (int counter = 0; counter < NumOfProduct; counter++)
            {
                if (CustomerProducts[NumOfCustomerProducts] == ProductsNames[counter])
                {
                    CustomerTotal[NumOfCustomerProducts] = ProductsPrice[counter] * CustomerQuantity[NumOfCustomerProducts];
                    break;
                }
                else if (CustomerProducts[NumOfCustomerProducts] == newProduct.name) {
                    CustomerTotal[NumOfCustomerProducts] = newProduct.price * CustomerQuantity[NumOfCustomerProducts];
                }

            }

            NumOfCustomerProducts++;
            cout << "\n\nEnter the name of product of (print) to show the bill: ";
            getline(cin, CustomerProducts[NumOfCustomerProducts]);
        }
        bill(CustomerName, CustomerAddress, CustomerPhoneNumber);
    }

    else
    {
        cout << "\nWould you like to be a regular customer?";
        getline(cin, regular);

        if (regular == "no") // if no, then the bill will show only the products and prices	and total
        {
            cout << "\n\nEnter the name of product or (print) to show the bill: "; // let the customer enter only the products he took
            cin >> CustomerProducts[NumOfCustomerProducts];

            while (CustomerProducts[NumOfCustomerProducts] != "print")
            {
                cout << "\nEnter quantity: ";
                cin >> CustomerQuantity[NumOfCustomerProducts];
                cin.ignore();

                for (int counter = 0; counter < NumOfProduct; counter++)
                {
                    if (CustomerProducts[NumOfCustomerProducts] == ProductsNames[counter])
                    {
                        CustomerTotal[NumOfCustomerProducts] = ProductsPrice[counter] * CustomerQuantity[NumOfCustomerProducts];
                        break;
                    }
                }
                NumOfCustomerProducts++;
                cout << "\n\nEnter the name of product of (print) to show the bill: ";
                getline(cin, CustomerProducts[NumOfCustomerProducts]);

            }

            bill(CustomerName, CustomerAddress, CustomerPhoneNumber);
        }


        else // if yes then, this mean that the customer want to be a regular
        {
            cout << "please, Enter your name: ";
            getline(cin, CustomerName);
            cout << "\nplease, Enter your Address: ";
            getline(cin, CustomerAddress);
            cout << "\nplease, Enter your Phone Number: ";
            getline(cin, CustomerPhoneNumber);
            cout << "\n\nEnter the name of product or (print) to show the bill: ";
            cin >> CustomerProducts[NumOfCustomerProducts];
            cin.ignore();

            while (CustomerProducts[NumOfCustomerProducts] != "print")
            {
                cout << "\nEnter quantity: ";
                cin >> CustomerQuantity[NumOfCustomerProducts];
                cin.ignore();
                for (int counter = 0; counter < NumOfProduct; counter++)
                {
                    if (CustomerProducts[NumOfCustomerProducts] == ProductsNames[counter])
                    {
                        CustomerTotal[NumOfCustomerProducts] = ProductsPrice[counter] * CustomerQuantity[NumOfCustomerProducts];

                    }
                }

                NumOfCustomerProducts++;
                cout << "\n\nEnter the name of product or (print) to show the bill: ";
                cin >> CustomerProducts[NumOfCustomerProducts];
            }

            bill(CustomerName, CustomerAddress, CustomerPhoneNumber);
        }

    }
}

void Market::addNewProduct(vector<Product>& products) {
    Product newProduct;
    cout << "Enter product name: ";
    cin >> newProduct.name;
    cout << "Enter product price: ";
    cin >> newProduct.price;
    products.push_back(newProduct);


    ProductsNames[NumOfProduct] = newProduct.name;
    ProductsPrice[NumOfProduct] = newProduct.price;

    NumOfProduct++;
    cout << "Product added successfully." << endl;
}

int main()
{
    int n;
    Customer a;
    vector<Product> products;
    do {
        cout << "\t\t\t\t_\n";
        cout << "\t\t\t\t                                         \n";
        cout << "\t\t\t\t          Supermarket Main Menu          \n";
        cout << "\t\t\t\t                                         \n";
        cout << "\t\t\t\t_\n";
        cout << "1)  Manegar\n";
        cout << "2)  Customer\n";
        cout << "3)  Exit\n";
        cout << "please select a choice\n";
        cin >> n;
        switch (n) {
        case 1: {
            int s;
            do {
                cout << "1) Get Market Name\n";
                cout << "2) Add the product\n";
                cout << "3) Add new product\n";
                cout << "4)Exit\n";
                cout << "please enter your choice\n";
                cin >> s;
                switch (s) {
                case 1: {
                    a.getMarketName();
                    break;
                }
                case 2: {
                    a.getProductinfo();
                    break;
                }
                case 3: {
                    a.addNewProduct(products);
                    break;
                }

                }
            } while (s != 4);

            break;
        }
        case 2: {
            a.askCustomer();
            break;
        }
        case 3: {
            return 0;
        }
        default: {
            cout << "select 1from the given options only";
        }
        }
    } while (true);
    return 0;
}
//
SHOBHA DUSEJA
24K-1006
//
#include <iostream>
using namespace std;

struct Product{
    int productID;
    string name;
    int quantity;
    double price;
};

Product* createInv(int n){
    Product* prodInv = new Product[n];
    cout << "Inventory IS created" << endl;
    return prodInv;
}
void Details(Product* products, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Details for Product " << i+1 << ": " << endl;
        cout << "ProductID: ";
        cin >> products[i].productID;
        cout << "Name: ";
        cin.ignore();
        getline(cin, products[i].name);
        cout << "Quantity: ";
        cin >> products[i].quantity;
        cout << "Price: ";
        cin >> products[i].price;
    }
}

void display(Product* products, int n){
    double sum = 0.0;
    for (int i = 0; i < n; i++){
        sum += (float)products[i].quantity*products[i].price;
    }
    cout << "Total Value of Inventory is : " << sum << endl;
}

void free(Product* products){
    delete[] products;
}


int main(){
    int size;
    cout << "Enter the size: ";
    cin >> size;
    Product* products = createInv(size);
    Details(products, size);
    display(products, size);
    free(products);
    return 0;
}

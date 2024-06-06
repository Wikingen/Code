#include <iostream>
using namespace std;

struct Order
{
    int orderID;
    double totalPrice;
    string items[5];
    double price[5];
};

struct Customer
{
    string name;
    string address;
    Order order;
};

// Updates the address of the customer at index 'customer_index' in the 'customer_array' as 'new_address'
void updateCustomerAddress(Customer customer_array[], int customer_index, string new_address) // err: return type should be void
{
    customer_array[customer_index].address = new_address;
}

int main()
{
    Order order1;
    // Assign values to order1's attributes
    order1.orderID = 153;

    string items[5] = {"cabbage", "carrot", "eggs", "milk", "yogurt"};
    double price[5] = {1.49, 2.99, 5.99, 4.00, 5.00};
    double total = 0;
    for (int i = 0; i < 5; i++)
    {
        order1.items[i] = items[i];
        order1.price[i] = price[i];
        total += price[i];
    }
    order1.totalPrice = total;

    // Declare and initialize order2 with order1's attributes
    Order order2 == order1; // err: Order order2 = order1
    // Update the orderID for order2
    order2.orderID = 154;

    // Create an array of Customer objects
    Customer customer1 = {"Jake", "1855 Athens St", order1}; // err: customer1
    Customer customer2 = {"John", "2156 Grove St", order2};  // err: customer2
    Customer customers[2] = {customer1, customer2};        // err: {customer1, customer2}

    updateCustomerAddress(customers, 1, "1475 Folsom St");

    cout << "Updated customer details: " << endl;
    cout << "Name | Address | Order ID | Total Price" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << customers[i].name << " | " << customers[i].address << " | "
             << customers[i].order.orderID << " | " << customers[i].order.totalPrice << endl; // err: customers[i].order.orderID, customers[i].order.totalPrice
    }

    return 0;
}

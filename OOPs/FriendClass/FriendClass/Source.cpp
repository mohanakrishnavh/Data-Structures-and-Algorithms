#include <iostream>
#include <string>

using namespace std;

//Friend Class Example
class Customer {
private:
	friend class GetCustomerData;
	string name;
public:
	Customer(string name) {
		this->name = name;
	}
};
class GetCustomerData {
public:
	static string getCustName(Customer& customer) {
		return customer.name;
	}
};

int main() {
	Customer customer1("Customer 1");
	GetCustomerData getName;
	cout << "Name : " << getName.getCustName(customer1) << endl;
	
	return 0;
}
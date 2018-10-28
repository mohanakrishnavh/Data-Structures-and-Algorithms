#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RealWorldObject {
//Private members are available only to methods inside the class
private:
	string name;
	double height;
	double weight;

	//static variable - shares the same value for all objects
	static int numOfObjects;

//Public members(variables and methods) can be accessed by anything that has access to object
public:
	string getName() {
		return name;
	}
	void setName(string name) {
		//this keyword is used to refer to current object member
		this->name = name;
	}

	double getHeight() {
		return height;
	}
	void setHeight(double height) {
		this->height = height;
	}

	double getWeight() {
		return weight;
	}
	void setWeight(double weight) {
		this->weight = weight;
	}

	void setAll(string, double, double);
	RealWorldObject(string, double, double);
	RealWorldObject();
	~RealWorldObject();

	//static methods can only access static fields
	static int getNumOfObjects() {
		return numOfObjects;
	}

	void toString();
};

int RealWorldObject::numOfObjects = 0;

void RealWorldObject::setAll(string name, double height, double wright) {
	this->name = name;
	this->weight = weight;
	this->height = height;
	RealWorldObject::numOfObjects++;
}

RealWorldObject::RealWorldObject(string name, double height, double weight) {
	this->name = name;
	this->weight = weight;
	this->height = height;
	RealWorldObject::numOfObjects++;
}

RealWorldObject::RealWorldObject() {
	this->name = "default";
	this->weight = 0;
	this->height = 0;
	RealWorldObject::numOfObjects++;
}

RealWorldObject::~RealWorldObject() {
	cout << "\nRealWorldObject " << this->name << " destroyed.\n";
}

void RealWorldObject::toString() {
	cout << "\n";
	cout << this->name << endl;
	cout << this->height << endl;
	cout << this->weight << endl;
	cout << "\n";
}


class Dog : public RealWorldObject {
private:
	string sound = "Woof";
public:
	void makeSound() {
		cout << "The dog " << this->getName() << " says " << this->sound << endl;
	}
	Dog(string, double, double, string);
	Dog() : RealWorldObject() {};
	void toString();
};

Dog::Dog(string name, double height, double weight, string sound) :
	RealWorldObject(name, height, weight) {
		this->sound = sound;
	}

void Dog::toString() {
	cout << "\n";
	cout << this->getName() << endl;
	cout << this->getHeight() << endl;
	cout << this->getWeight() << endl;
	cout << this->sound << endl;
	cout << "\n";
}

int main() {
	RealWorldObject obj1;
	obj1.toString();

	obj1.setName("Object 1");
	obj1.setHeight(10);
	obj1.setWeight(100);
	obj1.toString();

	RealWorldObject obj2("Object 2", 20.0, 200.0);
	obj2.toString();

	Dog dog1("Dog1", 28, 16, "Woooooof");
	dog1.toString();

	cout << "Number of objects : " << RealWorldObject::getNumOfObjects() << "\n";

	return 0;
}
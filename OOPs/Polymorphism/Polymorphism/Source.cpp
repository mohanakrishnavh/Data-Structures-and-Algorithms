#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
public:
	virtual double Area() = 0;
};

class Circle : public Shape {
protected:
	double width;
public:
	Circle(double w){
		width = w;
	}

	double Area() override {
		return 3.14159 * pow((width / 2), 2);
	}
};


class Rectangale : public Shape {
protected:
	double height, width;
public:
	Rectangale(double h, double w) {
		height = h;
		width = w;
	}

	//If marked final, we can't override it
	double Area() override final {
		return height* width;
	}
};


//Works for Shape or any sub-class of shape
void showArea(Shape& shape) {
	cout << "Area : " << shape.Area() << endl;
}

int main() {
	Rectangale rectangle(10, 5);
	Circle circle(10);
	showArea(rectangle);
	showArea(circle);

	return 0;
}
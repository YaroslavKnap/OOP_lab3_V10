#include <iostream>
#include <stdexcept>
#include <cmath>

const double PI = 3.14159265358979323846; // Define the PI constant

class Circle {
private:
    double radius; // Radius of the circle

public:
    Circle() : radius(0.0) {}

    // Overloading the input operator >>
    friend std::istream& operator>>(std::istream& in, Circle& circle) {
        std::cout << "Enter the radius of the circle: ";
        in >> circle.radius;

        // Check for input errors
        if (in.fail()) {
            in.clear();
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Incorrect value of circle radius.");
        }

        return in;
    }

    // Output operator overloading <<
    friend std::ostream& operator<<(std::ostream& out, const Circle& circle) {
        out << "A circle with a radius " << circle.radius << ", Area: " << circle.calculateArea()
            << ", Circuit: " << circle.calculateCircumference();
        return out;
    }

    // Method for calculating the area of ??a circle
    double calculateArea() const {
        return PI * radius * radius;
    }

    // Method for calculating the length of a circle
    double calculateCircumference() const {
        return 2 * PI * radius;
    }

    // Method for outputting shape data
    void printData() const {
        std::cout << "The radius of the circle: " << radius << std::endl;
        std::cout << "Circle area: " << calculateArea() << std::endl;
        std::cout << "Circuit: " << calculateCircumference() << std::endl;
    }
};

int main() {
    try {
        Circle myCircle;

        // Enter data about the circle
        std::cin >> myCircle;

        // Output data about the circle
        std::cout << myCircle << std::endl;

        // Output data about the shape
        myCircle.printData();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

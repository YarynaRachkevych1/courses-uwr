#include "Triangle.hpp"

Triangle::Triangle() {
    a = 1.0;
    b = 1.0;
    c = 1.0;
    name = "Trojkat";
}

Triangle::Triangle(double _a, double _b, double _c, std::string _name) {
    if (!isTriangle(_a, _b, _c)) {
        throw std::invalid_argument("Warunek trojkata nie jrst spelniony");
    }
    else {
        a = _a;
        b = _b;
        c = _c;
        name = _name;
    }

}
double Triangle::getA() const {
    return a;
}
double Triangle::getB() const {
    return b;
}
double Triangle::getC() const {
    return c;
}
double Triangle::perimeter() const {
    return a + b + c;
}
double Triangle::area() const {
    double p = perimeter() / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
    os << "Nazwa: " << triangle.name << ", Strona A: " << triangle.a << ", Strona B: " << triangle.b << ", Strona C: " << triangle.c;
    return os;
}
bool Triangle::isTriangle(double a, double b, double c) {
    return (a + b > c) && (b + c > a) && (c + a > b);
}
bool Triangle::isAcuteTriangle() const {
    bool checkA = (b * b) + (c * c) > (a * a);
    bool checkB = (a * a) + (c * c) > (b * b);
    bool checkC = (a * a) + (b * b) > (c * c);
    return checkA && checkB && checkC;
}

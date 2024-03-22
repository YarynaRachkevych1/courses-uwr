#include <iostream>
#include <vector>
#include <functional>
#include "Triangle.hpp"

int main() {
    std::vector<Triangle> triangles = {
            Triangle(9.0, 12.0, 5.0, "Trojkat1"),
            Triangle(5.0, 12.0, 13.0, "Trojkat2"),
            Triangle(4.0, 7.0, 9.0, "Trojkat3"),
            Triangle(8.0, 8.0, 10.0, "Trojkat4"),
            Triangle(27.0, 27.0, 29.0, "Trojkat5")
    };

    std::sort(triangles.begin(), triangles.end(), [](const Triangle& t1, const Triangle& t2) {
        return t1.perimeter() < t2.perimeter();
    });

    std::cout << "Trojkaty posortowane wedlug dlugosci obwodu: " << std::endl;
    for (const auto& triangle : triangles) {
        std::cout << triangle << ", Obwod: " << triangle.perimeter() << std::endl;
    }

    auto minMaxArea = std::minmax_element(triangles.begin(), triangles.end(), [](const Triangle& t1, const Triangle& t2) {
        return t1.area() > t2.area();
    });

    std::cout << "\nTrojkat o najwiekszym polu: " << *minMaxArea.first << ", Pole: " << (*minMaxArea.first).area() << std::endl;
    std::cout << "Trojkat o najmniejszym polu: " << *minMaxArea.second << ", Pole: " << (*minMaxArea.second).area() << std::endl;

    std::cout << "\nTrojkaty ostrokatne: " << std::endl;
    std::for_each(triangles.begin(), triangles.end(), [](const Triangle& triangle) {
        if (triangle.isAcuteTriangle()) {
            std::cout << triangle << std::endl;
        }
    });

    return 0;
}

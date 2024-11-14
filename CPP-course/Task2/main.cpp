#include <iostream>
#include "point.h"
#include "vector.h"
#include "line_segment.h"
#include "triangle.h"

using namespace std;

int main() {
    Point p1(-4, 2);
    Point p2(4, -2);

    //Prezentacja działania klasy punktu
    cout << "--Klasa punkt--" << endl;
    cout << "Koordynaty punktu1: " << p1.getX() << " " << p1.getY() << endl;
    cout << "Koordynaty punktu2: " << p2.getX() << " " << p2.getY() << endl;
    cout << "Dystans pomiedzy punktem1 i punktem2: " << p1.distanceTo(p2) << endl;
    cout << "Przesuniecie punktu1 o wektor [0,2]" << endl;
    p1.pMoveVector(Vector(0, 2));
    cout << "Koordynaty punktu1: " << p1.getX() << " " << p1.getY() << endl << endl;
    cout << "Obrot punktu1 wokol punktu2 o 45 stopni" << endl;
    p1.rotation(p2, 45);
    cout << "Koordynaty punktu1: " << p1.getX() << " " << p1.getY() << endl << endl;
    cout << "Odbicie punktu1 wzgledem osi OX" << endl;
    p1.xAxisSymetry();
    cout << "Koordynaty punktu1: " << p1.getX() << " " << p1.getY() << endl;
    cout << "Odbicie punktu1 wzgledem osi OY" << endl;
    p1.yAxisSymetry();
    cout << "Koordynaty punktu1: " << p1.getX() << " " << p1.getY() << endl << endl;
    cout << "Odbicie punktu1 wzgledem punkty p2" << endl;
    p1.pSymetry(p2);
    cout << "Koordynaty punktu1: " << p1.getX() << " " << p1.getY() << endl;
    cout << endl << endl;

    //Prezentacja działania klasy odcinek
    cout << "--Klasa odcinek--" << endl;
    LineSegment l1(Point(-1, -3), Point(1, 4));
    LineSegment l2(Point(1, -4), Point(2, 4));
    cout << "Koordynaty odcinka l1: (" << l1.getA().getX() << ' ' << l1.getA().getY() << "), (" << l1.getB().getX()
         << ' ' << l1.getB().getY() << ')' << endl;
    cout << "Koordynaty odcinka l2: (" << l2.getA().getX() << ' ' << l2.getA().getY() << "), (" << l2.getB().getX()
         << ' ' << l2.getB().getY() << ')' << endl;

    cout << "Przesuniecie l1 o wektor [1,1]" << endl;
    l1.pMoveVector(Vector(1, 1));
    cout << "Koordynaty odcinka l1: (" << l1.getA().getX() << ' ' << l1.getA().getY() << "), (" << l1.getB().getX()
         << ' ' << l1.getB().getY() << ')' << endl;
    cout << endl;

    cout << "Obrot l1 wokol p1 o 45 stopni" << endl;
    l1.rotation(p1,  45);
    cout << "Koordynaty odcinka l1: (" << l1.getA().getX() << ' ' << l1.getA().getY() << "), (" << l1.getB().getX()
         << ' ' << l1.getB().getY() << ')' << endl;
    cout << endl;

    cout << "Odbicie l1 wzgledem osi OX" << endl;
    l1.xAxisSymetry();
    cout << "Koordynaty odcinka l1: (" << l1.getA().getX() << ' ' << l1.getA().getY() << "), (" << l1.getB().getX()
         << ' ' << l1.getB().getY() << ')' << endl;
    cout << endl;
    cout << "Odbicie l1 wzgledem osi OY" << endl;
    l1.yAxisSymetry();
    cout << "Koordynaty odcinka l1: (" << l1.getA().getX() << ' ' << l1.getA().getY() << "), (" << l1.getB().getX()
         << ' ' << l1.getB().getY() << ')' << endl;
    cout << endl;

    cout << "Odbicie l1 wzgledem punktu p1" << endl;
    l1.pSymetry(p1);
    cout << "Koordynaty odcinka l1: (" << l1.getA().getX() << ' ' << l1.getA().getY() << "), (" << l1.getB().getX()
         << ' ' << l1.getB().getY() << ')' << endl;
    cout << endl;

    cout << "Czy l1 jest rownolegly wobec l2? : " << l1.isParallel(l2) << endl;
    cout << "Czy l1 jest prostopadly wobec l2? : " << l1.isPerpendicular(l2) << endl;
    cout << "Czy l1 zawiera p1? : " << l1.containsPoint(p1) << endl;
    cout << endl << endl;

    //Prezentacja działania klasy trojkata
    cout << "--Klasa trojkat--" << endl;
    Triangle w1(Point(-5, 5), Point(2, 5), Point(4, 10));
    cout << "Koordynaty jednego wierzcholka w1: " << w1.getA().getX() << " " << w1.getA().getY() << endl;
    cout << "Koordynaty drugiego wierzcholka w1: " << w1.getB().getX() << " " << w1.getB().getY() << endl;
    cout << "Koordynaty trzeciego wierzcholka w1: " << w1.getC().getX() << " " << w1.getC().getY() << endl;
    cout << "Pole w1: " << w1.area() << endl;
    cout << "Obwod w1: " << w1.perimeter() << endl;
    cout << "Przesuniecie t1 o wektor [-1,2]" << endl;
    w1.pMoveVector(Vector(-1, 2));
    cout << "Koordynaty jednego wierzcholka w1: " << w1.getA().getX() << " " << w1.getA().getY() << endl;
    cout << "Koordynaty drugiego wierzcholka w1: " << w1.getB().getX() << " " << w1.getB().getY() << endl;
    cout << "Koordynaty trzeciego wierzcholka w1: " << w1.getC().getX() << " " << w1.getC().getY() << endl;
    cout << endl;
    cout << "Obrot t1 wokol punktu p1 o 45 stopni" << endl;
    w1.rotation(p1, 45);
    cout << "Koordynaty jednego wierzcholka w1: " << w1.getA().getX() << " " << w1.getA().getY() << endl;
    cout << "Koordynaty drugiego wierzcholka w1: " << w1.getB().getX() << " " << w1.getB().getY() << endl;
    cout << "Koordynaty trzeciego wierzcholka w1: " << w1.getC().getX() << " " << w1.getC().getY() << endl;
    cout << endl;
    cout << "Odbicie w1 wzgledem osi OX" << endl;
    w1.xAxisSymetry();
    cout << "Koordynaty jednego wierzcholka w1: " << w1.getA().getX() << " " << w1.getA().getY() << endl;
    cout << "Koordynaty drugiego wierzcholka w1: " << w1.getB().getX() << " " << w1.getB().getY() << endl;
    cout << "Koordynaty trzeciego wierzcholka w1: " << w1.getC().getX() << " " << w1.getC().getY() << endl;
    cout << endl;
    cout << "Odbicie w1 wzgledem osi OY" << endl;
    w1.yAxisSymetry();
    cout << "Koordynaty jednego wierzcholka w1: " << w1.getA().getX() << " " << w1.getA().getY() << endl;
    cout << "Koordynaty drugiego wierzcholka w1: " << w1.getB().getX() << " " << w1.getB().getY() << endl;
    cout << "Koordynaty trzeciego wierzcholka w1: " << w1.getC().getX() << " " << w1.getC().getY() << endl;
    cout << endl;
    cout << "Odbicie w1 wzgledem punktu p1" << endl;
    w1.pSymetry(p1);
    cout << "Koordynaty jednego wierzcholka w1: " << w1.getA().getX() << " " << w1.getA().getY() << endl;
    cout << "Koordynaty drugiego wierzcholka w1: " << w1.getB().getX() << " " << w1.getB().getY() << endl;
    cout << "Koordynaty trzeciego wierzcholka w1: " << w1.getC().getX() << " " << w1.getC().getY() << endl;


    return 0;
}
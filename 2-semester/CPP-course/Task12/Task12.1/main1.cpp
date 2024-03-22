#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
struct SumFunctor {
public:
    // Konstruktor
    SumFunctor() : sum(0), count(0), average(0) {}

    // Operator wywołania
    void operator()(const T& value) {
        sum += value;
        count++;
        average = static_cast<double>(sum) / count;
        cout << "Suma: " << sum << ", Liczba zsumowanych elementow: " << count << ", Srednia arytmetyczna: " << average << endl;
    }

private:
    T sum;
    int count;
    double average;
};

int main() {
    set<int> intSet = { 1, 5, 7, 9, 11 };
    list<float> floatList = { 1.5, 5.25, 7.35, 9.45, 11.55 };
    vector<double> doubleVector = { 1.2, 2.3, 3.4, 4.5, 5.6 };

    // objekty funktora
    SumFunctor<int> intSum;
    SumFunctor<float> floatSum;
    SumFunctor<double> doubleSum;

    for_each(intSet.begin(), intSet.end(), intSum);
    cout << "\n";
    for_each(floatList.begin(), floatList.end(), floatSum);
    cout << "\n";
    for_each(doubleVector.begin(), doubleVector.end(), doubleSum);

    return 0;
}

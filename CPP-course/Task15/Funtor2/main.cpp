#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <algorithm>

template<typename T>
struct SumFunctor {
public:
    SumFunctor() : sum(0), count(0), average(0) {}

    void operator()(const T& value) {
        sum += value;
        count++;
        average = static_cast<double>(sum) / count;
        std::cout << "Current sum: " << sum << ", Count: " << count << ", Average: " << average << std::endl;
    }

private:
    T sum;
    int count;
    double average;
};

int main() {
    std::set<int> intSet = { 1, 2, 3, 4, 5 };
    std::list<float> floatList = { 1.5, 2.5, 3.5, 4.5, 5.5 };
    std::vector<double> doubleVector = { 1.2, 2.3, 3.4, 4.5, 5.6 };

    SumFunctor<int> intSum;
    SumFunctor<float> floatSum;
    SumFunctor<double> doubleSum;

    std::for_each(intSet.begin(), intSet.end(), intSum);
    std::for_each(floatList.begin(), floatList.end(), floatSum);
    std::for_each(doubleVector.begin(), doubleVector.end(), doubleSum);

    return 0;
}
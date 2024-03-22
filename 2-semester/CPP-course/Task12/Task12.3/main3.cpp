#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// szablon funkcji
template<int a, int b>
auto generateRandom() {
    return []() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrb(a, b);
        return distrb(gen);
    };
}

//template<int a, int b>
//class gen_random
//{
//public:
//    gen_random( random_device rd = random_device() )
//     : gen( rd() )
//     , dist( a, b ) {}
//
//     auto operator()() { return dist(gen); }
//private:
//    mt19937 gen;
//    uniform_int_distribution<> dist;
//};

int main() {
    auto randomInt = generateRandom<1, 50>();

    int arrayInts[20];
    generate(begin(arrayInts), end(arrayInts), randomInt);

    cout << "Tablica: ";
    for_each(begin(arrayInts), end(arrayInts), [](int x) {
        cout << x << " ";
    });
    cout << endl;

    vector<int> vectorInts(20);
    generate(begin(vectorInts), end(vectorInts), randomInt);

    cout << "Wektor: ";
    for_each(begin(vectorInts), end(vectorInts), [](int x) {
        cout << x << " ";
    });
    cout << endl;

    auto isPrime = [&](int number) {
        if (number < 2)
            return false;
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0)
                return false;
        }
        return true;
    };

    int primes[10];
    auto primeNum = copy_if(begin(arrayInts), end(arrayInts), begin(primes), isPrime);
    int primeCount = distance(begin(primes), primeNum);

    cout << "Liczby pierwsze z tablicy: ";
    for_each(begin(primes), primeNum, [](int x) {
        cout << x << " ";
    });
    cout << endl;

    cout << "Ilosc liczb pierwszych: " << primeCount << endl;
    return 0;
}

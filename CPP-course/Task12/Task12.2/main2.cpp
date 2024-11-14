#include <iostream>
#include <functional>

using namespace std;

template <typename T>
struct Function {
    T a, b;

    Function(T _a, T _b) : a(_a), b(_b) {}

    T operator()(T x) const {
        // objekty funkcyjne
        multiplies<T> multiply_op;
        plus<T> add_op;

        auto result = bind(add_op, bind(multiply_op, a, placeholders::_1), b);
        return result(x);
    }
};

int main() {
    Function<int> int_f(4, 2);
    Function<float> float_f(5.5f, 5.5f);
    Function<double> double_f(0.5, 1.0);

    cout << "Funkcja liniowa z wartoscia 5: " << int_f(42) << endl;
    cout << "Funkcja liniowa z wartoscia 2.5: " << float_f(1.1f) << endl;
    cout << "Funkcja liniowa z wartoscia 1.5: " << double_f(1.5) << endl;

    return 0;
}

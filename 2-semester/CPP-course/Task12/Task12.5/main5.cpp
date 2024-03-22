#include <iostream>
#include <functional>

int main() {
    int n;

    std::cout << "Podaj wartosc poczatkowa ( > 0): ";
    std::cin >> n;

    std::function<void(int, int)> collatzSequence = [&collatzSequence](int num, int count = 0) {
        std::cout << num << " ";

        if (num == 1) {
            std::cout << std::endl << "Dlugosc ciagu: " << count + 1 << std::endl;
            return;
        }

        if (num % 2 == 0) {
            collatzSequence(num / 2, count + 1);
        } else {
            collatzSequence(3 * num + 1, count + 1);
        }
    };

    collatzSequence(n, 0);

    return 0;
}

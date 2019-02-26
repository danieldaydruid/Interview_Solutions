#include <iostream>
#include <iomanip>
#include <cstddef>

std::size_t Power(std::size_t number, int power);

int main() {
    for(auto i = 0; i <= 20; i++) {
        std::cout << "Power " << i << ":" << std::endl;
        std::cout << "[0]: " << Power(0, i) << std::endl;
        std::cout << "[1]: " << Power(1, i) << std::endl;
        std::cout << "[2]: " << Power(2, i) << std::endl;
        std::cout << "[3]: " << Power(3, i) << std::endl;
        std::cout << "[4]: " << Power(4, i) << std::endl;
        std::cout << "[5]: " << Power(5, i) << std::endl;
        std::cout << "[6]: " << Power(6, i) << std::endl;
        std::cout << "[7]: " << Power(7, i) << std::endl;
        std::cout << "[8]: " << Power(8, i) << std::endl;
        std::cout << "[9]: " << Power(9, i) << std::endl;
        std::cout << "[10]: " << Power(10, i) << std::endl << std::endl;
    }
    return 0;
}

std::size_t Power(std::size_t number, int power) {
    if(power == 0) return 1;
    else {
        std::size_t original_value = number;
        for(auto i = 1; i < power; i++) {
            number *= original_value;
        }
    }
    return number;
}
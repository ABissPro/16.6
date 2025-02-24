#include <iostream>
#include <string>

int main() {
    system("chcp 1251"); // Установить кодировку
    std::string whole_part;
    std::string fractional_part;

    std::cout << "Введите целую часть числа: ";
    std::getline(std::cin, whole_part);

    std::cout << "Введите дробную часть числа: ";
    std::getline(std::cin, fractional_part);

    std::string full_number = whole_part + "." + fractional_part;

    try {
        double result = std::stod(full_number);

        std::cout << "Полученное число: " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: введенная строка не является числом." << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: число выходит за пределы допустимого диапазона." << std::endl;
    }

    return 0;
}

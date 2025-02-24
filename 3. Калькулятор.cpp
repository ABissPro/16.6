#include <iostream>
#include <sstream>
#include <string>

int main()
{
    system("chcp 1251"); // Установить кодировку
    std::string buffer;
    std::cout << "Введите выражение в формате '<число-1><действие><число-2>': ";
    std::getline(std::cin, buffer);

    std::stringstream buffer_stream(buffer); //оборот строки в строковый поток для разбора

    //разбор строки на три компонента
    double num1, num2;
    char op;

    buffer_stream >> num1 >> op >> num2;

    if (op == '+') {
        std::cout << "Результат: " << num1 + num2 << std::endl;
    }
    else if (op == '-') {
        std::cout << "Результат: " << num1 - num2 << std::endl;
    }
    else if (op == '*') {
        std::cout << "Результат: " << num1 * num2 << std::endl;
    }
    else if (op == '/') {
        if (num2 == 0) {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
        }
        else {
            std::cout << "Результат: " << num1 / num2 << std::endl;
        }
    }
    else {
        std::cout << "Недопустимая операция!" << std::endl;
    }
}
#include <iostream>

int main()
{
	system("chcp 1251"); // Установить кодировку
	double speed_value = 0.0;
	char speed_str[10]; // буфер для хранения строки скорости ([]?)
	do {
		std::cout << "Speed delta: ";
		double delta;
		std::cin >> delta;

		speed_value += delta;

		if (speed_value > 150.0) {
			speed_value = 150.0;
		}
		else if (speed_value <= 0.01) { // сравниваем с дельтой 0.01
			break; //выходим из цикла, когда скорость близка к нулю
		}

		std::snprintf(speed_str, sizeof(speed_str), "%.1f", speed_value);

		std::cout << "Speed: " << speed_str << "\n";

	} while (true);
}

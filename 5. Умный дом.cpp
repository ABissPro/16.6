#include <iostream>
#include <string>
#include <sstream>

// Перечисление состояний переключателей
enum Switches {
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

//переменные для хранения текущего состояния системы
int temperatureInside = 0;
int temperatureOutside = 0;
bool hasMovement = false;
bool isLightOn = false;
int colorTemperature = 5000;
int switchesState = 0;

void processInput(std::string input) {
    std::istringstream iss(input);
    iss >> temperatureInside >> temperatureOutside;
    std::string movementStr;
    iss >> movementStr;
    hasMovement = (movementStr == "yes");
    std::string lightStatus;
    iss >> lightStatus;
    isLightOn = (lightStatus == "on");
}

void updateDevices(int time) {
    //Обогрев водопровода
    if (temperatureOutside <= 0 && !(switchesState & WATER_PIPE_HEATING)) {
        switchesState |= WATER_PIPE_HEATING;
        std::cout << "Обогрев водопровода ВКЛ." << std::endl;
    }
    else if (temperatureOutside > 5 && (switchesState & WATER_PIPE_HEATING)) {
        switchesState &= ~WATER_PIPE_HEATING;
        std::cout << "Обогрев водопровода ВЫКЛ." << std::endl;
    }

    //наружное освещение
    if ((time % 24 >= 16 || time % 24 < 5) && hasMovement && !(switchesState & LIGHTS_OUTSIDE)) {
        switchesState |= LIGHTS_OUTSIDE;
        std::cout << "Наружное освещение ВКЛ." << std::endl;
    }
    else if (!hasMovement || (time % 24 < 16 && time % 24 >= 5) && (switchesState & LIGHTS_OUTSIDE)) {
        switchesState &= ~LIGHTS_OUTSIDE;
        std::cout << "Наружное освещение ВЫКЛ." << std::endl;
    }

    //Внутреннее освещение
    if (isLightOn && !(switchesState & LIGHTS_INSIDE)) {
        switchesState |= LIGHTS_INSIDE;
        std::cout << "Внутреннее освещение ВКЛ." << std::endl;
    }
    else if (!isLightOn && (switchesState & LIGHTS_INSIDE)) {
        switchesState &= ~LIGHTS_INSIDE;
        std::cout << "Внутреннее освещение ВЫКЛ." << std::endl;
    }

    //отопление
    if (temperatureInside < 22 && !(switchesState & HEATERS)) {
        switchesState |= HEATERS;
        std::cout << "Отопление ВКЛ." << std::endl;
    }
    else if (temperatureInside >= 25 && (switchesState & HEATERS)) {
        switchesState &= ~HEATERS;
        std::cout << "Отопление ВЫКЛ." << std::endl;
    }

    //кондиционер
    if (temperatureInside >= 30 && !(switchesState & CONDITIONER)) {
        switchesState |= CONDITIONER;
        std::cout << "Кондиционер ВКЛ." << std::endl;
    }
    else if (temperatureInside <= 25 && (switchesState & CONDITIONER)) {
        switchesState &= ~CONDITIONER;
        std::cout << "Кондиционер ВЫКЛ." << std::endl;
    }

    //Цветовая температура освещения
    if (isLightOn && (time % 24 >= 16 && time % 24 < 20)) {
        colorTemperature = 5000 + (2700 - 5000) * (time % 24 - 16) / 4;
        std::cout << "Цветовая температура: " << colorTemperature << "K" << std::endl;
    }
    else if (time % 24 == 0) {
        colorTemperature = 5000;
        std::cout << "Цветовая температура: " << colorTemperature << "K" << std::endl;
    }
}

int main() {
    system("chcp 1251"); // Установить кодировку
    for (int time = 0; time < 48; ++time) {
        std::cout << "Время: " << time % 24 << ":00\n" 
            << "введите внутреннюю и наружную температуру, есть ли движение (yes/no), состояние ламп (on/off):" 
            << std::endl;
        std::string inputLine;
        std::getline(std::cin, inputLine);

        processInput(inputLine);
        updateDevices(time);
    }
    return 0;
}

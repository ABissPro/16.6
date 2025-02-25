#include <iostream>
#include <string>

enum Note { //noteindex = 0 - 6
    DO = 1,   // 00000001
    RE = 2,   // 00000010
    MI = 4,   // 00000100
    FA = 8,   // 00001000
    SOL = 16, // 00010000
    LA = 32,  // 00100000
    SI = 64   // 01000000
};

int main() {
    //битовая маска аккорда
    int chordMask = 0;

    std::string inputChord;
    std::cout << "Enter a chord (numbers from 1 to 7): ";
    std::getline(std::cin, inputChord);

    //преобразование строки в битовую маску
    for (char ch : inputChord) {
        if (ch >= '1' && ch <= '7') {
            int noteIndex = ch - '0';  //символ в число через ASCII
            chordMask |= (1 << (noteIndex - 1)); // Устанавливаем соответствующий бит
            //единица смещается на noteIndex - 1 позиций влево; 
            //noteIndex - 1 соответствует нумерации в перечислении (0-6)
            //0-6 соответствуют позиции 1 в маске
        }
    }

    if (chordMask & DO) {
        std::cout << "DO ";
    }
    if (chordMask & RE) {
        std::cout << "RE ";
    }
    if (chordMask & MI) {
        std::cout << "MI ";
    }
    if (chordMask & FA) {
        std::cout << "FA ";
    }
    if (chordMask & SOL) {
        std::cout << "SOL ";
    }
    if (chordMask & LA) {
        std::cout << "LA ";
    }
    if (chordMask & SI) {
        std::cout << "SI ";
    }

}
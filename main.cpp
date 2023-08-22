#include <iostream>
#include "flashCard.h"
#include <vector>

int main(int argc, char **argv) {
    //argv[1] = name, argv[2] = method type
    //method type = studying || new || review 
    std::string filename(argv[1]);
    filename += ".txt";
    const std::string method(argv[2]);
    FlashCard f{filename};
    //f.print();
    std::cout << f.get_size() << std::endl;
    f.guessKanji(10);
}
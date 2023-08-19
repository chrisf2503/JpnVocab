#include <iostream>
#include "flashCard.h"
#include <vector>

int main(){
    FlashCard f{"Chapter16.txt"};
    //f.print();
    std::cout << f.get_size() << std::endl;
    f.guessKanji(10);
}
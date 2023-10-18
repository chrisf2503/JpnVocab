#include <iostream>
#include "flashCard.h"
#include <string>
#include <fstream>
#include <fstream>
int main(){
    std::ifstream file("Vocab21.txt");
    FlashCard f1{file};
    f1.print();
}

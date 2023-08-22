#include <iostream>
#include "flashCard.h"
#include <vector>
#include <fstream>
#include <string>

void studyMethod(FlashCard &f){
    std::cout << "There are " << f.get_size() << " words " << std::endl << 
    "how many words you like to study: ";
    std::string numWords;
    getline(std::cin,numWords);
    int getNum = stoi(numWords);
    while(getNum <= 0 || getNum >= f.get_size()+1){
        std::cout << "Please enter a valid number: "; 
        getline(std::cin,numWords);
        getNum = stoi(numWords);    
    }
    f.guessKanji(getNum);
}

int main(int argc, char **argv) {
    //argv[1] = name, argv[2] = method type
    //method type = studying || new || review 
    if(argc != 3){
        std::cout << argv[0] << " <Chapter#> <Method>" << std::endl;
        return 0; 
    }
    std::string filename(argv[1]);
    filename += ".txt";
    const std::string method(argv[2]);
    FlashCard f{filename};
    //f.print();
    if(method == "study"){
        studyMethod(f);
    }
    else if(method == "review"){
        std::cout << "On the works " << std::endl;
        return 0;
    }
    else if(method == "new"){
        std::cout << "On the works " << std::endl;
        return 0;
    }
    else{
        std::cout << "The choice of method does not exist" << std::endl;
        return 0;
    }
}
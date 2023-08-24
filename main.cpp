#include <iostream>
#include "flashCard.h"
#include <vector>
#include <fstream>
#include <string>
void createNew(const std::string fileName){

}
void reviewMethod(FlashCard &f){
    std::cout << "How many words you want to review: ";
    std::string numWords;
    getline(std::cin,numWords);
    int getNum = stoi(numWords);
    while(getNum <= 0 || getNum >= f.get_size()+1){
        std::cout << "Please enter a valid number: "; 
        getline(std::cin,numWords);
        getNum = stoi(numWords);    
    }
    f.reviewVocab(getNum);
}
void studyMethod(FlashCard &f){
    std::cout << "how many words you like to study: ";
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
    /*Here we want to first check if the fileName exist or not
        If it doesnt exist and user enter new, then it is okay and call 
        the create New function. If not then abort and say file doesnt exist
    */
    std::ifstream file(filename);
    //Here we dont have to create a class, we can just write a new file
    //and insert the words in the following order
    //1.kanji 2.kana 3.english then when writing in the file we just do 
    //kanji \t\t kana \t\t english
    if(!file.is_open() && method == "new"){
        file.close();
        std::cout << "we can make a new flashcard" << std::endl;
        return 0;
    }
    FlashCard f{file};
    std::cout << "There are " << f.get_size() << " words " << std::endl;
    //f.print();
    if(method == "study"){
        studyMethod(f);
    }
    else if(method == "review"){
        //std::cout << "On the works " << std::endl;
        reviewMethod(f);
    }// If we have an exisiting file but want to add then we should allow it
    else{
        std::cout << "The choice of method does not exist" << std::endl;
    }
    return 0;
}
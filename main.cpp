#include <iostream>
#include "flashCard.h"
#include <vector>
#include <fstream>
#include <string>
void createNew(std::ofstream && fileName){
    fileName << "漢字		かな			英語\n";
    std::string kanji, kana, eng, userInput;
    std::cout << "If the word has no kanji that is associated with it please hit enter " << std::endl;
    while(userInput != "yes"){
        std::cout << "Kanji: ";
        getline(std::cin,kanji);
        if(kanji == ""){
            kanji = "NONE";
        }
        std::cout << "Kana: ";
        getline(std::cin,kana);
        std::cout << "English: ";
        getline(std::cin,eng);
        fileName << kanji + "\t\t\t" + kana + "\t\t\t" + eng + '\n';
        std::cout << "Are you finished(type yes) if not hit enter: ";
        getline(std::cin, userInput);

    }
    fileName.close();
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
        std::cout << "we can make a new flashcard!" << std::endl;
        createNew(std::ofstream(filename));
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
    else if (method == "new"){
        std::cout << "This set already exist!" << std::endl;
    }
    else{
        std::cout << "The choice of method does not exist" << std::endl;
    }
    return 0;
}
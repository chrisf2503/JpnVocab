#include <iostream>
#include "flashCard.h"
#include <vector>
#include <fstream>
#include <string>
void findWords(FlashCard & f){
    std::string kanji, kana, userInput;
    std::cout << "this will only find kanji words or hiragana or katakana that do not have kanji\n"
    << "if you are trying to look for a kana with kanji then results might not show\n"
    << "please follow the instruction carefully!\n"
    << "If you are looking for a kanji word please type it in, if not hit enter\n"
    << "type in the kanaword you will be looking for\n";
    std::vector<std::string> word{"","",""};
    while(userInput != "yes"){
        std::cout << "Kanji: ";
        getline(std::cin,kanji);
        if(kanji == ""){
            std::cout << "Kana: ";
            getline(std::cin,kana);
            kanji = "NONE";
            if(!f.contain(kanji,kana)){
                std::cout << "Word doesnt not exist yet! Try a new Word!" << std::endl;
                continue; 
            }
            word = f.find_word(kanji,kana);
        }else{
            if(!f.contain(kanji)){
                std::cout << "Word doesnt not exist yet! Try a new Word!" << std::endl;
                continue; 
            }
            word = f.find_word(kanji);
        }
        std::cout << "Here is the result:" << std::endl;
        std::cout << "Kanji: " << word[0] << std::endl;
        std::cout << "Kana: " << word[1] << std::endl;
        std::cout << "English: " << word[2] << std::endl;
        std::cout << "Are you finished(type yes) if not hit enter: ";
        getline(std::cin, userInput);
    }
}

void add(FlashCard & f,std::ofstream & filename){
    std::string kanji, kana, eng, userInput;
    std::cout << "If the word has no kanji that is associated with it please hit enter " << std::endl;
    while(userInput != "yes"){
        std::cout << "Kanji: ";
        getline(std::cin,kanji);
        if(kanji == ""){
            kanji = "NONE";
        }else{
            if(f.contain(kanji)){
                std::cout << "word already exist" << std::endl;
                continue;
            }
        }
        std::cout << "Kana: ";
        getline(std::cin,kana);
        if(kanji == "NONE"){
            if(f.contain(kanji,kana)){
                std::cout << "word already exist" << std::endl;
                continue;
            }
        }
        std::cout << "English: ";
        getline(std::cin,eng);
        if(eng == "" || kana == ""){
            std::cout << "We are missing imporant information! Try again!\n";
            continue;
        }
        filename << kanji + "\t\t\t" + kana + "\t\t\t" + eng;
        filename << std::endl;
        f.insert({kanji,kana,eng});
        std::cout << "Are you finished(type yes) if not hit enter: ";
        getline(std::cin, userInput);

    }
    filename.close();
}
void reviewMethod(FlashCard &f){
    std::cout << "How many words you want to review: ";
    std::string numWords;
    getline(std::cin,numWords);
    int getNum = stoi(numWords);
    while(getNum <= 0 || getNum >= f.get_flashCard_size()+1){
        std::cout << "Please enter a valid number: "; 
        getline(std::cin,numWords);
        getNum = stoi(numWords);    
    }
    f.reviewVocab(getNum);
}
void studyMethod(FlashCard &f,const bool &study_kanji){
    std::cout << "how many words you like to study: ";
    std::string numWords;
    getline(std::cin,numWords);
    int getNum = stoi(numWords);
    while(getNum <= 0 || getNum >= f.get_flashCard_size()+1){
        std::cout << "Please enter a valid number: "; 
        getline(std::cin,numWords);
        getNum = stoi(numWords);    
    }
    //now allow user to choose mode
    std::cout << "What would you like to guess (choose a number)" 
    << std::endl << "1. Guess kanji"<<std::endl<<"2. Guess English" 
    << std::endl << "Enter: ";
    std::string userInput_;
    getline(std::cin,userInput_);
    while(userInput_ != "1" && userInput_ != "2"){
        std::cout << "Please enter a valid number: "; 
        getline(std::cin,userInput_);
    }
    if(userInput_ == "1"){
        f.guessKanji(getNum,study_kanji);
    }else{
        f.guessEngl(getNum);
    }
}

int main(int argc, char **argv) {
    //argv[1] = name, argv[2] = method type
    //method type = studying || new || review 
    if(argc != 3){
        std::cout << argv[0] << " <Vocab#> <Method>" << std::endl;
        return 0; 
    }
    std::string filename(argv[1]);
    //this condition might change because we want to access other vocab files
    //if you cant find the key Word Vocab or Kanki then we want to use this if statement
    if(filename.find("Vocab") == -1 && filename.find ("Kanji") == -1){
        std::cout << "Please type Vocab or Kanji and then chapter number" << std::endl;
        std::cout << "Example: \n./main Vocab21 review\n./main Kanji21 study" << std::endl;
        return 0;
    }
    bool study_kanji;
    if(filename.substr(0,5) == "Kanji"){
        study_kanji = true;
    }
    else
        study_kanji = false;
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
        std::ofstream write(filename);
        write << "漢字		    かな			英語";
        file = std::ifstream(filename);
        FlashCard f{file};
        add(f,write);
        return 0;
    }
    FlashCard f{file};
    std::cout << "There are " << f.get_flashCard_size() << " words " << std::endl;
    if(method == "study"){
        studyMethod(f,study_kanji);
    }
    else if(method == "review"){
        //std::cout << "On the works " << std::endl;
        reviewMethod(f);
    }// If we have an exisiting file but want to add then we should allow it
    else if (method == "new"){
        std::cout << "This set already exist!" << std::endl;
    }
    else if (method == "add"){
        std::ofstream open(filename,std::ios::app);
        add(f,open);
    }
    else if(method == "find"){
        std::cout << "Currently working on it!" << std::endl;
        //findWords(f);
    }
    else{
        std::cout << "The choice of method does not exist" << std::endl;
    }
    return 0;
}
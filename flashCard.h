#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FlashCard{
    public:
        //We want to the file and put them all within the list
        FlashCard(std::string fileName){
            std::string kanji_,kana_,english_;
            std::ifstream words(fileName);
            if(!words.is_open()){
                std::cout << "the file is not open!" << std::endl;
                abort();
            }
            getline(words,kanji_);
            while(words >> kanji_ >> kana_){
                getline(words,english_);
                //We want to remove the spaces and tabs
                remove_Space(english_);
                insert({kanji_,kana_,english_});
            }
        }
        void remove_Space(std::string & word){
            for(int i = 0; i < word.length(); i++){
                if(word[i] != '\t' || word[i] == ' '){
                    word = word.substr(i);
                    break;
                }
            }
        }
        void insert(const std::vector<std::string> && vocab){
            list.push_back(vocab);
        }
        void print(){
            for(int i = 0; i < list.size(); i++){
                std::cout << list[i].kanji << ' ' << list[i].hiragana << ' ' << list[i].english << std::endl;
            }
        }
        //Now we want to get a random word in the list and then try to guess the maning
        //Let user choose the number of guesses 1 to the size of the list
        void guessKanji(size_t num){
            int correct = 0;
            std::string userinput;
            for(int i = 0; i < list.size(); i++){
                std::cout << "What is the meaning of ";
                if(list[i].kanji == "NONE"){
                    std::cout << list[i].hiragana << std::endl;
                }
                else{
                    std::cout << list[i].kanji <<std::endl;
                }    
                std::cout << "Enter: ";
                //std::cin >> userinput;
                getline(std::cin, userinput);
                //Now we want to give the user an opertunity to guess the word 3 times
                //if they cant guess it write then give user a hint (if its in kanji)
                //else say the answer
                if(userinput != list[i].english){
                    std::cout << "The answer is: " << list[i].english << std::endl;
                }else{
                    correct++;
                    std::cout << "CORRECT" << std::endl;
                }
            }
            std::cout << correct << "/" << list.size() << " correct" << std::endl;
        }
        size_t get_size(){
            return list.size();
        }
    private:  
        struct define{
            std::string kanji;
            std::string hiragana;
            std::string english;
            //index 0 is kanji, index 1 is hiragana, index 2 is english
            define(const std::vector<std::string> & vocab){
                this->kanji = vocab[0];
                this->hiragana = vocab[1];
                this->english = vocab[2];
            }
        };
        std::vector<define> list;
};
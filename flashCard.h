#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>    // std::random_shuffle

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
            int correct_ = 0;
            
            std::string userinput_;

            std::random_shuffle(list.begin(),list.end());
            
            for(std::vector<define>::iterator itr = list.begin(); itr != list.end(); ++itr){
                define word = *itr;
                std::cout << "What is the meaning of ";
                if(word.kanji == "NONE"){
                    std::cout << word.hiragana << std::endl;
                }
                else{
                    std::cout << word.kanji <<std::endl;
                }    
                std::cout << "Enter: ";
                //std::cin >> userinput_;
                getline(std::cin, userinput_);
                if(userinput_ != word.english){
                    std::cout << "The answer is: " << word.english << std::endl;
                    std::cout << word.kanji << " " << word.hiragana << " " << word.english << std::endl;

                }else{
                    correct_++;
                    std::cout << "CORRECT!" << std::endl;
                }
            }
            std::cout << correct_ << "/" << list.size() << " correct" << std::endl;
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
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
class FlashCard{
    public:
        //We want to the file and put them all within the list
        FlashCard(std::ifstream & words){
            std::string kanji_,kana_,english_;
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
            words.close();
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
        void guessKanji(const size_t &num,const bool &study_kanji){
            int correct_ = 0; size_t counter = 0;
            std::string userinput_;
            std::srand ( unsigned ( std::time(0) ) );
            std::random_shuffle(list.begin(),list.end());
            std::vector<define>::iterator itr = list.begin();
            while(itr != list.end() && counter != num){
                define word = *itr;
                std::cout << "What is the meaning of ";
                if(word.kanji == "NONE"){
                    std::cout << word.hiragana << std::endl;
                }
                else if(study_kanji == true && word.kanji != "NONE"){
                    std::cout << word.kanji <<std::endl;
                }
                else{
                    std::cout << word.kanji << "(" << word.hiragana << ')'
                    << std::endl;
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
                ++itr;
                counter++;
            }
            std::cout << correct_ << "/" << num << " correct" << std::endl;
        }
        //Now we want to let user get the english word and try to guess it in
        //japanese, therefore guessEngl(size_t num)
        void guessEngl(const size_t &num){
            int correct_ = 0; size_t counter = 0;
            std::string userinput_;
            std::srand ( unsigned ( std::time(0) ) );
            std::random_shuffle(list.begin(),list.end());
            std::vector<define>::iterator itr = list.begin();
            while(counter != num && itr != list.end()){
                define word = *itr;
                std::cout << "Guess the meaning of \"" << word.english << "\"" 
                << std::endl << "Enter: ";
                getline(std::cin, userinput_);
                if(userinput_ == word.hiragana ||(userinput_ != "NONE" && userinput_ == word.kanji)){
                    correct_++;
                    std::cout << "CORRECT!" << std::endl;
                }else{
                    std::cout << "The answer is: " << word.hiragana;
                    if(word.kanji != "NONE"){
                        std::cout << " " << word.kanji << std::endl;
                    }
                    else{
                        std::cout << std::endl;
                    }
                    std::cout << word.kanji << " " << word.hiragana << " " << word.english << std::endl;
                }
                ++itr;
                counter++;
            }
            std::cout << correct_ << "/" << num << " correct" << std::endl;
        }
        void reviewVocab(size_t num){
            std::srand ( unsigned ( std::time(0) ) );
            std::cout << "Hit Enter once you are ready to move on" << std::endl;
            size_t count = 0;
            std::random_shuffle(list.begin(),list.end());
            std::vector<define>::iterator itr = list.begin();
            while(count != num){
                define word = *itr;
                std::cout << count+1 << ". ";
                if(word.kanji != "NONE"){
                    std::cout << "Kanji: " << word.kanji << " ";
                    std::cin.ignore();
                }
                std::cout << "Kana: " <<  word.hiragana << " "; 
                std::cin.ignore();
                std::cout << "English: " << word.english << " ";
                std::cin.ignore();
                ++itr;
                count++;
            }
        }
        size_t get_size(){
            return list.size();
        }
        //if word1 is smaller then word2 then return true else; return false;
        /*bool smaller(const define & word1,const define & word2){
            return word1.kanji < word2.kanji;
        }
        //if word1 is bigger then word2 then return true else; return false;
        bool bigger(const define & word1,const define & word2){
            return word1.kanji > word2.kanji;
        }*/
    private:  
        struct define{
            std::string kanji;
            std::string hiragana;
            std::string english;
            //Adding japanese and english sentence with chapter grammer 
            //std::string jpnSent; std::string engSent;
            //index 0 is kanji, index 1 is hiragana, index 2 is english
            define(const std::vector<std::string> & vocab){
                this->kanji = vocab[0];
                this->hiragana = vocab[1];
                this->english = vocab[2];
            }
            bool operator<(const define & word)const{
               return this->hiragana < word.hiragana;
            }
        };
        std::vector<define> list;
};
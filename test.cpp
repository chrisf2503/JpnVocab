#include <iostream>
#include "VocabTree.h"
#include <string>
#include <fstream>
//Here I am only going to use this in order to test implementation 
//and testing out function in different classes
//Here we are going to only use the smaple.txt file just for test run
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
        return this->kanji < word.kanji;
    }
};
void remove_Space(std::string & word);
void print(std::vector<define> & words);
int main(){
    std::vector<define> list;
    std::ifstream words("sample.txt");
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
        list.push_back(std::vector<std::string>{kanji_,kana_,english_});
    }
    words.close();
    print(list);
    vocabTree<define> tree{};
    for(int i = 0; i < list.size(); ++i){
        tree.insert(list[i]);
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
void print(std::vector<define>& words){
    for(define w: words){
        std::cout << w.kanji << " " << w.hiragana << " " << w.english << std::endl;
    }
}
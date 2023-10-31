/***
 * struct define{
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
                if(word.kanji != "NONE"){
                    return this->kanji < word.kanji;
                }else{
                    return this->hiragana < word.hiragana;
                }   
            }
    };
    struct Kanji{
            char kanji;
            std::string furigana;
            std::string meaning;
            Kanji(const char &kanji, const std::string &furigana, const std::string & meaning){
                this->kanji = kanji;
                this->furigana = furigana;
                this->meaning = meaning;
            }
        
    };
    Probably make these all into one and then call the struct when ever we need it
    so we dont have to repeat the process
*/
#pragma once
#include <vector>
#include <string>
struct word
{
    std::string kanji;
    std::string hiragana;
    std::string english;
    //Adding japanese and english sentence with chapter grammer 
    //std::string jpnSent; std::string engSent;
    //index 0 is kanji, index 1 is hiragana, index 2 is english
    word(const std::vector<std::string> & vocab){
        this->kanji = vocab[0];
        this->hiragana = vocab[1];
        this->english = vocab[2];
    }
    word(const std::vector<std::string> && vocab){
        this->kanji = vocab[0];
        this->hiragana = vocab[1];
        this->english = vocab[2];
    }
    bool operator<(const word & word)const{
        if(word.kanji != "NONE"){
            return this->kanji < word.kanji;
        }else{
            return this->hiragana < word.hiragana;
        }   
    }
};

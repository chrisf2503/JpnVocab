/***
 * Here we want to make a list on kanji character, where when we want to do
 * something like search, then we dont have to do it by index, we can just do it 
 * by characters
 * 
 * [外][国][人][風]
 * 
 * Therefore when we want to do somehthing like search, then we can go by the start
 * of the first character
 *  
 * Since kanji charcter do have meaning to them, if user want to look at the meaning
 * and they way to pro nounce them, then we should allow to give defintion as well
 * struct kanji{
 *   char character;
 *   string furigana;
 *   string meaning;
 * }
 * So we are going to read from a file with the following formate
 * Character        furikana            meaning
 * 
 * Then we will insert it with in the list of kanji character
 * vector<kanji> k;
 * Then we can add basic methods like search, find, contain, etc.
*/
#include <string>
#include <vector>
#include <fstream>
#include "word.h"
class KanjiList{
    public:
        KanjiList(){
            std::ifstream f("KanjiTest.txt");
            KanjiIndex = "";
            std::string chars;
            std::string furigana;
            std::string meaning;
            while(f >> chars >> furigana){
                getline(f,meaning);
                //We want to remove the spaces and tabs
                remove_Space(meaning);
                list.push_back(word({chars,furigana,meaning}));
                KanjiIndex += chars;
            }
            f.close();
        }
        void remove_Space(std::string & word){
            for(int i = 0; i < word.length(); i++){
                if(word[i] != '\t' || word[i] == ' '){
                    word = word.substr(i);
                    break;
                }
            }
        }
        std::string get_KanjiIndex(){
            return this->KanjiIndex;
        }
        bool findKanji(const std::string& kanji){
            if(KanjiIndex.find(kanji)){
                return true;
            }
            else{
                for(int i = 0; i < KanjiIndex.length(); i++){
                    if(std::to_string(KanjiIndex[i]) == kanji){
                        return true;
                    }
                }
                return false;
            }
        }
        word getWord(const std::string& kanji){
            return list[KanjiIndex.find(kanji)];
        }
    private:
        std::vector<word> list;
        std::string KanjiIndex;
};
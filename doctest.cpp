#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
//#include "VocabTree.h"
#include "flashCard.h"
#include <fstream>
#include <string>
#include <vector>

/*struct define{
    //make a list of strings?
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
    //there will be a case such that we might want to store all kanji assosiated with 
    //its kana and could possibly have more then one meaning 
    bool operator<(const define & word)const{
        return this->hiragana+this->kanji < word.hiragana + word.kanji;
    }
};
vocabTree<define> t;
void remove_Space(std::string & word){
    for(int i = 0; i < word.length(); i++){
        if(word[i] != '\t' || word[i] == ' '){
            word = word.substr(i);
            break;
        }
    }
}
void makingCard(){
    std::vector<define> list;
    std::ifstream words("sample.txt");
    std::string kanji_,kana_,english_;
    if(!words.is_open()){
        std::cout << "the file is not open!" << std::endl;
        abort();
    }
    getline(words,kanji_);
    int i = 0;
    while(words >> kanji_ >> kana_){
        getline(words,english_);
        remove_Space(english_);
        list.push_back(std::vector<std::string>{kanji_,kana_,english_});
        t.insert(list[i]);
        i++;
    }
    words.close();
    CHECK(!t.empty());
    CHECK(list.size() == t.get_size());
} 
TEST_CASE("Contain word"){
    makingCard();
    define w1({"飲み物","のみもの","drink"});
    define w2({"暑い","あつい","hot"});
    define w3({"NONE","ころ","time, when"});
    define w4({"文句","もんく","complain"});
    define w5({"運転","うんてん","drive"});
    CHECK(t.contain(w1));//true
    CHECK(!t.contain(w2));//false
    CHECK(!t.contain(w3));//false
    CHECK(!t.contain(w4));//false
    CHECK(t.contain(w5));
    
}*/
//Given a word, kana or kanji, we want to get its whole meaning 
TEST_CASE("Containing basic words in samples"){
    std::ifstream f("sample.txt");
    FlashCard vocab{f};
    std::ifstream f2("sample2.txt");
    FlashCard vocab2{f2};
    CHECK(vocab.get_tree_size() == vocab.get_flashCard_size());
    CHECK(vocab2.get_flashCard_size()!= vocab2.get_tree_size());
    CHECK(vocab2.contain("NONE","ボール"));
    CHECK(!vocab.contain("NONE","ボール"));
    CHECK(vocab2.contain("木"));
    CHECK(!vocab2.contain("NONE","き"));
    CHECK(vocab2.contain("免許"));
    CHECK(vocab.contain("NONE","ごめん"));
}
TEST_CASE("Find and get word"){
    std::ifstream f("sample.txt");
    FlashCard vocab{f};
    std::ifstream f2("sample2.txt");
    FlashCard vocab2{f2};
    CHECK(vocab2.contain("木"));
    std::vector<std::string> s = vocab2.find_word("木");
    CHECK(s[0] == "木");
    CHECK(s[1] == "き");
    CHECK(s[2] == "tree");
    if(vocab.contain("NONE","ごめん")){
        s = vocab.find_word("NONE","ごめん");
        CHECK(s[0] == "NONE");
        CHECK(s[1] == "ごめん");
        CHECK(s[2] == "I’m sorry(casual)");
    }
    
}
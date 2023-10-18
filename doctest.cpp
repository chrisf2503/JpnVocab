#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
//#include "VocabTree.h"
#include "flashCard.h"
#include <fstream>
#include <string>
#include <vector>

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
    std::ifstream f3("Vocab21.txt");
    FlashCard v3(f3);
    CHECK(v3.contain("見つける"));
    CHECK(v3.contain("気が付く"));
    CHECK(v3.contain("盗む"));
    CHECK(v3.get_tree_size() == v3.get_flashCard_size());
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
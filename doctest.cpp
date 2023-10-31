#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
//#include "VocabTree.h"
#include "flashCard.h"
#include "KanjiList.h"
#include <fstream>
#include <string>
#include <vector>
#include "word.h"
TEST_CASE("Testing kanji list header file"){
    KanjiList k{};
    std::string list = "風木猿免予復塾英嬢神先輩部受書家";
    CHECK(k.get_KanjiIndex() == list);
    for(int i = 0; i < list.length(); i++){
        CHECK(k.findKanji(std::to_string(list[i])));
        //Check words, furigana, and meaning
    }
    word w = k.getWord("風");
    CHECK(w.kanji == "風");
    CHECK(w.hiragana == "かぜ");
    CHECK(w.english == "wind");
}
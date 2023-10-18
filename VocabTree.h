#include <iostream>
#include <algorithm>

template<typename Comparable>
class vocabTree{
    public:
        vocabTree():root{nullptr}{numNodes = 0;}
        vocabTree(Comparable &data):root{new vocabNode(data,nullptr,nullptr)}{numNodes = 1;}
        vocabTree(Comparable &&data):root{new vocabNode(std::move(data),nullptr,nullptr)}{numNodes = 1;}
        ~vocabTree(){}
        void insert(const Comparable & x){
            insert(x,root);
        }
        bool contain(const Comparable & x){
            return contain(x,root);
        }
        bool contain(const Comparable && x){
            return contain(std::move(x),root);
        }
        int get_size()const{
            return this->numNodes;
        }
        bool is_empty(){
            return (root == nullptr);
        }
        /*For search we want to be given the one of the following:
            Kanji, kana, english
            And we want to find its meaning for english,
            lets assume that if we are given in hiragana, and has no kanji 
            assiated with it, then we shall return only the english portion
            else if we are given the kanji, then we shall give back its kana 
            and english def

        In order to do general search, we should consider all possibility
        For english search, we should consider only key words?
        For this search we will be given a list(of string) with a size of 3
        [kanji][kana][english]
        For now we shall only do search based on kana and kanji
        We will know what search to do when only one of the index has a full string
        [""][""][""]
        if none are filled then we should make user keep on doing inputs until one 
        is filled
        Comparable findWord(std::vector<string> info);
        */
        Comparable findWord(Comparable word){
            return findWord(word, root);
        }

    private:
        struct vocabNode{
            Comparable data;
            vocabNode *left;
            vocabNode *right;
            vocabNode(const Comparable &words, vocabNode *lt, vocabNode *rt) :
                data{words}, left{lt}, right{rt} { }

            vocabNode(const Comparable &&words, vocabNode*lt, vocabNode *rt) :
                data{std::move(words)}, left{lt}, right{rt} { }
        };
        vocabNode *root;
        int numNodes;
        //Their are some words that are being misplaces, such that we cant find them!
        //Therefore we need to figure out a better implementation for this in order
        //To find these words, or else try to use another data structer that will (probably hash table with link list)
        
        void insert(const Comparable & x, vocabNode * & node){
            if(node == nullptr){
                numNodes++;
                node = new vocabNode(x,nullptr,nullptr);
            }
            else if(x < node->data){
                insert(x,node->left);
            }else if(node->data < x){
                insert(x,node->right);
            }else
                ;
        }
        bool contain(const Comparable & x, vocabNode * & node){
            if(node == nullptr){
                return false;
            }else if(x < node->data){
                return contain(x,node->left);
            }else if(node->data < x){
                return contain(x,node->right);
            }else 
                return true;
            
        }
        Comparable findWord(const Comparable &x, vocabNode *&node){
            if(x < node->data){
                return findWord(x,node->left);
            }else if(node->data < x){
                return findWord(x,node->right);
            }
            else{
                return node->data;
            }

        }
};
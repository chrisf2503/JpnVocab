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
        bool empty(){
            return root == nullptr;
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
        //now we want to find words such that user will look for its kanji, kana or english def
        //therefore when we want to search, we want to be given a string and make sure that
        //we check all 3 in order to determine if its in the tree or not
        //Also note that Kanji != NONE
};
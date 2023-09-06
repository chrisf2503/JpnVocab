#include <iostream>
#include <algorithm>
#include "flashCard.h"
template<typename Comparable>
class vocabTree{
    public:
        vocabTree():root{nullptr}{}
        vocabTree(Comparable &data):root{new vocabNode(data,nullptr,nullptr)}{}
        vocabTree(Comparable &&data):root{new vocabNode(std::move(data),nullptr,nullptr)}{}
        ~vocabTree(){}
        void insert(const Comparable & x){
            insert(x,root);
        }
        bool contain(const Comparable & x){
            return contain(x,root);
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
        
        void insert(const Comparable & x, vocabNode * & node){
            if(node == nullptr){
                node = new vocabNode(x,nullptr,nullptr);
            }
            else if(x < node->data){
                std::cout << "goes left" << std::endl;
                insert(x,node->left);
            }else if(node->data < x){
                std::cout << "goes right" << std::endl;
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
        Comparable getVocab(const Comparable &x, vocabNode * & node ){
            
        }
};
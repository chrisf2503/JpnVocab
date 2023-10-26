# JpnVocab

Hello this a program wanted to do for quite a while now so I can get into the habit of studying Japanese Vocabulary. Therefore it might only benefit those who are currently are studying Japanese right now. 

# Basic Discription 

You are able to choose one of the following methods 
- reviewing existing words
- creating a new flash cards
- studying existing words
These words will be going by chapter (in order). As of now I will be updating chaper vocab each time I progress within my JPN classes. Therefore I will try to cover from chapter 1 all the way to current lesson I am on.
As of now I am currently testing and making changes and will be up loading chapter vocab when ever I get the chance.

# Using Review Method

When using this method you will just go word by word and looking at both kanji, hiragana or katakana, and english word. Therefore you will choose the chapter that you desire and go through the list that will be shuffled.  

# Using Creating New Flash Cards

When using this method, you will have to tell us what type of Chapter number of this new list. Therefore the formate of the list should be done by the following 

kanji           kana            english

For example if you want to add a word like 飲み物 which means drink you must put it as the following format 

飲み物          のみもの            drink

But lets say their is no kanji associated to the kana YOU MUST WRITE "NONE"
Example:

NONE			これから		From now on

This word above does not contain any kanji therefore we write none. Same thing applies if its in katakana. 
Example:

NONE             ペン           pen

* In the future I might update this part to also include sentences but this will be done in the future

# Using Study method

Here you will have to any of the existing chapter vocab, here you can select select an existing set and study all the words at random. 

Current implementation:
This study method only allow you to guess the english word, therefore you will be give the japanese words and your goal is to guess its meaning in english. If you can't get it right the first try, then the answer will be shown

User can choose the number of words they wish to study. Meaning you choose if you want to study 1 up to the list size. Therefore if you say you wish to follow 1 word, you will just be given 1 random word (boring!). But if you wish to study lets say 10 words, then you will be given 10 random word. 

At some point I will try to add a way to give hints (if its in kanji) so user can have an oppertunity to get a chance to keep on trying. But also give user 6 changes to guess the word. Meaning if the user doesnt get it right the first half then a hint will be given, but if the user still can get it, then the answer will be shown. 

I also want to add where user can guess the words in japanese. Therefore if the word is given in english then they must guess the word in japanese

# Adding words:

For the new method(not yet implemented), i want to be able to add more words within a list of words that is currently existing. But here is the thing, we have to consider the following if the "word currently exist", this mean that if the word like 飲み物          のみもの            drink          
already exist, then we should not add it to the list and tell user this word exist.
There for we must consider what type of data structure should be added (tree's, list, etc), and what type of algorithm will allow me to search for the word at a sufficient time. 
# Notes

For this, all we are going to do is to read a md file that has notes for each chapter, therefore all we do is read a file. But some fetures will be added.
We will allow user to input the Chapter number <Chapter#> and allow user to choose the lesson number. So we can let user choose the lesson they may choose in stead of going throw the whole chapter and waiting until the lesson is bring shown. How ever, user should be allowed to choose all lesson if they wish to do so. 

# Search Word

Givin the kanji or kana, we want to be able to look up that work from any of the following chapters, therefore we might want to have a while that will contain all word from every chapter, merge them all together, the file could be name all.txt and when adding words, we can also check if it exist or not. 
Therefore trying to figure out which data strcutre can go best with it.

Note:
A tree implementation was made, but it was soon to be discovered that we are able to store these words within a tree by its kanji or kana character (if doesnt have kanji), but now here the main issue is they are some words that are already stored but now they are no where to be found, they exist within the tree but when looking for that exact same word, then we are told it does not exist. 

# Future plans

- I want to include current lessons not only within my JPN class but also use CS algorithms and data structure as I advance in my classes. 
- I will also try to include basic sentence structure on how vocab is being used. But also trying to keep it within the level of each chapter.

# How to run the code

If you are trying to use this in terminal, do the following 
Method names: new/review/study 

To study and review methods do the following:
1. make main
2. ./main vocab# Method
Example:
./main Vocab21 review
./main Vocab21 study
./main Vocab23 add
./main Vocab13 new

If you want to review notes, if you want to review all then type "All" or else type the Lesson# then do the following:

1. make notes
2. ./notes Chapter# Lesson# 
Example: 
./notes Chapter21 Lesson1
./notes Chapter21 All

If you want to do doctest, then do the following:
1. make doctest
2. ./doctest
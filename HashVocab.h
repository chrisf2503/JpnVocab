/*
Poblem:
    Here want to insert these vocab words by the first character of the word
    Therefore given a words: 他の			ほかの			other
    We want to index it to based on its first character,
    [0][0][0][0][0][他][0][0] //Lets assume the hash function lead us to this index
    
    We want to dedicate that slot for words that start with that character

My Goal:
    I want to create a hash function such that each slot is dedicated to its on character.
    Seperate Chaining:
        Idea:
        Each word has a distinct character, just like the abc's, they start off with the first
        character and then the next, therefore we can seperate each word by the first character
        Pros:
        We can use seperate chaining because we can just hash the word, if we want to just
        use the first character, we can set the index equal to that character, and then 
        start inserting words within that start

        Cons:
        lets say we have a huge list, bigger then we can imagine with 100 character and 10000 words. 
        If we have a word that has a character that the 99 index and the the word is at the end of 
        that link list, then it can take about O(NxM) times which is no good.
        Best possible case is its near the character is has a smaller index and has the link list has size 
        m, then it can possibly take O(m) times to find the word
    HashTable of HashTable:
        Idea: We have a word where it can have a length > 0, we want to hash the first characterx

*/
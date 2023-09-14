#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>

int main(int argc, char **argv){
    if(argc != 2){
        std::cout << argv[0] << " <Notes#>" << std::endl;
        return 0;
    }
    std::string fileName(argv[1]);
    fileName += ".md";
    std::ifstream f(fileName);
    std::string s;
    while(getline(f,s)){
        if(s == "Side Note:") {break;}
        for(char c: s)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            std::cout << c << std::flush;
        }
        std::cout << '\n';
    }
}
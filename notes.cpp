#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
void printAll(std::ifstream &f){
    std::string s;
    while(getline(f,s)){
        for(char c: s)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            std::cout << c << std::flush;
        }
        std::cout << '\n';
    }
}
//Here we only want to look for the lesson we want to print
//once its finished, then we want to exit
void printLesson(std::ifstream & f, const std::string & lesson){
    std::string s;
    while(getline(f,s)){
        if(s.substr(0,7) == lesson){
            std::cout << s << std::endl;
            while(getline(f,s)){
                if(s.substr(0,6) == "Lesson"){
                    break;
                }
                for(char c: s)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(50));
                    std::cout << c << std::flush;
                }
                std::cout << '\n';
                
            }
            break;
        }
    }
}
int main(int argc, char **argv){
    if(argc != 3){
        std::cout << argv[0] << " <Chapter#> <Lesson#>" << std::endl;
        return 0;
    }
    std::string fileName(argv[1]);
    std::string lesson(argv[2]);
    fileName += ".md";
    std::ifstream f(fileName);
    if(!f.is_open()){
        std::cout << "This current Chapter notes does not exist" << std::endl;
        f.close();
        return 0;
    }
    int numlesson;
    f >> numlesson;
    if(lesson == "All"){
        printAll(f);
    }
    else{
        //std::cout << "Print the lesson we want" << std::endl;
        if(stoi(lesson.substr(6)) < 1 || stoi(lesson.substr(6)) > numlesson){
            std::cout << "This lesson does not exist" << std::endl;
            f.close();
            return 0;
        }
        printLesson(f,lesson);
    }
    f.close();
}
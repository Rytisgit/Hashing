#include <iostream>
#include <fstream>
#include "RytisMasterClassOnHashingAlgorithms.h"

int main(int argc, char *argv[]) {
//    if(argv[3][0]=='1'){
//        std::string line;
//        std::string location {};
//        location += "../";
//        location+=argv[2];
//        location+=".txt";
//        std::ifstream myfile(location);
//        while ( std::getline(myfile, line))
//        {
//            for(auto single : hash("-s",line))
//                std::cout << goodChars[single];
//
//            std::cout << '\n';
//        }
//    }
//    else{
//        for(auto single : hash(argv[1], argv[2]))
//           std::cout<<goodChars[single];
//    }
    std::cout<<hash("asdfasdfasdfas")<<'\n';
    return 0;
}

std::vector<int> readf1(std::string mode, std::string string)
{
    std::vector<int> myintArray {};
    if(mode.compare("-f") == 0){
        std::string line;
        std::string location {};
        location += "../";
        location+=string;
        location+=".txt";
        std::ifstream myfile(location);
        while ( std::getline(myfile, line))
        {
            std::vector<int> result {convertToASCII(line)};
            myintArray.insert(std::end(myintArray), std::begin(result), std::end(result));
        }
    }
    else {return convertToASCII(string);}

    return myintArray;
}
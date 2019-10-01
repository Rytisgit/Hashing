#include <iostream>
#include <fstream>
#include "RytisMasterClassOnHashingAlgorithms.h"

std::string readFile(std::string string);
int main(int argc, char *argv[]) {
    if(argv[3][0]=='1'){
        std::string line;
        std::string location {};
        location += "../";
        location+=argv[2];
        location+=".txt";
        std::ifstream myfile(location);
        while ( std::getline(myfile, line))
        {
            std::cout << hash(line);
            std::cout << '\n';
        }
    }
    else{
        if(argv[1][1]=='s')
           std::cout<< hash(argv[2]);
        else{
            std::cout<<hash(readFile(argv[2]));
        }
    }
    return 0;
}

std::string readFile(std::string string)
{
    std::ostringstream sstream;
    std::string line;
    std::string location {};
    location += "../";
    location+=string;
    location+=".txt";
    std::ifstream myfile(location);
    while ( std::getline(myfile, line))
    {
        sstream<<line;
    }
    return sstream.str();
}
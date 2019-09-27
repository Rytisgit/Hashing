#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <dshow.h>

const int hashSize = 20;
const int goodCharsLength = 63;
auto goodChars = const_cast<char *>("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");

std::vector<int> readf1(std::string mode, std::string string);
std::vector<int> convertToASCII(std::string s);
int ror63(int toBits, unsigned int moves);

std::vector<int> hash(char *const *argv, std::vector<int> &passVector);

int main(int argc, char *argv[]) {
    std::vector<int> readVector{};
    std::vector<int> passVector;
    if(argv[3][1]=='1'){
        std::string line;
        std::string location {};
        location += "../";
        location+=argv[2];
        location+=".txt";
        std::ifstream myfile(location);
        while ( std::getline(myfile, line))
        {
            char ** test;
            test[0] = "-s";
            std::StringCbCopyA(test[1],line.c_str());
            std::vector copy = convertToASCII(line);
            hash(test,copy);
            for(auto single : hash(argv, copy)) {
                if (single == 62) { std::cout << "0"; }
                else std::cout << goodChars[single];
            }
            std::cout << '\n';
        }
    }
    else{
        for(auto single : hash(argv, passVector)){
            if(single == 62){std::cout<<"0";}
            else std::cout<<goodChars[single];
        }
    }




    return 0;
}

std::vector<int> hash(char *const *argv, std::vector<int> input) {
    std::vector<int> passVector{};
    for(long double number : input){
        std::vector<int> tempVector{};
        auto temp = std::pow(number, 1 / 691.) * pow(10, 5);
        temp -= (long double)(int)temp;
        int tempInt;
        for(int i = 0; i<hashSize; i++){
            tempInt = temp*=100;
            tempVector.push_back(tempInt);
            temp-=(long double)tempInt;
        }
        if(passVector.empty())
            for(auto single : tempVector) passVector.push_back(single%goodCharsLength);
        else{
            int i = 0;
            for(auto single : tempVector)
            {
                passVector.at(i) = ror63((passVector.at(i)+single)%goodCharsLength,single);
                i++;
            }
        }
    };
    return passVector;
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
std::vector<int> convertToASCII(std::string s)
{
    std::vector<int> newlineArray;
    for (int i = 0; i < s.length(); i++)
    {
        newlineArray.push_back((int)s[i]);
    }
    return newlineArray;
}
int ror63(int toBits, unsigned int moves)
{
    std::bitset<6> bits(toBits);
    std::bitset<6> newSet;
    int moveBy = moves%6;
    for(int i = 5; i>=0;i--){
        newSet[i] = bits[(i+moveBy)%6];
    }
    return (int) newSet.to_ulong();
}
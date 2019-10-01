//
// Created by SuperPC on 10/1/2019.
//

#ifndef HASHING_RYTISMASTERCLASSONHASHINGALGORITHMS_H
#define HASHING_RYTISMASTERCLASSONHASHINGALGORITHMS_H

#include <string>
#include <vector>
#include <bitset>
#include <cmath>

const int hashSize = 20;
const int goodCharsLength = 64;
auto goodChars = const_cast<char *>("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+/");
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
std::vector<int> hash(std::string input) {
    std::vector<int> passVector{};
    for(long double number : convertToASCII(input)){
        std::vector<int> tempVector{};
        auto temp = pow(number, 1 / 691.) * pow(10, 5);
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

#endif //HASHING_RYTISMASTERCLASSONHASHINGALGORITHMS_H

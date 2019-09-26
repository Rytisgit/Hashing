#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <bitset>

const int hashSize = 20;
const int goodCharsLength = 63;

std::vector<int> readf1();
std::vector<int> convertToASCII(std::string s);
int ror63(int toBits, unsigned int moves);

int main() {
    auto goodChars = const_cast<char *>("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
    std::vector<int> passVector{};
    std::bitset<6> sixbits(50);

    auto test = ror63(45,13574);
    for(long double number : readf1()){
        std::vector<int> tempVector{};
        auto temp = std::pow(number, 1/691.)*pow(10,5);
        temp -= (long double)(int)temp;
        //std::cout<<std::setprecision(40)<<temp<<'\n';
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
    for(auto single : passVector){
        if(single == 62){std::cout<<"0";}
        else std::cout<<goodChars[single];
    }
    return 0;
}

std::vector<int> readf1()
{
    std::vector<int> myintArray {};

    std::string line;
    std::ifstream myfile("../f1.txt");
    while ( std::getline(myfile, line))
    {
        std::vector<int> result {convertToASCII(line)};
        myintArray.insert(std::end(myintArray), std::begin(result), std::end(result));
    }
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
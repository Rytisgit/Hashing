#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <random>
#include "RytisMasterClassOnHashingAlgorithms.h"
#include "timer.h"

std::string readFile(std::string string);
void testDuplicates();
void testSimilarity();
std::string random_string( size_t length )
{
    thread_local static std::mt19937 rg{
            static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count())};
    thread_local static std::uniform_int_distribution<int> pick(0, goodCharsLength);
    auto randchar = []() -> char {return goodChars[ pick(rg) % goodCharsLength ];};
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}
int main(int argc, char *argv[]) {
    if(argv[1][1]!='t'){
        if(argv[1][1]=='l'){
            std::string line;
            std::string location {};
            std::ifstream myfile(argv[2]);
            double time = 0;
            while ( std::getline(myfile, line))
            {
                Timer t;
                hash(line);
                std::cout << hash(line);
                std::cout << '\n';
                time+=t.elapsed();
            }
            std::cout << time;
        }
        else{
            if(argv[1][1]=='s')
                std::cout<< hash(argv[2]);
            else{
                std::cout<<hash(readFile(argv[2]));
            }
        }}
    else{
        testSimilarity();
        std::cout<<std::endl;
        testDuplicates();
    }
    return 0;
}

std::string readFile(std::string string)
{
    std::ostringstream sstream;
    std::string line;
    std::ifstream myfile(string);
    while ( std::getline(myfile, line))sstream<<line;
    return sstream.str();
}
void testDuplicates(){
    std::set<std::string> hashes;
    std::set<std::string> strings;
    double totalTime = 0;
    double intervalTime = 0;
    int printInterval = 1e5;
    int duplicate = 0;
    for (int i = 1; i <= 1e6; i++){
        auto string = random_string(6);
        Timer start;
        std::string res = hash(string);
        double currentTime = start.elapsed();
        totalTime += currentTime;
        intervalTime += currentTime;
        auto p = hashes.insert(res);
        auto t = strings.insert(string);
        if (!t.second)//only same string
            std::cout << "same string generated twice:"<<string<<std::endl;
        if (!p.second && t.second)//different string same hash
            duplicate++;
        if (i%printInterval==0){
            std::cout << "Hashes: " << i << ", Duplicates: " << duplicate << " Hashes/s: " << printInterval/intervalTime << std::endl;
            intervalTime = 0;
        }
    }
    std::cout<<"Total time:" <<totalTime<< std::endl;
}
void testSimilarity(){
    double min = 1, max = 0;
    double total = 0;
    for (int i = 1; i <= 1e5; i++){
        double cmp = HashComparer(random_string(5)+"a", random_string(5)+"A");
        if (cmp < min)
            min = cmp;
        if (cmp > max)
            max = cmp;
        total += cmp;
    }
    std::cout << "Similarity ratings: " << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Avg: " << total/1e5 << std::endl;
}
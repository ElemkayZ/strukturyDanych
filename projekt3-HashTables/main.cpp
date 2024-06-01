#include "openHash.cpp"
#include "doubleHash.cpp"
#include <iostream>
#include <ctime>
#include <random>
#include<chrono>

std::mt19937 rng(time(0));
std::uniform_int_distribution<unsigned long> rNum(0,10000000);
std::chrono::high_resolution_clock start,stop;
std::chrono::duration <double, std::nano> d;
int main() {
    double oHashInsert = 0;
    double oHashRemove = 0;


    double dHashInsert = 0;
    double dHashRemove = 0;

    int dataBaseSize = 1000;//number of random elements added to DBs
    std::cout << "data base size = " << dataBaseSize << std::endl;
    //////////////////////
    //data base generation

for (size_t i = 0; i < 100; i++)
{
    openHash oHash(1000);
    doubleHash dHash(1000);
    
    for (int i = 0; i < dataBaseSize ; ++i) {
        oHash.insert(*new Pair(rNum(rng),rNum(rng)));
        dHash.insert(*new Pair(rNum(rng),rNum(rng)));
    }
    /////////////////////////////
    //openHash testing

    //insert
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        oHash.insert(*new Pair(rNum(rng),rNum(rng)));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        oHashInsert += d.count();
    }

    //remove
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        oHash.remove(rNum(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        oHashRemove += d.count();
    }
        
    // oHash.display();

    /////////////////////////////
    //doubleHash testing

    //insert
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        dHash.insert(*new Pair(rNum(rng),rNum(rng)));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        dHashInsert += d.count();
    }

    //remove
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        dHash.remove(rNum(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        dHashRemove += d.count();
    }
        
    // dHash.display();
}

    std::cout << "-------------- OpenHash Testing --------------\n";
    oHashInsert /= 10000;
    std::cout << "AvgInsert Time = " << oHashInsert << std::endl;
    oHashRemove /= 10000;
    std::cout << "AvgRemove Time = " << oHashRemove << std::endl;
    
        std::cout << "-------------- doubleHash Testing --------------\n";
    dHashInsert /= 10000;
    std::cout << "AvgInsert Time = " << dHashInsert << std::endl;
    dHashRemove /= 10000;
    std::cout << "AvgRemove Time = " << dHashRemove << std::endl;



    return 0;

}

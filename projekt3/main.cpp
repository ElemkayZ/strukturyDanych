#include "openHash.cpp"
#include <iostream>
#include <ctime>
#include <random>
#include<chrono>

std::mt19937 rng(time(0));
std::uniform_int_distribution<unsigned long> rData(0,10000000);
std::chrono::high_resolution_clock start,stop;
std::chrono::duration <double, std::nano> d;
int main() {
    double oHashInsert = 0;
    double oHashRemove = 0;


    double BHavgInsert = 0;
    double BHavgExtract = 0;

    int dataBaseSize = 1000;//number of random elements added to DBs
    std::cout << "data base size = " << dataBaseSize << std::endl;
    //////////////////////
    //data base generation

for (size_t i = 0; i < 10; i++)
{
    openHash oHash(1000);

    
    for (int i = 0; i < dataBaseSize ; ++i) {
        oHash.insert(rData(rng));

    }
    /////////////////////////////
    //openHash testing

    //insert
    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        oHash.insert(rData(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        oHashInsert += d.count();
    }

    //remove
    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        oHash.remove(rData(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        oHashRemove += d.count();
    }
        
    oHash.display();
}

    std::cout << "-------------- OpenHash Testing --------------\n";
    oHashInsert /= 200;
    std::cout << "AvgInsert Time = " << oHashInsert << std::endl;
    oHashRemove /= 200;
    std::cout << "AvgRemove Time = " << oHashRemove << std::endl;
    



    return 0;

}

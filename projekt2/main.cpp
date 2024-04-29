#include "binaryHeap.cpp"
#include "orderedArray.cpp"
#include <iostream>
#include <ctime>  
#include <random>
#include<chrono>

mt19937 rng(time(0));
std::uniform_int_distribution<unsigned long> rData(0,10000);
std::uniform_int_distribution<unsigned long> rPriority(0,10000000);
std::chrono::high_resolution_clock start,stop;
std::chrono::duration <double, std::nano> d;
int main() {

    orderedArray orderedArray;
    binaryHeap binaryHeap;
    int dataBaseSize = 80000;//number of random elements added to DBs
    for (int i = 0; i < dataBaseSize ; ++i) {
        orderedArray.insert(rData(rng), rPriority(rng));
        binaryHeap.insert(rData(rng), rPriority(rng));

    }
    std::cout << "data base size = " << dataBaseSize << std::endl;

    //orderedArray testing
    std::cout << "-------------- Ordered Array Testing --------------\n";
    double avgInsert = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.insert(rData(rng), rPriority(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgInsert += d.count();
    }
        avgInsert /= 100;
        std::cout << "AvgInsert Time = " << avgInsert << std::endl;

    double avgExtract = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.extract();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgExtract += d.count();
    }
        avgExtract /= 100;
        std::cout << "AvgExtract Time = " << avgExtract << std::endl;
    

    double avgPeek = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.peek();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgPeek += d.count();
    }
        avgPeek /= 100;
        std::cout << "avgPeek Time = " << avgPeek << std::endl;


    double avgModify = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.modifyPriority(rData(rng), rPriority(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgModify += d.count();
    }
        avgModify /= 100;
        std::cout << "avgModify Time = " << avgModify << std::endl;


    double avgSize = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.getSize();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgSize += d.count();
    }
        avgSize /= 100;
        std::cout << "avgSize Time = " << avgSize << std::endl;


//BinaryHeap testing
    std::cout << "-------------- binary Heap Testing --------------\n";
     avgInsert = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.insert(rData(rng), rPriority(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgInsert += d.count();
    }
        avgInsert /= 100;
        std::cout << "AvgInsert Time = " << avgInsert << std::endl;

     avgExtract = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.extract();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgExtract += d.count();
    }
        avgExtract /= 100;
        std::cout << "AvgExtract Time = " << avgExtract << std::endl;
    

     avgPeek = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.peek();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgPeek += d.count();
    }
        avgPeek /= 100;
        std::cout << "avgPeek Time = " << avgPeek << std::endl;


     avgModify = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.modifyPriority(rData(rng), rPriority(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgModify += d.count();
    }
        avgModify /= 100;
        std::cout << "avgModify Time = " << avgModify << std::endl;


     avgSize = 0;
    for (int i = 0; i < 100; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.getSize();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        avgSize += d.count();
    }
        avgSize /= 100;
        std::cout << "avgSize Time = " << avgSize << std::endl;










    // while (!(orderedArray.getSize() == 0)) {
    //     Pair element = orderedArray.extract();
    //     std::cout << "Value: " << element.item << ", Priority: " << element.priority << std::endl;
    // }


    // printf("Dequeue:%d\n",pq2.extract()); // Output: 6

    // pq.modifyPriority(1, 20);
    // printf("Dequeue:%d\n",pq2.extract()); // Output: 1

    return 0;

}

//   while (!(pq.getSize() == 0)) {
//         Pair element = pq.extract();
//         std::cout << "Value: " << element.item << ", Priority: " << element.priority << std::endl;
//     }

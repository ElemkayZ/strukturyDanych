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
    double OAavgInsert = 0;
    double OAavgExtract = 0;
    double OAavgPeek = 0;
    double OAavgModify = 0;
    double OAavgSize = 0;

    double BHavgInsert = 0;
    double BHavgExtract = 0;
    double BHavgPeek = 0;
    double BHavgModify = 0;
    double BHavgSize = 0;
    int dataBaseSize = 70000;//number of random elements added to DBs
    std::cout << "data base size = " << dataBaseSize << std::endl;
for (size_t i = 0; i < 10; i++)
{
    orderedArray orderedArray;
    binaryHeap binaryHeap;

    
    for (int i = 0; i < dataBaseSize ; ++i) {
        orderedArray.insert(rData(rng), rPriority(rng));
        binaryHeap.insert(rData(rng), rPriority(rng));

    }

    //orderedArray testing
    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.insert(rData(rng), rPriority(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        OAavgInsert += d.count();
    }


    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.extract();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        OAavgExtract += d.count();
    }
        
    

    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.peek();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        OAavgPeek += d.count();
    }
        

    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.modifyPriority(rData(rng), rPriority(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        OAavgModify += d.count();
    }
        


    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        orderedArray.getSize();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        OAavgSize += d.count();
    }
        


//BinaryHeap testing
    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.insert(rData(rng), rPriority(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        BHavgInsert += d.count();
    }
    

    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.extract();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        BHavgExtract += d.count();
    }
    
    

    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.peek();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        BHavgPeek += d.count();
    }
    


    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.modifyPriority(rData(rng), rPriority(rng));
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        BHavgModify += d.count();
    }
    


    for (int i = 0; i < 20; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        binaryHeap.getSize();
        auto stop = std::chrono::high_resolution_clock::now();
        d = stop - start;
        BHavgSize += d.count();
    }
    



}

    std::cout << "-------------- Ordered Array Testing --------------\n";
    OAavgInsert /= 200;
    std::cout << "AvgInsert Time = " << OAavgInsert << std::endl;
    OAavgExtract /= 200;
    std::cout << "AvgExtract Time = " << OAavgExtract << std::endl;
    OAavgPeek /= 200;
    std::cout << "avgPeek Time = " << OAavgPeek << std::endl;
    OAavgModify /= 200;
    std::cout << "avgModify Time = " << OAavgModify << std::endl;
    OAavgSize /= 200;
    std::cout << "avgSize Time = " << OAavgSize << std::endl;

    std::cout << "-------------- binary Heap Testing --------------\n";
    BHavgInsert /= 200;
    std::cout << "AvgInsert Time = " << BHavgInsert << std::endl;
    BHavgExtract /= 200;
    std::cout << "AvgExtract Time = " << BHavgExtract << std::endl;
    BHavgPeek /= 200;
    std::cout << "avgPeek Time = " << BHavgPeek << std::endl;
    BHavgModify /= 200;
    std::cout << "avgModify Time = " << BHavgModify << std::endl;
    BHavgSize /= 200;
    std::cout << "avgSize Time = " << BHavgSize << std::endl;

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

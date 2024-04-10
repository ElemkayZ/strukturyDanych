#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "sigLinkList.cpp"
#include "SigNode.cpp"
#include "DubLinkList.cpp"
#include "DubNode.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include "file.cpp"
#include <chrono>
#include "ArrayList.cpp"
int main(){


    std::cout << "---------------MENU-------------------\n\n";
    std::cout << "ENTER GIVEN NUMBER FROM OPTIONS\n";
    std::cout << "OPTIONS:\n";
    std::cout << "1 - ArrayList\n";
    std::cout << "2 - Singley Linked List (only head)\n";
    std::cout << "3 - Singley Linked List (head and tail)\n";
    std::cout << "4 - Doubley Linked List\n";
    std::cout << "5 - Create Random Number File\n";
    std::cout << "0 - QUIT\n";
    int userInput= -1;
    int count;
    srand(time(0));

    while (userInput != 0 )
    {
        std::cout << "AWAITING INPUT\n";
        vector<string> randNumbList = readFile("randomNumbers8.txt");
        std::cout << ">";std::cin>>userInput;std::cout << "\n";
        int innerInput= -1;
        SigNode* showPtr = new SigNode;
        DubNode* showDubPtr = new DubNode;

        std::chrono::high_resolution_clock start,stop;
        std::chrono::duration <double, std::milli> d;
        if(userInput == 0){
            return 0;

        }
        if(userInput == 1){
            ArrayList* arrayList = new ArrayList();
            while (innerInput != 0 )
            {
                std::chrono::duration <double, std::milli> avg;
                std::cout << "\n---------------MENU-------------------\n\n";
                std::cout << "ENTER GIVEN NUMBER FROM OPTIONS\n";
                std::cout << "OPTIONS:\n";
                std::cout << "1 - Create From File\n";
                std::cout << "2 - Add\n";
                std::cout << "3 - Remove\n";
                std::cout << "4 - Find\n";
                std::cout << "5 - Show\n";
                std::cout << "0 - QUIT\n";

                std::cout << "\nAWAITING INPUT\n";
                std::cout << ">";std::cin>>innerInput;std::cout << "\n";
                if(innerInput == 0){
                    break;
                }
                if(innerInput == 1){
                    auto start = std::chrono::high_resolution_clock::now();
                    for(const std::string& number : randNumbList){
                    arrayList->add(stoi(number));
                    }
                    auto stop = std::chrono::high_resolution_clock::now();
                    d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                }
                if(innerInput == 2){
                    int addOption;
                    std::cout << "\n---------------MENU-------------------\n\n";
                    std::cout << "OPTIONS:\n";
                    std::cout << "1 - Add to End\n";
                    std::cout << "2 - Add in index\n";
                    std::cout << "3 - Add to Start\n";
                    std::cin>>addOption;
                    if(addOption == 1){
                        for (int i = 0; i < 5; i++)
                        {
                            auto start = std::chrono::high_resolution_clock::now();
                            arrayList->add(rand());
                            auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 2){
                        for (int i = 0; i < 5; i++)
                        {
                            int randNum = 1+rand()%(arrayList->getSize()-1);
                            auto start = std::chrono::high_resolution_clock::now();
                            arrayList->insert(randNum,rand());
                            auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 3){
                        for (int i = 0; i < 5; i++)
                        {
                            auto start = std::chrono::high_resolution_clock::now();
                            arrayList->insert(0,rand());
                            auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                }
                if(innerInput == 3){
                    int addOption;
                    std::cout << "\n---------------MENU-------------------\n\n";
                    std::cout << "OPTIONS:\n";
                    std::cout << "1 - Remove End\n";
                    std::cout << "2 - Remove in index\n";
                    std::cout << "3 - Remove Start\n";

                    std::cin>>addOption;
                    if(addOption == 1){
                        for (int i = 0; i < 5; i++)
                        {
                            auto start = std::chrono::high_resolution_clock::now();
                        arrayList->remove(arrayList->getSize()-1);
                            auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 2){
                        for (int i = 0; i < 5; i++)
                        {
                            int randNum = 1+rand()%(arrayList->getSize()-1);

                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->remove(randNum);
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 3){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->remove(0);
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                }
                if(innerInput == 4){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->search(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;

                }
                if(innerInput == 5){

                    arrayList->print();
                }

            }
            int innerInput = -1;
        }
        if(userInput == 2){
        SigLinklist* sigLinklist = new SigLinklist();
 
            while (innerInput != 0 )
            {
                std::chrono::duration <double, std::milli> avg;

                std::cout << "\n---------------MENU-------------------\n\n";
                std::cout << "ENTER GIVEN NUMBER FROM OPTIONS\n";
                std::cout << "OPTIONS:\n";
                std::cout << "1 - Create From File\n";
                std::cout << "2 - Add\n";
                std::cout << "3 - Remove\n";
                std::cout << "4 - Find\n";
                std::cout << "5 - Show\n";
                std::cout << "0 - QUIT\n";

                std::cout << "\nAWAITING INPUT\n";
                std::cout << ">";std::cin>>innerInput;std::cout << "\n";
                if(innerInput == 0){
                    break;
                }
                if(innerInput == 1){
                    auto start = std::chrono::high_resolution_clock::now();
                    for(const std::string& number : randNumbList){
                    sigLinklist->addEnd(stoi(number));
                    }
                    auto stop = std::chrono::high_resolution_clock::now();
                    d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                }
                if(innerInput == 2){
                    int addOption;
                    std::cout << "\n---------------MENU-------------------\n\n";
                    std::cout << "OPTIONS:\n";
                    std::cout << "1 - Add to End\n";
                    std::cout << "2 - Add in index\n";
                    std::cout << "3 - Add to Start\n";
                    std::cin>>addOption;
                    if(addOption == 1){
                        for (int i = 0; i < 5; i++){
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->addEnd(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 2){
                        for (int i = 0; i < 5; i++){
                            int randNum = 1+rand()%(sigLinklist->getLen()-1);

                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->add(randNum,rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 3){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->addStart(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                }
                if(innerInput == 3){
                    int addOption;
                    std::cout << "\n---------------MENU-------------------\n\n";
                    std::cout << "OPTIONS:\n";
                    std::cout << "1 - Remove End\n";
                    std::cout << "2 - Remove in index\n";
                    std::cout << "3 - Remove Start\n";

                    std::cin>>addOption;
                    if(addOption == 1){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->removeEnd();
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 2){
                        for (int i = 0; i < 5; i++)
                        {
                            int randNum = 1+rand()%(sigLinklist->getLen()-1);
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->remove(randNum);
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 3){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->removeStart();
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                }
                if(innerInput == 4){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->FindNumber(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;

                }
                if(innerInput == 5){

                    showPtr = sigLinklist->getHead();
                    while (showPtr != NULL)
                    {
                        printf("\n%d",showPtr->getData());
                        showPtr = showPtr->getAdress();
                    }
                }

            }
            int innerInput = -1;

        }
            if(userInput == 3){
            BetterSigLinklist* sigLinklist = new BetterSigLinklist();
 
            while (innerInput != 0 )
            {
                std::chrono::duration <double, std::milli> avg;

                std::cout << "\n---------------MENU-------------------\n\n";
                std::cout << "ENTER GIVEN NUMBER FROM OPTIONS\n";
                std::cout << "OPTIONS:\n";
                std::cout << "1 - Create From File\n";
                std::cout << "2 - Add\n";
                std::cout << "3 - Remove\n";
                std::cout << "4 - Find\n";
                std::cout << "5 - Show\n";
                std::cout << "0 - QUIT\n";

                std::cout << "\nAWAITING INPUT\n";
                std::cout << ">";std::cin>>innerInput;std::cout << "\n";
                if(innerInput == 0){
                    break;
                }
                if(innerInput == 1){
                    auto start = std::chrono::high_resolution_clock::now();
                    for(const std::string& number : randNumbList){
                    sigLinklist->addEnd(stoi(number));
                    }
                    auto stop = std::chrono::high_resolution_clock::now();
                    d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                }
                if(innerInput == 2){
                    int addOption;
                    std::cout << "\n---------------MENU-------------------\n\n";
                    std::cout << "OPTIONS:\n";
                    std::cout << "1 - Add to End\n";
                    std::cout << "2 - Add in index\n";
                    std::cout << "3 - Add in Start\n";
                    std::cin>>addOption;
                    if(addOption == 1){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->addEnd(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 2){
                        for (int i = 0; i < 5; i++)
                        {
                            int randNum = 1+rand()%(sigLinklist->getLen()-1);
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->add(randNum,rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 3){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->addStart(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                }
                if(innerInput == 3){
                    int addOption;
                    std::cout << "\n---------------MENU-------------------\n\n";
                    std::cout << "OPTIONS:\n";
                    std::cout << "1 - Remove End\n";
                    std::cout << "2 - Remove in index\n";
                    std::cout << "3 - Remove Start\n";
                    std::cin>>addOption;
                    if(addOption == 1){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->removeEnd();
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 2){
                        for (int i = 0; i < 5; i++)
                        {
                            int randNum = 1+rand()%(sigLinklist->getLen()-1);
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->remove(randNum);
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 3){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->removeStart();
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                }
                if(innerInput == 4){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->FindNumber(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;

                }
                if(innerInput == 5){

                    showPtr = sigLinklist->getHead();
                    while (showPtr != NULL)
                    {
                        printf("\n%d",showPtr->getData());
                        showPtr = showPtr->getAdress();
                    }
                }

            }
            int innerInput = -1;

        
            }
            if(userInput == 4){
            DubLinklist* dubLinklist = new DubLinklist();
 
            while (innerInput != 0 )
            {
                std::chrono::duration <double, std::milli> avg;

                std::cout << "\n---------------MENU-------------------\n\n";
                std::cout << "ENTER GIVEN NUMBER FROM OPTIONS\n";
                std::cout << "OPTIONS:\n";
                std::cout << "1 - Create From File\n";
                std::cout << "2 - Add\n";
                std::cout << "3 - Remove\n";
                std::cout << "4 - Find\n";
                std::cout << "5 - Show\n";
                std::cout << "0 - QUIT\n";

                std::cout << "\nAWAITING INPUT\n";
                std::cout << ">";std::cin>>innerInput;std::cout << "\n";
                if(innerInput == 0){
                    break;
                }
                if(innerInput == 1){
                    auto start = std::chrono::high_resolution_clock::now();
                    for(const std::string& number : randNumbList){
                    dubLinklist->addEnd(stoi(number));
                    }
                    auto stop = std::chrono::high_resolution_clock::now();
                    d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                }
                if(innerInput == 2){
                    int addOption;
                    std::cout << "\n---------------MENU-------------------\n\n";
                    std::cout << "OPTIONS:\n";
                    std::cout << "1 - Add to End\n";
                    std::cout << "2 - Add before index\n";
                    std::cout << "3 - Add after index\n";
                    std::cout << "4 - Add to Start\n";
                    std::cin>>addOption;
                    if(addOption == 1){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->addEnd(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 2){
                        for (int i = 0; i < 5; i++)
                        {
                            int randNum = 1+rand()%(dubLinklist->getLen()-1);
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->addBefore(randNum,rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 3){
                        for (int i = 0; i < 5; i++)
                        {
                            int randNum = 1+rand()%(dubLinklist->getLen()-1);
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->addAfter(randNum,rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 4){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->addStart(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                }
                if(innerInput == 3){
                    int addOption;
                    std::cout << "\n---------------MENU-------------------\n\n";
                    std::cout << "OPTIONS:\n";
                    std::cout << "1 - Remove End\n";
                    std::cout << "2 - Remove index\n";
                    std::cout << "1 - Remove Start\n";
                    std::cin>>addOption;
                    if(addOption == 1){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->removeEnd();
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 2){
                        for (int i = 0; i < 5; i++)
                        {
                            int randNum = 1+rand()%(dubLinklist->getLen()-1);
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->remove(randNum);
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                    if(addOption == 3){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->removeStart();
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;
                    }
                }
                if(innerInput == 4){
                        for (int i = 0; i < 5; i++)
                        {
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->findNumber(rand());
                        auto stop = std::chrono::high_resolution_clock::now();
                            d = stop - start;
                            avg = avg + d;
                        }
                        
                        avg = avg/4;
                    std::cout << "Time taken = " << avg.count() << std::endl;

                }
                if(innerInput == 5){

                    showDubPtr = dubLinklist->getHead();
                    while (showDubPtr != NULL)
                    {
                        printf("\n%d",showDubPtr->getData());
                        showDubPtr = showDubPtr->getNext();
                    }
                }

            }
            int innerInput = -1;

            }
            if(userInput == 0){
                return 0;
            }
            if(userInput == 5){
            GenRandNumbFile();
            }
    }
    userInput= -1;

        
}

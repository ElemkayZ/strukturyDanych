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
                        std::cout << "Input Number\n";    
                        int _data;
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->add(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 2){
                        int _data,_idx;
                        std::cout << "Input Number\n";    
                        std::cin >> _data;
                        std::cout << "Input Index\n";    
                        std::cin >> _idx;
                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->insert(_idx,_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 3){
                        std::cout << "Input Number\n";    
                        int _data;
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->insert(_data,0);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
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
                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->remove(arrayList->getSize()-1);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 2){
                        int _idx;
                        std::cout << "Input Number\n";    
                        std::cin >> _idx    ;
                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->remove(_idx);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 3){
                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->remove(0);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                }
                if(innerInput == 4){
                        int _data;
                        std::cout << "Input Number\n";  
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        arrayList->search(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        // printf("\n%d",arrayList[_data]);
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;

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
                        std::cout << "Input Number\n";    
                        int _data;
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->addEnd(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 2){
                        int _data,_idx;
                        std::cout << "Input Number\n";    
                        std::cin >> _data;
                        std::cout << "Input Index\n";    
                        std::cin >> _idx;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->add(_idx,_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 3){
                        std::cout << "Input Number\n";    
                        int _data;
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->addStart(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
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
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->removeEnd();
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 2){
                        int _idx;
                        std::cout << "Input Number\n";    
                        std::cin >> _idx    ;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->remove(_idx);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 3){
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->removeStart();
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                }
                if(innerInput == 4){
                        int _data;
                        std::cout << "Input Number\n";  
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->FindNumber(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        printf("\n%d",sigLinklist);
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;

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
                        std::cout << "Input Number\n";    
                        int _data;
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->addEnd(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 2){
                        int _data,_idx;
                        std::cout << "Input Number\n";    
                        std::cin >> _data;
                        std::cout << "Input Index\n";    
                        std::cin >> _idx;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->add(_idx,_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 3){
                        std::cout << "Input Number\n";    
                        int _data;
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->addStart(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
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
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->removeEnd();
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 2){
                        int _idx;
                        std::cout << "Input Number\n";    
                        std::cin >> _idx    ;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->remove(_idx);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 3){
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->removeStart();
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                }
                if(innerInput == 4){
                        int _data;
                        std::cout << "Input Number\n";  
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        sigLinklist->FindNumber(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        printf("\n%d",sigLinklist);
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;

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
                        std::cout << "Input Number\n";    
                        int _data;
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->addEnd(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 2){
                        int _data,_idx;
                        std::cout << "Input Number\n";    
                        std::cin >> _data;
                        std::cout << "Input Index\n";    
                        std::cin >> _idx;
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->addBefore(_idx,_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 3){
                        int _data,_idx;
                        std::cout << "Input Number\n";    
                        std::cin >> _data;
                        std::cout << "Input Index\n";    
                        std::cin >> _idx;
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->addAfter(_idx,_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 4){
                        std::cout << "Input Number\n";    
                        int _data;
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->addStart(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
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
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->removeEnd();
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 2){
                        int _idx;
                        std::cout << "Input Number\n";    
                        std::cin >> _idx    ;
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->remove(_idx);
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;
                    }
                    if(addOption == 3){
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->removeStart();
                        auto stop = std::chrono::high_resolution_clock::now();
                        d = stop - start;
                    std::cout << "Time taken = " << d.count() << std::endl;
                    }
                }
                if(innerInput == 4){
                        int _data;
                        std::cout << "Input Number\n";  
                        std::cin >> _data;
                        auto start = std::chrono::high_resolution_clock::now();
                        dubLinklist->findNumber(_data);
                        auto stop = std::chrono::high_resolution_clock::now();
                        printf("\n%d",dubLinklist);
                        d = stop - start;
                        std::cout << "Time taken = " << d.count() << std::endl;

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

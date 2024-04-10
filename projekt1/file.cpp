#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>  
#include <vector>
#include <istream>
#include <string>
using namespace std;

void GenRandNumbFile() {
    int numNumbers;
    cout << "Enter the number of random numbers to generate: ";
    cin >> numNumbers;
    ofstream outFile("randomNumbers5.txt", std::ios::out | std::ios::trunc);
    if (!outFile) {
        cerr << "Unable to open file" << endl;
        return ;
    }
    srand(time(0));
    for (int i = 0; i < numNumbers; ++i) {
        int randomNumber = rand(); 
        outFile << randomNumber << endl; 
    }
    outFile.close();
    return;
}
vector<string> readFile(string _file){
    ifstream inFile(_file);
    vector<string> numberList;
    string line;
    while (getline(inFile, line)) {
        numberList.push_back(line);
    }
    
    inFile.close();
    return numberList;
}
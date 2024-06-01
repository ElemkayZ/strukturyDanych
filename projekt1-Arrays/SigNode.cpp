#include <stdio.h>
#include <stdlib.h>
#include "SigNode.h"
/////////////////////////////////////////////////////////
// SigNode CLASS
/////////////////////////////////////////////////////////
//default constructor
SigNode::SigNode(){
    this->data = 0;
    this->adress = NULL;
}
//element insertion constructor
SigNode::SigNode(int _data){
    this->data = _data;
    this->adress = NULL;
}
//get data from SigNode function
int SigNode::getData(){
    return this->data;
}
//get pointer for next SigNode function
SigNode* SigNode::getAdress(){
    return this->adress;
}
//change data of SigNode function
void SigNode::changeData(int _data){
    this->data = _data;
}
//change adress of SigNode function
void SigNode::changeAdress(SigNode* _adress){
    this->adress = _adress;
}
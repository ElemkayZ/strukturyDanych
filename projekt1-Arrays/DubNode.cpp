#include <stdio.h>
#include <stdlib.h>
#include "DubNode.h"
/////////////////////////////////////////////////////////
// DubNode CLASS
/////////////////////////////////////////////////////////
//default constructor
DubNode::DubNode(){
    this->data = 0;
    this->next = NULL;
    this->prev = NULL;
}
//element insertion constructor
DubNode::DubNode(int _data){
    this->data = _data;
    this->next = NULL;
    this->prev = NULL;
}
//get data from DubNode function
int DubNode::getData(){
    return this->data;
}
//get pointer for next DubNode function
DubNode* DubNode::getNext(){
    return this->next;
}
//change data of DubNode function
void DubNode::changeData(int _data){
    this->data = _data;
}
//change next of DubNode function
void DubNode::changeNext(DubNode* _next){
    this->next = _next;
}
//get pointer for prev DubNode function
DubNode* DubNode::getPrev(){
    return this->prev;
}
//change prev of DubNode function
void DubNode::changePrev(DubNode* _prev){
    this->prev = _prev;
}
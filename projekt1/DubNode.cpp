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
}
//element insertion constructor
DubNode::DubNode(int _data){
    this->data = _data;
    this->next = NULL;
}
//get data from DubNode function
int DubNode::getData(){
    return this->data;
}
//get pointer for next DubNode function
DubNode* DubNode::getnext(){
    return this->next;
}
//change data of DubNode function
void DubNode::changeData(int _data){
    this->data = _data;
}
//change next of DubNode function
void DubNode::changenext(DubNode* _next){
    this->next = _next;
}
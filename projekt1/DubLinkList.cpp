#include <stdio.h>
#include <stdlib.h>
#include "DubLinkList.h"
#include <math.h>
/////////////////////////////////////////////////////////
// DubLinkList CLASS
/////////////////////////////////////////////////////////
//default constructor
DubLinklist::DubLinklist(){
    this->head = NULL;
    this->tail = NULL;
    this->len = 0;
}
//function adding new DubNode at the end
void DubLinklist::addEnd(int _data){
    DubNode *newDubNode = new DubNode(_data);
    newDubNode->changePrev(this->tail);
    this->tail = newDubNode;
    if(newDubNode->getPrev()){
        newDubNode->getPrev()->changeNext(newDubNode);
    }
    else{
        this->head = newDubNode;
    }
    this->len++;
}
//function adding new DubNode at the start
void DubLinklist::addStart(int _data){
    DubNode *newDubNode = new DubNode(_data);
    newDubNode->changeNext(head);
    head = newDubNode;
    if (newDubNode->getNext())
        newDubNode->getNext()->changePrev(newDubNode);
    else{
        this->tail = newDubNode;
    }
    this->len++;
}
/////////////////////////////////////////////////////

//function removing DubNode at start
void DubLinklist::removeStart(){
    if(head == NULL){
        printf("empty DubLinkList");
        return;
    }
    DubNode *iterator = head;
    this->head->getNext()->changePrev(NULL);
    this->head = head->getNext();
    delete iterator;
        this->len--;

}
DubNode* DubLinklist::getHead(){
    return this->head;
}
DubNode* DubLinklist::getTail(){
    return this->tail;
}
//function removing DubNode on given offset
void DubLinklist::remove(int DubNodeOffset){
    if(head == NULL){
        printf("empty DubLinkList");
        return;
    }
    int count = this->getLen();
    if(count<=DubNodeOffset){
        printf("index out of range");
        return;
    }
    if(DubNodeOffset == 0){
        this->removeStart();
        return;
    }
    if(DubNodeOffset == this->len-1){
        this->removeEnd();
        return;
    }
    DubNode *bevoreNode =  this->getNode(DubNodeOffset);
    if(bevoreNode->getPrev()){
        bevoreNode->getPrev()->changeNext(bevoreNode->getNext());
    }
    else{
        this->head = bevoreNode->getNext();
    }
    if(bevoreNode->getNext()){
        bevoreNode->getNext()->changePrev(bevoreNode->getPrev());
    }else{
        this->tail = bevoreNode->getPrev();
    }
    delete bevoreNode;
    this->len--;
}
//function returning number of DubNodes in linked list
int DubLinklist::getLen(){
    return this->len;
}
DubNode* DubLinklist::getNode(int _idx){
    if(_idx <= static_cast<int>(this->len/2)-1){
        DubNode* node = this->head;

        for (int i = 0; i < _idx; i++)
        {
            node = node->getNext();
        }
        return node;
    }
    else{
        DubNode* node = this->tail;
        _idx = this->len-_idx-1;
        for (int i = 0; i < _idx; i++)
        {
            node = node->getPrev();
        }
        return node;
    }
}
//function adding DubNode on given offset
void DubLinklist::addBefore(int DubNodeOffset,int _data){
    int count = this->getLen();
    if(count<=DubNodeOffset){
        printf("index out of range");
        return;
    }
    if(DubNodeOffset == 1){
        this->addStart(_data);
    }
    else{
        DubNode *newDubNode = new DubNode(_data);
        DubNode *bevoreNode =  this->getNode(DubNodeOffset);
        newDubNode->changeNext(bevoreNode);
        newDubNode->changePrev(bevoreNode->getPrev());
        bevoreNode->getPrev()->changeNext(newDubNode);
        bevoreNode->changePrev(newDubNode);
        this->len++;
    }

}
void DubLinklist::addAfter(int DubNodeOffset,int _data){
    int count = this->getLen();
    if(count<=DubNodeOffset){
        printf("index out of range");
        return;
    }
    if(DubNodeOffset == count-1){
        this->addEnd(_data);
        return;
    }
    else{
        DubNode *bevoreNode =  this->getNode(DubNodeOffset);
        DubNode *newDubNode = new DubNode(_data);
        newDubNode->changeNext(bevoreNode->getNext());
        newDubNode->changePrev(bevoreNode);
        newDubNode->getNext()->changePrev(newDubNode);
        bevoreNode->changeNext(newDubNode);
        this->len++;
    }
}
//function removing last DubNode
void DubLinklist::removeEnd(){
    if(head == NULL){
        printf("empty DubLinkList");
        return;
    }
    DubNode *iterator = tail;
    this->tail->getPrev()->changeNext(NULL);
    this->tail = tail->getPrev();
    delete iterator;
        this->len--;

}
DubNode* DubLinklist::findNumber(int _number){
    if(_number <= static_cast<int>(this->len/2)-1){
        DubNode* ptr = this->head;
        while (ptr->getNext())
        {
            if(ptr->getData()==_number){
                return ptr;
            }
            ptr = ptr->getNext();

        }
    }
    else{
        DubNode* ptr = this->tail;
        while (ptr->getPrev())
        {
            if(ptr->getData()==_number){
                return ptr;
            }
        ptr = ptr->getPrev();

        }
    }
    
    return NULL;
};
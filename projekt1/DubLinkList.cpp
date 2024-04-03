#include <stdio.h>
#include <stdlib.h>
#include "DubLinkList.h"
/////////////////////////////////////////////////////////
// DubLinkList CLASS
/////////////////////////////////////////////////////////
//default constructor
DubLinklist::DubLinklist(){
    this->head = NULL;
    this->tail = NULL;
}
//function adding new DubNode at the end
void DubLinklist::addEnd(int _data){
    DubNode *newDubNode = new DubNode(_data);
    newDubNode->changeData(_data);
    if(head == NULL){
        this->head = newDubNode;
        this->tail = newDubNode;
        return;
    }
    this->getTail()->changeNext(newDubNode);
    this->tail = newDubNode;
}
//function adding new DubNode at the start
void DubLinklist::addStart(int _data){
    DubNode *newDubNode = new DubNode(_data);
    newDubNode->changeNext(head);
    head = newDubNode;
}
//function removing DubNode at the start
void DubLinklist::removeStart(){
    DubNode *iterator = new DubNode();
    iterator->changeNext(this->head->getNext());
    head=head->getNext();
    delete iterator;

}
DubNode* DubLinklist::getHead(){
    return this->head;
}
DubNode* DubLinklist::getTail(){
    return this->tail;
}
//function removing DubNode on given offset
void DubLinklist::remove(int DubNodeOffset){
    int count = this->getLen();
    if(head == NULL){
        printf("empty DubLinkList");
        return;
    }
    if(count<DubNodeOffset){
        printf("index out of range");
        return;
    }
    if(DubNodeOffset == 1){
        this->removeStart();
        return;
    }
    DubNode *iterator = new DubNode();
    DubNode *iterator2 = new DubNode();
    iterator = head;
    while(DubNodeOffset-- > 1){
        iterator2 = iterator;
        iterator = iterator->getNext();
    }
    iterator2->changeNext(iterator->getNext());
    delete iterator;
}
//function returning number of DubNodes in linked list
int DubLinklist::getLen(){
    DubNode *iterator = new DubNode();
    int count = 0;
    iterator->changeNext(this->head);
    while(iterator != NULL){
        iterator = iterator->getNext();
        count++;
    }
    delete iterator;
    return count;
}
//function adding DubNode on given offset
void DubLinklist::add(int DubNodeOffset,int _data){
    DubNode *newDubNode = new DubNode(_data);
    newDubNode->changeData(_data);
    if(head == NULL){
        head = newDubNode;
        return;
    }
    int count = this->getLen();
    if(count<DubNodeOffset){
        printf("index out of range");
        return;
    }
    if(DubNodeOffset == 1){
        this->addStart(_data);
        return;
    }
    if(DubNodeOffset == count){
        this->addEnd(_data);
        return;
    }
    DubNode *iterator = new DubNode();
    DubNode *iterator2 = new DubNode();
    iterator = head;
    while(DubNodeOffset-- > 1){
        iterator2 = iterator;
        iterator = iterator->getNext();
    }
    newDubNode->changeNext(iterator->getNext());
    iterator2->changeNext(newDubNode);

}
//function removing last DubNode
void DubLinklist::removeEnd(){
DubNode *iterator = new DubNode();
    DubNode *iterator2 = new DubNode();
    iterator = head;
    while(iterator->getNext()!=NULL){
        iterator2 = iterator;
        iterator = iterator->getNext();
    }
    iterator2->changeNext(NULL);
    this->tail = iterator;
    delete iterator;
}
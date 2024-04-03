#include <stdio.h>
#include <stdlib.h>
#include "sigLinkList.h"
/////////////////////////////////////////////////////////
// NODE CLASS
/////////////////////////////////////////////////////////
//default constructor
Node::Node(){
    this->data = 0;
    this->adress = NULL;
}
//element insertion constructor
Node::Node(int _data){
    this->data = _data;
    this->adress = NULL;
}
//get data from node function
int Node::getData(){
    return this->data;
}
//get pointer for next node function
Node* Node::getAdress(){
    return this->adress;
}
//change data of node function
void Node::changeData(int _data){
    this->data = _data;
}
//change adress of node function
void Node::changeAdress(Node* _adress){
    this->adress = _adress;
}
/////////////////////////////////////////////////////////
// SigLinkList CLASS
/////////////////////////////////////////////////////////
//default constructor
SigLinklist::SigLinklist(){
    this->head = NULL;
}
//function returning pointer to last node
Node* SigLinklist::getLastNode(){
    Node *iterator = head;
    while(iterator->getAdress()!=NULL){
        iterator = iterator->getAdress();
    }
    return iterator;
}
//function adding new node at the end
void SigLinklist::addEnd(int _data){
    Node *newNode = new Node(_data);
    newNode->changeData(_data);
    if(head == NULL){
        head = newNode;
        return;
    }
    this->getLastNode()->changeAdress(newNode);
}
//function adding new node at the start
void SigLinklist::addStart(int _data){
    Node *newNode = new Node(_data);
    newNode->changeAdress(head);
    head = newNode;
}
void SigLinklist::removeStart(){
    Node *iterator = new Node();
    iterator->changeAdress(this->head->getAdress());
    head=head->getAdress();
    delete iterator;

}
Node* SigLinklist::getHead(){
    return this->head;
}
//function removing node on given offset
void SigLinklist::remove(int nodeOffset){
    int count = this->getLen();
    if(head == NULL){
        printf("empty SigLinkList");
        return;
    }
    if(count<nodeOffset){
        printf("index out of range");
        return;
    }
    if(nodeOffset == 1){
        this->removeStart();
        return;
    }
    Node *iterator = new Node();
    Node *iterator2 = new Node();
    iterator = head;
    while(nodeOffset-- > 1){
        iterator2 = iterator;
        iterator = iterator->getAdress();
    }
    iterator2->changeAdress(iterator->getAdress());
    delete iterator;
}
//function returning number of nodes in linked list
int SigLinklist::getLen(){
    Node *iterator = new Node();
    int count = 0;
    iterator->changeAdress(this->head);
    while(iterator != NULL){
        iterator = iterator->getAdress();
        count++;
    }
    delete iterator;
    return count;
}
//function adding node on given offset
void SigLinklist::add(int nodeOffset,int _data){
    Node *newNode = new Node(_data);
    newNode->changeData(_data);
    if(head == NULL){
        head = newNode;
        return;
    }
    int count = this->getLen();
    if(count<nodeOffset){
        printf("index out of range");
        return;
    }
    if(nodeOffset == 1){
        this->addStart(_data);
        return;
    }
    Node *iterator = new Node();
    Node *iterator2 = new Node();
    iterator = head;
    while(nodeOffset-- > 1){
        iterator2 = iterator;
        iterator = iterator->getAdress();
    }
    newNode->changeAdress(iterator->getAdress());
    iterator2->changeAdress(newNode);

}
//function removing last node
void SigLinklist::removeEnd(){
Node *iterator = new Node();
    Node *iterator2 = new Node();
    iterator = head;
    while(iterator->getAdress()!=NULL){
        iterator2 = iterator;
        iterator = iterator->getAdress();
    }
    iterator2->changeAdress(NULL);
    delete iterator;
}

/////////////////////////////////////////////////////////
// BetterSigLinkList CLASS
/////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "sigLinkList.h"

/////////////////////////////////////////////////////////
// SigLinkList CLASS
/////////////////////////////////////////////////////////
//default constructor
SigLinklist::SigLinklist(){
    this->head = NULL;
}
//function returning pointer to last SigNode
SigNode* SigLinklist::getLastSigNode(){
    SigNode *iterator = head;
    while(iterator->getAdress()!=NULL){
        iterator = iterator->getAdress();
    }
    return iterator;
}
//function adding new SigNode at the end
void SigLinklist::addEnd(int _data){
    SigNode *newSigNode = new SigNode(_data);
    newSigNode->changeData(_data);
    if(head == NULL){
        head = newSigNode;
        return;
    }
    this->getLastSigNode()->changeAdress(newSigNode);
}
//function adding new SigNode at the start
void SigLinklist::addStart(int _data){
    SigNode *newSigNode = new SigNode(_data);
    newSigNode->changeAdress(head);
    head = newSigNode;
}
void SigLinklist::removeStart(){
    SigNode *iterator = new SigNode();
    iterator->changeAdress(this->head->getAdress());
    head=head->getAdress();
    delete iterator;

}
SigNode* SigLinklist::getHead(){
    return this->head;
}
//function removing SigNode on given offset
void SigLinklist::remove(int SigNodeOffset){
    int count = this->getLen();
    if(head == NULL){
        printf("empty SigLinkList");
        return;
    }
    if(count<SigNodeOffset){
        printf("index out of range");
        return;
    }
    if(SigNodeOffset == 1){
        this->removeStart();
        return;
    }
    SigNode *iterator = new SigNode();
    SigNode *iterator2 = new SigNode();
    iterator = head;
    while(SigNodeOffset-- > 1){
        iterator2 = iterator;
        iterator = iterator->getAdress();
    }
    iterator2->changeAdress(iterator->getAdress());
    delete iterator;
}
//function returning number of SigNodes in linked list
int SigLinklist::getLen(){
    SigNode *iterator = new SigNode();
    int count = 0;
    iterator->changeAdress(this->head);
    while(iterator != NULL){
        iterator = iterator->getAdress();
        count++;
    }
    delete iterator;
    return count;
}
//function adding SigNode on given offset
void SigLinklist::add(int SigNodeOffset,int _data){
    SigNode *newSigNode = new SigNode(_data);
    newSigNode->changeData(_data);
    if(head == NULL){
        head = newSigNode;
        return;
    }
    int count = this->getLen();
    if(count<SigNodeOffset){
        printf("index out of range");
        return;
    }
    if(SigNodeOffset == 1){
        this->addStart(_data);
        return;
    }
    SigNode *iterator = new SigNode();
    SigNode *iterator2 = new SigNode();
    iterator = head;
    while(SigNodeOffset-- > 1){
        iterator2 = iterator;
        iterator = iterator->getAdress();
    }
    newSigNode->changeAdress(iterator->getAdress());
    iterator2->changeAdress(newSigNode);

}
//function removing last SigNode
void SigLinklist::removeEnd(){
SigNode *iterator = new SigNode();
    SigNode *iterator2 = new SigNode();
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
//default constructor
BetterSigLinklist::BetterSigLinklist(){
    this->head = NULL;
    this->tail = NULL;
}
//function adding new SigNode at the end
void BetterSigLinklist::addEnd(int _data){
    SigNode *newSigNode = new SigNode(_data);
    newSigNode->changeData(_data);
    if(head == NULL){
        this->head = newSigNode;
        this->tail = newSigNode;
        return;
    }
    this->getTail()->changeAdress(newSigNode);
    this->tail = newSigNode;
}
//function adding new SigNode at the start
void BetterSigLinklist::addStart(int _data){
    SigNode *newSigNode = new SigNode(_data);
    newSigNode->changeAdress(head);
    head = newSigNode;
}
//function removing SigNode at the start
void BetterSigLinklist::removeStart(){
    SigNode *iterator = new SigNode();
    iterator->changeAdress(this->head->getAdress());
    head=head->getAdress();
    delete iterator;

}
SigNode* BetterSigLinklist::getHead(){
    return this->head;
}
SigNode* BetterSigLinklist::getTail(){
    return this->tail;
}
//function removing SigNode on given offset
void BetterSigLinklist::remove(int SigNodeOffset){
    int count = this->getLen();
    if(head == NULL){
        printf("empty BetterSigLinklist");
        return;
    }
    if(count<SigNodeOffset){
        printf("index out of range");
        return;
    }
    if(SigNodeOffset == 1){
        this->removeStart();
        return;
    }
    SigNode *iterator = new SigNode();
    SigNode *iterator2 = new SigNode();
    iterator = head;
    while(SigNodeOffset-- > 1){
        iterator2 = iterator;
        iterator = iterator->getAdress();
    }
    iterator2->changeAdress(iterator->getAdress());
    delete iterator;
}
//function returning number of SigNodes in linked list
int BetterSigLinklist::getLen(){
    SigNode *iterator = new SigNode();
    int count = 0;
    iterator->changeAdress(this->head);
    while(iterator != NULL){
        iterator = iterator->getAdress();
        count++;
    }
    delete iterator;
    return count;
}
//function adding SigNode on given offset
void BetterSigLinklist::add(int SigNodeOffset,int _data){
    SigNode *newSigNode = new SigNode(_data);
    newSigNode->changeData(_data);
    if(head == NULL){
        head = newSigNode;
        return;
    }
    int count = this->getLen();
    if(count<SigNodeOffset){
        printf("index out of range");
        return;
    }
    if(SigNodeOffset == 1){
        this->addStart(_data);
        return;
    }
    if(SigNodeOffset == count){
        this->addEnd(_data);
        return;
    }
    SigNode *iterator = new SigNode();
    SigNode *iterator2 = new SigNode();
    iterator = head;
    while(SigNodeOffset-- > 1){
        iterator2 = iterator;
        iterator = iterator->getAdress();
    }
    newSigNode->changeAdress(iterator->getAdress());
    iterator2->changeAdress(newSigNode);

}
//function removing last SigNode
void BetterSigLinklist::removeEnd(){
SigNode *iterator = new SigNode();
    SigNode *iterator2 = new SigNode();
    iterator = head;
    while(iterator->getAdress()!=NULL){
        iterator2 = iterator;
        iterator = iterator->getAdress();
    }
    iterator2->changeAdress(NULL);
    this->tail = iterator;
    delete iterator;
}
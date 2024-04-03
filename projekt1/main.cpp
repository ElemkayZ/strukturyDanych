#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "sigLinkList.cpp"
#include "SigNode.cpp"

int main(){
    BetterSigLinklist *lista = new BetterSigLinklist();
    for (int i = 1; i < 100; i++)
    {
        lista->addEnd(i);
    }
    lista->removeStart();
    lista->addEnd(69);
    lista->addStart(69);
    lista->remove(98);
    lista->add(5,69);
    lista->removeEnd();
    printf("%d",lista->getLen());
    SigNode *ptr = new SigNode();
    ptr = lista->getHead();
    
    while (ptr != NULL)
    {
        printf("\n%d",ptr->getData());
        // ptr->changeAdress(ptr->getAdress()); ---- zły sposób
        ptr = ptr->getAdress(); // dobry sposób
    }
    
    return 0;
}

#ifndef SingleLinkedList_hpp
#define SingleLinkedList_hpp

#include <stdio.h>

#include "SingleLinkedNode.hpp"

class SingleLinkedList
{
public:
    SingleLinkedList();
    void AddHead(int newVal);
    void AddTail(int newVal);
    void RemoveNode(int val);
    void RemoveAt(int index);
    
    SingleLinkedNode* head;
private:
    
};
#endif /* SingleLinkedList_hpp */

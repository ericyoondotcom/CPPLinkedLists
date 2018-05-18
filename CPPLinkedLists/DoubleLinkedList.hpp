
#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include <stdio.h>

#include "DoubleLinkedNode.hpp"

class DoubleLinkedList
{
public:
    DoubleLinkedList();
    void AddHead(int newVal);
    void AddTail(int newVal);
    void RemoveNode(int val);
    void RemoveAt(int index);
    
    DoubleLinkedNode* head;
private:
    
};
#endif /* DoubleLinkedList_hpp */

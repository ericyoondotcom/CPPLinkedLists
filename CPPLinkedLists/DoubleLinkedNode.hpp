#ifndef DoubleLinkedNode_hpp
#define DoubleLinkedNode_hpp

#include <stdio.h>
class DoubleLinkedNode
{
public:
    DoubleLinkedNode(int val);
    int value;
    DoubleLinkedNode* next;
    DoubleLinkedNode* prev;
private:
    
};
#endif /* DoubleLinkedNode_hpp */

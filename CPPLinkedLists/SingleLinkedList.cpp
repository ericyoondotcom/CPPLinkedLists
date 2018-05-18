

#include "SingleLinkedList.hpp"




SingleLinkedList::SingleLinkedList()
{
    
}

void SingleLinkedList::AddHead(int newVal){
    SingleLinkedNode* oldHead = head;
    head = new SingleLinkedNode(newVal);
    
    head->next = oldHead;
}
void SingleLinkedList::AddTail(int newVal){
    if(head == NULL){
        head = new SingleLinkedNode(newVal);
        return;
    }
    SingleLinkedNode* currNode = head;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }
    currNode->next = new SingleLinkedNode(newVal);
}

void SingleLinkedList::RemoveNode(int val){
    if(head->value == val){
        head = head->next;
        return;
    }
    SingleLinkedNode* prevNode = nullptr;
    SingleLinkedNode* currNode = head;
    while(currNode->value != val){
        if(currNode->next == NULL){
            throw "Node could not be found";
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = currNode->next;
    
    delete currNode;
    currNode = nullptr;
}
void SingleLinkedList::RemoveAt(int index){
    if(index == 0){
        head = head->next;
        return;
    }
    SingleLinkedNode* prevNode = nullptr;
    SingleLinkedNode* currNode = head;
    for(int i = 0; i < index; i++){
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = currNode->next;
    delete currNode;
    currNode = nullptr;
    
}

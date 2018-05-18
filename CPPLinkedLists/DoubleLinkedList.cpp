

#include "DoubleLinkedList.hpp"




DoubleLinkedList::DoubleLinkedList()
{
    
}

void DoubleLinkedList::AddHead(int newVal){
    DoubleLinkedNode* oldHead = head;
    head = new DoubleLinkedNode(newVal);
    head->next = oldHead;
    if(head->next != nullptr) head->next->prev = head;
    
}
void DoubleLinkedList::AddTail(int newVal){
    if(head == NULL){
        head = new DoubleLinkedNode(newVal);
        return;
    }
    DoubleLinkedNode* currNode = head;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }
    currNode->next = new DoubleLinkedNode(newVal);
    currNode->next->prev = currNode;
}

void DoubleLinkedList::RemoveNode(int val){
    if(head->value == val){
        head = head->next;
        if(head->next != nullptr) head->next->prev = nullptr;
        return;
    }
    DoubleLinkedNode* prevNode = nullptr;
    DoubleLinkedNode* currNode = head;
    while(currNode->value != val){
        if(currNode->next == NULL){
            throw "Node could not be found";
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
    
    delete currNode;
    currNode = nullptr;
}
void DoubleLinkedList::RemoveAt(int index){
    if(index == 0){
        head = head->next;
        if(head->next != nullptr) head->next->prev = nullptr;
        return;
    }
    DoubleLinkedNode* prevNode = nullptr;
    DoubleLinkedNode* currNode = head;
    for(int i = 0; i < index; i++){
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
    delete currNode;
    currNode = nullptr;
    
}

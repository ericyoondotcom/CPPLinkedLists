#ifndef DoubleLinkedListTemplates_hpp
#define DoubleLinkedListTemplates_hpp

#include <stdio.h>
#include "DoubleLinkedNodeTemplates.hpp"

using namespace std;

template <class T>
class DoubleLinkedListTemplates 
{
public:
    DoubleLinkedListTemplates();
    void AddHead(T newVal);
    void AddTail(T newVal);
    void RemoveNode(T val);
    void RemoveAt(int index);
    
    DoubleLinkedNodeTemplates<T>* head;
private:
    
};

template <class T>
DoubleLinkedListTemplates<T>::DoubleLinkedListTemplates()
{
    
}

template <class T>
void DoubleLinkedListTemplates<T>::AddHead(T newVal){
    DoubleLinkedNodeTemplates<T>* oldHead = head;
    head = new DoubleLinkedNodeTemplates<T>(newVal);
    head->next = make_shared<DoubleLinkedNodeTemplates<T>>(oldHead);
    if(head->next != nullptr) head->next->prev = make_shared<DoubleLinkedNodeTemplates<T>>(head);
    
}

template <class T>
void DoubleLinkedListTemplates<T>::AddTail(T newVal){
    if(head == NULL){
        head = new DoubleLinkedNodeTemplates<T>(newVal);
        return;
    }
    DoubleLinkedNodeTemplates<T>* currNode = head;
    while(currNode->next != NULL){
        currNode = currNode->next;
    }
    currNode->next = make_shared<DoubleLinkedNodeTempates<T>>(new DoubleLinkedNodeTemplates<T>(newVal));
    currNode->next->prev = make_shared<DoubleLinkedNodeTempates<T>>(currNode);
}

template <class T>
void DoubleLinkedListTemplates<T>::RemoveNode(T val){
    if(head->value == val){
        head = head->next;
        if(head->next != nullptr) head->next->prev = nullptr;
        return;
    }
    DoubleLinkedNodeTemplates<T>* prevNode = nullptr;
    DoubleLinkedNodeTemplates<T>* currNode = head;
    while(currNode->value != val){
        if(currNode->next == NULL){
            throw "Node could not be found";
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
    
    //delete currNode; should be taken care of by the sharedptrs??
    currNode = nullptr;
}

template <class T>
void DoubleLinkedListTemplates<T>::RemoveAt(int index){
    if(index == 0){
        head = head->next;
        if(head->next != nullptr) head->next->prev = nullptr;
        return;
    }
    DoubleLinkedNodeTemplates<T>* prevNode = nullptr;
    DoubleLinkedNodeTemplates<T>* currNode = head;
    for(int i = 0; i < index; i++){
        prevNode = currNode;
        currNode = currNode->next;
    }
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
    //delete currNode;
    currNode = nullptr;
    
}



#endif /* DoubleLinkedListTemplates_hpp */

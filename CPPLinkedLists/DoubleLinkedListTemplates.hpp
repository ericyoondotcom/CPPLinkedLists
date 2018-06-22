#ifndef DoubleLinkedListTemplates_hpp
#define DoubleLinkedListTemplates_hpp

#include <stdio.h>
#include "DoubleLinkedNodeTemplates.hpp"
#include <memory>

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
    head = nullptr;
}

template <class T>
void DoubleLinkedListTemplates<T>::AddHead(T newVal){
    DoubleLinkedNodeTemplates<T>* oldHead = head;
    head = new DoubleLinkedNodeTemplates<T>(newVal);
    head->next = make_shared<DoubleLinkedNodeTemplates<T>>(*oldHead);
    if(head->next != nullptr) head->next->prev = make_shared<DoubleLinkedNodeTemplates<T>>(*head);
    
}

template <class T>
void DoubleLinkedListTemplates<T>::AddTail(T newVal){
    if(head == nullptr){
        head = new DoubleLinkedNodeTemplates<T>(newVal);
        return;
    }
    auto currNode = make_shared<DoubleLinkedNodeTemplates<T>>(*head);
    while(currNode->next != NULL){
        currNode = currNode->next;
    }
    currNode->next = make_shared<DoubleLinkedNodeTemplates<T>>(DoubleLinkedNodeTemplates<T>(newVal));
    currNode->next->prev = currNode;
}

template <class T>
void DoubleLinkedListTemplates<T>::RemoveNode(T val){
    if(head->value == val){
        head = head->next.get();
        if(head->next != nullptr) head->next->prev = nullptr;
        return;
    }
    shared_ptr<DoubleLinkedNodeTemplates<T>> prevNode = nullptr;
    auto currNode = make_shared<DoubleLinkedNodeTemplates<T>>(*head);
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
        head = head->next.get();
        if(head->next != nullptr) head->next->prev = nullptr;
        return;
    }
    shared_ptr<DoubleLinkedNodeTemplates<T>> prevNode = nullptr;
    shared_ptr<DoubleLinkedNodeTemplates<T>> currNode = make_shared<DoubleLinkedNodeTemplates<T>>(*head);
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

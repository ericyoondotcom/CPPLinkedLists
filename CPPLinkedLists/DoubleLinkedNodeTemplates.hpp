#ifndef DoubleLinkedNodeTemplates_hpp
#define DoubleLinkedNodeTemplates_hpp

#include <stdio.h>

#include <memory>

template <class T>
class DoubleLinkedNodeTemplates
{
public:
    DoubleLinkedNodeTemplates(T val);
    T value;
    std::shared_ptr<DoubleLinkedNodeTemplates<T>> next;
    std::shared_ptr<DoubleLinkedNodeTemplates<T>> prev;
private:
    
};

template <class T>
DoubleLinkedNodeTemplates<T>::DoubleLinkedNodeTemplates(T val){
    value = val;
    next = NULL;
    prev = NULL;
}

#endif /* DoubleLinkedNodeTemplates_hpp */

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
};

template <class T>
DoubleLinkedNodeTemplates<T>::DoubleLinkedNodeTemplates(T val){
    value = val;
    next = nullptr;
    prev = nullptr;
}

#endif /* DoubleLinkedNodeTemplates_hpp */

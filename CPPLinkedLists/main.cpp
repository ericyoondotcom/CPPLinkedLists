#include <iostream>
#include <string>
#include "DoubleLinkedList.hpp"
#include "DoubleLinkedNode.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    DoubleLinkedList l;
    while(true){
        string input;
        cout << "What do you want to do?\r(add / delete) > ";
        cin >> input;
        if(input == "add"){
            int newVal;
            cout << "What value do you want to insert?\r<int> > ";
            cin >> newVal;
            cout << "Should I add at head or tail?\r(head / tail) > ";
            cin >> input;
            if(input == "head"){
                l.AddHead(newVal);
            }else if(input == "tail"){
                l.AddTail(newVal);
            }else{
                cout << "I'm afraid I don't know what you mean...";
            }
        }else if(input == "delete"){
            cout << "Do you want to delete by value or index?\r(value / index) > ";
            cin >> input;
            if(input == "value"){
                int nodeToRem;
                cout << "What value should I remove??\r<int> > ";
                cin >> nodeToRem;
                l.RemoveNode(nodeToRem);
            }else if(input == "index"){
                int nodeToRem;
                cout << "What index should I remove??\r<int> > ";
                cin >> nodeToRem;
                l.RemoveAt(nodeToRem);
            }else{
                cout << "I'm afraid I don't know what you mean...";
            }
        }else{
            cout << "I don't know what you mean.";
        }
        
        cout << "Your new list: ";
        DoubleLinkedNode* curr = l.head;
        while(curr != NULL){
            cout << curr->value << ",";
            curr = curr->next;
        }
        while(curr != NULL){
            cout << curr->value << ",";
            curr = curr->prev;
        }
        cout << "\r~~~~~~~~~~~~~~~\r";
    }
}

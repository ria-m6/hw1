/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

void printList(Node* list){
    while(list != nullptr){
        std::cout << list-> value << " ";
        list = list->next;
    }
    std::cout<<std::endl;
}


int main(int argc, char* argv[])
{
    
    Node* list = new Node(1, new Node(2, new Node(3, nullptr)));
    Node* odds = nullptr;
    Node* evens = nullptr;

    split(list, odds, evens);
    
    std::cout<<"Odds: ";
    printList(odds);
    
    std::cout<<"Evens: ";
    printList(evens);
    
    Node* temp;
    while(odds != nullptr){
        temp = odds;
        odds = odds->next;
        delete temp;
    }
    while(evens != nullptr){
        temp = evens;
        evens = evens->next;
        delete temp;
    }
    return 0;

}



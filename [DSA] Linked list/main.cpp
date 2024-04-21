#include"Linked list.h"
#include<iostream>
using namespace std;



int main() {
    CNode<int> a(4);

    CLinkedList<int> llList;
    CNode<int>* ndHead = llList.GetHead();
    llList.InsertNode(ndHead, 1);
    llList.InsertNode(2, 2);
    llList.PrintList();

    return 0;
}
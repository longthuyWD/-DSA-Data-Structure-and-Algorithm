#include"Linked list.h"
#include<iostream>
using namespace std;



int main() {
    CNode<int> a(4);

    LinkedList<int> llList;
    CNode<int>* ndHead = llList.GetHead();
    llList.InsertNode(ndHead, 1);
    llList.PrintList();


    return 0;
}
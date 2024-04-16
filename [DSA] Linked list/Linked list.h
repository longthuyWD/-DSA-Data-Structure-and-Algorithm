#pragma once


class Node {
    int m_nData;
    Node* m_ndNext;
public:
    // Default constructor 
    Node();

    // Copy contructor
    Node(int nData, Node* ndNext);

    // Parameterised Constructor 
    Node(int nData);

    int GetData();
    Node* GetNext();
    void SetData(Node* node);
    void SetNext(Node* node);
};

class LinkedList
{
    Node* m_ndHead;
public:
    LinkedList();
    ~LinkedList();

    void InsertNode(Node*,Node*,int);
    void DeleteNode(int);

};


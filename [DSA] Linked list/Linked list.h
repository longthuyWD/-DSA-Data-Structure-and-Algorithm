#pragma once
#include<iostream>

// Class Node represent by a data point and a pointe refer to next node
template<class T = int>
class CNode {
    T m_nData;
    CNode* m_ndNext;
public:
    // Default constructor 
    CNode();

    // Copy contructor
    CNode(T nData, CNode* ndNext);

    // Parameterised Constructor 
    CNode(T nData);

    T GetData();
    CNode* GetNext();
    void SetData(CNode* node);
    void SetNext(CNode* node);
};

template<class T>
inline CNode<T>::CNode()
{
	this->m_nData = 0;
	this->m_ndNext = nullptr;
}

template<class T>
inline CNode<T>::CNode(T nData)
{
	this->m_nData = nData;
	this->m_ndNext = nullptr;
}


template<class T>
T CNode<T>::GetData()
{
	return this->m_nData;
}

template<class T>
inline CNode<T>* CNode<T>::GetNext()
{
	if(this->m_ndNext != nullptr)
		return this->m_ndNext;
	return nullptr;
}

template<class T>
inline void CNode<T>::SetData(CNode<T>* node)
{
	this->m_nData = node->GetData();
}

template<class T>
inline void CNode<T>::SetNext(CNode<T>* node)
{
	if (node == nullptr)
		this->m_ndNext = nullptr;
	else
		this->m_ndNext = node;
}

// Class Linked list represent for a chain of node
template<class T>
class LinkedList
{
    CNode<T>* m_ndHead;
public:
    LinkedList();
    ~LinkedList();


    CNode<T>* GetHead();
    void InsertNode(CNode<T>*,T);
    void DeleteNode(int);
    void PrintList();
};

template<class T>
inline LinkedList<T>::LinkedList()
{
	this->m_ndHead = nullptr; 
}

template<class T>
LinkedList<T>::~LinkedList()
{
}

template<class T>
inline CNode<T>* LinkedList<T>::GetHead()
{
	return m_ndHead;
}

template<class T>
inline void LinkedList<T>::InsertNode(CNode<T>* ndCur, T nData)
{
	CNode<T>* ndNewNode = new CNode<T>(nData);
	if (this->m_ndHead == nullptr)
	{
		this->m_ndHead = ndNewNode;
		this->m_ndHead->SetNext(nullptr);
	}
	else
	{
		ndNewNode->SetNext(ndCur->GetNext());
		ndCur->SetNext(ndNewNode);
	}
}

template<class T>
inline void LinkedList<T>::DeleteNode(int nIdx)
{
	CNode* ndTemp = m_ndHead;
	int nLength = 0;

	// Count length of linked list
	while (ndTemp != nullptr)
	{
		nLength++;
		ndTemp = ndTemp->GetNext();
	}

	CNode* ndTemp1 = m_ndHead;
	CNode* ndTemp2 = nullptr;
	// Check index of node deleted with length of linked list
	if (nIdx > nLength)
	{
		std::cout << "Out of length" << std::endl;
		return;
	}

	if (nIdx == 1)
	{
		m_ndHead->SetNext(m_ndHead->GetNext());
		delete ndTemp1;
		return;
	}

	while (nIdx-- > 1)
	{
		ndTemp2 = ndTemp1;
		ndTemp1 = ndTemp1->GetNext();
	}
	ndTemp2->SetNext(ndTemp1->GetNext());
	delete ndTemp1;
}

template<class T>
inline void LinkedList<T>::PrintList()
{
	CNode<T>* ndTemp = m_ndHead;
	// Traverse linked list and print data
	while (ndTemp != nullptr)
	{
		T data = ndTemp->GetData();
		std::cout << data << " ";
		ndTemp = ndTemp->GetNext();
	}
	return;
}

template<class T = int>
class CNodeDou: public CNode<T>
{
public:
	CNodeDou();
	~CNodeDou();

private:
	CNode<T>* m_ndPre;
};

template<class T>
inline CNodeDou<T>::CNodeDou()
{
}

template<class T>
inline CNodeDou<T>::~CNodeDou()
{
}

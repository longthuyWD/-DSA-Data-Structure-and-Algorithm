#pragma once
#include<iostream>

// Class Node represent by a data point and a pointe refer to next node
template<class T = int>
class CNode {
    T m_nData;
    CNode* m_pNext;
public:
    // Default constructor 
    CNode();

    // Copy contructor
    CNode(T nData, CNode* pNext);

    // Parameterised Constructor 
    CNode(T nData);

    T GetData();
    CNode* GetNext();
    void SetData(CNode* pNode);
    void SetNext(CNode* pNode);
};

template<class T>
inline CNode<T>::CNode()
{
	this->m_nData = 0;
	this->m_pNext = nullptr;
}

template<class T>
inline CNode<T>::CNode(T nData)
{
	this->m_nData = nData;
	this->m_pNext = nullptr;
}


template<class T>
T CNode<T>::GetData()
{
	return this->m_nData;
}

template<class T>
inline CNode<T>* CNode<T>::GetNext()
{
	if(this->m_pNext != nullptr)
		return this->m_pNext;
	return nullptr;
}

template<class T>
inline void CNode<T>::SetData(CNode<T>* pNode)
{
	this->m_nData = pNode->GetData();
}

template<class T>
inline void CNode<T>::SetNext(CNode<T>* pNode)
{
	if (pNode == nullptr)
		this->m_pNext = nullptr;
	else
		this->m_pNext = pNode;
}

// Class Linked list represent for a chain of node
template<class T = int>
class CLinkedList
{
    CNode<T>* m_pHead;
public:
	CLinkedList();
    ~CLinkedList();


    CNode<T>* GetHead();
	// Insert node after current node
    void InsertNode(CNode<T>*,T);
	// Insert new node at given position with a given data
	void InsertNode(int, T);
	// Insert node at given position with a given node
	void InsertNode(int, CNode<T>*);
	// Delete node after current node
	void DeleteNode(CNode<T>*, T);
	// Delete node at given position
    void DeleteNode(int);
    void PrintList();
};

template<class T>
inline CLinkedList<T>::CLinkedList()
{
	this->m_pHead = nullptr; 
}

template<class T>
CLinkedList<T>::~CLinkedList()
{
}

template<class T>
inline CNode<T>* CLinkedList<T>::GetHead()
{
	return m_pHead;
}

template<class T>
inline void CLinkedList<T>::InsertNode(CNode<T>* pCurNode, T nData)
{
	CNode<T>* pNewNode = new CNode<T>(nData);
	if (this->m_pHead == nullptr)
	{
		this->m_pHead = pNewNode;
		this->m_pHead->SetNext(nullptr);
	}
	else
	{
		pNewNode->SetNext(pCurNode->GetNext());
		pCurNode->SetNext(pNewNode);
	}
}

template<class T>
inline void CLinkedList<T>::InsertNode(int nIdx, T nData)
{
	CNode<T>* pTemp = m_pHead;
	int nLength = 0;

	// Count length of linked list
	while (pTemp != nullptr)
	{
		nLength++;
		pTemp = pTemp->GetNext();
	}

	// Check index of node inserted with length of linked list
	if (nIdx > nLength+1)
	{
		std::cout << "Out of length" << std::endl;
		return;
	}

	CNode<T>* pTemp1 = m_pHead;
	CNode<> ndTemp2(nData);

	if (nIdx == 1)
	{
		m_pHead = &ndTemp2;
		m_pHead->SetNext(pTemp1);
		return;
	}

	// Differce with delete node
	// Traverse (nIdx - 2) times
	while (--nIdx > 1)
	{
		pTemp1 = pTemp1->GetNext();
	}
	pTemp1->SetNext(&ndTemp2);
}

template<class T>
inline void CLinkedList<T>::InsertNode(int nIdx, CNode<T>* pNode)
{
	CNode<T>* pTemp = m_pHead;
	int nLength = 0;

	// Count length of linked list
	while (pTemp != nullptr)
	{
		nLength++;
		pTemp = pTemp->GetNext();
	}

	// Check index of node inserted with length of linked list
	if (nIdx > nLength + 1)
	{
		std::cout << "Out of length" << std::endl;
		return;
	}

	CNode<T>* pTemp1 = m_pHead;

	if (nIdx == 1)
	{
		m_pHead = pNode;
		m_pHead->SetNext(pTemp1);
		return;
	}

	// Differce with delete node
	// Traverse (nIdx - 2) times
	while (--nIdx > 1)
	{
		pTemp1 = pTemp1->GetNext();
	}
	pTemp1->SetNext(pNode);
}

template<class T>
inline void CLinkedList<T>::DeleteNode(int nIdx)
{
	CNode<T>* pTemp = m_pHead;
	int nLength = 0;

	// Count length of linked list
	while (pTemp != nullptr)
	{
		nLength++;
		pTemp = pTemp->GetNext();
	}

	// Check index of node deleted with length of linked list
	if (nIdx > nLength)
	{
		std::cout << "Out of length" << std::endl;
		return;
	}

	CNode<T>* pTemp1 = m_pHead;
	CNode<T>* pTemp2 = nullptr;

	if (nIdx == 1)
	{
		m_pHead->SetNext(m_pHead->GetNext());
		delete pTemp1;
		return;
	}

	// Differce with insert node
	// Traverse (nIdx - 1) times
	while (nIdx-- > 1)
	{
		pTemp2 = pTemp1;
		pTemp1 = pTemp1->GetNext();
	}
	pTemp2->SetNext(pTemp1->GetNext());
	delete pTemp1;
}

template<class T>
inline void CLinkedList<T>::PrintList()
{
	CNode<T>* pTemp = m_pHead;
	int nLength = 0;
	// Count length of linked list
	while (pTemp != nullptr)
	{
		nLength++;
		pTemp = pTemp->GetNext();
	}
	std::cout << "Length of list: " << nLength << std::endl;

	pTemp = m_pHead;
	// Traverse linked list and print data
	while (pTemp != nullptr)
	{
		T data = pTemp->GetData();
		std::cout << data << " ";
		pTemp = pTemp->GetNext();
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
	CNode<T>* m_pPre;
};

template<class T>
inline CNodeDou<T>::CNodeDou()
{
}

template<class T>
inline CNodeDou<T>::~CNodeDou()
{
}

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
	// Parameterised Constructor 
    CNode(T nData, CNode* pNext);
    // Parameterised Constructor 
    CNode(T nData);
	// Copy contructor
	CNode(const CNode&) = delete;
	CNode& operator =(CNode&) = delete;
	~CNode() = default;

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
inline CNode<T>::CNode(T nData, CNode* pNext)
{
	this->m_nData = nData;
	this->m_pNext = pNext;
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

// Class interface Common Linked list represent for a chain of node
template<class T = int, class H = CNode<T>>
class CComLinkedList
{
protected:
	H* m_pHead;
public:
	CComLinkedList() = default;
	~CComLinkedList() = default;
	// Prevent the compliler automatically genarate copy constructor and assignment operator 
	// to avoid shallow copy
	CComLinkedList(const CComLinkedList&) = delete;
	void operator =(const CComLinkedList&) = delete;


	virtual H* GetHead() = 0;
	// Insert node after current node
	virtual void InsertNode(H*, T) = 0;
	// Insert new node at given position with a given data
	virtual void InsertNode(int, T) = 0;
	// Insert node at given position with a given node
	virtual void InsertNode(int, H*) = 0;
	// Delete node after current node
	virtual void DeleteNode(H*, T) = 0;
	// Delete node at given position
	virtual void DeleteNode(int) = 0;
	virtual void PrintList() = 0;
};

// Class Linked list represent for a chain of node
template<class T = int>
class CLinkedList: public CComLinkedList<T, CNode<T>>
{
public:
	CLinkedList();
    ~CLinkedList() = default;
	// Prevent the compliler automatically genarate copy constructor and assignment operator 
	// to avoid shallow copy
	CLinkedList(const CLinkedList&) = delete;
	void operator =(const CLinkedList&) = delete;


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
inline CNode<T>* CLinkedList<T>::GetHead()
{
	return this->m_pHead;
}

template<class T>
inline void CLinkedList<T>::InsertNode(CNode<T>* pCurNode, T nData)
{
	// Check if the given pCurNode is NULL
	if (pCurNode == nullptr) {
		std::cout << "The given Current node cannot be NULL";
		return;
	}

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
	CNode<T>* pTemp = this->m_pHead;
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

	CNode<T>* pTemp1 = this->m_pHead;
	CNode<> ndTemp2(nData);

	if (nIdx == 1)
	{
		this->m_pHead = &ndTemp2;
		this->m_pHead->SetNext(pTemp1);
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
	CNode<T>* pTemp = this->m_pHead;
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

	CNode<T>* pTemp1 = this->m_pHead;

	if (nIdx == 1)
	{
		this->m_pHead = pNode;
		this->m_pHead->SetNext(pTemp1);
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
inline void CLinkedList<T>::DeleteNode(CNode<T>*, T)
{
}

template<class T>
inline void CLinkedList<T>::DeleteNode(int nIdx)
{
	CNode<T>* pTemp = this->m_pHead;
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

	CNode<T>* pTemp1 = this->m_pHead;
	CNode<T>* pTemp2 = nullptr;

	if (nIdx == 1)
	{
		this->m_pHead->SetNext(this->m_pHead->GetNext());
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
	CNode<T>* pTemp = this->m_pHead;
	int nLength = 0;
	// Count length of linked list
	while (pTemp != nullptr)
	{
		nLength++;
		pTemp = pTemp->GetNext();
	}
	std::cout << "Length of list: " << nLength << std::endl;

	// Traverse linked list and print data
	CNode<T>* pTemp1 = this->m_pHead;
	while (pTemp1 != nullptr)
	{
		std::cout << pTemp1->GetData() << " ";
		pTemp1 = pTemp1->GetNext();
	}
	return;
}

template<class T = int>
class CNodeDou: public CNode<T>
{
private:
	CNode<T>* m_pPre;
public:
	CNodeDou();
	CNodeDou(T nData, CNode<T>* pNext, CNode<T>* pPre);
	~CNodeDou() = default;

	void SetPrev(CNode<T>* pNode);
};

template<class T>
inline CNodeDou<T>::CNodeDou():CNode(0,nullptr)
{
	this->m_pPre = nullptr;
}

template<class T>
inline CNodeDou<T>::CNodeDou(T nData, CNode<T>* pNext, CNode<T>* pPre):CNode(nData, pNext)
{
	this->m_pPre = pPre;
}

template<class T>
inline void CNodeDou<T>::SetPrev(CNode<T>* pNode)
{
	this->m_pPre = pNode;
}

// Class Linked list represent for a chain of node
template<class T>
class CDouLinkedList:public CComLinkedList<T, CNodeDou<T>>
{
public:
	CDouLinkedList();
	~CDouLinkedList() = default;
	// Prevent the compliler automatically genarate copy constructor and assignment operator 
	// to avoid shallow copy
	CDouLinkedList(const CDouLinkedList&) = delete;
	void operator =(const CDouLinkedList&) = delete;

	CNodeDou<T>* GetHead();
	// Insert node after current node
	void InsertNode(CNodeDou<T>*, T);
	// Insert new node at given position with a given data
	void InsertNode(int, T);
	// Insert node at given position with a given node
	void InsertNode(int, CNodeDou<T>*);
	// Delete node after current node
	void DeleteNode(CNodeDou<T>*, T);
	// Delete node at given position
	void DeleteNode(int);
	void PrintList();
};

template<class T>
inline CDouLinkedList<T>::CDouLinkedList()
{
	this->m_pHead = nullptr;
}

template<class T>
inline CNodeDou<T>* CDouLinkedList<T>::GetHead()
{
	return this->m_pHead;
}

template<class T>
inline void CDouLinkedList<T>::InsertNode(CNodeDou<T>* pCurNode, T nData)
{
	// Check if the given pCurNode is NULL
	if (pCurNode == nullptr) {
		std::cout << "The given Current node cannot be NULL";
		return;
	}

	CNodeDou<T>* pNewNode = new CNodeDou<T>(nData);
	if (this->m_pHead == nullptr)
	{
		this->m_pHead = pNewNode;
		this->m_pHead->SetNext(nullptr);
		this->m_pHead->SetPrev(nullptr);
	}
	else
	{
		// Set link between the next of current node and new node
		pCurNode->GetNext()->SetPrev(pNewNode);
		pNewNode->SetNext(pCurNode->GetNext());
		// Set link between current node and new node
		pCurNode->SetNext(pNewNode);
		pNewNode->SetPrev(pCurNode);
	}
}

template<class T>
inline void CDouLinkedList<T>::PrintList()
{
	CNodeDou<T>* pTemp = this->m_pHead;
	int nLength = 0;
	// Count length of linked list
	while (pTemp != nullptr)
	{
		nLength++;
		pTemp = pTemp->GetNext();
	}
	std::cout << "Length of list: " << nLength << std::endl;

	// Traverse linked list and print data
	CNodeDou<T>* pTemp1 = this->m_pHead;
	while (pTemp1 != nullptr)
	{
		std::cout << pTemp1->GetData() << " ";
		pTemp1 = pTemp1->GetNext();
	}
	return;
}

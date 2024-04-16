#include "Linked list.h"
#include <iostream>

Node::Node()
{
	this->m_nData = 0;
	this->m_ndNext = nullptr;
}

Node::Node(int nData)
{
	this->m_nData = nData;
	this->m_ndNext = nullptr;
}

int Node::GetData()
{
	return this->m_nData;
}

Node* Node::GetNext()
{
	return this->m_ndNext;
}

void Node::SetData(Node* node)
{
	this->m_nData = node->GetData();
}

void Node::SetNext(Node* node)
{
	this->m_ndNext = node->GetNext();
}

LinkedList::LinkedList()
{
	this->m_ndHead = nullptr; 
}

LinkedList::~LinkedList()
{
}

void LinkedList::InsertNode(Node* ndHead, Node* ndCur, int nData)
{
	Node* ndNewNode = new Node(nData);
	if (this->m_ndHead == nullptr)
	{
		this->m_ndHead = ndNewNode;
		this->m_ndHead->SetNext(ndNewNode->GetNext());
	}
	else
	{
		ndNewNode->SetNext(ndCur->GetNext());
		ndCur->SetNext(ndNewNode);
	}
}

void LinkedList::DeleteNode(int nIdx)
{
	Node* ndTemp = m_ndHead;
	int nLength = 0;

	while (ndTemp != nullptr)
	{
		nLength++;
		ndTemp = ndTemp->GetNext();
	}
	Node* ndTemp1 = m_ndHead;
	Node* ndTemp2 = nullptr;

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

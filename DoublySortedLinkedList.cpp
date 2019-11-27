#include "DoublySortedLinkedList.h"

template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_pFirst = NULL;
	m_pLast = NULL;
	m_nLength = 0;
}

template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	MakeEmpty();
}

template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty() 
{
	return m_nLength == 0;
}

template <typename T>
bool DoublySortedLinkedList<T>::IsFull()
{

}

template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyIterator<T> iter(*this);
	while (iter.NextNotNull())
	{
		iter.Next();
		delete iter.GetCurrentNode()->prev;
	}
	delete iter->m_pCurPointer;
	DoublySortedLinkedList();
}

template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

template <typename T>
int DoublySortedLinkedList<T>::Add(T item)
{
	DoublyNodeType<T>* temp = new DoublyNodeType<T>;
	DoublyIterator<T> iter(*this);
	while (iter.NextNotNull())
	{
		if (item == iter.GetCurrentNode().data)
		{
			return 0;
		}
		if (item < iter.GetCurrentNode().data)
		{
			temp->data = item;
			temp->prev = iter.m_pCurPointer->prev;
			temp->next = iter.m_pCurPointer;
			temp->prev->next = temp;
			temp->next->prev = temp;
			return 1;
		}
		iter.Next();
	}
}

template <typename T>
int DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> iter(*this);
	while (iter.NextNotNull())
	{
		if (item == iter.Next())
		{
			iter.m_pCurPointer->prev->next = iter.m_pCurPointer->next;
			iter.m_pCurPointer->next->prev = iter.m_pCurPointer->prev;
			delete iter.m_pCurPointer
			return 1;
		}
	}
	return 0;
}

template <typename T>
void DoublySortedLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> iter(*this);
	while (iter.NextNotNull())
	{
		if (item == iter.Next())
		{
			iter.m_pCurPointer->data.SetRecordFromKB();
		}
	}
}

template <typename T>
int DoublySortedLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> iter(*this);
	while (iter.NextNotNull())
	{
		if (item == iter.Next())
		{
			item = iter.m_pCurPointer->data;
			return 1;
		}
	}
	return 0;
}
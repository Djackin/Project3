#include "DoublyIterator.h"

template <typename T>
bool DoublyIterator<T>::NotNull()
{
	return m_pCurPointer != NULL;
}

template <typename T>
bool DoublyIterator<T>::NextNotNull()
{
	return m_pCurPointer->next != NULL;
}

template <typename T>
T DoublyIterator<T>::First()
{
	return m_List.m_pFirst->data;
}

template <typename T>
T DoublyIterator<T>::Next()
{
	if (NextNotNull())
	{
		m_pCurPointer = m_pCurPointer->next;
		return m_pCurPointer->data;
	}
}

template <typename T>
DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode()
{
	return *m_pCurPointer;
}
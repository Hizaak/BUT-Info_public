#include "ListIntsL.h"

ListIntsL::ListIntsL() :
    m_listInts ()
{
}

ListIntsL::ListIntsL(const ListIntsL& listIntsL) :
    m_listInts (listIntsL.m_listInts)
    {
    }

ListIntsL::~ListIntsL()
{
}

void ListIntsL::insertBeg(int value)
{
    m_listInts.push_front(value);
}

int ListIntsL::getSize()
{
    return m_listInts.size();
}

void ListIntsL::removeAt(int index)
{
    if (index >= 0 && index < m_listInts.size())
    {
        std::list<int>::iterator it = m_listInts.begin();
        for (int i = 0; i < index; i++)
        {
            it++;
        }
        m_listInts.erase(it);
    }
}
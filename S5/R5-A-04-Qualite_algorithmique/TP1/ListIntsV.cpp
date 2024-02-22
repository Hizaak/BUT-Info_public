#include "ListIntsV.h"

ListIntsV::ListIntsV() :
    m_listInts ()
{
}

ListIntsV::ListIntsV(const ListIntsV& listIntsV) :
    m_listInts (listIntsV.m_listInts)
    {
    }

ListIntsV::~ListIntsV()
{
}

void ListIntsV::insertBeg(int value)
{
    m_listInts.insert(m_listInts.begin(), value);
}

int ListIntsV::getSize()
{
    return m_listInts.size();
}

void ListIntsV::removeAt(int index)
{
    if (index >= 0 && index < m_listInts.size())
    {
        m_listInts.erase(m_listInts.begin() + index);
    }
}

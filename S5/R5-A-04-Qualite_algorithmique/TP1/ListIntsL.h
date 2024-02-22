#ifndef ListIntsL_H
#define ListIntsL_H

#include <list>

class ListIntsL
{
    protected:
        std::list<int> m_listInts;
    public:

        // Constructors // Complexity
        ListIntsL(); // O(1)
        ListIntsL(const ListIntsL& listIntsL); // O(n)

        // Destructor
        ~ListIntsL(); // O(1)

        // Methods
        void insertBeg(int value); // O(1)
        int getSize(); // O(1)
        void removeAt(int index); // O(n)
};




#endif // ListIntsL_H
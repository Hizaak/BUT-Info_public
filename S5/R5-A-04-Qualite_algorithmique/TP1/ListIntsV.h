#ifndef LISTINTSV_H
#define LISTINTSV_H

#include <vector>

class ListIntsV
{
    protected:
        std::vector<int> m_listInts;
    public:

        // Constructors // Complexity
        ListIntsV(); // O(1)
        ListIntsV(const ListIntsV& listIntsV); // O(n)

        // Destructor
        ~ListIntsV(); // O(1)

        // Methods
        void insertBeg(int value); // O(n)
        int getSize(); // O(1)
        void removeAt(int index); // O(n)
};

#endif // LISTINTSV_H
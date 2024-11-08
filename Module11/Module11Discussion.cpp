#include <iostream>
#include <string>

using namespace std;

template <Type>
class MyList {
    private:

    struct ListNode {
        Type value;
        ListNode* pNext;
    };

    ListNode* pFirstNode;
    ListNode* pLastNode;
    ListNode* pCurrentNode;
    int currentIndex;
    int size;

    public:

    // Constructor
    MyList() {
        pFirstNode = nullptr;
        pLastNode = nullptr;
        pCurrentNode = nullptr;
        currentIndex = -1;
        size = 0;
    }

    // Gets the number of elements in the list
    int getSize() {
        return size;
    }

    // Add a new value to the end of the list
    void add(Type* pObj) {
        ListNode* pNode = new ListNode;
        pNode->value = *pObj;
        pNode->pNext = nullptr;

        if (size == 0) {
            pFirstNode = pNode;
            pLastNode = pNode;
        }
        else {
            pLastNode->pNext = pNode;
            pLastNode = pNode;
        }

        size++;
    }

    // Add a new value to the end of the list
    void add(Type obj) {
        add(&obj);
    }

    // Insert a value at the given index
    void insert(int index, Type obj) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of bounds.");
        }

        ListNode* pNode = new ListNode;
        pNode->value = obj;

        if (index == 0) {
            pNode->pNext = pFirstNode;
            pFirstNode = pNode;
        }
        else {
            ListNode* p = pFirstNode;

            for (int i = 0; i < index - 1; i++) {
                p = p->pNext;
            }

            pNode->pNext = p->pNext;
            p->pNext = pNode;
        }

        size++;
    }

    // Gets a value at the given index
    Type get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds.");
        }

        ListNode* pNode = pFirstNode;

        for (int i = 0; i < index; i++) {
            pNode = pNode->pNext;
        }

        return pNode->value;
    }

    // Checks if there is another value past the current iterator cursor
    bool hasNext() {
        if (size == 0 || (pCurrentNode != nullptr && pCurrentNode->pNext == nullptr)) {
            return false;
        }

        return true;
    }

    // Advances the iterator cursor and returns that value
    Type getNext() {
        if (pCurrentNode == nullptr && size > 0) {
            pCurrentNode = pFirstNode;
        }
        else {
            pCurrentNode = pCurrentNode->pNext;
        }

        return pCurrentNode.value;
    }

    // Resets the iterator cursor back to the beginning of the list
    void reset() {
        pCurrentNode = nullptr;
    }
};

// Prints the given list items separated by commas
template <class Type>
void printDelimitedList(MyList<Type> list) {
    for (int i = 0; i < list.getSize(); i++) {
        cout << list.get(i);
        if (i < list.getSize() - 1) {
            cout << ", ";
        }
    }
    cout << endl << endl;
}

// Prints the given list of items in a virtical list
template <class Type>
void printVirticalList(MyList<Type> list) {
    list.reset();
    while(list.hasNext()) {
        cout << list.getNext() << endl;
    }
    cout << endl << endl;
}

// Main function
int main() {
    auto names = MyList();
    names.add("Michael");
    names.add("Anthony");
    names.add("Isabella");
    cout << "Original list" << endl;
    printDelimitedList<string>(names);

    names.insert(1, "Megan");
    cout << "Inserted name" << endl;
    printDelimitedList(names);

    cout << "Virtical list" << endl;
    printVirticalList<string>(names);

    return 0;
}
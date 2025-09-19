#include <iostream>

using namespace std;

template <class T> class LinkedList;

template <class T>
class Node
{
private:
    T data;
    Node<T> *next;

    friend class LinkedList<T>;

public:
    Node(T value) : data(value), next(nullptr) {}
    T getData();
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;
public:
    LinkedList();

    LinkedList(initializer_list<T> values);

    ~LinkedList();

    void prepend(T value);
    void append(T value);
    void display() const;

    int countNodes();

    void insertBeforeValue(T target, T value);
    void insertAfterValue(T target, T value);
    void insertAtIndex(int index, T value);

    void deleteFirst();
    void deleteLast();
    void deleteBefore(T target);
    void deleteAfter(T target);
    void deleteIndex(int index);
    void deleteValue(T value);
    void deleteAllValue(T value);

    T sum();
    T max();
    T min();

    Node<T>* search(T key);
    bool isSorted();
    void reverse();

    void createLoop(T fromValue, T toValue);
    bool isLoop();

    void BubbleSort();
    
    Node<T> *getMiddle(Node<T> *start, Node<T> *end);
    bool BinarySearch(int value);
};

template <class T>
T Node<T>::getData()
{
    return data;
}

template <class T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <class T>
LinkedList<T>::LinkedList(initializer_list<T> values) : head(nullptr)
{
    for (const T& val : values) {
        append(val);
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::prepend(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

template <class T>
void LinkedList<T>::append(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template <class T>
void LinkedList<T>::display() const
{
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node<T>* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <class T>
int LinkedList<T>::countNodes()
{
    if (head == nullptr) return 0;

    if (head->next == nullptr) return 1;

    Node<T>* current = head;
    int count = 0;

    while (current != nullptr) {
        current = current->next;
        count++;
    }

    return count;
}

template <class T>
void LinkedList<T>::insertBeforeValue(T target, T value)
{
    if (head == nullptr)
        return;

    if (head->data == target) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;

        return;
    }

    Node<T>* current = head;

    while (current->next != nullptr && current->next->data != target) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        current->next = newNode;
    }
}

template <class T>
void LinkedList<T>::insertAfterValue(T target, T value)
{
    if (head == nullptr)
        return;

    Node<T>* current = head;

    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    if (current != nullptr) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        current->next = newNode;
    }
}

template <class T>
void LinkedList<T>::insertAtIndex(int index, T value)   // 1 based
{
    if (index <= 0 || index > countNodes() + 1)
        return;

    if (index == 1) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        return;
    }

    Node<T>* current = head;

    for (int i = 1; i < index - 1; i++) {
        if (current == nullptr) return;

        current = current->next;
    }

    if (current != nullptr) {
        Node<T>* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
    }
}

template <class T>
void LinkedList<T>::deleteFirst()
{
    if (head == nullptr) return;

    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template <class T>
void LinkedList<T>::deleteLast()
{
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* current = head;

    while (current->next != nullptr && current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

template <class T>
void LinkedList<T>::deleteBefore(T target)
{
    if (head == nullptr || head->next == nullptr || head->data == target) return;

    if (head->next->data == target) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node<T>* current = head;

    while (current->next != nullptr && current->next->next != nullptr && current->next->next->data != target) {
        current = current->next;
    }

    if (current->next != nullptr && current->next->next != nullptr) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::deleteAfter(T target)
{
    if (head == nullptr || head->next == nullptr) return;

    Node<T>* current = head;

    while (current != nullptr && current->next != nullptr && current->data != target) {
        current = current->next;
    }

    if (current != nullptr && current->next != nullptr) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::deleteIndex(int index)
{
    if (index <= 0 || index > countNodes()) return;

    if (index == 1) {
        deleteFirst();
        return;
    }

    Node<T>* current = head;

    for (int i = 1; i < index - 1; i++) {
        current = current->next;
    }

    if (current != nullptr && current->next != nullptr) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::deleteValue(T value)
{
    if (head == nullptr) return;

    if (head->data == value) {
        deleteFirst();
        return;
    }

    Node<T>* current = head;

    while (current != nullptr && current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current != nullptr && current->next != nullptr) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::deleteAllValue(T value)
{
    if (head == nullptr) return;

    if (head->data == value) {
        deleteFirst();
        return;
    }

    Node<T>* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == value) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

template <class T>
T LinkedList<T>::sum()
{
    if (head == nullptr) return T{};

    T sum{}; 

    Node<T>* current = head;

    while (current != nullptr) {
        sum += current->data;
        current = current->next;
    }

    return sum;
}

template <class T>
T LinkedList<T>:: max()
{
    if (head == nullptr) return T{};

    T maximum = head->data;

    Node<T>* current = head;

    while (current != nullptr) {
        if (current->data > maximum) {
            maximum = current->data;
        }
        current = current->next;
    }

    return maximum;
}

template <class T>
T LinkedList<T>:: min()
{
    if (head == nullptr) return T{};

    T minimum = head->data;

    Node<T>* current = head;

    while (current != nullptr) {
        if (current->data < minimum) {
            minimum = current->data;
        }
        current = current->next;
    }

    return minimum;
}

template <class T>
Node<T>* LinkedList<T>::search(T key)
{
    Node<T>* current = head;

    while (current != nullptr) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

template <class T>
bool LinkedList<T>::isSorted()
{
    if (head == nullptr || head->next == nullptr)
        return true;

    Node<T>* current = head;

    while (current->next != nullptr) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }

    return true;
}

template <class T>
void LinkedList<T>::reverse()   // using sliding pointers
{
    Node<T>* current = head;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

template <class T>
void LinkedList<T>::createLoop(T fromValue, T toValue)
{
    Node<T>* from = search(fromValue);
    Node<T>* to = search(toValue);

    if (from != nullptr && to != nullptr) {
        from->next = to;
    }
}

// Floyd’s Cycle Detection Algorithm, aka the Tortoise and Hare algorithm
template <class T>
bool LinkedList<T>::isLoop()
{
    Node<T>* fast = head;
    Node<T>* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            return true;
        }
    }

    return false;
}

template <class T>
void LinkedList<T>::BubbleSort(){}
template <class T>
Node<T>* LinkedList<T>::getMiddle(Node<T> *start, Node<T> *end){}

template <class T>
bool LinkedList<T>::BinarySearch(int value){}

int main()
{
    LinkedList<int> list = {19, 10, 28, 1, 3};

    list.insertAtIndex(6, 99);

    list.display();
    
    return 0;
}
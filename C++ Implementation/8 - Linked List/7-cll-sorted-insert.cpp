#include <iostream>

using namespace std;

template <class T> class CircularLinkedList;

template <class T>
class Node
{
private:
    T data;
    Node<T> *next;

    friend class CircularLinkedList<T>;

public:
    Node(T value) : data(value), next(nullptr) {}
    T getData() { return data; }
};

template <class T>
class CircularLinkedList
{
private:
    Node<T> *head;
public:
    CircularLinkedList();

    CircularLinkedList(initializer_list<T> values);

    ~CircularLinkedList();

    void prepend(T value);
    void append(T value);
    void display() const;

    void sortedInsert(T value);
};

template <class T>
CircularLinkedList<T>::CircularLinkedList() : head(nullptr) {}

template <class T>
CircularLinkedList<T>::CircularLinkedList(initializer_list<T> values) : head(nullptr)
{
    for (const T& val : values) {
        append(val);
    }
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    if (!head) return;

    Node<T>* current = head->next;

    while (current != head) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }

    delete head;
    head = nullptr;
}

template <class T>
void CircularLinkedList<T>::prepend(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else {
        Node<T>* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }
}

template <class T>
void CircularLinkedList<T>::append(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else {
        Node<T>* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
}

template <class T>
void CircularLinkedList<T>::display() const
{
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node<T>* current = head;

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << endl;
}

template <class T>
void CircularLinkedList<T>::sortedInsert(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
        head->next = head;
        return;
    }

    if (value < head->data) {
        Node<T>* last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        return;
    }

    Node<T>* current = head;

    while (current->next != head && current->next->data < value) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}


int main()
{
    CircularLinkedList<int> list;

    list.display();

    list.sortedInsert(3);
    list.display();
    list.sortedInsert(1);
    list.display();
    list.sortedInsert(9);
    list.display();
    list.sortedInsert(9);
    list.sortedInsert(8);
    list.sortedInsert(2);
    list.sortedInsert(7);
    list.sortedInsert(11);
    list.display();
    
    return 0;
}
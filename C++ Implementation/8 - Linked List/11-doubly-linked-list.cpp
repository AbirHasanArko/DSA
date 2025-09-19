#include <iostream>
using namespace std;

template <class T> class DoublyLinkedList;

template <class T>
class Node
{
private:
    T data;
    Node<T>* prev;
    Node<T>* next;

    friend class DoublyLinkedList<T>;
public:
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    
    T getData() { return data; }
};

template <class T>
class DoublyLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList();
    DoublyLinkedList(initializer_list<T> values);
    ~DoublyLinkedList();

    void prepend(T value);
    void append(T value);

    void display() const;
    void reverseDisplay() const;

    int countNodes();

    void insertBeforeValue(T target, T value);
    void insertAfterValue(T target, T value);
    void insertAtIndex(int index, T value);  // 0-based

    void deleteFirst();
    void deleteLast();
    void deleteBeforeValue(T target);
    void deleteAfterValue(T target);
    void deleteAtIndex(int index);

    Node<T>* search(T key);
    void reverse();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(initializer_list<T> values) : head(nullptr), tail(nullptr)
{
    for (const T& val : values) {
        append(val);
    }
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void DoublyLinkedList<T>::prepend(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (!head) {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

template <class T>
void DoublyLinkedList<T>::append(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (!tail) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

template <class T>
void DoublyLinkedList<T>::display() const
{
    if (!head) return;

    Node<T>* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::reverseDisplay() const
{
    if (!tail) return;

    Node<T>* current = tail;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

template <class T>
int DoublyLinkedList<T>::countNodes() {
    if (!head) return 0;

    int count = 0;

    Node<T>* current = head;
    while (current) {
        count++;
        current = current->next;
    }

    return count;
}

template <class T>
void DoublyLinkedList<T>::insertBeforeValue(T target, T value)
{
    if (!head) return;

    if (head->data == target) {
        prepend(value);
        return;
    }

    Node<T>* current = head;
    while (current && current->data != target) {
        current = current->next;
    }

    if (current) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::insertAfterValue(T target, T value)
{
    if (!head) return;

    Node<T>* current = head;
    while (current && current->data != target) {
        current = current->next;
    }

    if (current) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next)
            current->next->prev = newNode; 
        else
            tail = newNode;

        current->next = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::insertAtIndex(int index, T value)  // 0-based
{
    if (index < 0 || index > countNodes()) throw runtime_error("Out of bounds");

    if (index == 0) {
        prepend(value);
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    if (current == tail) {
        append(value);
    } else if (current) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode; 
        current->next = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteFirst()
{
    if (!head) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}

template <class T>
void DoublyLinkedList<T>::deleteLast()
{
    if (!tail) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node<T>* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

template <class T>
void DoublyLinkedList<T>::deleteBeforeValue(T target)
{
    if (!head || !head->next) return;

    if (head->next->data == target) {
        deleteFirst();
        return;
    }

    Node<T>* current = head;

    while (current && current->data != target) {
        current = current->next;
    }

    if (current && current->prev && current->prev->prev) {
        Node<T>* temp = current->prev;
        current->prev->prev->next = current;
        current->prev = current->prev->prev;
        delete temp;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteAfterValue(T target)
{
    if (!head) return;

    Node<T>* current = head;

    while (current && current->data != target) {
        current = current->next;
    }

    if (current && current->next) {
        Node<T>* temp = current->next;

        if (current->next->next) {
            current->next->next->prev = current;
        } else {
            tail = current;
        }
        current->next = temp->next;

        delete temp;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteAtIndex(int index)  // 0-based
{
    if (index < 0 || index >= countNodes())
        throw runtime_error("Out of bounds");

    if (index == 0) {
        deleteFirst();
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < index && current; i++) {
        if (!current) throw runtime_error("Out of bounds");
        current = current->next;
    }

    if (current == tail) {
        deleteLast();
        return;
    }

    if (current) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

template <class T>
Node<T>* DoublyLinkedList<T>::search(T key)
{
    Node<T>* current = head;

    while (current) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template <class T>
void DoublyLinkedList<T>:: reverse()
{
    if (!head || !head->next) return;

    Node<T>* current = head;
    Node<T>* temp = nullptr;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }

    swap(head, tail);
}

int main()
{
    DoublyLinkedList<int> list = {19, 10, 28, 1, 3};

    list.reverse();

    list.display();
    list.reverseDisplay();
    

    
    return 0;
}
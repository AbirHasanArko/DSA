#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;

    Node(T value) : data(value), next(nullptr) {}
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

    void display() const;

    void sortedInsert(T value);
};

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
void LinkedList<T>::sortedInsert(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node<T>* current = head;

    while (current != nullptr && current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    }
    
}


int main()
{
    LinkedList<int> list;

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
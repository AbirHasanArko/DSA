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

    void removeDuplicates();
};

template <class T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <class T>
LinkedList<T>::LinkedList(initializer_list<T> values) : head(nullptr)
{
    for (const T& val : values) {
        Node<T>* newNode = new Node<T>(val);

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
void LinkedList<T>::removeDuplicates()
{
    Node<T>* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    
}


int main()
{
    LinkedList<int> list = {1, 1, 1, 2, 2, 3, 4, 5, 5, 8, 8, 8};
    list.display();

    list.removeDuplicates();

    list.display();
    
    return 0;
}
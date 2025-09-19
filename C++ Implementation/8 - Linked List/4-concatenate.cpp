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

    static void conc(LinkedList<T>& l1, LinkedList<T>& l2);
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
void LinkedList<T>::conc(LinkedList<T>& l1, LinkedList<T>& l2)
{
    Node<T>* current = l1.head;

    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    
    if (current != nullptr) {
        current->next = l2.head;
    }
}

int main()
{
    LinkedList<int> list1 = {1, 3, 5, 7};
    LinkedList<int> list2 = {2, 4, 6, 8};

    LinkedList<int>::conc(list1, list2);

    list1.display();

    return 0;
}



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

    static void merge(LinkedList<T>& l1, LinkedList<T>& l2);
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
void LinkedList<T>::merge(LinkedList<T>& l1, LinkedList<T>& l2)
{
    Node<T>* first = l1.head;
    Node<T>* second = l2.head;
    Node<T>* mergedHead = nullptr;
    Node<T>* mergedTail = nullptr;

    if (first == nullptr) {
        l1.head = second;
        return;
    }

    if (second == nullptr) return;

    if (first->data <= second->data) {
        mergedHead = mergedTail = first;
        first = first->next;
    } else {
        mergedHead = mergedTail = second;
        second = second->next;
    }

    while (first != nullptr && second != nullptr) {
        if (first->data <= second->data) {
            mergedTail->next = first;
            mergedTail = first;
            first = first->next;
        } else {
            mergedTail->next = second;
            mergedTail = second;
            second = second->next;
        }
    }

    if (first != nullptr) mergedTail->next = first;
    if (second != nullptr) mergedTail->next = second;

    l1.head = mergedHead;
}

int main()
{
    LinkedList<int> list1 = {2, 8, 10, 15, 17};
    LinkedList<int> list2 = {4, 7, 10, 12, 14};

    LinkedList<int>::merge(list1, list2);

    list1.display();

    return 0;
}



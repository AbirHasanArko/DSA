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
int CircularLinkedList<T>::countNodes()
{
    if (head == nullptr) return 0;

    Node<T>* current = head;
    int count = 0;

    do {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

template <class T>
void CircularLinkedList<T>::insertBeforeValue(T target, T value)
{
    if (head == nullptr)
        return;

    if (head->data == target) {
        prepend(value);
        return;
    }

    Node<T>* current = head;

    do {
        if (current->next->data == target) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    } while (current != head);
}

template <class T>
void CircularLinkedList<T>::insertAfterValue(T target, T value)
{
    if (head == nullptr)
        return;

    Node<T>* current = head;

    do {
        if (current->data == target) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    } while (current != head);
}

template <class T>
void CircularLinkedList<T>::insertAtIndex(int index, T value)   // 0 based
{
    if (index < 0 || index > countNodes())
        return;

    if (index == 0) {
        prepend(value);
        return;
    }

    Node<T>* current = head;

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node<T>* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
}

template <class T>
void CircularLinkedList<T>::deleteFirst()
{
    if (head == nullptr) return;

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* last = head;
    while (last->next != head) {
        last = last->next;
    }

    Node<T>* temp = head;
    head = head->next;
    last->next = head;
    delete temp;
}

template <class T>
void CircularLinkedList<T>::deleteLast()
{
    if (head == nullptr) return;

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* current = head;

    while (current->next->next != head) {
        current = current->next;
    }

    delete current->next;
    current->next = head;
}

template <class T>
void CircularLinkedList<T>::deleteBefore(T target)
{
    if (head == nullptr || head->next == head) return;

    Node<T>* current = head;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;

    do {
        next = current->next;
        if (next->data == target) {
            if (current == head) {
                Node<T>* last = head;
                while (last->next != head) last = last->next;
                last->next = head->next;
                delete head;
                head = last->next;
            } else {
                prev->next = next;
                delete current;
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);
}

template <class T>
void CircularLinkedList<T>::deleteAfter(T target)
{
    if (head == nullptr || head->next == head) return;

    Node<T>* current = head;

    do {
        if (current->data == target) {
            Node<T>* temp = current->next;
            if (temp == head) {
                head = head->next;
            }
            current->next = temp->next;
            delete temp;
            return;
        }
        current = current->next;
    } while (current != head);
}

template <class T>
void CircularLinkedList<T>::deleteIndex(int index)  // 0 based
{
    if (index < 0 || index >= countNodes()) return;

    if (index == 0) {
        deleteFirst();
        return;
    }

    Node<T>* current = head;

    for (int i = 0; i < index - 1 && current->next != head; i++) {
        current = current->next;
    }

    if (current != head && current->next != head) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

template <class T>
void CircularLinkedList<T>::deleteValue(T value)
{
    if (head == nullptr) return;

    if (head->data == value) {
        deleteFirst();
        return;
    }

    Node<T>* current = head;

    do {
        if (current->next->data == value) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    } while (current != head);
}

template <class T>
void CircularLinkedList<T>::deleteAllValue(T value)
{
    if (head == nullptr) return;

    if (head->data == value) {
        deleteFirst();
        return;
    }

    Node<T>* current = head;

    do {
        if (current->next->data == value) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    } while (current != head);
}

template <class T>
T CircularLinkedList<T>::sum()
{
    if (head == nullptr) return T{};

    T total{}; 

    Node<T>* current = head;

    do {
        total += current->data;
        current = current->next;
    } while (current != head);

    return total;
}

template <class T>
T CircularLinkedList<T>:: max()
{
    if (head == nullptr) throw runtime_error("Empty List");

    T maximum = head->data;

    Node<T>* current = head->next;

    while (current != head) {
        if (current->data > maximum) {
            maximum = current->data;
        }
        current = current->next;
    }

    return maximum;
}

template <class T>
T CircularLinkedList<T>:: min()
{
    if (head == nullptr) throw runtime_error("Empty List");


    T minimum = head->data;

    Node<T>* current = head->next;

    while (current != head) {
        if (current->data < minimum) {
            minimum = current->data;
        }
        current = current->next;
    }

    return minimum;
}

template <class T>
Node<T>* CircularLinkedList<T>::search(T key)
{
    Node<T>* current = head;

    do {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    } while (current != head);

    return nullptr;
}

template <class T>
bool CircularLinkedList<T>::isSorted()
{
    if (head == nullptr || head->next == head)
        return true;

    Node<T>* current = head;

    do {
        if (current->next != head && current->data > current->next->data) {
            return false;
        }
        current = current->next;
    } while (current->next != head);

    return true;
}

template <class T>
void CircularLinkedList<T>::reverse()   // using sliding pointers
{
    if (!head || head->next == head) return;

    Node<T>* prev = head;
    Node<T>* current = head->next;
    Node<T>* next = nullptr;

    while (current != head) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head->next = prev;
    head = prev;
}

int main()
{
    CircularLinkedList<int> list = {19, 10, 28, 1, 3};
    list.display();

    list.insertBeforeValue(19, 98);
    list.display();
    list.insertBeforeValue(1, 90);
    list.display();
    
    list.insertAfterValue(3, 80);
    list.display();
    list.insertAfterValue(19, 77);
    list.display();

    list.insertAtIndex(0, 53);
    list.display();
    list.insertAtIndex(3, 75);
    list.display();
    list.insertAtIndex(list.countNodes(), 33);
    list.display();
    return 0;
}
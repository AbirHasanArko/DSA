#include <iostream>
using namespace std;

template <class T> class DoublyLinkedList;

template <class T>
class Node {
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
class DoublyLinkedList {
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
    void insertAtIndex(int index, T value); // 0-based

    void deleteFirst();
    void deleteLast();
    void deleteBeforeValue(T target);
    void deleteAfterValue(T target);
    void deleteAtIndex(int index);

    Node<T>* search(T key);
    void reverse();
};

// --- Constructor & Destructor ---
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(initializer_list<T> values) : head(nullptr), tail(nullptr) {
    for (const T& val : values) append(val);
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    while (head) {
        deleteFirst();
        if (head == nullptr) break;
    }
}

// --- Basic Operations ---
template <class T>
void DoublyLinkedList<T>::prepend(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (!head) {
        head = tail = newNode;
        head->next = head->prev = head;
        return;
    }

    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head =newNode;
}

template <class T>
void DoublyLinkedList<T>::append(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (!head) {
        head = tail = newNode;
        head->next = head->prev = head;
        return;
    }

    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
}

template <class T>
void DoublyLinkedList<T>::display() const {
    if (!head) return;

    Node<T>* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::reverseDisplay() const {
    if (!tail) return;

    Node<T>* current = tail;
    do {
        cout << current->data << " ";
        current = current->prev;
    } while (current != tail);
    cout << endl;
}

template <class T>
int DoublyLinkedList<T>::countNodes() {
    if (!head) return 0;
    int count = 0;
    Node<T>* current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

// --- Insert Functions ---
template <class T>
void DoublyLinkedList<T>::insertBeforeValue(T target, T value) {
    if (!head) return;

    Node<T>* current = head;
    do {
        if (current->data == target) {
            if (current == head)
                prepend(value);
            else {
                Node<T>* newNode = new Node<T>(value);
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != head);
}

template <class T>
void DoublyLinkedList<T>::insertAfterValue(T target, T value) {
    if (!head) return;

    Node<T>* current = head;
    do {
        if (current->data == target) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;

            if (current == tail) tail = newNode;
            return;
        }
        current = current->next;
    } while (current != head);
}

template <class T>
void DoublyLinkedList<T>::insertAtIndex(int index, T value) {
    if (index < 0 || index > countNodes())
        throw runtime_error("Out of bounds");

    if (index == 0) {
        prepend(value);
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;

    if (current == tail) {
        append(value);
    } else {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

// --- Delete Functions ---
template <class T>
void DoublyLinkedList<T>::deleteFirst() {
    if (!head) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    delete temp;
}

template <class T>
void DoublyLinkedList<T>::deleteLast() {
    if (!tail) return;

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
        return;
    }

    Node<T>* temp = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete temp;
}

template <class T>
void DoublyLinkedList<T>::deleteBeforeValue(T target) {
    if (!head || head == tail) return;

    Node<T>* current = head;
    do {
        if (current->data == target) {
            if (current == head)
                deleteLast();
            else if (current->prev == head)
                deleteFirst();
            else {
                Node<T>* temp = current->prev;
                temp->prev->next = current;
                current->prev = temp->prev;
                delete temp;
            }
            return;
        }
        current = current->next;
    } while (current != head);
}

template <class T>
void DoublyLinkedList<T>::deleteAfterValue(T target) {
    if (!head || head == tail) return;

    Node<T>* current = head;
    do {
        if (current->data == target) {
            Node<T>* temp = current->next;
            if (temp == head)
                deleteFirst();
            else {
                current->next = temp->next;
                temp->next->prev = current;
                if (temp == tail) tail = current;
                delete temp;
            }
            return;
        }
        current = current->next;
    } while (current != head);
}

template <class T>
void DoublyLinkedList<T>::deleteAtIndex(int index) {
    if (index < 0 || index >= countNodes())
        throw runtime_error("Out of bounds");

    if (index == 0) {
        deleteFirst();
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < index; i++)
        current = current->next;

    if (current == tail) {
        deleteLast();
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

// --- Search & Reverse ---
template <class T>
Node<T>* DoublyLinkedList<T>::search(T key) {
    if (!head) return nullptr;
    Node<T>* current = head;
    do {
        if (current->data == key)
            return current;
        current = current->next;
    } while (current != head);
    return nullptr;
}

template <class T>
void DoublyLinkedList<T>::reverse() {
    if (!head || head == tail) return;

    Node<T>* current = head;
    Node<T>* temp = nullptr;
    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != head);

    swap(head, tail);
}

// --- Main ---
int main() {
    DoublyLinkedList<int> list = { 19, 10, 28, 1, 3 };

    cout << "Original: ";
    list.display();

    list.reverse();
    cout << "Reversed: ";
    list.display();

    cout << "Reverse Display: ";
    list.reverseDisplay();

    return 0;
}

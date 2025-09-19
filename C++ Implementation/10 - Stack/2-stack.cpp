// Stack ADT using Linked List

#include <iostream>

using namespace std;

template <class T>
class Stack;

template <class T>
class Node
{
private:
    T data;
    Node<T>* next;

    friend class Stack<T>;
public:
    Node(T value) : data(value), next(nullptr) {}
};

template <class T>
class Stack
{
private:
    Node<T>* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack()
    {
        while (topNode != nullptr) {
            pop();
        }
    }

    void push(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    T pop()
    {
        if (topNode != nullptr) {
            T value = topNode->data;

            Node<T>* temp = topNode;
            topNode = topNode->next;

            delete temp;
            return value;
        } else {
            cerr << "Stack Underflow\n";
            throw runtime_error("Stack Underflow");
        }
    }

    T top() const
    {
        if (topNode != nullptr) {
            return topNode->data;
        } else {
            cerr << "Empty Stack\n";
            throw runtime_error("Empty Stack");
        }
    }

    T peek(int index) const
    {
        Node<T>* current = topNode;
        for (int i = 1; current != nullptr && i < index; i++) {
            current = current->next;
        }
        if(current != nullptr) {
            return current->data;
        } else {
            cerr << "Invalid index\n";
            throw runtime_error("Invalid index");
        }
    }

    bool isEmpty() const
    {
        return topNode == nullptr;
    }
};

int main()
{
    Stack<int> st;

    if (st.isEmpty()) {
        cout << "Stack is empty\n";
    }

    st.push(2);
    cout << st.top() << " is at top\n";

    st.push(4);
    cout << st.top() << " is at top\n";

    st.push(6);
    cout << st.top() << " is at top\n";

    st.push(8);
    cout << st.top() << " is at top\n";

    st.push(10);
    cout << st.top() << " is at top\n";

    cout << "Peek at index 2: " << st.peek(2) << endl;

    if (!st.isEmpty()) {
        cout << st.pop() << " was popped\n";
    } else {
        cout << "Stack is empty\n";
    }

    if (!st.isEmpty()) {
        cout << st.pop() << " was popped\n";
    } else {
        cout << "Stack is empty\n";
    }

    if (!st.isEmpty()) {
        cout << st.pop() << " was popped\n";
    } else {
        cout << "Stack is empty\n";
    }

    if (!st.isEmpty()) {
        cout << st.pop() << " was popped\n";
    } else {
        cout << "Stack is empty\n";
    }

    if (!st.isEmpty()) {
        cout << st.pop() << " was popped\n";
    } else {
        cout << "Stack is empty\n";
    }

    if (!st.isEmpty()) {
        cout << st.pop() << " was popped\n";
    } else {
        cout << "Stack is empty\n";
    }
    
    return 0;
}
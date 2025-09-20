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


template <class T>
class Queue
{
private:
    Stack<T> st1;
    Stack<T> st2;

public:
    Queue() {}
    ~Queue() {}

    void enqueue(T val)
    {
        st1.push(val);
    }

    T dequeue()
    {
        if (st1.isEmpty() && st2.isEmpty()) {
            throw runtime_error("Queue is emppty");
        }

        if (st2.isEmpty()) {
            while (!st1.isEmpty()) {
                st2.push(st1.pop());
            }
        }

        return st2.pop();
    }

    T front()
    {
        if (st1.isEmpty() && st2.isEmpty()) {
            throw runtime_error("Queue is empty");
        }

        if (st2.isEmpty()) {
            while (!st1.isEmpty()) {
                st2.push(st1.pop());
            }
        }

        return st2.top();
    }
};

int main()
{
    Queue<int> q;

    q.enqueue(6);
    q.enqueue(3);
    q.enqueue(9);
    q.enqueue(5);

    cout << q.dequeue() << " ";

    q.enqueue(4);
    q.enqueue(2);

    cout << q.dequeue() << " "
         << q.dequeue() << " "
         << q.dequeue() << " "
         << q.dequeue() << " "
         << q.dequeue() << endl;
    
    return 0;
}

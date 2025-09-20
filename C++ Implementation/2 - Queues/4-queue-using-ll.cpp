#include <iostream>

using namespace std;

template <class T>
class Queue;

template <class T>
class Node
{
private:
    T data;
    Node<T>* next;

    friend class Queue<T>;

public:
    Node(T value) : data(value), next(nullptr) {}
};

template <class T>
class Queue
{
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue()
    {
        while (!isEmpty()) {
            deque();
        }
    }

    void enqueue(T val)
    {
        Node<T>* newNode = new Node(val);

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    T deque()
    {
        if (front == nullptr) {
            cerr << "Queue is emoty\n";
            throw runtime_error("Queue is empty");
        }

        T val = front->data;

        Node<T>* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;

        return val;
    }

    T peek()
    {
        if (front == nullptr) {
            cerr << "Queue is empty\n";
            throw runtime_error("Queue is empty");
        }

        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    Queue<int> q;

    for (int i = 1; i <= 5; i++) {
        q.enqueue(i * 10);
        cout << "Enqueued " << i * 10 << endl;
    }

    while (!q.isEmpty()) {
        cout << "Front: " << q.peek() << endl;
        cout << "Dequeued: " << q.deque() << endl;
    }

    
    return 0;
}
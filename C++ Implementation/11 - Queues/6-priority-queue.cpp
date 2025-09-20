#include <iostream>

using namespace std;

template <class T>
class PriorityQueue;

template <class T>
class Node
{
private:
    T data;
    int priority;   // higher number = higher priority
    Node<T>* next;

    friend class PriorityQueue<T>;

public:
    Node(T val, int p) : data(val), priority(p), next(nullptr) {}
};

template <class T>
class PriorityQueue
{
private:
    Node<T>* front;

public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue()
    {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(T val, int p)  // O(n)
    {
        Node<T>* newNode = new Node<T>(val, p);

        if (front == nullptr || newNode->priority > front->priority) {
            newNode->next = front;
            front = newNode;
            return;
        }

        Node<T>* curr = front;

        while (curr->next != nullptr && curr->next->priority >= newNode->priority) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    T dequeue()     // O(1)
    {
        if (isEmpty()) {
            cerr << "Priority Queue is empty\n";
            throw runtime_error("Priority Queue is empty");
        }

        T val = front->data;

        Node<T>* temp = front;
        front = front->next;

        delete temp;
        return val;
    }

    T peek()
    {
        if (isEmpty()) {
            cerr << "Priority Queue is empty\n";
            throw runtime_error("Priority Queue is empty");
        }

        return front->data;
    }

    void display()
    {
        if (isEmpty()) {
            cout << "Priority Queue is empty\n";
            return;
        }

        Node<T>* curr = front;
        cout << "Priority Queue: ";
        while (curr != nullptr) {
            cout << "(" << curr->data << ", " << curr->priority << ") ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue<string> pq;

    pq.enqueue("Task1", 2);
    pq.enqueue("Task2", 5);
    pq.enqueue("Task3", 3);
    pq.enqueue("Task4", 5);

    pq.display();

    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.display();

    cout << "Peek: " << pq.peek() << endl;
    
    return 0;
}
#include <iostream>
using namespace std;

template <class T>
class PriorityQueue;

template <class T>
class Node {
private:
    T data;
    Node<T>* next;

    friend class PriorityQueue<T>;

public:
    Node(T val) : data(val), next(nullptr) {}
};

template <class T>
class PriorityQueue {
private:
    Node<T>* front;

public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(T val)
    {
        Node<T>* newNode = new Node<T>(val);

        if (front == nullptr || val < front->data) {
            newNode->next = front;
            front = newNode;
            return;
        }

        Node<T>* curr = front;
        while (curr->next != nullptr && curr->next->data <= val) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    T dequeue()
    {
        if (isEmpty()) {
            throw runtime_error("Priority Queue is empty");
        }

        Node<T>* temp = front;
        T val = temp->data;
        front = front->next;
        delete temp;
        return val;
    }

    T peek()
    {
        if (isEmpty()) {
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
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue<int> pq;

    pq.enqueue(50);
    pq.enqueue(10);
    pq.enqueue(30);
    pq.enqueue(20);

    pq.display();

    cout << "Dequeued: " << pq.dequeue() << endl;
    pq.display();

    cout << "Peek: " << pq.peek() << endl;

    return 0;
}

#include <iostream>

using namespace std;

template <class T>
class DEQue;

template <class T>
class Node
{
private:
    T data;
    Node<T>* next;
    Node<T>* prev;

    friend class DEQue<T>;

public:
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template <class T>
class DEQue
{
private:
    Node<T>* front;
    Node<T>* rear;

public:
    DEQue() : front(nullptr), rear(nullptr) {}

    ~DEQue()
    {
        while (!isEmpty()) {
            dequeue_front();
        }
    }

    void enqueue_front(T val)
    {
        Node<T>* newNode = new Node<T>(val);

        if (front == nullptr) {
            front = rear = newNode;
            return;
        }

        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    void enqueue_rear(T val)
    {
        Node<T>* newNode = new Node<T>(val);

        if (rear == nullptr) {
            rear = front = newNode;
            return;
        }

        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }

    T dequeue_front()
    {
        if (front == nullptr) {
            cerr << "Queue is empty\n";
            throw runtime_error("Queue is empty");
        }

        T val = front->data;
        Node<T>* temp = front;

        front = front->next;

        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }

        delete temp;
        return val;
    }

    T dequeue_rear()
    {
        if (rear == nullptr) {
            cerr << "Queue is empty\n";
            throw runtime_error("Queue is empty");
        }

        T val = rear->data;
        Node<T>* temp = rear;

        rear = rear->prev;

        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr;
        }

        delete temp;
        return val;
    }

    T peek_front()
    {
        if (front == nullptr) {
            cerr << "Queue is empty\n";
            throw runtime_error("Queue is empty");
        }

        return front->data;
    }

    T peek_rear()
    {
        if (rear == nullptr) {
            cerr << "Queue is empty\n";
            throw runtime_error("Queue is empty");
        }

        return rear->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void display()
    {
        Node<T>* curr = front;

        if (curr == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }
};

int main()
{
    DEQue<int> dq;

    dq.enqueue_rear(10);
    dq.enqueue_rear(20);
    dq.enqueue_front(5);
    dq.enqueue_front(1);

    dq.display();

    cout << "Dequeued Front: " << dq.dequeue_front() << endl;
    dq.display();

    cout << "Dequeued Rear: " << dq.dequeue_rear() << endl;
    dq.display();
    
    return 0;
}
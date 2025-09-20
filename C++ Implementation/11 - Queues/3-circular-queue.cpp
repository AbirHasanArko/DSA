#include <iostream>

using namespace std;

#define SIZE 7

template <class T>
class CircularQueue
{
private:
    T Arr[SIZE];
    int Front;
    int Rear;

public:
    CircularQueue() : Front(0), Rear(0) {}

    bool isEmpty() const
    {
        return (Front == Rear);
    }

    bool isFull() const
    {
        return ((Rear + 1) % SIZE == Front);
    }

    void enqueue(T x)   // O(1)
    {
        if (isFull()) {
            cerr << "Queue Overflow\n";
            throw runtime_error("Queue Overflow");
        }

        Arr[Rear] = x;
        Rear = (Rear + 1) % SIZE;
    }

    T dequeue()     // O(1)
    {
        if (isEmpty()) {
            cerr << "Queue Underflow\n";
            throw runtime_error("Queue Underflow");
        }

        T removed = Arr[Front];
        Front = (Front + 1) % SIZE;

        return removed;
    }

    T front() const     // O(1)
    {
        if (isEmpty()) {
            cerr << "Queue Underflow\n";
            throw runtime_error("Queue Underflow");
        }

        return Arr[Front];
    }

    void display() const
    {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = Front; i != Rear; i = (i + 1) % SIZE) {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue<int> q;

    cout << "--- Enqueue 6 elements ---\n";
    for (int i = 1; i <= 6; i++) {
        q.enqueue(i * 10);
    }
    q.display();

    cout << "--- Check if full ---\n";
    if (q.isFull()) cout << "Queue is full\n";

    cout << "--- Dequeue 2 elements ---\n";
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "--- Check if empty ---\n";
    if (q.isEmpty()) cout << "Queue is empty\n";
    else cout << "Queue is not empty\n";

    cout << "--- Enqueue 2 more elements (wrap-around) ---\n";
    q.enqueue(70);
    q.enqueue(80);
    q.display();

    cout << "--- Peek front element ---\n";
    cout << "Front: " << q.front() << endl;

    cout << "--- Dequeue all elements ---\n";
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }
    q.display();
    if (q.isEmpty()) cout << "Queue is now empty\n";
    
    return 0;
}
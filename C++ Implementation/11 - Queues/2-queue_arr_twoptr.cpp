#include <iostream>

using namespace std;

#define SIZE 100

template <typename T>
class Queue
{
private:
    T Arr[SIZE];
    int Front;
    int Rear;

public:
    Queue() : Front(-1), Rear(-1) {}

    bool isEmpty() const
    {
        return (Front == -1 || Front > Rear);
    }

    bool isFull() const
    {
        return (Rear == SIZE - 1);
    }

    void enqueue(T x)   // O(1)
    {
        if (isFull()) {
            cerr << "Queue Overflow\n";
            throw runtime_error("Queue Overflow");
        }

        if (Front == -1) Front = 0; // First element

        Arr[++Rear] = x;
    }

    T dequeue()         // O(1)
    {
        if (isEmpty()) {
            cerr << "Queue Underflow\n";
            throw runtime_error("Queue Underflow");
        }

        T removed = Arr[Front];

        Front++;

        // Reset pointers when queue becomes empty
        if (Front > Rear) {
            Front = Rear = -1;
        }

        return removed;
    }

    T front() const     // O(1)
    {
        if (isEmpty()) {
            cerr << "Queue is empty\n";
            throw runtime_error("Queue is empty");
        }

        return Arr[Front];
    }

    void display() const
    {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = Front; i <=Rear; i++) {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> q;

    q.enqueue(19);
    q.enqueue(10);
    q.enqueue(28);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(1);
    q.enqueue(3);
    q.display();

    cout << "Front element: " << q.front() << endl;

    // String queue
    Queue<string> qs;
    qs.enqueue("Hello");
    qs.enqueue("World");
    qs.display();
    qs.dequeue();
    qs.display();
    
    return 0;
}
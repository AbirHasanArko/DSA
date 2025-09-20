#include <iostream>

using namespace std;

#define SIZE 100

template <class T>
class Queue
{
private:
    T Arr[SIZE];
    int Rear;

public:
    Queue() : Rear(-1) {}

    void enqueue(T x)   // O(1)
    {
        if (Rear == SIZE - 1) {
            cerr << "Queue Overflow!\n";
            throw runtime_error("Queue Overflow!");
        }
        Rear++;
        Arr[Rear] = x;
    }

    T dequeue() // O(n)
    {
        if (Rear == -1) {
            cerr << "Queue Underflow!\n";
            throw runtime_error("Queue Underflow!");
        }

        T removed = Arr[0];

        for (int i = 0; i < Rear; i++) {
            Arr[i] = Arr[i + 1];
        }
        Rear--;

        return removed;
    }

    T front() const   // O(1)
    {
        if (Rear == -1) {
            cerr << "Queue Empty\n";
            throw runtime_error("Queue Empty");
        }

        return Arr[0];
    }

    void display() const
    {
        if (Rear == -1) {
            cerr << "Queue Empty\n";
            throw runtime_error("Queue Empty");
        }

        for (int i = 0; i <= Rear; i++) {
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
    q.enqueue(1);

    q.display();
    cout << "Front: " << q.front() << endl;

    q.dequeue();
    q.enqueue(3);

    q.display();
    cout << "Front: " << q.front() << endl;

    return 0;
}
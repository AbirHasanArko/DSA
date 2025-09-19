// Stack ADT using Array

#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    int size;
    int topIndex;
    T* St;

public:
    Stack(int s) : size (s), topIndex(-1)
    {
        St = new T[size];
    }

    ~Stack()
    {
        delete[] St;
    }

    void push(T x)
    {
        if (topIndex < size - 1) {
            St[++topIndex] = x;
        } else {
            cerr << "Stack Overflow\n";
            throw runtime_error("Stack Underflow\n");
        }
    }

    T pop()
    {
        if (topIndex != -1) {
            T x = St[topIndex--];
            return x;
        } else {
            cerr << "Stack Underflow\n";
            throw runtime_error("Stack Underflow\n");
        }
    }

    T top()
    {
        if (topIndex != -1) {
            return St[topIndex];
        } else {
            cerr << "Empty Stack\n";
            throw runtime_error("Empty Stack");
        }
    }

    T peek(int index)
    {
        if (topIndex - index + 1 >= 0) {
            return St[topIndex - index + 1];
        } else {
            cerr << "Invalid Index\n";
            throw runtime_error("Invalid Index");
        }
    }

    bool isFull()
    {
        return topIndex == size - 1;
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }
};

int main()
{
    Stack<int> st(5);

    if (st.isEmpty()) {
        cout << "Stack is empty\n";
    }

    if (!st.isFull()) {
        st.push(2);
    } else {
        cout << "Stack is full\n";
    }
    cout << st.top() << " is at top\n";
    
    if (!st.isFull()) {
        st.push(4);
    } else {
        cout << "Stack is full\n";
    }
    cout << st.top() << " is at top\n";

    if (!st.isFull()) {
        st.push(6);
    } else {
        cout << "Stack is full\n";
    }
    cout << st.top() << " is at top\n";

    if (!st.isFull()) {
        st.push(8);
    } else {
        cout << "Stack is full\n";
    }
    cout << st.top() << " is at top\n";

    if (!st.isFull()) {
        st.push(10);
    } else {
        cout << "Stack is full\n";
    }
    cout << st.top() << " is at top\n";

    if (!st.isFull()) {
        st.push(12);
    } else {
        cout << "Stack is full\n";
    }
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
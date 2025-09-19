// Stack ADT using Linked List

#include <iostream>
#include <string>

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

    bool isEmpty() const
    {
        return topNode == nullptr;
    }
};

bool isBalanced(string& s)
{
    Stack<char> st;
    for (char& ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (ch == ')' && st.top() == '(') {
                st.pop();
            } else if (ch == '}' && st.top() == '{') {
                st.pop();
            } else if (ch == ']' && st.top() == '[') {
                st.pop();
            } else {
                return false;
            }
        }
    }
    if(st.isEmpty()) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    string p = "[(a + r) + b * {c - d * (e ^ f)}]";

    if (isBalanced(p)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }

    p = "[(a + r} + b * {c - d * (e ^ f)}]";

    if (isBalanced(p)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }
}
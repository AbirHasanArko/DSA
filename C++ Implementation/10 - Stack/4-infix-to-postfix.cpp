#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '~' || c == '^';
}

int precedence(char c)
{
    if (c == '~') return 4;     // Unary minus (highest precedence)
    if (c == '^') return 3;     // Power
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;

    return 0;
}

bool isRightAssociative(char c)
{
    return c == '~' || c == '^';    // Right-to-left operators
}

bool isOperand(char c)
{
    return isalnum(c);      // letters and digits
}

string preprocess(const string &infix)
{
    string res;

    for (size_t i = 0; i < infix.length(); i++) {
        char c = infix[i];
        // Unary minus if it's the first character, or follows ( or operator
        if (c == '-') {
            if (i == 0 || infix[i - 1] == '(' || isOperator(infix[i - 1])) {
                res += '~'; // replace unary minus with ~
            } else {
                res += c;
            }
        } else {
            res += c;
        }
    }
    
    return res;
}

string infixToPostfix(const string& infixRaw)
{
    string infix = preprocess(infixRaw);
    string postfix;
    stack<char> st;

    for (char c : infix) {
        if (isOperand(c)) {
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();   // Remove '('
        } else if (isOperator(c)) {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(c) ||
                    (precedence(st.top()) == precedence(c)) && !isRightAssociative(c))) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}
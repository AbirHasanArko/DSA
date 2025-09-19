#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;

double evaluate_postfix(const string& expr)
{
    stack<double> st;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        // Case 1: token is a number (multi-digit supported)
        if (isdigit(token[0]) ||
            (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
            st.push(stod(token));
        } else {
            double result;

            // Case 2: unary operator ~
            if (token == "~") {
                double val = st.top();
                st.pop();
                result = -val;
            } else {
                // Case 3: binary operators
                double val2 = st.top(); st.pop();
                double val1 = st.top(); st.pop();

                switch(token[0]) {
                    case '+': result = val1 + val2; break;
                    case '-': result = val1 - val2; break;
                    case '*': result = val1 * val2; break;
                    case '/': result = val1 / val2; break;
                    case '^': result = pow(val1, val2); break;
                    default:
                        cerr << "Invalid Operator: " << token << endl;
                        return -1;
                }
            }
            st.push(result);
        }
    }
    return st.top();
}

int main()
{
    string expr;
    cout << "Enter postfix expression: ";
    getline(cin, expr);

    cout << "Result = " << evaluate_postfix(expr) << endl;
    
    return 0;
}
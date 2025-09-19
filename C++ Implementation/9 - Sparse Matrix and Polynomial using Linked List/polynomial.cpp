#include <iostream>

using namespace std;

struct Node
{
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

class Polynomial
{
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}
    ~Polynomial() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int coeff, int exp) {
        if (coeff == 0) return;

        Node* newNode = new Node(coeff, exp);

        // Case 1: empty list or new node has higher exponent than head
        if (head == nullptr || exp > head->exp) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        // Traverse to find the correct position
        while (curr != nullptr && curr->exp > exp) {
            prev = curr;
            curr = curr->next;
        }

        // If a node with the same exponent is found, add coefficients
        if (curr != nullptr && curr->exp == exp) {
            curr->coeff += coeff;
            delete newNode;

            // If coefficient becomes zero, remove the node
            if (curr->coeff == 0) {
                if (prev == nullptr) { // head node to be deleted
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
            }
        } else {
            // Insert new node between prev and curr
            if (prev == nullptr) {
                // Insert at head
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = curr;
                prev->next = newNode;
            }
        }
    }

    void create()
    {
        int n, coeff, exp;
        cout << "Enter number of terms: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter term " << i + 1 << " (coeff, exp) : ";
            cin >> coeff >> exp;
            insert(coeff, exp);
        }
    }

    void display()
    {
        Node* curr = head;
        bool isFirstTerm = true;
        while (curr != nullptr) {
            if (curr->coeff == 0){
                curr = curr->next;
                continue;
            }
            if (!isFirstTerm && curr->coeff > 0) cout << " + ";
            else if (!isFirstTerm && curr->coeff < 0) cout << " - ";
            if (isFirstTerm && curr->coeff < 0) cout << "-";

            int absCoeff = abs(curr->coeff);

            if (curr->exp == 0) {
                cout << absCoeff;
            } else {
                if (absCoeff != 1) cout << absCoeff;
                cout << "x";
                if (curr->exp != 1) cout << "^" << curr->exp;
            }

            curr = curr->next;
            isFirstTerm = false;
        }
        cout << endl;
    }

    friend Polynomial add(Polynomial& p1, Polynomial& p2);
};

Polynomial add(Polynomial& p1, Polynomial& p2)
{
    Polynomial sum;
    Node* c1 = p1.head;
    Node* c2 = p2.head;

    while (c1 && c2) {
        if (c1->exp > c2->exp) {
            sum.insert(c1->coeff, c1->exp);
            c1 = c1->next;
        } else if (c1->exp < c2->exp) {
            sum.insert(c2->coeff, c2->exp);
            c2 = c2->next;
        } else {
            sum.insert(c1->coeff + c2->coeff, c1->exp);
            c1 = c1->next;
            c2 = c2->next;
        }
    }

    while (c1) {
        sum.insert(c1->coeff, c1->exp);
        c1 = c1->next;
    }
    while (c2) {
        sum.insert(c2->coeff, c2->exp);
        c2 = c2->next;
    }

    return sum;
}

int main()
{
    Polynomial p1;
    p1.create();
    Polynomial p2;
    p2.create();

    cout << "p1: ";
    p1.display();

    cout << "p2: ";
    p2.display();

    Polynomial sum = add (p1, p2);

    cout << "sum: ";
    sum.display();
    
    return 0;
}
#include <iostream>

using namespace std;

struct Term
{
    int coeff;
    int exp;
};

class Poly
{
private:
    int n;  // number of terms
    Term *terms;

public:
    Poly(int n) {
        this->n = n;
        terms = new Term[n];
    }

    ~Poly() {
        delete[] terms;
    }

    friend ostream& operator<<(ostream& COUT, const Poly& p);
    friend istream& operator>>(istream& CIN, Poly& p);
    Poly operator+(const Poly& other);
};

ostream& operator<<(ostream& COUT, const Poly& p) {
    bool isFirstTerm = true;
    for (int i = 0; i < p.n; i++) {
        if (p.terms[i].coeff == 0) continue;
        if (!isFirstTerm && p.terms[i].coeff > 0) COUT << " + ";
        else if (!isFirstTerm && p.terms[i].coeff < 0) COUT << " - ";
        if (isFirstTerm && p.terms[i].coeff < 0) COUT << "-";

        int absCoeff = abs(p.terms[i].coeff);

        if (p.terms[i].exp == 0) {
            COUT << absCoeff;
        } else {
            if (absCoeff != 1) COUT << absCoeff;

            COUT << "x";

            if(p.terms[i].exp != 1) COUT << "^" << p.terms[i].exp;
        }
        
        isFirstTerm = false;
    }

    if(isFirstTerm) COUT << "0";
    
    return COUT;
}

istream& operator>>(istream& CIN, Poly& p) {
    cout << "Enter terms(coefficient exponent):\n";
    for (int i = 0; i < p.n; i++) {
        cout << "Term " << i + 1 << " : ";
        CIN >> p.terms[i].coeff >> p.terms[i].exp;
    }

    return CIN;
}

Poly Poly::operator+(const Poly& other) {
    int i = 0, j = 0, k = 0;
    int size = this->n + other.n;

    Poly sum(size);
    
    sum.n = 0;

    while (i < n && j < other.n) {
        if (terms[i].exp > other.terms[j].exp) {
            sum.terms[k++] = terms[i++];
        } else if (terms[i].exp < other.terms[j].exp) {
            sum.terms[k++] = other.terms[j++];
        } else {
            int newCoeff = terms[i].coeff + other.terms[j].coeff;
            if (newCoeff != 0) {
                sum.terms[k].exp = terms[i].exp;
                sum.terms[k++].coeff = newCoeff;
            }
            i++;
            j++;
        }
    }

    while (i < n) {
        sum.terms[k++] = terms[i++];
    }
    while (j < other.n) {
        sum.terms[k++] = other.terms[j++];
    }

    sum.n = k;

    return sum;
}

int main()
{
    int n1, n2;
    
    cout << "Enter number of terms for first polynomial: ";
    cin >> n1;
    Poly p1(n1);
    cin >> p1;

    cout << "Enter number of terms for second polynomial: ";
    cin >> n2;
    Poly p2(n2);
    cin >> p2;

    Poly sum = p1 + p2;

    cout << p1 << " + " << p2 << " = " << sum << endl;
    
    return 0;
}
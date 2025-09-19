#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

template <class T>
struct Element
{
    int i;  // row
    int j;  // col
    T x;    // data
};

template <class T>
class Sparse
{
    // order of matrix: m*n
    int m;
    int n;
    int num;    // Number of non-zero elements
    Element<T> *ele;

public:
    Sparse(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element<T>[this->num];
    }

    ~Sparse() {
        delete[] ele;
    }

    Sparse(const Sparse &s) {
        m = s.m;
        n = s.n;
        num = s.num;
        ele = new Element<T>[num];
        for (int i = 0; i < num; i++) {
            ele[i] = s.ele[i];
        }
    }

    Sparse& operator=(const Sparse &s) {
        delete[] ele;
        m = s.m;
        n = s.n;
        num = s.num;
        ele = new Element<T>[num];
        for (int i = 0; i < num; i++) {
            ele[i] = s.ele[i];
        }
        
        return *this;
    }

    Sparse operator+(Sparse &other);

    template <class U>
    friend istream& operator>>(istream &CIN, Sparse<U> &s);

    template <class U>
    friend ostream& operator<<(ostream &COUT, const Sparse<U> &s);
};

template <class T>
istream& operator>>(istream &CIN, Sparse<T> &s)
{
    for (int i = 0; i < s.num; i++) {
        CIN >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }

    sort(s.ele, s.ele + s.num, [](const Element<T>& a, const Element<T>& b) {
        return (a.i < b.i) || (a.i == b.i && a.j < b.j);
    });

    return CIN;
}

template <class T>
ostream& operator<<(ostream &COUT, const Sparse<T> &s)
{
    int k = 0;

    for (int i = 1; i <= s.m; i++) {
        for (int j = 1; j <= s.n; j++) {
            if (k < s.num && s.ele[k].i == i && s.ele[k].j == j) {
                COUT << setw(4) << s.ele[k++].x << " ";
            } else {
                COUT << setw(4) << 0 << " ";
            }
        }
        COUT << endl;
    }
    
    return COUT;
}

template <class T>
Sparse<T> Sparse<T>::operator+(Sparse<T> &other) {
    int i, j, k;

    if (m != other.m || n != other.n) {
        return Sparse(0, 0, 0);
    }

    Sparse<T> sum(m, n, num + other.num);

    i = j = k = 0;

    while (i < num && j < other.num) {
        if (ele[i].i < other.ele[j].i ||
            (ele[i].i == other.ele[j].i && ele[i].j < other.ele[j].j)) {
            sum.ele[k++] = ele[i++];
        } else if (ele[i].i > other.ele[j].i ||
                   (ele[i].i == other.ele[j].i && ele[i].j > other.ele[j].j)) {
            sum.ele[k++] = other.ele[j++];
        } else {
            sum.ele[k] = ele[i];
            sum.ele[k++].x = ele[i++].x + other.ele[j++].x;
        }
    }

    for (; i < num; i++) {
        sum.ele[k++] = ele[i];
    }
    for (; j < other.num; j++) {
        sum.ele[k++] = other.ele[j];
    }

    sum.num = k;

    return sum;
}

int main()
{
    Sparse<int> s1(5, 6, 5);
    Sparse<int> s2(5, 6, 6);
    
    cout << "Enter non-zero elements of s1 (row, col , data):\n";
    cin >> s1;
    cout << "Enter non-zero elements of s2 (row, col , data):\n";
    cin >> s2;

    Sparse<int> sum = s1 + s2;

    cout << "s1:" << endl << s1 << endl;
    cout << "s2:" << endl << s2 << endl;
    cout << "sum:" << endl << sum << endl;

    return 0;
}
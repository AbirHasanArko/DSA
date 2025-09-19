#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class Matrix
{
protected:
    T* A;
    int m, n;   // row, column

public:
    Matrix(int row, int column) {
        m = row;
        n = column;
        A = new T[m * n]();
    }

    virtual ~Matrix() {
        delete[] A;
    }

    virtual void set(int i, int j, T x);
    virtual T get(int i, int j) const;
    virtual void display() const;
};

template <class T>
void Matrix<T>::set(int i, int j, T x)
{
    if (i >= 1 && i <= m && j >= 1 && j <= n){
        A[(i - 1) * n + (j - 1)] = x;
    } else {
        cout << "Invalid index\n";
    }
}

template <class T>
T Matrix<T>::get(int i, int j) const
{
    if (i >= 1 && i <= m && j >= 1 && j <= n) {
        return A[(i - 1) * n + (j - 1)];
    }
    else {
        cout << "Invalid index\n";
        return T(); // default value
    }
}

template <class T>
void Matrix<T>::display() const
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << A[i * n + j] << " ";
        }
        cout << endl;
    }
}

template <class T>
class SquareMatrix : public Matrix<T>
{
public:
    SquareMatrix(int size) : Matrix<T>(size, size) {}

    int get_dimension() const {
        return this->n;
    }
};

template <class T>
class DiagonalMatrix : public SquareMatrix<T>
{
public:
    DiagonalMatrix(int size) : SquareMatrix<T>(size) {
        delete[] this->A;
        this->A = new T[size]();
    }

    void set(int i, int j, T x) override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            if (i == j) {
                this->A[i - 1] = x;
            } else if (i != j && x != 0) {
                cout << "Only diagonal elements can be set to non-zero in DiagonalMatrix\n";
            } else if (i != j && x == 0) {
                return;
            }
        } else {
            cout << "Invalid index\n";
        }
    }

    T get(int i, int j) const override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            return (i == j) ? this->A[i - 1] : 0;
        } else {
            cout << "Invalid index\n";
            return T();
        }
    }

    void display() const override {
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                cout << setw(4) << ((i == j) ? this->A[i] : 0) << " ";
            }
            cout << endl;
        }
    }
};

template <class T>
class LowerTriangularMatrix : public SquareMatrix<T>
{
public:
    LowerTriangularMatrix(int size) : SquareMatrix<T>(size) {
        delete[] this->A;
        this->A = new T[this->n * (this->n + 1) / 2]();
    }

    void set(int i, int j, T x) override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            if (i >= j) {
                this->A[i * (i - 1) / 2 + j - 1] = x;   // row-major mapping
            } else if (i < j && x != 0) {
                cout << "Only lower triangular elements can be set to non-zero in LowerTriangularMatrix\n";
            } else if (i < j && x == 0) {
                return;
            }
        } else {
            cout << "Invalid index\n";
        }
    }

    T get(int i, int j) const override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            return (i >= j) ? this->A[i * (i - 1) / 2 + j - 1] : 0;
        } else {
            cout << "Invalid index\n";
            return T();
        }
    }

    void display() const override {
        for (int i = 1; i <= this->n; i++) {
            for (int j = 1; j <= this->n; j++) {
                cout << setw(4) << ((i >= j) ? this->A[i * (i - 1) / 2 + j - 1] : 0) << " ";
            }
            cout << endl;
        }
    }
};

template <class T>
class UpperTriangularMatrix : public SquareMatrix<T>
{
    public:
    UpperTriangularMatrix(int size) : SquareMatrix<T>(size) {
        delete[] this->A;
        this->A = new T[this->n * (this->n + 1) / 2]();
    }

    void set(int i, int j, T x) override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            if (i <= j) {
                this->A[j * (j - 1) / 2 + i - 1] = x;   // column-major mapping
            } else if (i > j && x != 0) {
                cout << "Only upper triangular elements can be set to non-zero in UpperTriangularMatrix\n";
            } else if (i > j && x == 0) {
                return;
            }
        } else {
            cout << "Invalid index\n";
        }
    }

    T get(int i, int j) const override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            return (i <= j) ? this->A[j * (j - 1) / 2 + i - 1] : 0;
        } else {
            cout << "Invalid index\n";
            return T();
        }
    }

    void display() const override {
        for (int i = 1; i <= this->n; i++) {
            for (int j = 1; j <= this->n; j++) {
                cout << setw(4) << ((i <= j) ? this->A[j * (j - 1) / 2 + i - 1] : 0) << " ";
            }
            cout << endl;
        }
    }
};

template <class T>
class SymmetricMatrix : public LowerTriangularMatrix<T>
{
public:
    SymmetricMatrix(int size) : LowerTriangularMatrix<T>(size) {}

    void set(int i, int j, T x) override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            if (i >= j) {
                this->A[i * (i - 1) / 2 + j - 1] = x;   // row-major mapping
            } else {
                this->A[j * (j - 1) / 2 + i - 1] = x;
            }
        } else {
            cout << "Invalid index\n";
        }
    }

    T get(int i, int j) const override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            return (i >= j) ? this->A[i * (i - 1) / 2 + j - 1] : this->A[j * (j - 1) / 2 + i - 1];
        } else {
            cout << "Invalid index\n";
            return T();
        }
    }

    void display() const override {
        for (int i = 1; i <= this->n; i++) {
            for (int j = 1; j <= this->n; j++) {
                cout << setw(4) << ((i >= j) ? this->A[i * (i - 1) / 2 + j - 1] : this->A[j * (j - 1) / 2 + i - 1]) << " ";
            }
            cout << endl;
        }
    }
};

template <class T>
class TriDiagonalMatrix : public SquareMatrix<T>
{
public:
    TriDiagonalMatrix(int size) : SquareMatrix<T>(size) {
        delete[] this->A;
        this->A = new T[3 * size - 2]();
    }

    void set(int i, int j, T x) override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            if (i - j == 1) {
                this->A[i - 2] = x;
            } else if (i - j == 0) {
                this->A[this->n + i - 2] = x;
            } else if (i - j == -1) {
                this->A[2 * this->n + i - 2] = x;
            } else if ((abs(i - j)) > 1 && x != 0) {
                cout << "Only lower, main, and upper diagonal elements can be non-zero in TriDiagonalMatrix\n";
            } else if ((abs(i - j)) > 1 && x == 0) {
                return;
            }
        } else {
            cout << "Invalid index\n";
        }
    }

    T get(int i, int j) const override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            switch (i - j) {
            case 1:
                return this->A[i - 2];
                break;
            case 0:
                return this->A[this->n + i - 2];
                break;
            case -1:
                return this->A[2 * this->n + i - 2];
                break;
            default:
                return 0;
                break;
            }
        } else {
            cout << "Invalid index\n";
            return T();
        }
    }

    void display() const override {
        for (int i = 1; i <= this->n; i++) {
            for (int j = 1; j <= this->n; j++) {
                switch (i - j) {
                case 1:
                    cout << setw(4) << this->A[i - 2];
                    break;
                case 0:
                   cout << setw(4) << this->A[this->n + i - 2];
                    break;
                case -1:
                    cout << setw(4) << this->A[2 * this->n + i - 2];
                    break;
                default:
                    cout << setw(4) << 0;
                    break;
                }
            }
            cout << endl;
        }
    }
};

template <class T>
class ToeplitzMatrix : public SquareMatrix<T>
{
public:
    ToeplitzMatrix(int size) : SquareMatrix<T>(size) {
        delete[] this->A;
        this->A = new T[2 * this->n -1];
    }

    void set(int i, int j, T x) override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            if (i <= j) {
                this->A[j - i] = x;
            } else {
                this->A[this->n + i - j - 1] = x;
            }
        } else {
            cout << "Invalid index\n";
        }
    }

    T get(int i, int j) const override {
        if (i >= 1 && i <= this->n && j >= 1 && j <= this->n) {
            if (i <= j) {
                return this->A[j - i];
            } else {
                return this->A[this->n + i - j - 1];
            }
        } else {
            cout << "Invalid index\n";
            return T();
        }
    }

    void display() const override {
        for (int i = 1; i <= this->n; i++) {
            for (int j = 1; j <= this->n; j++) {
                if (i <= j) {
                    cout << setw(4) << this->A[j - i] << " ";
                } else {
                    cout << setw(4) << this->A[this->n + i - j - 1] << " ";
                }
            }
            cout << endl;
        }
    }
};

// Sample usage
int main()
{
    cout << "General Matrix:\n";
    Matrix<int> m(2, 3);
    m.set(1, 1, 5);
    m.set(2, 3, 9);
    m.display();

    cout << "\nSquare Matrix:\n";
    SquareMatrix<int> sm(3);
    sm.set(1, 1, 1);
    sm.set(2, 2, 2);
    sm.set(3, 3, 3);
    sm.set(1, 3, 7);
    sm.display();
    cout << "Dimension: " << sm.get_dimension() << endl;

    cout << "\nDiagonal Matrix:\n";
    DiagonalMatrix<int> dm(4);
    dm.set(1, 1, 10);
    dm.set(2, 2, 20);
    dm.set(3, 3, 30);
    dm.set(4, 4, 40);
    dm.set(1, 2, 5); // Should trigger warning
    dm.display();

    /*
    cout << "\nLower Triangular Matrix:\n";
    LowerTriangularMatrix<int> ltm(4);
    for (int i = 1; i <= ltm.get_dimension(); i++) {
        for (int j = 1; j <= ltm.get_dimension(); j++) {
            int x;
            cin >> x;
            ltm.set(i, j, x);
        }
    }
    ltm.display();

    cout << "\nUpper Triangular Matrix:\n";
    UpperTriangularMatrix<int> utm(4);
    for (int i = 1; i <= utm.get_dimension(); i++) {
        for (int j = 1; j <= utm.get_dimension(); j++) {
            int x;
            cin >> x;
            utm.set(i, j, x);
        }
    }
    utm.display();

    cout << "\nSymmetric Matrix:\n";
    SymmetricMatrix<int> symm(3);
    for (int i = 1; i <= symm.get_dimension(); i++) {
        for (int j = 1; j <= symm.get_dimension(); j++) {
            int x;
            cin >> x;
            symm.set(i, j, x);
        }
    }
    symm.display();

    cout << "\nTri Diagonal Matrix:\n";
    TriDiagonalMatrix<int> tdm(5);
    for (int i = 1; i <= tdm.get_dimension(); i++) {
        for (int j = 1; j <= tdm.get_dimension(); j++) {
            int x;
            cin >> x;
            tdm.set(i, j, x);
        }
    }
    tdm.display();
    */

    cout << "\nToeplitz Diagonal Matrix:\n";
    ToeplitzMatrix<int> tdm(5);
    for (int i = 1; i <= tdm.get_dimension(); i++) {
        for (int j = 1; j <= tdm.get_dimension(); j++) {
            int x;
            cin >> x;
            tdm.set(i, j, x);
        }
    }
    tdm.display();

    return 0;
}


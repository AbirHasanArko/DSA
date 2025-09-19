#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
struct Node
{
    int col;
    T value;
    Node<T>* next;

    Node(int c, T val) : col(c), value(val), next(nullptr) {}
};

template <class T>
class SparseMatrix
{
private:
    int rows, cols;
    Node<T>** rowHeads;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {
        rowHeads = new Node<T>*[rows];
        for (int i = 0; i < rows; i++) {
            rowHeads[i] = nullptr;
        }
    }

    void insert(int r, int c, T val) {
        if (val == 0 || r < 0 || c < 0 || r >= rows || c >= cols) {
            return;
        }

        Node<T>* newNode = new Node<T>(c, val);

        if (!rowHeads[r] || c < rowHeads[r]->col) {
            newNode->next = rowHeads[r];
            rowHeads[r] = newNode;
        } else {
            Node<T>* curr = rowHeads[r];
            while (curr->next && curr->next->col < c) {
                curr = curr->next;
            }
            if (curr->col == c) {
                curr->value += val;
                delete newNode;
            } else if (curr->next && curr->next->col == c) {
                curr->next->value += val;
                delete newNode;
            } else {
                newNode->next = curr->next;
                curr->next = newNode;
            }
        }
    }

    void create() {
        int n;
        cout << "Enter number of non-zero eleemts: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            int r, c;
            T val;
            cout << "Enter row, column, and value for element " << i + 1 << ": ";
            cin >> r >> c >> val;
            insert(r, c, val);
        }
    }

    void display()
    {
        cout << "\nFull Matrix:\n";
        for (int i = 0; i < rows; i++) {
            Node<T>* curr = rowHeads[i];

            for (int j = 0; j < cols; j++) {
                if (curr && curr->col == j) {
                    cout << setw(4) << curr->value;
                    curr = curr->next;
                } else {
                    cout << setw(4) << 0;
                }
            }
            cout << endl;
        }
    }

    template <class U>
    friend SparseMatrix<U> add(const SparseMatrix<U>& A, const SparseMatrix<U>& B);
};

template <class T>
SparseMatrix<T> add(const SparseMatrix<T>& A, const SparseMatrix<T>& B)
{
    if (A.rows != B.rows || A.cols != B.cols) {
        throw runtime_error("Matrix size mismatch!\n");
    }

    SparseMatrix<T> result(A.rows, A.cols);

    for (int i = 0; i < A.rows; i++) {
        Node<T>* a = A.rowHeads[i];
        Node<T>* b = B.rowHeads[i];

        while (a && b) {
            if (a->col < b->col) {
                result.insert(i, a->col, a->value);
                a = a->next;
            } else if (b->col < a->value) {
                result.insert(i, b->col, b->value);
                b = b->next;
            } else {
                result.insert(i, a->col, a->value + b->value);
                a = a->next;
                b = b->next;
            }
        }

        while (a) {
            result.insert(i, a->col, a->value);
            a = a->next;
        }

        while (b) {
            result.insert(i, b->col, b->value);
            b = b->next;
        }
    }

    return result;
}


int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    SparseMatrix<int> mat1(rows, cols);
    SparseMatrix<int> mat2(rows, cols);

    cout << "Enter 1st Matrix:\n";
    mat1.create();

    cout << "Enter 2nd Matrix:\n";
    mat2.create();

    cout << "\nMatrix 1:";
    mat1.display();

    cout << "\nMatrix 2:";
    mat2.display();

    SparseMatrix<int> sum = add(mat1, mat2);
    cout << "\nSum of matrices:";
    sum.display();
    
    return 0;
}
#include <iostream>
#include <optional>
#include <initializer_list>
#include <iomanip>

using namespace std;

template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        A = new T[size];
        length = 0;
    }

    Array(int s)
    {
        size = s;
        length = 0;
        A = new T[size];
    }

    Array(int s, int l, T arr[])
    {
        size = s;
        length = l;
        A = new T[size];
        for (int i = 0; i < length; i++) {
            A[i] = arr[i];
        }
    }

    Array(initializer_list<T> list)
    {
        size = list.size();
        length = size;
        A = new T[size];

        int i = 0;
        for (const T& val : list) {
            A[i++] = val;
        }
    }

    ~Array()
    {
        delete[] A;
    }

    void append(T x);
    void display();
    void insert(int index, T x);
    void fill();

    optional<T> _delete(int index);

    int linear_search(T key);

    int binary_search(T target);
    int recursive_binary_search(T target, int l, int r);

    int get_length();

    optional<T> get(int index);
    void set(int index, T x);

    T min();
    T max();
    T sum();
    T average();

    void reverse();
    void shift_left();
    void rotate_left();
    void shift_right();
    void rotate_right();

    void sorted_insert(T x);
    bool is_sorted();
    void neg_on_left();

    template<class U>
    friend Array<U> sorted_merge(Array<U>& arr1, Array<U>& arr2);

    template<class U>
    friend Array<U> set_union(Array<U>& arr1, Array<U>& arr2);
    template<class U>
    friend Array<U> set_intersection(Array<U>& arr1, Array<U>& arr2);
    template<class U>
    friend Array<U> set_difference(Array<U>& arr1, Array<U>& arr2);

    template<class U>
    friend Array<U> sorted_set_union(Array<U>& arr1, Array<U>& arr2);
    template<class U>
    friend Array<U> sorted_set_intersection(Array<U>& arr1, Array<U>& arr2);
    template<class U>
    friend Array<U> sorted_set_difference(Array<U>& arr1, Array<U>& arr2);
};



int main()
{
    Array<int> arr;

    for (int i = 0, x = 2; i < 5; i++, x += 2) {
        arr.append(x);
    }

    arr.display();

    arr.insert(3, 7);
    arr.display();

    optional<int> deleted = arr._delete(3);
    if (deleted.has_value()) {
        cout << "Deleted: " << *deleted << endl;
    } else {
        cout << "Invalid Index" << endl;
    }
    arr.display();

    int index = arr.linear_search(6);
    arr.display();
    if (index >= 0) {
        cout << "Index: " << index << endl;
    } else {
        cout << "Not found" << endl;
    }

    int data[] = {4, 8, 10, 15, 19, 21, 24, 27, 28, 33, 34, 37, 39, 41, 43};
    Array<int> sorted_array(sizeof(data) / sizeof(data[0]), sizeof(data) / sizeof(data[0]), data);
    sorted_array.display();
    index = sorted_array.binary_search(19);
    if (index >= 0) {
        cout << "Index: " << index << endl;
    } else {
        cout << "Not found" << endl;
    }

    index = sorted_array.recursive_binary_search(28, 0, sorted_array.get_length() - 1);
    if (index >= 0) {
        cout << "Index: " << index << endl;
    } else {
        cout << "Not found" << endl;
    }

    Array<float> a = {6, 8, 2, 4, 19, 28, 11, 15, 1, 3};
    a.display();

    auto result = a.get(4);
    if (result.has_value()) {
        cout << "Value: " << result.value() << endl;
    } else {
        cout << "Invalid index" << endl;
    }

    a.set(8, 29);
    a.display();

    cout << "Min: " << a.min() << endl;
    cout << "Max: " << a.max() << endl;
    cout << "Sum: " << a.sum() << endl;
    cout << "Avg: " << a.average() << endl;


    Array<char> b = {'R', 'O', 'Z', 'A'};
    b.display();

    b.reverse();
    b.display();

    b.rotate_left();
    b.display();

    b.shift_left();
    b.display();

    Array<char> c = {'W', 'O', 'R', 'L', 'D'};
    c.display();

    c.rotate_right();
    c.display();

    c.shift_right();
    c.display();

    int d[] = {1, 3, 5, 7, 25, 28, 31};
    Array<int> a1(10, sizeof(d) / sizeof(d[0]), d);
    cout << "a1: ";
    a1.display();

    a1.sorted_insert(19);
    cout << "a1: ";
    a1.display();

if (a1.is_sorted()) {
    cout << "a1 is sorted" << endl;
} else {
    cout << "a1 is not sorted" << endl;
}
Array<int> a2 = {1, 3, 19, 7, 25, 28, 31};
cout << "a2: ";
a2.display();
if (a2.is_sorted()) {
    cout << "a2 is sorted" << endl;
} else {
    cout << "a2 is not sorted" << endl;
}
Array<int> a3 = {-6, 3, -8, 10, 5, -7, -9, 28, -4, 19};
cout << "a3: ";
a3.display();

a3.neg_on_left();
cout << "a3: ";
a3.display();

    Array<int> arr1 = {1, 3, 5, 7, 9};
    cout << "arr1: ";
    arr1.display();
    Array<int> arr2 = {2, 4, 6, 8, 10};
    cout << "arr2: ";
    arr2.display();

    cout << "arr3: ";
    Array<int> arr3 = sorted_merge(arr1, arr2);
    arr3.display();

    Array<int> arr_A = {3, 4, 5, 6, 10};
    cout << left << setw(18) << "A: ";
    arr_A.display();
    Array<int> arr_B = {2, 4, 5, 7, 12};
    cout << left << setw(18) << "B: ";
    arr_B.display();

    Array<int> arr_U = sorted_set_union(arr_A, arr_B);
    cout << left << setw(18) << "A union B: ";
    arr_U.display();

    Array<int> arr_I = sorted_set_intersection(arr_A, arr_B);
    cout << left << setw(18) << "A intersection B: ";
    arr_I.display();

    Array<int> arr_D = sorted_set_difference(arr_A, arr_B);
    cout << left << setw(18) << "A - B: ";
    arr_D.display();

    return 0;
}

template <class T>
int Array<T>::get_length()
{
    return length;
}

template <class T>
void Array<T>::append(T x)              // O(1)
{
    A[length] = x;
    length++;
}

template <class T>
void Array<T>::display()                // O(n)
{
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T>::insert(int index, T x)   // O(n)
{
    for (int i = length; i > index; i--) {
        A[i] = A[i - 1];
    }

    A[index] = x;
    length++;
}

template <class T> 
optional<T> Array<T>::_delete(int index)    // O(n)
{
    T x;

    if (index >= 0 && index < length) {
        x = A[index];
        for (int i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
    return nullopt;
}

template <class T>
int Array<T>::linear_search(T key)      // O(n)
{
    for (int i = 0; i < length; i++) {
        if (A[i] == key) {
            return i;
        }
    }
    return -1;
}

/*
// Improving Linear Search

// Transposition
template <class T>
int Array<T>::linear_search(T key)
{
    for (int i = 0; i < length; i++) {
        if (A[i] == key) {
            swap(A[i], A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

// Move to Front / Head
template <class T>
int Array<T>::linear_search(T key)
{
    for (int i = 0; i < length; i++) {
        if (A[i] == key) {
            swap(A[i], A[0]);
            return 0;
        }
    }
    return -1;
}
*/

template <class T>
int Array<T>::binary_search(T target)       // O(log n)
{
    int left = 0, right = length - 1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

template <class T>
int Array<T>::recursive_binary_search(T target, int l, int r)
{
    int mid;
    if (l <= r) {
        mid = l + (r - l) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[mid] < target) {
            return recursive_binary_search(target, mid + 1, r);
        } else {
            return recursive_binary_search(target, l, mid - 1);
        }
    }
    return -1;
}

template <class T>
optional<T> Array<T>::get(int index)    // O(1)
{
    if (index >= 0 && index < length) {
        return A[index];
    }
    return nullopt;
}

template <class T>
void Array<T>::set(int index, T x)      // O(1)
{
    if (index >= 0 && index < length) {
        A[index] = x;
    }
}

template <class T>
T Array<T>::min()                       // O(n)
{
    T mn = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] < mn) {
            mn = A[i];
        }
    }
    return mn;
}

template <class T>
T Array<T>::max()                       // O(n)
{
    T mx = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > mx) {
            mx = A[i];
        }
    }
    return mx;
}

template <class T>
T Array<T>::sum()                       // O(n)
{
    T s = 0;
    for (int i = 0; i < length; i++) {
        s += A[i];
    }
    return s;
}

template <class T>
T Array<T>::average()                   // O(n)
{
    return sum() / length;
}

template <class T>
void Array<T>::reverse()                // O(n)
{
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        swap(A[i], A[j]);
    }
}

/*
// Using extra array
template <class T>
void Array<T>::reverse()                // O(n)
{
    int s = size;
    int l = length;
    T *B = new T[size];

    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }

    delete []A;
    A = B;
    B = nullptr;
}
*/

template <class T>
void Array<T>::shift_left()         // O(n)
{
    for (int i = 0; i < length - 1; i++) {
        A[i] = A[i + 1];
    }
    A[length - 1] = '_';
}

template <class T>
void Array<T>::rotate_left()        // O(n)
{
    T temp = A[0];
    for (int i = 0; i < length - 1; i++) {
        A[i] = A[i + 1];
    }
    A[length - 1] = temp;
}

template <class T>
void Array<T>::shift_right()        // O(n)
{
    for (int i = length - 1; i > 0 ; i--) {
        A[i] = A[i - 1];
    }
    A[0] = '_';
}

template <class T>
void Array<T>::rotate_right()       // O(n)
{
    T temp = A[length - 1];
    for (int i = length - 1; i > 0; i--) {
        A[i] = A[i - 1];
    }
    A[0] = temp;
}

template <class T>
void Array<T>::sorted_insert(T x)
{
    int i = length - 1;
    while (A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

template <class T>
bool Array<T>::is_sorted()
{
    for (int i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}

template <class T>
void Array<T>::neg_on_left()
{
    int i = 0, j = length - 1;

    while (i < j) {
        while (A[i] < 0) i++;
        while (A[j] >= 0) j--;

        if (i < j) {
            swap(A[i], A[j]);
        }
    }
}

template <class U>
Array<U> sorted_merge(Array<U>& arr1, Array<U>& arr2)   // O(m + n)
{
    int i = 0, j = 0, k = 0;

    Array<U> merged_arr(arr1.length + arr2.length);

    while (i < arr1.length && j < arr2.length) {
        if (arr1.A[i] < arr2.A[j]) {
            merged_arr.A[k++] = arr1.A[i++];
        } else {
            merged_arr.A[k++] = arr2.A[j++];
        }
    }

    while (i < arr1.length) {
        merged_arr.A[k++] = arr1.A[i++];
    }
    while (j < arr2.length) {
        merged_arr.A[k++] = arr2.A[j++];
    }

    merged_arr.length = k;

    return merged_arr;
}

template<class U>
Array<U> set_union(Array<U>& arr1, Array<U>& arr2)  // O(m * n)
{
    int k = 0;

    Array<U> union_arr(arr1.length + arr2.length);

    for (int i = 0; i < arr1.length; i++) {
        union_arr.A[k++] = arr1.A[i];
    }

    for (int i = 0; i < arr2.length; i++) {
        bool found = false;

        for (int j = 0; j < arr1.length; j++) {
            if (arr2.A[i] == arr1.A[j]) {
                found = true;
                break;
            }
        }
        
        if (!found) {
            union_arr.A[k++] = arr2.A[i];
        }
    }
    
    union_arr.length = k;

    return union_arr;
}

template<class U>
Array<U> set_intersection(Array<U>& arr1, Array<U>& arr2)   // O(m * n)
{
    int k = 0;

    Array<U>intersect_arr(min(arr1.length, arr2.length));

    for (int i = 0; i < arr1.length; i++) {
        bool found = false;

        for (int j = 0; j < arr2.length; j++) {
            if (arr1.A[i] == arr2.A[j]) {
                found = true;
                break;
            }
        }

        if (found) {
            intersect_arr.A[k++] = arr1.A[i];
        }
    }
    
    intersect_arr.length = k;

    return intersect_arr;
}

template<class U>
Array<U> set_difference(Array<U>& arr1, Array<U>& arr2) // O(m * n)
{
    int k = 0;

    Array<U>diff_arr(arr1.length);

    for (int i = 0; i < arr1.length; i++) {
        bool found = false;

        for (int j = 0; j < arr2.length; j++) {
            if (arr1.A[i] == arr2.A[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            diff_arr.A[k++] = arr1.A[i];
        }
    }
    
    diff_arr.length = k;

    return diff_arr;
}

template<class U>
Array<U> sorted_set_union(Array<U>& arr1, Array<U>& arr2)   // O(m + n)
{
    int i = 0, j = 0, k = 0;

    Array<U> union_arr(arr1.length + arr2.length);

    while (i < arr1.length && j < arr2.length) {
        if (arr1.A[i] < arr2.A[j]) {
            union_arr.A[k++] = arr1.A[i++];
        } else if (arr2.A[j] < arr1.A[i]) {
            union_arr.A[k++] = arr2.A[j++];
        } else {
            union_arr.A[k++] = arr1.A[i++];
            j++;
        }
    }

    while (i < arr1.length) {
        union_arr.A[k++] = arr1.A[i++];
    }
    while (j < arr2.length) {
        union_arr.A[k++] = arr2.A[j++];
    }

    union_arr.length = k;

    return union_arr;
}

template<class U>
Array<U> sorted_set_intersection(Array<U>& arr1, Array<U>& arr2)    // O(m + n)
{
    int i = 0, j = 0, k = 0;

    Array<U> intersect_arr(min(arr1.length, arr2.length));

    while (i < arr1.length && j < arr2.length) {
        if (arr1.A[i] < arr2.A[j]) {
            i++;
        } else if (arr2.A[j] < arr1.A[i]) {
            j++;
        } else {
            intersect_arr.A[k++] = arr1.A[i++];
            j++;
        }
    }

    intersect_arr.length = k;

    return intersect_arr;
}

template<class U>
Array<U> sorted_set_difference(Array<U>& arr1, Array<U>& arr2)  // O(m + n)
{
    int i = 0, j = 0, k = 0;

    Array<U> diff_arr(arr1.length);

    while (i < arr1.length && j < arr2.length) {
        if (arr1.A[i] < arr2.A[j]) {
            diff_arr.A[k++] = arr1.A[i++];
        } else if (arr2.A[j] < arr1.A[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i < arr1.length) {
        diff_arr.A[k++] = arr1.A[i++];
    }

    diff_arr.length = k;

    return diff_arr;
}



#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

template<typename T>
class MyVector {
public:
    MyVector();
    MyVector(T);

    MyVector(const MyVector &v);

    ~MyVector();

    void add_element(T);

    void delete_element(int i);

    T operator[](int i);

    void sort();

    int Size() { return size; }

    int Maxsize() { return maxsize; }

    int find(T);

    MyVector<T> &operator=(const MyVector<T> &v); //я люблю эту лабу

    template<typename T1>
    friend ostream &operator<<(ostream &out, MyVector<T1> &v);

protected:
    int maxsize;
    int size;
    T *pdata;
private:
    void resize();
};

//============================================================================================










template<>
MyVector<char *>::MyVector() {
    size = 0;
    maxsize = MAX_SIZE;
    pdata = new char *[maxsize];
}

template<typename T>
MyVector<T>::MyVector() {

    size = 0;
    maxsize = MAX_SIZE;
    pdata = new T[maxsize];
}


template<>
MyVector<char *>::MyVector(char *el) {
    maxsize = 5;
    size = 1;
    pdata = new char *[5];
    pdata[0] = new char[strlen(el) + 1];
    strcpy(*pdata, el);
}


template<typename T>
MyVector<T>::MyVector(T el) {
    maxsize = 5;
    size = 1;
    pdata = new T[5];
    pdata[0] = el;
}
template<>
void MyVector<char *>::resize() {
    if (size >= maxsize)
        maxsize = (maxsize / 2 + 1) * 3;
    else if (maxsize != MAX_SIZE && size <= maxsize / 2)
        maxsize = (maxsize / 3 + 1) * 2;
    else return;
    char **newMemory = new char *[maxsize];

    for (size_t i = 0; i < size; ++i) {
        if (pdata[i] == NULL) break;
        newMemory[i] = new char[strlen(pdata[i]) + 1];
        strcpy(newMemory[i], pdata[i]);
    }
    for (size_t i = 0; i < size; ++i) {
        delete[] pdata[i];

    }
    delete[] pdata;
    pdata = newMemory;
}

template<typename T>
void MyVector<T>::resize() {
    if (size >= maxsize)
        maxsize = (maxsize / 2 + 1) * 3;
    else if (maxsize != MAX_SIZE && size <= maxsize / 2)
        maxsize = (maxsize / 3 + 1) * 2;
    else return;
    T *newMemory = new T[maxsize];

    for (size_t i = 0; i < size; ++i) {
        if (pdata[i] == NULL) break;
        newMemory[i] = pdata[i];
    }
    delete[] pdata;
    pdata = newMemory;
}


template<>
void MyVector<char *>::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(pdata[i], pdata[j]) > 0) {
                swap(pdata[i], pdata[j]);
            }
        }
    }
}

template<typename T>
void MyVector<T>::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (pdata[i] > pdata[j]) {
                swap(pdata[i], pdata[j]);
            }
        }
    }
}


template<>
MyVector<char *>::MyVector(const MyVector &v) {
    maxsize = v.maxsize;
    size = v.size;
    pdata = new char *[v.maxsize];
    for (int i = 0; i < size; ++i) {
        pdata[i] = new char[strlen(v.pdata[i]) + 1];
        strcpy(pdata[i], v.pdata[i]);
    }
}

template<typename T>
MyVector<T>::MyVector(const MyVector &v)  {
    maxsize = v.maxsize;
    size = v.size;
    pdata = new T[v.maxsize];
    for (int i = 0; i < size; ++i) {
        pdata[i] = v.pdata[i];
    }
}

template<>
void MyVector<char *>::add_element(char *el) {
    size++;
    resize();
    pdata[size - 1] = new char[strlen(el) + 1];
    strcpy(pdata[size - 1], el);
}

template<typename T>
void MyVector<T>::add_element(T el) {
    size++;
    resize();
    pdata[size - 1] = el;
}

template<>
MyVector<char *>::~MyVector() {
    for (int i = 0; i < size; ++i) {
        delete[] pdata[i];
    }
    delete[] pdata;
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] pdata;
}

template<typename T>
ostream &operator<<(ostream &out, MyVector<T> &v) {
    for (int i = 0; i < v.size; ++i) {
        out << '[' << i << ']' << " : " << "{\"" << v.pdata[i] << "\"}" << endl;
    }
    return out;
}

template<>
ostream &operator<<(ostream &out, MyVector<char *> &v) {
    for (int i = 0; i < v.size; ++i) {
        out << '[' << i << ']' << " : " << "{\"" << v.pdata[i] << "\"}" << endl;
    }
    return out;
}


template<>
void MyVector<char *>::delete_element(int i) {
    if (i > -1 && i < size) {
        for (int j = i; j < size - 1; ++j) {
            pdata[j] = new char[strlen(pdata[j + 1]) + 1];
            strcpy(pdata[j], pdata[j + 1]);
        }
        size--;
        resize();
    }
}

template<typename T>
void MyVector<T>::delete_element(int i) {
    if (i > -1 && i < size) {
        for (int j = i; j < size - 1; ++j) {
            pdata[j] = pdata[j + 1];
        }
        size--;
        resize();
    }
}



template<typename T>
int MyVector<T>::find(T el) {
    int q = std::find_if(pdata, pdata + size, [el](T q) { return q == el; }) - pdata;
    if (q == size) q = -1;
    return q;
}

template<>
int MyVector<char *>::find(char *el) {
    int q = std::find_if(pdata, pdata + size, [el](char *q) { return strcmp(q, el); }) - pdata;
    if (q == size) q = -1;
    return q;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &v) {
    if (this != &v) {
        maxsize = v.maxsize;
        size = v.size;
        pdata = new T *[v.maxsize];
        for (int i = 0; i < size; ++i) {
            pdata[i] = new T;
            pdata[i] = v.pdata[i];
        }
    }
    return *this;
}

template<>
MyVector<char *> &MyVector<char *>::operator=(const MyVector<char *> &v) {
    if (this != &v) {
        maxsize = v.maxsize;
        size = v.size;
        pdata = new char *[v.maxsize];
        for (int i = 0; i < size; ++i) {
            pdata[i] = new char[strlen(v.pdata[i]) + 1];
            strcpy(pdata[i], v.pdata[i]);
        }
    }
    return *this;
}




template<>
char *MyVector<char *>::operator[](int i) {
    return pdata[i];
}

template<typename T>
T MyVector<T>::operator[](int i) {
    return pdata[i];
}





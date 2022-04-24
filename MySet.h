



#include <iostream>


using namespace std;

template<typename T>
class MySet : public MyVector<T> {
public:
    MySet() : MyVector<T>() {};

    MySet(T el) : MyVector<T>(el) {};

    template<typename T1>
    friend ostream &operator<<(ostream &out, MySet<T1> &s);

    template<typename T1>
    friend MySet<T1> operator+(MySet<T1> &s1, MySet<T1> &s2);

    template<typename T1>
    friend MySet<T1> operator-(MySet<T1> &s1, MySet<T1> &s2);

    template<typename T1>
    friend MySet<T1> operator*(MySet<T1> &s1, MySet<T1> &s2);

    bool operator==(MySet &s);

    MySet &operator+=(MySet &s);

    MySet &operator-=(MySet &s);

    MySet &operator*=(MySet &s);

    void add_element(T el);

    void delete_element(T el);

    bool is_element(T el);

private:
    int q_find(T el);
};



template<>
void MySet<char *>::add_element(char *el) {
    MyVector<char *>::add_element(el);
    MyVector<char *>::sort();
}

template<typename T>
void MySet<T>::add_element(T el) {
    MyVector<T>::add_element(el);
    MyVector<T>::sort();
}

template<>
int MySet<char *>::q_find(char *el) {
    int left = 0;
    int right = size - 1;
    int mid = 0;
    while (true) {
        mid = (left + right) / 2;
        if (strcmp(el, pdata[mid]) < 0)
            right = mid - 1;
        else if (strcmp(el, pdata[mid]) > 0)
            left = mid + 1;
        else
            return mid;
        if (left > right)
            return -1;
    }
}

template<typename T>
int MySet<T>::q_find(T el) {
    int left = 0;
    int right = this->size - 1;
    int mid = 0;
    while (true) {
        mid = (left + right) / 2;
        if (el < this->pdata[mid])
            right = mid - 1;
        else if (el > this->pdata[mid])
            left = mid + 1;
        else
            return mid;
        if (left > right)
            return -1;
    }
}

template<>
void MySet<char *>::delete_element(char *el) {
    int q = q_find(el);
    if (q != -1) {
        MyVector<char *>::delete_element(q);
        MyVector<char *>::sort();
    }
}

template<typename T>
void MySet<T>::delete_element(T el) {
    int q = q_find(el);
    if (q != -1) {
        MyVector<T>::delete_element(q);
        MyVector<T>::sort();
    }
}


template<typename T>
bool MySet<T>::is_element(T el) {
    if (q_find(el) != -1) return true;
    return false;
}

template<typename T>
ostream &operator<<(ostream &out, MySet<T> &s) {
    for (int i = 0; i < s.size; ++i) {
        out << '[' << i << ']' << " : " << "{\"" << s.pdata[i] << "\"}" << '\n';
    }
    return out;
}

template<>
ostream &operator<<(ostream &out, MySet<char *> &s) {
    for (int i = 0; i < s.size; ++i) {
        out << '[' << i << ']' << " : " << "{\"" << s.pdata[i] << "\"}" << '\n';
    }
    return out;
}


template<typename T>
MySet<T> operator+(MySet<T> &s1, MySet<T> &s2) {
    MySet<T> newSet = s1;
    for (int i = 0; i < s2.size; ++i) {
        if (newSet.q_find(s2[i]) == -1) {
            newSet.add_element(s2[i]);
        }
    }
    return newSet;
}

template<>
MySet<char *> operator+(MySet<char *> &s1, MySet<char *> &s2) {
    MySet<char *> newSet = s1;
    for (int i = 0; i < s2.size; ++i) {
        if (newSet.q_find(s2[i]) == -1) {
            newSet.add_element(s2[i]);
        }
    }
    return newSet;
}

template<>
MySet<char *> operator-(MySet<char *> &s1, MySet<char *> &s2) {
    MySet<char *> newSet;
    for (int i = 0; i < s1.size; ++i) {
        if (s2.q_find(s1[i]) == -1) {
            newSet.add_element(s1[i]);
        }
    }
    return newSet;
}

template<typename T>
MySet<T> operator-(MySet<T> &s1, MySet<T> &s2) {
    MySet<T> newSet;
    for (int i = 0; i < s1.size; ++i) {
        if (s2.q_find(s1[i]) == -1) {
            newSet.add_element(s1[i]);
        }
    }
    return newSet;
}


template<typename T>
MySet<T> operator*(MySet<T> &s1, MySet<T> &s2) {
    MySet<T> newSet;
    for (int i = 0; i < s1.size; ++i) {
        if (s2.q_find(s1[i]) != -1) {
            newSet.add_element(s1[i]);
        }
    }
    return newSet;
}

template<>
MySet<char *> operator*(MySet<char *> &s1, MySet<char *> &s2) {
    MySet<char *> newSet;
    for (int i = 0; i < s1.size; ++i) {
        if (s2.q_find(s1[i]) != -1) {
            newSet.add_element(s1[i]);
        }
    }
    return newSet;
}

template<>
bool MySet<char *>::operator==(MySet<char *> &s) {
    if (size == s.size) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(pdata[i], s[i]) != 0)
                return false;
        }
        return true;
    }
    return false;
}

template<typename T>
bool MySet<T>::operator==(MySet<T> &s) {
    if (this->size == s.size) {
        for (int i = 0; i < this->size; ++i) {
            if (this->pdata[i] != s[i])
                return false;
        }
        return true;
    }
    return false;
}
//
//template<typename T>
//MySet<T> &MySet<T>::operator+=(MySet<T> &s) {
//    *this = *this + s;
//    return *this;
//}
//
//template<typename T>
//MySet<T> &MySet<T>::operator-=(MySet<T> &s) {
//    *this = *this - s;
//    return *this;
//}
//
//template<typename T>
//MySet<T> &MySet<T>::operator*=(MySet<T> &s) {
//    *this = *this * s;
//    return *this;
//}



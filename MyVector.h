#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

const int MAX_SIZE = 5;
template <typename T>
class MyVector
{
public:
	MyVector();
	MyVector(T, int = MAX_SIZE);

	MyVector(const MyVector& v);

	~MyVector();

	void add_element(T);

	void delete_element(int ind); 

	T operator[](int i);

	void sort();

	int Size() { return size; }
	int Maxsize() { return maxsize; }

	int find(T);




	MyVector& operator=(const MyVector& v);
	template <typename T1>
	friend ostream& operator<<(ostream& out, MyVector<T1>& v);

protected:
	int maxsize;
	int size;
	T* pdata;
private:
	void resize();


};






//========================================= 

template<typename T>
MyVector<T>::MyVector() {
	size = 0;
	maxsize = MAX_SIZE;
	pdata = new T[maxsize];
}

template<>
MyVector<char*>::MyVector() {
	size = 0;
	maxsize = MAX_SIZE;
	pdata = new char* [maxsize];
}

template<>
MyVector<char*>::MyVector(char* el, int maxsz) : maxsize(maxsz) {
	size = 1;
	pdata = new char* [maxsz];
	pdata[0] = new char[strlen(el) + 1];
	strcpy(*pdata, el);
}

template<typename T>
MyVector<T>::MyVector(T el, int maxsz) : maxsize(maxsz) {
	size = 1;
	pdata = new T[maxsz];
	pdata[0] = el;
}







template <>
void MyVector<char*>::add_element(char* el) {
	pdata[size] = new char(strlen(el) + 1);
	strcpy(pdata[size], el);
	size++;
	resize();
}

template<>
void MyVector<char*>::delete_element(int ind) {
	if (ind > -1 and ind < size) {
		for (int i = ind; i < size - 1; i++) {
			swap(pdata[i], pdata[i + 1]);
		}
		size--;



		resize();
	}
}




template <>
void MyVector<char*>::sort() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (strcmp(pdata[i], pdata[j]) < 0) {
				swap(pdata[i], pdata[j]);
			}
		}
	}
}

template<>
void MyVector<char*>::resize() {
	if (size >= maxsize) {
		maxsize *= 2;
		char** buf = new char*[maxsize];


		for (int i = 0; i < size; i++) {
			buf[i] = new char[20];
			strcpy(buf[i],pdata[i]);
		}
		delete[]pdata;
		pdata = buf;
	}

	if (size < maxsize / 2) {
		maxsize /= 2;
	}

	if (maxsize < 5) {
		maxsize = 5;
		char** buf = new char* [maxsize];


		for (int i = 0; i < size; i++) {
			buf[i] = new char[20];
			strcpy(buf[i], pdata[i]);
		}
		delete[]pdata;
		pdata = buf;
	}
}

template<typename T>
void MyVector<T>::resize() {
	if (size >= maxsize) {
		maxsize *= 2;
		T* buf = new T[maxsize];


		for (int i = 0; i < size; i++) {
			buf[i] = pdata[i];
		}
		delete[]pdata;
		pdata = buf;
	}

	if (size < maxsize / 2) {
		maxsize /= 2;
	}

	if (maxsize < 5) {
		maxsize = 5;
		T* buf = new T[maxsize];


		for (int i = 0; i < size; i++) {
			buf[i] = pdata[i];
		}
		delete[]pdata;
		pdata = buf;
	}
}


template <>
int MyVector<char*>::find(char* el) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (strcmp(pdata[i], el) == 0) {
			index = i;
		}
	}
	return index;
}


template <>
MyVector<char*>& MyVector<char*>::operator=(const MyVector<char*>& v) {
	maxsize = v.maxsize;
	if (this != &v) {

		for (int i = 0; i < size; i++) {
			delete[] pdata[i];
		}
		delete[] pdata;


		size = v.size;

		pdata = new char* [maxsize];
		for (int i = 0; i < size; i++) {
			pdata[i] = new char[strlen(v.pdata[i]) + 1];
			strcpy(pdata[i], v.pdata[i]);
		}
	}
	return *this;
}


template <>
MyVector<char*>::MyVector(const MyVector& v) {
	maxsize = v.maxsize;
	size = v.size;
	pdata = new char*[v.maxsize];
	for (int i = 0; i < size; i++) {
		pdata[i] = new char[strlen(v.pdata[i]) + 1];
		strcpy(pdata[i], v.pdata[i]);

	}
}


template <typename T>
MyVector<T>::MyVector(const MyVector& v) {
	maxsize = v.maxsize;

	size = v.size;
	pdata = new T[v.maxsize];
	for (int i = 0; i < v.size; i++) {
		pdata[i] = v.pdata[i];
	}
}

template <>
MyVector<char*>::~MyVector() {
	delete[]pdata;
}

template <typename T>
MyVector<T>::~MyVector() {
	delete[]pdata;
}

 template <typename T>
void MyVector<T>::add_element(T el) {
	pdata[size] = el;
	size++;
	resize();
}


template<typename T>
void MyVector<T>::delete_element(int ind) {
	if (ind > -1 and ind < size) {
		for (int i = ind; i < size - 1; i++) {
			swap(pdata[i], pdata[i + 1]);
		}
		size--;



		resize();
	}
}


template <typename T>
void MyVector<T>::sort() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (pdata[i] > pdata[j]) {
				swap(pdata[i], pdata[j]);
			}
		}
	}
}

template <>
int MyVector<char*>::find(char* el) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (pdata[i] == el) {
			index = i;
		}
	}
	return index;
}


 template <typename T>
int MyVector<T>::find(T el) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (pdata[i] == el) {
			index = i;
		}
	}
	return index;
}




template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& v) {
	maxsize = v.maxsize;
	if (this != &v) {

		delete[] pdata;
		size = v.size;

		pdata = new T[maxsize];
		for (int i = 0; i < size; i++) {
			pdata[i] = v.pdata[i];
		}
	}
	return *this;
}

template <typename T>
ostream& operator<<(ostream& out, MyVector<T>& v) {
	for (int i = 0; i < v.size; i++) {
		out << v.pdata[i] << endl;
	}
	return out;
}

template<>
char* MyVector<char*>::operator[](int i) {
	return pdata[i];
}

template<typename T>
T MyVector<T>::operator[](int i) {
	return pdata[i];
}

template<>
ostream& operator<<(ostream& out, MyVector<char*>& v) {
	for (int i = 0; i < v.size; ++i) {
		out << '[' << i << ']' << " : " << "{\"" << v[i] << "\"}" << endl;
	}
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, MyVector<T>& v) {
	for (int i = 0; i < v.size; ++i) {
		out << '[' << i << ']' << " : " << "{\"" << v.pdata[i] << "\"}" << endl;
	}
	return out;
}



#endif




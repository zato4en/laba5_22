#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

const int MAX_SIZE = 5;
template <class T> 
class MyVector
{
public:
	MyVector(const char* el = NULL, int maxsz = MAX_SIZE) {
		maxsize = maxsz;
		pdata = new char* [maxsize];
		size = 0;
		pdata[0] = new char[20];
		if (el != NULL) {
			strcpy(pdata[0], el);
			size++;
		}
	}

	MyVector(MyVector& v) {
		maxsize = v.size * 2;
		pdata = new char* [maxsize];
		size = 0;
		for (int i = 0; i < v.size; i++) {
			pdata[i] = new char[20];
		}
		
		for (int i = 0; i < v.size; i++) {
			for (int j = 0; j < strlen(v.pdata[i]) + 1; j++) {
				pdata[i][j] = v.pdata[i][j];
			}
			size++;
		}
		resize();
		
	}

	~MyVector() {
		pdata = nullptr;
	}

	void add_element(const T el) {
		pdata[size] = new char(strlen(el) + 1);
		strcpy(pdata[size], el);
		size++;
		resize();
	}

	void delete_element(int ind) {
		if (pdata[ind] != nullptr) {
			delete[] pdata[ind];
			for (int i = ind; i < size - 1; i++) {
				if (ind == size - 1) {
					break;
				}
				pdata[i] = pdata[i + 1];
			}
			size--;



			resize();
		}
	}

	char* operator[](int i) {
		return pdata[i];
	}

	void sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (strcmp(pdata[i], pdata[j]) < 0) {
					swap(pdata[i], pdata[j]);
				}
			}
		}
	}

	int Size() { return size; }
	int Maxsize() { return maxsize; }
	int find(char* el) {
		int index = - 1;
		for (int i = 0; i < size; i++) {
			if (strcmp(pdata[i], el) == 0) {
				index = i;
			}
		}
		return index;
	}

	MyVector& operator=(const MyVector& v) {
		maxsize = v.maxsize;
		if (this != &v) {

			for (int i = 0; i < size; i++) {
				delete[] pdata[i];
			}
			delete[] pdata;

			
			size = v.size;

			pdata = new char* [maxsize];
			for (int i = 0; i < size; i++) {
				pdata[i] = new char[strlen(v.pdata[i])+1];
				strcpy(pdata[i], v.pdata[i]);
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, MyVector& v) {
		for (int i = 0; i < v.size; i++) {
			for (int j = 0; j < strlen(v.pdata[i]) + 1; j++) {
				out << v.pdata[i][j];
			}
			out << endl;
		}
		return out;
	}
protected:
	int maxsize;
	int size;
	char** pdata;
private:
	void resize() {
		if (size >= maxsize) {
			maxsize *= 2;
			char** buf = new char* [maxsize];
			for (int i = 0; i < maxsize; i++) {
				buf[i] = new char[20];
			}

			for (int i = 0; i < maxsize; i++) {
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
			char** buf = new char* [maxsize];
			for (int i = 0; i < maxsize; i++) {
				buf[i] = new char[20];
			}

			for (int i = 0; i < maxsize; i++) {
				buf[i] = pdata[i];
			}
			delete[]pdata;
			pdata = buf;
		}
	}
};

template <>
void MyVector<char*>::add_element(char* el) {
	pdata[size] = new char(strlen(el) + 1);
	strcpy(pdata[size], el);
	size++;
	resize();
}




#endif

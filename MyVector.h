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
	MyVector(T el = T(0), int maxsz = MAX_SIZE) {
		maxsize = maxsz;
		pdata = new T [maxsize];
		size = 0;
		if (el != T(0)) {
			pdata[0] = el;
			size++;
		}
		
	}

	MyVector(const MyVector& v) {
		maxsize = v.maxsize;
		
		size = v.size;
		pdata = new T[v.maxsize];
		for (int i = 0; i < v.size; i++) {
			pdata[i] = v.pdata[i];
		}
	}

	~MyVector() {
		delete []pdata;
	}

	void add_element(T el) {
		pdata[size] = el;
		size++;
		resize();
	}

	void delete_element(int ind) {
		if (pdata[ind] != T(0)) {
			for (int i = ind; i < size - 1; i++) {
				swap(pdata[i], pdata[i + 1]);
			}
			size--;



			resize();
		}
	}

	T operator[](int i) {
		return pdata[i];
	}

	void sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (pdata[i] > pdata[j]) {
					swap(pdata[i], pdata[j]);
				}
			}
		}
	}

	int Size() { return size; }
	int Maxsize() { return maxsize; }

	int find(T el) {
		int index = -1;
		for (int i = 0; i < size; i++) {
			if (pdata[i] == el) {
				index = i;
			}
		}
		return index;
	}


	

	MyVector& operator=(const MyVector& v) {
		maxsize = v.maxsize;
		if (this != &v) {
			
			delete[] pdata;
			size = v.size;

			pdata = new T [maxsize];
			for (int i = 0; i < size; i++) {
				pdata[i] = v.pdata[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, MyVector& v) {
		for (int i = 0; i < v.size; i++) {
			out << v.pdata[i] << endl;
		}
		return out;
	}

protected:
	int maxsize;
	int size;
	T* pdata;
private:
	void resize() {
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
	
	
};






//========================================= dlya char*
//
template <>
 MyVector<char*>::MyVector(char* el, int maxsz) {
	maxsize = 5;
	pdata = new char* [maxsize];
	size = 0;
	pdata[0] = new char[20];
	if (el != NULL) {
		strcpy(pdata[0], el);
		size++;
	}
}


template<>
MyVector<char*>::MyVector(const MyVector& v) {
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




template <>
void MyVector<char*>::add_element(char* el) {
	pdata[size] = new char(strlen(el) + 1);
	strcpy(pdata[size], el);
	size++;
	resize();
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












#endif
//
//
//#ifndef MYSET_H
//#define MYSET_H
//
//
//
//
//
//template <class T>
//class MySet :public MyVector<T>
//{
//public:
//	MySet(const T* el = NULL) :MyVector(el) {};
//
//
//	friend MySet operator+(const MySet& s1, const MySet& s2) {
//		MySet buf;
//		for (int i = 0; i < s1.size; i++) {
//			buf.add_element(s1[i]);
//		}
//		for (int i = 0; i < s2.size; i++) {
//			buf.add_element(s2[i]);
//		}
//
//
//		return buf;
//	}
//
//	friend MySet operator-(const MySet<T>& s1, const MySet<T>& s2) {
//		MySet<T> buf;
//		buf = s1;
//		for (int i = 0; i < s1.size; i++) {
//			for (int j = 0; j < s2.size; j++) {
//				if (s1[i] == s2[j]) {
//					buf.delete_element(s1[i]);
//				}
//			}
//		}
//		return buf;
//	}
//
//	friend MySet operator*(const MySet& s1, const MySet& s2) {
//		MySet buf;
//		for (int i = 0; i < s1.size; i++) {
//			for (int j = 0; j < s2.size; j++) {
//				if (strcmp(s1[i], s2[j]) == 0) {
//					buf.add_element(s1[i]);
//				}
//			}
//		}
//		return buf;
//	}
//
//	bool operator==(MySet& s) {
//		(*this).sort();
//		s.sort();
//		if (size != s.size) {
//			return false;
//		}
//
//		for (int i = 0; i < size; i++) {
//			if ((*this)[i] != s[i]) {
//				return false;
//			}
//		}
//		return true;
//	}
//
//
//	/*MySet& operator+=(MySet& s);
//	MySet& operator-=(MySet& s);
//	MySet& operator*=(MySet& s);*/
//
//	//void sett() {
//	//	for (int i = 0; i < size - 1; i++) {
//	//		for (int j = i + 1; j < size; i++) {
//	//			if (strcmp(pdata[i], pdata[j]) == 0){
//	//				delete_element(s1.pdata[i]);
//	//			}
//	//		}
//	//	}
//
//
//
//	void add_element(const char* el) {
//		bool flag = 0;
//		for (int i = 0; i < size; i++) {
//			if (strcmp((*this)[i], el) == 0)
//			{
//				flag = true;
//				break;
//			}
//		}
//		if (!flag) {
//			MyVector::add_element(el);
//		}
//	}
//
//	void delete_element(char* el) {
//
//		int index = -1;
//		for (int i = 0; i < size; i++) {
//			if (strcmp((*this)[i], el) == 0) {
//				index = i;
//				break;
//			}
//		}
//		if (index != -1) {
//			MyVector::delete_element(index);
//		}
//	}
//
//	bool is_element(char* el) {
//		for (int i = 0; i < size; i++) {
//			if (strcmp((*this)[i], el) == 0) {
//				return true;
//
//			}
//		}
//		return false;
//	}
//
//	//friend MySet<char*>& operator+(MySet<char*>& s1, MySet<char*>& s2);
//
//
//
//};
//
//
//
////==============================================================
//
////template<>
////MySet<char*> operator-(const MySet<char*>& s1, const MySet<char*>& s2) const {
////	MySet<char*> buf;
////	buf = s1;
////	for (int i = 0; i < s1.size; i++) {
////		for (int j = 0; j < s2.size; j++) {
////			if (strcmp(s1.pdata[i], s2.pdata[j]) == 0) {
////				buf.delete_element(s1.pdata[i]);
////			}
////		}
////	}
////	return buf;
////}
//
//
//
//#endif

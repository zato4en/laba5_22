#ifndef MYSET_H
#define MYSET_H
#include <iostream>
using namespace std;

class MySet :public MyVector
{
public:
	MySet(const char* el = NULL) :MyVector(el) {};

	
	friend MySet operator+(MySet& s1, MySet& s2) {
		MySet buf;
		for (int i = 0; i < s1.size; i++) {
			buf.add_element(s1.pdata[i]);
		}
		for (int i = 0; i < s2.size; i++) {
			buf.add_element(s2.pdata[i]);
		}
		

		return buf;
	}

	friend MySet operator-(const MySet& s1, const MySet& s2) {
		MySet buf;
		buf = s1;
		for (int i = 0; i < s1.size; i++) {
			for (int j = 0; j < s2.size; j++) {
				if (strcmp(s1.pdata[i], s2.pdata[j]) == 0) {
					buf.delete_element(s1.pdata[i]);
				}
			}
		}
		return buf;
	}

	friend MySet operator*(MySet& s1, MySet& s2) {
		MySet buf;
		for (int i = 0; i < s1.size; i++) {
			for (int j = 0; j < s2.size; j++) {
				if (strcmp(s1.pdata[i], s2.pdata[j]) == 0) {
					buf.add_element(s1.pdata[i]);
				}
			}
		}
		return buf;
	}

	bool operator==(MySet& s) {
		sort();
		s.sort();
		if (size != s.size) {
			return false;
		}

		for (int i = 0; i < size; i++) {
			if (strcmp(pdata[i], s.pdata[i]) != 0) {
				return false;
			}
		}
		return true;
	}


	/*MySet& operator+=(MySet& s);
	MySet& operator-=(MySet& s);
	MySet& operator*=(MySet& s);*/

	//void sett() {
	//	for (int i = 0; i < size - 1; i++) {
	//		for (int j = i + 1; j < size; i++) {
	//			if (strcmp(pdata[i], pdata[j]) == 0){
	//				delete_element(s1.pdata[i]);
	//			}
	//		}
	//	}

	//}

	void add_element(const char* el) {
		bool flag = 0;
		for (int i = 0; i < size; i++) {
			if (strcmp(pdata[i], el) == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag) {
			MyVector::add_element(el);
		}
	}

	void delete_element(char* el) {
		
		int index = -1;
		for (int i = 0; i < size; i++) {
			if (strcmp(pdata[i], el) == 0) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			MyVector::delete_element(index);
		}
	}

	bool is_element(char* el) {
		for (int i = 0; i < size; i++) {
			if (strcmp(pdata[i], el) == 0) {
				return true;
				
			}
		}
		return false;
	}

};

#endif

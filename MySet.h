
#include <iostream>
using namespace std;

template <typename T>
class MySet :public MyVector<T>
{
public:
	MySet() :MyVector<T>() {};
		
	MySet(const T el) : MyVector<T>(el, 5) {};


	template <typename T1>
	friend MySet<T1> operator-(MySet<T1>& s1, MySet<T1>& s2);


	//
	///*friend MySet operator+(MySet& s1, MySet& s2) {
	//	MySet buf;
	//	for (int i = 0; i < s1.size; i++) {
	//		buf.add_element(s1.pdata[i]);
	//	}
	//	for (int i = 0; i < s2.size; i++) {
	//		buf.add_element(s2.pdata[i]);
	//	}
	//	

	//	return buf;
	//}*/

	//
	//

	///*friend MySet operator*(MySet& s1, MySet& s2) {
	//	MySet buf;
	//	for (int i = 0; i < s1.size; i++) {
	//		for (int j = 0; j < s2.size; j++) {
	//			if (strcmp(s1.pdata[i], s2.pdata[j]) == 0) {
	//				buf.add_element(s1.pdata[i]);
	//			}
	//		}
	//	}
	//	return buf;
	//}*/

	//bool operator==(MySet<T>& s) {
	//	MyVector<T>::sort();
	//	s.MyVector<T>::sort();
	//	if (size != s.size) {
	//		return false;
	//	}

	//	for (int i = 0; i < size; i++) {
	//		if ((*this)[i] == s[i]) {
	//			return false;
	//		}
	//	}
	//	return true;
	//}


	///*MySet& operator+=(MySet& s);
	//MySet& operator-=(MySet& s);
	//MySet& operator*=(MySet& s);*/

	////void sett() {
	////	for (int i = 0; i < size - 1; i++) {
	////		for (int j = i + 1; j < size; i++) {
	////			if (strcmp(pdata[i], pdata[j]) == 0){
	////				delete_element(s1.pdata[i]);
	////			}
	////		}
	////	}

	////}

	//
	void add_element(T el); 
	//	bool flag = 0;
	//	for (int i = 0; i < size; i++) {
	//		if ((*this)[i] == el)
	//		{
	//			flag = true;
	//			break;
	//		}
	//	}
	//	if (!flag) {
	//		MyVector<T>::add_element(el);
	//	}
	//}

	void delete_element(T el);
	/*	
		int index = -1;
		for (int i = 0; i < size; i++) {
			if ((*this)[i] == el) {
				index = i;
				break;
			}
		}
		if (index != -1) {
			MyVector<T>::delete_element(index);
		}
	}*/

	//bool is_element(T el) {
	//	for (int i = 0; i < size; i++) {
	//		if ((*this)[i] == el) {
	//			return true;
	//		}
	//	}
	//	return false;
	//}

};





//=====================================================================

template <>
void MySet<char*>::add_element(char* el) {
	bool flag = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp((*this)[i],el) == 0){
			flag = true;
			break;
		}
	}
	if (!flag) {
		MyVector<char*>::add_element(el);
	}
}


template <typename T>
void MySet<T>::add_element(T el) {
		bool flag = 0;
		for (int i = 0; i < size; i++) {
			if ((*this)[i] == el)
			{
				flag = true;
				break;
			}
		}
		if (!flag) {
			MyVector<T>::add_element(el);
		}
	}


template <>
void MySet<char*>::delete_element(char* el) {

	int index = -1;
	for (int i = 0; i < size; i++) {
		if (strcmp((*this)[i], el) == 0) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		MyVector<char*>::delete_element(index);
	}
}

template<typename T>
void MySet<T>::delete_element(T el) {
	int index = -1;
	for (int i = 0; i < size; i++) {
		if ((*this)[i] == el) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		MyVector<T>::delete_element(index);
	}


}



template <typename T1>
MySet<T1> operator-(MySet<T1>& s1, MySet<T1>& s2) {
	MySet<T1> buf;
	buf = s1;
	for (int i = 0; i < s1.size; i++) {
		for (int j = 0; j < s2.size; j++) {
			if (s1[i] == s2[j]) {
				buf.delete_element(s1[i]);
			}
		}
	}
	return buf;
}

template <>
MySet<char*> operator-(MySet<char*>& s1, MySet<char*>& s2) {
	MySet<char*> buf;
	buf = s1;
	for (int i = 0; i < s1.size; i++) {
		for (int j = 0; j < s2.size; j++) {
			if (s1[i] == s2[j]) {
				buf.delete_element(s1[i]);
			}
		}
	}
	return buf;
}







//template<>
//void MySet<char*>::add_element(char* el) {
//	bool flag = 0;
//	for (int i = 0; i < size; i++) {
//		if (strcmp(pdata[i], el) == 0)
//		{
//			flag = true;
//			break;
//		}
//	}
//	if (!flag) {
//		MyVector<char*>::add_element(el);
//	}
//}
//




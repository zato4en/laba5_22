﻿
#include "MyVector.h"
#include "MySet.h"



using namespace std;

int main()
{
	setlocale(0, "russian");

	MyVector<int> lol;
	lol.add_element(10);
	lol.add_element(7);
	cout << lol;
	lol.delete_element(7);
	cout << lol;

	/*MySet<int> hui;
	MySet<int> pizda;
	hui.add_element(10);
	hui.add_element(8);*/

	/*MyVector<const char*> v("Hello!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	cout << "Вектор v: " << v << endl;
	v.add_element("Привет!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	cout << "Вектор v: " << v << endl;
	MyVector<const char*>  v1 = v;
	cout << "Вектор v1: " << v1 << endl;
	for (int i = 0; i < MAX_SIZE; i++)
		v1.delete_element(0);
	cout << "Вектор v1: " << v1 << endl;*/
	/*MySet<const char*>  s("Yes"), s1, s2;
	s.add_element("Привет!");
	s.add_element("No");
	const char* str = "Hello!";
	s.add_element(str);
	cout << "Множество s: " << s << endl;
	s1.add_element("Cat");
	s1.add_element("No");
	s1.add_element("Привет!");
	cout << "Множество s1: " << s1 << endl;
	s2 = (s1 - s);
	cout << "Множество s2=s1-s: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	s2 = (s - s1);
	cout << "Множество s2=s-s1: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	s2 = s1 + s;
	cout << "Множество s2=s1+s: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	s2 = s1 * s;
	cout << "Множество s2=s1*s: " << s2 << endl;
	cout << "========================================" << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	MySet<const char*>  s3 = s2;
	cout << "Множество s3=s2: " << s3 << endl;
	if (s3 == s2)
		cout << "Множество s3=s2\n";
	else
		cout << "Множество s3!=s2\n";
	if (s3 == s1)
		cout << "Множество s3=s1\n";
	else
		cout << "Множество s3!=s1\n";
	if (s1 == s3)
		cout << "Множество s1=s3\n";
	else
		cout << "Множество s1!=s3\n";*/
	return 0;
};

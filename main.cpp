

#include "MyVector.h"
#include "MySet.h"
#pragma warning


int main() {
    MyVector<char *> v("Hello!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    cout << "Вектор v:\n" << v << endl;
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    cout << "Вектор v:\n" << v << endl;
    MyVector<char *> v1 = v;
    cout << "Вектор v1:\n" << v1 << endl;
    for (int i = 0; i < MAX_SIZE; i++)
        v1.delete_element(0);
    cout << "Вектор v1:\n" << v1 << endl;


    MySet<char *> s1, s2;
    MySet<char *> s("Yes");
    s.add_element("Привет!");
    s.add_element("No");
    char *str = "Hello!";
    s.add_element(str);
    cout << "Множество s: \n" << s << endl;
    s1.add_element("Cat");
    s1.add_element("No");
    s1.add_element("Привет!");
    cout << "Множество s1: \n" << s1 << endl;
    s2 = s1 - s;
    cout << "Множество s2=s1-s:\n" << s2 << endl;
    cout << "Множество s1: \n" << s1 << endl;
    cout << "Множество s: \n" << s << endl;
    s2 = s - s1;
    cout << "Множество s2=s-s1: \n" << s2 << endl;
    cout << "Множество s1: \n" << s1 << endl;
    cout << "Множество s: \n" << s << endl;
    s2 = s1 + s;
    cout << "Множество s2=s1+s: \n" << s2 << endl;
    cout << "Множество s1: \n" << s1 << endl;
    cout << "Множество s: \n" << s << endl;
    s2 = s1 * s;
    cout << "Множество s2=s1*s: \n" << s2 << endl;
    cout << "Множество s1: \n" << s1 << endl;
    cout << "Множество s: \n" << s << endl;
    MySet<char *> s3 = s2;
    cout << "Множество s3=s2: \n" << s3 << endl;
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
        cout << "Множество s1!=s3\n\n";


    return 0;
}
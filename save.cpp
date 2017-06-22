#ifdef DEBUG
#include <iostream>
using namespace std;

class Shape
{
public:
	virtual double area() = 0;
	virtual void input() {};
	virtual void show() {};
};

class Circle : public Shape
{
public:
	double area()
	{
		return radius * radius * 3.14;
	}
	void input()
	{
		cin >> radius;
	}
	void show()
	{
		cout << "radius = " << radius << endl;
	}
private:
	double radius;
};

class Rectangle : public Shape
{
public:
	double area()
	{
		return width * length;
	}
	void input()
	{
		cin >> length >> width;
	}
	void show()
	{
		cout << "length = " << length << endl;
		cout << "width = " << width << endl;
	}
private:
	double width;
	double length;
};

int main()
{
	Shape *s[3];
	Rectangle r1;
	Rectangle r2;
	Circle c1;
	s[0] = &r1;
	s[1] = &r2;
	s[2] = &c1;

	for (int i = 0; i < 3; i++)
	{
		(*s[i]).input();
	}
	for (int i = 0; i < 3; i++)
	{
		(*s[i]).show();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << (*s[i]).area() << endl;
	}

	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();

	return 0;
}
#endif // DEBUG

#ifdef DEBUG
#include <iostream>

using namespace std;

template<typename T>
class Array
{
	friend ostream & operator << (ostream & os, const Array<T> & a)
	{
		os << "{" << a.p[0];
		for (int i = 1; i < a.size; i++)
		{
			os << "," << a.p[i];
		}
		os << "}" << endl;
		return os;
	}
	friend istream & operator >> (istream & is, Array<T> & a)
	{
		for (int i = 0; i < a.size; i++)
		{
			is >> a.p[i];
		}
		return is;
	}

public:
	Array()
	{
		p = new T[1];
		size = 0;
	}
	Array(T * q, int s)
	{
		size = s;
		p = new T[size];
		for (int i = 0; i < size; i++)
		{
			p[i] = q[i];
		}
	}
	Array(Array<T> & b)
	{
		size = b.size;
		p = new T[size];
		for (int i = 0; i < size; i++)
		{
			p[i] = b.p[i];
		}
	}
	~Array()
	{
		delete[]p;
	}

	T operator [](int i)
	{
		return p[i];
	}
	Array operator =(const Array<T> & b)
	{
		size = b.size;
		delete[]p;
		p = new T[size];
		for (int i = 0; i < size; i++)
		{
			p[i] = b.p[i];
		}
		return Array(p, size);
	}
	friend int operator == (const Array<T> & a1, const Array<T> & a2)
	{
		if (a1.size == a2.size)
		{
			for (int i = 0; i < a1.size; i++)
			{
				if (a1.p[i] != a2.p[i])
					return 0;
			}
		}
		return 1;
	}
private:
	T * p;
	int size;
};

int main()
{
	int a[3] = { 1,2,3 };
	Array<int> a1(a, 3);
	Array<int> a2(a1);
	cout << "hh" << endl;
	cout << a1;

	Array<int> a3;
	a3 = a1;
	if (a3 == a1)
		cout << "a3 = a1" << endl;

	Array<int> a4(a, 3);
	cin >> a4;
	cout << a4;

	getchar();
	getchar();
	getchar();
	return 0;
}
#endif // DEBUG

//�ļ����
#ifdef DEBUG
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	ofstream file;

	file.open("a.txt");
	file << "jfjfjjf";
	file.close();

	return 0;
}
#endif // DEBUG

//����
#ifdef DEBUG
#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
	friend ostream & operator << (ostream & os, Matrix<T> & mat)
	{
		os << "{";
		for (int i = 0; i < mat.n; i++)
		{
			for (int j = 0; j < mat.m; j++)
			{
				os << mat.p[i][j] << " ";
			}
		}
		os << "}" << endl;
		return os;
	}
public:
	Matrix(T** q, int a, int b) :n(a), m(b)
	{
		p = new T*[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = new T[m];
			for (int j = 0; j < m; j++)
			{
				p[i][j] = q[i][j];
			}
		}
	}
	Matrix(Matrix<T> & q)
	{
		p = new T*[q.n];
		for (int i = 0; i < q.n; i++)
		{
			p[i] = new T[q.m];
			for (int j = 0; j < q.m; j++)
			{
				p[i][j] = q.p[i][j];
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			delete[]p[i];
		}
	}
	T* operator [](int i)
	{
		return p[i];
	}
private:
	T** p;
	int m, n;
};

int main()
{
	int a1[2] = { 1,2 };
	int a2[2] = { 3,4 };
	int* a[2] = { a1,a2 };
	Matrix<int> mat1(a, 2, 2);
	Matrix<int> mat2(mat1);

	cout << mat1;
	cout << mat1[1][1] << endl;

	getchar(); getchar(); getchar(); getchar(); getchar();
	return 0;
}
#endif // DEBUG

#ifdef DEBUG
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int y = 0, int m = 0, int d = 0) :year(y), month(m), day(d) {}
	~Date() {}
	void Set(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void Show()
	{
		cout << year << "/" << month << "/" << day;
	}
	int IsPure()
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return 1;
		}
		return 0;
	}
private:
	int year;
	int month;
	int day;
};

int main()
{
	Date d1(2011, 3, 1);

	d1.Show();
	d1.Set(2016, 1, 1);
	d1.Show();

	if (d1.IsPure())
		cout << "����";

	getchar(); getchar(); getchar();
	return 0;
}
#endif // DEBUG

#ifdef DEBUG
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class String
{
	friend ostream & operator << (ostream & os, const String & s)
	{
		for (int i = 0; i < s.size; i++)
			os << s.p[i];
		cout << endl;
		return os;
	}
public:
	String()
	{
		p = new char[1];
		strcpy(p, "\0");
		size = 0;
	}
	String(char * a, int s = 0)
	{
		s = strlen(a);
		size = s;
		p = new char[size + 1];
		strcpy(p, a);
		//p[size] = '\0';
	}
	String(const String & s)
	{
		size = s.size;
		p = new char[size + 1];
		strcpy(p, s.p);
		//p[size] = '\0';
	}
	~String()
	{
		delete[]p;
	}
	char & operator [](int i)
	{
		return p[i];
	}
	String & operator = (const String & s)
	{
		if (s.p == p)
			return *this;
		delete[]p;
		size = s.size;
		p = new char[size + 1];
		strcpy(p, s.p);
		p[size] = '\0';
		return *this;
	}
	friend String operator + (String & str1, String & str2)
	{
		int size = str1.size + str2.size;
		char * str3 = new char[size + 1];
		for (int i = 0; i < str1.size; i++)
		{
			str3[i] = str1.p[i];
		}
		for (int i = 0; i < str2.size; i++)
		{
			str3[str1.size + i] = str2.p[i];
		}
		str3[size] = '\0';
		return String(str3, size);
	}

private:
	int size;
	char * p;
};

int main()
{
	char a[] = "1234";
	char b[] = "2345";
	String s1(a, 4);
	cout << a;
	cout << s1;

	s1 = s1;
	String s2(s1);
	s2 = s1;
	cout << s2;
	cout << s2[2];

	String s3(b, 4);
	cout << s3;
	s3 = s1;
	cout << s3;

	String s4;
	s4 = s1 + s2;
	cout << s4;

	getchar(); getchar(); getchar(); getchar(); getchar();
	return 0;
}

#endif // DEBUG

#ifdef DEBUG
#include <iostream>
using namespace std;

template <typename T>
class Set
{
public:
	friend ostream & operator << (ostream & os, const Set<T> & s)
	{
		for (int i = 0; i < s.size; i++)
		{
			os << s.p[i];
		}
		cout << endl;
		return os;
	}
	friend istream & operator >> (istream & is, Set<T> & s)
	{
		for (int i = 0; i < size; i++)
		{
			is >> s.p[i];
		}
	}
	Set()
	{
		p = new T[1];
		size = 0;
	}
	Set(T* q, int s)
	{
		size = s;
		p = new T[size];
		for (int i = 0; i < size; i++)
		{
			p[i] = q[i];
		}
	}
	Set(const Set<T> & s1)
	{
		size = s1.size;
		p = new T[size];
		for (int i = 0; i < size; i++)
		{
			p[i] = s1.p[i];
		}
	}
	~Set()
	{
		delete[]p;
	}
	int IsInSet(const T a)
	{
		for (int i = 0; i < size; i++)
		{
			if (p[i] == a)
				return i;
		}
		return -1;
	}
	Set<T> operator &&(Set<T> & s)
	{
		int minsize = size < s.size ? size : s.size;
		int num = 0;
		T* q = new T[minsize];
		for (int i = 0; i < size; i++)
		{
			if (s.IsInSet(p[i]) != -1)
			{
				q[num++] = p[i];
			}
		}

		return Set<T>(q, num);
	}
	Set<T> & operator = (const Set<T> & s)
	{
		if (this == &s)
			return *this;
		delete[]p;
		size = s.size;
		p = new T[size];
		for (int i = 0; i < size; i++)
		{
			p[i] = s.p[i];
		}
		return *this;
	}
private:
	T* p;
	int size;
};

int main()
{
	int a[] = { 1,2,3 };
	int b[] = { 2,3,4 };
	Set<int> s1(a, 3);
	Set<int> s2(b, 3);
	s1 = s1;
	cout << s1 << s2;

	Set<int> s3 = s1&&s2;
	cout << s3;

	getchar(); getchar(); getchar(); getchar(); getchar(); getchar(); getchar();
	return 0;
}
#endif // DEBUG

#include <iostream>
using namespace std;



int main()
{
	


	return 0;
}
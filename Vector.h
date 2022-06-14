#pragma once
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template<class T>
class Vector
{
	T* v;
	int size;
public:
	Vector(int newsize);
	Vector(Vector&);
	~Vector();

	T ext(const char*);
	Vector& sort(const char*);
	double norma(void);
	bool Dublikat();

	friend Vector<T> operator + <>(Vector<T>& x, Vector<T>& y);
	Vector<T>& operator += (Vector&);
	T& operator [](int index);
	Vector& operator = (const Vector&);

	friend ostream& operator << <>(ostream&, Vector&);
	friend istream& operator >> <>(istream&, Vector&);


};

template <class T>
Vector<T>::Vector(int newsize)
{
	v = new T[newsize];
	size = newsize;
	for (int i = 0; i < newsize; i++)
		v[i] = T();
}
template <class T>
Vector<T>::Vector(Vector<T>& x)
{
	v = new T[size = x.size];
	for (int i = 0; i < size; i++)
		v[i] = x.v[i];
}

template <class T>
Vector<T>::~Vector()
{
	delete[]v;
}

template <class T>
T Vector<T>::ext(const char* MinOrMax)
{
	T ExtrElem = v[0];
	for (int i = 0; i < size; i++) {
		if (!strcmp(MinOrMax, "min")) {
			if (v[i] < ExtrElem) ExtrElem = v[i]; // мінімальний елемент 
		}
		else
			if (v[i] > ExtrElem) ExtrElem = v[i]; // максимальний елемент
	}
	return ExtrElem;
}

template <class T>
Vector<T>& Vector<T>::operator += (Vector<T>& y)
{
	for (int i = 0; i < size; i++)
		v[i] += y.v[i];
	return *this;
}

template<class T>
T& Vector<T>::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
	return v[index];

}

template<class T>
Vector<T>& Vector<T>::sort(const char* UpOrDown)
{
	T x;
	for (int i = 0; i < size - 1; i++)
		for (int j = i + 1; j < size; j++)
			if (!strcmp(UpOrDown, "up"))
			{
				if (v[i] > v[j])
				{
					x = v[i];
					v[i] = v[j];
					v[j] = x;
				}
			}
			else
				if (v[i] < v[j])
				{
					x = v[i];
					v[i] = v[j];
					v[j] = x;
				}
	return *this;
}

template<class T>
double Vector<T>::norma(void)
{
	double S = 0;
	for (int i = 0; i < size; i++)
		S += v[i] * v[i];
	return sqrt(S);
}

template<class T>
bool Vector<T>::Dublikat()
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (v[i] == v[j]) {
				return 1;
			}
		}
	}
	return 0;
}

template <class T>
Vector<T> operator + (Vector<T>& x, Vector<T>& y)
{
	if (x.size != y.size)
	{
		throw exception("The sizes should be the same!");
	}
	Vector<T> z(x.size);
	for (int i = 0; i < x.size; i++)
		z.v[i] = x.v[i] + y.v[i];
	return z;
}


template <class T>
Vector<T>& Vector<T>::operator =(const Vector<T>& x)
{
	if (this != &x)
	{
		delete[]v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}

template <class T>
istream& operator >> (istream& is, Vector<T>& x)
{
	cout << "Input " << x.size << " elements of Vector" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] = ? ";
		is >> x.v[i];
	}
	return is;
}
template <class T>
ostream& operator << (ostream& os, Vector<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}


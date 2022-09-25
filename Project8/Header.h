#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
    T* arr;
    int size;
public:
    MyArray();
    MyArray(int s);
    //----------
    MyArray(const MyArray& obj);
    ~MyArray();
    MyArray& operator=(const MyArray& obj);
    //----------
    MyArray operator+(int a);
    bool operator>(const MyArray& a);
    void Print();
    void Random();
};

template<class T>
MyArray<T>::MyArray()
{
    arr = nullptr;
    size = 0;
}
template<class T>
MyArray<T>::MyArray(int s)
{
    arr = new T[s];
    size = s;
}
template<class T>
MyArray<T>::MyArray(const MyArray& obj)
{
    size = obj.size;
    arr = new T[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
}
template<class T>
MyArray<T>::~MyArray()
{
    delete[] arr;
    size = 0;
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& obj)
{
    if (this == &obj)// a=a
    {
        return this;
    }
    if (size > 0)
    {
        this->~MyArray(); // delete[] arr;
    }

    size = obj.size;
    arr = new T[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }

    return *this;
}

template<class T>
MyArray<T> MyArray<T>::operator+(int a)
{
    MyArray obj(size);

    for (int i = 0; i < size; i++)
    {
        obj.arr[i] = arr[i] + a;
    }
    return obj;
}

template<class T>
bool MyArray<T>::operator>(const MyArray& a)
{
    if (size > a.size)
    {
        return true;
    }
    else
        return false;
}

template<class T>
void MyArray<T>::Print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

template<class T>
void MyArray<T>::Random()
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 50 * 1.5;
    }
}

template<class T>
MyArray<T> operator+(int a, MyArray<T> obj)
{
    MyArray<T> rez = obj + a;
    return rez;
}
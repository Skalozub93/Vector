#pragma once

#include <iostream>
#include <algorithm>
using namespace std;
#define DEFAULT_CAPACITY 10
class Vector
{
	int* arr = nullptr;
	int size = 0;
	int capacity = DEFAULT_CAPACITY;
public:

	Vector() : Vector(10) {};
	Vector(unsigned int capacity);
	~Vector();

	void RemoveByIndex(int k);
	void RemoveByValue(int N);
	void PopFront();
	void PopBack();
	void TrimToSize();
	int IndexOf(int value);
	int LastIndexOf(int value);
	void Reverse();
	void SortAsc();
	void SortDesc();
	void Shuffle();
	void RandomFill(int N);
	void Equals();
	int GetSize() const;
	int GetCapacity() const;
	void Print();

	Vector& operator = (const Vector& other);
	int operator[](int index);

	bool operator ==(const Vector& other);
	friend istream& operator>>(istream& cin, Vector& other);
	friend ostream& operator<<(ostream& os, const Vector& original);
};

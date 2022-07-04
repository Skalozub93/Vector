#include <iostream>
#include <algorithm>
using namespace std;

class Vector
{
	int* arr;
	int size;
	int capacity;
public:
	Vector()
	{
		arr = new int[50];
		capacity = 50;
		size = 0;
	}
	Vector(Vector& value) : size(value.size), capacity(value.capacity)
	{
		arr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			arr[i] = value.arr[i];
		}
	}

	void RemoveByIndex(int k)
	{
		for (int i = k; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}
	void RemoveByValue(int N)
	{
		for (int i = 0; i < size; i++)
		{
			if (N == arr[i])
			{
				RemoveByIndex(i);
			}
		}
	}
	void PopFront()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}
	void PopBack()
	{
		size--;
	}
	void TrimToSize()
	{
		int* temp = new int[size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;

		arr = temp;
		capacity = size;
		delete[] temp;
	}
	int IndexOf(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value) return i;
			else - 1;
		}
	}
	int LastIndexOf(int value)
	{
		for (int i = size; i >= 0; i--)
		{
			if (arr[i] == value)
			{
				if (arr[i] == value) return i;
				else - 1;
			}
		}
	}
	void Reverse()
	{
		int temp;
		for (int i = 0; i < size / 2; i++)
		{
			temp = arr[i];
			arr[i] = arr[size - 1 - i];
			arr[size - 1 - i] = temp;
		}
	}
	void SortAsc()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	void SortDesc()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (arr[j] < arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}
	void Shuffle()
	{
		for (int i = 0; i < size; i++)
		{
			swap(arr[i], arr[rand() % size]);
		}
	}
	void RandomFill(int N)
	{
		if (N <= capacity)
		{
			for (int i = 0; i < N; i++)
			{
				arr[i] = rand() % 10;
				size++;
			}
		}
		else
		{
			throw "elements more than size";
		}
	}
	void Equals()
	{

	}
	int GetSize() const
	{
		return size;
	}
	int GetCapacity() const
	{
		return capacity;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}
};

int main()
{
	Vector a;
	a.RandomFill(10);
	//a.SortAsc();
	//a.SortDesc();
	//a.Shuffle();
	a.Print();

}
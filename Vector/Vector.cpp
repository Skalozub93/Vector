#include "Header1.h"
#define LIMIT_CAPACITY 10

	Vector::Vector(unsigned int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		arr = new int[capacity];
	}


	Vector::~Vector()
	{
		if (arr != nullptr)
		{
			delete[] arr;
			arr = nullptr;
		}
	}

	void Vector::RemoveByIndex(int k)
	{
		for (int i = k; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}
	void Vector::RemoveByValue(int N)
	{
		for (int i = 0; i < size; i++)
		{
			if (N == arr[i])
			{
				RemoveByIndex(i);
			}
		}
	}
	void Vector::PopFront()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}
	void Vector::PopBack()
	{

		size--;
	}
	void Vector::TrimToSize()
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
	int Vector::IndexOf(int value)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value) return i;
			else - 1;
		}
	}
	int Vector::LastIndexOf(int value)
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
	void Vector::Reverse()
	{
		int temp;
		for (int i = 0; i < size / 2; i++)
		{
			temp = arr[i];
			arr[i] = arr[size - 1 - i];
			arr[size - 1 - i] = temp;
		}
	}
	void Vector::SortAsc()
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
	void Vector::SortDesc()
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
	void Vector::Shuffle()
	{
		for (int i = 0; i < size; i++)
		{
			swap(arr[i], arr[rand() % size]);
		}
	}
	void Vector::RandomFill(int N)
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
	void Vector::Equals()
	{

	}
	int Vector::GetSize() const
	{
		return size;
	}
	int Vector::GetCapacity() const
	{
		return capacity;
	}
	void Vector::Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}

	Vector& Vector::operator = (const Vector &other)
	{
		if (this == &other)
		{
			return *this;
		}
		arr = other.arr;
		size = other.size;

		return *this;
	}

	int Vector::operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			return arr[0];
		}
		return arr[index];
	}

	bool Vector::operator ==(const Vector& other)
	{
		return this->arr == other.arr;
	}

	istream& operator>>(istream& cin, Vector& other)
	{
		delete[] other.arr;
		cout << "Enter size: ";
		cin >> other.size;
		cout << "Enter capacity: ";
		cin >> other.capacity;

		if (other.capacity > DEFAULT_CAPACITY)
		{
			other.capacity = 10;
		}
		other.arr = new int[other.capacity];
		for (int i = 0; i < other.size; i++)
		{
			cout << "Enter elements: ";
			cin >> other.arr[i];
			cout << "\n";
		}
		return cin;
	}

	ostream& operator<<(ostream& os, const Vector& original)
	{
		if (original.size == 0)
		{
			os << "Vector is empty";
		}
		for (int i = 0; i < original.size; i++)
		{
			os << original.arr[i] << " ";
		}
		os << "\n";
		os << "Size is - " << original.size;
		os << "Capacity - " << original.capacity;
		return os;
	}

int main()
{
	Vector a;
	a.RandomFill(10);
	//a.SortAsc();
	//a.SortDesc();
	//a.Shuffle();
	a.Print();
	
}
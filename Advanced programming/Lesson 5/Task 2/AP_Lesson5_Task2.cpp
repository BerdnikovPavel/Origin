#include <iostream>

template<class T>
class table
{
public:
	table(const int rows_count, const int columns_count): rows(rows_count), columns(columns_count)
	{
		arr = new T * [rows];
		for (int i = 0; i < rows; ++i)
		{
			arr[i] = new T[columns];
		}
	}

	~table()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
			delete[] arr;
	}

	const T operator[]( int a) const
	{
		return arr[a];
	}

	T* operator[](int a)
	{
		return arr[a];
	}

	int Size() const
	{
		return sizeof(T) * rows * columns;
	}

private:
	T** arr = nullptr;
	int rows = 0;
	int columns = 0;
};

int main(int argc, const char** argv)
{
	auto test = table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0] << std::endl;
}

#include <iostream>

class smart_array
{
private:
	int actual_size;
	int logical_size;
	int* arr;
public:
	smart_array& operator = (const smart_array& other)
	{
		if (&other != this)
		{
			if (actual_size < other.actual_size)
			{
				delete[]arr;
				arr = new int[other.actual_size];
				for (int i = 0; i < other.actual_size; ++i)
				{
					arr[i] = other.arr[i];
				}
			}
			else
			{
				for (int i = 0; i < other.actual_size; ++i)
				{
					arr[i] = other.arr[i];
				}
			}
			actual_size = other.actual_size;
			logical_size = other.logical_size;
		}
		return *this;
	}

	smart_array(int actual_size)
	{
		this->actual_size = actual_size;
		this->arr = new int[actual_size];
		this->logical_size = 0;
	}

	smart_array(const smart_array &other)
	{
		arr = new int[other.actual_size];
		for (int i = 0; i < other.actual_size; ++i)
		{
			arr[i] = other.arr[i];
		}
		actual_size = other.actual_size;
		logical_size = other.logical_size;
	}

	void add_element(int element)
	{
		if (logical_size == actual_size)
		{
			actual_size = actual_size * 2;
			int* new_arr = new int[actual_size];
			new_arr[logical_size] = element;
			for (int i = 0; i < logical_size; ++i)
			{
				new_arr[i] = arr[i];
			}
			++logical_size;
			delete[]arr;
			arr = new_arr;
		}
		else
		{
			arr[logical_size] = element;
			++logical_size;
		}
	}

	int get_element(int index)
	{
		if (index < 0 || index > logical_size - 1) throw std::exception("Неверный индекс!");
		return arr[index];
	}
	~smart_array()
	{
		delete[]arr;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
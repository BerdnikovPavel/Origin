#include <iostream>
#include <algorithm>

class smart_array 
{
private:
    int actual_size;
	int logical_size;
	int* arr;
public:
	smart_array(int actual_size)
	{
		this->actual_size = actual_size;
		this->arr = new int[actual_size];
		this->logical_size = 0;
	}

	int add_element(int element)
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
			return *new_arr;
		}
		else
		{
			arr[logical_size] = element;
			++logical_size;
			return *arr;
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
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
		std::cout << arr.get_element(4) << std::endl;
		arr.add_element(20);
		arr.add_element(30);
		std::cout << arr.get_element(5) << std::endl;
		std::cout << arr.get_element(8) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}



#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <locale.h>
#include <windows.h>

class Address
{
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    Address(std::string city, std::string street, int houseNumber, int apartmentNumber)
    {
        this->city = city;
        this->street = street;
        this->houseNumber = houseNumber;
        this->apartmentNumber = apartmentNumber;
    }

    Address()
    {
        city = "Неизвестно";
        street = "Неизвестно";
        houseNumber = 0;
        apartmentNumber = 0;
    }

    std::string get_output_address()
    {
        std::string house = std::to_string(houseNumber);
        std::string apartment = std::to_string(apartmentNumber);
        return city + ", " + street + ", " + house + ", " + apartment;
    }
};

void sort(Address*arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0 ; j < size - i - 1; ++j)
        {
            if (arr[j].get_output_address().compare(arr[j + 1].get_output_address()) > 0)
            {
                Address tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    int size = 0;
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    if (fin.is_open())
    {
        fin >> size;
    }
    else
    {
        std::cout << "Error. File cannot be opened";
    }

    std::string city;
    std::string street;
    int houseNumber = 0;
    int apartmentNumber = 0;
    Address* arr = new Address[size];
    for (int i = 0; i < size; ++i)
    {
        fin >> city;
        fin >> street;
        fin >> houseNumber;
        fin >> apartmentNumber;
        arr[i] = Address(city, street, houseNumber, apartmentNumber);
    }

    sort(arr, size);

    fout << size << std::endl;
    for (int i = 0; i < size; ++i)
    {
        fout << arr[i].get_output_address() << std::endl;
    }

    fin.close();
    fout.close();
    delete[]arr;
    arr = nullptr;
    return 0;
}

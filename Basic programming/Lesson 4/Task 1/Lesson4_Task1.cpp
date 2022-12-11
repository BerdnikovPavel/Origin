
#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>

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

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

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
    Address*arr = new Address[size];
    for (int i = 0; i < size; ++i)
    {
        fin >> city;
        fin >> street;
        fin >> houseNumber;
        fin >> apartmentNumber;
        arr[i] = Address(city, street, houseNumber, apartmentNumber);
    }

    fout << size << std::endl;
    for (int i = (size - 1); i >= 0; --i)
    {
        fout << arr[i].get_output_address() << std::endl;
    }

    fin.close();
    fout.close();
    delete[]arr;
    arr = nullptr;
    return 0;
}

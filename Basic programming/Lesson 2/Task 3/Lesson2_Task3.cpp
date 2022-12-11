
#include <iostream>

struct Address
{
    std::string m_country;
    std::string m_city;
    std::string m_street;
    int m_houseNumber;
    int m_apartmentNumber;
    int m_index;
};

void printAddress(Address p)
{
    std::cout << "Страна: " << p.m_country << std::endl
            << "Город: " << p.m_city << std::endl
            << "Улица: " << p.m_street << std::endl
            << "Номер дома: " << p.m_houseNumber << std::endl
            << "Номер квартиры: " << p.m_apartmentNumber << std::endl
            << "Индекс: " << p.m_index << std::endl << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    Address one{ "Россия", "Москва", "Арбат", 12, 8, 123456 }, 
            two{ "Россия", "Ижевск", "Пушкинская", 59, 143, 953769 };

    printAddress(one);
    printAddress(two);

    return 0;
}

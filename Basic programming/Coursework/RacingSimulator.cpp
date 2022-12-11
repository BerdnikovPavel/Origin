#include <iostream>

#include <windows.h>

#include "Class_GroundTransport.h"
#include "Class_Centaur.h"
#include "Class_Camel.h"
#include "Class_GroundTransport.h"
#include "Class_FastCamel.h"
#include "Class_AirTransport.h"
#include "Class_Eagle.h"
#include "Class_Broom.h"
#include "Class_MagicCarpet.h"
#include "Class_Race.h"
#include "Class_Transport.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int command3 = 0;
    int distance = 0;
    int raceType = 0;
    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
    do
    {
        int racersCount = 0;
        Centaur centaur;
        Camel camel;
        AllterrainBoots allterrainBoots;
        FastCamel fastCamel;
        MagicCarpet magicCarpet;
        Eagle eagle;
        Broom broom;

        do
        {
            std::cout << "1. Гонка для наземного транспорта" << std::endl << "2. Гонка для воздушного транспорта"
                << std::endl << "3. Гонка для наземного и воздушного транспорта" << std::endl << "Выберите тип гонки: ";
            std::cin >> raceType;
            if (raceType > 3 || raceType <= 0)
            {
                std::cout << "Неверная команда" << std::endl;
            }
            std::cout << std::endl;
        } while (raceType > 3 || raceType <= 0);

        do
        {
            std::cout << "Укажите длину дистанции (должна быть положительна): ";
            std::cin >> distance;
            if (distance < 0)
            {
                std::cout << "Дистанция не может быть меньше нуля!" << std::endl;
            }
        } while (distance < 0);

        int command1 = 0;
        do
        {
            std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl << "1. Зарегистрировать транспорт"
                << std::endl << "Выберите действие: ";
            std::cin >> command1;
            std::cout << std::endl;
            if (command1 != 1)
            {
                std::cout << "Неверная команда" << std::endl;
            }
        } while (command1 != 1);

        int command2 = 0;
        int command4 = 0;
        std::string registeredTS = "Зарегистрированные транспортные средства: ";
        Transport* arr[7]{ &centaur, &camel, &allterrainBoots, &fastCamel, &magicCarpet, &eagle, &broom };
        Race raceStart("none");

        do
        {
            if (raceType == 1)
            {
                Race groundRace("Гонка для наземного транспорта");
                raceStart = groundRace;
            }
            else if (raceType == 2)
            {
                Race airRace("Гонка для воздушного транспорта");
                raceStart = airRace;
            }
            else
            {
                Race groundAndAirRace("Гонка для наземного и воздушного транспорта");
                raceStart = groundAndAirRace;
            }

            std::cout << raceStart.get_name() << " Расстояние: " << distance << std::endl;
            std::cout << registeredTS << std::endl;
            std::cout << "1. " << allterrainBoots.get_name() << std::endl << "2. " << broom.get_name() << std::endl 
                << "3. " << camel.get_name() << std::endl << "4. " << centaur.get_name() << std::endl << "5. " 
                << eagle.get_name() << std::endl << "6. " << fastCamel.get_name() << std::endl
                << "7. " << magicCarpet.get_name() << std::endl << "0. Закончить регистрацию" << std::endl
                << "Выберите транспорт или 0 для окончания процесса регистрации: ";
            std::cin >> command2;
            std::cout << std::endl;

            switch (command2)
            {
            case 1:
                if (allterrainBoots.get_isRegistered() == 0 && (allterrainBoots.get_transportType() == raceType || raceType == 3))
                {
                    allterrainBoots.set_isRegistered(true);
                    arr[racersCount] = &allterrainBoots;
                    std::cout << allterrainBoots.get_name() << " успешно зарегистрирован!" << std::endl;
                    if (racersCount == 0) { registeredTS = registeredTS + allterrainBoots.get_name(); }
                    else { registeredTS = registeredTS + ", " + allterrainBoots.get_name(); }
                    ++racersCount;
                }
                else if (allterrainBoots.get_isRegistered() == 1 && (allterrainBoots.get_transportType() == raceType || raceType == 3))
                {
                    std::cout << allterrainBoots.get_name() << " уже зарегистрирован!" << std::endl;
                }
                else
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                }
                break;

            case 2:
                if (broom.get_isRegistered() == 0 && (broom.get_transportType() == raceType || raceType == 3))
                {
                    broom.set_isRegistered(true);
                    arr[racersCount] = &broom;
                    std::cout << broom.get_name() << " успешно зарегистрирован!" << std::endl;
                    if (racersCount == 0) { registeredTS = registeredTS + broom.get_name(); }
                    else { registeredTS = registeredTS + ", " + broom.get_name(); }
                    ++racersCount;
                }
                else if (broom.get_isRegistered() == 1 && (broom.get_transportType() == raceType || raceType == 3))
                {
                    std::cout << broom.get_name() << " уже зарегистрирован!" << std::endl;
                }
                else
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                }
                break;

            case 3:
                if (camel.get_isRegistered() == 0 && (camel.get_transportType() == raceType || raceType == 3))
                {
                    camel.set_isRegistered(true);
                    arr[racersCount] = &camel;
                    std::cout << camel.get_name() << " успешно зарегистрирован!" << std::endl;
                    if (racersCount == 0) { registeredTS = registeredTS + camel.get_name(); }
                    else { registeredTS = registeredTS + ", " + camel.get_name(); }
                    ++racersCount;
                }
                else if (camel.get_isRegistered() == 1 && (camel.get_transportType() == raceType || raceType == 3))
                {
                    std::cout << camel.get_name() << " уже зарегистрирован!" << std::endl;
                }
                else
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                }
                break;

            case 4:
                if (centaur.get_isRegistered() == 0 && (centaur.get_transportType() == raceType || raceType == 3))
                {
                    centaur.set_isRegistered(true);
                    arr[racersCount] = &centaur;
                    std::cout << centaur.get_name() << " успешно зарегистрирован!" << std::endl;
                    if (racersCount == 0) { registeredTS = registeredTS + centaur.get_name(); }
                    else { registeredTS = registeredTS + ", " + centaur.get_name(); }
                    ++racersCount;
                }
                else if (centaur.get_isRegistered() == 1 && (centaur.get_transportType() == raceType || raceType == 3))
                {
                    std::cout << centaur.get_name() << " уже зарегистрирован!" << std::endl;
                }
                else
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                }
                break;

            case 5:
                if (eagle.get_isRegistered() == 0 && (eagle.get_transportType() == raceType || raceType == 3))
                {
                    eagle.set_isRegistered(true);
                    arr[racersCount] = &eagle;
                    std::cout << eagle.get_name() << " успешно зарегистрирован!" << std::endl;
                    if (racersCount == 0) { registeredTS = registeredTS + eagle.get_name(); }
                    else { registeredTS = registeredTS + ", " + eagle.get_name(); }
                    ++racersCount;
                }
                else if (eagle.get_isRegistered() == 1 && (eagle.get_transportType() == raceType || raceType == 3))
                {
                    std::cout << eagle.get_name() << " уже зарегистрирован!" << std::endl;
                }
                else
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                }
                break;

            case 6:
                if (fastCamel.get_isRegistered() == 0 && (fastCamel.get_transportType() == raceType || raceType == 3))
                {
                    fastCamel.set_isRegistered(true);
                    arr[racersCount] = &fastCamel;
                    std::cout << fastCamel.get_name() << " успешно зарегистрирован!" << std::endl;
                    if (racersCount == 0) { registeredTS = registeredTS + fastCamel.get_name(); }
                    else { registeredTS = registeredTS + ", " + fastCamel.get_name(); }
                    ++racersCount;
                }
                else if (fastCamel.get_isRegistered() == 1 && (fastCamel.get_transportType() == raceType || raceType == 3))
                {
                    std::cout << fastCamel.get_name() << " уже зарегистрирован!" << std::endl;
                }
                else
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                }
                break;

            case 7:
                if (magicCarpet.get_isRegistered() == 0 && (magicCarpet.get_transportType() == raceType || raceType == 3))
                {
                    magicCarpet.set_isRegistered(true);
                    arr[racersCount] = &magicCarpet;
                    std::cout << magicCarpet.get_name() << " успешно зарегистрирован!" << std::endl;
                    if (racersCount == 0) { registeredTS = registeredTS + magicCarpet.get_name(); }
                    else { registeredTS = registeredTS + ", " + magicCarpet.get_name(); }
                    ++racersCount;
                }
                else if (magicCarpet.get_isRegistered() == 1 && (magicCarpet.get_transportType() == raceType || raceType == 3)) 
                { 
                    std::cout << magicCarpet.get_name() << " уже зарегистрирован!" << std::endl;
                }
                else
                {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
                }
                break;

            case 0:
                if (racersCount < 2)
                {
                    do
                    {
                        std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl << "1. Зарегистрировать транспорт"
                            << std::endl << "Выберите действие: ";
                        std::cin >> command1;
                        std::cout << std::endl;
                        if (command1 != 1)
                        {
                            std::cout << "Неверная команда" << std::endl;
                        }
                    } while (command1 != 1);
                    break;
                }
                else
                {
                    do
                    {
                        std::cout << "1. Зарегистрировать" << std::endl << "2. Начать гонку" << std::endl << "Выберите действие: ";
                        std::cin >> command4;
                        if (command4 != 1 && command4 != 2)
                        {
                            std::cout << "Неверная команда" << std::endl;
                        }
                        std::cout << std::endl;
                    } while (command4 != 2 && command4 != 1);
                    break;
                }

            default:
                std::cout << "Попытка зарегистрировать неправильный тип транспортного средства" << std::endl;
            }
        } while (command2 != 0 || racersCount < 2 || command4 == 1);

        Race race(racersCount, distance);
        race.RaceResultCalculation(arr);
        std::cout << std::endl << "Результаты гонки:" << std::endl;

        for (int i = 0; i < racersCount; ++i)
        {
            std::cout << i + 1 << ". " << arr[i]->get_name() << ". Время: " << arr[i]->resultCalculation(distance) << std::endl;
        }
    
        do
        {
            std::cout << std::endl << "1. Провести еще одну гонку" << std::endl << "2. Выйти" << std::endl << "Выберите действие: ";
            std::cin >> command3;
            if (command3 != 1 && command3 != 2)
            {
                std::cout << "Неверная команда" << std::endl;
            }
            std::cout << std::endl;
        } while (command3 != 2 && command3 != 1);
    } while (command3 != 2);
    return 0;
}

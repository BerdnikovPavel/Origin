#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <windows.h>

class Ini_parser
{
private:
    std::string file_name;
    std::map <std::pair<std::string, std::string>, std::string> file_content;
    std::string section;
    std::string var_name;
    std::string var_value;
    std::pair<std::string, std::string> key;
public:
    Ini_parser(std::string file_name)
    {
        this->file_name = file_name;
        std::ifstream fin(file_name);
        std::string line;
        if (fin.is_open())
        {
            while (!fin.eof())
            {
                line = "";
                std::getline(fin, line);
                if (line.find(';') != std::string::npos)
                {
                    const auto pos = line.find_first_of(';');
                    line.erase(pos);

                }
                if (line.empty()) { continue; }
                else if (std::count(line.begin(), line.end(), ' ') == line.length()) { continue; }
                else if (line.find('[') != std::string::npos)
                {
                    var_name = "";
                    var_value = "";
                    section = "";
                    const auto firstBracketIndex = line.find_first_of('[');
                    const auto lastBracketIndex = line.find_first_of(']');
                    for (auto i = firstBracketIndex + 1; i < lastBracketIndex; ++i) { section += line[i]; }
                }

                else
                {
                    var_name = "";
                    var_value = "";
                    const auto firstEqualIndex = line.find_first_of('=');
                    for (auto i = 0; i < firstEqualIndex; ++i) { var_name += line[i]; }
                    var_name.erase(std::remove_if(var_name.begin(), var_name.end(), ::isspace), var_name.end());
                    const auto endOfLine = line.find_last_not_of('\n');
                    for (auto i = firstEqualIndex + 1; i <= endOfLine; ++i) { var_value += line[i]; }
                    var_value.erase(std::remove_if(var_value.begin(), var_value.end(), ::isspace), var_value.end());
                }

                if (section != "" && var_name != "")
                {
                    key = std::make_pair(section, var_name);
                    file_content.insert({ key, var_value });
                }
            }
        }
        else throw std::exception("Файл не удалось открыть!");

        fin.close();
    }

    template <class T> T get_value(std::string address)
    {
        std::string section_name = "";
        std::string variable_name = "";
        const auto point = address.find_first_of('.');
        for (auto i = 0; i < point; ++i) { section_name += address[i]; }
        for (auto i = point + 1; i < address.length(); ++i) { variable_name += address[i]; }
        std::pair<std::string, std::string> key = std::make_pair(section_name, variable_name);
        T value = NULL;
        bool is_num = false;
        if (file_content[key] == "") throw std::exception("В файле нет значения для этой переменной");
        auto end = file_content[key].end();
        auto i = file_content[key].begin();
        if (*i == '-' || *i == '+' || (*i >= '0' && *i <= '9'))
        {
            ++i;
            for (; i != end; ++i)
            {
                if (*i >= '0' && *i <= '9') { continue; }
                else if (*i == '.' && i != file_content[key].begin()) { continue; }
                else { is_num = false; }
            }
            is_num = true;
        }

        if (is_num)
        {
            std::istringstream(file_content[key]) >> value;
        }
        else throw std::exception("Запрашиваемый тип переменной не соответствует типу переменной в файле");
        return value;
    }

    template<>
    std::string get_value(std::string address)
    {
        std::string section_name = "";
        std::string variable_name = "";
        const auto point = address.find_first_of('.');
        for (auto i = 0; i < point; ++i) { section_name += address[i]; }
        for (auto i = point + 1; i < address.length(); ++i) { variable_name += address[i]; }
        std::pair<std::string, std::string> key = std::make_pair(section_name, variable_name);
        if (file_content[key] == "") throw std::exception("В файле нет значения для этой переменной");
        bool is_num = false;
        auto end = file_content[key].end();
        auto i = file_content[key].begin();
        if (*i == '-' || *i == '+' || (*i >= '0' && *i <= '9'))
        {
            ++i;
            for (; i != end; ++i)
            {
                if (*i >= '0' && *i <= '9') { continue; }
                else if (*i == '.' && i != file_content[key].begin()) { continue; }
                else { is_num = false; }
            }
            is_num = true;
        }

        if (is_num) throw std::exception("Запрашиваемый тип переменной не соответствует типу переменной в файле");
        return file_content[key];
    }
};

int main(int  argc, char** argv)
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Ini_parser parser("INI.txt");
    try
    {
        auto value1 = parser.get_value<double>("Section1.var1");
        std::cout << value1 << std::endl;
        auto value2 = parser.get_value<std::string>("Section1.var2");
        std::cout << value2 << std::endl;
        auto value3 = parser.get_value<int>("Section2.var1");
        std::cout << value3 << std::endl;
        auto value4 = parser.get_value<std::string>("Section1.var2");
        std::cout << value4 << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
    
    return 0;
}
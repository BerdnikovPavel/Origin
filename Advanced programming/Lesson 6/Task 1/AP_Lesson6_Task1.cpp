#include <iostream>
#include <map>

int main()
{
    std::map<char, int> m;
    std::string line = "Hello world!!";
    std::cout << "[IN]: " << line << std::endl;

    for (const auto& element : line)
    {
        m.insert({ element, std::count(line.begin(), line.end(), element) });
    }

    std::multimap<int, char, std::greater<int>> reverse_m;

    for (const auto element : m) 
    {
        reverse_m.insert({ element.second, element.first });
    }

    std::cout << "[OUT]: " << std::endl;

    for (const auto& element : reverse_m) {
        std::cout << element.second << ": " << element.first << std::endl;
    }

    return 0;
}
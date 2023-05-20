#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class PrintToConsole : public LogCommand {
public:
    PrintToConsole() {}
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class PrintToFile : public LogCommand {
public:
    PrintToFile(){}
    void print(const std::string& message) override {
        std::ofstream file("file.txt");
        if (file.is_open())
        {
            file << message << std::endl;
        }
        else
        {
            std::cout << "Error";
        }
        file.close();
    }
};

void print(LogCommand& x, std::string message) {
    x.print(message);
}

int main()
{
    PrintToConsole* pts = new PrintToConsole;
    print(*pts, "Print to console");
    PrintToFile* ptf = new PrintToFile;
    print(*ptf, "Print to file");
    return 0;
}
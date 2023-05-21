#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string printAs() const = 0;
};

class PrintableText : public Printable
{
public:
    PrintableText(std::string data) : data_(std::move(data)) {}
    std::string printAs() const override
    {
        return data_;
    }
private:
    std::string data_;
};

class PrintableHTML : public Printable
{
public:
    PrintableHTML(std::string data) : data_(std::move(data)) {}
    std::string printAs() const override
    {
        return "<html>" + data_ + "<html/>";
    }
private:
    std::string data_;
};

class PrintableJSON : public Printable
{
public:
    PrintableJSON(std::string data) : data_(std::move(data)) {}
    std::string printAs() const override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }
private:
    std::string data_;
};

void saveTo(std::ofstream& file, const Printable& printable)
{
        file << printable.printAs();
}

void saveToAsHTML(std::ofstream& file, const PrintableHTML& printable) {
    saveTo(file, printable);
}

void saveToAsJSON(std::ofstream& file, const PrintableJSON& printable) {
    saveTo(file, printable);
}

void saveToAsText(std::ofstream& file, const PrintableText& printable) {
    saveTo(file, printable);
}

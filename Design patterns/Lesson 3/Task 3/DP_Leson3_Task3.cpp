#include <iostream>
#include <fstream>

enum class Type {
    FatalError,
    Error,
    Warning,
    UnknownError
};

class LogMessage {
public:
    LogMessage(std::string message, Type type) : message_(message), type_(type) {}
    Type type() const
    {
        return type_;
    }
    const std::string& message() const
    {
        return message_;
    }
private:
    std::string message_;
    Type type_;
};

class Handler {
public:
    Handler() : nextHandler(nullptr){}
    virtual void setNextHandler(Handler* handler)
    {
        this->nextHandler = handler;
    }
    void add(Handler* handler)
    {
        if (nextHandler) { nextHandler->add(handler); }
        else { nextHandler = handler; }
    }

    virtual void handle(LogMessage lm)
    {
        this->nextHandler->handle(lm);
    }
private:
    Handler* nextHandler;
};

class FatalErrorHandler : public Handler {
public:
    void handle(LogMessage lm) override
    {
        if (lm.type() == Type::FatalError)
        {
            throw std::runtime_error("Fatal Error: " + lm.message());
        }
        else
        {
            Handler::handle(lm);
        }
    }
};

class ErrorHandler : public Handler {
public:
    void handle(LogMessage lm) override
    {
        if (lm.type() == Type::Error)
        {
            std::ofstream file("error.txt");
            if (file.is_open())
            {
                file << "Error: " << lm.message() << std::endl;
            }
            file.close();
        }
        else
        {
            Handler::handle(lm);
        }
    }
};

class WarningHandler : public Handler {
public:
    void handle(LogMessage lm) override
    {
        if (lm.type() == Type::Warning)
        {
            std::cout << "Warning: " << lm.message() << std::endl;
        }
        else
        {
            Handler::handle(lm);
        }
    }
};

class UnknownErrorHandler : public Handler {
public:
    void handle(LogMessage lm) override
    {
        if (lm.type() == Type::UnknownError)
        {
            throw std::runtime_error("UnknownError: Message not processed");
        }
    }
};



int main()
{
    try
    {
        FatalErrorHandler feHandler;
        ErrorHandler eHandler;
        WarningHandler wHandler;
        UnknownErrorHandler ueHandler;

        feHandler.add(&eHandler);
        feHandler.add(&wHandler);
        feHandler.add(&ueHandler);
        ueHandler.setNextHandler(&feHandler);

        LogMessage lm("some error", Type::UnknownError);

        feHandler.handle(lm);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>
#include <ctime>
#include <sstream>

class Logger
{
public:
    static Logger &getInstance();
    void log(const std::string &message);

private:
    Logger();
    ~Logger();
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    std::string getTime();
    std::ofstream logfile;
    std::mutex mtx;
};

#endif // LOGGER_H

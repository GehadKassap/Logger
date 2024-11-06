#include "logger.h"
#include <thread>
#include <iostream>

void testLog()
{
    Logger::getInstance().log("Message from thread.. " + std::to_string(std::this_thread::get_id()));
}

int main()
{
    std::thread t1(testLog);
    std::thread t2(testLog);
    std::thread t3(testLog);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Logs have been written to Logfile.log.. " << std::endl;
    return 0;
}

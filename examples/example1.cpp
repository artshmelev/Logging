#include <iostream>
#include <thread>
#include <vector>

#include "logging.h"

void func(int id)
{
    for (int i = 0; i < 30; ++i)
        logging::info("I am thread " + std::to_string(id));
}

int main()
{
    logging::setConfig("log.txt", logging::kDebug);

    int p = 45;
    double d = 4.0;
    logging::info("Starting logging");
    logging::error("Test ERROR message");
    logging::crit("Test CRITICAL message");
    logging::warn("p = " + std::to_string(p));
    logging::info("d = " + std::to_string(d));

    for (int i = 0; i < 20; ++i)
        logging::debug("1234567");

    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i)
        threads.push_back(std::thread(func, i));

    logging::info("Main thread info");

    for (auto& t: threads)
        t.join();

    logging::info("Finishing logging");

    return 0;
}


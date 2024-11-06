# LoggerProject

## Description

This project contains a thread-safe Logger class in C++ that allows multiple processes to log messages to a single file in a synchronized way. The Logger class uses a singleton pattern to ensure only one instance of the logger is created. It uses a mutex to allow thread-safe logging, so multiple threads can log messages without data races. Each log entry is prefixed with a timestamp in the format `YYYY-MM-DD HH:MM:SS`.

## Folder Structure

- **include/**: Contains the `Logger.h` header file with the Logger class definition.
- **src/**: Contains `Logger.cpp`, the implementation of the Logger class.
- **test/**: Contains `LoggerTest.cpp`, which demonstrates usage and tests the Logger class.
- **logs/**: Contains `Logfile.log`, where log messages are stored.

## How to Run

1. Compile the code:
   ```bash
   g++ -std=c++11 -pthread src/Logger.cpp test/LoggerTest.cpp -o LoggerTest
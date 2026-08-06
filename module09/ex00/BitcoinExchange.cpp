#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : db(other.db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        db = other.db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& path) {
    std::ifstream file(path.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");
    std::string line;
    std::getline(file, line); // skip first line "date,exchange_rate"
    while (std::getline(file, line)) {
        std::size_t comma = line.find(',');
        if (comma == std::string::npos) continue;
        std::string date = line.substr(0, comma);
        double rate = std::strtod(line.substr(comma + 1).c_str(), NULL);
        db[date] = rate;
    }
}

bool BitcoinExchange::validDate(const std::string& date) const {
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) return false;
    }
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    int year = std::atoi(date.substr(0, 4).c_str());
    int dpm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leap) dpm[1] = 29;
    if (day > dpm[month - 1]) return false;
    return true;
}

double BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = db.lower_bound(date);
    // lower_bound returns first element with key >= date
    if (it == db.end() || it->first != date) {
        if (it == db.begin())
            throw std::runtime_error("Error: date before database range.");
        --it; // step back to nearest lower date
    }
    return it->second;
}

void BitcoinExchange::processInput(const std::string& path) const {
    std::ifstream file(path.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::cout.precision(12); // default is 6 digits, big prices would print as 4.71159e+07
    std::string line;
    if (std::getline(file, line) && line.substr(0, 4) != "date")
        file.seekg(0);
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::size_t pipe = line.find(" | ");
        if (pipe == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date   = line.substr(0, pipe);
        std::string valStr = line.substr(pipe + 3);
        if (!validDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        char*  end;
        double value = std::strtod(valStr.c_str(), &end);
        // nan is never equal to itself, and would pass both checks below
        if (end == valStr.c_str() || (*end != '\0' && *end != '\r') || value != value) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        try {
            double rate = getRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

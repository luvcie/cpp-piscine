#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
  private:
    std::map<std::string, double> db;

    void   loadDatabase(const std::string& path);
    bool   validDate(const std::string& date) const;
    double getRate(const std::string& date) const;

  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void processInput(const std::string& path) const;
};

#endif

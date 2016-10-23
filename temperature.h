#pragma once

#include <string>
#include <vector>
#include <unordered_map>

typedef std::unordered_map<std::string, std::vector<double>> records_by_station;

struct Record
{
    std::string station;
    double temperature;
};

class Data
{
protected:
    std::string filename;
    std::vector<Record> records;
public:
    Data(std::string f) : filename(f) { }

    void print();
    virtual void read() = 0;
    virtual void save(std::string filename, std::string sep = ";") = 0;

    virtual ~Data() {};
};

class TemperatureData : public Data
{
public:
    using Data::Data;

    void read();
    records_by_station to_map();
    void save(std::string filename, std::string sep = ";");

    ~TemperatureData() {};
};

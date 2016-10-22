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
    //records_by_station to_map();
    virtual void save(std::string filename, std::string sep = ";") = 0;
};

class TemperatureData : public Data
{

public:
    //TemperatureData(std::string f) : Data(f) { };
    using Data::Data;
    //void print();
    void read();
    records_by_station to_map();
    void save(std::string filename, std::string sep = ";");
};

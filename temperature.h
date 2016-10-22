#include <string>
#include <vector>
#include <unordered_map>

typedef std::unordered_map<std::string, std::vector<double>> records_by_station;

struct Record
{
    std::string station;
    double temperature;
};

// In C++, a structure is a class defined with the struct keyword.[1] Its members and base classes are public by default. A class defined with the class keyword has private members and base classes by default. This is the only difference between structs and classes in C++.
class TemperatureData
{
    std::string filename;
    std::vector<Record> records;
public:
    TemperatureData(std::string f) : filename(f) { }
    void print();
    void read();
    records_by_station to_map();
};

#include "temperature.h"
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>

void TemperatureData::print()
{
    std::cout << "Temperature data object of " << records.size() << " records." << std::endl;
}

void TemperatureData::read()
{
    std::string line;
    std::ifstream ifs(filename);

    // The function std::getline, like most iostreams operations, returns a reference to the stream object itself, which can be evaluated in a boolean context to tell you whether it is still good, i.e. whether the extraction operation succeeded.
    while(std::getline(ifs, line))
    {
        // size_t is an unsigned type. So, it cannot represent any negative values(<0). You use it when you are counting something, and are sure that it cannot be negative.  For example, strlen() returns a size_t because the length of a string has to be at least 0.
        size_t n_seps = std::count(line.begin(), line.end(), ';');

        if (n_seps == 1)
        {
            std::vector<std::string> fields;
            boost::split(fields, line, boost::is_any_of(";"));

            std::string station = fields.at(0);
            double temperature = std::stod(fields.at(1));

            std::cout << station << "\t" << temperature << std::endl;

            records.push_back({station, temperature});
        }

        else
        {
            std::cout << "\tWrong line found: " << line << std::endl ;
        }



    }

}

records_by_station TemperatureData::to_map()
{
    records_by_station m;

    for(auto value : records)
    {
        m[value.station].push_back(value.temperature);
    }

    std::cout << m.size() << " stations." << std::endl;

    return m;
}

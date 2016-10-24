#include "temperature.h"
#include "utils.h"

#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <typeinfo>
#include <chrono>

Data::Data(std::string f) : filename(f) { }

void Data::print() const
{
    std::cout << "Object of class " << typeid(*this).name() << " with " << records.size() << " records." << std::endl;
}

void TemperatureData::save(std::string filename, std::string sep) const
{
    std::ofstream myfile(filename);
    //myfile.open (filename);
    for(auto value : records) myfile << value.station << sep << value.temperature << std::endl;
    //myfile.close();
}

void TemperatureData::read()
{
    std::string line;
    std::ifstream ifs(filename);

    int good = 0;
    int bad = 0;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // The function std::getline, like most iostreams operations, returns a reference to the stream object itself, which can be evaluated in a boolean context to tell you whether it is still good, i.e. whether the extraction operation succeeded.
    while(std::getline(ifs, line))
    {
        // size_t is an unsigned type. So, it cannot represent any negative values(<0). You use it when you are counting something, and are sure that it cannot be negative.  For example, strlen() returns a size_t because the length of a string has to be at least 0.
        size_t n_seps = std::count(line.begin(), line.end(), ';');

        std::vector<std::string> fields;
        boost::split(fields, line, boost::is_any_of(";"));

        if (n_seps == 1 && is_number(fields.at(1)))
        {
            std::string station = fields.at(0);
            double temperature = std::stod(fields.at(1));

            std::cout << station << "\t" << temperature << std::endl;

            records.push_back({station, temperature});

            good++;
        }

        else
        {
            std::cout << FRED("BAD LINE") << " ("<< bad+good+1 << "): " << line << std::endl;
            bad++;
        }



    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() / 1e9;

    std::cout << boost::format("Read: %s lines  Skipped: %s lines In: %f seconds") % good % bad % duration << std::endl;

}

records_by_station TemperatureData::to_map() const
{
    records_by_station m;

    for(auto value : records)
    {
        m[value.station].push_back(value.temperature);
    }

    std::cout << m.size() << " stations." << std::endl;

    return m;
}

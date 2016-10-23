//#include <boost/program_options.hpp>
#include "temperature.h"
#include "utils.h"
#include <iostream>

//namespace po = boost::program_options;

int main (int argc, char *argv[])
{






    //TemperatureData t ("data/stations.csv");
    TemperatureData t ("data/stations.csv");

//read data from disk
    t.read();

    t.print();

//calculate avg temperature by station
    summarise_by_key(t.to_map(), avg);

//save clean data to disk
    t.save("results/stations-clean.csv");



    return 0;
}

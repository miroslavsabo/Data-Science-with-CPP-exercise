#include "temperature.h"
#include "utils.h"

#include <iostream>


int main (int argc, char *argv[])
{
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

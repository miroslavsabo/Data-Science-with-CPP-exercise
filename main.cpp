#include "temperature.h"
#include "utils.h"

int main ()
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

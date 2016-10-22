#include "temperature.h"
#include "utils.h"

int main ()
{
    TemperatureData t ("data/stations.csv");

    t.read();
    t.print();

    summarise_by_key(t.to_map(), avg);

    t.save("results/stations-clean.csv");
    return 0;
}

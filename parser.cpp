#include "temperature.h"
#include "utils.h"

int main ()
{
    TemperatureData t ("data/stations.csv");

    t.read();
    t.print();

    avg_by_key(t.to_map());

    return 0;
}

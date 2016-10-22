#include <iostream>
#include <numeric>
#include "boost/format.hpp"
#include <unordered_map>
#include <vector>
#include <sstream>

/** brief
 *
 * param accList list<AccountPtr>&
 * return void
 *
 */
template <typename T>
void avg_by_key(std::unordered_map<std::string, std::vector<T>> m)
{

    std::stringstream ss;

    for (auto const& x : m)
    {
        std::string station = x.first;
        std::vector<T> temperatures = x.second;

        double t_avg = std::accumulate(
                           temperatures.begin(),
                           temperatures.end(), 0.0)/temperatures.size();


        std::cout <<
                  boost::format("Station: %-10s  AVG: %10.2f") % station % t_avg <<
                  std::endl;

    }
}

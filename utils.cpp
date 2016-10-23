#include "utils.h"
#include <iostream>
#include <numeric>
#include <boost/format.hpp>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <functional>
#include <regex>

double avg(const std::vector<double> &v)
{
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

bool is_number(const std::string & s)
{
    return std::regex_match(s, std::regex("-?[0-9]+([.][0-9]+)?"));
}

/** brief
 *
 * param accList list<AccountPtr>&
 * return void
 *
 */
void summarise_by_key(const std::unordered_map<std::string, std::vector<double>> &m,
                      std::function<double (std::vector<double>)> agg)
{

    std::stringstream ss;

    for (auto const& x : m)
    {
        std::string station = x.first;
        std::vector<double> temperatures = x.second;

        //typedef std::function<double (std::vector<T>)> Funcp = agg<std::vector<T>>;
        double t_avg = agg(temperatures);


        std::cout << boost::format("Station: %-10s  AVG: %.2f") % station % t_avg << std::endl;

    }
}

#pragma once

#include <unordered_map>
#include <vector>
#include <functional>

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define FRED(x) KRED x RST

double avg(const std::vector<double> &v);


/** brief
 *
 * param accList list<AccountPtr>&
 * return void
 *
 */
void summarise_by_key(const std::unordered_map<std::string, std::vector<double>> &m,
                      std::function<double (std::vector<double>)> agg);

#include <unordered_map>
#include <vector>
#include <functional>

double avg(const std::vector<double> &v);


/** brief
 *
 * param accList list<AccountPtr>&
 * return void
 *
 */
void summarise_by_key(const std::unordered_map<std::string, std::vector<double>> &m,
                      std::function<double (std::vector<double>)> agg);

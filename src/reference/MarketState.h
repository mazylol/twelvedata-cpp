#ifndef TWELVEDATA_MARKETSTATE_H
#define TWELVEDATA_MARKETSTATE_H

/*
    json:
    [
{
"name": "NYSE",
"code": "XNYS",
"country": "United States",
"is_market_open": true,
"time_after_open": "02:39:03",
"time_to_open": "00:00:00",
"time_to_close": "05:20:57"
},
{
"name": "NYSE",
"code": "XASE",
"country": "United States",
"is_market_open": true,
"time_after_open": "02:39:03",
"time_to_open": "00:00:00",
"time_to_close": "05:20:57"
}
 ]
*/

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct MarketStateItem {
        std::string name;
        std::string code;
        std::string country;
        bool is_market_open;
        std::string time_after_open;
        std::string time_to_open;
        std::string time_to_close;
    };

    [[maybe_unused]]
    std::vector<MarketStateItem> getMarketState(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif // TWELVEDATA_MARKETSTATE_H

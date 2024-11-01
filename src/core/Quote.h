#ifndef TWELVEDATA_QUOTE_H
#define TWELVEDATA_QUOTE_H

#include "twelvedata.hpp"

namespace Twelvedata::Core {
    struct FiftyTwoWeek {
        std::string low;
        std::string high;
        std::string low_change;
        std::string high_change;
        std::string low_change_percent;
        std::string high_change_percent;
        std::string range;
    };

    struct Quote {
        std::string symbol;
        std::string name;
        std::string exchange;
        std::string mic_code;
        std::string currency;
        std::string datetime;
        int timestamp;
        std::string open;
        std::string high;
        std::string low;
        std::string close;
        std::string volume;
        std::string previous_close;
        std::string change;
        std::string percent_change;
        std::string average_volume;
        bool is_market_open;
        FiftyTwoWeek fifty_two_week;
    };

    [[maybe_unused]]
    Quote getQuote(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif // TWELVEDATA_QUOTE_H
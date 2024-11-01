#ifndef TWELVEDATA_EXCHANGERATE_H
#define TWELVEDATA_EXCHANGERATE_H

#include "twelvedata.hpp"

namespace Twelvedata::Core {
    struct ExchangeRate {
        std::string symbol;
        double rate;
        int timestamp;
    };

    [[maybe_unused]]
    ExchangeRate getExchangeRate(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif
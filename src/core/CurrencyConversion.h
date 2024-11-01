#ifndef TWELEVEDATA_CURRENCYCONVERSION_H
#define TWELEVEDATA_CURRENCYCONVERSION_H

#include "twelvedata.hpp"

namespace Twelvedata::Core {
    struct CurrencyConversion {
        std::string symbol;
        double rate;
        double amount;
        int timestamp;
    };

    [[maybe_unused]]
    CurrencyConversion getCurrencyConversion(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif // TWELEVEDATA_CURRENCYCONVERSION_H
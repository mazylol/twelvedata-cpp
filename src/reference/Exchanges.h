#ifndef TWELVEDATA_EXCHANGES_H
#define TWELVEDATA_EXCHANGES_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct ExchangeListItem {
        std::string name;
        std::string code;
        std::string country;
        std::string timezone;
    };

    struct Exchanges {
        std::vector<ExchangeListItem> data;
        std::string status;
    };

    [[maybe_unused]]
    Exchanges getExchanges(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif // TWELVEDATA_EXCHANGES_H
#ifndef TWELVEDATA_CRYPTOCURRENCYEXCHANGES_H
#define TWELVEDATA_CRYPTOCURRENCYEXCHANGES_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct CryptocurrencyExchangeListItem {
        std::string name;
    };

    struct CryptocurrencyExchanges {
        std::vector<CryptocurrencyExchangeListItem> data;
        std::string status;

        [[maybe_unused]]
        CryptocurrencyExchanges(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                                std::unordered_map<const char *, const char *> params);
    };
}

#endif // TWELVEDATA_CRYPTOCURRENCYEXCHANGES_H

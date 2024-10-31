#ifndef TWELVEDATA_CRYPTOLIST_H
#define TWELVEDATA_CRYPTOLIST_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct CryptocurrenciesListItem {
        std::string symbol;
        std::vector<std::string> available_exchanges;
        std::string currency_base;
        std::string currency_quote;
    };

    struct CryptocurrenciesList {
        std::vector<CryptocurrenciesListItem> data;
        int count;
        std::string status;
    };

    [[maybe_unused]]
    CryptocurrenciesList getCryptocurrenciesList(
            const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
            std::unordered_map<const char *, const char *> params);
}

#endif //TWELVEDATA_CRYPTOLIST_H

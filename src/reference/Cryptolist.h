#ifndef TWELVEDATA_CRYPTOLIST_H
#define TWELVEDATA_CRYPTOLIST_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct CryptoListItem {
        std::string symbol;
        std::vector<std::string> available_exchanges;
        std::string currency_base;
        std::string currency_quote;
    };

    struct CryptoList {
        std::vector<CryptoListItem> data;
        int count;
        std::string status;
    };

    CryptoList getCryptoList(
            const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
            std::unordered_map<const char *, const char *> params);
}

#endif //TWELVEDATA_CRYPTOLIST_H

#ifndef TWELVEDATA_FOREXLIST_H
#define TWELVEDATA_FOREXLIST_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct ForexPairListItem {
        std::string symbol;
        std::string currency_group;
        std::string currency_base;
        std::string currency_quote;
    };

    struct ForexPairsList {
        std::vector<ForexPairListItem> data;
        int count;
        std::string status;
    };

    ForexPairsList getForexPairsList(
            const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
            std::unordered_map<const char *, const char *> params);
}

#endif //TWELVEDATA_FOREXLIST_H

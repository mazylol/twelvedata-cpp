#ifndef TWELVEDATA_INDICESLIST_H
#define TWELVEDATA_INDICESLIST_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct IndexListItem {
        std::string symbol;
        std::string name;
        std::string country;
        std::string currency;
        std::string exchange;
        std::string mic_code;
    };

    struct IndicesList {
        std::vector<IndexListItem> data;
        int count;
        std::string status;
    };

    [[maybe_unused]]
    IndicesList getIndicesList(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif // TWELVEDATA_INDICESLIST_H

#ifndef TWELVEDATA_BONDLIST_H
#define TWELVEDATA_BONDLIST_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct BondListItem {
        std::string symbol;
        std::string name;
        std::string country;
        std::string currency;
        std::string exchange;
        std::string type;
    };

    struct BondResult {
        int count;
        std::vector<BondListItem> list;
    };

    struct BondsList {
        BondResult result;
        std::string status;

        [[maybe_unused]]
        BondsList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                  std::unordered_map<const char *, const char *> params);
    };
}

#endif // TWELVEDATA_BONDLIST_H

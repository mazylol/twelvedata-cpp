#ifndef TWELVEDATA_FUNDLIST_H
#define TWELVEDATA_FUNDLIST_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct FundListItem {
        std::string symbol;
        std::string name;
        std::string country;
        std::string currency;
        std::string exchange;
        std::string type;
        std::string figi_code;
    };

    struct FundResult {
        int count;
        std::vector<FundListItem> list;
    };

    struct FundsList {
        FundResult result;
        std::string status;
    };

    [[maybe_unused]]
    FundsList getFundsList(
            const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
            std::unordered_map<const char *, const char *> params);
}

#endif // TWELVEDATA_FUNDLIST_H

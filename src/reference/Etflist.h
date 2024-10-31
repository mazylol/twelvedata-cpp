#ifndef TWELVEDATA_ETFLIST_H
#define TWELVEDATA_ETFLIST_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct EtfListItem {
        std::string symbol;
        std::string name;
        std::string currency;
        std::string exchange;
        std::string mic_code;
        std::string country;
        std::string figi_code;
    };

    struct EtfsList {
        std::vector<EtfListItem> data;
        int count;
        std::string status;
    };

    [[maybe_unused]]
    EtfsList getEtfsList(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);

}

#endif // TWELVEDATA_ETFLIST_H

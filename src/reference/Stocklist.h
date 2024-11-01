#ifndef TWELVEDATA_STOCKLIST_H
#define TWELVEDATA_STOCKLIST_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct Access {
        std::string global;
        std::string plan;
    };

    struct StockListItem {
        std::string symbol;
        std::string name;
        std::string currency;
        std::string mic_code;
        std::string country;
        std::string type;
        Access access;
    };

    struct StocksList {
        ;
        std::vector<StockListItem> data;
        int count;
        std::string status;

        [[maybe_unused]]
        StocksList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                   std::unordered_map<const char *, const char *> params);
    };
};

#endif // TWELVEDATA_STOCKLIST_H

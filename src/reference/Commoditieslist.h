#ifndef TWELVEDATA_COMMODITIESLIST_H
#define TWELVEDATA_COMMODITIESLIST_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct CommodityListItem {
        std::string symbol;
        std::string name;
        std::string category;
        std::string description;
    };

    struct CommoditiesList {
        std::vector<CommodityListItem> data;
        int count;
        std::string status;

        [[maybe_unused]]
        CommoditiesList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                        std::unordered_map<const char *, const char *> params);
    };
}

#endif // TWELVEDATA_COMMODITIESLIST_H

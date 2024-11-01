#ifndef TWELVEDATA_REALTIMEPRICE_H
#define TWELVEDATA_REALTIMEPRICE_H

#include "twelvedata.hpp"

namespace Twelvedata::Core {
    struct RealTimePrice {
        std::string price;

        [[maybe_unused]]
        RealTimePrice(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params);
    };
}

#endif // TWELVEDATA_REALTIMEPRICE_H
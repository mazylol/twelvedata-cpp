#ifndef TWELVEDATA_EARLIESTTIMESTAMP_H
#define TWELVEDATA_EARLIESTTIMESTAMP_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct EarliestTimestamp {
        std::string datetime;
        int unix_time;
    };

    [[maybe_unused]]
    EarliestTimestamp getEarliestTimestamp(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif
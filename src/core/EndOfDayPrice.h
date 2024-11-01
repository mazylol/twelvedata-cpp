#ifndef TWELVEDATA_ENDOFDAYPRICE_H
#define TWELVEDATA_ENDOFDAYPRICE_H

#include "twelvedata.hpp"

namespace Twelvedata::Core {
    struct EndOfDayPrice {
        std::string symbol;
        std::string exchange;
        std::string mic_code;
        std::string currency;
        std::string datetime;
        std::string close;

        [[maybe_unused]]
        EndOfDayPrice(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params);
    };
}

#endif // TWELVEDATA_ENDOFDAYPRICE_H
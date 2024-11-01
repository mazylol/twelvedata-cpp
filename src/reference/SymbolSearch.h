#ifndef TWELVEDATA_SYMBOLSEARCH_H
#define TWELVEDATA_SYMBOLSEARCH_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct SymbolSearchItem {
        std::string symbol;
        std::string instrument_name;
        std::string exchange;
        std::string mic_code;
        std::string exchange_timezone;
        std::string instrument_type;
        std::string country;
        std::string currency;
    };

    struct SymbolSearchList {
        std::vector<SymbolSearchItem> data;
        std::string status;
    };

    SymbolSearchList getSymbolSearchList(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif
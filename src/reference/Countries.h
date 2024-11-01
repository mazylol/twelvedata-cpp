#ifndef TWELVEDATA_COUNTRIES_H
#define TWELVEDATA_COUNTRIES_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct CountryListItem {
        std::string iso2;
        std::string iso3;
        std::string numeric;
        std::string name;
        std::string official_name;
        std::string capital;
        std::string currency;
    };

    struct CountriesList {
        std::vector<CountryListItem> data;

        [[maybe_unused]]
        CountriesList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                      std::unordered_map<const char *, const char *> params);
    };
}

#endif

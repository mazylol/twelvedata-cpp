#ifndef TWELVEDATA_INSTRUMENTTYPE_H
#define TWELVEDATA_INSTRUMENTTYPE_H

#include "twelvedata.hpp"

namespace Twelvedata::Reference {
    struct InstrumentType {
        std::vector<std::string> result;
        std::string status;
    };

    [[maybe_unused]]
    InstrumentType getInstrumentType(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif // TWELVEDATA_INSTRUMENTTYPE_H

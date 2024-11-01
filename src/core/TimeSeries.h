#ifndef TWELVEDATA_TIMESERIES_H
#define TWELVEDATA_TIMESERIES_H

#include "twelvedata.hpp"

namespace Twelvedata::Core {
    struct TimeSeriesMeta {
        std::string symbol;
        std::string interval;
        std::string currency;
        std::string exchange_timezone;
        std::string exchange;
        std::string mic_code;
        std::string type;
    };

    struct TimeSeriesValue {
        std::string datetime;
        std::string open;
        std::string high;
        std::string low;
        std::string close;
        std::string volume;
    };

    struct TimeSeries {
        TimeSeriesMeta meta;
        std::vector<TimeSeriesValue> values;
        std::string status;
    };

    [[maybe_unused]]
    TimeSeries getTimeSeries(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params);
}

#endif // TWELVEDATA_TIMESERIES_H
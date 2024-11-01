#include "TimeSeries.h"

Twelvedata::Core::TimeSeries Twelvedata::Core::getTimeSeries(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/time_series", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        TimeSeries timeSeries;

        timeSeries.status = object.at("status").get<std::string>();

        nlohmann::json metaJson = object.at("meta");

        timeSeries.meta.symbol = metaJson.at("symbol").get<std::string>();
        timeSeries.meta.interval = metaJson.at("interval").get<std::string>();
        timeSeries.meta.currency = metaJson.at("currency").get<std::string>();
        timeSeries.meta.exchange_timezone = metaJson.at("exchange_timezone").get<std::string>();
        timeSeries.meta.exchange = metaJson.at("exchange").get<std::string>();
        timeSeries.meta.mic_code = metaJson.at("mic_code").get<std::string>();
        timeSeries.meta.type = metaJson.at("type").get<std::string>();

        for (const auto &dataJson: object.at("values")) {
            TimeSeriesValue value;

            value.datetime = dataJson.at("datetime").get<std::string>();
            value.open = dataJson.at("open").get<std::string>();
            value.high = dataJson.at("high").get<std::string>();
            value.low = dataJson.at("low").get<std::string>();
            value.close = dataJson.at("close").get<std::string>();
            value.volume = dataJson.at("volume").get<std::string>();

            timeSeries.values.push_back(value);
        }

        return timeSeries;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
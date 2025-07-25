#include "twelvedata.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

Twelvedata::Core::TimeSeries::TimeSeries(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/time_series", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();

        nlohmann::json metaJson = object.at("meta");

        this->meta.symbol = metaJson.at("symbol").get<std::string>();
        this->meta.interval = metaJson.at("interval").get<std::string>();
        this->meta.currency = metaJson.at("currency").get<std::string>();
        this->meta.exchange_timezone = metaJson.at("exchange_timezone").get<std::string>();
        this->meta.exchange = metaJson.at("exchange").get<std::string>();
        this->meta.mic_code = metaJson.at("mic_code").get<std::string>();
        this->meta.type = metaJson.at("type").get<std::string>();

        for (const auto &dataJson : object.at("values")) {
            TimeSeriesValue value;

            value.datetime = dataJson.at("datetime").get<std::string>();
            value.open = dataJson.at("open").get<std::string>();
            value.high = dataJson.at("high").get<std::string>();
            value.low = dataJson.at("low").get<std::string>();
            value.close = dataJson.at("close").get<std::string>();
            value.volume = dataJson.at("volume").get<std::string>();

            this->values.push_back(value);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

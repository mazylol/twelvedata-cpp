#include "twelvedata.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

Twelvedata::Core::EndOfDayPrice::EndOfDayPrice(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/eod", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->symbol = object.at("symbol").get<std::string>();
        this->exchange = object.at("exchange").get<std::string>();
        this->mic_code = object.at("mic_code").get<std::string>();
        this->currency = object.at("currency").get<std::string>();
        this->datetime = object.at("datetime").get<std::string>();
        this->close = object.at("close").get<std::string>();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

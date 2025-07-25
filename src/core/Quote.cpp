#include "twelvedata.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

Twelvedata::Core::Quote::Quote(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/quote", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->symbol = object.at("symbol").get<std::string>();
        this->name = object.at("name").get<std::string>();
        this->exchange = object.at("exchange").get<std::string>();
        this->mic_code = object.at("mic_code").get<std::string>();
        this->currency = object.at("currency").get<std::string>();
        this->datetime = object.at("datetime").get<std::string>();
        this->timestamp = object.at("timestamp").get<int>();
        this->open = object.at("open").get<std::string>();
        this->high = object.at("high").get<std::string>();
        this->low = object.at("low").get<std::string>();
        this->close = object.at("close").get<std::string>();
        this->volume = object.at("volume").get<std::string>();
        this->previous_close = object.at("previous_close").get<std::string>();
        this->change = object.at("change").get<std::string>();
        this->percent_change = object.at("percent_change").get<std::string>();
        this->average_volume = object.at("average_volume").get<std::string>();
        this->is_market_open = object.at("is_market_open").get<bool>();

        FiftyTwoWeek fiftyTwoWeek;

        fiftyTwoWeek.low = object.at("fifty_two_week").at("low").get<std::string>();
        fiftyTwoWeek.high = object.at("fifty_two_week").at("high").get<std::string>();
        fiftyTwoWeek.low_change = object.at("fifty_two_week").at("low_change").get<std::string>();
        fiftyTwoWeek.high_change = object.at("fifty_two_week").at("high_change").get<std::string>();
        fiftyTwoWeek.low_change_percent = object.at("fifty_two_week").at("low_change_percent").get<std::string>();
        fiftyTwoWeek.high_change_percent = object.at("fifty_two_week").at("high_change_percent").get<std::string>();
        fiftyTwoWeek.range = object.at("fifty_two_week").at("range").get<std::string>();

        this->fifty_two_week = fiftyTwoWeek;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

#include "Quote.h"

Twelvedata::Core::Quote Twelvedata::Core::getQuote(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/quote", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        Quote quote;

        quote.symbol = object.at("symbol").get<std::string>();
        quote.name = object.at("name").get<std::string>();
        quote.exchange = object.at("exchange").get<std::string>();
        quote.mic_code = object.at("mic_code").get<std::string>();
        quote.currency = object.at("currency").get<std::string>();
        quote.datetime = object.at("datetime").get<std::string>();
        quote.timestamp = object.at("timestamp").get<int>();
        quote.open = object.at("open").get<std::string>();
        quote.high = object.at("high").get<std::string>();
        quote.low = object.at("low").get<std::string>();
        quote.close = object.at("close").get<std::string>();
        quote.volume = object.at("volume").get<std::string>();
        quote.previous_close = object.at("previous_close").get<std::string>();
        quote.change = object.at("change").get<std::string>();
        quote.percent_change = object.at("percent_change").get<std::string>();
        quote.average_volume = object.at("average_volume").get<std::string>();
        quote.is_market_open = object.at("is_market_open").get<bool>();

        FiftyTwoWeek fiftyTwoWeek;

        fiftyTwoWeek.low = object.at("fifty_two_week").at("low").get<std::string>();
        fiftyTwoWeek.high = object.at("fifty_two_week").at("high").get<std::string>();
        fiftyTwoWeek.low_change = object.at("fifty_two_week").at("low_change").get<std::string>();
        fiftyTwoWeek.high_change = object.at("fifty_two_week").at("high_change").get<std::string>();
        fiftyTwoWeek.low_change_percent = object.at("fifty_two_week").at("low_change_percent").get<std::string>();
        fiftyTwoWeek.high_change_percent = object.at("fifty_two_week").at("high_change_percent").get<std::string>();
        fiftyTwoWeek.range = object.at("fifty_two_week").at("range").get<std::string>();

        quote.fifty_two_week = fiftyTwoWeek;

        return quote;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
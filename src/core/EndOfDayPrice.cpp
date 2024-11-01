#include "EndOfDayPrice.h"

Twelvedata::Core::EndOfDayPrice Twelvedata::Core::getEndOfDayPrice(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/eod", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        EndOfDayPrice endOfDayPrice;

        endOfDayPrice.symbol = object.at("symbol").get<std::string>();
        endOfDayPrice.exchange = object.at("exchange").get<std::string>();
        endOfDayPrice.mic_code = object.at("mic_code").get<std::string>();
        endOfDayPrice.currency = object.at("currency").get<std::string>();
        endOfDayPrice.datetime = object.at("datetime").get<std::string>();
        endOfDayPrice.close = object.at("close").get<std::string>();

        return endOfDayPrice;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
#include "ExchangeRate.h"

Twelvedata::Core::ExchangeRate Twelvedata::Core::getExchangeRate(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/exchange_rate", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        ExchangeRate exchangeRate;

        exchangeRate.symbol = object.at("symbol").get<std::string>();
        exchangeRate.rate = object.at("rate").get<double>();
        exchangeRate.timestamp = object.at("timestamp").get<int>();

        return exchangeRate;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
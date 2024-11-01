#include "CurrencyConversion.h"

Twelvedata::Core::CurrencyConversion Twelvedata::Core::getCurrencyConversion(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/currency_conversion", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        CurrencyConversion currencyConversion;

        currencyConversion.symbol = object.at("symbol").get<std::string>();
        currencyConversion.rate = object.at("rate").get<double>();
        currencyConversion.amount = object.at("amount").get<double>();
        currencyConversion.timestamp = object.at("timestamp").get<int>();

        return currencyConversion;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
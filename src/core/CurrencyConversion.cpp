#include "twelvedata.hpp"

Twelvedata::Core::CurrencyConversion::CurrencyConversion(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/currency_conversion", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->symbol = object.at("symbol").get<std::string>();
        this->rate = object.at("rate").get<double>();
        this->amount = object.at("amount").get<double>();
        this->timestamp = object.at("timestamp").get<int>();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
#include "twelvedata.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

Twelvedata::Reference::CryptocurrenciesList::CryptocurrenciesList(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/cryptocurrencies", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->count = object.at("count").get<int>();
        this->status = object.at("status").get<std::string>();

        for (const auto &dataJson : object.at("data")) {
            CryptocurrenciesListItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.currency_base = dataJson.at("currency_base").get<std::string>();
            listItem.currency_quote = dataJson.at("currency_quote").get<std::string>();

            for (const auto &exchange : dataJson.at("available_exchanges")) {
                listItem.available_exchanges.push_back(exchange.get<std::string>());
            }

            this->data.push_back(listItem);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

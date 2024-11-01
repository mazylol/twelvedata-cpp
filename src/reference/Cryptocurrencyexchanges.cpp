#include "Cryptocurrencyexchanges.h"

Twelvedata::Reference::CryptocurrencyExchanges Twelvedata::Reference::getCryptocurrencyExchanges(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/cryptocurrency_exchanges", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        CryptocurrencyExchanges exchanges;

        exchanges.status = object.at("status").get<std::string>();

        for (const auto &dataJson : object.at("data")) {
            CryptocurrencyExchangeListItem listItem;

            listItem.name = dataJson.at("name").get<std::string>();

            exchanges.data.push_back(listItem);
        }

        return exchanges;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
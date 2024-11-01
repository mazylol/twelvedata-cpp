#include "Cryptocurrencyexchanges.h"

Twelvedata::Reference::CryptocurrencyExchanges::CryptocurrencyExchanges(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/cryptocurrency_exchanges", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();

        for (const auto &dataJson : object.at("data")) {
            CryptocurrencyExchangeListItem listItem;

            listItem.name = dataJson.at("name").get<std::string>();

            this->data.push_back(listItem);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
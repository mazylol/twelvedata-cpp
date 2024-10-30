#include "Forexlist.h"

#include <utility>

Twelvedata::Reference::ForexPairsList Twelvedata::Reference::getForexPairsList(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/forex_pairs", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        ForexPairsList forexPairsList;

        forexPairsList.count = object.at("count").get<int>();
        forexPairsList.status = object.at("status").get<std::string>();

        for (const auto &dataJson: object.at("data")) {
            ForexPairListItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.currency_group = dataJson.at("currency_group").get<std::string>();
            listItem.currency_base = dataJson.at("currency_base").get<std::string>();
            listItem.currency_quote = dataJson.at("currency_quote").get<std::string>();

            forexPairsList.data.push_back(listItem);
        }

        return forexPairsList;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

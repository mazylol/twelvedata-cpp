#include "Forexlist.h"

#include <utility>

Twelvedata::Reference::ForexPairsList::ForexPairsList(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/forex_pairs", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->count = object.at("count").get<int>();
        this->status = object.at("status").get<std::string>();

        for (const auto &dataJson : object.at("data")) {
            ForexPairListItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.currency_group = dataJson.at("currency_group").get<std::string>();
            listItem.currency_base = dataJson.at("currency_base").get<std::string>();
            listItem.currency_quote = dataJson.at("currency_quote").get<std::string>();

            this->data.push_back(listItem);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

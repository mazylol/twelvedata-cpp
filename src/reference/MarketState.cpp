#include "MarketState.h"

std::vector<Twelvedata::Reference::MarketStateItem> Twelvedata::Reference::getMarketState(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/market_state", std::move(params));

        std::cout << text << std::endl;

        nlohmann::json object = nlohmann::json::parse(text);

        std::vector<MarketStateItem> marketState;

        for (const auto &dataJson : object) {
            MarketStateItem listItem;

            listItem.name = dataJson.at("name").get<std::string>();
            listItem.code = dataJson.at("code").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.is_market_open = dataJson.at("is_market_open").get<bool>();
            listItem.time_after_open = dataJson.at("time_after_open").get<std::string>();
            listItem.time_to_open = dataJson.at("time_to_open").get<std::string>();
            listItem.time_to_close = dataJson.at("time_to_close").get<std::string>();

            marketState.push_back(listItem);
        }

        return marketState;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
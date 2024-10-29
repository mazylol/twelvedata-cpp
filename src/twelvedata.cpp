#include <twelvedata.hpp>

#include <iostream>
#include <nlohmann/json.hpp>

Twelvedata::Reference::StocksList Twelvedata::Reference::getStocksList(GetFunction getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/stocks", params);

        nlohmann::json object = nlohmann::json::parse(text);

        StocksList stocksList;

        stocksList.status = object.at("status").get<std::string>();

        const auto &dataJson = object.at("data");
        for (const auto &dataJson : dataJson) {
            StockListItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.name = dataJson.at("name").get<std::string>();
            listItem.currency = dataJson.at("currency").get<std::string>();
            listItem.mic_code = dataJson.at("mic_code").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.type = dataJson.at("type").get<std::string>();
            if (dataJson.find("access") != dataJson.end()) {
                listItem.access = Access{dataJson.at("access").at("global").get<std::string>(), dataJson.at("access").at("plan").get<std::string>()};
            } else {
                listItem.access = Access{"", ""};
            }

            stocksList.data.push_back(listItem);
        }

        return stocksList;
    } catch (const std::exception &e) {
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
        return {};
    }
}

Twelvedata::Reference::ForexPairsList Twelvedata::Reference::getForexPairsList(GetFunction getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/forex_pairs", params);

        // Parse the JSON response
        nlohmann::json object = nlohmann::json::parse(text);

        ForexPairsList forexPairsList;

        forexPairsList.count = object.at("count").get<int>();
        forexPairsList.status = object.at("status").get<std::string>();

        const auto &dataJson = object.at("data");
        for (const auto &dataJson : dataJson) {
            ForexPairListItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.currency_group = dataJson.at("currency_group").get<std::string>();
            listItem.currency_base = dataJson.at("currency_base").get<std::string>();
            listItem.currency_quote = dataJson.at("currency_quote").get<std::string>();

            forexPairsList.data.push_back(listItem);
        }

        return forexPairsList;
    } catch (const std::exception &e) {
        // Handle exceptions
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
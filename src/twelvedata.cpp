#include <twelvedata.h>

#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>

Twelvedata::Reference::StocksList Twelvedata::Reference::getStocksList(const char *key) {
    try {
        std::string text = cpr::Get(cpr::Url{"https://api.twelvedata.com/stocks"}, cpr::Header{{"Authorization", key}}).text;

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
        return Twelvedata::Reference::StocksList{};
    }
}
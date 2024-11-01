#include "Commoditieslist.h"

Twelvedata::Reference::CommoditiesList::CommoditiesList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/commodities", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();
        this->count = object.at("count").get<int>();

        for (const auto &dataJson : object.at("data")) {
            CommodityListItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.name = dataJson.at("name").get<std::string>();
            listItem.category = dataJson.at("category").get<std::string>();
            listItem.description = dataJson.at("description").get<std::string>();

            this->data.push_back(listItem);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

#include "Bondlist.h"

Twelvedata::Reference::BondsList::BondsList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/bonds", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();

        BondResult bondResult;

        bondResult.count = object.at("result").at("count").get<int>();

        for (const auto &dataJson : object.at("result").at("list")) {
            BondListItem listItem;
            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.name = dataJson.at("name").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.currency = dataJson.at("currency").get<std::string>();
            listItem.exchange = dataJson.at("exchange").get<std::string>();
            listItem.type = dataJson.at("type").get<std::string>();
            bondResult.list.push_back(listItem);
        }
        this->result = bondResult;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

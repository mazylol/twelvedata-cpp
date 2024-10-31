#include "Etflist.h"

Twelvedata::Reference::EtfsList Twelvedata::Reference::getEtfsList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/etfs", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        EtfsList etfList;

        etfList.status = object.at("status").get<std::string>();
        etfList.count = object.at("count").get<int>();

        for (const auto &dataJson : object.at("data")) {
            EtfListItem listItem;
            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.name = dataJson.at("name").get<std::string>();
            listItem.currency = dataJson.at("currency").get<std::string>();
            listItem.exchange = dataJson.at("exchange").get<std::string>();
            listItem.mic_code = dataJson.at("mic_code").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.figi_code = dataJson.at("figi_code").get<std::string>();
            etfList.data.push_back(listItem);
        }

        return etfList;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

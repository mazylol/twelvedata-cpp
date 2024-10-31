#include "Indiceslist.h"

Twelvedata::Reference::IndicesList Twelvedata::Reference::getIndicesList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/indices", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        IndicesList indicesList;

        indicesList.status = object.at("status").get<std::string>();
        indicesList.count = object.at("count").get<int>();

        for (const auto &dataJson : object.at("data")) {
            IndexListItem listItem;
            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.name = dataJson.at("name").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.currency = dataJson.at("currency").get<std::string>();
            listItem.exchange = dataJson.at("exchange").get<std::string>();
            listItem.mic_code = dataJson.at("mic_code").get<std::string>();
            indicesList.data.push_back(listItem);
        }

        return indicesList;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

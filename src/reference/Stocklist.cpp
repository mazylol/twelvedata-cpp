#include "Stocklist.h"

Twelvedata::Reference::StocksList::StocksList(
        const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
        std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/stocks", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();
        this->count = object.at("count").get<int>();

        for (const auto &dataJson: object.at("data")) {
            Twelvedata::Reference::StockListItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.name = dataJson.at("name").get<std::string>();
            listItem.currency = dataJson.at("currency").get<std::string>();
            listItem.mic_code = dataJson.at("mic_code").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.type = dataJson.at("type").get<std::string>();
            if (dataJson.find("access") != dataJson.end()) {
                listItem.access = Twelvedata::Reference::Access{dataJson.at("access").at("global").get<std::string>(),
                                                                dataJson.at("access").at("plan").get<std::string>()};
            } else {
                listItem.access = Twelvedata::Reference::Access{"", ""};
            }

            this->data.push_back(listItem);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

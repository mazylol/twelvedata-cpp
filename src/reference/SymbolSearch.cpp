#include "twelvedata.hpp"

Twelvedata::Reference::SymbolSearchList::SymbolSearchList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/symbol_search", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();

        for (const auto &dataJson : object.at("data")) {
            SymbolSearchItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.instrument_name = dataJson.at("instrument_name").get<std::string>();
            listItem.exchange = dataJson.at("exchange").get<std::string>();
            listItem.mic_code = dataJson.at("mic_code").get<std::string>();
            listItem.exchange_timezone = dataJson.at("exchange_timezone").get<std::string>();
            listItem.instrument_type = dataJson.at("instrument_type").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.currency = dataJson.at("currency").get<std::string>();

            this->data.push_back(listItem);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
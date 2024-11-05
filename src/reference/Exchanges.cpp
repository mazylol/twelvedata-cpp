#include "twelvedata.hpp"

Twelvedata::Reference::Exchanges::Exchanges(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/exchanges", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();

        for (const auto &dataJson : object.at("data")) {
            ExchangeListItem listItem;

            listItem.name = dataJson.at("name").get<std::string>();
            listItem.code = dataJson.at("code").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.timezone = dataJson.at("timezone").get<std::string>();

            this->data.push_back(listItem);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
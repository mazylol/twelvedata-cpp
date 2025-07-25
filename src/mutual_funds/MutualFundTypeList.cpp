#include "twelvedata.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

Twelvedata::MutualFunds::MutualFundsTypeList::MutualFundsTypeList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/mutual_funds/family", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();

        for (const auto &dataJson : object.at("result").items()) {
            std::vector<std::string> familyList;
            for (const auto &family : dataJson.value()) {
                familyList.push_back(family.get<std::string>());
            }
            this->result[dataJson.key()] = familyList;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

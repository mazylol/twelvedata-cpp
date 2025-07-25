#include "twelvedata.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

Twelvedata::MutualFunds::MutualFundsList::MutualFundsList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/mutual_funds/list", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();

        MutualFundsListResult fundResult;

        fundResult.count = object.at("result").at("count").get<int>();

        for (const auto &dataJson : object.at("result").at("list")) {
            MutualFundListItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.name = dataJson.at("name").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.fund_family = dataJson.at("fund_family").get<std::string>();
            listItem.fund_type = dataJson.at("fund_type").get<std::string>();

            if (dataJson.at("performance_rating").is_null()) {
                listItem.performance_rating = 0;
            } else {
                listItem.performance_rating = dataJson.at("performance_rating").get<int>();
            }

            if (dataJson.at("risk_rating").is_null()) {
                listItem.risk_rating = 0;
            } else {
                listItem.risk_rating = dataJson.at("risk_rating").get<int>();
            }

            listItem.exchange = dataJson.at("exchange").get<std::string>();
            listItem.mic_code = dataJson.at("mic_code").get<std::string>();

            fundResult.list.push_back(listItem);
        }

        this->result = fundResult;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

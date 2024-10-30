#include "Fundslist.h"

Twelvedata::Reference::FundsList Twelvedata::Reference::getFundsList(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/funds", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        FundsList fundsList;

        fundsList.status = object.at("status").get<std::string>();

        FundResult fundResult;

        fundResult.count = object.at("result").at("count").get<int>();

        for (const auto &dataJson : object.at("result").at("list")) {
            FundListItem listItem;

            listItem.symbol = dataJson.at("symbol").get<std::string>();
            listItem.name = dataJson.at("name").get<std::string>();
            listItem.country = dataJson.at("country").get<std::string>();
            listItem.currency = dataJson.at("currency").get<std::string>();
            listItem.exchange = dataJson.at("exchange").get<std::string>();
            listItem.type = dataJson.at("type").get<std::string>();
            listItem.figi_code = dataJson.at("figi_code").get<std::string>();

            fundResult.list.push_back(listItem);
        }

        fundsList.result = fundResult;

        return fundsList;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
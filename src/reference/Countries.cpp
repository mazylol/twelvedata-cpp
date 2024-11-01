#include "Countries.h"

Twelvedata::Reference::CountriesList Twelvedata::Reference::getCountriesList(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/countries", std::move(params));

        std::cout << text << std::endl;

        nlohmann::json object = nlohmann::json::parse(text);

        CountriesList countriesList;

        for (const auto &dataJson : object.at("data")) {
            CountryListItem listItem;

            listItem.iso2 = dataJson.at("iso2").get<std::string>();
            listItem.iso3 = dataJson.at("iso3").get<std::string>();
            listItem.numeric = dataJson.at("numeric").get<std::string>();
            listItem.name = dataJson.at("name").get<std::string>();
            listItem.official_name = dataJson.at("official_name").get<std::string>();
            listItem.capital = dataJson.at("capital").get<std::string>();
            listItem.currency = dataJson.at("currency").get<std::string>();

            countriesList.data.push_back(listItem);
        }

        return countriesList;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
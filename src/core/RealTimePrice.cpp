#include "twelvedata.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

Twelvedata::Core::RealTimePrice::RealTimePrice(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/price", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->price = object.at("price").get<std::string>();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

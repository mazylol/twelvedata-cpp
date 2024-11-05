#include "twelvedata.hpp"

Twelvedata::Reference::EarliestTimestamp::EarliestTimestamp(
    const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
    std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/earliest_timestamp", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->datetime = object.at("datetime").get<std::string>();
        this->unix_time = object.at("unix_time").get<int>();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
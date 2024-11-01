#include "InstrumentType.h"

Twelvedata::Reference::InstrumentType::InstrumentType(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params) {
    try {
        std::string text = getFunc("https://api.twelvedata.com/instrument_type", std::move(params));

        nlohmann::json object = nlohmann::json::parse(text);

        this->status = object.at("status").get<std::string>();

        for (const auto &dataJson : object.at("result")) {
            this->result.push_back(dataJson.get<std::string>());
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
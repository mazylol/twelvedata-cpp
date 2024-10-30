#include <dotenv.h>
#include <twelvedata.hpp>

#include <cpr/cpr.h>

#include <iostream>

/// The function has to return a string and take a const char* as an argument and an unordered map of strings as an argument
std::string httpGet(const char *endpoint, const std::unordered_map<const char *, const char *> &params) {
    std::string url = endpoint;

    if (!params.empty()) {
        url += "?";

        for (const auto &param : params) {
            url += param.first;
            url += "=";
            url += param.second;
            url += "&";
        }

        url.pop_back();
    }

    std::cout << url << std::endl;

    std::string text = cpr::Get(cpr::Url{url}, cpr::Header{{"Authorization", std::getenv("TWELVEDATA_API_KEY")}}).text;

    return text;
}

int main() {
    dotenv::init();

    /*Twelvedata::Reference::StockList stockList = Twelvedata::Reference::getStockList(httpGet, {});

    for (const auto &stock : stockList.data) {
        std::cout << stock.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::ForexPairsList forexPairsList = Twelvedata::Reference::getForexPairsList(httpGet, {});

    for (const auto &forexPair : forexPairsList.data) {
        std::cout << forexPair.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::CryptoList cryptoList = Twelvedata::Reference::getCryptoList(httpGet, {});

    for (const auto &crypto : cryptoList.data) {
        std::cout << crypto.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::FundsList fundsList = Twelvedata::Reference::getFundsList(httpGet, {});

    for (const auto &fund : fundsList.result.list) {
        std::cout << fund.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::FundsList fundsList = Twelvedata::Reference::getFundsList(httpGet, {});

    for (const auto &fund : fundsList.result.list) {
        std::cout << fund.symbol << std::endl;
    }*/

    Twelvedata::Reference::BondsList bondsList = Twelvedata::Reference::getBondsList(httpGet, {});

    for (const auto &bond : bondsList.result.list) {
        std::cout << bond.symbol << std::endl;
    }

    return 0;
}

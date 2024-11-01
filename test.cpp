#include <twelvedata.hpp>

#include <cpr/cpr.h>
#include <dotenvloader.hpp>

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

    std::string apiKeyValue = "apikey " + std::string(std::getenv("TWELVEDATA_API_KEY"));

    std::string text = cpr::Get(cpr::Url{url}, cpr::Header{{"Authorization", apiKeyValue}}).text;

    return text;
}

int main() {
    dotenvloader::load();

    /*Twelvedata::Reference::StocksList stockList = Twelvedata::Reference::getStocksList(httpGet, {});

    for (const auto &stock : stockList.data) {
        std::cout << stock.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::ForexPairsList forexPairsList = Twelvedata::Reference::getForexPairsList(httpGet, {});

    for (const auto &forexPair : forexPairsList.data) {
        std::cout << forexPair.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::CryptocurrenciesList cryptoList = Twelvedata::Reference::getCryptocurrenciesList(httpGet, {});

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

    /*Twelvedata::Reference::BondsList bondsList = Twelvedata::Reference::getBondsList(httpGet, {});

    for (const auto &bond : bondsList.result.list) {
        std::cout << bond.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::EtfsList etfList = Twelvedata::Reference::getEtfsList(httpGet, {});

    for (const auto &etf : etfList.data) {
        std::cout << etf.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::IndicesList indicesList = Twelvedata::Reference::getIndicesList(httpGet, {});

    for (const auto &index : indicesList.data) {
        std::cout << index.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::CommoditiesList commoditiesList = Twelvedata::Reference::getCommoditiesList(httpGet, {});

    for (const auto &commodity : commoditiesList.data) {
        std::cout << commodity.symbol << std::endl;
    }*/

    /*Twelvedata::Reference::Exchanges exchanges = Twelvedata::Reference::getExchanges(httpGet, {});

    for (const auto &exchange : exchanges.data) {
        std::cout << exchange.name << std::endl;
    }*/

    /*Twelvedata::Reference::CryptocurrencyExchanges exchanges = Twelvedata::Reference::getCryptocurrencyExchanges(httpGet, {});

    for (const auto &exchange : exchanges.data) {
        std::cout << exchange.name << std::endl;
    }*/

    std::vector<Twelvedata::Reference::MarketStateItem> marketState = Twelvedata::Reference::getMarketState(httpGet, {});

    for (const auto &market : marketState) {
        std::cout << market.name << std::endl;
    }

    return 0;
}

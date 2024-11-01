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

    /*auto stockList = Twelvedata::Reference::StocksList(httpGet, {});

    for (const auto &stock : stockList.data) {
        std::cout << stock.symbol << std::endl;
    }*/

    /*auto forexPairsList = Twelvedata::Reference::ForexPairsList(httpGet, {});

    for (const auto &forexPair : forexPairsList.data) {
        std::cout << forexPair.symbol << std::endl;
    }*/

    /*auto cryptoList = Twelvedata::Reference::CryptocurrenciesList(httpGet, {});

    for (const auto &crypto : cryptoList.data) {
        std::cout << crypto.symbol << std::endl;
    }*/

    /*auto fundsList = Twelvedata::Reference::FundsList(httpGet, {});

    for (const auto &fund : fundsList.result.list) {
        std::cout << fund.symbol << std::endl;
    }*/

    /*auto bondsList = Twelvedata::Reference::BondsList(httpGet, {});

    for (const auto &bond : bondsList.result.list) {
        std::cout << bond.symbol << std::endl;
    }*/

   /*auto etfList = Twelvedata::Reference::EtfsList(httpGet, {});

    for (const auto &etf : etfList.data) {
        std::cout << etf.symbol << std::endl;
    }*/

    /*auto indicesList = Twelvedata::Reference::IndicesList(httpGet, {});

    for (const auto &index : indicesList.data) {
        std::cout << index.symbol << std::endl;
    }*/

    /*auto commoditiesList = Twelvedata::Reference::CommoditiesList(httpGet, {});

    for (const auto &commodity : commoditiesList.data) {
        std::cout << commodity.symbol << std::endl;
    }*/

    /*auto exchanges = Twelvedata::Reference::Exchanges(httpGet, {});

    for (const auto &exchange : exchanges.data) {
        std::cout << exchange.name << std::endl;
    }*/

    /*auto exchanges = Twelvedata::Reference::CryptocurrencyExchanges(httpGet, {});

    for (const auto &exchange : exchanges.data) {
        std::cout << exchange.name << std::endl;
    }*/

    /*std::vector<Twelvedata::Reference::MarketStateItem> marketState = Twelvedata::Reference::getMarketState(httpGet, {});

    for (const auto &market : marketState) {
        std::cout << market.name << std::endl;
    }*/

    /*auto instrumentType = Twelvedata::Reference::InstrumentType(httpGet, {});

    for (const auto &instrument : instrumentType.result) {
        std::cout << instrument << std::endl;
    }*/

    /*auto countriesList = Twelvedata::Reference::CountriesList(httpGet, {});

    for (const auto &country : countriesList.data) {
        std::cout << country.name << std::endl;
    }*/

    /*auto earliestTimestamp = Twelvedata::Reference::EarliestTimestamp(httpGet, {{"symbol", "AAPL"}, {"interval", "1min"}});

    std::cout << earliestTimestamp.datetime << std::endl;
    std::cout << earliestTimestamp.unix_time << std::endl;*/

    auto symbolSearchList = Twelvedata::Reference::SymbolSearchList(httpGet, {{"symbol", "AAPL"}});

    for (const auto &symbol : symbolSearchList.data) {
        std::cout << symbol.symbol << std::endl;
    }

    /*auto timeSeries = Twelvedata::Core::TimeSeries(httpGet, {{"symbol", "AAPL"}, {"interval", "1min"}});

    std::cout << timeSeries.meta.symbol << std::endl;*/

    /*auto exchangeRate = Twelvedata::Core::ExchangeRate(httpGet, {{"symbol", "USD/JPY"}});

    std::cout << exchangeRate.symbol << std::endl;*/

    /*auto currencyConversion = Twelvedata::Core::CurrencyConversion(httpGet, {{"symbol", "USD/EUR"}, {"amount", "100"}});

    std::cout << currencyConversion.amount << std::endl;*/

    /*auto quote = Twelvedata::Core::Quote(httpGet, {{"symbol", "AAPL"}});

    std::cout << quote.symbol << std::endl;*/

    /*auto realTimePrice = Twelvedata::Core::RealTimePrice(httpGet, {{"symbol", "AAPL"}});

    std::cout << realTimePrice.price << std::endl;*/

    /*auto endOfDayPrice = Twelvedata::Core::EndOfDayPrice(httpGet, {{"symbol", "AAPL"}});

    std::cout << endOfDayPrice.close << std::endl;*/

    return 0;
}

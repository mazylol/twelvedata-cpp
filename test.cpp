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

    /*std::vector<Twelvedata::Reference::MarketStateItem> marketState = Twelvedata::Reference::getMarketState(httpGet, {});

    for (const auto &market : marketState) {
        std::cout << market.name << std::endl;
    }*/

    /*Twelvedata::Reference::InstrumentType instrumentType = Twelvedata::Reference::getInstrumentType(httpGet, {});

    for (const auto &instrument : instrumentType.result) {
        std::cout << instrument << std::endl;
    }*/

    /*Twelvedata::Reference::CountriesList countriesList = Twelvedata::Reference::getCountriesList(httpGet, {});

    for (const auto &country : countriesList.data) {
        std::cout << country.name << std::endl;
    }*/

    /*Twelvedata::Reference::EarliestTimestamp earliestTimestamp = Twelvedata::Reference::getEarliestTimestamp(httpGet, {{"symbol", "AAPL"}, {"interval", "1min"}});

    std::cout << earliestTimestamp.datetime << std::endl;
    std::cout << earliestTimestamp.unix_time << std::endl;*/

    /*Twelvedata::Reference::SymbolSearchList symbolSearchList = Twelvedata::Reference::getSymbolSearchList(httpGet, {{"symbol", "AAPL"}});

    for (const auto &symbol : symbolSearchList.data) {
        std::cout << symbol.symbol << std::endl;
    }*/

    /*Twelvedata::Core::TimeSeries timeSeries = Twelvedata::Core::getTimeSeries(httpGet, {{"symbol", "AAPL"}, {"interval", "1min"}});

    std::cout << timeSeries.meta.symbol << std::endl;*/

    /*Twelvedata::Core::ExchangeRate exchangeRate = Twelvedata::Core::getExchangeRate(httpGet, {{"symbol", "USD/JPY"}});

    std::cout << exchangeRate.symbol << std::endl;*/

    /*Twelvedata::Core::CurrencyConversion currencyConversion = Twelvedata::Core::getCurrencyConversion(httpGet, {{"symbol", "USD/EUR"}, {"amount", "100"}});

    std::cout << currencyConversion.amount << std::endl;*/

    /*Twelvedata::Core::Quote quote = Twelvedata::Core::getQuote(httpGet, {{"symbol", "AAPL"}});

    std::cout << quote.symbol << std::endl;*/

    /*Twelvedata::Core::RealTimePrice realTimePrice = Twelvedata::Core::getRealTimePrice(httpGet, {{"symbol", "AAPL"}});

    std::cout << realTimePrice.price << std::endl;*/

    Twelvedata::Core::EndOfDayPrice endOfDayPrice = Twelvedata::Core::getEndOfDayPrice(httpGet, {{"symbol", "AAPL"}});

    std::cout << endOfDayPrice.close << std::endl;

    return 0;
}

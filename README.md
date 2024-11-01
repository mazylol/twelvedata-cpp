# twelvedata-cpp

This library handles requests to [twelvedata](https://twelvedata.com). You have to bring your own library. This is just a deserializer.

## Example using [cpr](https://github.com/libcpr/cpr):
```cpp
#include <twelvedata.hpp>
#include <cpr/cpr.h>

#include <iostream>
#include <string>
#include <unordered_map>

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
    auto stocksList = Twelvedata::Reference::getStocksList(httpGet, {{"symbol", "AAPL"}});
	
    for (const auto &stock : stocksList.data) {
        std::cout << stock.symbol << std::endl;
    }

    return 0;
}
```

## API Coverage
All the paid endpoints are not covered. If you want to use them, you will have to implement them yourself, I cannot in good conscience do it myself as I do not have paid access and cannot test it.
- Reference Data
  - [x] Stocks List `/stocks`
  - [x] Forex Pairs List `/forex_pairs`
  - [x] Cryptocurrencies List `/cryptocurrencies`
  - [x] Futures List `/futures`
  - [x] Bonds List `/bonds`
  - [x] ETFs List `/etfs`
  - [x] Indices List `/indices`
  - [x] Commodities List `/commodities`
  - [ ] Cross listings `/cross_listings` (Paid)
  - [x] Exchanges `/exchanges`
  - [ ] Exchange schedule `/exchange_schedule` (Paid)
  - [x] Cryptocurrency Exchanges `/cryptocurrency_exchanges`
  - [x] Market State `/market_state`
  - [ ] Instrument Type `/instrument_type`
  - [ ] Countries `/countries`
  - [ ] Technical Indicators Interface `/technical_indicators` (No idea how to implement, JSON structure is not standardized)
  - [ ] Earliest Timestamp `/earliest_timestamp`
  - [ ] Symbol Search `/symbol_search`

## Note
I HIGHLY recommend that you use parameters in your queries. For example, the /funds endpoint returns, at the time of writing this, 299364 entries. If you don't use parameters, you will get all of them. This is a waste of bandwidth and will take a considerable amount of time to deserialize. Use parameters to filter the results to what you need.
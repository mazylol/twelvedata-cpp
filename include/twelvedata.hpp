#ifndef TWELVEDATA_H
#define TWELVEDATA_H

#include <functional>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

namespace Twelvedata {
    namespace Reference {
        // Start Stock List
        struct Access {
            std::string global;
            std::string plan;
        };

        struct StockListItem {
            std::string symbol;
            std::string name;
            std::string currency;
            std::string mic_code;
            std::string country;
            std::string type;
            Access access;
        };

        struct StocksList {
            ;
            std::vector<StockListItem> data;
            int count;
            std::string status;

            [[maybe_unused]]
            StocksList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                       std::unordered_map<const char *, const char *> params);
        };
        // End Stock List

        // Start Forex Pairs List
        struct ForexPairListItem {
            std::string symbol;
            std::string currency_group;
            std::string currency_base;
            std::string currency_quote;
        };

        struct ForexPairsList {
            std::vector<ForexPairListItem> data;
            int count;
            std::string status;

            [[maybe_unused]]
            ForexPairsList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                           std::unordered_map<const char *, const char *> params);
        };
        // End Forex Pairs List

        // Start Cryptocurrencies List
        struct CryptocurrenciesListItem {
            std::string symbol;
            std::vector<std::string> available_exchanges;
            std::string currency_base;
            std::string currency_quote;
        };

        struct CryptocurrenciesList {
            std::vector<CryptocurrenciesListItem> data;
            int count;
            std::string status;

            [[maybe_unused]]
            CryptocurrenciesList(
                const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                std::unordered_map<const char *, const char *> params);
        };
        // End Cryptocurrencies List

        // Start Fund List
        struct FundListItem {
            std::string symbol;
            std::string name;
            std::string country;
            std::string currency;
            std::string exchange;
            std::string type;
            std::string figi_code;
        };

        struct FundResult {
            int count;
            std::vector<FundListItem> list;
        };

        struct FundsList {
            FundResult result;
            std::string status;

            [[maybe_unused]]
            FundsList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                      std::unordered_map<const char *, const char *> params);
        };
        // End Fund List

        // Start Bond List
        struct BondListItem {
            std::string symbol;
            std::string name;
            std::string country;
            std::string currency;
            std::string exchange;
            std::string type;
        };

        struct BondResult {
            int count;
            std::vector<BondListItem> list;
        };

        struct BondsList {
            BondResult result;
            std::string status;

            [[maybe_unused]]
            BondsList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                      std::unordered_map<const char *, const char *> params);
        };
        // End Bond List

        // Start ETF List
        struct EtfListItem {
            std::string symbol;
            std::string name;
            std::string currency;
            std::string exchange;
            std::string mic_code;
            std::string country;
            std::string figi_code;
        };

        struct EtfsList {
            std::vector<EtfListItem> data;
            int count;
            std::string status;

            [[maybe_unused]]
            EtfsList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                     std::unordered_map<const char *, const char *> params);
        };
        // End ETF List

        // Start Indices List
        struct IndexListItem {
            std::string symbol;
            std::string name;
            std::string country;
            std::string currency;
            std::string exchange;
            std::string mic_code;
        };

        struct IndicesList {
            std::vector<IndexListItem> data;
            int count;
            std::string status;

            [[maybe_unused]]
            IndicesList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                        std::unordered_map<const char *, const char *> params);
        };
        // End Indices List

        // Start Commodities List
        struct CommodityListItem {
            std::string symbol;
            std::string name;
            std::string category;
            std::string description;
        };

        struct CommoditiesList {
            std::vector<CommodityListItem> data;
            int count;
            std::string status;

            [[maybe_unused]]
            CommoditiesList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                            std::unordered_map<const char *, const char *> params);
        };
        // End Commodities List

        // Start Exchanges List
        struct ExchangeListItem {
            std::string name;
            std::string code;
            std::string country;
            std::string timezone;
        };

        struct Exchanges {
            std::vector<ExchangeListItem> data;
            std::string status;

            [[maybe_unused]]
            Exchanges(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                      std::unordered_map<const char *, const char *> params);
        };
        // End Exchanges List

        // Start Cryptocurrency Exchanges List
        struct CryptocurrencyExchangeListItem {
            std::string name;
        };

        struct CryptocurrencyExchanges {
            std::vector<CryptocurrencyExchangeListItem> data;
            std::string status;

            [[maybe_unused]]
            CryptocurrencyExchanges(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                                    std::unordered_map<const char *, const char *> params);
        };
        // End Cryptocurrency Exchanges List

        // Start Market State
        struct MarketStateItem {
            std::string name;
            std::string code;
            std::string country;
            bool is_market_open;
            std::string time_after_open;
            std::string time_to_open;
            std::string time_to_close;
        };

        [[maybe_unused]]
        std::vector<MarketStateItem> getMarketState(
            const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
            std::unordered_map<const char *, const char *> params);
        // End Market State

        // Start Instrument Type
        struct InstrumentType {
            std::vector<std::string> result;
            std::string status;

            [[maybe_unused]]
            InstrumentType(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                           std::unordered_map<const char *, const char *> params);
        };
        // End Instrument Type

        // Start Countries List
        struct CountryListItem {
            std::string iso2;
            std::string iso3;
            std::string numeric;
            std::string name;
            std::string official_name;
            std::string capital;
            std::string currency;
        };

        struct CountriesList {
            std::vector<CountryListItem> data;

            [[maybe_unused]]
            CountriesList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                          std::unordered_map<const char *, const char *> params);
        };
        // End Countries List

        // Start Earliest Timestamp
        struct EarliestTimestamp {
            std::string datetime;
            int unix_time;

            [[maybe_unused]]
            EarliestTimestamp(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                              std::unordered_map<const char *, const char *> params);
        };
        // End Earliest Timestamp

        // Start Symbol Search
        struct SymbolSearchItem {
            std::string symbol;
            std::string instrument_name;
            std::string exchange;
            std::string mic_code;
            std::string exchange_timezone;
            std::string instrument_type;
            std::string country;
            std::string currency;
        };

        struct SymbolSearchList {
            std::vector<SymbolSearchItem> data;
            std::string status;

            [[maybe_unused]]
            SymbolSearchList(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                             std::unordered_map<const char *, const char *> params);
        };
        // End Symbol Search
    }

    namespace Core {
        // Start Time Series
        struct TimeSeriesMeta {
            std::string symbol;
            std::string interval;
            std::string currency;
            std::string exchange_timezone;
            std::string exchange;
            std::string mic_code;
            std::string type;
        };

        struct TimeSeriesValue {
            std::string datetime;
            std::string open;
            std::string high;
            std::string low;
            std::string close;
            std::string volume;
        };

        struct TimeSeries {
            TimeSeriesMeta meta;
            std::vector<TimeSeriesValue> values;
            std::string status;

            [[maybe_unused]]
            TimeSeries(
                const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                std::unordered_map<const char *, const char *> params);
        };
        // End Time Series

        // Start Exchange Rate
        struct ExchangeRate {
            std::string symbol;
            double rate;
            int timestamp;

            [[maybe_unused]]
            ExchangeRate(
                const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                std::unordered_map<const char *, const char *> params);
        };
        // End Exchange Rate

        // Start Currency Conversion
        struct CurrencyConversion {
            std::string symbol;
            double rate;
            double amount;
            int timestamp;

            [[maybe_unused]]
            CurrencyConversion(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc,
                               std::unordered_map<const char *, const char *> params);
        };
        // End Currency Conversion

        // Start Quote
        struct FiftyTwoWeek {
            std::string low;
            std::string high;
            std::string low_change;
            std::string high_change;
            std::string low_change_percent;
            std::string high_change_percent;
            std::string range;
        };

        struct Quote {
            std::string symbol;
            std::string name;
            std::string exchange;
            std::string mic_code;
            std::string currency;
            std::string datetime;
            int timestamp;
            std::string open;
            std::string high;
            std::string low;
            std::string close;
            std::string volume;
            std::string previous_close;
            std::string change;
            std::string percent_change;
            std::string average_volume;
            bool is_market_open;
            FiftyTwoWeek fifty_two_week;

            [[maybe_unused]]
            Quote(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params);
        };
        // End Quote

        // Start Real Time Price
        struct RealTimePrice {
            std::string price;

            [[maybe_unused]]
            RealTimePrice(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params);
        };
        // End Real Time Price

        // Start End of Day Price
        struct EndOfDayPrice {
            std::string symbol;
            std::string exchange;
            std::string mic_code;
            std::string currency;
            std::string datetime;
            std::string close;

            [[maybe_unused]]
            EndOfDayPrice(const std::function<std::string(const char *, std::unordered_map<const char *, const char *>)> &getFunc, std::unordered_map<const char *, const char *> params);
        };
        // End End of Day Price
    }
}

#endif // TWELVEDATA_H

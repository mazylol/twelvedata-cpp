#ifndef TWELVEDATA_H
#define TWELVEDATA_H

#include <functional>
#include <string>
#include <vector>

using GetFunction = std::function<std::string(const char *)>;

namespace Twelvedata {
    struct Access {
        std::string global;
        std::string plan;
    };

    class Reference {
      public:
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
            std::vector<StockListItem> data;
            std::string status;
        };

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
        };
        
        /// get a list of stocks
        static StocksList getStocksList(GetFunction getFunc);

        /// get a list of forex pairs
        static ForexPairsList getForexPairsList(GetFunction getFunc);
    };
}

#endif

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
        
        /// get a list of stocks
        static StocksList getStocksList(GetFunction getFunc);
    };
}

#endif

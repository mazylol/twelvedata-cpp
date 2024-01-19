#ifndef TWELVEDATA_H
#define TWELVEDATA_H

#include <string>
#include <vector>

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

        static StocksList getStocksList(const char *key);
    };
}

#endif
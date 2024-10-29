#include <dotenv.h>
#include <twelvedata.hpp>

#include <cpr/cpr.h>

#include <iostream>

/// The function has to return a string and take a const char* as an argument
std::string httpGet(const char *endpoint) {
    std::string text = cpr::Get(cpr::Url{endpoint}, cpr::Header{{"Authorization", std::getenv("TWELVEDATA_API_KEY")}}).text;

    return text;
}

int main() {
    dotenv::init();

    //Twelvedata::Reference::StocksList stocksList = Twelvedata::Reference::getStocksList(httpGet);

    //for (const auto &stock : stocksList.data) {
    //    std::cout << stock.symbol << std::endl;
    //}

    Twelvedata::Reference::ForexPairsList forexPairsList = Twelvedata::Reference::getForexPairsList(httpGet);

    for (const auto &forexPair : forexPairsList.data) {
        std::cout << forexPair.symbol << std::endl;
    }

    return 0;
}

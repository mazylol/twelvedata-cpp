#include <dotenv.h>
#include <twelvedata.h>

#include <cpr/cpr.h>

#include <iostream>

std::string httpGet(const char *endpoint) {
    std::string text = cpr::Get(cpr::Url{endpoint}, cpr::Header{{"Authorization", std::getenv("TWELVEDATA_API_KEY")}}).text;

    return text;
}

int main() {
    dotenv::init();

    auto key = std::getenv("TWELVEDATA_API_KEY");

    Twelvedata::Reference::StocksList stocksList = Twelvedata::Reference::getStocksList(httpGet);

    for (const auto &stock : stocksList.data) {
        std::cout << stock.symbol << std::endl;
    }

    return 0;
}

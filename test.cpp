#include <twelvedata.h>
#include <dotenv.h>

#include <iostream>

int main() {
    dotenv::init();

    auto key = std::getenv("TWELVEDATA_API_KEY");

    Twelvedata::Reference::StocksList stocksList = Twelvedata::Reference::getStocksList(key);

    for (const auto &stock : stocksList.data) {
        std::cout << stock.symbol << std::endl;
    }

    return 0;
}

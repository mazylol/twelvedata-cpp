#include <twelvedata.h>
#include <dotenv.h>

#include <iostream>

int main() {
    dotenv::init();

    std::string key = dotenv::getenv("TWELVEDATA_API_KEY");

    Twelvedata::Reference::StocksList stocksList = Twelvedata::Reference::getStocksList(key.c_str());

    std::cout << stocksList.data[0].name << std::endl;

    return 0;
}
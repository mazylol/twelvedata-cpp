# Twelvedata-CPP

This library handles requests to Twelvedata. It is a bring your own http library situation.

Example using [cpr](https://github.com/libcpr/cpr):
```cpp
#include <twelvedata.h>
#include <cpr/cpr.h>

#include <iostream>
#include <string>

std::string httpGet(const char *endpoint) {
    std::string text = cpr::Get(cpr::Url{endpoint}, cpr::Header{{"Authorization", <your-token-here>}}).text;

    return text;
}

int main() {
    auto stocksList = Twelvedata::Reference::getStocksList(httpGet);
	
    for (const auto &stock : stocksList.data) {
        std::cout << stock.symbol << std::endl;
    }

    return 0;
}
```


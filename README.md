# Twelvedata-CPP

This library handles requests to Twelvedata. You have to bring your own library. This is just a deserializer.

Example using [cpr](https://github.com/libcpr/cpr):
```cpp
#include <twelvedata.h>
#include <cpr/cpr.h>

#include <iostream>
#include <string>
#include <unordered_map>

std::string httpGet(const char *endpoint, std::unordered_map<const char *, const char *>) {
    std::string url = endpoint;

    if (!params.empty()) {
        url += "?";

        for (const auto &param : params) {
            url += param.first + "=" + param.second + "&";
        }

        url.pop_back();
    }

    std::string text = cpr::Get(cpr::Url{url}, cpr::Header{{"Authorization", <your-token-here>}}).text;

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


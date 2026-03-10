#include "crow.h"
#include <unordered_map>
#include <string>
#include <random>

using namespace std;

unordered_map<string, string> urlMap;

// Random 6 character URL
string generateShortCode() {
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string result;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, (int)charset.size() - 1);

    for (int i = 0; i < 6; ++i) {
        result += charset[dis(gen)];
    }
    return result;
}

int main() {
    crow::SimpleApp app; //server initiation

    // Display Frontend
    CROW_ROUTE(app, "/")([]() {
        auto page = crow::mustache::load("index.html"); // find front code
        return page.render();
        });
    // User input and short URL generation 
    CROW_ROUTE(app, "/shorten").methods(crow::HTTPMethod::POST)([](const crow::request& req) {
        auto x = crow::json::load(req.body); // read input
        //validate response
        if (!x || !x.has("url")) {
            return crow::response(400, "missing 'url' field");
        }

        string longUrl = x["url"].s(); //take URL 
        string shortCode = generateShortCode();// Make short

        urlMap[shortCode] = longUrl; 
        //return new URL
        crow::json::wvalue res; // 
        res["shortCode"] = shortCode;
        return crow::response(res);
    });




    //Generates the list of shortened URLs
    CROW_ROUTE(app, "/list")([]() {
        crow::json::wvalue list;
        for (auto const& [code, url] : urlMap) {
            list[code] = url;
        }
        return crow::response(list);
        });

    //Checks if the short URL exists in our map
    CROW_ROUTE(app, "/<string>")([](string code) {
        if (urlMap.find(code) == urlMap.end()) {
            return crow::response(404, "Short code not found");
        }

        crow::response res;
        res.redirect(urlMap[code]);
        return res;
        });
    //launches localhost on port 18080
    app.port(18080).multithreaded().run();
}

//http://localhost:18080
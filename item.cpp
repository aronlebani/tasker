#include "item.h"
#include "nlohmann/json.hpp"

#include <string>

Item::Item() {
    this->complete  = false;
    this->text = "";
}

Item::Item(std::string text) {
    this->text = text;
    this->complete = false;
}

void Item::markAsComplete() {
    this->complete = true;
}

std::string Item::display() {
    if (this->complete) {
        return "[x] " + this->text;
    }
    else {
        return "[ ] " + this->text;
    }
}

void Item::parse(nlohmann::json item) {
    this->text = item["text"];
    this->complete = item["complete"];
}

nlohmann::json Item::dump() {
    nlohmann::json item = {
        {"text", this->text},
        {"complete", this->complete}
    };
    return item;
}
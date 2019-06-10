#ifndef ITEM_H
#define ITEM_H

#include "nlohmann/json.hpp"

#include <string>

class Item {
    public:
        Item();
        Item(std::string text);
        void markAsComplete();
        std::string display();
        void parse(nlohmann::json item);
        nlohmann::json dump();

    private:
        std::string text;
        bool complete;
};

#endif
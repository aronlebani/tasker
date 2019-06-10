#ifndef LIST_H
#define LIST_H

#include "item.h"
#include "nlohmann/json.hpp"

#include <vector>

class List {
    public:
        List();
        void addItem(Item item);
        void removeItem(int index);
        void completeItem(int index);
        void print();
        void save();
        void read();
    private:
        std::vector<Item> list;
        std::string filePath;

        void parse(nlohmann::json list);
        nlohmann::json dump();
};

#endif
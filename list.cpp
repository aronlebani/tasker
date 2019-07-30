#include "list.h"
#include "nlohmann/json.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

List::List() {
    this->list = std::vector<Item>();
    this->filePath = "./.tasker.json";
}

void List::addItem(Item item) {
    this->list.push_back(item);
}

void List::removeItem(int index) {
    this->list.erase(this->list.begin() + index);
}

void List::completeItem(int index) {
    this->list[index].markAsComplete();
}

void List::print() {
    std::cout << "Tasker" << std::endl << std::endl;
    if (this->list.size() > 0) {
        for (int i = 0; i < this->list.size(); i++) {
            std::cout << this->list[i].display(i) << std::endl;
        }
    }
    std::cout << std::endl;
}

void List::save() {
    std::ofstream file(this->filePath);

    nlohmann::json data = this->dump();
    std::stringstream buffer(data.dump());
    buffer >> file.rdbuf();
    file.close();
}

void List::read() {
    std::ifstream ifs{ this->filePath };
    if (!ifs.good()) {
        this->save();
    } else {
        nlohmann::json data = nlohmann::json::parse(ifs);
        this->parse(data);
    }
}

void List::parse(nlohmann::json list) {
    std::vector<Item> items;
    for (int i = 0; i < list["list"].size(); i++) {
        Item * item = new Item();
        item->parse(list["list"][i]);
        items.push_back(* item);
    }
    this->list = items;
}

nlohmann::json List::dump() {
    nlohmann::json list;
    std::vector<nlohmann::json> items;
    for (int i = 0; i < this->list.size(); i++) {
        items.push_back(this->list[i].dump());
    }
    list["list"] = items;
    return list;
}
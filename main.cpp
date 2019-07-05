#include "list.h"
#include "item.h"

#include <string>
#include <stdlib.h>

#include <iostream>

std::string getName(std::vector<std::string> name);
void clearScreen();

int main(int argc, char * argv[]) {

    std::vector<std::string> args;
    for(int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }

    List * list = new List();
    list->read();

    if (args.size() == 1) {
        clearScreen();
        list->print();
    }

    if (args[1].compare("a") == 0) {
        std::cout << "add" << std::endl;
        Item * item = new Item(getName(args));
        list->addItem(* item);
        list->save();
        clearScreen();
        list->print();
    }

    if (args[1].compare("r") == 0) {
        int index = atoi(argv[2]);
        list->removeItem(index);
        list->save();
        clearScreen();
        list->print();
    }

    if (args[1].compare("c") == 0) {
        int index = atoi(argv[2]);
        list->completeItem(index);
        list->save();
        clearScreen();
        list->print();
    }

    return 0;
}

std::string getName(std::vector<std::string> args) {
    std::string name = "";
    for (int i = 2; i < args.size(); i++) {
        if (i != args.size() - 1) {
            name += (args[i] + " ");
        } else {
            name += args[i];
        }
    }
    return name;
}

void clearScreen() {
    system("clear");
}
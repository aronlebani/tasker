#include "list.h"
#include "item.h"

#include <string>
#include <stdlib.h>

#include <iostream>

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

    if (args[1].compare("add") == 0) {
        std::cout << "add" << std::endl;
        Item * item = new Item(argv[2]);
        list->addItem(* item);
        list->save();
        clearScreen();
        list->print();
    }

    if (args[1].compare("remove") == 0) {
        int index = atoi(argv[2]);
        list->removeItem(index);
        list->save();
        clearScreen();
        list->print();
    }

    if (args[1].compare("complete") == 0) {
        int index = atoi(argv[2]);
        list->completeItem(index);
        list->save();
        clearScreen();
        list->print();
    }

    return 0;
}

void clearScreen() {
    system("clear");
}
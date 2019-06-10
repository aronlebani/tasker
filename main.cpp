#include "list.h"
#include "item.h"

#include <string>
#include <stdlib.h>

#include <iostream>

void clearScreen();

int main(int argc, char * argv[]) {
    List * list = new List();
    list->read();

    clearScreen();
    list->print();

    if (strcmp(argv[1], "add")) {
        Item * item = new Item(argv[2]);
        list->addItem(* item);
        list->save();
        clearScreen();
        list->print();
    }

    if (strcmp(argv[1], "remove")) {
        int index = atoi(argv[2]);
        list->removeItem(index);
        list->save();
        clearScreen();
        list->print();
    }

    if (strcmp(argv[1], "complete")) {
        int index = atoi(argv[2]);
        list->completeItem(index);
        list->save();
        clearScreen();
        list->print();
    }

    return 0;
}

void clearScreen() {
    // system("clear");
}
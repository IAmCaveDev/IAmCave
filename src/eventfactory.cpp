#include "eventfactory.h"


std::unique_ptr<Event> EventFactory::createEvent(short id, EventTypes type) {
    std::string path = "assets/events/";
    if (id < 10) {
        path = path + "0" + "0";
    }
    else {
        path = path + "0";
    }
    path = path + std::to_string(id) + "*.json";

    std::unique_ptr<Event> event(new Event(path));
    return event;
}

std::unique_ptr<Event> EventFactory::createRandomEvent(EventTypes type) {
    std::string path = "assets/events/";

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<short> distribution(1, 20); //Change max event id later or make dynamic

    short id = distribution(rng);
    if (id < 10) {
        path = path + "0" + "0";
    } else {
        path = path + "0";
    }
    path = path + std::to_string(id) + "*.json";

    std::unique_ptr<Event> event(new Event(std::to_string(0)));
    return event;
}
#include "eventfactory.h"


std::shared_ptr<Event> EventFactory::createEvent(short id, EventTypes type) {
    std::string path = "assets/events/";

    switch (type) {
    case Narrative:
        path += "narrative/";
        break;
    case Random:
        path += "random/";
        break;
    default:
        break;
    }

    if (id < 10) {
        path += "00";
    } else {
        path += "0";
    }

    path += std::to_string(id) + ".json";

    std::shared_ptr<Event> event(new Event(path));
    return event;
}

std::shared_ptr<Event> EventFactory::createRandomEvent() {
    std::string path = "assets/events/random/";

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<short> distribution(1, 24); //Change max event id later or make dynamic

    short id = distribution(rng);
    if (id < 10) {
        path += "00";
    } else {
        path += "0";
    }
    path += std::to_string(id) + ".json";

    std::shared_ptr<Event> event(new Event(path));
    return event;
}
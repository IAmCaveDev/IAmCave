#include "eventfactory.h"

std::unique_ptr<Event> EventFactory::createEvent(short id, EventTypes type) {
    std::string path = "assets/events/" + std::to_string(type) + "/";
    std::unique_ptr<Event> event(new Event(std::to_string(id)));
    return event;
}

std::unique_ptr<Event> EventFactory::createRandomEvent(EventTypes type) {
    std::unique_ptr<Event> event(new Event(std::to_string(0)));
    return event;
}
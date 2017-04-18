#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H

#include <random>
#include <fstream>

#include "event.h"

class EventFactory {
public:
    /**
    * Specific event factory method.
    * Creates an event with its modifiers located at assets/events/type/id*.json.
    */
    std::unique_ptr<Event> createEvent(short id, EventTypes type);
    /**
    * Random event factory method.
    * Is currently not safe to use due to unchecked file availability.
    */
    std::unique_ptr<Event> createRandomEvent(EventTypes type);
};

#endif
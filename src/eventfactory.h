#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H

#include <memory>

#include "event.h"
#include "enum.h"

class EventFactory {
public:
    std::unique_ptr<Event> createEvent(short id, EventTypes type);
};

#endif
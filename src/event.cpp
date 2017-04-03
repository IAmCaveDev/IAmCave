#include "event.h"

Event::Event(std::string path) {
    std::ifstream in(path);
    if (in.good()) {
        json data;
        in >> data;

        id = data["id"];
        title = data["title"];
        description = data["description"];

        trigger = { ETechs::Handaxe, data["trigger"]["tribeSize"], data["trigger"]["tribeFood"], data["trigger"]["tribeMaterial"] };
        std::unique_ptr<Option> option;
        option->name = data["option"]["name"];
        option->effects.foodGain = data["option"]["food"];
        option->effects.materialGain = data["option"]["materials"];

        options.push_back(option);
    }
    else {
        throw std::runtime_error("Could not open file at " + path);
    }
}

Event::~Event() {
}
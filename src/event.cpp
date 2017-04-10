#include "event.h"

#include "buttonfunctions.h"

Event::Event(std::string path) {
    std::ifstream in(path);

    if (in.good()) {
        json data;
        in >> data;

        id = data["id"];
        title = data["title"];
        description = data["description"];

        if (!data["trigger"]["has_tech"].empty()) trigger.has_tech = data["trigger"]["has_tech"];
        if (!data["trigger"]["missing_tech"].empty()) trigger.missing_tech = data["trigger"]["missing_tech"];
        if (!data["trigger"]["tribeFood"].empty()) trigger.tribeFood = data["trigger"]["tribeFood"];
        if (!data["trigger"]["tribeSize"].empty()) trigger.tribeSize = data["trigger"]["tribeSize"];
        if (!data["trigger"]["tribeMaterial"].empty()) trigger.tribeMaterial = data["trigger"]["tribeMaterial"];

        for (auto& it : data["options"]) {
        std::unique_ptr<Option> option(new Option{ "", {0.0, 0.0, 0.0, 0.0, 0, 0.0, 0, 0, 0, 0, false } });
            option->name = it["name"];
            if (!it["huntBonus"].empty()) option->effects.huntBonus = it["huntBonus"];
            if (!it["gatheringBonus"].empty()) option->effects.gatheringBonus = it["gatheringBonus"];
            if (!it["fitnessGain"].empty()) option->effects.fitnessGain = it["fitnessGain"];
            if (!it["intelligenceGain"].empty()) option->effects.intelligenceGain = it["intelligenceGain"];
            if (!it["capacityGain"].empty()) option->effects.capacityGain = it["capacityGain"];
            if (!it["foodGain"].empty()) option->effects.foodGain = it["foodGain"];
            if (!it["materialGain"].empty()) option->effects.materialGain = it["materialGain"];

            for (auto& caveman : it["cavemen"]) {
                option->effects.new_age = caveman["age"];
                option->effects.new_fitness = caveman["fitness"];
                option->effects.new_intelligence = caveman["intelligence"];
                option->effects.new_isMale = caveman["isMale"];
            }

            options.push_back(std::move(option));
        }
    }
    else {
        throw std::runtime_error("Could not open file at " + path);
    }

    eventbox = new Textbox({ 200, 200 }, { 450, 400 }, "assets/info.png", description);
}

Event::~Event() {
}

void Event::initButtons() {
    short numOptions = options.size();
    for (auto& it : options) {
    }
}

void Event::display(sf::RenderWindow& win) const {
    for (auto& it : options) {
        win.draw(*it->button);
}
    win.draw(*eventbox);
}
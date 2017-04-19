#include "event.h"

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
        std::shared_ptr<Option> option(new Option{ it["name"], {0.0, 0.0, 0.0, 0.0, 0, 0.0, 0, 0, 0, 0, false } });
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
            //std::shared_ptr<Button> button(new Button({ 200, 100 }, { 850, 700 }, "assets/confirm.png", std::bind([&]() {}), nullptr));
            //option->button = button;
            options.push_back(std::move(option));
        }
    }
    else {
        throw std::runtime_error("Could not open file at " + path);
    }
    
    textbox = new Textbox({ 700, 250 }, { 850, 400 }, "assets/info.png", title + "\n" + description);
}

Event::~Event() {
}

Event::Trigger Event::getTrigger() const {
    return trigger;
}

std::vector<std::shared_ptr<Event::Option>> Event::getOptions() const {
    return options;
}

Textbox* Event::getTextBox() const {
    return textbox;
}

short Event::getID() const {
    return id;
}
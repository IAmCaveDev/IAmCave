#include "event.h"

Event::Event(std::string path) {
    //std::ifstream in(path);
    std::ifstream in;
    in.open("assets/events/000-test.json", std::ios::in);

    if (in.good()) {
        json data;
        in >> data;

        id = data["id"];
        title = data["title"];
        description = data["description"];


        if (!data["trigger"]["techResearched"].empty()) trigger.techResearched = data["trigger"]["techResearched"];
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
}

Event::~Event() {
}
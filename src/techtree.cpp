#include "techtree.h"

#include <stdexcept>
#include <fstream>

void Techtree::parse(std::shared_ptr<Tech> parent, json data,
                     TransformedVector<> lastPos) {
    std::string techPath = "assets/tech/" + data["name"].get<std::string>() +
                           ".json";
    auto newParent = tree.emplace(new Tech(techPath, {parent}));

    newParent.first->get()->getButton().setTransformedPosition(lastPos);

    // if already exists in tree
    if (!newParent.second) {
        newParent.first->get()->getParents().push_back(parent);
    }

    int i = 0;
    for (auto& it : data["children"]) {
        i += 1;

        parse(*newParent.first, it,
              {lastPos.getRealX() + techSize + padding,
               size.getRealY() / static_cast<int>(data["children"].size() + 1)
               * i});
    }
}

Techtree::Techtree(std::string path, TransformedVector<> newSize,
                   TransformedVector<> newPos) {
    size = newSize;
    pos = newPos;

    std::ifstream in(path);
    if (in.good()) {
        json data;
        in >> data;

        std::string techPath = "assets/tech/" +
                               data["name"].get<std::string>() + ".json";

        parse(nullptr, data, {pos.getRealX(),
                              pos.getRealY() + size.getRealY() / 2 - techSize});
    } else {
        throw std::runtime_error("Could not open file at " + path);
    }
}

void Techtree::display(sf::RenderWindow& win) {
    for(auto& it : tree){
        it->getButton().display(win);
        // TODO: Draw arrows
    }
}

#include "techtree.h"

#include <stdexcept>
#include <fstream>

void Techtree::positionTree(json data, short level) {

}

void Techtree::parse(std::shared_ptr<Tech> parent, json data, short level) {
    std::string techPath = "assets/tech/" + data["name"].get<std::string>() +
                           ".json";
    auto newParent = tree.emplace(new Tech(techPath, {parent}));

    //newParent.first->get()->getButton().setTransformedPosition(lastPos);

    // if already exists in tree
    if (!newParent.second) {
        newParent.first->get()->getParents().push_back(parent);
    }
    else {
        sizePerLevel[level] += 1;
    }

    for (auto& it : data["children"]) {

        parse(*newParent.first, it, level+1);
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

        parse(nullptr, data, 0);

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

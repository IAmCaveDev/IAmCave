#include "techtree.h"

#include <stdexcept>
#include <fstream>

void Techtree::positionTree(json data, short level,
                            TransformedVector<> lastPos) {
    std::string name = data["name"].get<std::string>();

    auto p = tree[name];

    p->getButton().setTransformedPosition(lastPos);

    short i = 0;
    for (auto& it : data["children"]) {
        int posY;

        if (sizePerLevel[level] == 1) {
            posY = pos.getRealY() + size.getRealY()/2 - techSize/2;
        } else {
            posY = pos.getRealY() + size.getRealY() - size.getRealY()
                       / (sizePerLevel[level] - 1) * i;

            if (i > 0 && i < (sizePerLevel[level] - 1)) {
                posY -= techSize / 2;
            } else if(i == 0) {
                posY -= techSize;
            }
        }

        positionTree(it, level + 1, {lastPos.getRealX()+techSize+padding,posY});
        i += 1;
    }
}

void Techtree::parse(std::shared_ptr<Tech> parent, json data, short level) {
    std::string name = data["name"].get<std::string>();
    std::string techPath = "assets/tech/" + name + ".json";
    auto newParent = tree.emplace(name, new Tech(techPath, {parent}));

    // if already exists in tree
    if (!newParent.second) {
        newParent.first->second->getParents().push_back(parent);
    } else {
        try {
            sizePerLevel.at(level);

            sizePerLevel[level] += 1;
        }
        catch(const std::out_of_range& oor) {
            sizePerLevel.push_back(1);
        }
    }

    for (auto& it : data["children"]) {
        parse(newParent.first->second, it, level+1);
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

        parse(nullptr, data, 0);
        positionTree(data, 1, {pos.getRealX(),pos.getRealY()+size.getRealY()/2-techSize/2});
    } else {
        throw std::runtime_error("Could not open file at " + path);
    }
}

void Techtree::display(sf::RenderWindow& win) {
    for (auto& it : tree) {
        it.second->getButton().display(win);
        // TODO: Draw arrows
    }
}

void Techtree::onResize() {
    for (auto& it : tree) {
        auto& button = it.second->getButton();
        button.setPosition(button.getTransformedPosition());
        button.setSize(button.getTransformedSize());
    }
}

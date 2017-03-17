#include "techtree.h"

#include <fstream>

void Techtree::parse(std::shared_ptr<Tech> parent, json data) {
    std::string techPath = data["name"].dump().append(".json");
    auto newParent = tree.emplace(new Tech(techPath, {parent}));

    // if already exists in tree
    if (!newParent.second) {
        newParent.first->get()->getParents().push_back(parent);
    }

    for(auto& it : data["children"]){
        parse(*newParent.first, it);
    }
}

Techtree::Techtree(std::string path) {
    std::ifstream in(path);
    json data;
    in >> data;

    std::string techPath = data["name"].dump().append(".json");
    auto root = tree.emplace(new Tech(techPath, {nullptr}));

    parse(*root.first, data);
}

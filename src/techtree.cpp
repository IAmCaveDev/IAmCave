#include "techtree.h"

#include <stdexcept>
#include <fstream>

void Techtree::positionTree(json data, short level,
                            TransformedVector<> lastPos) {
    std::string name = data["name"].get<std::string>();

    auto p = tree[name];

    if (level - 1 == p->getLevel()) {
        p->getButton().setTransformedPosition(lastPos);
    }

    for (auto& it : p->getParents()) {
        std::shared_ptr<Tech> parent;
        while (parent != nullptr) {
            parent = it->getParents()[0];
        }
    }

    for (auto& it : data["children"]) {
        int sizeY = getTransformedSize().getRealY() - (paddingTop + paddingBottom);
        int posY = getTransformedPosition().getRealY();

        if (sizePerLevel[level] == 1) {
            posY += sizeY/2 - techSize/2;
        } else {
            posY += sizeY - sizeY / (sizePerLevel[level] - 1) *
                    iteratorPerLevel[level];

            if (iteratorPerLevel[level] > 0 && iteratorPerLevel[level] < (sizePerLevel[level] - 1)) {
                posY -= techSize / 2;
            } else if(iteratorPerLevel[level] == 0) {
                posY -= techSize;
            }
        }

        positionTree(it, level + 1, {lastPos.getRealX()+techSize+techPadding,posY+paddingTop});

        iteratorPerLevel[level] += 1;
    }
}

void Techtree::parse(std::shared_ptr<Tech> parent, json data, short level) {
    std::string name = data["name"].get<std::string>();
    std::string techPath = "assets/tech/" + name + ".json";
    bool straight;
    try {
        straight = data.at("straight");
    }
    catch(std::out_of_range& oor) {
        straight = false;
    }
    auto newParent = tree.emplace(name, new Tech(techPath, level, {parent},
                                  straight));

    // if already exists in tree
    if (!newParent.second) {
        newParent.first->second->getParents().push_back(parent);
        if (level > newParent.first->second->getLevel()) {
            newParent.first->second->setLevel(level);
        }
    } else {
        try {
            sizePerLevel.at(level);

            sizePerLevel[level] += 1;
        }
        catch(const std::out_of_range& oor) {
            sizePerLevel.push_back(1);
            iteratorPerLevel.push_back(0);
        }
    }

    for (auto& it : data["children"]) {
        parse(newParent.first->second, it, level+1);
    }
}

Techtree::Techtree(std::string backgroundPath, std::string path,
                   TransformedVector<> newSize, TransformedVector<> newPos,
                   int newPaddingTop, int newPaddingBottom, int newPaddingLeft)
                   : Rectangle(newSize, newPos, backgroundPath) {
    paddingTop = newPaddingTop;
    paddingBottom = newPaddingBottom;
    paddingLeft = newPaddingLeft;
    visibility = false;

    textbox = new Textbox({1580, 160}, {20, 1080 - 180},
                           "assets/state-textbox.png", "", 15, 30);

    std::ifstream in(path);
    if (in.good()) {
        json data;
        in >> data;

        parse(nullptr, data, 0);
        positionTree(data, 1, {getTransformedPosition().getRealX() + paddingLeft,
                               getTransformedPosition().getRealY() + paddingTop
                               + (getTransformedSize().getRealY() - (paddingTop + paddingBottom)) / 2
                               - techSize / 2});
        for (auto& it : tree) {
            it.second->createArrowsToParents();
        }
    } else {
        throw std::runtime_error("Could not open file at " + path);
    }

    training = std::shared_ptr<Tech>(new Tech("assets/tech/training.json", 0, { nullptr }));
    training->getButton().setVisibility(false);
    trainingButton = new Button({ 200, 80 }, { -250, -300 }, "assets/think.png", nullptr);

    properThinking = new Button({ 200, 80 }, { -250, -200 }, "assets/confirm.png", nullptr);
    abortThinking = new Button({ 200, 80 }, { -250, -100 }, "assets/abort.png", nullptr);
}

void Techtree::setVisibility(bool newVisibility) {
    visibility = newVisibility;
    for (auto& it : tree) {
        it.second->updateButtonState();
        it.second->getButton().setVisibility(newVisibility);
    }
}

bool Techtree::getVisibility() {
    return visibility;
}

void Techtree::setTextboxText(std::string str) {
    textbox->setText(str);
}

void Techtree::display(sf::RenderWindow& win) {
    if (visibility) {
        this->Rectangle::display(win);
        for (auto& it : tree) {
            it.second->getButton().display(win);
            win.draw(it.second->getArrowsToParents().tip);
            for(auto& line : it.second->getArrowsToParents().lines) {
                win.draw(line);
                sf::Transform transform;

                transform.translate(0, 1);
                win.draw(line, transform);

                transform.translate(0, -2);
                win.draw(line, transform);

                transform.translate(1, 1);
                win.draw(line, transform);

                transform.translate(-2, 0);
                win.draw(line, transform);
            }
        }
        trainingButton->display(win);
        properThinking->display(win);
        abortThinking->display(win);
        textbox->display(win);
    }
}

void Techtree::onResize() {
    for (auto& it : tree) {
        auto& button = it.second->getButton();
        button.setPosition(button.getTransformedPosition());
        button.setSize(button.getTransformedSize());

        it.second->updateArrowsToParents();
    }
    trainingButton->setPosition(trainingButton->getTransformedPosition());
    properThinking->setPosition(properThinking->getTransformedPosition());
    abortThinking->setPosition(abortThinking->getTransformedPosition());
    trainingButton->setSize(trainingButton->getTransformedSize());
    properThinking->setSize(properThinking->getTransformedSize());
    abortThinking->setSize(abortThinking->getTransformedSize());
    setPosition(getTransformedPosition());
    setSize(getTransformedSize());
    textbox->setTransformedPosition(textbox->getTransformedPosition());
    textbox->setTransformedSize(textbox->getTransformedSize());
}

std::map<std::string, std::shared_ptr<Tech>>& Techtree::getTree() {
    return tree;
}

std::shared_ptr<Tech>& Techtree::getTraining() {
    return training;
}

Button& Techtree::getTrainingButton() {
    return *trainingButton;
}

Button& Techtree::getProperThinking() {
    return *properThinking;
}

Button& Techtree::getAbortThinking() {
    return *abortThinking;
}

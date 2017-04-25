#include "resourcedisplay.h"

ResourceDisplay::ResourceDisplay(Game& gameRef) : gameRef(gameRef),
                    food({ 80, 40 }, {1270,55 }, "assets/testbox2.png", "", 7, 20,sf::Color::White),
                    buildingMaterial({ 80, 40 }, { 1500, 760 }, "assets/testbox2.png", "", 7, 20, sf::Color::White),
                    cavemanCapacity({ 80, 40 }, { 630, 210 }, "assets/testbox2.png", "", 7, 20, sf::Color::White),
                    foodHeap({ 200,400 }, { 1200,100 }, "assets/heaps/meat-m.png"),
                    materialHeap({ 300,600 }, { 1350,240}, "assets/heaps/stones-m.png"),
                    caveHeap({ 400,400 }, { 400, 200 }, "assets/heaps/cave-painting-s.png") {

}

void ResourceDisplay::update() {
    Resources newResources = gameRef.getResources();
    food.setText(" "+std::to_string(int(newResources.food)));
    buildingMaterial.setText(" "+std::to_string(newResources.buildingMaterial));
    cavemanCapacity.setText(" "+std::to_string(newResources.cavemanCapacity));
    if (newResources.food >= 300) {
        foodHeap.changeTexture("assets/heaps/meat-l.png");
    }
    else if (newResources.food >= 100) {
        foodHeap.changeTexture("assets/heaps/meat-m.png");
    }
    else {
        foodHeap.changeTexture("assets/heaps/meat-s.png");
    }
    if (newResources.buildingMaterial >= 100) {
        materialHeap.changeTexture("assets/heaps/stones-l.png");
    }
    else if (newResources.buildingMaterial >= 50) {
        materialHeap.changeTexture("assets/heaps/stones-m.png");
    }
    else {
        materialHeap.changeTexture("assets/heaps/stones-s.png");
    }
    if (newResources.cavemanCapacity >= 10) {
        caveHeap.changeTexture("assets/heaps/cave-painting-l.png");
    }
    else if (newResources.cavemanCapacity >= 6) {
        caveHeap.changeTexture("assets/heaps/cave-painting-m.png");
    }
    else {
        caveHeap.changeTexture("assets/heaps/cave-painting-s.png");
    }
}

void ResourceDisplay::display(sf::RenderWindow& win) {
    update();
    materialHeap.display(win);
    caveHeap.display(win);
    food.display(win);
    foodHeap.display(win);
    buildingMaterial.display(win);
    cavemanCapacity.display(win);
}

void ResourceDisplay::onResize() {
    foodHeap.setSize(foodHeap.getTransformedSize());
    foodHeap.setPosition(foodHeap.getTransformedPosition());

    materialHeap.setSize(materialHeap.getTransformedSize());
    materialHeap.setPosition(materialHeap.getTransformedPosition());

    caveHeap.setSize(caveHeap.getTransformedSize());
    caveHeap.setPosition(caveHeap.getTransformedPosition());

    food.setSize(food.getTransformedSize());
    food.setPosition(food.getTransformedPosition());

    buildingMaterial.setSize(buildingMaterial.getTransformedSize());
    buildingMaterial.setPosition(buildingMaterial.getTransformedPosition());

    cavemanCapacity.setSize(cavemanCapacity.getTransformedSize());
    cavemanCapacity.setPosition(cavemanCapacity.getTransformedPosition());
}

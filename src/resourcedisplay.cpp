#include "resourcedisplay.h"

ResourceDisplay::ResourceDisplay(Game& gameRef) : gameRef(gameRef), 
                    foodHeap({ 200,400 }, { 1200,100 }, "assets/heaps/meat-m.png"), 
                    materialHeap({ 300,600 }, { 1350,240}, "assets/heaps/stones-m.png"),
                    food({ 70, 30 }, {1180,100 }, "assets/testbox.png", "", 5, 20), 
                    buildingMaterial({ 70, 30 }, { 1320, 740 }, "assets/testbox.png", "", 5, 20),
                    cavemanCapacity({ 70, 30 }, { 500, 400 }, "assets/testbox.png", "", 5, 20){   
}

void ResourceDisplay::update() {
    Resources newResources = gameRef.getResources();
    food.setText(std::to_string(int(newResources.food)));
    buildingMaterial.setText(std::to_string(newResources.buildingMaterial));
    cavemanCapacity.setText(std::to_string(newResources.cavemanCapacity));
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
}

void ResourceDisplay::display(sf::RenderWindow& win) {
    update();
    food.display(win);
    foodHeap.display(win);
    buildingMaterial.display(win);
    materialHeap.display(win);
    cavemanCapacity.display(win);
}

void ResourceDisplay::onResize() {
    foodHeap.setSize(foodHeap.getTransformedSize());
    foodHeap.setPosition(foodHeap.getTransformedPosition());

    materialHeap.setSize(materialHeap.getTransformedSize());
    materialHeap.setPosition(materialHeap.getTransformedPosition());

    food.setSize(food.getTransformedSize());
    food.setPosition(food.getTransformedPosition());

    buildingMaterial.setSize(buildingMaterial.getTransformedSize());
    buildingMaterial.setPosition(buildingMaterial.getTransformedPosition());

    cavemanCapacity.setSize(cavemanCapacity.getTransformedSize());
    cavemanCapacity.setPosition(cavemanCapacity.getTransformedPosition());
}
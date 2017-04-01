#include "caveman.h"

#include <random>
#include <vector>

#include "buttonfunctions.h"

short Caveman::counter = 0;

std::vector<std::string> femaleNames = {
    "Hillary",
    "Liz",
    "Gina",
    "Chelsea",
    "Luna",
    "Giny",
    "Selina",
    "Lillian",
    "Harleen"
};

std::vector<std::string> maleNames = {
    "Donald",
    "Bernie",
    "Harambe",
    "Gabe",
    "Matthew",
    "Harry",
    "Ron",
    "Oswald",
    "Bruce"
};

std::vector<std::string> femaleTextures = {

	"assets/women/woman-1.png",
	"assets/women/woman-2.png",
	"assets/women/woman-3.png",
	"assets/women/woman-4.png",
	"assets/women/woman-5.png",
	"assets/women/woman-6.png",
	"assets/women/woman-7.png",
	"assets/women/woman-8.png",
	"assets/women/woman-9.png",
	"assets/women/woman-10.png",
	"assets/women/woman-11.png",
	"assets/women/woman-12.png",
	"assets/women/woman-13.png",
	"assets/women/woman-14.png",
	"assets/women/woman-15.png",
	"assets/women/woman-16.png",
	"assets/women/woman-17.png",
	"assets/women/woman-18.png",
	"assets/women/woman-19.png",
	"assets/women/woman-20.png",
	"assets/women/woman-21.png",
	"assets/women/woman-22.png",
	"assets/women/woman-23.png",
	"assets/women/woman-24.png",
	"assets/women/woman-25.png",
	"assets/women/woman-26.png",
	"assets/women/woman-27.png",
	"assets/women/woman-28.png",
	"assets/women/woman-29.png",
	"assets/women/woman-30.png",
	"assets/women/woman-31.png",
	"assets/women/woman-32.png",
	"assets/women/woman-33.png",
	"assets/women/woman-34.png",
	"assets/women/woman-35.png",
	"assets/women/woman-36.png",
	"assets/women/woman-37.png",
	"assets/women/woman-38.png",
	"assets/women/woman-39.png",
	"assets/women/woman-40.png",
	"assets/women/woman-41.png",
	"assets/women/woman-42.png",
	"assets/women/woman-43.png",
	"assets/women/woman-44.png",
	"assets/women/woman-45.png",
	"assets/women/woman-46.png",
	"assets/women/woman-47.png",
	"assets/women/woman-48.png",
	"assets/women/woman-49.png",
	"assets/women/woman-50.png",
	"assets/women/woman-51.png",
	"assets/women/woman-52.png",
	"assets/women/woman-53.png",
	"assets/women/woman-54.png",
	"assets/women/woman-55.png",
	"assets/women/woman-56.png",
	"assets/women/woman-57.png",
	"assets/women/woman-58.png",
	"assets/women/woman-59.png",
	"assets/women/woman-60.png",
	"assets/women/woman-61.png",
	"assets/women/woman-62.png",
	"assets/women/woman-63.png",
	"assets/women/woman-64.png",
	"assets/women/woman-65.png",
	"assets/women/woman-66.png",
	"assets/women/woman-67.png",
	"assets/women/woman-68.png",
	"assets/women/woman-69.png",
	"assets/women/woman-70.png",
	"assets/women/woman-71.png",
	"assets/women/woman-72.png",
	"assets/women/woman-73.png",
	"assets/women/woman-74.png",
	"assets/women/woman-75.png",
	"assets/women/woman-76.png",
	"assets/women/woman-77.png",
	"assets/women/woman-78.png",
	"assets/women/woman-79.png",
	"assets/women/woman-80.png",
	"assets/women/woman-81.png",
	"assets/women/woman-82.png",
	"assets/women/woman-83.png",
	"assets/women/woman-84.png",
	"assets/women/woman-85.png",
	"assets/women/woman-86.png",
	"assets/women/woman-87.png",
	"assets/women/woman-88.png",
	"assets/women/woman-89.png",
	"assets/women/woman-90.png",
	"assets/women/woman-91.png",
	"assets/women/woman-92.png",
	"assets/women/woman-93.png",
	"assets/women/woman-94.png",
	"assets/women/woman-95.png",
	"assets/women/woman-96.png",
	"assets/women/woman-97.png",
	"assets/women/woman-98.png",
	"assets/women/woman-99.png",
	"assets/women/woman-100.png",
	"assets/women/woman-101.png",
	"assets/women/woman-102.png",
	"assets/women/woman-103.png",
	"assets/women/woman-104.png",
	"assets/women/woman-105.png",
	"assets/women/woman-106.png",
	"assets/women/woman-107.png",
	"assets/women/woman-108.png",
	"assets/women/woman-109.png",
	"assets/women/woman-110.png",
	"assets/women/woman-111.png",
	"assets/women/woman-112.png",
	"assets/women/woman-113.png",
	"assets/women/woman-114.png",
	"assets/women/woman-115.png",
	"assets/women/woman-116.png",
	"assets/women/woman-117.png",
	"assets/women/woman-118.png",
	"assets/women/woman-119.png",
	"assets/women/woman-120.png",
	"assets/women/woman-121.png",
	"assets/women/woman-122.png",
	"assets/women/woman-123.png",
	"assets/women/woman-124.png",
	"assets/women/woman-125.png",
	"assets/women/woman-126.png",
	"assets/women/woman-127.png",
	"assets/women/woman-128.png",
	"assets/women/woman-129.png",
	"assets/women/woman-130.png",
	"assets/women/woman-131.png",
	"assets/women/woman-132.png",
	"assets/women/woman-133.png",
	"assets/women/woman-134.png",
	"assets/women/woman-135.png",
	"assets/women/woman-136.png",
	"assets/women/woman-137.png",
	"assets/women/woman-138.png",
	"assets/women/woman-139.png",
	"assets/women/woman-140.png",
	"assets/women/woman-141.png",
	"assets/women/woman-142.png",
	"assets/women/woman-143.png",
	"assets/women/woman-144.png",
	"assets/women/woman-145.png",
	"assets/women/woman-146.png",
	"assets/women/woman-147.png",
	"assets/women/woman-148.png",
	"assets/women/woman-149.png",
	"assets/women/woman-150.png",
	"assets/women/woman-151.png",
	"assets/women/woman-152.png",
	"assets/women/woman-153.png",
	"assets/women/woman-154.png",
	"assets/women/woman-155.png",
	"assets/women/woman-156.png",
	"assets/women/woman-157.png",
	"assets/women/woman-158.png",
	"assets/women/woman-159.png",
	"assets/women/woman-160.png",
	"assets/women/woman-161.png",
	"assets/women/woman-162.png"
};

std::vector<std::string> maleTextures = {
	"assets/men/man-1.png",
	"assets/men/man-2.png",
	"assets/men/man-3.png",
	"assets/men/man-4.png",
	"assets/men/man-5.png",
	"assets/men/man-6.png",
	"assets/men/man-7.png",
	"assets/men/man-8.png",
	"assets/men/man-9.png",
	"assets/men/man-10.png",
	"assets/men/man-11.png",
	"assets/men/man-12.png",
	"assets/men/man-13.png",
	"assets/men/man-14.png",
	"assets/men/man-15.png",
	"assets/men/man-16.png",
	"assets/men/man-17.png",
	"assets/men/man-18.png",
	"assets/men/man-19.png",
	"assets/men/man-20.png",
	"assets/men/man-21.png",
	"assets/men/man-22.png",
	"assets/men/man-23.png",
	"assets/men/man-24.png",
	"assets/men/man-25.png",
	"assets/men/man-26.png",
	"assets/men/man-27.png",
	"assets/men/man-28.png",
	"assets/men/man-29.png",
	"assets/men/man-30.png",
	"assets/men/man-31.png",
	"assets/men/man-32.png",
	"assets/men/man-33.png",
	"assets/men/man-34.png",
	"assets/men/man-35.png",
	"assets/men/man-36.png",
	"assets/men/man-37.png",
	"assets/men/man-38.png",
	"assets/men/man-39.png",
	"assets/men/man-40.png",
	"assets/men/man-41.png",
	"assets/men/man-42.png",
	"assets/men/man-43.png",
	"assets/men/man-44.png",
	"assets/men/man-45.png",
	"assets/men/man-46.png",
	"assets/men/man-47.png",
	"assets/men/man-48.png",
	"assets/men/man-49.png",
	"assets/men/man-50.png",
	"assets/men/man-51.png",
	"assets/men/man-52.png",
	"assets/men/man-53.png",
	"assets/men/man-54.png",
	"assets/men/man-55.png",
	"assets/men/man-56.png",
	"assets/men/man-57.png",
	"assets/men/man-58.png",
	"assets/men/man-59.png",
	"assets/men/man-60.png",
	"assets/men/man-61.png",
	"assets/men/man-62.png",
	"assets/men/man-63.png",
	"assets/men/man-64.png",
	"assets/men/man-65.png",
	"assets/men/man-66.png",
	"assets/men/man-67.png",
	"assets/men/man-68.png",
	"assets/men/man-69.png",
	"assets/men/man-70.png",
	"assets/men/man-71.png",
	"assets/men/man-72.png",
	"assets/men/man-73.png",
	"assets/men/man-74.png",
	"assets/men/man-75.png",
	"assets/men/man-76.png",
	"assets/men/man-77.png",
	"assets/men/man-78.png",
	"assets/men/man-79.png",
	"assets/men/man-80.png",
	"assets/men/man-81.png",
	"assets/men/man-82.png",
	"assets/men/man-83.png",
	"assets/men/man-84.png",
	"assets/men/man-85.png",
	"assets/men/man-86.png",
	"assets/men/man-87.png",
	"assets/men/man-88.png",
	"assets/men/man-89.png",
	"assets/men/man-90.png",
	"assets/men/man-91.png",
	"assets/men/man-92.png",
	"assets/men/man-93.png",
	"assets/men/man-94.png",
	"assets/men/man-95.png",
	"assets/men/man-96.png",
	"assets/men/man-97.png",
	"assets/men/man-98.png",
	"assets/men/man-99.png",
	"assets/men/man-100.png",
	"assets/men/man-101.png",
	"assets/men/man-102.png",
	"assets/men/man-103.png",
	"assets/men/man-104.png",
	"assets/men/man-105.png",
	"assets/men/man-106.png",
	"assets/men/man-107.png",
	"assets/men/man-108.png",
	"assets/men/man-109.png",
	"assets/men/man-110.png",
	"assets/men/man-111.png",
	"assets/men/man-112.png",
	"assets/men/man-113.png",
	"assets/men/man-114.png",
	"assets/men/man-115.png",
	"assets/men/man-116.png",
	"assets/men/man-117.png",
	"assets/men/man-118.png",
	"assets/men/man-119.png",
	"assets/men/man-120.png",
	"assets/men/man-121.png",
	"assets/men/man-122.png",
	"assets/men/man-123.png",
	"assets/men/man-124.png",
	"assets/men/man-125.png",
	"assets/men/man-126.png",
	"assets/men/man-127.png",
	"assets/men/man-128.png",
	"assets/men/man-129.png",
	"assets/men/man-130.png",
	"assets/men/man-131.png",
	"assets/men/man-132.png",
	"assets/men/man-133.png",
	"assets/men/man-134.png",
	"assets/men/man-135.png",
	"assets/men/man-136.png",
	"assets/men/man-137.png",
	"assets/men/man-138.png",
	"assets/men/man-139.png",
	"assets/men/man-140.png",
	"assets/men/man-141.png",
	"assets/men/man-142.png",
	"assets/men/man-143.png",
	"assets/men/man-144.png",
	"assets/men/man-145.png",
	"assets/men/man-146.png",
	"assets/men/man-147.png",
	"assets/men/man-148.png",
	"assets/men/man-149.png",
	"assets/men/man-150.png",
	"assets/men/man-151.png",
	"assets/men/man-152.png",
	"assets/men/man-153.png",
	"assets/men/man-154.png",
	"assets/men/man-155.png",
	"assets/men/man-156.png",
	"assets/men/man-157.png",
	"assets/men/man-158.png",
	"assets/men/man-159.png",
	"assets/men/man-160.png",
	"assets/men/man-161.png",
	"assets/men/man-162.png",
	"assets/men/man-163.png",
	"assets/men/man-164.png",
	"assets/men/man-165.png",
	"assets/men/man-166.png",
	"assets/men/man-167.png",
	"assets/men/man-168.png",
	"assets/men/man-169.png",
	"assets/men/man-170.png",
	"assets/men/man-171.png",
	"assets/men/man-172.png",
	"assets/men/man-173.png",
	"assets/men/man-174.png",
	"assets/men/man-175.png",
	"assets/men/man-176.png",
	"assets/men/man-177.png",
	"assets/men/man-178.png",
	"assets/men/man-179.png",
	"assets/men/man-180.png",
	"assets/men/man-181.png",
	"assets/men/man-182.png",
	"assets/men/man-183.png",
	"assets/men/man-184.png",
	"assets/men/man-185.png",
	"assets/men/man-186.png",
	"assets/men/man-187.png",
	"assets/men/man-188.png",
	"assets/men/man-189.png",
	"assets/men/man-190.png",
	"assets/men/man-191.png",
	"assets/men/man-192.png",
	"assets/men/man-193.png",
	"assets/men/man-194.png",
	"assets/men/man-195.png",
	"assets/men/man-196.png",
	"assets/men/man-197.png",
	"assets/men/man-198.png",
	"assets/men/man-199.png",
	"assets/men/man-200.png",
	"assets/men/man-201.png",
	"assets/men/man-202.png",
	"assets/men/man-203.png",
	"assets/men/man-204.png",
	"assets/men/man-205.png",
	"assets/men/man-206.png",
	"assets/men/man-207.png",
	"assets/men/man-208.png",
	"assets/men/man-209.png",
	"assets/men/man-210.png",
	"assets/men/man-211.png",
	"assets/men/man-212.png",
	"assets/men/man-213.png",
	"assets/men/man-214.png",
	"assets/men/man-215.png",
	"assets/men/man-216.png",
	"assets/men/man-217.png",
	"assets/men/man-218.png",
	"assets/men/man-219.png",
	"assets/men/man-220.png",
	"assets/men/man-221.png",
	"assets/men/man-222.png",
	"assets/men/man-223.png",
	"assets/men/man-224.png",
	"assets/men/man-225.png",
	"assets/men/man-226.png",
	"assets/men/man-227.png",
	"assets/men/man-228.png",
	"assets/men/man-229.png",
	"assets/men/man-230.png",
	"assets/men/man-231.png",
	"assets/men/man-232.png",
	"assets/men/man-233.png",
	"assets/men/man-234.png",
	"assets/men/man-235.png",
	"assets/men/man-236.png",
	"assets/men/man-237.png",
	"assets/men/man-238.png",
	"assets/men/man-239.png",
	"assets/men/man-240.png",
	"assets/men/man-241.png",
	"assets/men/man-242.png",
	"assets/men/man-243.png"
};

Caveman::Caveman(int maxAge, int minAge) : id(counter){
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> unid(minAge, maxAge);

    age = unid(rng);

	

	
    std::uniform_int_distribution<int> unbd(0, 1);

    if(counter < 3){
        male = true;
    }else if(counter < 5){
        male = false;
    }else{
        male = (unbd(rng) != 0);
    }

    std::uniform_int_distribution<int> maleN(0, maleNames.size() - 1);
    std::uniform_int_distribution<int> femaleN(0, femaleNames.size() - 1);

    if(male){
        name = maleNames[maleN(rng)];
    }else{
        name = femaleNames[femaleN(rng)];
    }


    std::uniform_int_distribution<int> stats(1, 5);

    fitness = stats(rng);
    intelligence = stats(rng);

    std::uniform_int_distribution<int> maleT(0, maleTextures.size() - 1);
    std::uniform_int_distribution<int> femaleT(0, femaleTextures.size() - 1);

    if (male) {
        texPath = maleTextures[maleT(rng)];
    }else{
        texPath = femaleTextures[femaleT(rng)];
    }

    button = new Button({100, 200}, {0, 0}, texPath,
        nullptr, std::bind(&ButtonFunctions::Tribe::displayInfo, std::ref(*this)));

    infobox = new Textbox({200, 200}, {450, 400}, "assets/info.png", "TEST");

    counter += 1;
}

Caveman::~Caveman() {
    delete button;
}


void Caveman::setInfoboxVisible(bool visible){
    infoboxVisible = visible;
}


short Caveman::getId(){
    return id;
}
std::string Caveman::getName(){
    return name;
}
bool Caveman::isMale(){
    return male;
}
unsigned short Caveman::getAge(){
    return age;
}
short Caveman::getFitness(){
    return fitness;
}
void Caveman::setFitness(short newFit) {
    fitness = newFit;
}
short Caveman::getIntelligence(){
    return intelligence;
}

Button& Caveman::getButton() {
    return *button;
}
Textbox& Caveman::getInfobox() {
    return *infobox;
}

void Caveman::setPosition(TransformedVector<> newPosition){
    button->setTransformedPosition(newPosition);
    infobox->setTransformedPosition(
        {newPosition.getRealX() - infobox->getTransformedSize().getRealX(),
         newPosition.getRealY() - infobox->getTransformedSize().getRealY()});
}

EActions Caveman::getCurrentAction(){
    return currentAction;
}

void Caveman::setCurrentAction(EActions newOccupation) {
    currentAction = newOccupation;
}

void Caveman::onResize(){
    button->setPosition(button->getTransformedPosition());
    button->setSize(button->getTransformedSize());
    infobox->setPosition(infobox->getTransformedPosition());
    infobox->setSize(infobox->getTransformedSize());
}

void Caveman::display(sf::RenderWindow& win) const {
    win.draw(*button);
    if(infoboxVisible){
        win.draw(*infobox);
    }
}

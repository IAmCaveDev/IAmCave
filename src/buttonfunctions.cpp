#include "buttonfunctions.h"

#include <string>
#include <sstream>

namespace ButtonFunctions {
    namespace Managing {
        namespace Hunting {
            void hunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                buttons.push_back(new Button({ 200, 80 }, { 300, 50 }, "assets/easyhunt.png", std::bind(&easyHunt, std::ref(stateRef))));
                buttons.push_back(new Button({ 200, 80 }, { 550, 50 }, "assets/hardhunt.png", std::bind(&hardHunt, std::ref(stateRef))));
                for (auto& it : stateRef.getIdlingTribe()) {
                    if (!it->isMale()) {
                        it->getButton().setClickability(false);
                    }
                }
                stateRef.setTextboxText("Please select a difficulty! The 'Hard' Difficulty yields more food, but your Caveman are also more likely to die.");
            }
            void easyHunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                buttons.pop_back();
                buttons.pop_back();
                stateRef.setCurrentAction(EActions::EasyHunt, 3);
                stateRef.setTextboxText("Select one or more Cavemen to go on a relaxed hunting trip!");
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
            void hardHunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                buttons.pop_back();
                buttons.pop_back();
                stateRef.setCurrentAction(EActions::HardHunt, 5);
                stateRef.setTextboxText("Select one or more Cavemen to go on a thrilling hunting trip!");
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
        }
        namespace Sex {
            void sex(Management& stateRef) {
                for (auto& it : stateRef.getActions()) {
                    if (it->getType() == EActions::SexAction) {
                        stateRef.setTextboxText("It is only possible to have one sex Action at a time!");
                        return;
                    }
                }
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                stateRef.setCurrentAction(EActions::SexAction, 1);
                stateRef.setTextboxText("Select two Cavemen to make love with each other! You can choose exactly one male and one female lover.");
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
        }
        namespace Improve {
            short improvement_mod = 1;    //Scales improvement costs

            void improve(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                stateRef.setCurrentAction(EActions::ImproveAction, 4 * improvement_mod);
                //improvement_mod++;       //Not in use yet
                stateRef.setTextboxText("Select one or more Cavemen to work on your cave! Increases the cave's capacity.");
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
        }
        namespace Collecting {
            void collect(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                for (auto& it : stateRef.getIdlingTribe()) {
                    if (it->isMale()) {
                        it->getButton().setClickability(false);
                    }
                }
                stateRef.setCurrentAction(EActions::CollectAction, 3);
                stateRef.setTextboxText("Select one or more Cavewomen to collect building material!");
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
        }
        namespace Research {
            void think(Management& stateRef, Techtree& techtreeRef) {
                if (techtreeRef.getTrainingMode()) {
                    stateRef.setTextboxText("You can only research one Tech at a time, you can still ponder though!");
                }
                else {
                    techtreeRef.setTextboxText("This is your techtree, click a technology to show information about it.");
                }

                techtreeRef.setVisibility(true);
                std::vector<Button*>& buttons = stateRef.getButtons();

                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setClickability(false);
                }

                techtreeRef.getProperThinking().setCallback(std::bind(&thinkConfirm, std::ref(stateRef), std::ref(techtreeRef)));
                techtreeRef.getProperThinking().setClickability(false);
                techtreeRef.getAbortThinking().setCallback(std::bind(&thinkAbort, std::ref(stateRef), std::ref(techtreeRef)));
                techtreeRef.getTrainingButton().setCallback(std::bind(&techCallback, std::ref(stateRef), std::ref(techtreeRef),techtreeRef.getTraining()));

                for (auto& it : techtreeRef.getTree()) {
                    it.second->getButton().setCallback(std::bind(&techCallback, std::ref(stateRef),std::ref(techtreeRef), it.second));
                }
            }
            void techCallback(Management& stateRef, Techtree& techtreeRef, std::shared_ptr<Tech> techRef) {
                stateRef.setActiveTech(techRef->getName());
                techtreeRef.getProperThinking().setClickability(true);
                stateRef.getTechtree().setTextboxText(techRef->getName() + "\n"
                        + std::to_string(techRef->getRequiredIntelligence())
                        + " int required, "
                        + std::to_string(techRef->getDuration()) + " rounds\n"
                        + techRef->getDescription());
            }
            void thinkAbort(Management& stateRef, Techtree& techtreeRef) {
                techtreeRef.setVisibility(false);
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setClickability(true);
                    it->getButton().setCallback(nullptr);
                }
                stateRef.deleteCurrentAction();
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(true);
                }
            }

            void thinkConfirm(Management& stateRef, Techtree& techtreeRef) {
                techtreeRef.setVisibility(false);

                std::string name = stateRef.getActiveTech();
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                std::shared_ptr<Tech> tech;

                if (name == "training") {
                    tech = techtreeRef.getTraining();
                } else {
                    tech = techtreeRef.getTree().find(name)->second;
                }

                stateRef.setCurrentAction(EActions::ThinkAction, tech->getDuration());

                if (name == "training") {
                    stateRef.setTextboxText("Select a caveman!");
                    for (auto& it : stateRef.getIdlingTribe()) {
                            it->getButton().setClickability(true);
                    }
                    General::actionStart(stateRef);
                    return;
                }

                stateRef.setTextboxText("Select a caveman with " +
                        std::to_string(tech->getRequiredIntelligence()) +
                        " intelligence or higher to research " +
                        tech->getName() + ".");
                for (auto& it : stateRef.getIdlingTribe()) {
                    if(it->getIntelligence() >= tech->getRequiredIntelligence()){
                        it->getButton().setClickability(true);
                    }
                }
                General::actionStart(stateRef);
            }
        }
        namespace General {
            void abort(Management& stateRef) {
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setClickability(true);
                }
                for (auto& it : stateRef.getCurrentAction().getActors()) {
                    it->getButton().setCallback(nullptr);
                    it->setActionBox(EActions::Idle);
                }
                stateRef.deleteCurrentAction();
                stateRef.deleteActiveTech();
                stateRef.resetTextbox();
                actionEnd(stateRef);
            }

            void confirm(Management& stateRef) {
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setClickability(true);
                }
                for (auto& it : stateRef.getCurrentAction().getActors()) {
                    it->getButton().setCallback(nullptr);
                    it->setActionBox(EActions::Idle);
                }
                if (stateRef.getCurrentAction().getActors().size() < 1) {
                    stateRef.deleteCurrentAction();
                    stateRef.setTextboxText("You didn't select enough cavemen, feel free to try again.");
                } else if (stateRef.getCurrentAction().getType() == EActions::SexAction && stateRef.getCurrentAction().getActors().size() < 2) {
                    stateRef.deleteCurrentAction();
                    stateRef.setTextboxText("You need exactly two cavemen with different genders for this action, pls try again.");
                } else {
                    if (stateRef.getGame().checkAndAddResources(stateRef.getCurrentAction().getCost())) {
                        stateRef.pushCurrentAction();
                        stateRef.setTextboxText("Action added to the queue! You can either select more actions or press 'Go' to go to the next Round!");
                    } else {
                        stateRef.deleteCurrentAction();
                        stateRef.setTextboxText("Not enough resources to perform this Action");
                    }
                }
                stateRef.deleteActiveTech();
                actionEnd(stateRef);
            }

            void actionStart(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }

                buttons.push_back(new Button({ 200, 80 }, { -250, -230 }, "assets/abort.png", std::bind(&abort, std::ref(stateRef))));
                buttons.push_back(new Button({ 200, 80 }, { -250, -330 }, "assets/confirm.png", std::bind(&confirm, std::ref(stateRef))));
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setCallback(std::bind(&ButtonFunctions::Tribe::addAsActor, std::ref(stateRef), it));
                }
            }

            void actionEnd(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                buttons.pop_back();
                buttons.pop_back();
                for (auto& it : buttons) {
                    it->setClickability(true);
                }
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setCallback(nullptr);
                }
            }
        }
    }

    namespace MainMenu {
        void options(){

        }
    }

    namespace Tribe {
        void addAsActor(Management& stateRef, std::shared_ptr<Caveman> caveman) {
            EActions actionType = stateRef.getCurrentAction().getType();
            stateRef.getCurrentAction().addActor(caveman);
            caveman->setActionBox(actionType);
            caveman->getButton().setCallback(std::bind(&ButtonFunctions::Tribe::removeAsActor, std::ref(stateRef), caveman));
            //sex action
            if (actionType == EActions::SexAction && caveman->isMale()) {
                for (auto& it : stateRef.getIdlingTribe()) {
                    if (it->isMale() && it != caveman) {
                        it->getButton().setClickability(false);
                    }
                }
            }
            if (actionType == EActions::SexAction && !caveman->isMale()) {
                for (auto& it : stateRef.getIdlingTribe()) {
                    if (!it->isMale() && it != caveman) {
                        it->getButton().setClickability(false);
                    }
                }
            }
            //think action
            if (actionType == EActions::ThinkAction) {
                for (auto& it : stateRef.getIdlingTribe()) {
                    if (it != caveman) {
                        it->getButton().setClickability(false);
                    }
                }
            }
        }
        void removeAsActor(Management& stateRef, std::shared_ptr<Caveman> caveman) {
            EActions actionType = stateRef.getCurrentAction().getType();
            stateRef.getCurrentAction().removeActor(caveman);
            caveman->setActionBox(EActions::Idle);
            caveman->getButton().setCallback(std::bind(&ButtonFunctions::Tribe::addAsActor, std::ref(stateRef), caveman));
            //sex action
            if (actionType == EActions::SexAction && caveman->isMale()) {
                for (auto& it : stateRef.getIdlingTribe()) {
                    if (it->isMale()) {
                        it->getButton().setClickability(true);
                    }
                }
            }
            if (actionType == EActions::SexAction && !caveman->isMale()) {
                for (auto& it : stateRef.getIdlingTribe()) {
                    if (!it->isMale() && it != caveman) {
                        it->getButton().setClickability(true);
                    }
                }
            }
            //think action
            if (actionType == EActions::ThinkAction) {
                std::string name = stateRef.getActiveTech();
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                std::shared_ptr<Tech> tech;

                if (name == "training") {
                    tech = stateRef.getTechtree().getTraining();
                }
                else {
                    tech = stateRef.getTechtree().getTree().find(name)->second;
                }

                for (auto& it : stateRef.getIdlingTribe()) {
                    if(it->getIntelligence() >= tech->getRequiredIntelligence()){
                        it->getButton().setClickability(true);
                    }
                }
            }
        }
        void displayInfo(std::shared_ptr<Caveman> caveman) {
            std::ostringstream oss;
            oss << caveman->getName()
                << "\nID: " << caveman->getId()
                << "\nSex: " << (caveman->isMale() ? "Male" : "Female")
                << "\nAge: " << caveman->getAge()
                << "\nFitness: " << caveman->getFitness()
                << "\nIntelligence: " << caveman->getIntelligence();

            caveman->getInfobox().setText(oss.str());

            caveman->setInfoboxVisible(true);
            caveman->getButton().setAltCallback(std::bind(&hideInfo, caveman));
        }
        void hideInfo(std::shared_ptr<Caveman> caveman){
            caveman->setInfoboxVisible(false);
            caveman->getButton().setAltCallback(std::bind(&displayInfo, caveman));
        }
    }
    namespace Events {
        void confirmOption(GameState& stateRef, std::shared_ptr<Event::Option> option, short id) {
            Tech::StatBoosts newStats = stateRef.getGame().getTechBonuses();

            newStats.addends.gatheringBonus += option->effects.gatheringBonus;
            newStats.addends.huntBonus += option->effects.huntBonus;
            stateRef.getGame().setTechBonuses(newStats);

            stateRef.getGame().addToResources({ option->effects.foodGain, option->effects.materialGain, option->effects.capacityGain });

            if (option->effects.newCaveman) {
                stateRef.getGame().addCaveman(50, option->effects.new_age, option->effects.new_intelligence, option->effects.new_fitness, option->effects.new_isMale);
            }

            for (int i = stateRef.getButtons().size() - 1; i > 0; i--) {
                stateRef.getButtons().at(i)->setPosition({ 2000, 2000 });
                option->button->setVisibility(false);
                stateRef.getButtons().pop_back();
            }
            stateRef.getButtons().at(0)->changeTexture("assets/go.png");
            stateRef.getButtons().at(0)->setCallback(std::bind(&ButtonFunctions::Events::resetButton, std::ref(stateRef)));
            stateRef.getButtons().at(0)->setPosition({ 450, -130 });
            stateRef.getGame().removeEvent(id);
            resetButton(stateRef);
        }
       void resetButton(GameState& stateRef) {
           stateRef.setNextState(EGamestates::management);
       }
    }
}

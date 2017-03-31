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
                buttons.push_back(new Button({ 200, 50 }, { 450, 100 }, "assets/easyhunt.png", std::bind(&easyHunt, std::ref(stateRef))));
                buttons.push_back(new Button({ 200, 50 }, { 450, 200 }, "assets/hardhunt.png", std::bind(&hardHunt, std::ref(stateRef))));
            }
            void easyHunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                buttons.pop_back();
                buttons.pop_back();
                stateRef.setCurrentAction(EActions::EasyHunt, 1);
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
            void hardHunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                buttons.pop_back();
                buttons.pop_back();
                stateRef.setCurrentAction(EActions::HardHunt, 1);
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
        }
        namespace Sex {
            void sex(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                stateRef.setCurrentAction(EActions::SexAction, 1);
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
        }
        namespace Improve {
            void improve(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                stateRef.setCurrentAction(EActions::ImproveAction, 1);
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
        }
        namespace Collecting {
            void collect(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                stateRef.setCurrentAction(EActions::CollectAction, 1);
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
        }
        namespace General {
            void abort(Management& stateRef) {
                stateRef.deleteCurrentAction();
                actionEnd(stateRef);
            }

            void confirm(Management& stateRef) {
                if (stateRef.getCurrentAction().getType() == EActions::SexAction && stateRef.getCurrentAction().getActors().size() < 2)
                    stateRef.deleteCurrentAction();
                else
                    stateRef.pushCurrentAction();
                
                actionEnd(stateRef);
            }

            void actionStart(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                buttons.push_back(new Button({ 200, 50 }, { 800, 100 }, "assets/abort.png", std::bind(&ButtonFunctions::Managing::General::abort, std::ref(stateRef))));
                buttons.push_back(new Button({ 200, 50 }, { 800, 200 }, "assets/confirm.png", std::bind(&ButtonFunctions::Managing::General::confirm, std::ref(stateRef))));
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
           stateRef.getCurrentAction().addActor(caveman);
           caveman->getButton().setCallback(nullptr);
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
            caveman->getButton().setAltCallback(std::bind(&displayInfo,
                                                          caveman));
        }
    }
}

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
                stateRef.setCurrentAction(EActions::Sex, 1);
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
        }
        namespace Research {
            void think(Management& stateRef, Techtree& techtreeRef) {

                techtreeRef.setVisibility(true);
                std::vector<Button*>& buttons = stateRef.getButtons();

                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setClickability(false);
                }

                techtreeRef.getProperThinking().setCallback(std::bind(&thinkConfirm, std::ref(stateRef), std::ref(techtreeRef)));
                techtreeRef.getAbortThinking().setCallback(std::bind(&thinkAbort, std::ref(stateRef), std::ref(techtreeRef)));

                for (auto& it : techtreeRef.getTree()) {
                    it.second->getButton().setCallback(std::bind(&techCallback, std::ref(stateRef), std::ref(it.second)));
                }
            }
            void techCallback(Management& stateRef, std::shared_ptr<Tech> techRef) {
                stateRef.setActiveTech(techRef->getName());
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
                //TODO: check for duration of specific Tech and use it instead of 1
                stateRef.setCurrentAction(EActions::ThinkAction, 1);
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setClickability(true);
                }
                General::actionStart(stateRef);
            }
        }
        namespace General {
            void abort(Management& stateRef) {
                stateRef.deleteCurrentAction();
                stateRef.deleteActiveTech();
                actionEnd(stateRef);
            }

            void confirm(Management& stateRef) {
                stateRef.pushCurrentAction();
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

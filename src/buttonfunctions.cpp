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

                General::actionStart(stateRef, std::bind(&thinkAbort,
                                                         std::ref(stateRef),
                                                         std::ref(techtreeRef)),
                                               std::bind(&thinkConfirm,
                                                         std::ref(stateRef),
                                                         std::ref(techtreeRef)));

                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setClickability(false);
                }
            }
            void thinkAbort(Management& stateRef, Techtree& techtreeRef) {
                techtreeRef.setVisibility(false);
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setClickability(true);
                }
                stateRef.deleteCurrentAction();
                General::actionEnd(stateRef);
            }

            void thinkConfirm(Management& stateRef, Techtree& techtreeRef) {
                techtreeRef.setVisibility(false);
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setClickability(true);
                }
                stateRef.pushCurrentAction();
                General::actionEnd(stateRef);
            }
        }
        namespace General {
            void abort(Management& stateRef) {
                stateRef.deleteCurrentAction();
                actionEnd(stateRef);
            }

            void confirm(Management& stateRef) {
                stateRef.pushCurrentAction();
                actionEnd(stateRef);
            }

            void actionStart(Management& stateRef,
                             std::function<void()> abortCallback,
                             std::function<void()> confirmCallback) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }

                if (abortCallback == nullptr) {
                    abortCallback = std::bind(&ButtonFunctions::Managing::General::abort, std::ref(stateRef));
                }
                if (confirmCallback == nullptr) {
                    confirmCallback = std::bind(&ButtonFunctions::Managing::General::confirm, std::ref(stateRef));
                }

                buttons.push_back(new Button({ 200, 80 }, { -250, -230 }, "assets/abort.png", abortCallback));
                buttons.push_back(new Button({ 200, 80 }, { -250, -330 }, "assets/confirm.png", confirmCallback));
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

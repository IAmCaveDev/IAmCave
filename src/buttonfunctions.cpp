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
            }
            void easyHunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                buttons.pop_back();
                buttons.pop_back();
                stateRef.setCurrentAction(EActions::EasyHunt, 3);
                ButtonFunctions::Managing::General::actionStart(stateRef);
            }
            void hardHunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                buttons.pop_back();
                buttons.pop_back();
                stateRef.setCurrentAction(EActions::HardHunt, 5);
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
            short improvement_mod = 1;    //Scales improvement costs

            void improve(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                stateRef.setCurrentAction(EActions::ImproveAction, 4 * improvement_mod);
                //improvement_mod++;       //Not in use yet
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
                stateRef.getTechtree().setTextboxText(techRef->getName() + "\n"
                        + std::to_string(techRef->getRequiredIntelligence())
                        + " int required\n" + techRef->getDescription());
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

                std::string name = stateRef.getActiveTech();
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);
                auto tech = techtreeRef.getTree().find(name)->second;

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
                } else if (stateRef.getCurrentAction().getType() == EActions::SexAction && stateRef.getCurrentAction().getActors().size() < 2) {
                    stateRef.deleteCurrentAction();
                } else {
                    stateRef.pushCurrentAction();
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
                auto tech = stateRef.getTechtree().getTree().find(name)->second;

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
            caveman->getButton().setAltCallback(std::bind(&displayInfo,
                                                          caveman));
        }
    }
}

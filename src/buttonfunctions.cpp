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
                buttons.push_back(new Button({ 200, 50 }, { 800, 100 }, "assets/abort.png", std::bind(&ButtonFunctions::Managing::General::abort, std::ref(stateRef))));
                buttons.push_back(new Button({ 200, 50 }, { 800, 200 }, "assets/confirm.png", std::bind(&ButtonFunctions::Managing::General::confirm, std::ref(stateRef))));
                for (auto& it : stateRef.getIdlingTribe()) {
                    it->getButton().setCallback(std::bind(&ButtonFunctions::Tribe::addAsActor, std::ref(stateRef), std::ref(*it)));
                }
            }
            void hardHunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();

            }
        }
        namespace General {
            void abort(Management& stateRef) {
                stateRef.deleteCurrentAction();
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
            void confirm(Management& stateRef) {
                stateRef.pushCurrentAction();
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
        void start(Game& game){
            game.setCurrentGameState(EGamestates::management);
        }
        void options(){

        }
        void quit(Game& game){
            game.getWindow().close();
        }
    }

    namespace Tribe {
        void addAsActor(Management& stateRef, Caveman& caveman) {
           stateRef.getCurrentAction().addActor(&caveman);
        }
        void displayInfo(Caveman& caveman) {
            std::ostringstream oss;
            oss << caveman.getName()
                << "\nID: " << caveman.getId()
                << "\nSex: " << (caveman.isMale() ? "Male" : "Female")
                << "\nAge: " << caveman.getAge()
                << "\nFitness: " << caveman.getFitness()
                << "\nIntelligence: " << caveman.getIntelligence();

            caveman.getInfobox().setText(oss.str());

            caveman.setInfoboxVisible(true);
            caveman.getButton().setAltCallback(std::bind(&hideInfo,
                                                         std::ref(caveman)));
        }
        void hideInfo(Caveman& caveman){
            caveman.setInfoboxVisible(false);
            caveman.getButton().setAltCallback(std::bind(&displayInfo,
                                                         std::ref(caveman)));
        }
    }
}

#include "buttonfunctions.h"

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
                 //buttons.push_back(new Button({ 50, 50 }, { 200, 400 }, "assets/easyhunt.png", abort));
            }
            void easyHunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();
                buttons.pop_back();
                buttons.pop_back();
                //new Hunt Action
            }
            void hardHunt(Management& stateRef) {
                std::vector<Button*>& buttons = stateRef.getButtons();

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
        void displayInfo(Caveman& caveman) {

        }
    }
}

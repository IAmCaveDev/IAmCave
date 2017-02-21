#include "buttonfunctions.h"

namespace ButtonFunctions {
    namespace Managing {
        namespace Hunting {
            void hunt(Management& stateRef) {
                /*
                 * std::vector<Button*> buttons = stateRef.getButtons();
                 * for (auto& it : buttons) {
                 *     it->setClickability(false);
                 * }
                 * buttons.push_back(new Button({ 50, 50 }, { 200, 400 }, "assets/easyhunt.png", easyHunt));
                 * buttons.push_back(new Button({ 50, 50 }, { 200, 400 }, "assets/easyhunt.png", hardHunt));
                 * buttons.push_back(new Button({ 50, 50 }, { 200, 400 }, "assets/easyhunt.png", abort));
                 */
            }
            void easyHunt() {

            }
        }
    }

    namespace MainMenu {
        void start(Game& game){
        // void start(Game& game){
            // game.setCurrentGameState(EGamestates::management);
        }
        void options(){

        }
        void quit(Game& game){
            game.getWindow().close();
        }
    }
}

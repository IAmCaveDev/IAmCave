#include "buttonfunctions.h"

namespace ButtonFunctions {
    namespace Managing {
        namespace Hunting {
            void hunt(Management& stateRef) {
                std::vector<Button*> buttons = stateRef.getButtons();
                for (auto& it : buttons) {
                    it->setClickability(false);
                }
                buttons.push_back(new Button({ 50, 50 }, { 200, 400 }, "assets/easyhunt.png", easyHunt));
                buttons.push_back(new Button({ 50, 50 }, { 200, 400 }, "assets/easyhunt.png", hardHunt));
                buttons.push_back(new Button({ 50, 50 }, { 200, 400 }, "assets/easyhunt.png", abort));
            }
            void easyHunt() {

            }
        }
    }
}


float ratio = (float)size.y / (float)size.x;

if (size.x / 16 == size.y / 9) {
    view.setViewport(sf::FloatRect(0, 0, 1, 1));
}
else if (size.x / 16 < size.y / 9) {
    view.setViewport(sf::FloatRect(0, (9.0 / 16.0*ratio) / 2,
        1, 9.0 / 16.0));
}
else {
    view.setViewport(sf::FloatRect((9.0 / 16.0*ratio) / 2, 0,
        9.0 / 16.0, 1));
}
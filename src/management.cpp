#include "management.h"
#include "button.h"
#include "game.h"

Management::Management(Game& gameRef) : GameState(gameRef) {

    std::function<void()> start = [&]() {
        game.setCurrentGameState(EGamestates::management);
    };

    std::function<void()> options = []() {

    };

    std::function<void()> quit = [&]() {
        game.getWindow().close();
    };

    buttons = {
    };

}

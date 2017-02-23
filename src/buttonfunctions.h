#ifndef BUTTONFUNCTIONS_H
#define BUTTONFUNCTIONS_H

#include "game.h"
#include "management.h"

namespace ButtonFunctions {
    namespace Managing {
        namespace Hunting {
            void hunt(Management& stateRef);
            void easyHunt(Management& stateRef);
            void hardHunt(Management& stateRef);
        }
        namespace Sex {
            void sex();
        }
        namespace Research {

        }
        namespace Improve {

        }
    }
    namespace MainMenu {
        void start(Game& game);
        void options();
        void quit(Game& game);
    }
    namespace Tribe {
        void displayInfo(Caveman& caveman);
    }
}


#endif


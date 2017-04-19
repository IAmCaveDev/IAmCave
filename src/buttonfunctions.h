#ifndef BUTTONFUNCTIONS_H
#define BUTTONFUNCTIONS_H

#include "game.h"
#include "management.h"
#include "hunt.h"
//#include "event.h"

namespace ButtonFunctions {
    namespace Managing {
        namespace Hunting {
            void hunt(Management& stateRef);
            void easyHunt(Management& stateRef);
            void hardHunt(Management& stateRef);
        }
        namespace Sex {
            void sex(Management& stateRef);
        }
        namespace Research {
            void think(Management& stateRef, Techtree& techtreeRef);
            void techCallback(Management& stateRef, std::shared_ptr<Tech> techRef);
            void thinkAbort(Management& stateRef, Techtree& techtreeRef);
            void thinkConfirm(Management& stateRef, Techtree& techtreeRef);
        }
        namespace Improve {
            void improve(Management& stateRef);
        }
        namespace Collecting {
            void collect(Management& stateRef);
        }
        namespace General {
            void abort(Management& stateRef);
            void confirm(Management& stateRef);
            void actionStart(Management& stateRef);
            void actionEnd(Management& stateRef);
        }
    }
    namespace MainMenu {
        void start(Game& game);
        void options();
        void quit(Game& game);
    }
    namespace Tribe {
        void addAsActor(Management& stateRef, std::shared_ptr<Caveman> caveman);
        void removeAsActor(Management& stateRef, std::shared_ptr<Caveman> caveman);
        void displayInfo(std::shared_ptr<Caveman> caveman);
        void hideInfo(std::shared_ptr<Caveman> caveman);
    }
    namespace Events {
        void confirmOption(Game& game, Event::Effects effects, short id);
    }
}


#endif


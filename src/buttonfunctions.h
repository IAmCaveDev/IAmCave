#ifndef BUTTONFUNCTIONS_H
#define BUTTONFUNCTIONS_H

#include "game.h"
#include "management.h"
#include "hunt.h"
//#include "event.h"

/**
 * Callbacks for Buttons throughout the whole game, maybe split into more files?
 */
namespace ButtonFunctions {
    /**
     * Button Callbacks you can only find in the Management Screen
     */
    namespace Managing {
        /**
         * Hunting Action Callback
         */
        namespace Hunting {
            void hunt(Management& stateRef);
            void easyHunt(Management& stateRef);
            void hardHunt(Management& stateRef);
        }
        /**
         * Sex Action Callback
         */
        namespace Sex {
            void sex(Management& stateRef);
        }
        /**
         * Thinking Action Callbacks
         */
        namespace Research {
            void think(Management& stateRef, Techtree& techtreeRef);
            void techCallback(Management& stateRef, Techtree& techtreeRef, std::shared_ptr<Tech> techRef);
            /**
             * Abort Callback in Techtree Screen
             */
            void thinkAbort(Management& stateRef, Techtree& techtreeRef);
            /**
             * Confirm Callback in Techtree Screen
             */
            void thinkConfirm(Management& stateRef, Techtree& techtreeRef);
        }
        /**
         * Improve Action Callback
         */
        namespace Improve {
            void improve(Management& stateRef);
        }
        /**
         * Collect Action Callback
         */
        namespace Collecting {
            void collect(Management& stateRef);
        }
        /**
         * General Functions used by every Action
         */
        namespace General {
            void abort(Management& stateRef);
            void confirm(Management& stateRef);
            void actionStart(Management& stateRef);
            void actionEnd(Management& stateRef);
        }
    }
    /**
     * MainMenu Callbacks; to use if the menu functions get more complicated (with save games e.g.)
     */
    namespace MainMenu {
        void start(Game& game);
        void options();
        void quit(Game& game);
    }
    /**
     * Callbacks when clicking on Cavemen
     */
    namespace Tribe {
        void addAsActor(Management& stateRef, std::shared_ptr<Caveman> caveman);
        void removeAsActor(Management& stateRef, std::shared_ptr<Caveman> caveman);
        void displayInfo(std::shared_ptr<Caveman> caveman);
        void hideInfo(std::shared_ptr<Caveman> caveman);
    }
    /**
     * Callbacks for Event Button and Event Handling
     */
    namespace Events {
        void confirmOption(GameState& stateRef, std::shared_ptr<Event::Option> option, short id);
        void resetButton(GameState& stateRef);
    }
}


#endif


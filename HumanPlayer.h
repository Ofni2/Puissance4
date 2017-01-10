#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"


class HumanPlayer : public Player
{
    public:
        HumanPlayer();
        virtual ~HumanPlayer();

        void play(int col);

    protected:

    private:
};

#endif // HUMANPLAYER_H

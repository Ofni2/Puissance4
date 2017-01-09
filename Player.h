#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    public:
        Player();
        virtual ~Player();

        void play(int col);

        std::string getName();
        void setName(std::string nom);

        char getCoinType();
        void setCoinType(char x);




    protected:

    private:
        std::string m_name;
        char m_coinType;
};

#endif // PLAYER_H

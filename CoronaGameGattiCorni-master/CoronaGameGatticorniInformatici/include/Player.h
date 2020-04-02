#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        void Start();
        void Update();
        void TakeDamage();
    private:
        Player();
        COORD m_pos;
        int m_size;
        int m_lives;
        void Move();
};

#endif // PLAYER_H

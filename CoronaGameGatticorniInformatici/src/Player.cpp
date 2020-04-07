#include "Player.h"

Player::Player(){}

void Player::Start(){
    m_lives = 7;
    m_score = 0;
    m_length = 7;
    m_pos.X = SCREEN_WIDTH/2;
    m_pos.Y = SCREEN_HEIGHT - 7;
    Move();
}

void Player::Update(){
    if( m_lives <= 0 ){
        //EndGame();
    }
    if( Input::Get().IsPressed( VK_LEFT ) ){
        stepLeft();
    }
    if( Input::Get().IsPressed( VK_RIGHT ) ){
        stepRight();
    }
    Move();
}

void Player::TakeDamage(){
    if( m_lives > 0 ){
        m_lives--;
    }
    else{
        //error.
    }
}

void Player::ScorePoint( const int &points ){
    m_score += points;
}

Player& Player::Get()
{
    static Player s_instance;
    return s_instance;
}

void Player::stepLeft(){
    if( m_pos.X > 0 ){
        m_pos.X--;
    }
}

void Player::stepRight(){
    if( m_pos.X < SCREEN_WIDTH-m_length ){
        m_pos.X++;
    }
}

void Player::Move(){
    //Clear the line where the player is.
    Output::Get().FillChar( { 0, m_pos.Y }, { SCREEN_WIDTH, 1 }, ' ', FOREGROUND_WHITE);
    //Print the player in the new position.
    Output::Get().FillChar( m_pos, { m_length, 1 }, '=', FOREGROUND_WHITE);
}

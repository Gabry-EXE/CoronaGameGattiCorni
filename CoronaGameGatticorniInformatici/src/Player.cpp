#include "Player.h"

Player::Player(){
    m_lives = 7;
    m_score = 0;
    m_length = 5;
    m_pos.X = SCREEN_WIDTH/2;
    m_pos.Y = SCREEN_HEIGHT - 5;
}

void Player::Update(){
    if( m_lives <= 0 ){
        EndGame();
    }
    if( Input::Get().IsPressed( VK_LEFT ) ){
        stepLeft();
    }
    if( Input::Get().IsPressed( VK_RIGHT ) ){
        stepRight();
    }
}

void Player::TakeDamage(){
    if( m_lives > 0 ){
        m_lives--;
    }
    else{
        //error.
    }
}

void Player::ScorePoint( int points ){
    m_score += points;
}

Player& Player::Get()
{
    static Player s_instance;
    return s_instance;
}

Player::stepLeft(){
    if( m_pos.X > 0 ){
        m_pos.X--;
    }
}

Player::stepRight(){
    if( m_pos.X < SCREEN_WIDTH-m_length ){

    }
}

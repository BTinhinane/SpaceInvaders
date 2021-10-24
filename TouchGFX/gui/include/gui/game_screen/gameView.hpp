#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include <gui_generated/game_screen/gameViewBase.hpp>
#include <gui/game_screen/gamePresenter.hpp>
#include <stdlib.h>

class gameView : public gameViewBase
{
public:
    gameView();
    virtual ~gameView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void createInvaders();
    virtual void createLifes();
    virtual void shootButtonIsClicked();
    void killInviders(int inviders_pos);
    void rocket_inviders_kill();
    int MyRand( unsigned int start_range, unsigned int end_range);
    void sniperMove();
    void invaderMove();
    void rocketMove();
    void rocketInvaders();
    void collusionRocketInvaders();
    void collusionInvadersSniper();
    void collusionRocketInvadersSniper();

private:

    static int const invaders_row = 4;
    static int const invaders_column = 5;
    static int const invaderNumber = invaders_row * invaders_column;

    Image invader[invaderNumber];
    Image rocket;
    Image rocket_inviders;
    Image life[3];

    int objects_counter = 0;
    int object_Xmove = 0;
    int object_Ymove = 0;
    bool object_direction = true;

    int time_devider = 0;
    int game_speed = 40;

    int display_width = 480;
    int Xshift = 0;
    int Yshift = 80;
    int Ylife =60;
    int balle_move = 5;
    int balle_time_devider=0;
    int balle_speed = 5;

    int rocket_inviders_move = 5;
    int rocket_inviders_time_devider=0;
    int rocket_inviders_speed = 5;

    int inviders_pos = 0;
    int score = 0;
    struct
	{
    	int X, Y;
    	bool life;
    	float points;
	}invaderXY[invaderNumber];

	struct
	{
	    int X, Y;
	    bool life = false;
	    bool isCreated = false;
	}rocketXY;
	struct
		{
		    int X, Y;
		    bool life = false;
		    bool isCreated = false;
		}rocket_invidersXY;
	struct
		{
			bool life = true;
		}sniperXY;

};

#endif // SCREENVIEW_HPP


#include <gui/game_screen/gameView.hpp>
#include <gui_generated/game_screen/gameViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <stdlib.h>


gameView::gameView()
{

}

void gameView::setupScreen()
{
    gameViewBase::setupScreen();
    gameView::createInvaders();
    gameView::createLifes();

}
void gameView::createLifes()
{
	for (int b = 0; b < 3; b++)
		{
		    life[b].setBitmap(touchgfx::Bitmap(BITMAP_LIFE_ID));
		    life[b].setXY(50*(b+1) + Ylife ,20);
		    add(life[b]);
            Ylife -= 10;
            // y1 = 110 y2 = 150
		}

}
void gameView::createInvaders()
{
	for (int b = 0; b < invaders_row; b++)
	{

		for (int a = 0; a < invaders_column; a++)
		{
			switch(b)
			{
				case(0):invader[objects_counter].setBitmap(touchgfx::Bitmap(BITMAP_INVADER_1_ID));
				        break;
				case(1):invader[objects_counter].setBitmap(touchgfx::Bitmap(BITMAP_INVADER_2_ID));
						Xshift = 1;
						break;
				case(2):invader[objects_counter].setBitmap(touchgfx::Bitmap(BITMAP_INVADER_3_ID));
				        Xshift = 3;
						break;
				case(3):invader[objects_counter].setBitmap(touchgfx::Bitmap(BITMAP_INVADER_4_ID));
				        Xshift = 7;
						break;
			}
			invaderXY[objects_counter].X = a*80 + Xshift;
		    invaderXY[objects_counter].Y = b*50 + Yshift;
			invader[objects_counter].setXY(invaderXY[objects_counter].X, invaderXY[objects_counter].Y);
			invaderXY[objects_counter].life = true;
			add(invader[objects_counter]);
			objects_counter++;
		}
	}
}

void gameView::tearDownScreen()
{
    gameViewBase::tearDownScreen();
}

void gameView::handleTickEvent()
{

	sniperMove();

	invaderMove();

	rocketMove();

	rocketInvaders();

	collusionRocketInvaders();

	collusionRocketInvadersSniper();

	collusionInvadersSniper();

}



void gameView::shootButtonIsClicked()
{
   if(sniperXY.life){
		if(rocketXY.isCreated == false)
		{
			rocket.setBitmap(touchgfx::Bitmap(BITMAP_TIR_ID));
			add(rocket);
			rocketXY.isCreated = true;
		}

		if(rocketXY.life == false)
		{
			rocketXY.life = true;
			rocketXY.X = sniperImage.getX()+23;
			rocketXY.Y = sniperImage.getY();
			rocket.setXY(rocketXY.X,rocketXY.Y);
		}
   }
}

void gameView::killInviders(int inviders_pos)
{
	if(((rocket.getX()+ rocket.getWidth()/2) >= invader[inviders_pos].getX()) &&
		((rocket.getX()+ rocket.getWidth()/2) <= invader[inviders_pos].getX()+invader[inviders_pos].getWidth()) &&
		(rocket.getY() <= invader[inviders_pos].getY()+invader[inviders_pos].getHeight())&&
		(rocket.getY() >= invader[inviders_pos].getY()-invader[inviders_pos].getHeight()))
	{
				invader[inviders_pos].setVisible(0);
				remove(invader[inviders_pos]);
				if(inviders_pos>=0 && inviders_pos<=4){
					score +=40;
				}else if(inviders_pos>=5 && inviders_pos<=9){
					score +=30;
				}else if(inviders_pos>=10 && inviders_pos<=14){
					score +=20;
				}else if(inviders_pos>=15 && inviders_pos<=19){
					score +=10;
				}

				Unicode::snprintf(actualScoreBuffer, ACTUALSCORE_SIZE, "%d", score);
				actualScore.invalidate();

				rocket.setVisible(0);
				rocketXY.life = false;
				invaderXY[inviders_pos].life = false;
	}
}

void gameView::rocket_inviders_kill()
{
	if(rocket_invidersXY.isCreated == false )
	{
		rocket_inviders.setBitmap(touchgfx::Bitmap(BITMAP_TIR_ID));
	    add(rocket_inviders);
	    rocket_invidersXY.isCreated = true;
	}

	int alliatoire = (int) MyRand(0,invaderNumber);

	if(rocket_invidersXY.life == false && invaderXY[alliatoire].life )
	{
		 rocket_invidersXY.life = true;
		 rocket_invidersXY.X = invader[alliatoire].getX()+20;
		 rocket_invidersXY.Y = invader[alliatoire].getY()+10;
		 rocket_inviders.setXY(rocket_invidersXY.X,rocket_invidersXY.Y);
	 }

}

int gameView::MyRand( unsigned int start_range, unsigned int end_range)
 {
	static unsigned int rand = 0x134fU; /* Any nonzero start state will work. */

   /*check for valid range.*/
   if(start_range == end_range)
   {
       return start_range;
   }

   /*get the random in end-range.*/
   rand += 0x3AD;
   rand %= end_range;

   /*get the random in start-range.*/
   while(rand < start_range)
   {
       rand = rand + end_range - start_range;
   }
   return rand;
 }

void gameView::sniperMove()
{
	sniperImage.moveTo(shootButton.getX(), 650);
	sniperImage.invalidate();
}

void gameView::invaderMove()
{
	for (objects_counter = 0; objects_counter<invaderNumber; objects_counter++)
	{
		invader[objects_counter].moveTo(invaderXY[objects_counter].X + object_Xmove, invaderXY[objects_counter].Y + object_Ymove);
		invader[objects_counter].invalidate();
	}

	if (time_devider == game_speed)
	{
		if (object_direction)
		{
			object_Xmove+=15;

			if ((invader[4].getX() + invader[4].getWidth()) == display_width)
			{
			   object_direction = false;
			   object_Ymove+=10;
			   game_speed-=2;
			}
		}
		else
		{
			object_Xmove-=15;
			if (invader[0].getX() == 0)
			{
			   object_direction = true;
			   object_Ymove+=10;
			   game_speed-=2;
			}
		}

		time_devider = 0;

	}
	else
	{
		time_devider++;

	}

}
void gameView::rocketMove(){
	if(rocketXY.life)
	{
		rocket.moveTo(rocketXY.X, rocketXY.Y - balle_move);
		rocket.invalidate();

		if (balle_time_devider == balle_speed)
		{
			balle_move+=3;

		}
		else
		{
			balle_time_devider++;
		}

		if( rocket.getY()<10 )
		{
			rocket.setVisible(0);
			rocketXY.life = false;
			remove(rocket);
			rocketXY.isCreated = false;
		}
		else
		{
			rocket.setVisible(1);
		}

	}
	else
	{
		balle_move=5;
	}
}

void gameView::rocketInvaders()
{
	if(rocket_invidersXY.life)
	{
			rocket_inviders.moveTo(rocket_invidersXY.X, rocket_invidersXY.Y + rocket_inviders_move);
			rocket_inviders.invalidate();

			if (rocket_inviders_time_devider == rocket_inviders_speed)
			{
				rocket_inviders_move+=3;
			}
			else
			{
				rocket_inviders_time_devider++;
			}

			if( rocket_inviders.getY()>750 )
			{
				rocket_inviders.setVisible(0);
				rocket_invidersXY.life = false;
			}
			else
			{
				rocket_inviders.setVisible(1);
			}

	}
	else
	{
		rocket_inviders_move=5;
			rocket_inviders_kill();
	}
}

void gameView::collusionRocketInvaders()
{
	for(int j=0 ; j<invaderNumber ;j++)
	{
		if ( rocketXY.isCreated)
		{
			if(invaderXY[j].life)
				killInviders(j);
		}
	}
}

void gameView::collusionInvadersSniper()
{
	for(int i=0 ;i<8;i++)
	{
		if((((invader[i].getX()+ invader[i].getWidth()/2) >= sniperImage.getX()) &&
			((invader[i].getX()+ invader[i].getWidth()/2) <= sniperImage.getX()+sniperImage.getWidth()) &&
			(invader[i].getY() >= sniperImage.getY()-23))||
			(((invader[i+8].getX()+ invader[i+8].getWidth()/2) >= sniperImage.getX()) &&
			((invader[i+8].getX()+ invader[i+8].getWidth()/2) <= sniperImage.getX()+sniperImage.getWidth()) &&
			(invader[i+8].getY() >= sniperImage.getY()-23)))
		{
				sniperImage.setVisible(0);
				remove(sniperImage);
		}
	}
}

void gameView::collusionRocketInvadersSniper()
{
	if(rocket_invidersXY.isCreated)
	{
		if(((rocket_inviders.getX()+ rocket_inviders.getWidth()/2) >= sniperImage.getX()) &&
			((rocket_inviders.getX()+ rocket_inviders.getWidth()/2) <= sniperImage.getX()+sniperImage.getWidth()) &&
			(rocket_inviders.getY() >= sniperImage.getY()))
		{
						sniperImage.setVisible(0);
						remove(sniperImage);
						rocket_inviders.setVisible(0);
						rocket_invidersXY.life = false;
						sniperXY.life = false;
						//gameViewBase::application().gotoendScreenNoTransition();
		}

	}

}

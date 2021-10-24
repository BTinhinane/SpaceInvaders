/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/home_screen/homeViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

homeViewBase::homeViewBase() :
    flexButtonCallback(this, &homeViewBase::flexButtonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 800);
    __background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    box1.setPosition(0, 0, 480, 272);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

    homeImage.setXY(0, 0);
    homeImage.setBitmap(touchgfx::Bitmap(BITMAP_HOME_ID));

    startImage.setXY(0, -73);
    startImage.setBitmap(touchgfx::Bitmap(BITMAP_START_ID));

    startButton.setBoxWithBorderPosition(0, 0, 150, 53);
    startButton.setBorderSize(5);
    startButton.setBoxWithBorderColors(touchgfx::Color::getColorFrom24BitRGB(0, 102, 153), touchgfx::Color::getColorFrom24BitRGB(0, 153, 204), touchgfx::Color::getColorFrom24BitRGB(0, 51, 102), touchgfx::Color::getColorFrom24BitRGB(51, 102, 153));
    startButton.setPosition(173, 631, 150, 53);
    startButton.setAlpha(0);
    startButton.setAction(flexButtonCallback);

    aboutImage.setXY(0, 0);
    aboutImage.setBitmap(touchgfx::Bitmap(BITMAP_ABOUT_ID));

    aboutButton.setBoxWithBorderPosition(0, 0, 144, 56);
    aboutButton.setBorderSize(5);
    aboutButton.setBoxWithBorderColors(touchgfx::Color::getColorFrom24BitRGB(0, 102, 153), touchgfx::Color::getColorFrom24BitRGB(0, 153, 204), touchgfx::Color::getColorFrom24BitRGB(0, 51, 102), touchgfx::Color::getColorFrom24BitRGB(51, 102, 153));
    aboutButton.setPosition(176, 705, 144, 56);
    aboutButton.setAlpha(0);
    aboutButton.setAction(flexButtonCallback);

    add(__background);
    add(box1);
    add(homeImage);
    add(startImage);
    add(startButton);
    add(aboutImage);
    add(aboutButton);
}

void homeViewBase::setupScreen()
{

}

void homeViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &startButton)
    {
        //startClick
        //When startButton clicked change screen to game
        //Go to game with no screen transition
        application().gotogameScreenNoTransition();
    }
    else if (&src == &aboutButton)
    {
        //aboutClick
        //When aboutButton clicked change screen to about
        //Go to about with no screen transition
        application().gotoaboutScreenNoTransition();
    }
}

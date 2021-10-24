/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef HOMEVIEWBASE_HPP
#define HOMEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/home_screen/homePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class homeViewBase : public touchgfx::View<homePresenter>
{
public:
    homeViewBase();
    virtual ~homeViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box box1;
    touchgfx::Image homeImage;
    touchgfx::Image startImage;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > startButton;
    touchgfx::Image aboutImage;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger > aboutButton;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<homeViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // HOMEVIEWBASE_HPP

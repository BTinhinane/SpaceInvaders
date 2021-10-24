#ifndef ABOUTPRESENTER_HPP
#define ABOUTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class aboutView;

class aboutPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    aboutPresenter(aboutView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~aboutPresenter() {};

private:
    aboutPresenter();

    aboutView& view;
};

#endif // ABOUTPRESENTER_HPP

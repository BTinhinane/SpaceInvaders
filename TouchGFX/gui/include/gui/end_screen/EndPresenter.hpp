#ifndef ENDPRESENTER_HPP
#define ENDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class EndView;

class EndPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    EndPresenter(EndView& v);

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

    virtual ~EndPresenter() {};

private:
    EndPresenter();

    EndView& view;
};

#endif // ENDPRESENTER_HPP

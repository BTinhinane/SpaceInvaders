#ifndef ABOUTVIEW_HPP
#define ABOUTVIEW_HPP

#include <gui_generated/about_screen/aboutViewBase.hpp>
#include <gui/about_screen/aboutPresenter.hpp>

class aboutView : public aboutViewBase
{
public:
    aboutView();
    virtual ~aboutView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ABOUTVIEW_HPP

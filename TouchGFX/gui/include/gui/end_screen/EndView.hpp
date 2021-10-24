#ifndef ENDVIEW_HPP
#define ENDVIEW_HPP

#include <gui_generated/end_screen/EndViewBase.hpp>
#include <gui/end_screen/EndPresenter.hpp>

class EndView : public EndViewBase
{
public:
    EndView();
    virtual ~EndView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ENDVIEW_HPP

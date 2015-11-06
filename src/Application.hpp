/// @author Dr. Martin Ettl
/// @date   2013-11-26


#ifndef APP_H
#define APP_H

#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Frame.hpp"
class MyApp : public wxApp
{
        MyFrame *m_pMainFrame;
    public:
        virtual bool OnInit();
        void CallMe();
};

wxDECLARE_APP(MyApp);

#endif // APP_H

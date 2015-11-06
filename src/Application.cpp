/// @author Dr. Martin Ettl
/// @date   2013-11-26

#include "Application.hpp"


/// The use of IMPLEMENT_APP(appClass), which allows wxWidgets to dynamically create an instance of the application object at the appropriate point in wxWidgets initialization.
/// Previous versions of wxWidgets used to rely on the creation of a global application object, but this is no longer recommended, because required global initialization may not
/// have been performed at application object construction time.
wxIMPLEMENT_APP(MyApp);

/// OnInit will usually create a top window as a bare minimum. Unlike in earlier versions of wxWidgets,
/// OnInit does not return a frame. Instead it returns a boolean value which indicates whether processing should continue (true) or not (false).
bool MyApp::OnInit(void)
{
    m_pMainFrame = new MyFrame(0L, wxT("wxGetApp"));
    m_pMainFrame->Show();
    return true;
}

void MyApp::CallMe()
{
    (void)wxMessageBox("wxGetApp works", "Confirm",
                       wxCANCEL, m_pMainFrame);

}

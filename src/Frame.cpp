/// @author Dr. Martin Ettl
/// @date   2014-12-01

#include "Application.hpp"
#include "Frame.hpp"

// wxEvent Table
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_QUIT            , MyFrame::OnQuit)
    EVT_MENU(ID_ABOUT           , MyFrame::OnAbout)
    //EVT_BUTTON(ID_START_BTN     , MyFrame::OnButton)
END_EVENT_TABLE()

MyFrame::MyFrame(wxFrame *frame, const wxString& appTitle)
    : wxFrame(frame, -1, appTitle)
    , m_menuBar(NULL)
    , m_fileMenu(NULL)
    , m_helpMenu(NULL)
{
    // set up the menu bar
    SetUpMenuBar();

    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxFrame::SetBackgroundColour(wxColor(235, 235, 235));

    wxFrame::Layout();

    this->SetSize(590, 640);

    // initialize controls with recent values
    RestoreCurrentProgramSettings();

    wxGetApp().CallMe();
}

MyFrame::~MyFrame(void)
{
    SaveCurrentProgramSettings();
}

void MyFrame::SaveCurrentProgramSettings(void)
{

    //   m_config->Write("Hex2BinConverter.parallelCheckBox", (m_parallelCheckBox->IsChecked() ? "true" : "false"));
    //   m_config->Write("Hex2BinConverter.serielCheckBox", (m_serielCheckBox->IsChecked() ? "true" : "false"));
    // cleanup
    delete m_config;
}

void MyFrame::RestoreCurrentProgramSettings(void)
{
    m_config = new wxConfig(wxFrame::GetTitle());

    // restore check box settings
    /*   wxString currentCheckBoxState;
       if( m_config->Read("Hex2BinConverter.parallelCheckBox", &currentCheckBoxState) )
       {
           m_parallelCheckBox->SetValue(currentCheckBoxState == "true");
       }
    */
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close();
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxAboutDialogInfo AboutDialogInfo;
    AboutDialogInfo.AddDeveloper(wxT("Dr. rer. nat. Martin Ettl"));
    AboutDialogInfo.SetName(this->GetTitle());
    wxString versionInfo = wxT("(");
    versionInfo += wxT(__DATE__);
    versionInfo += wxT(")");
    versionInfo += wxT("\n");
    versionInfo += wxVERSION_STRING;
    AboutDialogInfo.SetVersion(versionInfo);
    AboutDialogInfo.SetDescription(wxT("\n"));
    wxAboutBox(AboutDialogInfo);
}

void MyFrame::OnButton(wxCommandEvent &event)
{
    switch(event.GetId())
    {
        case ID_START_BTN:
        {
            break;
        }
        default:
            break;
    }
}

void MyFrame::SetUpMenuBar(void)
{
#if wxUSE_MENUS
    m_menuBar = new wxMenuBar();

    // set up the file menu
    m_fileMenu = new wxMenu(_T(""));
    m_fileMenu->Append(ID_QUIT, _("&Quit\tAlt-F4"), _("Quit the application"));
    m_menuBar->Append(m_fileMenu, _("&File"));

    // set up the help menu
    m_helpMenu = new wxMenu(_T(""));
    m_helpMenu->Append(ID_ABOUT, _("&About\tF1"), _("Show info about this application"));
    m_menuBar->Append(m_helpMenu, _("&Help"));

    // realize the menu(send it to the window)
    wxFrame::SetMenuBar(m_menuBar);
#endif // wxUSE_MENUS
}


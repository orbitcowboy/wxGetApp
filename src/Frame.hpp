/// @author Dr. Martin Ettl
/// @date   2013-11-26

#ifndef MAIN_H
#define MAIN_H

#include <wx/wx.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/textdlg.h>
#include <wx/notebook.h>
#include <wx/aboutdlg.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statline.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/spinctrl.h>
#include <wx/grid.h>
#include <wx/config.h>

class MyFrame: public wxFrame
{
        enum wxIDs
        {
            ID_ABOUT = wxID_HIGHEST
                       , ID_QUIT
            , ID_START_BTN
        };

    public:

        MyFrame(wxFrame *frame, const wxString& title);
        virtual ~MyFrame();

    protected:

        // ---------------
        // Event Handler :
        // ---------------
        void OnQuit   (wxCommandEvent& );
        void OnAbout  (wxCommandEvent& );
        void OnButton (wxCommandEvent& );

        void SaveCurrentProgramSettings(void);
        void RestoreCurrentProgramSettings(void);

        // Helper functions:
        void SetUpMenuBar  (void);

        wxPanel * m_panel;
        wxMenuBar * m_menuBar;
        wxMenu * m_fileMenu;
        wxMenu * m_helpMenu;
        wxConfig * m_config;

        DECLARE_EVENT_TABLE()
};
#endif // MAIN_H

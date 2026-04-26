#pragma once

#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
    MyFrame();

private:
    wxTextCtrl* text;
    void OnButtonClicked(wxCommandEvent& event);
};

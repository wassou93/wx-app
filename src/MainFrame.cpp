#include "MainFrame.h"

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Hello, wxWidgets")
{
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxButton* button = new wxButton(panel, wxID_ANY, "Click me");
    sizer->Add(button, 0, wxALL | wxCENTER, 10);

    text = new wxTextCtrl(panel, wxID_ANY);
    sizer->Add(text, 1, wxALL | wxEXPAND, 10);

    panel->SetSizer(sizer);

    button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
}

void MyFrame::OnButtonClicked(wxCommandEvent& event) {
    wxString input = text->GetValue();

    wxMessageBox(
        wxString::Format("You typed: %s", input),
        "Input Received",
        wxOK | wxICON_INFORMATION
    );
}

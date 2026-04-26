#include <wx/wx.h>

class MyApp : public wxApp {
public:
  virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
  MyFrame() : wxFrame(nullptr, wxID_ANY, "Hello, wxWidgets") {
    wxPanel *panel = new wxPanel(this);
    wxButton *button = new wxButton(panel, wxID_ANY, "Click me");
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(button, 0, wxALL | wxCENTER, 10);

    this->text = new wxTextCtrl(panel, wxID_ANY);
    sizer->Add(this->text, 0, wxALL | wxEXPAND, 10);

    panel->SetSizer(sizer);

    button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
  }

private:
  wxTextCtrl *text;
  void OnButtonClicked(wxCommandEvent &event) {
    wxString input = this->text->GetValue();
    // wxMessageBox("You typed: " + input, "Input Received", wxOK | wxICON_INFORMATION);
    wxMessageBox(wxString::Format("You typed: %s", input), "Input Received", wxOK | wxICON_INFORMATION);
  }
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  MyFrame *frame = new MyFrame();
  frame->Show(true);
  return true;
}

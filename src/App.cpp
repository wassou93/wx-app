#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->SetClientSize(800, 400);
    frame->Center();
    frame->Show(true);
    return true;
}

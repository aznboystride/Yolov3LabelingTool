#include "cApp.h"

wxIMPLEMENT_APP(cApp);

bool cApp::OnInit()
{
	wxInitAllImageHandlers();
	frame = new cMain();
	frame->Show();
	return true;
}

cApp::cApp()
{
}


cApp::~cApp()
{
}

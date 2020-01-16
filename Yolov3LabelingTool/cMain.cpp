#include "cMain.h"
#define FRAMEWIDTH 800
#define FRAMEHEIGHT 600
#define PHOTOFILESHEIGHT 500
#define PHOTOFILESWIDTH 200
#define PHOTOFILESX 10
#define PHOTOFILESY 45
#define SAVEWIDTH 150
#define SAVEHEIGHT 25
#define BROWSE_ID 10001

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_DIRPICKER_CHANGED(BROWSE_ID, OnBrowseClick)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(0, wxID_ANY
	, "Label Tool", wxPoint(10, 10), wxSize(FRAMEWIDTH, FRAMEHEIGHT))
{

	browse = new wxDirPickerCtrl(this, BROWSE_ID, "", "Choose Directory", wxPoint(PHOTOFILESWIDTH*(1 - .8) / 2 + PHOTOFILESX, 10), wxSize(.8*PHOTOFILESWIDTH, 25), wxDIRP_DIR_MUST_EXIST);
	//browse = new wxButton(this, BROWSE_ID, "choose directory", wxPoint(PHOTOFILESWIDTH*(1-.8)/2+PHOTOFILESX, 10), wxSize(.8*PHOTOFILESWIDTH, 25));
	save = new wxButton(this, wxID_ANY, "save", wxPoint(.9*(FRAMEWIDTH - SAVEWIDTH), .9*(FRAMEHEIGHT - SAVEHEIGHT)), wxSize(150, 25));
	photoFiles = new wxListBox(this, wxID_ANY, wxPoint(10, 45), wxSize(PHOTOFILESWIDTH, PHOTOFILESHEIGHT), 0, 0, wxLB_HSCROLL);
}


cMain::~cMain()
{
}

void cMain::OnBrowseClick(wxFileDirPickerEvent& event)
{
	for (auto& entry : std::filesystem::directory_iterator(std::string(browse->GetPath()))) {
		photoFiles->AppendString(entry.path().string());
	}
	event.Skip();
}

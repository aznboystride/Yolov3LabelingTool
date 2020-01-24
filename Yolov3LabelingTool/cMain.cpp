#include "cMain.h"
#include "constants.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_DIRPICKER_CHANGED(BROWSE_ID, OnBrowseClick)
EVT_LISTBOX_DCLICK(ITEMS_PATHS, OnItemDoubleClick)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(0, wxID_ANY
	, "Label Tool", wxPoint(10, 10), wxSize(FRAMEWIDTH, FRAMEHEIGHT))
{
	browse = new wxDirPickerCtrl(this, BROWSE_ID, "", "Choose Directory", wxPoint(PHOTOFILESWIDTH*(1 - .8) / 2 + PHOTOFILESX, 10), wxSize(.8*PHOTOFILESWIDTH, 25), wxDIRP_DIR_MUST_EXIST);
	save = new wxButton(this, wxID_ANY, "save", wxPoint(.9*(FRAMEWIDTH - SAVEWIDTH), .9*(FRAMEHEIGHT - SAVEHEIGHT)), wxSize(150, 25));
	photoFiles = new wxListBox(this, ITEMS_PATHS, wxPoint(10, 45), wxSize(PHOTOFILESWIDTH, PHOTOFILESHEIGHT), 0, 0, wxLB_HSCROLL);
}

cMain::~cMain()
{
}

void cMain::OnBrowseClick(wxFileDirPickerEvent& event)
{
	std::string path;
	for (auto& entry : std::filesystem::directory_iterator(std::string(browse->GetPath()))) {
		path = entry.path().string();
		if (path.find(".jpg") != std::string::npos || path.find(".png") != std::string::npos || path.find(".jpeg") != std::string::npos) {
			photoFiles->AppendString(entry.path().string());
		}
	}
	event.Skip();
}

void cMain::OnItemDoubleClick(wxCommandEvent & event)
{
	const wxString& item = event.GetString();
	imagePanel = new wxImagePanel(this);
	imagePanel->Render(item);
	event.Skip();
}

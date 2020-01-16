#pragma once
#include "wx/wx.h"
#include <wx/filepicker.h>
#include <filesystem>

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
	void OnBrowseClick(wxFileDirPickerEvent& event);
	wxDECLARE_EVENT_TABLE();
private:
	wxDirPickerCtrl* browse;
	wxButton* save;
	wxListBox* photoFiles;
};

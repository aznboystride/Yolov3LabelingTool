#pragma once
#include "wx/wx.h"
#include <string>
#include <wx/filepicker.h>
#include <filesystem>
#include "wxImagePanel.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
	void OnBrowseClick(wxFileDirPickerEvent& event);
	void OnItemDoubleClick(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
private:
	wxDirPickerCtrl* browse;
	wxButton* save;
	wxListBox* photoFiles;
	wxImagePanel* imagePanel;
};

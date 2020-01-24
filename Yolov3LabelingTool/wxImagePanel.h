#pragma once
#include "wx/wx.h"
class wxImagePanel : public wxPanel
{
private:
	wxBitmap image;
	wxString imagePath;
public:
	wxImagePanel(wxWindow* parent);
	void Render(const wxString& imagePath);
	~wxImagePanel();
};


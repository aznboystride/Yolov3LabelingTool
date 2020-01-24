#include "wxImagePanel.h"
#include "constants.h"


wxImagePanel::wxImagePanel(wxWindow* parent) : wxPanel(parent, IMAGEPANEL_ID, wxPoint(PANELX, PANELY), wxSize(PANELWIDTH, PANELHEIGHT))
{
}

void wxImagePanel::Render(const wxString& imagePath)
{
	wxClientDC dc(this);
	if (imagePath.find(".jpg") != wxString::npos || imagePath.find(".jpeg") != wxString::npos)
		image.LoadFile(imagePath, wxBITMAP_TYPE_JPEG);
	else
		image.LoadFile(imagePath, wxBITMAP_TYPE_PNG);
	dc.DrawBitmap(image, 0, 0);
}

wxImagePanel::~wxImagePanel()
{
}

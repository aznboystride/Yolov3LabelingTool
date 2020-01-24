#pragma once

#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp
{
private:
	cMain* frame;
public:
	bool OnInit();
	cApp();
	~cApp();
};

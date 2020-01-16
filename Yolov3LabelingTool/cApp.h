#pragma once

#include "wx\wx.h"
#include "cMain.h"

class cApp : public wxApp
{
public:
	bool OnInit();
	cApp();
	~cApp();
};


// Van_bai26.h : main header file for the Van_bai26 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CVanbai26App:
// See Van_bai26.cpp for the implementation of this class
//

class CVanbai26App : public CWinApp
{
public:
	CVanbai26App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CVanbai26App theApp;

//**************************************************************************/
// Copyright (c) 1998-2007 Autodesk, Inc.
// All rights reserved.
// 
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information written by Autodesk, Inc., and are
// protected by Federal copyright law. They may not be disclosed to third
// parties or copied or duplicated in any form, in whole or in part, without
// the prior written consent of Autodesk, Inc.
//**************************************************************************/
// DESCRIPTION: Appwizard generated plugin
// AUTHOR: 
//***************************************************************************/

#include "FSImport.h"

#define FSImport_CLASS_ID	Class_ID(0x64046c07, 0xb260dafa)


class FSImport : public SceneImport
{
public:
	//Constructor/Destructor
	FSImport();
	virtual ~FSImport();

	virtual int				ExtCount();					// Number of extensions supported
	virtual const TCHAR *	Ext(int n);					// Extension #n (i.e. "3DS")
	virtual const TCHAR *	LongDesc();					// Long ASCII description (i.e. "Autodesk 3D Studio File")
	virtual const TCHAR *	ShortDesc();				// Short ASCII description (i.e. "3D Studio")
	virtual const TCHAR *	AuthorName();				// ASCII Author name
	virtual const TCHAR *	CopyrightMessage();			// ASCII Copyright message
	virtual const TCHAR *	OtherMessage1();			// Other message #1
	virtual const TCHAR *	OtherMessage2();			// Other message #2
	virtual unsigned int	Version();					// Version number * 100 (i.e. v3.01 = 301)
	virtual void			ShowAbout(HWND hWnd);		// Show DLL's "About..." box
	virtual int				DoImport(const TCHAR *name,ImpInterface *i,Interface *gi, BOOL suppressPrompts=FALSE);	// Import file
};



class FSImportClassDesc : public ClassDesc2 
{
public:
	virtual int IsPublic() 							{ return TRUE; }
	virtual void* Create(BOOL /*loading = FALSE*/) 		{ return new FSImport(); }
	virtual const TCHAR *	ClassName() 			{ return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID SuperClassID() 				{ return SCENE_IMPORT_CLASS_ID; }
	virtual Class_ID ClassID() 						{ return FSImport_CLASS_ID; }
	virtual const TCHAR* Category() 				{ return GetString(IDS_CATEGORY); }

	virtual const TCHAR* InternalName() 			{ return _T("FSImport"); }	// returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE HInstance() 					{ return hInstance; }					// returns owning module handle
	

};


ClassDesc2* GetFSImportDesc() { 
	static FSImportClassDesc FSImportDesc;
	return &FSImportDesc; 
}




INT_PTR CALLBACK FSImportOptionsDlgProc(HWND hWnd,UINT message,WPARAM ,LPARAM lParam) {
	static FSImport* imp = nullptr;

	switch(message) {
		case WM_INITDIALOG:
			imp = (FSImport *)lParam;
			CenterWindow(hWnd,GetParent(hWnd));
			return TRUE;

		case WM_CLOSE:
			EndDialog(hWnd, 0);
			return 1;
	}
	return 0;
}


//--- FSImport -------------------------------------------------------
FSImport::FSImport()
{

}

FSImport::~FSImport() 
{

}

int FSImport::ExtCount()
{
	#pragma message(TODO("Returns the number of file name extensions supported by the plug-in."))
	return 1;
}

const TCHAR *FSImport::Ext(int /*n*/)
{		
	#pragma message(TODO("Return the 'i-th' file name extension (i.e. \"3DS\")."))
	return _T("MDL");
}

const TCHAR *FSImport::LongDesc()
{
	#pragma message(TODO("Return long ASCII description (i.e. \"Targa 2.0 Image File\")"))
	return _T("FS MDL File");
}
	
const TCHAR *FSImport::ShortDesc() 
{			
	#pragma message(TODO("Return short ASCII description (i.e. \"Targa\")"))
	return _T("FS MDL");
}

const TCHAR *FSImport::AuthorName()
{			
	#pragma message(TODO("Return ASCII Author name"))
	return _T("Igor Milovidov");
}

const TCHAR *FSImport::CopyrightMessage() 
{	
	#pragma message(TODO("Return ASCII Copyright message"))
	return _T("Virtual FlightSim Studio");
}

const TCHAR *FSImport::OtherMessage1() 
{		
	//TODO: Return Other message #1 if any
	return _T("");
}

const TCHAR *FSImport::OtherMessage2() 
{		
	//TODO: Return other message #2 in any
	return _T("");
}

unsigned int FSImport::Version()
{				
	#pragma message(TODO("Return Version number * 100 (i.e. v3.01 = 301)"))
	return 100;
}

void FSImport::ShowAbout(HWND /*hWnd*/)
{			
	// Optional
}






int FSImport::DoImport(const TCHAR* filename, ImpInterface* i, Interface* gi, BOOL suppressPrompts)
{
	#pragma message(TODO("Implement the actual file import here and"))	

	/*if(!suppressPrompts)
		DialogBoxParam(hInstance, 
				MAKEINTRESOURCE(IDD_PANEL), 
				GetActiveWindow(), 
				FSImportOptionsDlgProc, (LPARAM)this);*/

	
	return TRUE;
}

	

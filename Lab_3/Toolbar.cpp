#include "framework.h"
#include "Resource.h"
#include "Toolbar.h"
#include <commctrl.h>

Toolbar::Toolbar() {}

void Toolbar::OnCreate(HWND hWndParent, HINSTANCE hInstance) 
{
	InitCommonControls();
	TBBUTTON tbb[4]; 
	
	ZeroMemory(tbb, sizeof(tbb));
	tbb[0].iBitmap = 0;
	tbb[0].fsState = TBSTATE_ENABLED;
	tbb[0].fsStyle = TBSTYLE_BUTTON; 
	tbb[0].idCommand = ID_TOOL_POINT;

	tbb[1].iBitmap = 1;
	tbb[1].fsState = TBSTATE_ENABLED;
	tbb[1].fsStyle = TBSTYLE_BUTTON;
	tbb[1].idCommand = ID_TOOL_LINE;

	tbb[2].iBitmap = 2;
	tbb[2].fsState = TBSTATE_ENABLED;
	tbb[2].fsStyle = TBSTYLE_BUTTON;
	tbb[2].idCommand = ID_TOOL_RECTANGLE;

	tbb[3].iBitmap = 3;
	tbb[3].fsState = TBSTATE_ENABLED;
	tbb[3].fsStyle = TBSTYLE_BUTTON;
	tbb[3].idCommand = ID_TOOL_ELLIPSE;
	
	SendMessage(hwndToolbar, TB_ADDBUTTONS, 4, (LPARAM)&tbb);

	hwndToolbar = CreateToolbarEx(hWndParent,
		WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP | TBSTYLE_TOOLTIPS,
		IDC_TOOLBAR,						
		4, 
		hInstance, 
		IDB_TOOLBAR,
		tbb,
		4,				
		24, 24, 24, 24, 
		sizeof(TBBUTTON));
}

void Toolbar::OnSize(HWND hWnd)
{
	RECT rc, rw;
	if (hwndToolbar)
	{
		GetClientRect(hWnd, &rc);
		GetWindowRect(hwndToolbar, &rw);
		MoveWindow(hwndToolbar, 0, 0,
			rc.right - rc.left,
			rw.bottom - rw.top, FALSE);
	}
}

void Toolbar::OnToolChoose(HWND hWnd, LPARAM lParam)
{
	if (currentlParam)
	{
		SendMessage(hwndToolbar, TB_PRESSBUTTON, currentlParam, 0);
	}
	SendMessage(hwndToolbar, TB_PRESSBUTTON, lParam, 1);
	currentlParam = lParam;
}

void Toolbar::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	LPNMHDR pnmh = (LPNMHDR)lParam;
	if (pnmh->code == TTN_NEEDTEXT)
	{
		LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
		switch (lpttt->hdr.idFrom)
		{
		case ID_TOOL_POINT:
			lstrcpy(lpttt->szText, L"POINT drawing mode");
			break;
		case ID_TOOL_LINE:
			lstrcpy(lpttt->szText, L"LINE drawing mode");
			break;
		case ID_TOOL_RECTANGLE:
			lstrcpy(lpttt->szText, L"RECTANGLE drawing mode");
			break;
		case ID_TOOL_ELLIPSE:
			lstrcpy(lpttt->szText, L"ELLIPSE drawing mode");
			break;
		default: lstrcpy(lpttt->szText, L"What are you doing?");
		}
	}
};
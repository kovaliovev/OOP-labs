#include "framework.h"
#include "Resource.h"
#include "Table.h"

HWND Table::hWndMain = NULL;
HWND Table::hWndTable = NULL;
int Table::selectedIndex = -1;
Table* Table::p_instance = NULL;

Table* Table::GetInstance()
{
	if (!p_instance)
	{
		p_instance = new Table();
	}
	return p_instance;
};

Table::Table(){}

Table::~Table()
{
	if (p_instance)
	{
		delete p_instance;
	}
};

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hWndTable = Table::GetHWndTable();
	HWND hWndMain = Table::GetHWndMain();
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_SYSCOMMAND:
		if (wParam == SC_CLOSE) ShowWindow(hWndTable, SW_HIDE);
		break;
	case WM_COMMAND:
		if (HIWORD(wParam) == LBN_SELCHANGE)
		{	
			int index = SendMessage(GetDlgItem(hWnd, IDC_LIST1), LB_GETCURSEL, 0, 0);
			Table::SetSelectedIndex(index);

			PostMessage(hWndMain, WM_SELECT_SHAPE, index, 0);
			InvalidateRect(hWndMain, NULL, TRUE);
		}
		if (LOWORD(wParam) == IDC_REMOVE_BUTTON)
		{	
			int index = Table::GetSelectedIndex();
			if (index) 
			{
				SendMessage(GetDlgItem(hWnd, IDC_LIST1), LB_DELETESTRING, index, 0);
				PostMessage(hWndMain, WM_REMOVE_SHAPE, index, 0);
			}
			InvalidateRect(hWndMain, NULL, TRUE);
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			ShowWindow(hWndTable, SW_HIDE);
			InvalidateRect(hWndMain, NULL, TRUE);
		}
		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		hWndTable = NULL;
		break;
	}
	return FALSE;
};


void Table::OnCreate(HWND hWnd, HINSTANCE hInst)
{
	if (hWndTable)
	{
		PostMessage(hWndTable, WM_SYSCOMMAND, SC_CLOSE, 0);
		return;
	}

	hWndMain = hWnd;
	hWndTable = CreateDialog(hInst, MAKEINTRESOURCE(IDD_OBJECTS_TABLE), hWnd, (DLGPROC)DlgProc);
};

HWND Table::GetHWndTable()
{
	return hWndTable;
};

HWND Table::GetHWndMain()
{
	return hWndMain;
};

void Table::Add(LPCWSTR record)
{
	SendMessage(GetDlgItem(hWndTable, IDC_LIST1), LB_ADDSTRING, 0, (LPARAM)record);
};

void Table::Clear()
{
	SendMessage(GetDlgItem(hWndTable, IDC_LIST1), LB_RESETCONTENT, 0, 0);
}

void Table::Show()
{
	ShowWindow(hWndTable, SW_SHOW);
};

void Table::SetSelectedIndex(int index)
{
	selectedIndex = index;
};

int Table::GetSelectedIndex()
{
	return selectedIndex;
};

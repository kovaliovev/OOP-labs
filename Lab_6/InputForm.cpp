#include "framework.h"
#include "resource.h"
#include "InputForm.h"

BOOL CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK) {
			int n, min, max;
			try {
				n = stoi(InputForm::GetBoxText(hDlg, IDC_INPUT_N));
				min = stoi(InputForm::GetBoxText(hDlg, IDC_INPUT_MIN));
				max = stoi(InputForm::GetBoxText(hDlg, IDC_INPUT_MAX));
			}
			catch (...) {
				MessageBox(hDlg, L"Enter numbers in fields!", L"Type error", MB_OK | MB_ICONERROR);
				break;
			}

			if (n <= 0 || min > max || abs(min) > MAX_NUMBER || abs(min) > MAX_NUMBER) {
				MessageBox(hDlg, L"Entered numbers are invalid!", L"Value error", MB_OK | MB_ICONERROR);
				break;
			}

			HWND hWndObject2 = FindWindow(L"OBJECT2", NULL);
			if (!hWndObject2) {
				WinExec("Object_2.exe", SW_SHOW);
				hWndObject2 = FindWindow(L"OBJECT2", NULL);
			}

			int data[3] = { n, min, max };
			InputForm::SendData(hWndObject2, GetParent(hDlg), data, sizeof(data));

			HWND hWndObject3 = FindWindow(L"OBJECT3", NULL);
			if (!hWndObject3) {
				WinExec("Object_3.exe", SW_SHOW);
				hWndObject3 = FindWindow(L"OBJECT3", NULL);
			}
			PostMessage(hWndObject3, WM_CLIPBOARDUPDATE, NULL, NULL);

			EndDialog(hDlg, 1);
			return TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;
}

void InputForm::OnStart(HWND hWnd, HINSTANCE hInst) {
	DialogBox(hInst, MAKEINTRESOURCE(IDD_INPUT_FORM), hWnd, (DLGPROC)DlgProc);
}

wstring InputForm::GetBoxText(HWND hWnd, int boxId) {
	WCHAR buf[32];
	GetWindowText(GetDlgItem(hWnd, boxId), buf, 32);
	return buf;
}

void InputForm::SendData(HWND hWndDest, HWND hWndSrc, int* data, long size) {
	COPYDATASTRUCT cds;
	cds.dwData = 1;
	cds.cbData = size;
	cds.lpData = data;

	SendMessage(hWndDest, WM_COPYDATA, (WPARAM)hWndSrc, (LPARAM)&cds);
};
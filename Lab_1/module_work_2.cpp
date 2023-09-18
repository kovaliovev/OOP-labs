#include "framework.h"
#include "module_work_2.h"
#include "resource2.h"

static WCHAR* p_text;

static INT_PTR CALLBACK Work_2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return 1;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDYES)
        {
            GetDlgItemText(hDlg, IDC_EDIT2, p_text, 256);
            EndDialog(hDlg, 1);
        }
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, 0);
        }
    }
    return 0;
}

int Func_MOD2(HWND hWnd, HINSTANCE hInst, WCHAR* base_p_text)
{
    p_text = base_p_text;
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Work_2);
}

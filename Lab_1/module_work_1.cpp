#include "framework.h"
#include "module_work_1.h"
#include "resource1.h"

#define GROUPS_COUNT 10

static WCHAR* p_text;
static const WCHAR* groups[GROUPS_COUNT]
= { L"��-21", L"��-22", L"��-23", L"��-24", L"��-21", L"��-22", L"��-23", L"��-24", L"��-21", L"��-22" };

static INT_PTR CALLBACK Work_1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        for (int i = 0; i < GROUPS_COUNT; i++)
        {
            SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)groups[i]);
        }
        return 1;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDYES)
        {
            int index = SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETTEXT, index, (LPARAM)p_text);
            EndDialog(hDlg, 1);
        }
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, 0);
        }
    }
    return 0;
}

int Func_MOD1(HWND hWnd, HINSTANCE hInst, WCHAR* base_p_text)
{
    p_text = base_p_text;
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work_1);
}

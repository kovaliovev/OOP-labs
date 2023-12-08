#pragma once

#include <string>
using namespace std;

#define MAX_NUMBER 99999

class InputForm {
public:
	static wstring GetBoxText(HWND hDlg, int boxId);
	static void SendData(HWND hWndDest, HWND hWndSrc, int* data, long size);
	void OnStart(HWND hWnd, HINSTANCE hInst);
};
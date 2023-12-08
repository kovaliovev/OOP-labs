#include "framework.h"
#include "Resource.h"
#include "Vector.h"

void Vector::OnData(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	COPYDATASTRUCT* cds;
	cds = (COPYDATASTRUCT*)lParam;
	int* data = (int*)cds->lpData;
	int n = data[0];
	int min = data[1];
	int max = data[2];

	RandomGenerate(n, min, max);
	InvalidateRect(hWnd, NULL, TRUE);

	char* text = ConvertToChars();
	PutToClipboard(hWnd, text);
};

void Vector::OnPaint(HWND hWnd, HDC hdc) {
	int x = NUMS_START_X;
	int y = NUMS_START_Y;

	for (int i = 0; i < numbers.size(); i++) {
		WCHAR text[32];
		swprintf_s(text, 32, L"%8.2lf", numbers[i]);

		if (i % NUMS_IN_ROW == 0) {
			x = NUMS_START_X;
			y += 20;
		}
		TextOut(hdc, x, y, text, wcslen(text));
		x += 70;
	}
}

void Vector::RandomGenerate(int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		double normalizedValue = (double)rand() / RAND_MAX;
		double randomNum = min + normalizedValue * (max - min);
		numbers.push_back(randomNum);
	}
};

char* Vector::ConvertToChars()
{
	char buffer[CLIPBOARD_SIZE];
	memset(buffer, 0, sizeof(buffer));

	for (int i = 0; i < numbers.size(); i++)
	{
		sprintf_s(buffer, CLIPBOARD_SIZE, "%s%.2lf\n", buffer, numbers[i]);
	}

	return buffer;
}

int Vector::PutToClipboard(HWND hWnd, char* src) {
	HGLOBAL hglbCopy;
	BYTE* pTmp;
	long len;

	if (!(src && src[0])) return 0;
	len = strlen(src);

	hglbCopy = GlobalAlloc(GHND, len + 1);
	if (!hglbCopy) return 0;

	pTmp = (BYTE*)GlobalLock(hglbCopy);
	memcpy(pTmp, src, len + 1);
	GlobalUnlock(hglbCopy);

	if (!OpenClipboard(hWnd))
	{
		GlobalFree(hglbCopy);
		return 0;
	}

	EmptyClipboard();
	SetClipboardData(CF_TEXT, hglbCopy);
	CloseClipboard();

	return 1;
};
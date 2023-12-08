#include "framework.h"
#include "Resource.h"
#include "Painter.h"

void Painter::OnStart(HWND hWnd) {
	char textVector[102400];
	GetDataFromClipboard(hWnd, textVector, 102400);
	ParseVector(textVector);

	InvalidateRect(hWnd, NULL, TRUE);
}

void Painter::OnPaint(HDC hdc) {
	if (points.empty()) return;
	CalculateScaleFactors();

	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(hdc, hPen);

	DrawAxis(hdc);
	DrawNumbers(hdc);
	DrawGraph(hdc);

	DeleteObject(hPen);
}

void Painter::GetDataFromClipboard(HWND hWnd, char *dest, int maxSize) {
	if (!IsClipboardFormatAvailable(CF_TEXT)) return;
	if (!OpenClipboard(hWnd)) return;

	int size = 0;
	HGLOBAL hglb = GetClipboardData(CF_TEXT);
	if (hglb) {
		LPTSTR lptstr = (LPTSTR)GlobalLock(hglb);
		if (lptstr) {
			size = (int)strlen((char*)lptstr);
			if (size > maxSize) {
				lptstr[maxSize] = 0;
				size = (int)strlen((char*)lptstr);
			}
			strcpy_s(dest, maxSize, (char*)lptstr);
			GlobalUnlock(hglb);
		}
	}
	CloseClipboard();
};

void Painter::ParseVector(char* textVector) {
	istringstream iss(textVector);
	string str;

	while (getline(iss, str)) {
		double number = stod(str);
		points.push_back(number);
	}
};

void Painter::CalculateScaleFactors() {
	max_abs_num = abs(*max_element(points.begin(), points.end(),
		[](double a, double b) { return abs(a) < abs(b); }));

	d_x = (x_end - x_start - 20) / points.size();
	d_y = (y_end - y_start) / (2 * max_abs_num + 1);
};

void Painter::DrawAxis(HDC hdc)
{
	TextOut(hdc, x_start - 2 * arrow_size, y_start - 2 * arrow_size, L"Y", 2);

	MoveToEx(hdc, x_start - arrow_size, y_start + arrow_size, NULL);
	LineTo(hdc, x_start, y_start);
	LineTo(hdc, x_start + arrow_size, y_start + arrow_size);

	MoveToEx(hdc, x_start, y_start, NULL);
	LineTo(hdc, x_start, y_end + 10);

	int y_mid = y_end - d_y * max_abs_num;
	TextOut(hdc, x_end, y_mid + arrow_size, L"X", 2);

	MoveToEx(hdc, x_start - 30, y_mid, NULL);
	LineTo(hdc, x_end, y_mid);

	MoveToEx(hdc, x_end - arrow_size, y_mid - arrow_size, NULL);
	LineTo(hdc, x_end, y_mid);
	LineTo(hdc, x_end - arrow_size, y_mid + arrow_size);
}

void Painter::DrawNumbers(HDC hdc) {

	for (int i = 0; i < points.size(); i++) {
		int x_cord = x_start + d_x * (i + 1);
		int y_mid = y_end - d_y * max_abs_num;

		MoveToEx(hdc, x_cord, y_mid - 3, NULL);
		LineTo(hdc, x_cord, y_mid + 3);

		WCHAR x_str[8];
		swprintf_s(x_str, 8, L"%3.lf", (double)i + 1);
		TextOut(hdc, x_cord - 10, y_mid + 10, x_str, wcslen(x_str));
	}

	for (int i = 0; i < 2 * max_abs_num + 1; i++) {
		int y_cord = y_end - d_y * i;

		MoveToEx(hdc, x_start - 3, y_cord, NULL);
		LineTo(hdc, x_start + 3, y_cord);

		WCHAR y_str[8];
		swprintf_s(y_str, 8, L"%3.lf", -max_abs_num + i);
		TextOut(hdc, x_start - 30, y_cord - 8, y_str, wcslen(y_str));
	}
}

void Painter::DrawGraph(HDC hdc) {
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBrush);

	for (int i = 0; i < points.size(); i++) {
		int x_cord = x_start + d_x * (i + 1);
		double y_cord = y_end - d_y * (points[i] + max_abs_num);

		if(i == 0) MoveToEx(hdc, x_cord, y_cord, NULL);

		LineTo(hdc, x_cord, y_cord);
		Ellipse(hdc, x_cord - 3, y_cord - 3, x_cord + 3, y_cord + 3);
	}
	DeleteObject(hBrush);
}
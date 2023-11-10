#include "framework.h"
#include "resource.h"
#include "Line_Shape.h"

void LineShape::Show(HDC hdc) {
	MoveToEx(hdc, shape_x_1, shape_y_1, NULL);
	LineTo(hdc, shape_x_2, shape_y_2);
}

void LineShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	HMENU hMenu = GetMenu(hWnd);
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_OBJECTS_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_LINE, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_RECTANGLE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_OLINEO, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_CUBE, MF_UNCHECKED);
	}
};

void LineShape::DrawRubberTrack(HWND hWnd) {
	HPEN hPenOld, hPen;
	HDC hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DASH, 1, COL_BLACK);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	LineShape::Show(hdc);
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
};

Shape* LineShape::CreateNew() {
	return new LineShape;
};
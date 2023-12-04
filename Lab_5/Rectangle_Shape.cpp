#include "framework.h"
#include "resource.h"
#include "Rectangle_Shape.h"

RectangleShape::RectangleShape() {
	SetName(L"Rectangle");
	SetColor(COL_YELLOW);
}

void RectangleShape::Show(HDC hdc, BOOL isSelected) {
	COLORREF color = (isSelected ? COL_RED : shape_color);

	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(color);
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, shape_x_1, shape_y_1, shape_x_2, shape_y_2);
	
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

void RectangleShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	HMENU hMenu = GetMenu(hWnd);
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_OBJECTS_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_RECTANGLE, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_OLINEO, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_CUBE, MF_UNCHECKED);
	}
};

void RectangleShape::DrawRubberTrack(HWND hWnd) {
	HPEN hPenOld, hPen;
	HDC hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);

	hPen = CreatePen(PS_DASH, 1, COL_BLACK);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	Rectangle(hdc, shape_x_1, shape_y_1, shape_x_2, shape_y_2);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
};

Shape* RectangleShape::CreateNew() {
	return new RectangleShape;
};
#include "framework.h"
#include "resource.h"
#include "Shape_Editor.h"
#include "Rectangle_Shape.h"
#include "Rectangle_Editor.h"

#define COL_BLACK RGB(0, 0, 0)

void RectangleEditor::OnLBup(HWND hWnd) {
	pp_shapes[index] = new RectangleShape;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	pp_shapes[index]->SetStartCords(x_start, y_start);
	pp_shapes[index]->SetEndCords(point.x, point.y);

	InvalidateRect(hWnd, NULL, TRUE);
	index++;
	isDrawing = false;
}

void RectangleEditor::OnMouseMove(HWND hWnd) {
	if (!isDrawing) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);

	hPen = CreatePen(PS_SOLID, 1, COL_BLACK);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	Rectangle(hdc, x_start, y_start, x_end, y_end);

	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	x_end = point.x;
	y_end = point.y;

	Rectangle(hdc, x_start, y_start, x_end, y_end);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
};

void RectangleEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu = GetMenu(hWnd);
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_OBJECTS_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_RECTANGLE, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_ELLIPSE, MF_UNCHECKED);
	}
}
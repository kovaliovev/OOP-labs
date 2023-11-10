#include "framework.h"
#include "resource.h"
#include "Shape_Editor.h"
#include "Ellipse_Shape.h"
#include "Ellipse_Editor.h"

#define COL_BLACK RGB(0, 0, 0)

void EllipseEditor::OnLBup(HWND hWnd) {
	pp_shapes[index] = new EllipseShape;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	pp_shapes[index]->SetStartCords(x_start, y_start);
	pp_shapes[index]->SetEndCords(point.x, point.y);

	InvalidateRect(hWnd, NULL, TRUE);
	index++;
	isDrawing = false;
}

void EllipseEditor::OnMouseMove(HWND hWnd) {
	if (!isDrawing) return;
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);

	hPen = CreatePen(PS_SOLID, 1, COL_BLACK);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	int real_x_start = x_end - (2 * (x_end - x_start));
	int real_y_start = y_end - (2 * (y_end - y_start));
	Arc(hdc, real_x_start, real_y_start, x_end, y_end, 0, 0, 0, 0);

	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	x_end = point.x;
	y_end = point.y;

	real_x_start = x_end - (2 * (x_end - x_start));
	real_y_start = y_end - (2 * (y_end - y_start));
	Arc(hdc, real_x_start, real_y_start, x_end, y_end, 0, 0, 0, 0);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
};

void EllipseEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu = GetMenu(hWnd);
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_OBJECTS_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_RECTANGLE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_ELLIPSE, MF_CHECKED);
	}
}
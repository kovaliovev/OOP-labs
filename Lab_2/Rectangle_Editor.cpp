#include "framework.h"
#include "Shape_Editor.h"
#include "Rectangle_Shape.h"
#include "Rectangle_Editor.h"

#define COL_BLACK RGB(0, 0, 0)

void RectangleEditor::OnLBup(HWND hWnd) {
	p_shapes[index] = new RectangleShape;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	p_shapes[index]->SetStartCords(x_start, y_start);
	p_shapes[index]->SetEndCords(point.x, point.y);

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

	hPen = CreatePen(PS_DASH, 1, COL_BLACK);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	int real_x_start = x_end - (2 * (x_end - x_start));
	int real_y_start = y_end - (2 * (y_end - y_start));
	Rectangle(hdc, real_x_start, real_y_start, x_end, y_end);

	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	x_end = point.x;
	y_end = point.y;

	real_x_start = x_end - (2 * (x_end - x_start));
	real_y_start = y_end - (2 * (y_end - y_start));
	Rectangle(hdc, real_x_start, real_y_start, x_end, y_end);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
};

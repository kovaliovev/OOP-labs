#include "framework.h"
#include "Shape_Editor.h"
#include "Ellipse_Shape.h"
#include "Ellipse_Editor.h"

#define COL_BLACK RGB(0, 0, 0)

void EllipseEditor::OnLBup(HWND hWnd) {
	p_shapes[index] = new EllipseShape;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	p_shapes[index]->SetStartCords(x_start, y_start);
	p_shapes[index]->SetEndCords(point.x, point.y);

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

	hPen = CreatePen(PS_DASH, 1, COL_BLACK);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	Ellipse(hdc, x_start, y_start, x_end, y_end);

	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	x_end = point.x;
	y_end = point.y;

	Ellipse(hdc, x_start, y_start, x_end, y_end);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
};

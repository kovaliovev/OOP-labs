#include "framework.h"
#include "Editor.h"

Shape* Editor::p_shapes[ARRAY_OF_SHAPES_SIZE];
int Editor::currIndex = 0;

void Editor::Start(HWND hWnd, LPARAM lParam, Shape* shape) {
	currShape = shape;
	toolbar.OnToolChoose(hWnd, lParam);
}

void Editor::OnLBdown(HWND hWnd) {
	if (!currShape) return;
	isDrawing = true;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	p_shapes[currIndex] = currShape->CreateNew();
	p_shapes[currIndex]->SetStartCords(point.x, point.y);
	p_shapes[currIndex]->SetEndCords(point.x, point.y);
}

void Editor::OnLBup(HWND hWnd) {
	if (!(isDrawing && currShape)) return;
	isDrawing = false;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	p_shapes[currIndex]->SetEndCords(point.x, point.y);
	currIndex++;
	InvalidateRect(hWnd, NULL, TRUE);
}

void Editor::OnMouseMove(HWND hWnd) {
	if (!(isDrawing && currShape)) return;
	p_shapes[currIndex]->DrawRubberTrack(hWnd);
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	p_shapes[currIndex]->SetEndCords(point.x, point.y);
	p_shapes[currIndex]->DrawRubberTrack(hWnd);
}

void Editor::OnPaint(HWND hWnd) {
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < ARRAY_OF_SHAPES_SIZE; i++)
	{
		if (p_shapes[i]) p_shapes[i]->Show(hdc);
	}
	EndPaint(hWnd, &ps);
}

void Editor::OnCreate(HWND hWnd, HINSTANCE hInst) {
	toolbar.OnCreate(hWnd, hInst);
}

void Editor::OnSize(HWND hWnd) {
	toolbar.OnSize(hWnd);
}

void Editor::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam) {
	toolbar.OnNotify(hWnd, wParam, lParam);
}

void Editor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	if (currShape) currShape->OnInitMenuPopup(hWnd, wParam);
}
#include "framework.h"
#include "resource.h"
#include "Editor.h"
#include <fstream>

Shape* Editor::p_shapes[ARRAY_OF_SHAPES_SIZE];
int Editor::currIndex = 0;
Editor* Editor::p_instance = NULL;

Editor* Editor::GetInstance()
{
	if (!p_instance)
		p_instance = new Editor();
	return p_instance;
}

Editor::~Editor()
{
	for (int i = 0; i < ARRAY_OF_SHAPES_SIZE; i++)
	{
		if (p_shapes[i]) delete p_shapes[i];
	}
}

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

void Editor::OnLBup(HWND hWnd, TABLEADD TableAdd) {
	if (!(isDrawing && currShape)) return;

	isDrawing = false;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	p_shapes[currIndex]->SetEndCords(point.x, point.y);

	WCHAR tableRecord[64];
	p_shapes[currIndex]->GetInfo(tableRecord);
	TableAdd(tableRecord);

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

void Editor::OnPaint(HWND hWnd, int selectedIndex) {
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	int realIndex = 0;
	for (int i = 0; i < ARRAY_OF_SHAPES_SIZE; i++)
	{	
		if (p_shapes[i]) 
		{	
			BOOL isSelected = (realIndex == selectedIndex);
			p_shapes[i]->Show(hdc, isSelected);
			realIndex++;
		}
	}
	EndPaint(hWnd, &ps);
}

void Editor::OnShapeRemove(HWND hWnd, int selectedIndex) {
	int realIndex = 0;
	for (int i = 0; i < ARRAY_OF_SHAPES_SIZE; i++)
	{
		if (p_shapes[i])
		{
			if (realIndex == selectedIndex)
			{
				p_shapes[i] = NULL;
				break;
			}
			realIndex++;
		}
	}
}

void Editor::OnCreate(HWND hWnd, HINSTANCE hInst, TABLEADD TableAdd) {
	toolbar.OnCreate(hWnd, hInst);
	TableAdd(L"SHAPE\t\tx1\ty1\tx2\ty2\n");
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

void Editor::OnFileSave(LPCWSTR path) {
	FILE* outputFile;
	_wfopen_s(&outputFile, path, L"w");
	if (outputFile)
	{
		fwprintf(outputFile, L"SHAPE\t\tx1\ty1\tx2\ty2\n");
		for (int i = 0; i < ARRAY_OF_SHAPES_SIZE; i++)
		{	
			if (!p_shapes[i]) continue;
			WCHAR line[64];
			p_shapes[i]->GetInfo(line);
			fwprintf(outputFile, line);
		}
		fclose(outputFile);
	}

}

void Editor::OnFileLoad(HWND hWnd, LPCWSTR path, TABLEADD TableAdd, TABLECLEAR TableClear) {
	FILE* inputFile;
	_wfopen_s(&inputFile, path, L"r");
	if (inputFile)
	{
		TableClear();
		for (int i = 0; i < ARRAY_OF_SHAPES_SIZE; i++)
		{
			if (p_shapes[i]) p_shapes[i] = NULL;
		}
		currIndex = 0;
		InvalidateRect(hWnd, NULL, TRUE);

		WCHAR buf[64];
		while (fgetws(buf, 64, inputFile))
		{
			WCHAR shapeName[64];
			int x1, y1, x2, y2;
			if (swscanf_s(buf, L"%s\t\t%d\t%d\t%d\t%d\n", shapeName, 64, &x1, &y1, &x2, &y2))
			{
				TableAdd((LPCWSTR)buf);
				int shapeType;

				if (!wcscmp(shapeName, L"Point")) {
					shapeType = ID_OBJECTS_POINT;
				}
				else if (!wcscmp(shapeName, L"Line")) {
					shapeType = ID_OBJECTS_LINE;
				}
				else if (!wcscmp(shapeName, L"Rectangle")) {
					shapeType = ID_OBJECTS_RECTANGLE;
				}
				else if (!wcscmp(shapeName, L"Ellipse")) {
					shapeType = ID_OBJECTS_ELLIPSE;
				}
				else if (!wcscmp(shapeName, L"OlineO")) {
					shapeType = ID_OBJECTS_OLINEO;
				}
				else if (!wcscmp(shapeName, L"Cube")) {
					shapeType = ID_OBJECTS_CUBE;
				}
				else continue;

				SendMessage(hWnd, WM_COMMAND, shapeType, 0);
				p_shapes[currIndex] = currShape->CreateNew();
				p_shapes[currIndex]->SetStartCords(x1, y1);
				p_shapes[currIndex]->SetEndCords(x2, y2);
				currIndex++;
			}
		}
		fclose(inputFile);
	}
}
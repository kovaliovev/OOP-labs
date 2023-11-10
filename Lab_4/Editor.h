#pragma once
#include "Shape.h"
#include "Toolbar.h"

#define ARRAY_OF_SHAPES_SIZE 111

class Editor {
private:
	static Shape* p_shapes[ARRAY_OF_SHAPES_SIZE];
	static int currIndex;
	Shape* currShape;
	Toolbar toolbar;
	bool isDrawing = false;
	POINT point;
public:
	void Start(HWND, LPARAM, Shape*);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnInitMenuPopup(HWND, WPARAM);
};
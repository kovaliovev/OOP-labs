#pragma once
#include "Line_Shape.h"
#include "Rectangle_Shape.h"

#define CUBE_SIZE 30

class CubeShape : public LineShape, public RectangleShape {
public:
	void Show(HDC);
	void OnInitMenuPopup(HWND, WPARAM);
	void DrawRubberTrack(HWND);
	Shape* CreateNew();
};
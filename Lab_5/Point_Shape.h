#pragma once
#include "Shape.h"

class PointShape : public Shape {
public:
	PointShape();
	void Show(HDC, BOOL);
	void OnInitMenuPopup(HWND, WPARAM);
	void DrawRubberTrack(HWND);
	Shape* CreateNew();
};
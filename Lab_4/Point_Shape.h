#pragma once
#include "Shape.h"

class PointShape : public Shape {
public:
	void Show(HDC);
	void OnInitMenuPopup(HWND, WPARAM);
	void DrawRubberTrack(HWND);
	Shape* CreateNew();
};
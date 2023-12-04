#pragma once
#include "Shape.h"

class RectangleShape : public virtual Shape {
public:
	RectangleShape();
	void Show(HDC, BOOL);
	void OnInitMenuPopup(HWND, WPARAM);
	void DrawRubberTrack(HWND);
	Shape* CreateNew();
};
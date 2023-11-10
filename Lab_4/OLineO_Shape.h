#pragma once
#include "Line_Shape.h"
#include "Ellipse_Shape.h"

#define O_SIZE 10

class OLineOShape : public LineShape, public EllipseShape {
public:
	void Show(HDC);
	void OnInitMenuPopup(HWND, WPARAM);
	void DrawRubberTrack(HWND);
	Shape* CreateNew();
};
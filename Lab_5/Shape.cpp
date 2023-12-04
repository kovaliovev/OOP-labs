#include "framework.h"
#include "Shape.h"

Shape::~Shape() {}

void Shape::SetStartCords(int new_x_start, int new_y_start) {
	shape_x_1 = new_x_start;
	shape_y_1 = new_y_start;
}

void Shape::SetEndCords(int new_x_end, int new_y_end) {
	shape_x_2 = new_x_end;
	shape_y_2 = new_y_end;
}

void Shape::SetColor(COLORREF new_color) {
	shape_color = new_color;
}

void Shape::SetName(LPCWSTR new_name) {
	shape_name = new_name;
}

void Shape::GetInfo(WCHAR*string) {
	LPCWSTR shapeName = GetName();
	LPCWSTR format =
		wcslen(shapeName) >= 8 ?
		L"%s\t%d\t%d\t%d\t%d\n" :
		L"%s\t\t%d\t%d\t%d\t%d\n";
	swprintf_s(string, 64, format, shapeName, shape_x_1, shape_y_1, shape_x_2, shape_y_2);
}

LPCWSTR Shape::GetName() {
	return shape_name;
}
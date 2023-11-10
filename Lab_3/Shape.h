#pragma once

class Shape {
protected:
	int shape_x_1;
	int shape_y_1;
	int shape_x_2;
	int shape_y_2;
public:
	virtual ~Shape();
	void SetStartCords(int new_x_start, int new_y_start);
	void SetEndCords(int new_x_end, int new_y_end);
	virtual void Show(HDC) = 0;
};
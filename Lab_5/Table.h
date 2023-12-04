#pragma once

class Table
{
private:
	static Table* p_instance;
	Table();
	Table(const Table&);
	Table& operator=(Table&);
	static HWND hWndTable;
	static HWND hWndMain;
	static int selectedIndex;
public:
	static Table* GetInstance();
	~Table();
	void OnCreate(HWND, HINSTANCE);
	void Show();
	static HWND GetHWndTable();
	static HWND GetHWndMain();
	static void Add(LPCWSTR);
	static void Clear();
	static int GetSelectedIndex();
	static void SetSelectedIndex(int);
};

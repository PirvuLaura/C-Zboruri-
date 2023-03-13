#pragma once
#pragma once
#include "service.h"
class ui
{
private:
	service service;
	void showMenu();

	void ui_add_zbor();

	void ui_delete_zbor();

	void ui_update_zbor();

	void ui_show_all();
public:
	ui();
	ui(class service service);
	~ui();

	void run_menu();
};

#pragma once
#include <gtkmm.h>
#include <gtkmm/fontselection.h>
class MyWindow : public Gtk::Window
{
public:
	MyWindow();
	~MyWindow(void);
private:
	Gtk::FontSelection m_fontSelection;
	Gtk::VBox m_box;
	Gtk::Button m_button;
	void on_button_clicked();
};

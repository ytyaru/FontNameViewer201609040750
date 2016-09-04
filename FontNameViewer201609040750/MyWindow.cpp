#include "MyWindow.h"
#include <gtkmm/box.h>
MyWindow::MyWindow(void)
{
	m_button.set_label("Select");
	m_button.signal_clicked().connect(sigc::mem_fun( *this, &MyWindow::on_button_clicked ) );
	m_box.pack_start(m_fontSelection);
	m_box.pack_start(m_button, Gtk::PACK_SHRINK, 0);
	this->add(m_box);
	show_all_children();
}
MyWindow::~MyWindow(void)
{
}
void MyWindow::on_button_clicked()
{
	g_print("Selected font: %s\n", m_fontSelection.get_font_name().c_str());
}
#include "ApplicationView.h"

using namespace View;

ApplicationView* ApplicationView::m_instance = nullptr;

ApplicationView::ApplicationView()
{}

ApplicationView::~ApplicationView()
{
	delete m_instance;
}

ApplicationView* ApplicationView::getInstance()
{
	if(!m_instance)
		m_instance = new ApplicationView();
	return m_instance;
}


// static Event fired from GTK
void ApplicationView::calculateClicked(GtkWidget *widget, gpointer data)
{
	ApplicationView::getInstance()->whenCalculateClicked();
}

void ApplicationView::onCalculateClicked( CallbackFunction callback)
{
	whenCalculateClicked = callback;
}

void ApplicationView::build()
{
  // calculate button stuff
  GtkWidget *calculateButton = gtk_button_new_with_label("Calculate");
  g_signal_connect(calculateButton, "clicked", G_CALLBACK(calculateClicked), this);
  gtk_widget_show(calculateButton);

  // box it up
  GtkWidget *bigBox = gtk_vbox_new(TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bigBox), calculateButton, FALSE, FALSE, 0);
  gtk_widget_show(bigBox);

  // window stuff
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "PF Calculator");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 80);
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect_swapped(window, "delete-event", G_CALLBACK(gtk_widget_destroy), window);
  gtk_widget_show(window);

  // tie the room together
  gtk_container_add(GTK_CONTAINER(window), bigBox);
}

void ApplicationView::start()
{
  gtk_main();
}


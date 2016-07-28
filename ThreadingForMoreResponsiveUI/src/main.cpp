#include <iostream>
#include <gtk/gtk.h>
#include "../inc/crawlingView.h"

namespace oblongata
{
	namespace crawler
	{

		void displayCrawlingView (GtkApplication* app, gpointer user_data)
		{

			crawlingView crawlingv(app);

			GtkWidget *window = crawlingv.getInstance();

			if(window)
			{
				gtk_widget_show_all (window);
			}
			else
			{
				std::cout << "ERROR happened";
			}
		}
	}
}


int main(int argc, char* argv[])
{
	std::cout << "Main is executed" << std::endl;

	  GtkApplication *app;
	  int status;


	  app = gtk_application_new ("org.oblongata.crawler", G_APPLICATION_FLAGS_NONE);
	  g_signal_connect (app, "activate", G_CALLBACK (oblongata::crawler::displayCrawlingView), NULL);
	  status = g_application_run (G_APPLICATION (app), argc, argv);
	  g_object_unref (app);


}

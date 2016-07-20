#ifndef _APPLICATION_VIEW_H_
#define _APPLICATION_VIEW_H_

#include <gtk/gtk.h>
#include <functional>
#include <iostream>

using namespace std;

namespace View
{
	typedef std::function<void()> CallbackFunction;

	class ApplicationView
	{
	public:
		~ApplicationView();
		ApplicationView(ApplicationView const&) = delete;
		void operator=(ApplicationView const&) = delete;

		static ApplicationView* getInstance();

		//events to register in Presenter
		void onCalculateClicked(CallbackFunction callback);

		//Events from GTK
		static void calculateClicked(GtkWidget *widget, gpointer data);

		// getter for the values
		int getSummandA() { return 10; }
		int getSummandB() { return 20; }

		//public Interface
		void build();
		void start();

	private:
		//Singleton
		ApplicationView();
		static ApplicationView* m_instance;

		//Callbacks back to Presenter
		CallbackFunction whenCalculateClicked;
	};
}

#endif //_APPLICATION_VIEW_H_

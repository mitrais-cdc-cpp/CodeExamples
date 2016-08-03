#include "../../inc/crawlingView.h"

using namespace oblongata::crawler;

// static variables
crawlingPresenter* presenter = nullptr;

// local variables
GtkWidget *container_box;
GtkWidget *gridContainer;

GtkWidget *headerInfoLabel;

GtkWidget *doActionButton;

GtkWidget *anyTextLabel;
GtkWidget *anyTextEntry;


GtkWidget *statusBar;
guint statusBarContextId;


crawlingView::crawlingView(GtkApplication* app) : gtkApp(app)
{

}

crawlingView::~crawlingView()
{

}

void displayStatus(const char* message)
{
	gtk_statusbar_push(GTK_STATUSBAR(statusBar), statusBarContextId, message);
}

static void triggerStatusDisplay(const char* theMessage, void(*func) (const char*))
{
	func(theMessage);
}

static void *performTimeConsumingTask(void *threadId)
{
	std::cout << "A - thread address: " << &threadId << std::endl;

	triggerStatusDisplay("timeconsuming task is started", &displayStatus);

	presenter->doingSomethingTimeConsuming(&displayStatus);

	//pthread_exit(NULL); // it will wait the thread operation completion. Not need to avoid blocking
}

static void onButtonAClicked( GtkWidget *widget, gpointer data)
{
	displayStatus("button A clicked.");

	pthread_t myThread;

	pthread_create(&myThread, NULL, performTimeConsumingTask, NULL);
}


GtkWidget* crawlingView::getInstance()
{
	viewInstance = gtk_application_window_new (gtkApp);

	// set title and size
	gtk_window_set_title (GTK_WINDOW (viewInstance), "Welcome on Threading sample");
	gtk_window_set_default_size (GTK_WINDOW (viewInstance), 500, 200);

	gridContainer = gtk_grid_new();

	// add the container to the window
	gtk_container_add (GTK_CONTAINER (viewInstance), gridContainer);

	// add the header info into the container as the first item, cell 0,0, 2 span horizontal, 1 height
	headerInfoLabel = gtk_label_new_with_mnemonic("Please hit the button and then keep interaction with the UI (by typing something) \nwhile the backend processing is being performed.\n \n The status bar will display the backend message.\n");
	gtk_grid_attach(GTK_GRID(gridContainer), headerInfoLabel, 0,0,3,1);


	// add buttons
	doActionButton = gtk_button_new_with_label ("Do Action");
	g_signal_connect (doActionButton, "clicked", G_CALLBACK (onButtonAClicked), NULL);
	gtk_grid_attach(GTK_GRID(gridContainer), doActionButton, 0,1,3,1);


	// add label and text input pair to play with
	anyTextLabel = gtk_label_new_with_mnemonic("Entry anything:");
	gtk_grid_attach(GTK_GRID(gridContainer), anyTextLabel, 0,2,1,1);

	anyTextEntry = gtk_entry_new ();
	//gtk_entry_set_max_length (GTK_ENTRY (anyTextEntry),10);
	gtk_grid_attach(GTK_GRID(gridContainer), anyTextEntry, 1,2,2,1);



	statusBar = gtk_statusbar_new();
	statusBarContextId = gtk_statusbar_get_context_id(GTK_STATUSBAR (statusBar), "status bar");
	gtk_grid_attach(GTK_GRID(gridContainer), statusBar, 0,4,3,1);

	return viewInstance;
}

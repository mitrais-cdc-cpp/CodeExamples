/*
 * crawlerView.h
 *
 *  Created on: Jul 18, 2016
 *      Author: developer
 */

#ifndef INC_CRAWLINGVIEW_H_
#define INC_CRAWLINGVIEW_H_

#include <iostream>
#include <gtk/gtk.h>
#include "crawlingPresenter.h"

namespace oblongata
{
	namespace crawler
	{
		class crawlingView
		{
			public:
				crawlingView(GtkApplication* app);

				virtual ~crawlingView();

				virtual GtkWidget* getInstance();

			protected:
				GtkApplication* gtkApp;

				GtkWidget* viewInstance;

				// it shall be static due to gtk expectation
				static crawlingPresenter* presenter;
		};
	}
}


#endif /* INC_CRAWLINGVIEW_H_ */

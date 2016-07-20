#ifndef _ApplicationPresenter_H_
#define _ApplicationPresenter_H_

#include <functional>
#include <iostream>

#include "../view/ApplicationView.h"
#include "../model/ApplicationModel.h"



namespace Present
{
	class ApplicationPresenter
	{
	public:

		ApplicationPresenter(View::ApplicationView *view, Model::ApplicationModel *model);
		~ApplicationPresenter();

		//derived
		void registerEvents();

		void applicationStartCallback();
		void calculateClickedCallback();

	private:
	    View::ApplicationView *m_view;
		Model::ApplicationModel *m_model;
	};
}

#endif // _ApplicationPresenter_H_

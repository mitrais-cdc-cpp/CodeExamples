#ifndef _ApplicationModel_H_
#define _ApplicationModel_H_

#include <functional>
#include <iostream>

namespace Model
{
	typedef std::function<void()> CallbackFunction;

	class ApplicationModel
	{
	public:
		~ApplicationModel();
		ApplicationModel(ApplicationModel const&) = delete;
		void operator=(ApplicationModel const&) = delete;

		static ApplicationModel* getInstance();

		void run();
		int sum(int a, int b);

		void whenApplicationStarts(CallbackFunction callback);

	private:

		ApplicationModel();

		CallbackFunction cb;

		static ApplicationModel* m_instance;
	};
}

#endif // _ApplicationModel_H_

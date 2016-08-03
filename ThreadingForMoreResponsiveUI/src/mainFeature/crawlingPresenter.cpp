#include "../../inc/crawlingPresenter.h"

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <ctime>

using namespace oblongata::crawler;

const int maxCounter = 10;

crawlingPresenter::crawlingPresenter()
{
	std::cout << "crawlingPresenter constructor" << std::endl;
}

crawlingPresenter::~crawlingPresenter()
{
	std::cout << "crawlingPresenter destructor" << std::endl;
}

void crawlingPresenter::doingSomethingTimeConsuming(void(*funcToInformUI) (const char*))
{
	std::cout << "doingSomethingTimeConsuming" << std::endl;

	funcToInformUI("doingSomethingTimeConsuming");

	std::string message;



	for(int i = 0;i < maxCounter; i++)
	{
	    // extract the current date time, ignoring the newline feed at the end of the string.
	    time_t now = time(0);
	    std::string currentTime = ctime(&now);
	    currentTime = "[" + currentTime.substr(0, currentTime.length()-1) + "]";

	    message += currentTime;
	    message += " doing something at the background for ";
		message += std::to_string(i);
		message += " seconds.";

		std::cout << message << std::endl;

		const char* msgToUI = message.c_str();
		funcToInformUI(msgToUI);

		sleep(i);
		message = "";
	}


	std::cout << "[end] doingSomethingTimeConsuming" << std::endl;
	funcToInformUI("[end] doingSomethingTimeConsuming");

}


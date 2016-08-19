
#include <memory>
#include "Logger.h"
#include "ATM.h"





using namespace std;

static std::shared_ptr<AbstractLogger> getChainOfLogger()
{
	auto errorLogger = std::make_shared<ErrorLogger>(AbstractLogger::ERROR);
	auto outputLogger = std::make_shared<OutputLogger>(AbstractLogger::INFO);
	auto standardLogger = std::make_shared<StandardLogger>(AbstractLogger::DEBUG);

	errorLogger->setNextLogger(outputLogger);
	outputLogger->setNextLogger(standardLogger);

	return errorLogger;
}

static std::shared_ptr<MoneyHandler> getChainOfATM()
{
	auto hundredHandler = std::make_shared<HundredHandler>(MoneyHandler::HUNDRED);
	auto fiftyHandler = std::make_shared<FiftyHandler>(MoneyHandler::FIFTY);
	auto twentyHandler = std::make_shared<TwentyHandler>(MoneyHandler::TWENTY);
	auto tenHandler = std::make_shared<TenHandler>(MoneyHandler::TEN);

	hundredHandler->setNextHandler(fiftyHandler);
	fiftyHandler->setNextHandler(twentyHandler);
	twentyHandler->setNextHandler(tenHandler);

	return hundredHandler;
}

int main()
{
/*	auto loggerChain = getChainOfLogger();
	loggerChain->logMessage(AbstractLogger::INFO, "This is an information!");
	loggerChain->logMessage(AbstractLogger::DEBUG, "This is a debug message!");
	loggerChain->logMessage(AbstractLogger::ERROR, "This is an error!");*/

	auto atmChain = getChainOfATM();
	atmChain->calculate(MoneyHandler::FIFTY, 1280);


	return 0;
}

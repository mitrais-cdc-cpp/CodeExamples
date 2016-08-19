#ifndef INC_ATM_H_
#define INC_ATM_H_

#include <iostream>
#include <memory>



class MoneyHandler
{
	protected:
		int level;
		std::shared_ptr<MoneyHandler> nextHandler;
		virtual int handle(int amount_) = 0;

	public:
		MoneyHandler(int level_) : level(level_){}
		virtual ~MoneyHandler() {}

		static const int HUNDRED	= 100;
		static const int FIFTY 		= 50;
		static const int TWENTY 	= 20;
		static const int TEN 		= 10;

	void setNextHandler(std::shared_ptr<MoneyHandler> next_)
	{
		this->nextHandler = next_;
	}

	void calculate(int level_, int sum_)
	{
		if(this->level <= level_)
		{
			sum_ = handle(sum_);
		}
		if(nextHandler != nullptr)
		{
			nextHandler->calculate(level_, sum_);
		}
	}
};

const int MoneyHandler::HUNDRED;
const int MoneyHandler::FIFTY;
const int MoneyHandler::TWENTY;
const int MoneyHandler::TEN;

class HundredHandler : public MoneyHandler
{
	public:
		HundredHandler(int level_) : MoneyHandler(level_) {}
	protected:
		int handle(int amount_) override
		{
			int rest = amount_ % MoneyHandler::level;
			int i = amount_ / MoneyHandler::level;

			std::cout << "HundredHandler gives out: " << i << " notes!" << std::endl;

			return rest;
		}
};

class FiftyHandler : public MoneyHandler
{
	public:
		FiftyHandler(int level_) : MoneyHandler(level_) {}
	protected:
		int handle(int amount_) override
		{
			int rest = amount_ % MoneyHandler::level;
			int i = amount_ / MoneyHandler::level;

			std::cout << "FiftyHandler gives out: " << i << " notes!" << std::endl;

			return rest;
		}
};

class TwentyHandler : public MoneyHandler
{
	public:
		TwentyHandler(int level_) : MoneyHandler(level_) {}
	protected:
		int handle(int amount_) override
		{
			int rest = amount_ % MoneyHandler::level;
			int i = amount_ / MoneyHandler::level;

			std::cout << "TwentyHandler gives out: " << i << " notes!" << std::endl;

			return rest;
		}
};

class TenHandler : public MoneyHandler
{
	public:
		TenHandler(int level_) : MoneyHandler(level_) {}
	protected:
		int handle(int amount_) override
		{
			int rest = amount_ % MoneyHandler::level;
			int i = amount_ / MoneyHandler::level;

			std::cout << "TenHandler gives out: " << i << " notes!" << std::endl;

			return rest;
		}
};



#endif /* INC_ATM_H_ */

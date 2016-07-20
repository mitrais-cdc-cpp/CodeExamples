#include "ApplicationModel.h"

using namespace Model;

ApplicationModel* ApplicationModel::m_instance = nullptr;

ApplicationModel::ApplicationModel()
{

}

ApplicationModel::~ApplicationModel()
{
	delete m_instance;
}

ApplicationModel* ApplicationModel::getInstance()
{
	if(!m_instance)
		m_instance = new ApplicationModel();
	return m_instance;
}

void ApplicationModel::whenApplicationStarts(CallbackFunction callback)
{
	cb = callback;
}

void ApplicationModel::run()
{
	cb();
}

int ApplicationModel::sum(int a, int b)
{
	int c = a+b;
	return c;
}


#include "ApplicationPresenter.h"

using namespace Present;

ApplicationPresenter::ApplicationPresenter(View::ApplicationView *view, Model::ApplicationModel *model)
: m_model(model)
, m_view(view)
{}

ApplicationPresenter::~ApplicationPresenter()
{}


void ApplicationPresenter::registerEvents()
{
	m_model->whenApplicationStarts( [this]() { this->applicationStartCallback(); } );
	m_view->onCalculateClicked( [this]() { this->calculateClickedCallback(); });

	//m_model.whenApplicationStarts( std::bind( &ApplicationPresenter::applicationStart Callback(), this ) );
	//m_view.onCalculateClicked( std::bind( &ApplicationPresenter::calculateClickedCallback(), this ) );
}

void ApplicationPresenter::applicationStartCallback()
{
  m_view->build();
  m_view->start();
}

void ApplicationPresenter::calculateClickedCallback()
{ int a = m_view->getSummandA();
  int b = m_view->getSummandB();
  int result = m_model->sum(a, b);
}



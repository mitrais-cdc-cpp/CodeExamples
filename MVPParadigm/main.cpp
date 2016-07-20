#include <iostream>

#include "presenter/ApplicationPresenter.h"
#include "view/ApplicationView.h"
#include "model/ApplicationModel.h"

using namespace std;
using namespace View;
using namespace Model;
using namespace Present;

int main(int argc, char* argv[])
{
  gtk_init(&argc, &argv);

  ApplicationPresenter presenter(ApplicationView::getInstance(), ApplicationModel::getInstance());
  presenter.registerEvents();

  ApplicationModel::getInstance()->run();

  return 0;
}

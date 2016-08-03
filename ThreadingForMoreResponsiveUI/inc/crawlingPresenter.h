/*
 * crawlingPresenter.h
 *
 *  Created on: Jul 18, 2016
 *      Author: developer
 */

#ifndef INC_CRAWLINGPRESENTER_H_
#define INC_CRAWLINGPRESENTER_H_

#include <iostream>

namespace oblongata
{
	namespace crawler
	{
		class crawlingPresenter
		{
			public:
				crawlingPresenter();
				virtual ~crawlingPresenter();

				static void doingSomethingTimeConsuming(void(*funcToInformUI) (const char*));
		};
	}
}



#endif /* INC_CRAWLINGPRESENTER_H_ */

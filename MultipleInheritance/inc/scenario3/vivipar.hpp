#ifndef INC_SCENARIO3_VIVIPAR_HPP_
#define INC_SCENARIO3_VIVIPAR_HPP_

#include <iostream>
#include "animal.hpp"

namespace scenario3
{
	class vivipar: public animal
	{
		public:
			vivipar(std::string name);
			virtual ~vivipar();

			void deliverBaby();
	};
}

#endif /* INC_SCENARIO3_VIVIPAR_HPP_ */

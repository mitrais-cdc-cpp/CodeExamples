#ifndef INC_SCENARIO3B_VIVIPAR_HPP_
#define INC_SCENARIO3B_VIVIPAR_HPP_

#include <iostream>
#include "animal.hpp"

namespace scenario3b
{
	class vivipar: public virtual animal
	{
		public:
			vivipar(std::string name);
			virtual ~vivipar();

			void deliverBaby();
	};
}

#endif /* INC_SCENARIO3B_VIVIPAR_HPP_ */

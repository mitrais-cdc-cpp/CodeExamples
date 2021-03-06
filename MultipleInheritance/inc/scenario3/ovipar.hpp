#ifndef INC_SCENARIO3_OVIPAR_HPP_
#define INC_SCENARIO3_OVIPAR_HPP_

#include <iostream>
#include "animal.hpp"

namespace scenario3
{
	class ovipar: public animal
	{
		public:
			ovipar(std::string name);
			virtual ~ovipar();

			void produceEgg();
	};
}

#endif /* INC_SCENARIO3_OVIPAR_HPP_ */

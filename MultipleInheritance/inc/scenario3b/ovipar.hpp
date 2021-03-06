#ifndef INC_SCENARIO3B_OVIPAR_HPP_
#define INC_SCENARIO3B_OVIPAR_HPP_

#include <iostream>
#include "animal.hpp"

namespace scenario3b
{
	class ovipar: public virtual animal
	{
		public:
			ovipar(std::string name);
			virtual ~ovipar();

			void produceEgg();
	};
}

#endif /* INC_SCENARIO3B_OVIPAR_HPP_ */

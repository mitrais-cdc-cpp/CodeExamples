#ifndef INC_SCENARIO3_OVOVIVIPAR_HPP_
#define INC_SCENARIO3_OVOVIVIPAR_HPP_

#include "ovipar.hpp"
#include "vivipar.hpp"

namespace scenario3
{
	class ovovivipar final: public ovipar, public vivipar
	{
		public:
			ovovivipar(std::string name);
			~ovovivipar();
	};
}

#endif /* INC_SCENARIO3_OVOVIVIPAR_HPP_ */

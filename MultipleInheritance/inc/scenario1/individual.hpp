
#ifndef INC_SCENARIO1_INDIVIDUAL_HPP_
#define INC_SCENARIO1_INDIVIDUAL_HPP_

#include <iostream>

namespace scenario1
{
	class individual
	{
		public:
			individual(std::string id, std::string name);
			virtual ~individual();
			void showId();
			void showName();

		protected:
			std::string id;
			std::string name;
	};
}

#endif /* INC_SCENARIO1_INDIVIDUAL_HPP_ */

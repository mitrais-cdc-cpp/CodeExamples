#ifndef INC_SCENARIO3B_ANIMAL_HPP_
#define INC_SCENARIO3B_ANIMAL_HPP_

#include <iostream>

namespace scenario3b
{
	class animal
	{
		public:
			animal(std::string name);
			virtual ~animal();

			void showName();
			void showType();
			void makeMovement();

		protected:
			std::string name;
			std::string type;
	};
}

#endif /* INC_SCENARIO3B_ANIMAL_HPP_ */

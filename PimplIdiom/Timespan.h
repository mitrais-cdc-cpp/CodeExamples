#ifndef _PIMPL_TIMESPAN_H_
#define _PIMPL_TIMESPAN_H_

#include <ostream>

class Timespan
{
	public:
		/* ctor remain same! */
		Timespan(int ticks_ = 0);
		Timespan(int h_, int m_, int s_);

		/* Rule of 5 */
		~Timespan();
		Timespan(const Timespan& other_);
		Timespan& operator=(const Timespan& other_); 
		
		
		/* publi interface */
		int ticks() const;
		int hours() const;
		int minutes()const;
		int seconds() const;
	
		void setTicks(int t_);
		void setHours(int h_);
		void setMinutes(int m_);
		void setSeconds(int s_);

	private:

		/* ... here it starts
		 * maybe somebody decide, probably not the best implementation with 3 integers.
		*/
		//void normalize();
		//int m_hours;
		//int m_minutes;
		//int m_seconds;
		//int m_ticks;
		
		/*wouldnt it be nice to really change the implementation and seperate it without recompiling?*/
		/*instead of having 3 integers declared, we declare a pointer*/

		struct Impl;
		Impl * pimpl;	// pointer size is always 8Bytes (x64) 
		
				
};

std::ostream& operator<<(std::ostream& os, Timespan const& ts);

#endif // _PIMPL_TIMESPAN_H_
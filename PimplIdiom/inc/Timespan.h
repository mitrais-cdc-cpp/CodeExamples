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
		
		
		/* public interface */
		int ticks() const;
		int hours() const;
		int minutes()const;
		int seconds() const;
	
		void setTicks(int t_);
		void setHours(int h_);
		void setMinutes(int m_);
		void setSeconds(int s_);

	private:

		struct Impl;
		Impl * pimpl;	// pointer size is always 8Bytes (x64)
};

#endif // _PIMPL_TIMESPAN_H_

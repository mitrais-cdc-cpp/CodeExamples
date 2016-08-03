#include "../inc/Timespan.h"

struct Timespan::Impl
{
	Impl(int ticks_) : m_hours(0), m_minutes(0), m_seconds(ticks_)
	{
		normalize();
	}

	Impl(int h_, int m_, int s_): m_hours(h_), m_minutes(m_), m_seconds(s_)
	{
		normalize();
	}

	void normalize();
	int m_hours;
	int m_minutes;
	int m_seconds;
};

Timespan::Timespan(int ticks_)
: pimpl(nullptr)
{
}

Timespan::Timespan(int h_, int m_, int s_): pimpl(new Impl(h_, m_, s_))
{
}

/* Rule of 5 - dtor */
Timespan::~Timespan()
{
	delete pimpl;
}

/* Rule of 5 - Copy ctor */
Timespan::Timespan(const Timespan& other_) : pimpl(new Impl(*other_.pimpl))
{
	
}

/* Rule of 5 - Assignment operator */
/* Copy & Swap implementation to provide strong exception guarantee */
Timespan& Timespan::operator=(const Timespan& other_)
{

#define __COPYSWAP /* __BASIC */

#ifdef __COPYSWAP
	Timespan tmp(other_);		// COPY: create temp and call copy-ctor .. if any exception occurs, "this" will not lost his state!
	std::swap(pimpl, tmp.pimpl); 	// SWAP: take the guts from tmp (here just our pimpl) and swap it to this.pimpl
	return *this;			// no delete, tmp is scope bound, dtor will be called and invoke pimpl dtor! easy peacy
#endif

#ifdef __BASIC
	if(this == &other_)
		return *this;

	delete pimpl;
	pimpl = new Impl(*other_.pimpl);
	return *this;
#endif		
}

int Timespan::ticks() const
{
	return (pimpl->m_hours * 3600) + (pimpl->m_minutes * 60) + pimpl->m_seconds;
}

int Timespan::hours() const
{
	return pimpl->m_hours;
}
int Timespan::minutes() const
{
	return pimpl->m_minutes;
}
int Timespan::seconds() const
{
	return pimpl->m_seconds;	
}

void Timespan::setTicks(int ticks_)
{
	pimpl->m_hours = 0;
	pimpl->m_minutes = 0;
	pimpl->m_seconds = ticks_;
	pimpl->normalize();

}

void Timespan::setHours(int h_)
{
	pimpl->m_hours = h_;
	pimpl->normalize();
}

void Timespan::setMinutes(int m_)
{
	pimpl->m_minutes = m_;
	pimpl->normalize();
}

void Timespan::setSeconds(int s_)
{
	pimpl->m_seconds = s_;
	pimpl->normalize();
}

//void Timespan::normalize()
void Timespan::Impl::normalize()
{
	m_minutes += m_seconds / 60;
	m_hours += m_minutes / 60;
	m_minutes %= 60;
	m_seconds %= 60;
}

/*
 * Subject.h
 *
 *  Created on: Jul 18, 2016
 *      Author: developer
 */

#ifndef SUBJECT_SUBJECT_H_
#define SUBJECT_SUBJECT_H_

#include <map>
#include <vector>
#include <functional>	// std::function
#include <utility>		// std::forward

#include "../event/Event.h"

class Subject
{
public:
	Subject()=default;
	Subject(const Subject &)=delete;
	Subject& operator=(const Subject &)=delete;

	template<typename Observer>
	void registerObserver(const Event& event_, Observer&& observer_)
	{
		m_obsCol[event_].push_back(std::forward<Observer>(observer_));
	}

	void notify(const Event& event_)
	{
		for(const auto & obs : m_obsCol[event_])
			obs();
	}

private:
	std::map<Event, std::vector<std::function<void()>>> m_obsCol;
};


#endif /* SUBJECT_SUBJECT_H_ */

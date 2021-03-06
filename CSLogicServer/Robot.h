#ifndef _ROBOT_H
#define _ROBOT_H

#include "LBase.h"
#include "User.h"
#include "LTabFile.h"
class Robot : public User
{
public:
	Robot(LUser& data, Lint gateId, Lint gateUserId);
	~Robot(void);
	void	Tick();
	void	SetRobotIndex(Lint index);
	Lint	GetRobotIndex();
	virtual Lint GetUserDataId(bool bRandId = false);
	bool	IsRobot();
private:
	Lint	mIndex;
	Lint	m_robotShowId;
};

#endif

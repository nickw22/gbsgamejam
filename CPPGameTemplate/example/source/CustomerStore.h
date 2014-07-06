/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
 
#if !defined(_CUSTOMERSTORE_H_)
#define _CUSTOMERSTORE_H_

#include "Actor.h"

/**
 * @class MyActor
 *
 * @brief MyActor derives from Actor to provide custom functionality.
 *
 */
class CustomerStore: public Actor
{
protected:
	
public:
    CustomerStore();
    void			Init();
    void			Release();
    void            Update();
    void            Render();
	virtual void	Collided(Actor* collidedWith);
};


#endif  // _CUSTOMERSTORE_H_

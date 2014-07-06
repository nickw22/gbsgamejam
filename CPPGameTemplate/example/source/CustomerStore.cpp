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

#include "Audio.h"
#include "CustomerStore.h"
#include "MyWorld.h"

CustomerStore::CustomerStore() 
	: Actor(EActorType_CustomerStore)
{
}

void CustomerStore::Init()
{
    Actor::Init();
}

void CustomerStore::Release()
{
    Actor::Release();
}
const float k_fSpeed = 1.0f;
void CustomerStore::Update()
{
    // Add actor logic here
    Actor::Update();
}

void CustomerStore::Render()
{
    Actor::Render();
}

int score = 0;

void CustomerStore::Collided(Actor* collidedWith)
{
	if (collidedWith->m_Type == Actor::EActorType_MyActor)
	{
		((MyWorld*)Parent)->iScore++;
		collidedWith->setVisible(false);
	}
}
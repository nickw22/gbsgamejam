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
#include "MyActor.h"
#include "MyWorld.h"

MyActor::MyActor() 
	: Actor(EActorType_MyActor)
	, CubeSpinSpeed(0)
	, bIsSelected(false)
	, bIsMoving(false)
{
}

void MyActor::Init()
{
    Actor::Init();
	v3TargetPosition = CIwFVec3(0.f, 0.f, 0.f);
}

void MyActor::Release()
{
    Actor::Release();
}
const float k_fSpeed = 1.0f;
void MyActor::Update()
{
    // Add actor logic here
    Actor::Update();

	bool bTargetPositionValid = !(v3TargetPosition == CIwFVec3::g_Zero);
	bool bTargetInRange = (abs(getPosition().x - v3TargetPosition.x) < 1.0f && abs(getPosition().z - v3TargetPosition.z) < 1.0f );
	bIsMoving = bTargetPositionValid && !bTargetInRange;

	if ( bIsMoving)
	{
		CIwFVec3 v3MoveDirection = (v3TargetPosition - getPosition()).GetNormalised();
		CIwFVec3 v3MoveAmount = v3MoveDirection * k_fSpeed;
		v3MoveAmount.y = 0;
		setPosition(getPosition().x + v3MoveAmount.x, getPosition().y + v3MoveAmount.y, getPosition().z + v3MoveAmount.z);
		TransformDirty = true;
	}
}

void MyActor::Render()
{
    // TODO: Add any actor specific rendering / state changes here
    if (Model != 0 && Visible)
    {
        IwGxSetModelMatrix(&Transform);
        IwGxLightingOn();
		if ( bIsSelected)
		{
			IwGxSetColDiffuse(255, 0, 0, 255);
			IwGxSetColAmbient(255, 0, 0, 255);
			IwGxDebugPrimSphere( CIwFSphere( getPosition(), 5));
		}
		else
		{
			IwGxSetColDiffuse(128, 128, 128, 128);
			IwGxSetColAmbient(128, 128, 128, 128);
		}
        Model->Render();
        IwGxLightingOff();
    }
}

int MyActor::getSymbol() const
{
    return ((MyWorld*)Parent)->getGameGridCell(GridX, GridY);
}

void MyActor::setGridPosition(int x, int y)
{
    GridX = x;
    GridY = y;
}

void MyActor::Event_BeginTouch()
{
}

void MyActor::Event_EndTouch()
{
    if (CubeSpinSpeed == 0 && ((MyWorld*)Parent)->getGameState() == eGameState_Running)
    {
        TransformDirty = true;
        g_pAudio->PlaySound("turn.wav");
		((MyWorld*)Parent)->UnselectAllActors();
		bIsSelected = true;
    }
}

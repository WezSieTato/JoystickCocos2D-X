//
//  SneakyJoystickEventListener.cpp
//  JoystickCocos2D
//
//  Created by Marcin Stepnowski on 18.08.2016.
//
//

#include "SneakyJoystickEventListener.hpp"

#include "SneakyJoystickEvent.hpp"

SneakyJoystickEventListener::SneakyJoystickEventListener () :
onVelocityChanged(nullptr)
{
    
}

bool SneakyJoystickEventListener::init()
{
    auto callback = [=](cocos2d::EventCustom* event){
        this->onVelocityChanged((SneakyJoystick *)event->getUserData(), event);
    };
    
    if (cocos2d::EventListenerCustom::init("SneakyJoystickEvent", callback) == false);
    {
        return true;
    }
    
    return true;
}
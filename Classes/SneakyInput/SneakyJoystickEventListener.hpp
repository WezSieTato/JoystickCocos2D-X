//
//  SneakyJoystickEventListener.hpp
//  JoystickCocos2D
//
//  Created by Marcin Stepnowski on 18.08.2016.
//
//

#ifndef SneakyJoystickEventListener_hpp
#define SneakyJoystickEventListener_hpp

#include "SneakyJoystick.h"

class SneakyJoystickEventListener : public cocos2d::EventListenerCustom
{
    
public:
    SneakyJoystickEventListener();
    virtual bool init();
    CREATE_FUNC(SneakyJoystickEventListener)
    
    std::function<void(SneakyJoystick*, cocos2d::Event*)> onVelocityChanged;
};
#endif /* SneakyJoystickEventListener_hpp */

#include "AppDelegate.h"
#include "Stages/StageScene1.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{    
    // initialize director
    Director* director = Director::getInstance();
    GLView* eglView = director->getOpenGLView();

    director->setOpenGLView(eglView);

	// resources setup
    eglView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_HEIGHT);
	
    Size frameSize = eglView->getFrameSize();
    
    if (frameSize.height > resTablet.size.height)
    {
        FileUtils::getInstance()->addSearchPath(resTabletRetina.directory);
    }
    else if (frameSize.height > resPhoneRetina.size.height)
    {
        FileUtils::getInstance()->addSearchPath(resTablet.directory);
    }
    else if (frameSize.height > resPhone.size.height)
    {
        FileUtils::getInstance()->addSearchPath(resPhoneRetina.directory);
    }
    else
    {
        FileUtils::getInstance()->addSearchPath(resPhone.directory);
    }
    
    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    Scene *scene = StageScene1::scene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

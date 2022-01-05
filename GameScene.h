#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScreen : public cocos2d::Layer
{
public:
    //since there is no id in cpp, it better to return the class instance pointer
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScreen);

    void setPhysicsWorld(cocos2d::PhysicsWorld* world) { mWorld = world; mWorld->setGravity(cocos2d::Vect(0, 0)); } // used for collision detection 
    bool onContactBegin(cocos2d::PhysicsContact& contact); //called when a collision has taken place.

    cocos2d::PhysicsWorld* mWorld;
};

#endif // __HELLOWORLD_SCENE_H__

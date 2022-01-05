#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Definitions.h"

USING_NS_CC;

Scene* GameScreen::createScene()
{
    // 'scene is an autorelease object
    auto scene = Scene::createWithPhysics();

    // 'Layer is an autorelease object
    auto layer = GameScreen::create();
    layer->setPhysicsWorld(scene->getPhysicsWorld());

    //add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);

    this->addChild(edgeNode);

    {
        auto niveau2 = Sprite::create("niveau2.png");
        niveau2->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        auto spriteBody = PhysicsBody::createBox(niveau1->getContentSize(), PhysicsMaterial(0, 1, 0));

        spriteBody->setDynamic(false);
        niveau1->setPhysicsBody(spriteBody);

        this->addChild(niveau2);
    }
    {
        auto sprite = Sprite::create("ball.png");
        sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 200));

        auto spriteBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 1, 0));

        sprite->setPhysicsBody(spriteBody);

        this->addChild(sprite);

    }
    // MoveBy - lets move the sprite by 200 on the x axis over 2 seconds
    auto moveBy21 = MoveBy::create(2, Vec2(200, sprite->getPositionY()));

    // MoveBy - lets move the sprite by 370 on the y axis over 2 seconds
    auto moveBy22 = MoveBy::create(2, Vec2(sprite->getPositionX(), 270));

    // MoveBy - lets move the sprite by 200 on the x axis over 2 seconds to the left
    auto moveBy23 = MoveBy::create(2, Vec2(sprite->getPositionX()-200, sprite->getPositionY()));

    // MoveBy - lets move the sprite by 200 on the x=y axis over 2 seconds to the bottom
    auto moveBy24 = MoveBy::create(2, Vec2(sprite->getPositionX(), sprite->getPositionY()-200));

    // MoveBy - lets move the sprite by 370 on the x axis over 2 seconds
    auto moveBy25 = MoveBy::create(2, Vec2(370, sprite->getPositionY()));


    // Delay - create a small delay
    auto delay = DelayTime::create(1);

    auto seq = Sequence::create(moveBy21, delay, moveBy22, delay, moveBy23, delay, moveBy24, delay, moveBy25, nullptr);

    sprite->runAction(seq);

    return true;
}
void GameScene::GoToGameScene(cocos2d::Ref* sender)
{
    auto scene = GameScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

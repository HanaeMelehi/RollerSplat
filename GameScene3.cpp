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
        auto niveau3 = Sprite::create("niveau3.png");
        niveau3->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        auto spriteBody = PhysicsBody::createBox(niveau1->getContentSize(), PhysicsMaterial(0, 1, 0));

        spriteBody->setDynamic(false);
        niveau1->setPhysicsBody(spriteBody);

        this->addChild(niveau3);
    }
    {
        auto sprite = Sprite::create("ball.png");
        sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 200));

        auto spriteBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0, 1, 0));

        sprite->setPhysicsBody(spriteBody);

        this->addChild(sprite);

    }
   
    // MoveBy - lets move the sprite by 380 on the y axis over 2 seconds
    auto moveBy31 = MoveBy::create(2, Vec2(sprite->getPositionX(), 280));

    // MoveBy - lets move the sprite by 200 on the x axis over 2 seconds to the left
    auto moveBy32 = MoveBy::create(2, Vec2(sprite->200, sprite->getPositionY()));

    // MoveBy - lets move the sprite by 200 on the x=y axis over 2 seconds to the bottom
    auto moveBy33 = MoveBy::create(2, Vec2(sprite->getPositionX(), sprite->getPositionY() - 380));

    // MoveBy - lets move the sprite by 150 on the x axis over 2 seconds
    auto moveBy34 = MoveBy::create(2, Vec2(150, sprite->getPositionY()));


    // Delay - create a small delay
    auto delay = DelayTime::create(1);

    auto seq = Sequence::create(moveBy31, delay, moveBy32, delay, moveBy33, delay, moveBy34, nullptr);

    sprite->runAction(seq);

    return true;
}
void GameScene3::GoToMainMenuScene(cocos2d::Ref* sender)
{
    auto scene = MainMenuScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

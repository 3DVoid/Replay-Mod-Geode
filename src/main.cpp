/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

/**
 * `$modify` lets you extend and modify GD's classes.
 * To hook a function in Geode, simply $modify the class
 * and write a new function definition with the signature of
 * the function you want to hook.
 *
 * Here we use the overloaded `$modify` macro to set our own class name,
 * so that we can use it for button callbacks.
 *
 * Notice the header being included, you *must* include the header for
 * the class you are modifying, or you will get a compile error.
 *
 * Another way you could do this is like this:
 *
 * struct MyMenuLayer : Modify<MyMenuLayer, MenuLayer> {};
 */

#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>

struct RMPlayLayer : Modify<RMPlayLayer, PauseLayer> {
	void customSetup() {
		PauseLayer::customSetup();

		geode::log::warn("RMPlayLayer Works");

		auto spr = CCSprite::createWithSpriteFrameName("Static.png"_spr);
		auto rplybtn = CCMenuItemSpriteExtra::create(CircleButtonSprite::create(spr, CircleBaseColor::Green, CircleBaseSize::SmallAlt), this, menu_selector(RMPlayLayer::onRplyBtn));

		auto menu = this->getChildByID("left-button-menu");
		menu->addChild(rplybtn);

	};

	void onRplyBtn(CCObject* sender) {
		FLAlertLayer::create("It", "Finally", "Works")->show();
	}
};
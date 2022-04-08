#pragma once
#include <memory>
#include <functional>
#include <stdlib.h>

#include "Bomb.h"
#include "Plane.h"
#include "LevelGUI.h"
#include "Ground.h"
#include "SBomber.h"

class SBomber;

class CollisionDetectorImpl
{
public:

	virtual ~CollisionDetectorImpl() = default;
	virtual void CheckPlaneAndLevelGUI(SBomber* sBomber_) = 0;
	//virtual void CheckBombsAndGround(std::function < std::vector<Bomb*>()> FindAllBombs, std::function < Ground* ()> FindGround, std::function <void(DynamicObject* pBomb)> DeleteDynamicObj) = 0;
    virtual void CheckBombsAndGround(SBomber* sBomber_) = 0;
	virtual void __fastcall CheckDestoyableObjects(Bomb* pBomb, SBomber* sBomber_) = 0;
private:

};

class XCollisionDetector : public CollisionDetectorImpl {
public:
    void CheckPlaneAndLevelGUI(SBomber* sBomber_) override;
    void CheckBombsAndGround(SBomber* sBomber_) override;
    void __fastcall CheckDestoyableObjects(Bomb* pBomb, SBomber* sBomber_) override;
};

class WinCollisionDetector : public CollisionDetectorImpl {
public:
    void CheckPlaneAndLevelGUI(SBomber* sBomber_) override;
    void CheckBombsAndGround(SBomber* sBomber_) override;
    void __fastcall CheckDestoyableObjects(Bomb* pBomb, SBomber* sBomber_) override;
};

class CollisionDetector {
public:
    CollisionDetector(std::unique_ptr<CollisionDetectorImpl> impl) : impl_{ std::move(impl) } {}
    ~CollisionDetector() {};

    void CheckPlaneAndLevelGUI(SBomber* sBomber_);

    void CheckBombsAndGround(SBomber* sBomber_);

    void __fastcall CheckDestoyableObjects(Bomb* pBomb, SBomber* sBomber_);

protected:
    std::unique_ptr<CollisionDetectorImpl> impl_;
};

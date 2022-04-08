#pragma once

#include <vector>
#include <memory>
#include <stdlib.h>

#include "CollisionDetector.h"
#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "MyTools.h"

class SBomber
{
    friend class XCollisionDetector; 
    friend class CollisionDetectorImpl;
    friend class WinCollisionDetector;
public:

    SBomber(std::shared_ptr<MyTools::ILogger> logger, std::unique_ptr<CollisionDetectorImpl> collDetector);
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    
protected:
    
private:

    

    //void CheckPlaneAndLevelGUI();
    //void CheckBombsAndGround();
    //void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    std::vector<Bomb*> FindAllBombs() const;
    Ground* FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
    std::shared_ptr<MyTools::ILogger> logger_;
    std::unique_ptr<CollisionDetectorImpl> collDetector_;


};
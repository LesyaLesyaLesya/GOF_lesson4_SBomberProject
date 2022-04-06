
#include "CollisionDetector.h"

//void XCollisionDetector::CheckPlaneAndLevelGUI(std::function<Plane*()> FindPlane, std::function<LevelGUI* ()> FindLevelGUI, bool& exitFlag)
void XCollisionDetector::CheckPlaneAndLevelGUI(SBomber* sBomber_)
{
    if (sBomber_->FindPlane()->GetX() > sBomber_->FindLevelGUI()->GetFinishX())
    {
        sBomber_->exitFlag = true;
    }
}
void XCollisionDetector::CheckBombsAndGround(SBomber* sBomber_)
{
    std::vector<Bomb*> vecBombs = sBomber_->FindAllBombs();
    Ground* pGround = sBomber_->FindGround();
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            CheckDestoyableObjects(vecBombs[i], sBomber_);
            sBomber_->DeleteDynamicObj(vecBombs[i]);
        }
    }
}
void __fastcall XCollisionDetector::CheckDestoyableObjects(Bomb* pBomb, SBomber* sBomber_)
{
    std::vector<DestroyableGroundObject*> vecDestoyableObjects = sBomber_->FindDestoyableGroundObjects();
    const double size = pBomb->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
    {
        const double x1 = pBomb->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecDestoyableObjects[i]->isInside(x1, x2))
        {
            sBomber_->score += vecDestoyableObjects[i]->GetScore();
            sBomber_->DeleteStaticObj(vecDestoyableObjects[i]);
        }
    }
}


void WinCollisionDetector::CheckPlaneAndLevelGUI(SBomber* sBomber_)
{
    if (sBomber_->FindPlane()->GetX() > sBomber_->FindLevelGUI()->GetFinishX())
    {
        sBomber_->exitFlag = true;
    }
}
void WinCollisionDetector::CheckBombsAndGround(SBomber* sBomber_)
{
    std::vector<Bomb*> vecBombs = sBomber_->FindAllBombs();
    Ground* pGround = sBomber_->FindGround();
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            CheckDestoyableObjects(vecBombs[i], sBomber_);
            sBomber_->DeleteDynamicObj(vecBombs[i]);
        }
    }
}
void __fastcall WinCollisionDetector::CheckDestoyableObjects(Bomb* pBomb, SBomber* sBomber_)
{
    std::vector<DestroyableGroundObject*> vecDestoyableObjects = sBomber_->FindDestoyableGroundObjects();
    const double size = pBomb->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
    {
        const double x1 = pBomb->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecDestoyableObjects[i]->isInside(x1, x2))
        {
            sBomber_->score += vecDestoyableObjects[i]->GetScore();
            sBomber_->DeleteStaticObj(vecDestoyableObjects[i]);
        }
    }
}

void CollisionDetector::CheckPlaneAndLevelGUI(SBomber* sBomber_)
{   
        if (impl_) {
            impl_->CheckPlaneAndLevelGUI(sBomber_);
        }
}
void CollisionDetector::CheckBombsAndGround(SBomber* sBomber_) {
    if (impl_) {
        impl_->CheckBombsAndGround(sBomber_);
    }
}

void __fastcall CollisionDetector::CheckDestoyableObjects(Bomb* pBomb, SBomber* sBomber_)
{
    if (impl_) {
        impl_->CheckDestoyableObjects(pBomb, sBomber_);
    }
}





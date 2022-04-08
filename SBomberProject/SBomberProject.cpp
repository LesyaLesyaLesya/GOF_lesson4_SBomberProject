
#include <conio.h>
#include <stdlib.h>
#include <memory>

#include "SBomber.h"
#include "MyTools.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    auto logger = std::make_shared<MyTools::ProxyLogger>(MyTools::FileLoggerSingleton::getInstance());
    logger->OpenLogFile("log.txt");
   
    auto collDetector = std::make_unique<WinCollisionDetector>();
   // std::unique_ptr<CollisionDetectorImpl> collDetector (new CollisionDetector(d));

    SBomber game{logger, std::move(collDetector)};

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    logger->CloseLogFile();

    return 0;
}

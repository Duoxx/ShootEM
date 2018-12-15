#ifndef GAMEDATA_H
#define GAMEDATA_H
#include <QRect>
#include <QVector>
#include <tuple>

enum BlockTypes
{
	solid,
	null,
	ladder,
    laddertop,
    spike
};

enum CDIR {X, Y};

typedef std::tuple<QRect, QPointF, BlockTypes> MapProps;

namespace Game {
	template <typename T> int getSign(T val) {
		return (T(0) < val) - (val < T(0));
	}
	extern float gravity;
	extern float scaleFactor;
	extern float framerate;

	const QRect Hud0(240, 8, 8, 8);
	const QRect Hud1(224, 8, 8, 8);
	const QRect Hud2(232, 8, 8, 8);
	const QRect Hud3(232, 0, 8, 8);
	const QRect Hud4(224, 0, 8, 8);

	namespace Tiles {
		const QRect air(0, 0, 16, 16);
		namespace Ladders {
			const QRect ladderBlue(208, 0, 16, 16);
		}
        namespace Spikes {
            const QRect spikeRed(416, 0, 16, 16);
        }
		namespace Grass {
			const QRect grassNC(32, 0, 16, 16);
            const QRect grassAC(112, 16, 16, 16);
			const QRect grassRC(48, 0, 16, 16);
			const QRect grassRLC(56, 0, 16, 16);
			const QRect grassLC(80, 0, 16, 16);
            namespace Angle {
                const QRect grassLT(96, 0, 16, 16);
                const QRect grassLD(96, 32, 16, 16);
                const QRect grassRT(128, 0, 16, 16);
                const QRect grassRD(128, 32, 16, 16);
            }
            namespace Corners {
                const QRect grassL(96, 16, 16, 16);
                const QRect grassT(112, 0, 16, 16);
                const QRect grassR(128, 16, 16, 16);
                const QRect grassD(112, 32, 16, 16);
            }
		}
		namespace Bricks {
			const QRect brickBlue(192, 0, 16, 16);
		}
		namespace Backgrounds {
			const QRect bgMountain(448, 0, 704-448, 239);
			const QRect bgBrick(704, 0, 32, 32);
		}
	}
    namespace Weapons
    {
        namespace Melee
        {
			const QRect startSword(176, 16, 16, 16);
        }
		namespace Magic {
			const QRect leafShieldLeaf(176, 0, 8, 8);
		}
    }
	namespace Entities {
		namespace Player {
			namespace Blue {
				const QRect playerStand1(0, 32, 16, 16);
				const QRect playerStand2(0, 32+16, 16, 16);
				const QRect playerWalk(16, 32, 16, 16);
				const QRect playerAttack(16, 80, 16, 16);
				const QRect playerJump(16, 48, 16, 16);
				const QRect playerClimb(0, 64, 16, 16);
				const QRect playerClimb2(0, 64+16, 16, 16);
				const QRect playerHit(16, 64, 16, 16);
			}
			namespace Red {
				const QRect playerStand1(0, 96, 16, 16);
				const QRect playerStand2(16, 96, 16, 16);
				const QRect playerAttack(0, 48, 16, 16);
				const QRect playerJump(16, 48, 16, 16);
				const QRect playerClimb(0, 64, 16, 16);
			}
		}
	}

	//extern void init();

	const QVector<MapProps> ids
	{
        MapProps(Game::Tiles::air, QPointF(0, 0), BlockTypes::null),
        MapProps(Game::Tiles::Grass::grassAC, QPointF(0, 0), BlockTypes::solid),
        MapProps(Game::Tiles::Grass::Angle::grassLT, QPointF(0, 0), BlockTypes::solid),
        MapProps(Game::Tiles::Grass::Angle::grassRT, QPointF(0, 0), BlockTypes::solid),
        MapProps(Game::Tiles::Grass::Angle::grassRD, QPointF(0, 0), BlockTypes::solid),
        MapProps(Game::Tiles::Grass::Angle::grassLD, QPointF(0, 0), BlockTypes::solid),
        MapProps(Game::Tiles::Grass::Corners::grassL, QPointF(0, 0), BlockTypes::solid),
        MapProps(Game::Tiles::Grass::Corners::grassR, QPointF(0, 0), BlockTypes::solid),
        MapProps(Game::Tiles::Grass::Corners::grassD, QPointF(0, 0), BlockTypes::solid),
        MapProps(Game::Tiles::Grass::Corners::grassT, QPointF(0, 0), BlockTypes::solid),
        MapProps(Game::Tiles::Ladders::ladderBlue, QPointF(0, 0), BlockTypes::ladder),
		MapProps(Game::Tiles::Spikes::spikeRed, QPointF(0, 0), BlockTypes::spike),
		MapProps(Game::Tiles::Grass::grassNC, QPointF(0, 0), BlockTypes::solid)
	}

	//extern QVector<MapObject> ids
	/*{
		Game::Tiles::Grass::grassAC,
		Game::Tiles::Grass::Angle::grassLT,
		Game::Tiles::Grass::Angle::grassRT,
		Game::Tiles::Grass::Angle::grassRD,
		Game::Tiles::Grass::Angle::grassLD,
		Game::Tiles::Grass::Corners::grassL,
		Game::Tiles::Grass::Corners::grassR,
		Game::Tiles::Grass::Corners::grassD,
		Game::Tiles::Grass::Corners::grassT
	}*/;
}



#endif // GAMEDATA_H
#include "CubeDialog.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

CubeDialog::CubeDialog()
{

}

CubeDialog::~CubeDialog()
{

}

void CubeDialog::UpdateCubeDialog(const CubeFace& _Face, const std::string_view& _Dialog)
{
	On();
	SetMugPic(CubeMugshot.find(_Face)->second);
	SetUpdateText(_Dialog);
}

void CubeDialog::Start()
{
	Dialog::Start();
	SetCubeMugShot();
	SetMugPic(CubeMugshot.find(CubeFace::Nomal)->second);
	SetMugLoc(MugShotLR::Right);
	SetPos(ActorPos);
}

void CubeDialog::SetCubeMugShot()
{
	CubeMugshot.insert(std::make_pair(CubeFace::Nomal, "Mug_Cube_Nomal.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Anger, "Mug_Cube_Anger.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::BigWorry, "Mug_Cube_BigWorry.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Embarrassment, "Mug_Cube_Embarrassment.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Excited, "Mug_Cube_Excited.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Happy, "Mug_Cube_Happy.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Hmm, "Mug_Cube_Hmm.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Love, "Mug_Cube_Love.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::OMG, "Mug_Cube_OMG.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Proud, "Mug_Cube_Proud.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Serious, "Mug_Cube_Serious.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::SuperExcited, "Mug_Cube_SuperExcited.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Surprise, "Mug_Cube_Surprise.bmp"));
	CubeMugshot.insert(std::make_pair(CubeFace::Worry, "Mug_Cube_Worry.bmp"));
}

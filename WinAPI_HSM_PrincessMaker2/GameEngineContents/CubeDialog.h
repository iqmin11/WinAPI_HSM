#pragma once
#include  <map>
#include "Dialog.h"

enum class CubeFace
{
	Nomal,
	Happy,
	Proud,
	BigWorry,
	Excited,
	Embarrassment,
	Anger,
	Worry,
	Surprise,
	Hmm,
	Serious,
	SuperExcited,
	OMG,
	Love
};

class GameEngineRender;
class CubeDialog : public Dialog
{
public:
	// construtor destructor
	CubeDialog();
	~CubeDialog();

	// delete Function
	CubeDialog(const CubeDialog& _Other) = delete;
	CubeDialog(CubeDialog&& _Other) noexcept = delete;
	CubeDialog& operator=(const CubeDialog& _Other) = delete;
	CubeDialog& operator=(CubeDialog&& _Other) noexcept = delete;

	void UpdateCubeDialog(const CubeFace& _Face, const std::string_view& _Dialog);

protected:
	void Start() override;

private:
	//GlobalButton* NextButton = nullptr;
	std::map<CubeFace, std::string> CubeMugshot = std::map<CubeFace, std::string>();
	float4 ActorPos = {250 , 500};

	void SetCubeMugShot();
};


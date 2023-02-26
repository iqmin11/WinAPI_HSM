#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"

class IconButton;
class ClassSelectWindow : public GameEngineActor
{
public:
	// construtor destructor
	ClassSelectWindow();
	~ClassSelectWindow();

	// delete Function
	ClassSelectWindow(const ClassSelectWindow& _Other) = delete;
	ClassSelectWindow(ClassSelectWindow&& _Other) noexcept = delete;
	ClassSelectWindow& operator=(const ClassSelectWindow& _Other) = delete;
	ClassSelectWindow& operator=(ClassSelectWindow&& _Other) noexcept = delete;

	IconButton* GetPaintingButton() const
	{
		return Painting;
	}

	void On() override;
	void Off() override;

protected:

	void Start() override;

private:
	IconButton* Painting = nullptr;
	float4 Button1Pos = { 540 , 400 };
	IconButton* Dance = nullptr;
	float4 Button2Pos = { 710 , 400 };
	IconButton* Magic = nullptr;
	float4 Button3Pos = { 540 , 340 };
	IconButton* Protocol = nullptr;
	float4 Button4Pos = { 710 , 340 };
	IconButton* Fencing = nullptr;
	float4 Button5Pos = { 540 , 280 };
	IconButton* Fighting = nullptr;
	float4 Button6Pos = { 710 , 280 };
	IconButton* Theology = nullptr;
	float4 Button7Pos = { 540 , 220 };
	IconButton* Strategy = nullptr;
	float4 Button8Pos = { 710 , 220 };
	IconButton* Science = nullptr;
	float4 Button9Pos = { 540 , 160 };
	IconButton* Poetry = nullptr;
	float4 Button10Pos = { 710 , 160 };
};


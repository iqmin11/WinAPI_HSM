#include "BasicInfo.h"

#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

BasicInfo::BasicInfo()
{

}

BasicInfo::~BasicInfo()
{

}

void BasicInfo::Start()
{
	SetPos({700, 109});
	SetAge(10);
	SetStar(Zodiac::Leo); // 이건 아이콘 액터를 만들고 렌더하자
	SetGold(1000);
	SetHeight(130.0f);
	SetWeight(27.0f);
	SetBust(20.0f);
	SetWaist(20.0f);
	SetHip(20.0f);
	
	BasicInfoFrame = CreateRender("BasicInfo.bmp",PM2RenderOrder::Menu0); // 베이직 인포 프레임 렌더

	AgeRender.resize(GameEngineMath::GetLenth(Age)); // 나이 렌더
	for (size_t i = 0; i < AgeRender.size(); i++) 
	{
		AgeRender[i] = CreateRender("Num_Age.bmp", PM2RenderOrder::Menu0_Display);
		AgeRender[i]->SetScale({20 , 20});
		AgeRender[i]->SetFrame(GameEngineMath::GetDigits(Age)[i]);
		AgeRender[i]->SetPosition(float4{-70, -20} + (float4::Left * AgeRender[i]->GetScale().half()) * (static_cast<float>(AgeRender.size()) - 1.0f) + (float4::Right * AgeRender[i]->GetScale()) * static_cast<float>(i));
	}

	GoldRender.resize(GameEngineMath::GetLenth(Gold)); // 돈 렌더
	for (size_t i = 0; i < GoldRender.size(); i++)
	{
		GoldRender[i] = CreateRender("Num.bmp", PM2RenderOrder::Menu0_Display);
		GoldRender[i]->SetScale({ 10,19 });
		GoldRender[i]->SetFrame(GameEngineMath::GetDigits(Gold)[i]);
		GoldRender[i]->SetPosition(float4{ 65, -12 } + (float4::Left * GoldRender[i]->GetScale()) * static_cast<float>(GoldRender.size() - 1.0f) + (float4::Right * GoldRender[i]->GetScale()) * static_cast<float>(i));
	}
	
	int iHeight = static_cast<int>(Height);
	HeightRender.resize(GameEngineMath::GetLenth(iHeight)); // 
	for (size_t i = 0; i < HeightRender.size(); i++)
	{
		HeightRender[i] = CreateRender("Num.bmp", PM2RenderOrder::Menu0_Display);
		HeightRender[i]->SetScale({ 10 , 20 });
		HeightRender[i]->SetFrame(GameEngineMath::GetDigits(iHeight)[i]);
		HeightRender[i]->SetPosition(float4{ -75, 89 } + (float4::Left * HeightRender[i]->GetScale().half()) * (static_cast<float>(HeightRender.size()) - 1.0f) + (float4::Right * HeightRender[i]->GetScale()) * static_cast<float>(i));
	}

	int iWeight = static_cast<int>(Weight);
	WeightRender.resize(GameEngineMath::GetLenth(iWeight)); // 
	for (size_t i = 0; i < WeightRender.size(); i++)
	{
		WeightRender[i] = CreateRender("Num.bmp", PM2RenderOrder::Menu0_Display);
		WeightRender[i]->SetScale({ 10 , 20 });
		WeightRender[i]->SetFrame(GameEngineMath::GetDigits(iWeight)[i]);
		WeightRender[i]->SetPosition(float4{ -35, 89 } + (float4::Left * WeightRender[i]->GetScale().half()) * (static_cast<float>(WeightRender.size()) - 1.0f) + (float4::Right * WeightRender[i]->GetScale()) * static_cast<float>(i));
	}

	int iBust = static_cast<int>(Bust);
	BustRender.resize(GameEngineMath::GetLenth(iBust)); // 
	for (size_t i = 0; i < BustRender.size(); i++)
	{
		BustRender[i] = CreateRender("Num.bmp", PM2RenderOrder::Menu0_Display);
		BustRender[i]->SetScale({ 10 , 20 });
		BustRender[i]->SetFrame(GameEngineMath::GetDigits(iBust)[i]);
		BustRender[i]->SetPosition(float4{ -5, 89 } + (float4::Left * BustRender[i]->GetScale().half()) * (static_cast<float>(BustRender.size()) - 1.0f) + (float4::Right * BustRender[i]->GetScale()) * static_cast<float>(i));
	}

	int iWaist = static_cast<int>(Waist);
	WaistRender.resize(GameEngineMath::GetLenth(iWaist)); // 
	for (size_t i = 0; i < WaistRender.size(); i++)
	{
		WaistRender[i] = CreateRender("Num.bmp", PM2RenderOrder::Menu0_Display);
		WaistRender[i]->SetScale({ 10 , 20 });
		WaistRender[i]->SetFrame(GameEngineMath::GetDigits(iWaist)[i]);
		WaistRender[i]->SetPosition(float4{ 37, 89 } + (float4::Left * WaistRender[i]->GetScale().half()) * (static_cast<float>(WaistRender.size()) - 1.0f) + (float4::Right * WaistRender[i]->GetScale()) * static_cast<float>(i));
	}

	int iHip = static_cast<int>(Hip);
	HipRender.resize(GameEngineMath::GetLenth(iHip)); // 
	for (size_t i = 0; i < HipRender.size(); i++)
	{
		HipRender[i] = CreateRender("Num.bmp", PM2RenderOrder::Menu0_Display);
		HipRender[i]->SetScale({ 10 , 20 });
		HipRender[i]->SetFrame(GameEngineMath::GetDigits(iHip)[i]);
		HipRender[i]->SetPosition(float4{ 79, 89 } + (float4::Left * HipRender[i]->GetScale().half()) * (static_cast<float>(HipRender.size()) - 1.0f) + (float4::Right * HipRender[i]->GetScale()) * static_cast<float>(i));
	}
	//StarRender = CreateRender("", PM2RenderOrder::Menu0_Display);
	

}

void BasicInfo::Update(float _DeltaTime)
{
}

void BasicInfo::Render(float _Time)
{
}

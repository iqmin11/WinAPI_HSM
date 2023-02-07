#include "NumberRenderObject.h"
#include "GameEngineResources.h"
#include "GameEngineActor.h"

NumberRenderObject::NumberRenderObject()
{

}

NumberRenderObject::~NumberRenderObject()
{

}

void NumberRenderObject::SetImage(const std::string_view& _ImageName, float4 _Scale, int _Order)
{
	GameEngineImage* FindNumberImage = GameEngineResources::GetInst().ImageFind(_ImageName);
	
	if (FindNumberImage->GetImageCuttingCount() != 10)
	{
		MsgAssert("���� �̹����� 10���� �߷��־�� �մϴ�")
	}
	
	if (0 >= NumberScale.x || 0 >= NumberScale.y)
	{
		MsgAssert("ũ�Ⱑ 0���� ���ڸ� ����� �� �����ϴ�.");
	}

	ImageName = _ImageName;
	NumberScale = _Scale;
	Order = _Order;
}

void NumberRenderObject::SetValue(int _Value)
{
	Value = _Value;

	std::vector<unsigned int> Numbers = GameEngineMath::GetDigits(Value);
	GameEngineActor* Actor = GetOwner<GameEngineActor>();

	if (nullptr == Actor)
	{
		MsgAssert("���͸��� NumberRenderObject�� �θ� �� �� �ֽ��ϴ�.");
	}

	if (NumberRenders.size() != Numbers.size() && NumberRenders.size() < Numbers.size())
	{
		for (size_t i = 0; i < Numbers.size() - NumberRenders.size(); i++)
		{
			NumberRenders.push_back(Actor->CreateRender(Order));
		}
	}

	float4 RenderPos;

	for (size_t i = 0; i < NumberRenders.size(); i++)
	{
		GameEngineRender* Render = NumberRenders[i];

		if (nullptr == Render)
		{
			MsgAssert("���ڷ������� nullptr�Դϴ�")
		}

		Render->SetPosition(Pos + RenderPos);
		Render->SetScale(NumberScale);
		Render->SetImage(ImageName);
		Render->SetFrame(Numbers[i]);

		RenderPos.x += NumberScale.x;
	}
}

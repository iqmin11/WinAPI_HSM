#pragma once
#include "Dialog.h"
#include "ContentsEnums.h"
#include <map>

enum class ScheduleSituation
{
	Null = -1,
	ScheduleFirstStart,
	ScheduleStart,
	ScheduleEnd,
	ScheduleEnd_NoMoney,
	ScheduleEnd_Bonus,
	End,
};

struct ScheduleScript
{
	ScheduleScript() {}
	ScheduleScript(ScheduleLabel _Char, ScheduleSituation _Situ)
		: Character(_Char), Situation(_Situ) {}
	
	ScheduleLabel Character = ScheduleLabel::Null;
	ScheduleSituation Situation = ScheduleSituation::Null;
};

class ScheduleDialog : public Dialog
{
public:
	// construtor destructor
	ScheduleDialog();
	~ScheduleDialog();

	// delete Function
	ScheduleDialog(const ScheduleDialog& _Other) = delete;
	ScheduleDialog(ScheduleDialog&& _Other) noexcept = delete;
	ScheduleDialog& operator=(const ScheduleDialog& _Other) = delete;
	ScheduleDialog& operator=(ScheduleDialog&& _Other) noexcept = delete;

	void UpdateScheduleDialog(const ScheduleLabel& _Mug, const std::string_view& _Dialog);
	void UpdateScheduleDialog(ScheduleLabel _Char, ScheduleSituation _Situ);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = {253, 400}; 
	std::map<ScheduleLabel, std::string> ScheduleMugshot = std::map<ScheduleLabel, std::string>();
	void SetScheduleMugshot();
	bool IsFirstUpdate = true;
};


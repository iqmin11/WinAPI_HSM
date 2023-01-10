#pragma once
#include <map>
#include <string>
#include <GameEnginePlatform/GameEngineImage.h>	

//모든 리소스 관리(사운드, 이미지 등)

class GameEnginePath;
class GameEngineImage;
class GameEngineResources
{
public:

	// delete Function
	GameEngineResources(const GameEngineResources& _Other) = delete;
	GameEngineResources(GameEngineResources&& _Other) noexcept = delete;
	GameEngineResources& operator=(const GameEngineResources& _Other) = delete;
	GameEngineResources& operator=(GameEngineResources&& _Other) noexcept = delete;

	static GameEngineResources& GetInst()
	{
		return Inst;
	}

	bool ImageLoad(const GameEnginePath& _Path);
	
	bool ImageLoad(const std::string_view& _Path, const std::string_view& _Name);

	GameEngineImage* ImageFind(const std::string_view& _Name);

	void Relase();


protected:


private:
	static GameEngineResources Inst;
	std::map<std::string, GameEngineImage*> AllImage;
	
	// construtor destructor
	GameEngineResources();
	~GameEngineResources();

};


#pragma once
// c++이 실행되는 곳에서 사용할수 있는 모든 경로 관련 처리방식을 지원해준다.
#include <filesystem> 

//이동 등 경로를 움직이는것에대한 역할인것 같아
class GameEnginePath // 경로에 관련한 기능을 대표하는 클래스
{
public:
	// construtor destructor
	GameEnginePath();
	GameEnginePath(std::filesystem::path _Path);
	GameEnginePath(const std::string& _Path);
	~GameEnginePath();

	// delete Function
	GameEnginePath(const GameEnginePath& _Other); // 쉽게말하면 L-Value를 인자로 받는 복사생성자
	GameEnginePath(GameEnginePath&& _Other); // 쉽게말하면 R-Value를 인자로 받는 이동생성자
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

	std::string GetFileName() const;

	std::string GetPathToString() const;
	void MoveParent(); //Path를 상위폴더Path로 바꿈
	void MoveParentToChildPath(const std::string_view& _String); // 인자의 파일명이 있을때까지 상위폴더로 이동 리소스 폴더는 상위폴더에 만들거기 떄문에 이렇게 구성했나봐
	bool IsRoot(); // 패스가 루트 패스야?
	bool IsExistsToPlusString(const std::string_view& _String); // 니가 인자로 받은 파일명을 현재 Path에서 접근 가능해??
	bool IsExists(); // 그 경로가 실제로 있어?
	bool Move(const std::string_view& _Path); // 파일명을 받으면 현재 경로랑 합쳐서 파일 실행 경로로 이동


protected:


private:

	std::filesystem::path Path;

};


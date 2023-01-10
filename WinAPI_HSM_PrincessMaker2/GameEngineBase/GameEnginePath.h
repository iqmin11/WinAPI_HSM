#pragma once
// c++�� ����Ǵ� ������ ����Ҽ� �ִ� ��� ��� ���� ó������� �������ش�.
#include <filesystem> 

//�̵� �� ��θ� �����̴°Ϳ����� �����ΰ� ����
class GameEnginePath // ��ο� ������ ����� ��ǥ�ϴ� Ŭ����
{
public:
	// construtor destructor
	GameEnginePath();
	GameEnginePath(std::filesystem::path _Path);
	GameEnginePath(const std::string& _Path);
	~GameEnginePath();

	// delete Function
	GameEnginePath(const GameEnginePath& _Other); // ���Ը��ϸ� L-Value�� ���ڷ� �޴� ���������
	GameEnginePath(GameEnginePath&& _Other); // ���Ը��ϸ� R-Value�� ���ڷ� �޴� �̵�������
	GameEnginePath& operator=(const GameEnginePath& _Other) = delete;
	GameEnginePath& operator=(GameEnginePath&& _Other) noexcept = delete;

	std::string GetFileName() const;

	std::string GetPathToString() const;
	void MoveParent(); //Path�� ��������Path�� �ٲ�
	void MoveParentToChildPath(const std::string_view& _String); // ������ ���ϸ��� ���������� ���������� �̵� ���ҽ� ������ ���������� ����ű� ������ �̷��� �����߳���
	bool IsRoot(); // �н��� ��Ʈ �н���?
	bool IsExistsToPlusString(const std::string_view& _String); // �ϰ� ���ڷ� ���� ���ϸ��� ���� Path���� ���� ������??
	bool IsExists(); // �� ��ΰ� ������ �־�?
	bool Move(const std::string_view& _Path); // ���ϸ��� ������ ���� ��ζ� ���ļ� ���� ���� ��η� �̵�


protected:


private:

	std::filesystem::path Path;

};


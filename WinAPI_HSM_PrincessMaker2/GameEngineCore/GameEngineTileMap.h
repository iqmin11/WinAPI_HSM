#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineActor.h"

// �������
// �� ���ʹ� ������ 0,0,0
// ������ �����Ҷ��� ������ cutting�� �̹����� ���ü� �ִ�.

struct FloorInfo
{

};

// ���� :
class GameEngineTileMap : public GameEngineActor
{
public:
    // constrcuter destructer
    GameEngineTileMap();
    ~GameEngineTileMap();

    // delete Function
    GameEngineTileMap(const GameEngineTileMap& _Other) = delete;
    GameEngineTileMap(GameEngineTileMap&& _Other) noexcept = delete;
    GameEngineTileMap& operator=(const GameEngineTileMap& _Other) = delete;
    GameEngineTileMap& operator=(GameEngineTileMap&& _Other) noexcept = delete;

    // ������ 
    void CreateTileMap(int _X, int _Y, int _Z, int _Order, float4 _TileSize);

    void SetFloorSetting(int _ZIndex, const std::string_view& _ImageName);

    void SetTileFrame(int _ZIndex, float4 _Pos, int _ImageFrame);

    int GetTileFrame(int _ZIndex, float4 _Pos);

protected:

private:
    float4 ScreenSize = float4::Zero;
    float4 TileScale = float4::Zero;

    int X = 0;
    int Y = 0;
    int Z = 0;

    std::vector<std::string_view> FloorImageName = std::vector<std::string_view>();
    std::vector<std::vector<std::vector<GameEngineRender*>>> TileRenders = std::vector<std::vector<std::vector<GameEngineRender*>>>();
};


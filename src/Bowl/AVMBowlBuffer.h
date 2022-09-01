#ifndef AVMBOWLBUFFER_H
#define AVMBOWLBUFFER_H

#include "../Platform/platform.h"

const float PAI = 3.141592657932385f;
const float EPSILON = 1e-9; // 接受1e-9以内的误差

struct Point {
    float world_x;
    float world_y;
    float world_z;
    
    Point() {
        world_x = 0.0f;
        world_y = 0.0f;
        world_z = 0.0f;
    }
};

//--------------------------------------------------------------------------------------
// Name: class AVMBowlBuffer()
// Desc: AVMBowlBuffer class
//--------------------------------------------------------------------------------------
class AVMBowlBuffer
{
public:
    AVMBowlBuffer();
    void Initialize();
    void Build();
    ~AVMBowlBuffer();

    void getAllPointBuffer(std::vector<float> &pointBuffer);
    void getAllIndexBuffer(std::vector<unsigned int> &indexBuffer);

    void getFrontPointBuffer(std::vector<float> &pointBuffer);
    void getFrontIndexBuffer(std::vector<unsigned int> &indexBuffer) const;

    void getFrontRightPointBuffer(std::vector<float> &pointBuffer);
    void getFrontRightIndexBuffer(std::vector<unsigned int> &indexBuffer);

    void getRightPointBuffer(std::vector<float> &pointBuffer);
    void getRightIndexBuffer(std::vector<unsigned int> &indexBuffer);

    void getBackRightPointBuffer(std::vector<float> &pointBuffer);
    void getBackRightIndexBuffer(std::vector<unsigned int> &indexBuffer);

    void getBackPointBuffer(std::vector<float> &pointBuffer);
    void getBackIndexBuffer(std::vector<unsigned int> &indexBuffer);

    void getBackLeftPointBuffer(std::vector<float> &pointBuffer);
    void getBackLeftIndexBuffer(std::vector<unsigned int> &indexBuffer);

    void getLeftPointBuffer(std::vector<float> &pointBuffer);
    void getLeftIndexBuffer(std::vector<unsigned int> &indexBuffer);

    void getFrontLeftPointBuffer(std::vector<float> &pointBuffer);
    void getFrontLeftIndexBuffer(std::vector<unsigned int> &indexBuffer);

private:
    // 车辆参数
    float m_fLength;        // 长度
    float m_fWidth;         // 宽度
    float m_fRotation;      // 底部半径
    float m_fRotationHigh;  // 腰部半径

    // 定点个数
    unsigned int m_nWidthNumber;
    unsigned int m_nLengthNumber;
    unsigned int m_nAngleNumber;
    unsigned int m_nRotationNumber;
    unsigned int m_nHighNumber;

    // 结果定点数据缓存
    std::vector<std::vector<Point>> m_vecFrontPointBuffer;
    std::vector<std::vector<Point>> m_vecFrontRightPointBuffer;
    std::vector<std::vector<Point>> m_vecRightPointBuffer;
    std::vector<std::vector<Point>> m_vecBackRightPointBuffer;
    std::vector<std::vector<Point>> m_vecBackPointBuffer;
    std::vector<std::vector<Point>> m_vecBackLeftPointBuffer;
    std::vector<std::vector<Point>> m_vecLeftPointBuffer;
    std::vector<std::vector<Point>> m_vecFrontLeftPointBuffer;

    // 结果索引数据缓存
    // std::vector<unsigned int> m_vecFrontIndexBuffer;
    // std::vector<unsigned int> m_vecFrontRightIndexBuffer;
    // std::vector<unsigned int> m_vecRightIndexBuffer;
    // std::vector<unsigned int> m_vecBackRightIndexBuffer;
    // std::vector<unsigned int> m_vecBackIndexBuffer;
    // std::vector<unsigned int> m_vecBackLeftIndexBuffer;
    // std::vector<unsigned int> m_vecLeftIndexBuffer;
    // std::vector<unsigned int> m_vecFrontLeftIndexBuffer;

    // 结果定点数据缓存
    std::vector<std::vector<Point>> m_vecBowlPointBuffer;
    // 结果索引数据缓存
    // std::vector<unsigned int> m_vecBowlIndexBuffer;
};

#endif // AVMBOWLBUFFER_H

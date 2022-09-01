#include "AVMBowlBuffer.h"

float fellipse(float a, float b, float x) 
{
    if (fabs(a - x) < EPSILON) {
        return 0.0f;
    }
    
    float temp = 1.0f - glm::pow(x,2)/glm::pow(a,2);
    float y = std::pow(glm::pow(b,2) * temp, 0.5);
    return y;
}

//--------------------------------------------------------------------------------------
// Name: AVMBowlBuffer()
// Desc: Construction the application base class. The default values can be overrided
//       by the derived class.
//--------------------------------------------------------------------------------------
AVMBowlBuffer::AVMBowlBuffer()
{

}

//--------------------------------------------------------------------------------------
// Name: Initialize()
// Desc: 碗状模型参数的初始化
//       长度、宽度、高度和顶点个数都在这里完成
//--------------------------------------------------------------------------------------
void AVMBowlBuffer::Initialize()
{
    m_fLength       = 4.95f;
    m_fWidth        = 2.25f;
    m_fRotation     = 4.0f;
    m_fRotationHigh = 2.0f;

    m_nWidthNumber    = 40;
    m_nLengthNumber   = 40;
    m_nAngleNumber    = 40;
    m_nRotationNumber = 30;
    m_nHighNumber     = 15;
}

//--------------------------------------------------------------------------------------
// Name: Build()
// Desc: 创建碗状模型
//--------------------------------------------------------------------------------------
void AVMBowlBuffer::Build()
{
    m_vecFrontPointBuffer.resize(m_nRotationNumber + m_nHighNumber);
    for (auto & i : m_vecFrontPointBuffer)
    {
        i.resize(m_nWidthNumber);
    }

    m_vecFrontRightPointBuffer.resize(m_nRotationNumber + m_nHighNumber);
    for (auto & i : m_vecFrontRightPointBuffer)
    {
        i.resize(m_nAngleNumber);
    }

    m_vecRightPointBuffer.resize(m_nRotationNumber + m_nHighNumber);
    for (auto & i : m_vecRightPointBuffer)
    {
        i.resize(m_nLengthNumber);
    }

    m_vecBackRightPointBuffer.resize(m_nRotationNumber + m_nHighNumber);
    for (auto & i : m_vecBackRightPointBuffer)
    {
        i.resize(m_nAngleNumber);
    }

    m_vecBackPointBuffer.resize(m_nRotationNumber + m_nHighNumber);
    for (auto & i : m_vecBackPointBuffer)
    {
        i.resize(m_nWidthNumber);
    }

    m_vecBackLeftPointBuffer.resize(m_nRotationNumber + m_nHighNumber);
    for (auto & i : m_vecBackLeftPointBuffer)
    {
        i.resize(m_nAngleNumber);
    }

    m_vecLeftPointBuffer.resize(m_nRotationNumber + m_nHighNumber);
    for (auto & i : m_vecLeftPointBuffer)
    {
        i.resize(m_nLengthNumber);
    }

    m_vecFrontLeftPointBuffer.resize(m_nRotationNumber + m_nHighNumber);
    for (auto & i : m_vecFrontLeftPointBuffer)
    {
        i.resize(m_nAngleNumber);
    }

    for (unsigned int i = 0; i < m_nRotationNumber + m_nHighNumber; ++i) {
        float eachRotationLength = 0.0f;
        float eachRotationWidth =  0.0f;
        float eachHeigh = 0.0f;

        if (i >= 0 && i < m_nRotationNumber)
        {
            float dr = m_fRotation / m_nRotationNumber;
            eachRotationLength = i * dr * 1.5f;
            eachRotationWidth =  i * dr;
            eachHeigh = 0.0f;
        }
        else if (i >= m_nRotationNumber && i < m_nRotationNumber + m_nHighNumber)
        {
            float dr = m_fRotationHigh / m_nHighNumber;
            eachRotationLength = (m_fRotation + (i - m_nRotationNumber) * dr) * 1.5f;
            eachRotationWidth =  m_fRotation + (i - m_nRotationNumber) * dr;
            eachHeigh = 1.05f * glm::pow((i - m_nRotationNumber) * dr, 2);
        }

        float da = (PAI / 2.0f) / (m_nAngleNumber + 1);

        // front
        for (unsigned int j = 0; j < m_nWidthNumber; ++j) {
            m_vecFrontPointBuffer[i][j].world_x = m_fLength / 2.0f + eachRotationLength;
            m_vecFrontPointBuffer[i][j].world_y = m_fWidth / 2.0f - j * m_fWidth / (m_nWidthNumber - 1);
            m_vecFrontPointBuffer[i][j].world_z = eachHeigh;
        }

        // front_right
        for (unsigned int j = 0; j < m_nAngleNumber; ++j) {
            float x = eachRotationLength * glm::cos((j+1) * da);
            m_vecFrontRightPointBuffer[i][j].world_x = m_fLength / 2.0f + x;
            m_vecFrontRightPointBuffer[i][j].world_y = -m_fWidth / 2.0f - fellipse(eachRotationLength, eachRotationWidth, x);
            m_vecFrontRightPointBuffer[i][j].world_z = eachHeigh;
        }

        // right
        for (unsigned int j = 0; j < m_nLengthNumber; ++j) {
            m_vecRightPointBuffer[i][j].world_x = m_fLength / 2.0f - j * m_fLength / (m_nLengthNumber - 1);
            m_vecRightPointBuffer[i][j].world_y = -m_fWidth / 2.0f - eachRotationWidth;
            m_vecRightPointBuffer[i][j].world_z = eachHeigh;
        }

        // back_right
        for (unsigned int j = 0; j < m_nAngleNumber; ++j) {
            float x = eachRotationLength * glm::sin((j+1) * da);
            m_vecBackRightPointBuffer[i][j].world_x = -m_fLength / 2.0f - x;
            m_vecBackRightPointBuffer[i][j].world_y = -m_fWidth / 2.0f - fellipse(eachRotationLength, eachRotationWidth, x);
            m_vecBackRightPointBuffer[i][j].world_z = eachHeigh;
        }

        // back
        for (unsigned int j = 0; j < m_nWidthNumber; ++j) {
            m_vecBackPointBuffer[i][j].world_x = -m_fLength / 2.0f - eachRotationLength;
            m_vecBackPointBuffer[i][j].world_y = -m_fWidth / 2.0f + j * m_fWidth / (m_nWidthNumber - 1);
            m_vecBackPointBuffer[i][j].world_z = eachHeigh;
        }

        // back_left
        for (unsigned int j = 0; j < m_nAngleNumber; ++j) {
            float x = eachRotationLength * glm::cos((j+1) * da);
            m_vecBackLeftPointBuffer[i][j].world_x = -m_fLength / 2.0f - x;
            m_vecBackLeftPointBuffer[i][j].world_y = m_fWidth / 2.0f + fellipse(eachRotationLength, eachRotationWidth, x);
            m_vecBackLeftPointBuffer[i][j].world_z = eachHeigh;
        }

        // left
        for (unsigned int j = 0; j < m_nLengthNumber; ++j) {
            m_vecLeftPointBuffer[i][j].world_x = -m_fLength/2.0f + j * m_fLength / (m_nLengthNumber - 1);
            m_vecLeftPointBuffer[i][j].world_y = m_fWidth / 2.0f + eachRotationWidth;
            m_vecLeftPointBuffer[i][j].world_z = eachHeigh;
        }

        //front_left
        for (unsigned int j = 0; j < m_nAngleNumber; ++j) {
            float x = eachRotationLength * glm::sin((j+1) * da);
            m_vecFrontLeftPointBuffer[i][j].world_x = m_fLength / 2.0f + x;
            m_vecFrontLeftPointBuffer[i][j].world_y = m_fWidth / 2.0f + fellipse(eachRotationLength, eachRotationWidth, x);
            m_vecFrontLeftPointBuffer[i][j].world_z = eachHeigh;
        }
    }

    m_vecBowlPointBuffer.clear(); 
    for (unsigned int i = 0; i < m_nRotationNumber + m_nHighNumber; ++i) 
    {
        std::vector<Point> eachPointBuffer;
        for (unsigned int j = 0; j < m_nWidthNumber; ++j) {
            eachPointBuffer.push_back(m_vecFrontPointBuffer[i][j]);
        }
        for (unsigned int j = 0; j < m_nAngleNumber; ++j) {
            eachPointBuffer.push_back(m_vecFrontRightPointBuffer[i][j]);
        }
        for (unsigned int j = 0; j < m_nLengthNumber; ++j) {
            eachPointBuffer.push_back(m_vecRightPointBuffer[i][j]);
        }
        for (unsigned int j = 0; j < m_nAngleNumber; ++j) {
            eachPointBuffer.push_back(m_vecBackRightPointBuffer[i][j]);
        }
        for (unsigned int j = 0; j < m_nWidthNumber; ++j) {
            eachPointBuffer.push_back(m_vecBackPointBuffer[i][j]);
        }
        for (unsigned int j = 0; j < m_nAngleNumber; ++j) {
            eachPointBuffer.push_back(m_vecBackLeftPointBuffer[i][j]);
        }
        for (unsigned int j = 0; j < m_nLengthNumber; ++j) {
            eachPointBuffer.push_back(m_vecLeftPointBuffer[i][j]);
        }
        for (unsigned int j = 0; j < m_nAngleNumber; ++j) {
            eachPointBuffer.push_back(m_vecFrontLeftPointBuffer[i][j]);
        }
        m_vecBowlPointBuffer.push_back(eachPointBuffer);
    }
}

//--------------------------------------------------------------------------------------
// Name: getAllPointBuffer()
// Desc: 获取模型所有顶点数据
// Example: Point.x Point.y Point.z ...
//--------------------------------------------------------------------------------------
void AVMBowlBuffer::getAllPointBuffer(std::vector<float> &pointBuffer) 
{
    pointBuffer.clear();
    for (size_t i = 0; i < m_vecBowlPointBuffer.size(); ++i) {
        for(size_t j = 0; j < m_vecBowlPointBuffer[i].size(); ++j) {
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_x);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_y);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_z);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_weight);
        }
    }
}

void AVMBowlBuffer::getAllIndexBuffer(std::vector<unsigned int> &indexBuffer) 
{
    indexBuffer.clear();
    unsigned int move = m_vecBowlPointBuffer[0].size();
    for (size_t i = 0; i < m_vecBowlPointBuffer.size() - 1; ++i) {
        for (size_t j = 0; j < m_vecBowlPointBuffer[i].size() - 1; ++j) {
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+move+j);
            indexBuffer.push_back(move*i+move+j+1);
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+j+1);
            indexBuffer.push_back(move*i+move+j+1);
        }
        unsigned int lastPointIndex = (unsigned int)(m_vecBowlPointBuffer[i].size() - 1);
        indexBuffer.push_back(move*i + lastPointIndex);
        indexBuffer.push_back(move*i + move + lastPointIndex);
        indexBuffer.push_back(move*i + move);
        indexBuffer.push_back(move*i + lastPointIndex);
        indexBuffer.push_back(move*i);
        indexBuffer.push_back(move*i + move);
    }
}

void AVMBowlBuffer::getFrontPointBuffer(std::vector<float> &pointBuffer)
{
    // for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
    //     for (unsigned int j = 0; j < m_nWidthNumber; ++j) {
    //         CalculatePointToUVForMei(mCamera.front_short_camera,
    //                                  m_vecBowlPointBuffer[i][j],
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_u,
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_v);
    //         m_vecBowlPointBuffer[i][j].texture_a_f_weight = 1.0f;
    //         m_vecBowlPointBuffer[i][j].texture_a_s_weight = 0.0f;
    //         m_vecBowlPointBuffer[i][j].texture_b_f_weight = 0.0f;
    //         m_vecBowlPointBuffer[i][j].texture_b_s_weight = 0.0f;
    //     }
    // }
    pointBuffer.clear();
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
        for(unsigned int j = 0; j < m_nWidthNumber; ++j) {
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_x);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_y);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_z);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_weight);
        }
    }
}

void AVMBowlBuffer::getFrontRightPointBuffer(std::vector<float> &pointBuffer)
{
    // for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
    //     for(unsigned int j = (m_nWidthNumber - 1); j < (m_nWidthNumber + m_nAngleNumber + 2); ++j) {
    //         CalculatePointToUVForMei(mCamera.front_short_camera,
    //                                  m_vecBowlPointBuffer[i][j],
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_u,
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_v);
    //         m_vecBowlPointBuffer[i][j].texture_a_f_weight = 1.0f;
    //         m_vecBowlPointBuffer[i][j].texture_a_s_weight = 0.0f;
    //         m_vecBowlPointBuffer[i][j].texture_b_f_weight = 0.0f;
    //         m_vecBowlPointBuffer[i][j].texture_b_s_weight = 0.0f;
    //     }
    // }
    pointBuffer.clear();
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
        for(unsigned int j = (m_nWidthNumber - 1); j < (m_nWidthNumber + m_nAngleNumber + 1); ++j) {
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_x);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_y);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_z);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_weight);
        }
    }
}

void AVMBowlBuffer::getRightPointBuffer(std::vector<float> &pointBuffer)
{
    // for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
    //     for (unsigned int j = (m_nWidthNumber + m_nAngleNumber); j < (m_nWidthNumber + m_nAngleNumber + m_nLengthNumber); ++j) {
    //         CalculatePointToUVForMei(mCamera.right_short_camera,
    //                                  m_vecBowlPointBuffer[i][j],
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_u,
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_v);
    //         m_vecBowlPointBuffer[i][j].texture_a_f_weight = 1.0f;
    //     }
    // }
    pointBuffer.clear();
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
        for(unsigned int j = (m_nWidthNumber + m_nAngleNumber); j < (m_nWidthNumber + m_nAngleNumber + m_nLengthNumber); ++j) {
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_x);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_y);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_z);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_weight);
        }
    }
}

void AVMBowlBuffer::getBackRightPointBuffer(std::vector<float> &pointBuffer)
{
    // for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
    //     for(unsigned int j = (m_nWidthNumber + m_nLengthNumber + m_nAngleNumber - 1); 
    //                      j < (m_nWidthNumber + m_nLengthNumber + m_nAngleNumber * 2 + 1); ++j) {
    //         CalculatePointToUVForMei(mCamera.right_short_camera,
    //                                  m_vecBowlPointBuffer[i][j],
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_u,
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_v);
    //         m_vecBowlPointBuffer[i][j].texture_a_f_weight = 1.0f;
    //     }
    // }
    pointBuffer.clear();
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
        for(unsigned int j = (m_nWidthNumber + m_nLengthNumber + m_nAngleNumber - 1); 
                         j < (m_nWidthNumber + m_nLengthNumber + m_nAngleNumber * 2 + 1); ++j) {
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_x);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_y);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_z);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_weight);
        }
    }
}

void AVMBowlBuffer::getBackPointBuffer(std::vector<float> &pointBuffer)
{
    // for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
    //     for(unsigned int j = (m_nWidthNumber + m_nLengthNumber + m_nAngleNumber * 2); 
    //                      j < (m_nWidthNumber * 2 + m_nLengthNumber + m_nAngleNumber * 2); ++j) {
    //         CalculatePointToUVForMei(mCamera.rear_short_camera,
    //                                  m_vecBowlPointBuffer[i][j],
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_u,
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_v);
    //         m_vecBowlPointBuffer[i][j].texture_a_f_weight = 1.0f;
    //     }
    // }
    pointBuffer.clear();
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
        for(unsigned int j = (m_nWidthNumber + m_nLengthNumber + m_nAngleNumber * 2); 
                         j < (m_nWidthNumber * 2 + m_nLengthNumber + m_nAngleNumber * 2); ++j) {
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_x);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_y);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_z);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_weight);
        }
    }
}

void AVMBowlBuffer::getBackLeftPointBuffer(std::vector<float> &pointBuffer)
{
    // for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
    //     for(unsigned int j = (m_nWidthNumber * 2 + m_nLengthNumber + m_nAngleNumber * 2 - 1); 
    //                      j < (m_nWidthNumber * 2 + m_nLengthNumber + m_nAngleNumber * 3 + 1); ++j) {
    //         CalculatePointToUVForMei(mCamera.left_short_camera,
    //                                  m_vecBowlPointBuffer[i][j],
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_u,
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_v);
    //         m_vecBowlPointBuffer[i][j].texture_a_f_weight = 1.0f;
    //     }
    // }
    pointBuffer.clear();
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
        for(unsigned int j = (m_nWidthNumber * 2 + m_nLengthNumber + m_nAngleNumber * 2 - 1); 
                         j < (m_nWidthNumber * 2 + m_nLengthNumber + m_nAngleNumber * 3 + 1); ++j) {
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_x);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_y);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_z);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_weight);
        }
    }
}

void AVMBowlBuffer::getLeftPointBuffer(std::vector<float> &pointBuffer)
{
    // for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
    //     for (unsigned int j = (m_nWidthNumber * 2 + m_nAngleNumber * 3 + m_nLengthNumber); 
    //                       j < (m_nWidthNumber * 2 + m_nAngleNumber * 3 + m_nLengthNumber * 2); ++j) {
    //         CalculatePointToUVForMei(mCamera.left_short_camera,
    //                                  m_vecBowlPointBuffer[i][j],
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_u,
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_v);
    //         m_vecBowlPointBuffer[i][j].texture_a_f_weight = 1.0f;
    //     }
    // }
    pointBuffer.clear();
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
        for(unsigned int j = (m_nWidthNumber * 2 + m_nAngleNumber * 3 + m_nLengthNumber); 
                         j < (m_nWidthNumber * 2 + m_nAngleNumber * 3 + m_nLengthNumber * 2); ++j) {
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_x);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_y);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_z);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_weight);
        }
    }
}

void AVMBowlBuffer::getFrontLeftPointBuffer(std::vector<float> &pointBuffer)
{
    // for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
    //     for(unsigned int j = (m_nWidthNumber * 2 + m_nLengthNumber * 2 + m_nAngleNumber * 3 - 1); 
    //                      j < (m_nWidthNumber * 2 + m_nLengthNumber * 2 + m_nAngleNumber * 4); ++j) {
    //         CalculatePointToUVForMei(mCamera.front_short_camera,
    //                                  m_vecBowlPointBuffer[i][j],
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_u,
    //                                  m_vecBowlPointBuffer[i][j].texture_a_f_v);
    //         m_vecBowlPointBuffer[i][j].texture_a_f_weight = 1.0f;
    //     }
    //     CalculatePointToUVForMei(mCamera.front_short_camera,
    //                                  m_vecBowlPointBuffer[i][0],
    //                                  m_vecBowlPointBuffer[i][0].texture_a_f_u,
    //                                  m_vecBowlPointBuffer[i][0].texture_a_f_v);
    //     m_vecBowlPointBuffer[i][0].texture_a_f_weight = 1.0f;
    // }
    pointBuffer.clear();
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber); ++i) {
        for(unsigned int j = (m_nWidthNumber * 2 + m_nLengthNumber * 2 + m_nAngleNumber * 3 - 1); 
                         j < (m_nWidthNumber * 2 + m_nLengthNumber * 2 + m_nAngleNumber * 4); ++j) {
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_x);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_y);
            pointBuffer.push_back(m_vecBowlPointBuffer[i][j].world_z);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_a_s_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_f_weight);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_u);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_v);
            // pointBuffer.push_back(m_vecBowlPointBuffer[i][j].texture_b_s_weight);
        }
        pointBuffer.push_back(m_vecBowlPointBuffer[i][0].world_x);
        pointBuffer.push_back(m_vecBowlPointBuffer[i][0].world_y);
        pointBuffer.push_back(m_vecBowlPointBuffer[i][0].world_z);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_a_f_u);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_a_f_v);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_a_f_weight);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_a_s_u);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_a_s_v);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_a_s_weight);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_b_f_u);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_b_f_v);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_b_f_weight);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_b_s_u);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_b_s_v);
        // pointBuffer.push_back(m_vecBowlPointBuffer[i][0].texture_b_s_weight);
    }
}

void AVMBowlBuffer::getFrontIndexBuffer(std::vector<unsigned int> &indexBuffer) const
{
    indexBuffer.clear();
    unsigned int move = m_nWidthNumber;
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber - 1); ++i) {
        for (unsigned int j = 0; j < (m_nWidthNumber - 1); ++j) {
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+move+j);
            indexBuffer.push_back(move*i+move+j+1);
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+j+1);
            indexBuffer.push_back(move*i+move+j+1);
        }
    }
}

void AVMBowlBuffer::getFrontRightIndexBuffer(std::vector<unsigned int> &indexBuffer)
{
    indexBuffer.clear();
    unsigned int move = m_nAngleNumber + 2;
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber - 1); ++i) {
        for (unsigned int j = 0; j < (move - 1); ++j) {
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+move+j);
            indexBuffer.push_back(move*i+move+j+1);
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+j+1);
            indexBuffer.push_back(move*i+move+j+1);
        }
    }
}

void AVMBowlBuffer::getRightIndexBuffer(std::vector<unsigned int> &indexBuffer)
{
    indexBuffer.clear();
    unsigned int move = m_nLengthNumber;
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber - 1); ++i) {
        for (unsigned int j = 0; j < (m_nLengthNumber - 1); ++j) {
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+move+j);
            indexBuffer.push_back(move*i+move+j+1);
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+j+1);
            indexBuffer.push_back(move*i+move+j+1);
        }
    }
}

void AVMBowlBuffer::getBackRightIndexBuffer(std::vector<unsigned int> &indexBuffer)
{
    indexBuffer.clear();
    unsigned int move = m_nAngleNumber + 2;
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber - 1); ++i) {
        for (unsigned int j = 0; j < (move - 1); ++j) {
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+move+j);
            indexBuffer.push_back(move*i+move+j+1);
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+j+1);
            indexBuffer.push_back(move*i+move+j+1);
        }
    }
}

void AVMBowlBuffer::getBackIndexBuffer(std::vector<unsigned int> &indexBuffer)
{
    indexBuffer.clear();
    unsigned int move = m_nWidthNumber;
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber - 1); ++i) {
        for (unsigned int j = 0; j < (m_nWidthNumber - 1); ++j) {
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+move+j);
            indexBuffer.push_back(move*i+move+j+1);
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+j+1);
            indexBuffer.push_back(move*i+move+j+1);
        }
    }
}

void AVMBowlBuffer::getBackLeftIndexBuffer(std::vector<unsigned int> &indexBuffer)
{
    indexBuffer.clear();
    unsigned int move = m_nAngleNumber + 2;
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber - 1); ++i) {
        for (unsigned int j = 0; j < (move - 1); ++j) {
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+move+j);
            indexBuffer.push_back(move*i+move+j+1);
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+j+1);
            indexBuffer.push_back(move*i+move+j+1);
        }
    }
}

void AVMBowlBuffer::getLeftIndexBuffer(std::vector<unsigned int> &indexBuffer)
{
    indexBuffer.clear();
    unsigned int move = m_nLengthNumber;
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber - 1); ++i) {
        for (unsigned int j = 0; j < (m_nLengthNumber - 1); ++j) {
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+move+j);
            indexBuffer.push_back(move*i+move+j+1);
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+j+1);
            indexBuffer.push_back(move*i+move+j+1);
        }
    }
}

void AVMBowlBuffer::getFrontLeftIndexBuffer(std::vector<unsigned int> &indexBuffer)
{
    indexBuffer.clear();
    unsigned int move = m_nAngleNumber + 2;
    for (unsigned int i = 0; i < (m_nRotationNumber + m_nHighNumber - 1); ++i) {
        for (unsigned int j = 0; j < (move - 1); ++j) {
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+move+j);
            indexBuffer.push_back(move*i+move+j+1);
            indexBuffer.push_back(move*i+j);
            indexBuffer.push_back(move*i+j+1);
            indexBuffer.push_back(move*i+move+j+1);
        }
    }
}

AVMBowlBuffer::~AVMBowlBuffer()
{

}

//
//  AVMCamera.h
//  AVMTest
//
//  Created by longyaowei on 2022/5/4.
//

#ifndef AVMCAMERA_H
#define AVMCAMERA_H

#include "../Platform/platform.h"
#include "AVMBowlBuffer.h"

struct Rotation {
    float yaw;
    float pitch;
    float roll;
};

struct Translation {
    float x;
    float y;
    float z;
};

//--------------------------------------------------------------------------------------
// Name: struct MEICamera
// Desc: MEI 
//       相机模型 Unified projection model
//--------------------------------------------------------------------------------------
struct MEICamera {
    std::string name;
    float xi;
    float fx;
    float fy;
    float cx;
    float cy;
    float distortion1;
    float distortion2;
    float distortion3;
    float distortion4;
    float distortion5;
    float image_width;
    float image_height;
    Rotation rotation;
    Translation translation;
    std::string cameraModel;
    std::string orientation;
    MEICamera() {
        cameraModel = "MEI";
    }
};

//--------------------------------------------------------------------------------------
// Name: struct PinholeCamera
// Desc: PINHOLE     
//       相机模型 Pinhole camera model
//--------------------------------------------------------------------------------------
struct PinholeCamera {
    std::string name;
    float xi;
    float fx;
    float fy;
    float cx;
    float cy;
    float distortion1;
    float distortion2;
    float distortion3;
    float distortion4;
    float distortion5;
    float image_width;
    float image_height;
    Rotation rotation;
    Translation translation;
    std::string cameraModel;
    std::string orientation;
    PinholeCamera() {
        cameraModel = "PINHOLE";
    }
};

//--------------------------------------------------------------------------------------
// Name: struct EquidistantCamera
// Desc: EQUIDISTANT 
//       相机模型 Equidistant fish-eye model
//--------------------------------------------------------------------------------------
struct EquidistantCamera {
    std::string name;
    float xi;
    float fx;
    float fy;
    float cx;
    float cy;
    float distortion1;
    float distortion2;
    float distortion3;
    float distortion4;
    float distortion5;
    float image_width;
    float image_height;
    Rotation rotation;
    Translation translation;
    std::string cameraModel;
    std::string orientation;
    EquidistantCamera() {
        cameraModel = "EQUIDISTANT";
    }
};

class AVMCamera {
public:
    AVMCamera();
    // MEI         相机模型 Unified projection model
    void CalculatePointToUVForMei(MEICamera &cameraParam, Point &point, float &resultu, float &resultv);
    // PINHOLE     相机模型 Pinhole camera model
    void CalculatePointToUVForPinhole(PinholeCamera &cameraParam, Point &point, float &resultu, float &resultv);
    // EQUIDISTANT 相机模型 Equidistant fish-eye model
    void CalculatePointToUVForEquidistant(EquidistantCamera &cameraParam, Point &point, float &resultu, float &resultv);
    PinholeCamera front_long_camera;
    EquidistantCamera front_wide_camera;
    PinholeCamera rear_middle_camera;
    PinholeCamera front_middle_camera;
    PinholeCamera right_rear_camera;
    EquidistantCamera left_front_camera;
    PinholeCamera left_rear_camera;
    EquidistantCamera right_front_camera;
    MEICamera front_short_camera;
    MEICamera right_short_camera;
    MEICamera left_short_camera;
    MEICamera rear_short_camera;
};

#endif /* AVMCAMERA_H */

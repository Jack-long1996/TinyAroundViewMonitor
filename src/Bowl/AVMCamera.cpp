//
//  AVMCameraParam.cpp
//  AVMTest
//
//  Created by longyaowei on 2022/5/4.
//

#include "AVMCamera.h"

AVMCamera::AVMCamera() {
    // front_long_camera
    front_long_camera.name              = "front_long_camera";
    front_long_camera.xi                = 0.0;
    front_long_camera.fx                = 3885.12;
    front_long_camera.fy                = 3885.12;
    front_long_camera.cx                = 964.872;
    front_long_camera.cy                = 542.96;
    front_long_camera.distortion1       = -0.110491;
    front_long_camera.distortion2       = -0.20726;
    front_long_camera.distortion3       = 0.0;
    front_long_camera.distortion4       = 0.0;
    front_long_camera.distortion5       = 0.0;
    front_long_camera.image_width       = 1920;
    front_long_camera.image_height      = 1080;
    front_long_camera.rotation.yaw      = -1.5743382;
    front_long_camera.rotation.pitch    = -0.00325092603;
    front_long_camera.rotation.roll     = -1.57006848;
    front_long_camera.translation.x     = 1.94102657;
    front_long_camera.translation.y     = -0.0339999981;
    front_long_camera.translation.z     = 1.49424303;
    front_long_camera.cameraModel       = "PINHOLE";
    front_long_camera.orientation       = "FRONT";
    
    // front_wide_camera
    front_wide_camera.name              = "front_wide_camera";
    front_wide_camera.xi                = 0.0;
    front_wide_camera.fx                = 1014.88;
    front_wide_camera.fy                = 1014.73;
    front_wide_camera.cx                = 945.649;
    front_wide_camera.cy                = 548.417;
    front_wide_camera.distortion1       = -0.0616657;
    front_wide_camera.distortion2       = -0.00195312;
    front_wide_camera.distortion3       = 0.0;
    front_wide_camera.distortion4       = 0.0;
    front_wide_camera.distortion5       = 0.0;
    front_wide_camera.image_width       = 1920;
    front_wide_camera.image_height      = 1080;
    front_wide_camera.rotation.yaw      = -1.56911695;
    front_wide_camera.rotation.pitch    = 0.0169506464;
    front_wide_camera.rotation.roll     = -1.56963634;
    front_wide_camera.translation.x     = 1.93965268;
    front_wide_camera.translation.y     = 0.002;
    front_wide_camera.translation.z     = 1.45181477;
    front_wide_camera.cameraModel       = "EQUIDISTANT";
    front_wide_camera.orientation       = "FRONT";

    // rear_middle_camera
    rear_middle_camera.name              = "rear_middle_camera";
    rear_middle_camera.xi                = 0.0;
    rear_middle_camera.fx                = 1832.75818;
    rear_middle_camera.fy                = 1832.75818;
    rear_middle_camera.cx                = 959.5;
    rear_middle_camera.cy                = 539.5;
    rear_middle_camera.distortion1       = -0.375136;
    rear_middle_camera.distortion2       = 0.134107;
    rear_middle_camera.distortion3       = 0.0;
    rear_middle_camera.distortion4       = 0.0;
    rear_middle_camera.distortion5       = 0.0;
    rear_middle_camera.image_width       = 1920;
    rear_middle_camera.image_height      = 1080;
    rear_middle_camera.rotation.yaw      = 1.5763396;
    rear_middle_camera.rotation.pitch    = -0.00226781843;
    rear_middle_camera.rotation.roll     = -1.59627116;
    rear_middle_camera.translation.x     = -0.565307558;
    rear_middle_camera.translation.y     = 0.0751388445;
    rear_middle_camera.translation.z     = 1.57701516;
    rear_middle_camera.cameraModel       = "PINHOLE";
    rear_middle_camera.orientation       = "REAR";

    // front_middle_camera
    front_middle_camera.name              = "front_middle_camera";
    front_middle_camera.xi                = 0.0;
    front_middle_camera.fx                = 1832.75818;
    front_middle_camera.fy                = 1832.75818;
    front_middle_camera.cx                = 959.5;
    front_middle_camera.cy                = 539.5;
    front_middle_camera.distortion1       = -0.375136;
    front_middle_camera.distortion2       = 0.134107;
    front_middle_camera.distortion3       = 0.0;
    front_middle_camera.distortion4       = 0.0;
    front_middle_camera.distortion5       = 0.0;
    front_middle_camera.image_width       = 1920;
    front_middle_camera.image_height      = 1080;
    front_middle_camera.rotation.yaw      = -1.57576168;
    front_middle_camera.rotation.pitch    = 0.0183185935;
    front_middle_camera.rotation.roll     = -1.59331119;
    front_middle_camera.translation.x     = 1.94360769;
    front_middle_camera.translation.y     = 0.0330000035;
    front_middle_camera.translation.z     = 1.4788388;
    front_middle_camera.cameraModel       = "PINHOLE";
    front_middle_camera.orientation       = "FRONT";

    // right_rear_camera
    right_rear_camera.name              = "right_rear_camera";
    right_rear_camera.xi                = 0.0;
    right_rear_camera.fx                = 1313.98;
    right_rear_camera.fy                = 1314.47;
    right_rear_camera.cx                = 961.468;
    right_rear_camera.cy                = 529.942;
    right_rear_camera.distortion1       = -0.352383;
    right_rear_camera.distortion2       = 0.125;
    right_rear_camera.distortion3       = 0.0;
    right_rear_camera.distortion4       = 0.0;
    right_rear_camera.distortion5       = 0.0;
    right_rear_camera.image_width       = 1920;
    right_rear_camera.image_height      = 1080;
    right_rear_camera.rotation.yaw      = 2.19119573;
    right_rear_camera.rotation.pitch    = 0.0203194581;
    right_rear_camera.rotation.roll     = -1.53618956;
    right_rear_camera.translation.x     = 2.28347397;
    right_rear_camera.translation.y     = -0.909847319;
    right_rear_camera.translation.z     = 0.888465106;
    right_rear_camera.cameraModel       = "PINHOLE";
    right_rear_camera.orientation       = "RIGHT_BACKWARD";

    // left_front_camera
    left_front_camera.name              = "left_front_camera";
    left_front_camera.xi                = 0.0;
    left_front_camera.fx                = 1015.02;
    left_front_camera.fy                = 1015.06;
    left_front_camera.cx                = 950.574;
    left_front_camera.cy                = 533.146;
    left_front_camera.distortion1       = -0.0612612;
    left_front_camera.distortion2       = -0.00195312;
    left_front_camera.distortion3       = 0.0;
    left_front_camera.distortion4       = 0.0;
    left_front_camera.distortion5       = 0.0;
    left_front_camera.image_width       = 1920;
    left_front_camera.image_height      = 1080;
    left_front_camera.rotation.yaw      = -0.234970734;
    left_front_camera.rotation.pitch    = -0.000562130474;
    left_front_camera.rotation.roll     = -1.6940763;
    left_front_camera.translation.x     = 1.62993014;
    left_front_camera.translation.y     = 0.628240466;
    left_front_camera.translation.z     = 1.64752984;
    left_front_camera.cameraModel       = "EQUIDISTANT";
    left_front_camera.orientation       = "LEFT_FORWARD";

    // left_rear_camera
    left_rear_camera.name              = "left_rear_camera";
    left_rear_camera.xi                = 0.0;
    left_rear_camera.fx                = 1316.95;
    left_rear_camera.fy                = 1317.4;
    left_rear_camera.cx                = 958.361;
    left_rear_camera.cy                = 514.233;
    left_rear_camera.distortion1       = -0.351735;
    left_rear_camera.distortion2       = 0.125;
    left_rear_camera.distortion3       = 0.0;
    left_rear_camera.distortion4       = 0.0;
    left_rear_camera.distortion5       = 0.0;
    left_rear_camera.image_width       = 1920;
    left_rear_camera.image_height      = 1080;
    left_rear_camera.rotation.yaw      = 0.932137847;
    left_rear_camera.rotation.pitch    = 0.0238270275;
    left_rear_camera.rotation.roll     = -1.5516175;
    left_rear_camera.translation.x     = 2.29393816;
    left_rear_camera.translation.y     = 0.902453959;
    left_rear_camera.translation.z     = 0.918301404;
    left_rear_camera.cameraModel       = "PINHOLE";
    left_rear_camera.orientation       = "LEFT_BACKWARD";

    // right_front_camera
    right_front_camera.name              = "right_front_camera";
    right_front_camera.xi                = 0.0;
    right_front_camera.fx                = 1014.86;
    right_front_camera.fy                = 1014.74;
    right_front_camera.cx                = 953.521;
    right_front_camera.cy                = 546.146;
    right_front_camera.distortion1       = -0.0618835;
    right_front_camera.distortion2       = -0.00195312;
    right_front_camera.distortion3       = 0.0;
    right_front_camera.distortion4       = 0.0;
    right_front_camera.distortion5       = 0.0;
    right_front_camera.image_width       = 1920;
    right_front_camera.image_height      = 1080;
    right_front_camera.rotation.yaw      = -2.86548567;
    right_front_camera.rotation.pitch    = 0.0150961466;
    right_front_camera.rotation.roll     = -1.70069361;
    right_front_camera.translation.x     = 1.61589015;
    right_front_camera.translation.y     = -0.569178581;
    right_front_camera.translation.z     = 1.61472285;
    right_front_camera.cameraModel       = "EQUIDISTANT";
    right_front_camera.orientation       = "RIGHT_FORWARD";

    // front_short_camera
    front_short_camera.name              = "front_short_camera";
    front_short_camera.xi                = 1.2106;
    front_short_camera.fx                = 625.931;
    front_short_camera.fy                = 625.992;
    front_short_camera.cx                = 640.066;
    front_short_camera.cy                = 360.055;
    front_short_camera.distortion1       = 0.429887;
    front_short_camera.distortion2       = -0.345013;
    front_short_camera.distortion3       = -0.000916921;
    front_short_camera.distortion4       = 0.000621178;
    front_short_camera.distortion5       = 0.0;
    front_short_camera.image_width       = 1280;
    front_short_camera.image_height      = 720;
    front_short_camera.rotation.yaw      = -1.57395017;
    front_short_camera.rotation.pitch    = -0.0120895104;
    front_short_camera.rotation.roll     = -1.82835937;
    front_short_camera.translation.x     = 3.58883071;
    front_short_camera.translation.y     = -0.00914543308;
    front_short_camera.translation.z     = 0.657663584;
    front_short_camera.cameraModel       = "MEI";
    front_short_camera.orientation       = "FRONT";

    // right_short_camera
    right_short_camera.name              = "right_short_camera";
    right_short_camera.xi                = 1.21439;
    right_short_camera.fx                = 625.922;
    right_short_camera.fy                = 625.834;
    right_short_camera.cx                = 638.171;
    right_short_camera.cy                = 359.047;
    right_short_camera.distortion1       = 0.43836;
    right_short_camera.distortion2       = -0.351088;
    right_short_camera.distortion3       = -0.00272368;
    right_short_camera.distortion4       = -0.00147046;
    right_short_camera.distortion5       = 0.0;
    right_short_camera.image_width       = 1280;
    right_short_camera.image_height      = 720;
    right_short_camera.rotation.yaw      = -3.13437724;
    right_short_camera.rotation.pitch    = -0.0128762489;
    right_short_camera.rotation.roll     = -2.25982237;
    right_short_camera.translation.x     = 2.00058413;
    right_short_camera.translation.y     = -1.01808476;
    right_short_camera.translation.z     = 1.14124346;
    right_short_camera.cameraModel       = "MEI";
    right_short_camera.orientation       = "RIGHT";

    // left_short_camera
    left_short_camera.name              = "left_short_camera";
    left_short_camera.xi                = 1.20874;
    left_short_camera.fx                = 625.172;
    left_short_camera.fy                = 624.985;
    left_short_camera.cx                = 638.096;
    left_short_camera.cy                = 360.118;
    left_short_camera.distortion1       = 0.426238;
    left_short_camera.distortion2       = -0.34007;
    left_short_camera.distortion3       = -7.09998e-05;
    left_short_camera.distortion4       = -0.000623345;
    left_short_camera.distortion5       = 0.0;
    left_short_camera.image_width       = 1280;
    left_short_camera.image_height      = 720;
    left_short_camera.rotation.yaw      = -0.0178333111;
    left_short_camera.rotation.pitch    = 0.015978694;
    left_short_camera.rotation.roll     = -2.28935432;
    left_short_camera.translation.x     = 2.0089829;
    left_short_camera.translation.y     = 1.02387154;
    left_short_camera.translation.z     = 1.11918378;
    left_short_camera.cameraModel       = "MEI";
    left_short_camera.orientation       = "LEFT";

    // rear_short_camera
    rear_short_camera.name              = "rear_short_camera";
    rear_short_camera.xi                = 1.21676;
    rear_short_camera.fx                = 625.946;
    rear_short_camera.fy                = 625.751;
    rear_short_camera.cx                = 641.027;
    rear_short_camera.cy                = 361.272;
    rear_short_camera.distortion1       = 0.446334;
    rear_short_camera.distortion2       = -0.356414;
    rear_short_camera.distortion3       = 0.00118095;
    rear_short_camera.distortion4       = 0.000378366;
    rear_short_camera.distortion5       = 0.0;
    rear_short_camera.image_width       = 1280;
    rear_short_camera.image_height      = 720;
    rear_short_camera.rotation.yaw      = 1.56405127;
    rear_short_camera.rotation.pitch    = 0.00724841515;
    rear_short_camera.rotation.roll     = -2.06860113;
    rear_short_camera.translation.x     = -0.925272942;
    rear_short_camera.translation.y     = 0.0416127332;
    rear_short_camera.translation.z     = 0.972438633;
    rear_short_camera.cameraModel       = "MEI";
    rear_short_camera.orientation       = "REAR";
}

void AVMCamera::CalculatePointToUVForMei(MEICamera &cameraParam, Point &point, float &resultu, float &resultv) 
{
    /* 1.获取观察矩阵 世界坐标-->摄像机空间 */
    glm::mat4 rot_p(1.0f);
    rot_p = glm::rotate(rot_p, cameraParam.rotation.pitch, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rot_y(1.0f);
    rot_y = glm::rotate(rot_y, cameraParam.rotation.yaw, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 rot_r(1.0f);
    rot_r = glm::rotate(rot_r, cameraParam.rotation.roll, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 rot = glm::inverse(rot_y * rot_p * rot_r);
    glm::mat4 viewMatrix = glm::translate(rot, glm::vec3(-cameraParam.translation.x, -cameraParam.translation.y, -cameraParam.translation.z));
    
    /* 2.获取相机参数 */
    float halfWheelbase = 2.703/2.0;

    /* 2.计算摄像机空间下坐标 */
    glm::vec4 camera_point = viewMatrix * glm::vec4(point.world_x + halfWheelbase, point.world_y, point.world_z, 1.0f);

    /* 3.归一化像素坐标 */
    float x1 = camera_point.x/(camera_point.z + glm::distance(glm::vec3(camera_point),glm::vec3(0.0))*cameraParam.xi);
    float y1 = camera_point.y/(camera_point.z + glm::distance(glm::vec3(camera_point),glm::vec3(0.0))*cameraParam.xi);

    // Radtans Distortion models
    float r2 = pow(x1, 2) + pow(y1, 2);

    /* 4.计算径向形变 */
    float radial_ret_x = x1 * (1.0f + cameraParam.distortion1 * r2 + cameraParam.distortion2 * pow(r2, 2));
    float radial_ret_y = y1 * (1.0f + cameraParam.distortion1 * r2 + cameraParam.distortion2 * pow(r2, 2));

    /* 5.计算切向形变 */
    float tangential_ret_x = 2.0 * cameraParam.distortion3 * x1 * y1 + cameraParam.distortion4 * (r2 + 2.0 * pow(x1,2));
    float tangential_ret_y = 2.0 * cameraParam.distortion4 * x1 * y1 + cameraParam.distortion3 * (r2 + 2.0 * pow(y1,2));

    /* 6.像素坐标校准 */
    float ret_x = radial_ret_x + tangential_ret_x;
    float ret_y = radial_ret_y + tangential_ret_y;

    /* 7.计算UV值 */
    float u = (cameraParam.fx * ret_x + cameraParam.cx)/cameraParam.image_width;
    float v = (cameraParam.fy * ret_y + cameraParam.cy)/cameraParam.image_height;

    /* 8.UV有效性检查 */
    if ((u >= 0 && u <= 1) && (v >= 0 && v <= 1)) {
        resultu = u;
        resultv = v;
    } else {
        resultu = 0.0;
        resultv = 0.0;
    }
}

void AVMCamera::CalculatePointToUVForPinhole(PinholeCamera &cameraParam, Point &point, float &resultu, float &resultv)
{
    /* 1.获取观察矩阵 世界坐标-->摄像机空间 */
    glm::mat4 rot_p(1.0f);
    rot_p = glm::rotate(rot_p, cameraParam.rotation.pitch, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rot_y(1.0f);
    rot_y = glm::rotate(rot_y, cameraParam.rotation.yaw, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 rot_r(1.0f);
    rot_r = glm::rotate(rot_r, cameraParam.rotation.roll, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 rot = glm::inverse(rot_y * rot_p * rot_r);
    glm::mat4 viewMatrix = glm::translate(rot, glm::vec3(-cameraParam.translation.x, -cameraParam.translation.y, -cameraParam.translation.z));
    
    /* 2.获取相机参数 */
    float halfWheelbase = 2.703/2.0;

    /* 2.计算摄像机空间下坐标 */
    glm::vec4 camera_point = viewMatrix * glm::vec4(point.world_x + halfWheelbase, point.world_y, point.world_z, 1.0f);

    /* 3.归一化像素坐标 */
    float x1 = camera_point.x/camera_point.z;
    float y1 = camera_point.y/camera_point.z;

    // Radtans Distortion models
    float r2 = pow(x1, 2) + pow(y1, 2);

    /* 4.计算径向形变 */
    float radial_ret_x = x1 * (1.0f + cameraParam.distortion1 * r2 + cameraParam.distortion2 * pow(r2, 2));
    float radial_ret_y = y1 * (1.0f + cameraParam.distortion1 * r2 + cameraParam.distortion2 * pow(r2, 2));

    /* 5.计算切向形变 */
    float tangential_ret_x = 2.0 * cameraParam.distortion3 * x1 * y1 + cameraParam.distortion4 * (r2 + 2.0 * pow(x1,2));
    float tangential_ret_y = 2.0 * cameraParam.distortion4 * x1 * y1 + cameraParam.distortion3 * (r2 + 2.0 * pow(y1,2));

    /* 6.像素坐标校准 */
    float ret_x = radial_ret_x + tangential_ret_x;
    float ret_y = radial_ret_y + tangential_ret_y;

    /* 7.计算UV值 */
    float u = (cameraParam.fx * ret_x + cameraParam.cx)/cameraParam.image_width;
    float v = (cameraParam.fy * ret_y + cameraParam.cy)/cameraParam.image_height;

    /* 8.UV有效性检查 */
    if ((u >= 0 && u <= 1) && (v >= 0 && v <= 1)) {
        resultu = u;
        resultv = v;
    } else {
        resultu = 0.0;
        resultv = 0.0;
    }
}

void AVMCamera::CalculatePointToUVForEquidistant(EquidistantCamera &cameraParam, Point &point, float &resultu, float &resultv)
{
    /* 1.获取观察矩阵 世界坐标-->摄像机空间 */
    glm::mat4 rot_p(1.0f);
    rot_p = glm::rotate(rot_p, cameraParam.rotation.pitch, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rot_y(1.0f);
    rot_y = glm::rotate(rot_y, cameraParam.rotation.yaw, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 rot_r(1.0f);
    rot_r = glm::rotate(rot_r, cameraParam.rotation.roll, glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 rot = glm::inverse(rot_y * rot_p * rot_r);
    glm::mat4 viewMatrix = glm::translate(rot, glm::vec3(-cameraParam.translation.x, -cameraParam.translation.y, -cameraParam.translation.z));
    
    /* 2.获取相机参数 */
    float halfWheelbase = 2.703/2.0;

    /* 2.计算摄像机空间下坐标 */
    glm::vec4 camera_point = viewMatrix * glm::vec4(point.world_x + halfWheelbase, point.world_y, point.world_z, 1.0f);

    /* 3.归一化像素坐标 */
    float x1 = camera_point.x/camera_point.z;
    float y1 = camera_point.y/camera_point.z;

    // Equidistant Distortion models
    float r = glm::sqrt(pow(x1, 2) + pow(y1, 2));
    float theta = glm::atan(r);
    float theta2 = theta * theta;
    float theta4 = theta2 * theta2;
    float theta6 = theta4 * theta2;
    float theta8 = theta4 * theta4;
    float thetad = theta * (1 + cameraParam.distortion1 * theta2 
                              + cameraParam.distortion2 * theta4 
                              + cameraParam.distortion3 * theta6 
                              + cameraParam.distortion4 * theta8);
    float scaling = (r > 1e-8) ? thetad / r : 1.0;

    /* 7.计算UV值 */
    float u = (cameraParam.fx * x1 * scaling + cameraParam.cx)/cameraParam.image_width;
    float v = (cameraParam.fy * y1 * scaling + cameraParam.cy)/cameraParam.image_height;

    /* 8.UV有效性检查 */
    if ((u >= 0 && u <= 1) && (v >= 0 && v <= 1)) {
        resultu = u;
        resultv = v;
    } else {
        resultu = 0.0;
        resultv = 0.0;
    }
}
 
// void AVMCamera::SaveRGB() {
//     // front_long_camera
//     int grayBytes = front_long_camera.image_width * front_long_camera.image_height * 2;
//     unsigned char* front_long_camera_buffer = new unsigned char [grayBytes];
//     std::string front_long_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleSlave/5_0.yuv";
//     getImageBuffer((void*)front_long_camera_buffer,front_long_camera_filepath.c_str());
//     cv::Mat front_long_camera_yuv(front_long_camera.image_height, front_long_camera.image_width, CV_8UC2, front_long_camera_buffer);
//     cv::Mat front_long_camera_img;
//     cv::cvtColor(front_long_camera_yuv, front_long_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/front_long_camera.jpg", front_long_camera_img);
//     std::cout<<"front_long_camera save successs!"<<std::endl;
//     delete[] front_long_camera_buffer;
    
//     // front_wide_camera
//     grayBytes = front_wide_camera.image_width * front_wide_camera.image_height * 2;
//     unsigned char* front_wide_camera_buffer = new unsigned char [grayBytes];
//     std::string front_wide_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleSlave/4_0.yuv";
//     getImageBuffer((void*)front_wide_camera_buffer,front_wide_camera_filepath.c_str());
//     cv::Mat front_wide_camera_yuv(front_wide_camera.image_height, front_wide_camera.image_width, CV_8UC2, front_wide_camera_buffer);
//     cv::Mat front_wide_camera_img;
//     cv::cvtColor(front_wide_camera_yuv, front_wide_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/front_wide_camera.jpg", front_wide_camera_img);
//     std::cout<<"front_wide_camera save successs!"<<std::endl;
//     delete[] front_wide_camera_buffer;
    
//     // rear_middle_camera
//     grayBytes = rear_middle_camera.image_width * rear_middle_camera.image_height * 2;
//     unsigned char* rear_middle_camera_buffer = new unsigned char [grayBytes];
//     std::string rear_middle_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleSlave/7_0.yuv";
//     getImageBuffer((void*)rear_middle_camera_buffer,rear_middle_camera_filepath.c_str());
//     cv::Mat rear_middle_camera_yuv(rear_middle_camera.image_height, rear_middle_camera.image_width, CV_8UC2, rear_middle_camera_buffer);
//     cv::Mat rear_middle_camera_img;
//     cv::cvtColor(rear_middle_camera_yuv, rear_middle_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/rear_middle_camera.jpg", rear_middle_camera_img);
//     std::cout<<"rear_middle_camera save successs!"<<std::endl;
//     delete[] rear_middle_camera_buffer;

//     // front_middle_camera
//     grayBytes = front_middle_camera.image_width * front_middle_camera.image_height * 2;
//     unsigned char* front_middle_camera_buffer = new unsigned char [grayBytes];
//     std::string front_middle_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleSlave/6_0.yuv";
//     getImageBuffer((void*)front_middle_camera_buffer,front_middle_camera_filepath.c_str());
//     cv::Mat front_middle_camera_yuv(front_middle_camera.image_height, front_middle_camera.image_width, CV_8UC2, front_middle_camera_buffer);
//     cv::Mat front_middle_camera_img;
//     cv::cvtColor(front_middle_camera_yuv, front_middle_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/front_middle_camera.jpg", front_middle_camera_img);
//     std::cout<<"front_middle_camera save successs!"<<std::endl;
//     delete[] front_middle_camera_buffer;

//     // right_rear_camera
//     grayBytes = right_rear_camera.image_width * right_rear_camera.image_height * 2;
//     unsigned char* right_rear_camera_buffer = new unsigned char [grayBytes];
//     std::string right_rear_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleSlave/1_0.yuv";
//     getImageBuffer((void*)right_rear_camera_buffer,right_rear_camera_filepath.c_str());
//     cv::Mat right_rear_camera_yuv(right_rear_camera.image_height, right_rear_camera.image_width, CV_8UC2, right_rear_camera_buffer);
//     cv::Mat right_rear_camera_img;
//     cv::cvtColor(right_rear_camera_yuv, right_rear_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/right_rear_camera.jpg", right_rear_camera_img);
//     std::cout<<"right_rear_camera save successs!"<<std::endl;
//     delete[] right_rear_camera_buffer;

//     // left_front_camera
//     grayBytes = left_front_camera.image_width * left_front_camera.image_height * 2;
//     unsigned char* left_front_camera_buffer = new unsigned char [grayBytes];
//     std::string left_front_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleSlave/0_0.yuv";
//     getImageBuffer((void*)left_front_camera_buffer,left_front_camera_filepath.c_str());
//     cv::Mat left_front_camera_yuv(left_front_camera.image_height, left_front_camera.image_width, CV_8UC2, left_front_camera_buffer);
//     cv::Mat left_front_camera_img;
//     cv::cvtColor(left_front_camera_yuv, left_front_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/left_front_camera.jpg", left_front_camera_img);
//     std::cout<<"left_front_camera save successs!"<<std::endl;
//     delete[] left_front_camera_buffer;

//     // left_rear_camera
//     grayBytes = left_rear_camera.image_width * left_rear_camera.image_height * 2;
//     unsigned char* left_rear_camera_buffer = new unsigned char [grayBytes];
//     std::string left_rear_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleSlave/3_0.yuv";
//     getImageBuffer((void*)left_rear_camera_buffer,left_rear_camera_filepath.c_str());
//     cv::Mat left_rear_camera_yuv(left_rear_camera.image_height, left_rear_camera.image_width, CV_8UC2, left_rear_camera_buffer);
//     cv::Mat left_rear_camera_img;
//     cv::cvtColor(left_rear_camera_yuv, left_rear_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/left_rear_camera.jpg", left_rear_camera_img);
//     std::cout<<"left_rear_camera save successs!"<<std::endl;
//     delete[] left_rear_camera_buffer;

//     // right_front_camera
//     grayBytes = right_front_camera.image_width * right_front_camera.image_height * 2;
//     unsigned char* right_front_camera_buffer = new unsigned char [grayBytes];
//     std::string right_front_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleSlave/2_0.yuv";
//     getImageBuffer((void*)right_front_camera_buffer,right_front_camera_filepath.c_str());
//     cv::Mat right_front_camera_yuv(right_front_camera.image_height, right_front_camera.image_width, CV_8UC2, right_front_camera_buffer);
//     cv::Mat right_front_camera_img;
//     cv::cvtColor(right_front_camera_yuv, right_front_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/right_front_camera.jpg", right_front_camera_img);
//     std::cout<<"right_front_camera save successs!"<<std::endl;
//     delete[] right_front_camera_buffer;

//     // front_short_camera
//     grayBytes = front_short_camera.image_width * front_short_camera.image_height * 2;
//     unsigned char* front_short_camera_buffer = new unsigned char [grayBytes];
//     std::string front_short_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleMaster/1_0.yuv";
//     getImageBuffer((void*)front_short_camera_buffer,front_short_camera_filepath.c_str());
//     cv::Mat front_short_camera_yuv(front_short_camera.image_height, front_short_camera.image_width, CV_8UC2, front_short_camera_buffer);
//     cv::Mat front_short_camera_img;
//     cv::cvtColor(front_short_camera_yuv, front_short_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/front_short_camera.jpg", front_short_camera_img);
//     std::cout<<"front_short_camera save successs!"<<std::endl;
//     delete[] front_short_camera_buffer;

//     // right_short_camera
//     grayBytes = right_short_camera.image_width * right_short_camera.image_height * 2;
//     unsigned char* right_short_camera_buffer = new unsigned char [grayBytes];
//     std::string right_short_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleMaster/2_0.yuv";
//     getImageBuffer((void*)right_short_camera_buffer,right_short_camera_filepath.c_str());
//     cv::Mat right_short_camera_yuv(right_short_camera.image_height, right_short_camera.image_width, CV_8UC2, right_short_camera_buffer);
//     cv::Mat right_short_camera_img;
//     cv::cvtColor(right_short_camera_yuv, right_short_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/right_short_camera.jpg", right_short_camera_img);
//     std::cout<<"right_short_camera save successs!"<<std::endl;
//     delete[] right_short_camera_buffer;

//     // left_short_camera
//     grayBytes = left_short_camera.image_width * left_short_camera.image_height * 2;
//     unsigned char* left_short_camera_buffer = new unsigned char [grayBytes];
//     std::string left_short_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleMaster/0_0.yuv";
//     getImageBuffer((void*)left_short_camera_buffer,left_short_camera_filepath.c_str());
//     cv::Mat left_short_camera_yuv(left_short_camera.image_height, left_short_camera.image_width, CV_8UC2, left_short_camera_buffer);
//     cv::Mat left_short_camera_img;
//     cv::cvtColor(left_short_camera_yuv, left_short_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/left_short_camera.jpg", left_short_camera_img);
//     std::cout<<"left_short_camera save successs!"<<std::endl;
//     delete[] left_short_camera_buffer;

//     // rear_short_camera
//     grayBytes = rear_short_camera.image_width * rear_short_camera.image_height * 2;
//     unsigned char* rear_short_camera_buffer = new unsigned char [grayBytes];
//     std::string rear_short_camera_filepath = "/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/wideAngleMaster/3_0.yuv";
//     getImageBuffer((void*)rear_short_camera_buffer,rear_short_camera_filepath.c_str());
//     cv::Mat rear_short_camera_yuv(rear_short_camera.image_height, rear_short_camera.image_width, CV_8UC2, rear_short_camera_buffer);
//     cv::Mat rear_short_camera_img;
//     cv::cvtColor(rear_short_camera_yuv, rear_short_camera_img, cv::COLOR_YUV2BGR_UYVY);
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/rear_short_camera.jpg", rear_short_camera_img);
//     std::cout<<"rear_short_camera save successs!"<<std::endl;
//     delete[] rear_short_camera_buffer;

//     //    cv::imshow("Display Image", img);
//     //    cv::waitKey(0);

//     cv::Mat front_short_camera_img_flip;
//     cv::flip(front_short_camera_img, front_short_camera_img_flip, 0);
//     cv::Mat right_short_camera_img_flip;
//     cv::flip(right_short_camera_img, right_short_camera_img_flip, 0);
//     cv::Mat rear_short_camera_img_flip;
//     cv::flip(rear_short_camera_img, rear_short_camera_img_flip, 0);
//     cv::Mat left_short_camera_img_flip;
//     cv::flip(left_short_camera_img, left_short_camera_img_flip, 0);

//     vector<cv::Mat> vImgs;
//     cv::Mat result;
//     vImgs.push_back(front_short_camera_img_flip);
//     vImgs.push_back(right_short_camera_img_flip);
//     vImgs.push_back(rear_short_camera_img_flip);
//     vImgs.push_back(left_short_camera_img_flip);
//     vconcat(vImgs, result); //垂直方向拼接
//     //hconcat(vImgs, result); //水平方向拼接
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/vImgs.jpg", result);
//     std::cout<<"vImgs save successs!"<<std::endl;

//     cv::Mat right_front_camera_img_flip;
//     cv::flip(right_front_camera_img, right_front_camera_img_flip, 0);
//     cv::Mat right_rear_camera_img_flip;
//     cv::flip(right_rear_camera_img, right_rear_camera_img_flip, 0);
//     cv::Mat left_rear_camera_img_flip;
//     cv::flip(left_rear_camera_img, left_rear_camera_img_flip, 0);
//     cv::Mat left_front_camera_img_flip;
//     cv::flip(left_front_camera_img, left_front_camera_img_flip, 0);

//     vector<cv::Mat> aroundImgs;
//     cv::Mat aroundResult;
//     aroundImgs.push_back(right_front_camera_img_flip);
//     aroundImgs.push_back(right_rear_camera_img_flip);
//     aroundImgs.push_back(left_rear_camera_img_flip);
//     aroundImgs.push_back(left_front_camera_img_flip);
//     vconcat(aroundImgs, aroundResult); //垂直方向拼接
//     //hconcat(aroundImgs, aroundResult); //水平方向拼接
//     cv::imwrite("/Users/longyaowei/Documents/BasicProg/AVMBowlTest/source/output/aroundImgs.jpg", aroundResult);
//     std::cout<<"aroundImgs save successs!"<<std::endl;
//     return;
// }

// void AVMCamera::getImageBuffer(void *buffer, const char *path) {
//     FILE *fp = fopen(path, "r");
//     if (fp) {
//         fseek(fp, 0, SEEK_END);
//         size_t _file_len = ftell(fp);
//         fseek(fp, 0, SEEK_SET);
//         fread(buffer, static_cast<size_t>(_file_len), 1, fp);
//         fclose(fp);
//     } else {
//         printf("get ImageBuffer fp is error. path: %s \n ",path);
//     }
// }

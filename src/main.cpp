//
//  main.cpp
//  AVMEngine
//
//  Created by longyaowei on 2022/4/1.
//
#include "Application.h"

int main(int argc, const char * argv[]) {
    std::shared_ptr<Application> m_application = nullptr;
    m_application.reset(new Application("Test"));
    m_application->Initialize();
    m_application->Update();
    m_application->Destroy();
    m_application = nullptr;
    return 0;
}
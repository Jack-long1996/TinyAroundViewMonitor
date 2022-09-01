#ifndef NODE_H
#define NODE_H

#include "../Platform/platform.h"

//--------------------------------------------------------------------------------------
// Name: class Node()
// Desc: Node class
//--------------------------------------------------------------------------------------
class Node
{
public:
    Node();
    virtual bool Update() = 0;
    virtual bool Render() = 0;
    ~Node();
private:
    uint64_t m_id;
    std::string m_name;
};

#endif // NODE_H
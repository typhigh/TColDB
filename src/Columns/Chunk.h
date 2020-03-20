#pragma once
#include "Column.h"

namespace Columns {
class Chunk
{
private:
    /* data */
public:
    Chunk(/* args */);
    ~Chunk();
};

using ChunkPtr = std::shared_ptr<Chunk>;

Chunk::Chunk(/* args */)
{
}

Chunk::~Chunk()
{
}

}
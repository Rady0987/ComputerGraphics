#include "vertex.h"

Vertex newVertex(float x, float y, float z, float red, float green, float blue) {
    Vertex v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.red = red;
    v.green = green;
    v.blue = blue;
    return v;
}

#include "vertex.h"

Vertex newVertex(float x, float y, float z, float red, float green,
                 float blue) {
    Vertex v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.blue = blue;
    v.red = red;
    v.green = green;
    return v;
}

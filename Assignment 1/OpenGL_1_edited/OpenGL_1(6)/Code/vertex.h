#ifndef VERTEX_H
#define VERTEX_H


struct Vertex {
    float x;
    float y;
    float z;
    float red;
    float green;
    float blue;
};

Vertex newVertex(float x, float y, float z, float red,
                 float green, float blue);

#endif // VERTEX_H

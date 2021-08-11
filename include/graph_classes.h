#ifndef GRAPH_CLASSES_H
#define GRAPH_CLASSES_H
#include <bits/stdc++.h>

class smallest_gunit
{
    public:
        int graph_id = -1;
        int next_byte = -1;
};

class vertex_gunit
{
    public:
        smallest_gunit v_gunit[100];
};

#endif
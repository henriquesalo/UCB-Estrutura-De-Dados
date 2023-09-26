#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

float calcularArea(Ponto* vertices, int n) {
    float area = 0.0;

    int i;
    for (i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (vertices[i].X * vertices[j].Y) - (vertices[j].X * vertices[i].Y);
    }

    area = 0.5 * fabs(area);

    return area;
}
#include <iostream>
#include <cmath>
#include "Canvas.h"

Canvas::Canvas(int width, int height) {
    this->height = height;
    this->width = width;
    grid = new char* [height];
    for(int i = 0; i < width; i++)
        grid[i] = new char[height];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++)
            grid[i][j] = ' ';
    }
}

int dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            if(abs(dist(x, y, i, j) - ray * ray) <= 2)
                grid[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    this->DrawCircle(x, y, ray, ch);
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            if(dist(x, y, i, j) <= ray * ray)
                grid[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for(int i = left;  i <= right; i++) {
        grid[top][i] = ch;
        grid[bottom][i] = ch;
    }
    for(int i = top;  i <= bottom; i++) {
        grid[i][left] = ch;
        grid[i][right] = ch;
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for(int i = left + 1;  i <= right - 1; i++) {
       for(int j = top + 1; j <= bottom - 1; j++)
           grid[i][j] = ch;
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    grid[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int md = (y2 - y1) / (x2 - x1);
    for(int i = x1; i <= x2; i++) {
        int j = md * (i - x1) + y1;
        grid[i][j] = ch;
    }
}

void Canvas::Print() {
    for(int i = 0; i < height; i++, std::cout << '\n') {
        for(int j = 0; j < width; j++) {
             std::cout << grid[i][j] << grid[i][j];
        }
    }
}

void Canvas::Clear() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++)
            grid[i][j] = ' ';
    }
}

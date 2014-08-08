//
//  main.cpp
//  OpenGLDemo
//
//  Created by shihongyang on 8/8/14.
//  Copyright (c) 2014 shihongyang. All rights reserved.
//

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    /*
    mode：创建图元的类型。可以是以下数值
    
    GL_POINTS：把每一个顶点作为一个点进行处理，顶点n即定义了点n，共绘制N个点
     
    GL_LINES：把每一个顶点作为一个独立的线段，顶点2n－1和2n之间共定义了n条线段，总共绘制N/2条线段
     
    GL_LINE_STRIP：绘制从第一个顶点到最后一个顶点依次相连的一组线段，第n和n+1个顶点定义了线段n，总共绘制n－1条线段
     
    GL_LINE_LOOP：绘制从第一个顶点到最后一个顶点依次相连的一组线段，然后最后一个顶点和第一个顶点相连，第n和n+1个顶点定义了线段n，总共绘制n条线段
     
    GL_TRIANGLES：把每个顶点作为一个独立的三角形，顶点3n－2、3n－1和3n定义了第n个三角形，总共绘制N/3个三角形
     
    GL_TRIANGLE_STRIP：绘制一组相连的三角形，对于奇数n，顶点n、n+1和n+2定义了第n个三角形；对于偶数n，顶点n+1、n和n+2定义了第n个三角形，总共绘制N-2个三角形
     
    GL_TRIANGLE_FAN：绘制一组相连的三角形，三角形是由第一个顶点及其后给定的顶点确定，顶点1、n+1和n+2定义了第n个三角形，总共绘制N-2个三角形
     
    GL_QUADS：绘制由四个顶点组成的一组单独的四边形。顶点4n－3、4n－2、4n－1和4n定义了第n个四边形。总共绘制N/4个四边形
     
    GL_QUAD_STRIP：绘制一组相连的四边形。每个四边形是由一对顶点及其后给定的一对顶点共同确定的。顶点2n－1、2n、2n+2和2n+1定义了第n个四边形，总共绘制N/2-1个四边形
     
    GL_POLYGON：绘制一个凸多边形。顶点1到n定义了这个多边形。
    */
    glBegin(GL_LINE_LOOP);
    
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    
    glEnd();
    glFlush();
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Xcode Glut Demo");
    glutDisplayFunc(&display);
    glutMainLoop();
}






















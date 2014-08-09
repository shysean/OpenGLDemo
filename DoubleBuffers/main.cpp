//
//  main.cpp
//  DoubleBuffers
//
//  Created by shihongyang on 8/9/14.
//  Copyright (c) 2014 shihongyang. All rights reserved.
//
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

static GLfloat spin = 0.0;

/*
 
 了解glutSwapBuffers()的用法
 了解GLUT的控制输入
 了解空闲处理函数的打开和关闭。
 
 */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // glPushMatrix与glPopMatrix配对使用
    // 矩阵的操作都是对于矩阵栈的栈顶来操作的
    // 配合glMatrixMode函数
    glPushMatrix();
    
    /* 如何旋转？
     想象：从坐标（0，0，0）即原点，引出一条线到（0, 0, 1）
     用右手大拇指指向（0，0，0）至（0，0，1）的方向握住。其他四个手指的弯曲指向即是物体旋转方向。
    */
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    /*
     画矩形（x1,y1,x2,y2）;
     */
    // 调用glutReshapeFunc后才可以使用坐标？
    glRectf(-25.0, -25.0, 25.0, 25.0);
//    glRectf(-0.5, -0.5, 0.5, 0.5);
    glPopMatrix();
    
    // OpenGL不提供swapbuffers方法，该方法依赖窗口系统
    // 下面的该方法由GLUT提供
    glutSwapBuffers();
}

// 改变旋转的角度
void spinDisplay(void)
{
    spin = spin + 2.0;
    if (spin > 360.0) {
        spin = spin - 360.0;
    }
    
    // 改变spin的值后，屏幕会被重绘.
    glutPostRedisplay();
}

// 窗口改变时的回调方法
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    /*
    GL_MODELVIEW: 把其后的矩阵操作施加于造型视图矩阵栈。（默认）
    GL_PROJECTION: 把其后的矩阵操作施加于投影矩阵栈。
    GL_TEXTURE： 把其后的矩阵操作施加于纹理矩阵栈。
     */
    glMatrixMode(GL_PROJECTION);
    // 恢复初始坐标系
    glLoadIdentity();
    // 正射投影
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// 空闲处理函数的打开和关闭
// 为glutMouseFunc函数的回调函数
// glutIdleFunc设置“空闲操作”
void mouse(int button, int state, int x, int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                glutIdleFunc(spinDisplay);
            }
            break;
            
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN) {
                glutIdleFunc(nullptr);
            }
            break;
        default:
            break;
    }
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    // 设置双缓存模式
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("DoubleBuffers");
    
    // 初始化
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMouseFunc(mouse);
    glutMainLoop();
}

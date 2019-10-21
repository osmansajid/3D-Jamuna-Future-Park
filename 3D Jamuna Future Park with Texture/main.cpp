/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<bits/stdc++.h>
 #include <stdlib.h>
#include<Windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <glut.h>
#endif
#include<math.h>

#include<stdio.h>
#include <gl.h>
#include <glu.h>
#include <GLAUX.h>
using namespace std;
double a=0.0,b=0.0,c=15.0;
GLfloat	l_t=0;
GLuint texture[50];
void LoadGLTextures()
{
	glPushMatrix();
	AUX_RGBImageRec* TextureImage;

	glGenTextures(6,texture);

	if (TextureImage = auxDIBImageLoad("C:\\Users\\commoc\\Downloads\\Compressed\\Lab 06\\Lab-06 3D Quad Draw with Texture\\bin\\Debug\\glass4.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("C:\\Users\\commoc\\Downloads\\Compressed\\Lab 06\\Lab-06 3D Quad Draw with Texture\\bin\\Debug\\wall.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("C:\\Users\\commoc\\Downloads\\Compressed\\Lab 06\\Lab-06 3D Quad Draw with Texture\\bin\\Debug\\grass3.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("C:\\Users\\commoc\\Downloads\\Compressed\\Lab 06\\Lab-06 3D Quad Draw with Texture\\bin\\Debug\\Title.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("C:\\Users\\commoc\\Downloads\\Compressed\\Lab 06\\Lab-06 3D Quad Draw with Texture\\bin\\Debug\\window.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("C:\\Users\\commoc\\Downloads\\Compressed\\Lab 06\\Lab-06 3D Quad Draw with Texture\\bin\\Debug\\glasswall.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

}
// Simple QUAD Draw

/*void quad()
{
    // Draw A QUAD

        glBegin(GL_QUADS);

            glColor3f(1.0f,1.0f,0.0f);
            glVertex3f(-1.0f,1.0f,8.0f);					// Top front Of The Quad (left)
            glVertex3f(-1.0f,1.0f,1.0f);					// Top back Of The Quad (left)
            glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (left)
            glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (left)

            glColor3f(0.0f,1.0f,0.0f);
            glVertex3f(1.0f,1.0f,8.0f);					    // Top front Of The Quad (right)
            glVertex3f(1.0f,1.0f,1.0f);					    // Top back Of The Quad (right)
            glVertex3f(1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (right)
            glVertex3f(1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (right)

            glColor3f(1.0f,0.0f,1.0f);
            glVertex3f(1.0f,1.0f,8.0f);					    // Right front Of The Quad (top)
            glVertex3f(1.0f,1.0f,1.0f);					    // Right back Of The Quad (top)
            glVertex3f(-1.0f,1.0f,1.0f);				    // Left back Of The Quad (top)
            glVertex3f(-1.0f,1.0f,8.0f);				    // Left front Of The Quad (top)


            glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(1.0f,-1.0f,8.0f);					// Right front Of The Quad (bottom)
            glVertex3f(1.0f,-1.0f,1.0f);					// Right back Of The Quad (bottom)
            glVertex3f(-1.0f,-1.0f,1.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(-1.0f,-1.0f,8.0f);				    // Left front Of The Quad (bottom)

            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(1.0f,1.0f,1.0f);					    // Top Right Of The Quad (Back)
            glVertex3f(-1.0f,1.0f,1.0f);					// Top Left Of The Quad (Back)
            glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom Left Of The Quad (Back)
            glVertex3f(1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Back)


            glColor3f(1.0f,0.0f,0.0f);
            glVertex3f(1.0f,1.0f,8.0f);					    // Top Right Of The Quad (Front)
            glVertex3f(-1.0f,1.0f,8.0f);					// Top Left Of The Quad (Front)
            glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom Left Of The Quad (Front)
            glVertex3f(1.0f,-1.0f,8.0f);					// Bottom Right Of The Quad (Front)

        glEnd();
}*/

// Range of Z from 5 to -8 (We should not use it because -ve means we see the object from back side.)

/*void quad()
{
    // Draw A Quad
        glBegin(GL_QUADS);


            glColor3f(1.0f,1.0f,0.0f);
            glVertex3f(1.0f,1.0f,5.0f);					    // Top front Of The Quad (right)
            glVertex3f(1.0f,1.0f,-8.0f);					// Top back Of The Quad (right)
            glVertex3f(1.0f,-1.0f,-8.0f);					// Bottom back Of The Quad (right)
            glVertex3f(1.0f,-1.0f,5.0f);					// Bottom front Of The Quad (right)

            glColor3f(0.0f,1.0f,0.0f);
            glVertex3f(-1.0f,1.0f,5.0f);					// Top front Of The Quad (left)
            glVertex3f(-1.0f,1.0f,-8.0f);					// Top back Of The Quad (left)
            glVertex3f(-1.0f,-1.0f,-8.0f);					// Bottom back Of The Quad (left)
            glVertex3f(-1.0f,-1.0f,5.0f);					// Bottom front Of The Quad (left)


            glColor3f(1.0f,0.0f,1.0f);
            glVertex3f(1.0f,1.0f,5.0f);					    // Right front Of The Quad (top)
            glVertex3f(1.0f,1.0f,-8.0f);					// Right back Of The Quad (top)
            glVertex3f(-1.0f,1.0f,-8.0f);				    // Left back Of The Quad (top)
            glVertex3f(-1.0f,1.0f,5.0f);				    // Left front Of The Quad (top)


            glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(1.0f,-1.0f,5.0f);					// Right front Of The Quad (bottom)
            glVertex3f(1.0f,-1.0f,-8.0f);					// Right back Of The Quad (bottom)
            glVertex3f(-1.0f,-1.0f,-8.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(-1.0f,-1.0f,5.0f);				    // Left front Of The Quad (bottom)


            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(1.0f,1.0f,-8.0f);					 // Top Right Of The Quad (Back)
            glVertex3f(-1.0f,1.0f,-8.0f);					// Top Left Of The Quad (Back)
            glVertex3f(-1.0f,-1.0f,-8.0f);					// Bottom Left Of The Quad (Back)
            glVertex3f(1.0f,-1.0f,-8.0f);					// Bottom Right Of The Quad (Back)


            glColor3f(1.0f,0.0f,0.0f);
            glVertex3f(1.0f,1.0f,5.0f);					    // Top Right Of The Quad (Front)
            glVertex3f(-1.0f,1.0f,5.0f);					// Top Left Of The Quad (Front)
            glVertex3f(-1.0f,-1.0f,5.0f);					// Bottom Left Of The Quad (Front)
            glVertex3f(1.0f,-1.0f,5.0f);					// Bottom Right Of The Quad (Front)
        glEnd();


}*/


//// Draw A Quad with texture
//void quad()
//{
//
//    glBindTexture(GL_TEXTURE_2D, texture[0]);
//        glBegin(GL_QUADS);
//
//
//            //glColor3f(1.0f,1.0f,0.0f);
//            glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,8.0f);					// Top front Of The Quad (left)
//            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);					// Top back Of The Quad (left)
//            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (left)
//            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (left)
//
//            //glColor3f(0.0f,1.0f,0.0f);
//
//            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					 // Top front Of The Quad (right)
//            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					// Top back Of The Quad (right)
//            glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Bottom back Of The Quad (right)
//            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Bottom front Of The Quad (right)
//
//        glEnd();
//
//    glBindTexture(GL_TEXTURE_2D, texture[1]);
//        glBegin(GL_QUADS);
//
//            //glColor3f(1.0f,0.0f,1.0f);
//            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,8.0f);					 // Right front Of The Quad (top)
//            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					// Right back Of The Quad (top)
//            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,1.0f,1.0f);				    // Left back Of The Quad (top)
//            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,1.0f,8.0f);				    // Left front Of The Quad (top)
//
//
//            //glColor3f(0.0f,1.0f,1.0f);
//            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,-1.0f,8.0f);					// Right front Of The Quad (bottom)
//            glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Right back Of The Quad (bottom)
//            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);				    // Left back Of The Quad (bottom)
//            glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,8.0f);				    // Left front Of The Quad (bottom)
//
//        glEnd();
//
//    glBindTexture(GL_TEXTURE_2D, texture[2]);
//        glBegin(GL_QUADS);
//
//            //glColor3f(0.0f,0.0f,1.0f);
//            glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);					 // Top Right Of The Quad (Back)
//            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);					// Top Left Of The Quad (Back)
//            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);					// Bottom Left Of The Quad (Back)
//            glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);					// Bottom Right Of The Quad (Back)
//
//
//            //glColor3f(1.0f,0.0f,0.0f);
//            glTexCoord2f(0.0f,1.0f); 			// Top Right Of The Quad (Front)
//            glTexCoord2f(1.0f,1.0f); 			// Top Left Of The Quad (Front)
//            glTexCoord2f(1.0f,0.0f);					// Bottom Left Of The Quad (Front)
//            glTexCoord2f(0.0f,0.0f); 			    // Bottom Right Of The Quad (Front)
//
//
//    glEnd();
//}

void quad( )
{
  // Draw A Quad

  //middle one
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
             glVertex3f(1.0f,1.0f,0.0f);					    // Top front Of The Quad (right)
            glVertex3f(1.0f,1.0f,-2.0f);					// Top back Of The Quad (right)
            glVertex3f(1.0f,-1.0f,-2.0f);					// Bottom back Of The Quad (right)
            glVertex3f(1.0f,-1.0f,0.0f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glVertex3f(-1.0f,1.0f,0.0f);					// Top front Of The Quad (left)
            glVertex3f(-1.0f,1.0f,-2.0f);					// Top back Of The Quad (left)
            glVertex3f(-1.0f,-1.0f,-2.0f);					// Bottom back Of The Quad (left)
            glVertex3f(-1.0f,-1.0f,0.0f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,1.0f,0.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,1.0f,-2.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,1.0f,-2.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,1.0f,0.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(1.0f,-1.0f,0.0f);					// Right front Of The Quad (bottom)
            glVertex3f(1.0f,-1.0f,-2.0f);					// Right back Of The Quad (bottom)
            glVertex3f(-1.0f,-1.0f,-2.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(-1.0f,-1.0f,0.0f);				    // Left front Of The Quad (bottom)


           // glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,1.0f,-2.0f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,1.0f,-2.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-1.0f,-2.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,-1.0f,-2.0f);				    // Bottom Right Of The Quad (Back)
        glEnd();
        glBindTexture(GL_TEXTURE_2D, texture[0]);
            //glColor3f(1.0f,0.0f,0.0f);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,1.0f,0.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,1.0f,0.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-1.0f,0.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,-1.0f,0.0f);					// Bottom Right Of The Quad (Front)

        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,1.0f,0.1f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f); glVertex3f(-1.15f,1.0f,0.1f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.15f,.7f,0.1f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,.7f,0.1f);					// Bottom Right Of The Quad (Front)

        glEnd();
//1st left
glBindTexture(GL_TEXTURE_2D, texture[1]);
        glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,1.5f,0.5f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,1.5f,-1.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f,0.5f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.5f,1.5f,0.5f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.5f,1.5,-1.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.5f,-1.0f,-1.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.5f,-1.0f,0.5f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,1.5f,0.5f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,1.5f,-1.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.5f,1.5f,-1.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.5f,1.5f,0.5f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(-1.0f,-1.0f,0.5f);					// Right front Of The Quad (bottom)
            glVertex3f(-1.0f,-1.0f,-1.0f);					// Right back Of The Quad (bottom)
            glVertex3f(-1.5f,-1.0f,-1.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(-1.5f,-1.0f,0.5f);				    // Left front Of The Quad (bottom)


            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,1.5f,-1.0f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.5f,1.5f,-1.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.5f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f,-1.0f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,1.5f,0.5f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.5f,1.5f,0.5f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.5f,-1.0f,0.5f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f,0.5f);					// Bottom Right Of The Quad (Front)


        glEnd();

//windows
glBindTexture(GL_TEXTURE_2D, texture[4]);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.3f,1.3f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.4f,1.3f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.4f,1.2f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.3f,1.2f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(.2-1.3f,1.3f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.2-1.4f,1.3f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(.2-1.4f,1.2f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.2-1.3f,1.2f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.3f,1.1f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.4f,1.1f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.4f,1.0f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.3f,1.0f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(.2-1.3f,1.1f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.2-1.4f,1.1f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(.2-1.4f,1.0f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.2-1.3f,1.0f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(-1.3f,.9f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.4f,.9f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.4f,.8f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.3f,.8f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(.2-1.3f,.9f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.2-1.4f,.9f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(.2-1.4f,.8f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.2-1.3f,.8f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(-1.3f,.7f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.4f,.7,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.4f,.6f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.3f,.6f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(.2-1.3f,.7f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.2-1.4f,.7f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(.2-1.4f,.6f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.2-1.3f,.6f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(-1.3f,.5f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.4f,.5f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.4f,.4f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.3f,.4f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(.2-1.3f,.5f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.2-1.4f,.5f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(.2-1.4f,.4f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.2-1.3f,.4f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(-1.3f,.3f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.4f,.3f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.4f,.2f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.3f,.2f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(.2-1.3f,.3f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.2-1.4f,.3f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(.2-1.4f,.2f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.2-1.3f,.2f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(-1.3f,.1f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.4f,.1f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-1.4f,.0f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.3f,.0f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(.2-1.3f,.1f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.2-1.4f,.1f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(.2-1.4f,.0f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.2-1.3f,.0f,0.51f);
        glEnd();

//1st right
glBindTexture(GL_TEXTURE_2D, texture[1]);

        glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5-1.0f,1.5f,0.5f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5-1.0f,1.5f,-1.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5-1.0f,-1.0f,-1.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5-1.0f,-1.0f,0.5f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5-1.5f,1.5f,0.5f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5-1.5f,1.5,-1.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5-1.5f,-1.0f,-1.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5-1.5f,-1.0f,0.5f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5-1.0f,1.5f,0.5f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5-1.0f,1.5f,-1.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5-1.5f,1.5f,-1.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5-1.5f,1.5f,0.5f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(2.5-1.0f,-1.0f,0.5f);					// Right front Of The Quad (bottom)
            glVertex3f(2.5-1.0f,-1.0f,-1.0f);					// Right back Of The Quad (bottom)
            glVertex3f(2.5-1.5f,-1.0f,-1.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(2.5-1.5f,-1.0f,0.5f);				    // Left front Of The Quad (bottom)


            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5-1.0f,1.5f,-1.0f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5-1.5f,1.5f,-1.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5-1.5f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5-1.0f,-1.0f,-1.0f);				    // Bottom Right Of The Quad (Back)



            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5-1.0f,1.5f,0.5f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5-1.5f,1.5f,0.5f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(2.5-1.5f,-1.0f,0.5f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5-1.0f,-1.0f,0.5f);					// Bottom Right Of The Quad (Front)

        glEnd();

glBindTexture(GL_TEXTURE_2D, texture[4]);

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.3f,1.3f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.4f,1.3f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.4f,1.2f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.3f,1.2f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(-.2+1.3f,1.3f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-.2+1.4f,1.3f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-.2+1.4f,1.2f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.2+1.3f,1.2f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(1.3f,1.1f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.4f,1.1f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.4f,1.0f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.3f,1.0f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(-.2+1.3f,1.1f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-.2+1.4f,1.1f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-.2+1.4f,1.0f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.2+1.3f,1.0f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(1.3f,.9f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.4f,.9f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.4f,.8f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.3f,.8f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(-.2+1.3f,.9f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-.2+1.4f,.9f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-.2+1.4f,.8f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.2+1.3f,.8f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(1.3f,.7f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.4f,.7,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.4f,.6f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.3f,.6f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(-.2+1.3f,.7f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-.2+1.4f,.7f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-.2+1.4f,.6f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.2+1.3f,.6f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(1.3f,.5f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.4f,.5f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.4f,.4f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.3f,.4f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(-.2+1.3f,.5f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-.2+1.4f,.5f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-.2+1.4f,.4f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.2+1.3f,.4f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(1.3f,.3f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.4f,.3f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.4f,.2f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.3f,.2f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(-.2+1.3f,.3f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-.2+1.4f,.3f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-.2+1.4f,.2f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.2+1.3f,.2f,0.51f);

             glTexCoord2f(0.0f,1.0f);glVertex3f(1.3f,.1f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.4f,.1f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(1.4f,.0f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.3f,.0f,0.51f);

            glTexCoord2f(0.0f,1.0f);glVertex3f(-.2+1.3f,.1f,0.51f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-.2+1.4f,.1f,0.51f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f); glVertex3f(-.2+1.4f,.0f,0.51f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.2+1.3f,.0f,0.51f);
        glEnd();



glBindTexture(GL_TEXTURE_2D, texture[1]);
//2nd left

        glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.5f,1.0f,0.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.5f,1.0f,-2.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.5f,-1.0f,-2.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.5f,-1.0f,0.0f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-2.5f,1.0f,0.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5f,1.0f,-2.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5f,-1.0f,-2.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5f,-1.0f,0.0f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.5f,1.0f,0.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.5f,1.0f,-2.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5f,1.0f,-2.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5f,1.0f,0.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(-1.5f,-1.0f,0.0f);					// Right front Of The Quad (bottom)
            glVertex3f(-1.5f,-1.0f,-2.0f);					// Right back Of The Quad (bottom)
            glVertex3f(-2.5f,-1.0f,-2.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(-2.5f,-1.0f,0.0f);				    // Left front Of The Quad (bottom)


            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.5f,1.0f,-2.0f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5f,1.0f,-2.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5f,-1.0f,-2.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.5f,-1.0f,-2.0f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.5f,1.0f,0.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5f,1.0f,0.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5f,-1.0f,0.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.5f,-1.0f,0.0f);					// Bottom Right Of The Quad (Front)

        glEnd();


//2nd right
        glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.5f,1.0f,0.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.5f,1.0f,-2.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(1.5f,-1.0f,-2.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.5f,-1.0f,0.0f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5f,1.0f,0.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5f,1.0f,-2.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5f,-1.0f,-2.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5f,-1.0f,0.0f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.5f,1.0f,0.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.5f,1.0f,-2.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5f,1.0f,-2.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5f,1.0f,0.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(1.5f,-1.0f,0.0f);					// Right front Of The Quad (bottom)
            glVertex3f(1.5f,-1.0f,-2.0f);					// Right back Of The Quad (bottom)
            glVertex3f(2.5f,-1.0f,-2.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(2.5f,-1.0f,0.0f);				    // Left front Of The Quad (bottom)


            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.5f,1.0f,-2.0f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5f,1.0f,-2.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5f,-1.0f,-2.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.5f,-1.0f,-2.0f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.5f,1.0f,0.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5f,1.0f,0.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5f,-1.0f,0.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.5f,-1.0f,0.0f);					// Bottom Right Of The Quad (Front)

        glEnd();

//3rd left
 glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-2.5f,0.5f,0.5f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5f,0.5f,-1.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5f,-1.0f,-1.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5f,-1.0f,0.5f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-4.0f,0.5f,0.5f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-4.0f,0.5f,-1.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-4.0f,-1.0f,-1.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-4.0f,-1.0f,0.5f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-2.5f,0.5f,0.5f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5f,0.5f,-1.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-4.0f,0.5f,-1.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-4.0f,0.5f,0.5f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(-2.5f,-1.0f,0.5f);					// Right front Of The Quad (bottom)
            glVertex3f(-2.5f,-1.0f,-1.0f);					// Right back Of The Quad (bottom)
            glVertex3f(-4.0f,-1.0f,-1.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(-4.0f,-1.0f,0.5f);				    // Left front Of The Quad (bottom)


            //glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(-2.5f,0.5f,-1.0f);					// Top Right Of The Quad (Back)
            glVertex3f(-4.0f,0.5f,-1.0f);					// Top Left Of The Quad (Back)
            glVertex3f(-4.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Back)
            glVertex3f(-2.5f,-1.0f,-1.0f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-2.5f,0.5f,0.5f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-4.0f,0.5f,0.5f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-4.0f,-1.0f,0.5f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5f,-1.0f,0.5f);					// Bottom Right Of The Quad (Front)

        glEnd();
//windows
        glBindTexture(GL_TEXTURE_2D, texture[4]);

        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,1.0f);glVertex3f(-3.8f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(-3.9f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(-3.9f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(-3.8f,0.35f,0.51f);

        glTexCoord2f(0.0f,1.0f);glVertex3f(-3.5f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(-3.6f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(-3.6f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(-3.5f,0.35f,0.51f);

        glTexCoord2f(0.0f,1.0f);glVertex3f(-3.2f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(-3.3f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(-3.3f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(-3.2f,0.35f,0.51f);

        glTexCoord2f(0.0f,1.0f);glVertex3f(-2.9f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(-3.0f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(-3.0f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(-2.9f,0.35f,0.51f);

        glTexCoord2f(0.0f,1.0f);glVertex3f(-2.6f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(-2.7f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(-2.7f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(-2.6f,0.35f,0.51f);
        glEnd();

//3rd right
     glBindTexture(GL_TEXTURE_2D, texture[1]);
     glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5f,0.5f,0.5f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5f,0.5f,-1.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5f,-1.0f,-1.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5f,-1.0f,0.5f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(4.0f,0.5f,0.5f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(4.0f,0.5f,-1.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(4.0f,-1.0f,-1.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(4.0f,-1.0f,0.5f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5f,0.5f,0.5f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5f,0.5f,-1.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(4.0f,0.5f,-1.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(4.0f,0.5f,0.5f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(2.5f,-1.0f,0.5f);					// Right front Of The Quad (bottom)
            glVertex3f(2.5f,-1.0f,-1.0f);					// Right back Of The Quad (bottom)
            glVertex3f(4.0f,-1.0f,-1.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(4.0f,-1.0f,0.5f);				    // Left front Of The Quad (bottom)


            //glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(2.5f,0.5f,-1.0f);					// Top Right Of The Quad (Back)
            glVertex3f(4.0f,0.5f,-1.0f);					// Top Left Of The Quad (Back)
            glVertex3f(4.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Back)
            glVertex3f(2.5f,-1.0f,-1.0f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
           glTexCoord2f(0.0f,1.0f); glVertex3f(2.5f,0.5f,0.5f);					    // Top Right Of The Quad (Front)
           glTexCoord2f(1.0f,1.0f);glVertex3f(4.0f,0.5f,0.5f);					// Top Left Of The Quad (Front)
           glTexCoord2f(1.0f,0.0f);glVertex3f(4.0f,-1.0f,0.5f);					// Bottom Left Of The Quad (Front)
           glTexCoord2f(0.0f,0.0f);glVertex3f(2.5f,-1.0f,0.5f);					// Bottom Right Of The Quad (Front)

        glEnd();

//windows
        glBindTexture(GL_TEXTURE_2D, texture[4]);

        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,1.0f);glVertex3f(3.8f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(3.9f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(3.9f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(3.8f,0.35f,0.51f);

        glTexCoord2f(0.0f,1.0f);glVertex3f(3.5f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(3.6f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(3.6f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(3.5f,0.35f,0.51f);

        glTexCoord2f(0.0f,1.0f);glVertex3f(3.2f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(3.3f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(3.3f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(3.2f,0.35f,0.51f);

        glTexCoord2f(0.0f,1.0f);glVertex3f(2.9f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(3.0f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(3.0f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(2.9f,0.35f,0.51f);

        glTexCoord2f(0.0f,1.0f);glVertex3f(2.6f,0.45f,0.51f);					    // Top Right Of The Quad (Front)
        glTexCoord2f(1.0f,1.0f);glVertex3f(2.7f,0.45f,0.51f);					// Top Left Of The Quad (Front)
        glTexCoord2f(1.0f,0.0f);glVertex3f(2.7f,0.35f,0.51f);					// Bottom Left Of The Quad (Front)
        glTexCoord2f(0.0f,0.0f);glVertex3f(2.6f,0.35f,0.51f);
        glEnd();

//4th left
     glBindTexture(GL_TEXTURE_2D, texture[1]);
     glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-2.5-1.5f,1.0f,0.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5-1.5f,1.0f,-2.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5-1.5f,-1.0f,-2.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5-1.5f,-1.0f,0.0f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-2.5-2.5f,1.0f,0.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5-2.5f,1.0f,-2.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5-2.5f,-1.0f,-2.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5-2.5f,-1.0f,0.0f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-2.5-1.5f,1.0f,0.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5-1.5f,1.0f,-2.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5-2.5f,1.0f,-2.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5-2.5f,1.0f,0.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(-2.5-1.5f,-1.0f,0.0f);					// Right front Of The Quad (bottom)
            glVertex3f(-2.5-1.5f,-1.0f,-2.0f);					// Right back Of The Quad (bottom)
            glVertex3f(-2.5-2.5f,-1.0f,-2.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(-2.5-2.5f,-1.0f,0.0f);				    // Left front Of The Quad (bottom)


            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-2.5-1.5f,1.0f,-2.0f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5-2.5f,1.0f,-2.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5-2.5f,-1.0f,-2.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5-1.5f,-1.0f,-2.0f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f); glVertex3f(-2.5-1.5f,1.0f,0.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-2.5-2.5f,1.0f,0.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-2.5-2.5f,-1.0f,0.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5-1.5f,-1.0f,0.0f);					// Bottom Right Of The Quad (Front)

        glEnd();

//4th right
    glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5+1.5f,1.0f,0.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5+1.5f,1.0f,-2.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5+1.5f,-1.0f,-2.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5+1.5f,-1.0f,0.0f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5+2.5f,1.0f,0.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5+2.5f,1.0f,-2.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5+2.5f,-1.0f,-2.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5+2.5f,-1.0f,0.0f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5+1.5f,1.0f,0.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5+1.5f,1.0f,-2.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5+2.5f,1.0f,-2.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5+2.5f,1.0f,0.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(2.5+1.5f,-1.0f,0.0f);					// Right front Of The Quad (bottom)
            glVertex3f(2.5+1.5f,-1.0f,-2.0f);					// Right back Of The Quad (bottom)
            glVertex3f(2.5+2.5f,-1.0f,-2.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(2.5+2.5f,-1.0f,0.0f);				    // Left front Of The Quad (bottom)


            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5+1.5f,1.0f,-2.0f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5+2.5f,1.0f,-2.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5+2.5f,-1.0f,-2.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5+1.5f,-1.0f,-2.0f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(2.5+1.5f,1.0f,0.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(2.5+2.5f,1.0f,0.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(2.5+2.5f,-1.0f,0.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(2.5+1.5f,-1.0f,0.0f);					// Bottom Right Of The Quad (Front)

        glEnd();

//big one
        glBegin(GL_QUADS);

           // glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(5.0f,.5f,0.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(5.0f,.5f,-5.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(5.0f,-1.0f,-5.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(5.0f,-1.0f,0.0f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-5.0f,.5f,0.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-5.0f,.5f,-5.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-5.0f,-1.0f,-5.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-5.0f,-1.0f,0.0f);					// Bottom front Of The Quad (left)


           // glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(5.0f,.5f,0.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(5.0f,.5f,-5.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-5.0f,.5f,-5.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-5.0f,.5f,0.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(5.0f,-1.0f,0.0f);					// Right front Of The Quad (bottom)
            glVertex3f(5.0f,-1.0f,-5.0f);					// Right back Of The Quad (bottom)
            glVertex3f(-5.0f,-1.0f,-5.0f);				    // Left back Of The Quad (bottom)
            glVertex3f(-5.0f,-1.0f,0.0f);				    // Left front Of The Quad (bottom)


           // glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(5.0f,.5f,-5.0f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-5.0f,.5f,-5.0f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-5.0f,-1.0f,-5.0f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(5.0f,-1.0f,-5.0f);				    // Bottom Right Of The Quad (Back)


        glEnd();

//Gate support
        glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,-.3f,2.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,-.3f,0.0f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,-.5f,0.0f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,-.5f,2.0f);					// Bottom front Of The Quad (right)

           // glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,-.3f,2.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,-.3f,0.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-.5f,0.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-.5f,2.0f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,-.3f,2.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,-.3f,0.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-.3f,0.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-.3f,2.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,-.5f,2.0f);					// Right front Of The Quad (bottom)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,-.5f,0.0f);					// Right back Of The Quad (bottom)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-.5f,0.0f);				    // Left back Of The Quad (bottom)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-.5f,2.0f);				    // Left front Of The Quad (bottom)


           // glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(1.0f,-.3f,0.0f);					// Top Right Of The Quad (Back)
            glVertex3f(-1.0f,-.3f,0.0f);					// Top Left Of The Quad (Back)
            glVertex3f(-1.0f,-.5f,0.0f);					// Bottom Left Of The Quad (Back)
            glVertex3f(1.0f,-.5f,0.0f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,-.3f,2.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,-.3f,2.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-.5f,2.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,-.5f,2.0f);					// Bottom Right Of The Quad (Front)

        glEnd();
//283500

glBindTexture(GL_TEXTURE_2D, texture[1]);
//Gate Pillar Left
    glBegin(GL_QUADS);

           // glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-.8f,-.5f,2.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-.8f,-.5f,1.7f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-.8f,-1.0f,1.7f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.8f,-1.0f,2.0f);					// Bottom front Of The Quad (right)

           // glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,-.5f,2.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,-.5f,1.7f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-1.0f,1.7f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f,2.0f);					// Bottom front Of The Quad (left)


           // glColor3f(1.0f,0.0f,1.0f);
            glVertex3f(-.8f,-.5f,2.0f);					    // Right front Of The Quad (top)
            glVertex3f(-.8f,-.5f,1.7f);					// Right back Of The Quad (top)
            glVertex3f(-1.0f,-.5f,1.7f);				    // Left back Of The Quad (top)
            glVertex3f(-1.0f,-.5f,2.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glVertex3f(-.8f,-1.0f,2.0f);					// Right front Of The Quad (bottom)
            glVertex3f(-.8f,-1.0f,1.7f);					// Right back Of The Quad (bottom)
            glVertex3f(-1.0f,-1.0f,1.7f);				    // Left back Of The Quad (bottom)
            glVertex3f(-1.0f,-1.0f,2.0f);				    // Left front Of The Quad (bottom)


           // glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-.8f,-.5f,1.7f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,-.5f,1.7f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-1.0f,1.7f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.8f,-1.0f,1.7f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-.8f,-.5f,2.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,-.5f,2.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,-1.0f,2.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-.8f,-1.0f,2.0f);					// Bottom Right Of The Quad (Front)

        glEnd();


//Gate Pillar Right

    glBegin(GL_QUADS);

            //glColor3f(0.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(.8f,-.5f,2.0f);					    // Top front Of The Quad (right)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.8f,-.5f,1.7f);					// Top back Of The Quad (right)
            glTexCoord2f(1.0f,0.0f);glVertex3f(.8f,-1.0f,1.7f);					// Bottom back Of The Quad (right)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.8f,-1.0f,2.0f);					// Bottom front Of The Quad (right)

            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,-.5f,2.0f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,-.5f,1.7f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,-1.0f,1.7f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,-1.0f,2.0f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(.8f,-.5f,2.0f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.8f,-.5f,1.7f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,-.5f,1.7f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,-.5f,2.0f);				    // Left front Of The Quad (top)


            //glColor3f(0.0f,1.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(.8f,-1.0f,2.0f);					// Right front Of The Quad (bottom)
            glTexCoord2f(1.0f,1.0f);glVertex3f(.8f,-1.0f,1.7f);					// Right back Of The Quad (bottom)
            glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,-1.0f,1.7f);				    // Left back Of The Quad (bottom)
            glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,-1.0f,2.0f);				    // Left front Of The Quad (bottom)


            //glColor3f(0.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(.8f,-.5f,1.7f);					// Top Right Of The Quad (Back)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,-.5f,1.7f);					// Top Left Of The Quad (Back)
            glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,-1.0f,1.7f);					// Bottom Left Of The Quad (Back)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.8f,-1.0f,1.7f);				    // Bottom Right Of The Quad (Back)


            //glColor3f(1.0f,0.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(.8f,-.5f,2.0f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,-.5f,2.0f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,-1.0f,2.0f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(.8f,-1.0f,2.0f);					// Bottom Right Of The Quad (Front)

        glEnd();

//Glass Left
glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_POLYGON);
            glTexCoord2f(0.0f,1.0f);glVertex3f(4.5f,.3f,0.52f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(3.5f,.3f,0.52f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(3.5f,-1.0f,0.52f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(4.5f,-1.0f,0.52f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_POLYGON);
            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(4.5f,.3f,.52f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(4.5f,.3f,0.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(4.5f,-1.0f,0.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(4.5f,-1.0f,.52f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(3.5f,.3f,0.52f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(3.5f,.3f,0.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(4.5f,.3f,0.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(4.5f,.3f,0.52f);				    // Left front Of The Quad (top)
    glEnd();
//Glass Right
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_POLYGON);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-4.5f,.3f,0.52f);					    // Top Right Of The Quad (Front)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-3.5f,.3f,0.52f);					// Top Left Of The Quad (Front)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-3.5f,-1.0f,0.52f);					// Bottom Left Of The Quad (Front)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-4.5f,-1.0f,0.52f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_POLYGON);
            //glColor3f(1.0f,1.0f,0.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-4.5f,.3f,.52f);					// Top front Of The Quad (left)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-4.5f,.3f,0.0f);					// Top back Of The Quad (left)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-4.5f,-1.0f,0.0f);					// Bottom back Of The Quad (left)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-4.5f,-1.0f,.52f);					// Bottom front Of The Quad (left)


            //glColor3f(1.0f,0.0f,1.0f);
            glTexCoord2f(0.0f,1.0f);glVertex3f(-3.5f,.3f,0.52f);					    // Right front Of The Quad (top)
            glTexCoord2f(1.0f,1.0f);glVertex3f(-3.5f,.3f,0.0f);					// Right back Of The Quad (top)
            glTexCoord2f(1.0f,0.0f);glVertex3f(-4.5f,.3f,0.0f);				    // Left back Of The Quad (top)
            glTexCoord2f(0.0f,0.0f);glVertex3f(-4.5f,.3f,0.52f);				    // Left front Of The Quad (top)
    glEnd();
//Field

    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_POLYGON);
      //glColor3f(0.0f,0.3f,0.0f);
       glTexCoord2f(0.0f,1.0f);glVertex3f(7.0f,-1.0f,-7.0f);
       glTexCoord2f(1.0f,1.0f);glVertex3f(-7.0f,-1.0f,-7.0f);
       glTexCoord2f(1.0f,0.0f);glVertex3f(-7.0f,-1.0f,7.0f);
       glTexCoord2f(0.0f,0.0f);glVertex3f(7.0f,-1.0f,7.0f);
    glEnd();

//Gate
    vector<float>x,y;
    glPushMatrix();//static part static thakbe
    int i=0;
	float angle = 0.0;
	float PI =3.1416;
	//glBegin(GL_POLYGON);
	//glColor3f(0.5,0.3,1);
    //glColor3f(0.686274,0.933333,0.933333);
    //glColor3f( 0.5294117  , 0.8078431  , 0.980392);

    for(i = 0; i < 500; i++)
    {
        float angle = 2 * PI * i / 1000;
        //glVertex3f (0.0+cos(angle) * .4,-.3+ sin(angle) * .4,2.0f);
        x.push_back(0.0+cos(angle) * .4);
        y.push_back(-.3+ sin(angle)* .4);

        //glVertex3f (0.0+cos(angle) * .4,-.3+ sin(angle) * .4,0.0f);
    }

//	glEnd();

//	for(int i=0;i<x.size();i++){
//        glBegin(GL_LINE_STRIP);
//            //glColor3f(0.5,0.3,1);
//            glVertex3f (x[i],y[i],2.0f);
//            glVertex3f (x[i],y[i],0.0f);
//        glEnd();
//	}

	vector<float>p,q;

    for(i = 0; i < 500; i++)
    {
        float angle = 2 * PI * i / 1000;
        //glVertex3f (0.0+cos(angle) * .4,-.3+ sin(angle) * .4,2.0f);
        p.push_back(0.0+cos(angle) * .2);
        q.push_back(-.3+ sin(angle)* .2);

        //glVertex3f (0.0+cos(angle) * .4,-.3+ sin(angle) * .4,0.0f);
    }

    for(int i=0;i<x.size()-10;i++){
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glBegin(GL_POLYGON);
        glTexCoord2f(0.0f,1.0f);
        glVertex3f (x[i+10],y[i+10],2.1f);
        glTexCoord2f(1.0f,1.0f);
        glVertex3f (x[i+10],y[i+10],0.0f);
        glTexCoord2f(1.0f,0.0f);
        glVertex3f (x[i],y[i],0.0f);
        glTexCoord2f(0.0f,0.0f);
        glVertex3f (x[i],y[i],2.1f);

        glEnd();
//        glBegin(GL_LINE_STRIP);
//            //glColor3f(0.5,0.3,1);
//            glVertex3f (x[i],y[i],2.0f);
//            glVertex3f (p[i],q[i],2.0f);
//        glEnd();
	}

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_POLYGON);
    for(int i=0;i<x.size();i++){
            //glColor3f(0.5,0.3,1);
            glTexCoord2f(x[i]+.75, y[i]+.75);
            glVertex3f (x[i],y[i],2.0f);


	}
	glEnd();
}


void init(void)
{

    LoadGLTextures();

	//glEnable(GL_TEXTURE_2D);
    glClearColor (0.39, 0.78, 0.52, 0.0);
}

void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);      // GL_COLOR_BUFFER_BIT indicates that the buffer is currently enabled for color writing
   glMatrixMode(GL_PROJECTION);       // Specify which matrix is the current matrix mode
   glLoadIdentity();                  // Replace the current matrix with the identity matrix
   int w=glutGet(GLUT_WINDOW_WIDTH);
   int h=glutGet(GLUT_WINDOW_HEIGHT);
   gluPerspective(40,w/h,0.1,100);    // fovy specifies the field of view angle in degrees in y direction, aspect specifies aspect ratio that determines the field of view in the x direction, znear and zfar specifies the distance from viewer to the near and far clipping plane respectively (always positive)
   glMatrixMode(GL_MODELVIEW);       //  To allow transformation on 3D object

   glLoadIdentity();
   gluLookAt(                       //  eyex, eyey, eyez specify the position of the eye point, centerx, centery, centerz specify the position of reference point, upx, upy, upz specify the direction of up vector
               a,b,c,
               0,0,0,
               0,1,0
             );
   glPushMatrix();
   glRotatef(l_t,0.0f,1.0f,0.0f);

   glEnable(GL_TEXTURE_2D);
   quad();
   glDisable(GL_TEXTURE_2D);

    glPopMatrix();

   glutSwapBuffers(); // Force execution of GL commands in finite time

}

void my_keyboard(unsigned char key, int p, int q)
{
switch (key)
{
    case 'f':  //front view
        a=0.0,b=0.0,c=15.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'b':  //back view
        a=0.0,b=0.0,c=-20.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'l':  //left view
        a=-20.0,b=0.0,c=0.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'r':  //right view
        a=20.0,b=0.0,c=0.0,l_t=0;
        glutPostRedisplay();
		break;
    case 't': //top view
        a=0.0,b=30.0,c=0.0001,l_t=0;
        glutPostRedisplay();
		break;
    case 'm': //bottom view
        a=0.0,b=-70.0,c=0.0001,l_t=0;
        glutPostRedisplay();
		break;
     default:
        break;
}
}

void spinDisplay_left(void)		//spin speed
{

    l_t =l_t+0.2;
    glutPostRedisplay();
}

void specialKeys(int key,int x,int y)
{
    if(key==GLUT_KEY_RIGHT)
           a+=0.02;
    else if(key==GLUT_KEY_LEFT)
            a-=0.02;
    else if(key==GLUT_KEY_UP)
            c--;
   else if(key==GLUT_KEY_DOWN)
            c++;
    glutPostRedisplay();
}

void mouse(int button, int state, int s, int t)
{

   switch (button)
   {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

int main()
{
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("3D View of a Quad");
	init();
    glutSpecialFunc(specialKeys);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(my_keyboard);
    glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

////////////////////////////////
// 2008			      //
// TD Animation 3D            //
// Université Paris 11	      //  
// Mehdi AMMI - ammi@limsi.fr //
////////////////////////////////

#include <GL/glut.h>    // Header pour GLUT 
#include <GL/gl.h>	// Header pour OpenGL
#include <GL/glu.h>	// Header pour GLu
#include <stdlib.h>     // Heard  Utilitaire général
#include <stdio.h>      // Header pour les fonctions entrées/sorties
#include <math.h>       // Header pour les fonctions mathèmatiques
#include "TD_Animation_3D.h"

// [nicolas.bougie@a-018350 TP1-2OPENGLTP1-2OPENGL*]$ gcc TD_animation_3D.c -o TD2 -lGL -lglut -lGLU && ./TD2

/* code ASCII pour la touche escape*/
#define ESCAPE 27

/* Idantifiant de la fenêtre GLUT */
int window; 

/* Fonction d'initialisation */
void InitGL(int Width, int Height)	        
{
// Couleur d'effacement du buffer de couleur
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		

// paramètrage du Z-buffer
  glClearDepth(1.0);	
  glDepthFunc(GL_LESS);	
  glEnable(GL_DEPTH_TEST);	


// Activation du lissage
  glShadeModel(GL_SMOOTH);			

// Projection perceptive
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				

// Projection orthogonale sans aspect ratio
  glOrtho(0.0f,(GLfloat)Width,0.0f,(GLfloat)Height,-25,25); //**

  glMatrixMode(GL_MODELVIEW);

// Compilation des lists des objets crées : axex, segments, etc.
  Objects_List();


// Initialisation du système cinématique
  InitBonesystem();

}

/* Fonction de redimensionnement de la fenêtre */
void ReSizeGLScene(int Width, int Height)
{

  glViewport(0, 0, Width, Height);		

// Projection perceptive
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				


// Projection orthogonale avec aspect ratio
  glOrtho(0.0f,(GLfloat)Width,0.0f,(GLfloat)Height,-25,25); //**


// Sauvegarde (variables globales) de la taille de la fenêtre
  m_Width = Width;
  m_Height = Height;


// Retour à la modélisation
  glMatrixMode(GL_MODELVIEW);

}

/* Focntion de dessin */
void DrawGLScene()
{
// Effacement du buffer de couleur et de profondeur
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
  glLoadIdentity();
    
    
    // ..
    // ..
	
	//glCallList(AXIS_DLIST
	
	// dessin des deux segments
	glCallList(AXIS_DLIST);
	
	
	
	glTranslatef(m_UpArm.trans.x,m_UpArm.trans.y,0);
	glRotatef(m_UpArm.rot.z,0,0,1);
	glCallList(UpArm_DLIST);
	
	
	
	
	glTranslatef(m_LowArm.trans.x,m_LowArm.trans.y,0);
	glRotatef(m_LowArm.rot.z,0,0,1);
	glCallList(LowArm_DLIST);
	
	
  // Permutation des buffers
  glutSwapBuffers();
}

/* Fonction de gestion du clavier */
void keyPressed(unsigned char key, int x, int y) 
{
	
	
	if(key== 'a'){
		m_UpArm.rot.z +=2;
		
	}
	if(key =='b'){
		m_UpArm.rot.z -=2;
		
	}
    if(key== 'z'){
		m_LowArm.rot.z +=2;
		
	}
	if(key =='s'){
		
		m_LowArm.rot.z -=2;
	}
	
    if (key == ESCAPE) 
    {
	/* Eteindre la fenêtre */
	glutDestroyWindow(window); 

	/* Sortire du programme */
	exit(0);                   
    }
    
   glutSwapBuffers();
   glutPostRedisplay();
}


// Fonction de sauvegarde des états de la souris et du système cinématique au moment du clique
void processMouse(int button, int state, int x, int y)
{
	// Sauvegarde du bouton (droit, gauche, milieu)
	m_boutton = button;

	// Sauvegarde de la position de la souris et de l'orientation des segment pour la gestion continue des angles
	m_mousepos_x = x;
	m_Grab_UPArm_Rot_Z = 	m_UpArm.rot.z;
	m_Grab_LowArm_Rot_Z = m_LowArm.rot.z;
}


// Fonction d'interaction : choix de l'opération à faire (cinématique directe / inverse)
void processMouseActiveMotion(int x, int y)
{
			
	switch (m_boutton)
	{

// Cinématique inverse
	case GLUT_LEFT_BUTTON : // Manipulation par cinématique inverse

//..
            
		break;





// Cinématique directe
	case GLUT_MIDDLE_BUTTON : // Manipulation directe du segment UpArm

//..
            
		break;

	case GLUT_RIGHT_BUTTON : // Manipulation durecte du segment LowArm

            
// ..

		break;
	}


}





int main(int argc, char **argv) 
{
  /* Initialize GLUT state - glut will take any command line arguments that pertain to it or 
     X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */  
  glutInit(&argc, argv);

  /*  Activation des buffers :   
     Double buffer 
     RGBA color
     Alpha
     Depth buffer */  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

  /* Création de la fenêtre */
  glutInitWindowSize(800, 600);  

  /* Positionnement de la fenêtre */
  glutInitWindowPosition(200, 200);  

  /* Ouverture de la fenêtre */  
  window = glutCreateWindow("TD Animation 3D");  

  /* Spécification de la fontion de dessin */
  glutDisplayFunc(&DrawGLScene);  

  /* Spécification de la fontion de redimensionnement */
  glutReshapeFunc(&ReSizeGLScene);

  /* Spécification de la fontion de  gestion du clavier */
  glutKeyboardFunc(&keyPressed);

  /* Spécification de la fontion de la souris : boutons appuyés */
  glutMouseFunc(processMouse);

  /* Spécification de la fontion de la souris : boutons appuyés avec mouvement */
  glutMotionFunc(processMouseActiveMotion);

  /* Intitialisation des paramètres de l'affichage et de la fenêtre */
  InitGL(800, 600);
  
  /* Lancement de la boucle OpenGL */  
  glutMainLoop();  

  return 1;
}





// Listes des objets à dessiner
void Objects_List()
{

// Liste Axes
glNewList(AXIS_DLIST,GL_COMPILE);

	glPushMatrix();
	glTranslatef(0.0,0.0,1.0);
	glScalef(200.0,200.0,200.0);

	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);	
		glVertex3f(-0.2f,  0.0f, 0.0f);
		glVertex3f( 0.2f,  0.0f, 0.0f);
		glVertex3f( 0.2f,  0.0f, 0.0f);	
		glVertex3f( 0.15f,  0.04f, 0.0f);
		glVertex3f( 0.2f,  0.0f, 0.0f);	
		glVertex3f( 0.15f, -0.04f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);	
		glVertex3f( 0.0f,  0.2f, 0.0f);
		glVertex3f( 0.0f, -0.2f, 0.0f);			
		glVertex3f( 0.0f,  0.2f, 0.0f);	
		glVertex3f( 0.04f,  0.15f, 0.0f);
		glVertex3f( 0.0f,  0.2f, 0.0f);	
		glVertex3f( -0.04f,  0.15f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);	
		glVertex3f( 0.0f,  0.0f,  0.2f);
		glVertex3f( 0.0f,  0.0f, -0.2f);
		glVertex3f( 0.0f,  0.0f, 0.2f);	
		glVertex3f( 0.0f,  0.04f, 0.15f);
		glVertex3f( 0.0f, 0.0f, 0.2f);	
		glVertex3f( 0.0f, -0.04f, 0.15f);
	glEnd();
	glPopMatrix();

glEndList();



// Liste UpArm
glNewList(UpArm_DLIST,GL_COMPILE);

	glPushMatrix();

		glTranslatef(UpArm_Length/2.0,0.0,0.0);
		glScalef(UpArm_Length,Arm_Width ,1.0);
		glColor3f(0.6,0.6,0.6);
		glutSolidCube(1.0);

	glPopMatrix();

glEndList();



// Liste LowArm
glNewList(LowArm_DLIST,GL_COMPILE);

	glPushMatrix();

		glTranslatef(LowArm_Length/2.0,0.0,0.0);
		glScalef(LowArm_Length,Arm_Width ,1.0);
		glColor3f(0.8,0.8,0.8);
		glutSolidCube(1.0);

	glPopMatrix();

glEndList();

}

// Fonction d'initilisation du système cinématique
void ResetBone(t_Bone *bone, float ox, float oy, float oz, float tx, float ty, float tz)
{

// Initilisation de l'orientation
	bone->rot.x = ox;
	bone->rot.y = oy;
	bone->rot.z = oz;

// Initialisation de la position
	bone->trans.x = tx;
	bone->trans.y = ty;
	bone->trans.z = tz;
}


// Initilisation du système cinématique
void InitBonesystem()
{

// Initilisation de UpArm
	// ..
	
	m_UpArm = (t_Bone){{0,0,0},{250,120,0}};


// Initilisation LowArm
    //..
    
    m_LowArm = (t_Bone){{0,0,120},{UpArm_Length,Arm_Width/2,0}};

// Initilisation de Effector
	//..

}


// Fonction de calcul de la cinématique inverse : Résultat vrais ou faux en fonction de l'objectif donnée (accessible ou non)
int ComputeIK(int x, int y)
{
/// Variables locales
  float ex,ey;		// Vecteur déplacement
  float sin2,cos2;	// SINE ry COSINE de l'ANGLE 2
  float angle1,angle2;  // ANGLE 1 et 2 en RADIANS
  float tan1;		// TAN de ANGLE 1


// ..
    
}

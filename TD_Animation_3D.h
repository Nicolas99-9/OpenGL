////////////////////////////////
// 2008			      //
// TD Animation 3D            //
// Université Paris 11	      //  
// Mehdi AMMI - ammi@limsi.fr //
////////////////////////////////

#define TRUE 1
#define FALSE 0

// Identifiants des listes (segments, axes, etc.)
#define AXIS_DLIST		1		// OPENGL DISPLAY LIST ID
#define UpArm_DLIST		2		// OPENGL DISPLAY LIST ID
#define LowArm_DLIST		3		// OPENGL DISPLAY LIST ID

// Facteur permetttant de la manipulation de la vitesse de rotation
#define ROTATE_SPEED		1.0		// SPEED OF ROTATION

// Transfomation Degrée <-> Radian
#define DEGTORAD(A)	((A * M_PI) / 180.0f)
#define RADTODEG(A)	((A * 180.0f) / M_PI)

// Structure du vecteur
typedef struct
{
	float x,y,z;
} tVector;


// Structure des segments
typedef struct 
{	// Orientation du segment
	tVector	rot;		
	// Position du segment				
	tVector	trans;						
} t_Bone;


// Varialbes

// Dimensions des segments
float UpArm_Length = 4.0 * 100;
float LowArm_Length = 3.0 * 100;
float Arm_Width = 1.0 * 100;
float Arm_Depth = 1.0 * 100;

// Déclaration des segments de la structure cinématique
t_Bone m_Body,m_UpArm,m_LowArm,m_Effector;

// Sauvegardes
float m_Grab_UPArm_Rot_Z, m_Grab_LowArm_Rot_Z;
float m_ModelScale;
int m_Width,m_Height;
int m_boutton = 0;
int m_mousepos_x = 0;

// Entêtes des fonctions
void InitGL(int Width, int Height)	;
void ReSizeGLScene(int Width, int Height);
void DrawGLScene();
void keyPressed(unsigned char key, int x, int y) ;
void processMouse(int button, int state, int x, int y);
void processMouseActiveMotion(int x, int y);
void ResetBone(t_Bone *bone, float ox, float oy, float oz, float tx, float ty, float tz);
void InitBonesystem();
void Objects_List();




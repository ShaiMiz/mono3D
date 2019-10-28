#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <mysql/mysql.h>

#include "GL/glew.h" // Important - this header must come before glfw3 header
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "FMOD/fmod.hpp"
#include "FMOD/fmod_errors.h"

#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Player.h"
#include "Camera.h"
#include "Mesh.h"

#define Num_Of_Properties 40					// Total number of squares on the board
#define This_Player Players[currentPlayer - 1]	// Current player index
#define Current_Property properties[card - 1]	// Current property that the player stand upon

//using namespace
using namespace FMOD;
using namespace glm;

typedef struct property
{
	int Position;					// Property position on the board
	int Buy_Price;					// Property buying price
	int Rent_Price;					// Property renting price (tax)
	int House_Count = 0;			// Number of houses on the property
	bool Got_Hotel = false;			// Does the property have an hotel?
	int House_Price;				// Property house buying price
	int Hotel_Price;				// Property hotel buying price
	int Owner;						// Property player owner id
	int Category;					// Property category
	int With_House[5];				// Property tax price upon landing with houses/hotel
	char Color[50];					// The property color group association
	char Name[50];					// Name of the property
} Property;

typedef struct chance
{
	int ID;							// Card id
	char CardText[255];				// Card instructions text
	int Operation;					// Card activity
} Chance, CommunityChest;

typedef struct Trivia
{
	int ID;							// Trivia question id
	char question[70];				// Trivia question text
	char answer[4][20];				// Trivia answers array
	char correctanswer[20];			// Trivia correct answer
} Trivia;

typedef struct Transaction
{
	int t_id;						// Transaction id
	int p_offer_id;					// Transaction creator (offering player) id
	int p_receive_id;				// Transaction target (offering player) id
	int t_prop_offer[28];			// Transaction offering player properties
	int t_prop_receive[28];			// Transaction receiving player properties
	int t_money_offer;				// Transaction offering player money
	int t_money_receive;			// Transaction receiving player money
	Transaction *Next;				// Transaction next pointer
	Transaction *Prev;				// Transaction back pointer
} Transaction;

typedef struct Highscore
{
	char name[10];				// Name of the player who won
	int points;					// Number of points the player have (used for rating his performance)
	int rounds;					// How long did the game took
	int money;					// How much money does the player have
} Highscore;

vec3 modelPosHouse[22][4] = {

	vec3(-5.63f, 0.2f, -7.97f),      vec3(-6.13f, 0.2f, -7.97f),	  vec3(-6.63f, 0.2f, -7.97f),      vec3(-6.13f, 0.2f, -7.27f),
	vec3(-2.48004f, 0.2f, -7.97f),   vec3(-2.98004f, 0.2f, -7.97f),   vec3(-3.48004f, 0.2f, -7.97f),   vec3(-2.98004f, 0.2f, -7.27f),
	vec3(2.37f, 0.2f, -7.97f),	     vec3(1.87f, 0.2f, -7.97f),       vec3(1.37f, 0.2f, -7.97f),       vec3(1.87f, 0.2f, -7.27f),
	vec3(5.66986f, 0.2f, -7.97f),    vec3(5.16986f, 0.2f, -7.97f),    vec3(4.66986f, 0.2f, -7.97f),    vec3(5.16986f, 0.2f, -7.27f),
	vec3(7.27984f, 0.2f, -7.97f),    vec3(6.77984f, 0.2f, -7.97f),    vec3(6.27984f, 0.2f, -7.97f),    vec3(6.77984f, 0.2f, -7.27f),
	
	vec3(7.89984f, 0.2f, -6.35002f), vec3(7.89984f, 0.2f, -6.85002f), vec3(7.89984f, 0.2f, -7.35002f), vec3(7.19984f, 0.2f, -6.85002f),
	vec3(7.89984f, 0.2f, -3.14006f), vec3(7.89984f, 0.2f, -3.64006f), vec3(7.89984f, 0.2f, -4.14006f), vec3(7.19984f, 0.2f, -3.64006f),
	vec3(7.89984f, 0.2f, -1.51008f), vec3(7.89984f, 0.2f, -2.01008f), vec3(7.89984f, 0.2f, -2.51008f), vec3(7.19984f, 0.2f, -2.01008f),
	vec3(7.89984f, 0.2f, 1.72988f),  vec3(7.89984f, 0.2f, 1.22988f),  vec3(7.89984f, 0.2f, 0.72988f),  vec3(7.19984f, 0.2f, 1.22988f),
	vec3(7.89984f, 0.2f, 4.96984f),  vec3(7.89984f, 0.2f, 4.46984f),  vec3(7.89984f, 0.2f, 3.96984f),  vec3(7.19984f, 0.2f, 4.46984f),
	vec3(7.89984f, 0.2f, 6.60982f),  vec3(7.89984f, 0.2f, 6.10982f),  vec3(7.89984f, 0.2f, 5.60982f),  vec3(7.19984f, 0.2f, 6.10982f),
	
	vec3(7.27984f, 0.2f, 7.24982f),  vec3(6.77984f, 0.2f, 7.24982f),  vec3(6.27984f, 0.2f, 7.24982f),  vec3(6.77984f, 0.2f, 6.54982f),
	vec3(4.05988f, 0.2f, 7.24982f),  vec3(3.55988f, 0.2f, 7.24982f),  vec3(3.05988f, 0.2f, 7.24982f),  vec3(3.55988f, 0.2f, 6.54982f),
	vec3(2.4499f, 0.2f, 7.24982f),   vec3(1.9499f, 0.2f, 7.24982f),	  vec3(1.4499f, 0.2f, 7.24982f),   vec3(1.9499f, 0.2f, 6.54982f),
	vec3(-0.83006f, 0.2f, 7.24982f), vec3(-1.33006f, 0.2f, 7.24982f), vec3(-1.83006f, 0.2f, 7.24982f), vec3(-1.33006f, 0.2f, 6.54982f),
	vec3(-2.44004f, 0.2f, 7.24982f), vec3(-2.94004f, 0.2f, 7.24982f), vec3(-3.44004f, 0.2f, 7.24982f), vec3(-2.94004f, 0.2f, 6.54982f),
	vec3(-5.7f, 0.2f, 7.24982f),     vec3(-6.2f, 0.2f, 7.24982f),	  vec3(-6.7f, 0.2f, 7.24982f),     vec3(-6.2f, 0.2f, 6.54982f),
	
	vec3(-7.27f, 0.2f, 6.57982f),    vec3(-7.27f, 0.2f, 6.07982f),	  vec3(-7.27f, 0.2f, 5.57982f),	   vec3(-6.57f, 0.2f, 6.07982f),
	vec3(-7.27f, 0.2f, 4.96984f),    vec3(-7.27f, 0.2f, 4.46984f),    vec3(-7.27f, 0.2f, 3.96984f),    vec3(-6.57f, 0.2f, 4.46984f),
	vec3(-7.27f, 0.2f, 1.70988f),    vec3(-7.27f, 0.2f, 1.20988f),    vec3(-7.27f, 0.2f, 0.70988f),    vec3(-6.57f, 0.2f, 1.20988f),
	vec3(-7.27f, 0.2f, -3.12006f),   vec3(-7.27f, 0.2f, -3.62006f),   vec3(-7.27f, 0.2f, -4.12006f),   vec3(-6.57f, 0.2f, -3.62006f),
	vec3(-7.27f, 0.2f, -6.34002f),   vec3(-7.27f, 0.2f, -6.84002f),   vec3(-7.27f, 0.2f, -7.34002f),   vec3(-6.57f, 0.2f, -6.84002f)
};

vec3 propertyPos[40][4] = {
	
	vec3(-7.9, 0, -8.5),			vec3(-7.9, 0, -9.5),			vec3(-8.9, 0, -8.5),			vec3(-8.9, 0, -9.5),
	vec3(-5.80001, 0, -8.5),		vec3(-5.80001, 0, -9.5),		vec3(-6.5, 0, -8.5),			vec3(-6.5, 0, -9.5),
	vec3(-4.19003, 0, -8.5),		vec3(-4.19003, 0, -9.5),		vec3(-4.89002, 0, -8.5),		vec3(-4.89002, 0, -9.5),
	vec3(-2.58004, 0, -8.5),		vec3(-2.58004, 0, -9.5),		vec3(-3.28004, 0, -8.5),		vec3(-3.28004, 0, -9.5),
	vec3(-0.970059, 0, -8.5),		vec3(-0.970059, 0, -9.5),		vec3(-1.67005, 0, -8.5),		vec3(-1.67005, 0, -9.5),
	vec3(0.639921, 0, -8.5),		vec3(0.639921, 0, -9.5),		vec3(-0.0600703, 0, -8.5),		vec3(-0.0600703, 0, -9.5),
	vec3(2.2499, 0, -8.5),			vec3(2.2499, 0, -9.5),			vec3(1.54991, 0, -8.5),			vec3(1.54991, 0, -9.5),
	vec3(3.85989, 0, -8.5),			vec3(3.85989, 0, -9.5),			vec3(3.15989, 0, -8.5),			vec3(3.15989, 0, -9.5),
	vec3(5.46987, 0, -8.5),			vec3(5.46987, 0, -9.5),			vec3(4.76988, 0, -8.5),			vec3(4.76988, 0, -9.5),
	vec3(7.07985, 0, -8.5),			vec3(7.07985, 0, -9.5),			vec3(6.37986, 0, -8.5),			vec3(6.37986, 0, -9.5),
	vec3(9.47985, 0, -8.5),			vec3(9.47985, 0, -9.5),			vec3(8.47985, 0, -8.5),			vec3(8.47985, 0, -9.5),
	vec3(9.47985, 0, -6.50003),		vec3(9.47985, 0, -7.1),			vec3(8.47985, 0, -6.50003),		vec3(8.47985, 0, -7.1),
	vec3(9.47985, 0, -4.89005),		vec3(9.47985, 0, -5.49002),		vec3(8.47985, 0, -4.89005),		vec3(8.47985, 0, -5.49002),
	vec3(9.47985, 0, -3.28006),		vec3(9.47985, 0, -3.88004),		vec3(8.47985, 0, -3.28006),		vec3(8.47985, 0, -3.88004),
	vec3(9.47985, 0, -1.67008),		vec3(9.47985, 0, -2.27005),		vec3(8.47985, 0, -1.67008),		vec3(8.47985, 0, -2.27005),
	vec3(9.47985, 0, -0.0600989),	vec3(9.47985, 0, -0.660069),	vec3(8.47985, 0, -0.0600989),	vec3(8.47985, 0, -0.660069),
	vec3(9.47985, 0, 1.54988),		vec3(9.47985, 0, 0.949911),		vec3(8.47985, 0, 1.54988),		vec3(8.47985, 0, 0.949911),
	vec3(9.47985, 0, 3.15987),		vec3(9.47985, 0, 2.55989),		vec3(8.47985, 0, 3.15987),		vec3(8.47985, 0, 2.55989),
	vec3(9.47985, 0, 4.76985),		vec3(9.47985, 0, 4.16988),		vec3(8.47985, 0, 4.76985),		vec3(8.47985, 0, 4.16988),
	vec3(9.47985, 0, 6.37983),		vec3(9.47985, 0, 5.77986),		vec3(8.47985, 0, 6.37983),		vec3(8.47985, 0, 5.77986),
	vec3(9.47985, 0, 8.77983),		vec3(9.47985, 0, 7.77983),		vec3(8.47985, 0, 8.77983),		vec3(8.47985, 0, 7.77983),
	vec3(7.07985, 0, 8.77983),		vec3(7.07985, 0, 7.77983),		vec3(6.37986, 0, 8.77983),		vec3(6.37986, 0, 7.77983),
	vec3(5.46987, 0, 8.77983),		vec3(5.46987, 0, 7.77983),		vec3(4.76988, 0, 8.77983),		vec3(4.76988, 0, 7.77983),
	vec3(3.85989, 0, 8.77983),		vec3(3.85989, 0, 7.77983),		vec3(3.15989, 0, 8.77983),		vec3(3.15989, 0, 7.77983),
	vec3(2.2499, 0, 8.77983),		vec3(2.2499, 0, 7.77983),		vec3(1.54991, 0, 8.77983),		vec3(1.54991, 0, 7.77983),
	vec3(0.639921, 0, 8.77983),		vec3(0.639921, 0, 7.77983),		vec3(-0.0600705, 0, 8.77983),	vec3(-0.0600705, 0, 7.77983),
	vec3(-0.970059, 0, 8.77983),	vec3(-0.970059, 0, 7.77983),	vec3(-1.67005, 0, 8.77983),		vec3(-1.67005, 0, 7.77983),
	vec3(-2.58004, 0, 8.77983),		vec3(-2.58004, 0, 7.77983),		vec3(-3.28004, 0, 8.77983),		vec3(-3.28004, 0, 7.77983),
	vec3(-4.19003, 0, 8.77983),		vec3(-4.19003, 0, 7.77983),		vec3(-4.89002, 0, 8.77983),		vec3(-4.89002, 0, 7.77983),
	vec3(-5.80001, 0, 8.77983),		vec3(-5.80001, 0, 7.77983),		vec3(-6.5, 0, 8.77983),			vec3(-6.5, 0, 7.77983),
	vec3(-7.9, 0, 8.77983),			vec3(-7.9, 0, 7.77983),			vec3(-8.9, 0, 8.77983),			vec3(-8.9, 0, 7.77983),
	vec3(-7.9, 0, 6.37983),			vec3(-7.9, 0, 5.67984),			vec3(-8.9, 0, 6.37983),			vec3(-8.9, 0, 5.67984),
	vec3(-7.9, 0, 4.76985),			vec3(-7.9, 0, 4.06986),			vec3(-8.9, 0, 4.76985),			vec3(-8.9, 0, 4.06986),
	vec3(-7.9, 0, 3.15987),			vec3(-7.9, 0, 2.45987),			vec3(-8.9, 0, 3.15987),			vec3(-8.9, 0, 2.45987),
	vec3(-7.9, 0, 1.54988),			vec3(-7.9, 0, 0.849889),		vec3(-8.9, 0, 1.54988),			vec3(-8.9, 0, 0.849889),
	vec3(-7.9, 0, -0.0600991),		vec3(-7.9, 0, -0.760091),		vec3(-8.9, 0, -0.0600991),		vec3(-8.9, 0, -0.760091),
	vec3(-7.9, 0, -1.67008),		vec3(-7.9, 0, -2.37007),		vec3(-8.9, 0, -1.67008),		vec3(-8.9, 0, -2.37007),
	vec3(-7.9, 0, -3.28006),		vec3(-7.9, 0, -3.98006),		vec3(-8.9, 0, -3.28006),		vec3(-8.9, 0, -3.98006),
	vec3(-7.9, 0, -4.89005),		vec3(-7.9, 0, -5.59004),		vec3(-8.9, 0, -4.89005),		vec3(-8.9, 0, -5.59004),
	vec3(-7.9, 0, -6.50003),		vec3(-7.9, 0, -7.20002),		vec3(-8.9, 0, -6.50003),		vec3(-8.9, 0, -7.20002)
};

vec3 modelOwnerNum[] = {
	vec3(-2.5, 1.5, -5.7),								// 1
	vec3(-2.5, 1.5, -4.7),								// 3
	vec3(-2.5, 1.5, -2.9),								// 6
	vec3(-2.5, 1.5, -1.9),								// 8
	vec3(-2.5, 1.5, -0.9),								// 9
	vec3(-2.5, 1.5, 0.9),								// 11
	vec3(-2.5, 1.5, 1.9),								// 13
	vec3(-2.5, 1.5, 2.9),								// 14
	vec3(2.0, 1.5, -5.7),								// 16
	vec3(2.0, 1.5, -4.7),								// 18
	vec3(2.0, 1.5, -3.7),								// 19
	vec3(2.0, 1.5, -1.9),								// 21
	vec3(2.0, 1.5, -0.9),								// 23
	vec3(2.0, 1.5, 0.1),								// 24
	vec3(2.0, 1.5, 1.9),								// 26
	vec3(2.0, 1.5, 2.9),								// 27
	vec3(2.0, 1.5, 3.9),								// 29
	vec3(6.5, 1.5, -5.7),								// 31
	vec3(6.5, 1.5, -4.7),								// 32
	vec3(6.5, 1.5, -3.7),								// 34
	vec3(6.5, 1.5, -1.9),								// 37
	vec3(6.5, 1.5, -0.9),								// 39
	vec3(6.5, 1.5, 1.2),								// 5 - Reading Railroad
	vec3(6.5, 1.5, 1.9),								// 15 - Pennysylvania Railroad
	vec3(6.5, 1.5, 2.6),								// 25 - B & O Railroad
	vec3(6.5, 1.5, 3.3),								// 35 - Shortline Railroad
	vec3(6.5, 1.5, 4.3),								// 12 - Electric Company
	vec3(6.5, 1.5, 5.5),								// 28 - Water Works
};

// Positions for the checkboxes button in the negotiation screen
int SposX[28] = { 800,800,800,800,800,800,800,800, 1053,1053,1053,1053,1053,1053,1053,1053,1053, 1303,1303,1303,1303,1303,1303,1303,1303,1303,1303,1303 };
int SposY[28] = { 178,234,337,393,450,551,608,665,  194, 249, 304, 405, 461, 516, 617, 672, 727,  193, 250, 304, 404, 460, 578, 616, 656, 695, 750, 818 };
int EposX[28] = { 833,833,833,833,833,833,833,833, 1085,1085,1085,1085,1085,1085,1085,1085,1085, 1334,1334,1334,1334,1334,1334,1334,1334,1334,1334,1334 };
int EposY[28] = { 209,266,368,425,481,582,639,698,  224, 280, 336, 435, 491, 547, 648, 703, 758,  225, 280, 337, 434, 491, 607, 646, 686, 723, 780, 847 };
int NFlagRealIndex[28] = { 1,3,6,8,9,11,13,14,16,18,19,21,23,24,26,27,29,31,32,34,37,39,5,15,25,35,12,28 };

int Mod;												// Main Game (turnState 2) - Indexer for model number used for showing property card
int MoIndex;											// Main Game (turnState 2) - Indexer for model scale & Position used for showing property card

vec3 ModScl[5][2] = {									// Main Game (turnState 2) - Scale matrice for displaying the card and buttons
	vec3(2.7f, 2.7f, 2.7f), vec3(1.4f, 0.0f, 0.8f),
	vec3(2.7f, 2.7f, 2.7f), vec3(0.8f, 0.0f, 1.4f),
	vec3(2.7f, 2.7f, 2.7f), vec3(1.4f, 0.0f, 0.8f),
	vec3(2.7f, 2.7f, 2.7f), vec3(0.8f, 0.0f, 1.4f),
	vec3(0.2f, 0.6f, 0.2f), vec3(0.8f, 1.5f, 1.4f)
};

vec3 ModPos[5][4] = { 
	vec3(0.0f, 2.5f, 3.5f),  ModPos[0][0] - vec3(0.0f, 1.0f, 6.3f),  ModPos[0][0] - vec3(-3.0f, 1.0f, 6.3f), ModPos[0][0] - vec3(3.0f, 1.0f, 6.3f),
	vec3(-3.5f, 2.5f, 0.0f), ModPos[1][0] - vec3(-6.3f, 1.0f, 0.0f), ModPos[1][0] - vec3(-6.3f, 1.0f,-3.0f), ModPos[1][0] - vec3(-6.3f, 1.0f, 3.0f),
	vec3(0.0f, 2.5f,-3.5f),  ModPos[2][0] - vec3(0.0f, 1.0f,-6.3f),  ModPos[2][0] - vec3(3.0f, 1.0f,-6.3f),  ModPos[2][0] - vec3(-3.0f, 1.0f,-6.3f),
	vec3(3.5f, 2.5f, 0.0f),  ModPos[3][0] - vec3(6.3f, 1.0f, 0.0f),  ModPos[3][0] - vec3(6.3f, 1.0f, 3.0f),  ModPos[3][0] - vec3(6.3f, 1.0f,-3.0f),
	vec3(4.0f, 2.5f, 0.8f),  vec3(-0.8f, 2.5f, 4.0f), vec3(-4.0f, 2.5f, -0.8f), vec3(0.8f, 2.5f, -4.0f)
};

// Global Variables
GLFWwindow* gWindow = NULL;								// General - Our game window pointer
const char* APP_TITLE = "Monopoly";						// General - Window title
OrbitCamera orbitCamera;								// General - Game orbit camera (x,y,z)
Player Players[4];										// General - Player array
Mesh MeshArr[20];										// General - Mesh array containing our game models (obj files)
Texture2D TextureArr[250];								// General - Texture array containing all our game pictures (png files)
ShaderProgram shaderProgram;							// General - Game shader program
vec2 lastMousePos = vec2(0, 0);							// General - Mouse position vector in the game window (x,y)
mat4 model, view, projection;							// General - Different matrices for model, view and projection from the camera
stringstream msg;										// General - StringStream variable for displaying massages on the console
ofstream logout;										// General - OfStream variable for saving the massages to the log file
Property properties[40];								// General - Properties array
CommunityChest communitychests[17];						// General - Community Chest array
Chance chance[17];										// General - Chance array
Trivia trivia[50];										// General - Trivia array
Highscore highscore[10];								// General - High Score array
Transaction *t_Head = NULL, *c_ptr = NULL;				// General - Transaction pointers for the head of the linked list and current transaction
int gWindowWidth = 1920;								// General - Game window width
int gWindowHeight = 1080;								// General - Game window height
bool gFullscreen = false;								// General - Full screen flag
bool gWireframe = false;								// General - Flag for Wireframe mode
bool pIcon[4] = { true, true, true, true };				// Settings - Temp human OR computer flag. true = Human, false = Computer
int pToken[4] = { 1,1,1,1 };							// Settings - Temp player token indicator at the selection screen
int nEdit = -1;											// Settings - Index flag for which player do we want to change the name
char pNames[4][10] = { "Player a", "Player b",			// Settings - Temp player names
					   "Player c", "Player d" };
int pNamesIndex[4] = { (int)strlen(pNames[0]),			// Settings - Temp player name length count
					   (int)strlen(pNames[1]),
					   (int)strlen(pNames[2]),
					   (int)strlen(pNames[3]) };
bool allow_print[70];									// Main Game - Flag array to display a certain massage only once
bool SkipIt = false;									// Main Game - One time timer flag for each turnState in the game
bool Payed = false;										// Main Game - One timer payment flag for each game money transaction
bool pQuit = false;										// Main Game - Flag indicating whether to display the end turn massage (Not needed if the player quit)
int gameState = -1;										// Main Game - GameState indicator: -1 - Loading, 0 - Main Menu, 1 - Game Options, 2 - Play, 3 - Load Game, 4 - High Score, 5 - Credits
int turnState = 0;										// Main Game - TurnState indicator: 0 - Before dice, 1 - Progressing, 2 - Landing, 3 - Decision, 4 - Auction Bid, 5 - Debt Clear, 6 - Loan, 7 - Negotiations, 8 - Managment, 9 - Trivia, 10 - Negotiations 2
int NumberofPlayers = 2;								// Main Game - Total player amount, will get updated upon game start
int timer1 = 600, timer2 = 600, timer3 = 3600, timer4 = 900, timer5 = 18000, timer6 = 180, timer7 = 240, timer8 = 120, timer9 = 3, timer10 = 1200, zeroCheck = 0, timer11 = 60;
int timer = timer1;										// Main Game - Game timer, initialized to 10 seconds = 600 frames
int currentPlayer = 1;									// Main Game - Current player index
bool RandButton = false;								// Main Game (turnState 0) - Indicator for if the dice  were rolled
int getoutbutton = 0;									// Main Game (turnState 0) - Get out of jail button flag if the player is in jail and have cards
int flagdouble = 0;										// Main Game (turnState 0) - Flag indicating if the dice rolled double (both dices have the same number)
int Dicefrm = timer2;									// Main Game (turnState 0) - Number of frames the dice roll needs to show dices (5 sec = 300 frames) = 5 rotations
int Dice[2] = { 0 };									// Main Game (turnState 0) - Dice array containing 2 dices and their numbers
int vacationTimer = timer2;								// Main Game (turnState 0) - Vacation - Timer for displaying the vacation screen
bool oneTimeCordDiff = false;							// Main Game (turnState 1) - Flag for one time calculation of the jump distance between 2 properties
bool PlayerMove = false;								// Main Game (turnState 1) - Indicator for if the player still needs to move on the board
int Dicesum = 0;										// Main Game (turnState 1) - Dice sum of both dices for moving the player token on board
int frm = timer11;										// Main Game (turnState 1) - Number of steps the player token need to move between each property (1 sec = 60 frames)
vec3 cordDiff;											// Main Game (turnState 1) - Temp vector for saving the difference between the current position and the next position
bool isDrop = false;									// Main Game (turnState 2) - Flag indicating whether when we need to start the animation / end it
int CurCard = 0;										// Main Game (turnState 2) - Index indicating the current property card to display on screen
int RandValue = 0;										// Main Game (turnState 2) - Community Chest / Chance random number upon landing on corrosponding property
int pHouse = 0;											// Main Game (turnState 2) - House / hotel position for sell animation
int dropDir = 0;										// Main Game (turnState 2) - Direction for sell / buy animation (Drop OR Pull)
int pHouseBack = 0;										// Main Game (turnState 2) - Saving the current House / hotel position for sell animation
vec3 dropCord = vec3(0.0f, 10.0f, 0.0f);				// Main Game (turnState 2) - Temporary house / hotel coordinations for the drop / pull
int showPrice[4] = { 0 };								// Main Game (turnState 2) - Displaying the property tax
int globalDebt = 0;										// Main Game (turnState 2) - Displaying the property tax
int roundcount = 2;										// Loan - Round index
int loanprice = 0;										// Loan - Total sum with interest
int loanInterest = 0;									// Loan - Interest sum
float Interest = 1.2f;									// Loan - Loan interest
bool botChoiceDelay = false;							// Auction - Timer for delaying the bot response in bidding
bool aucCompOnly = false;								// Auction - Flag indicating if there are only computer players in the bidding proccess
int s_sum;												// Auction - Current price saved as global for displaying purposes 
int PlayerBid = { 0 };									// Auction - Index indicating of the current player turn in the bid
int CurrentPlayerBack = 0;								// Auction - Backup of the current player before going to auction
int bidPrice = 0;										// Auction - Sum of the current highest bid
int PlayerInBid[4] = { 0 };								// Auction - Flag array indicating if the players in bid are still bidding or quit
int HighestBidder = 0;									// Auction - Player index of the current highest bidder in the bid
int ExitBid = 0;										// Auction - Flag indicating if we finished the bid proccess, someone won or the property is still unsold
bool oneTimeTriv = true;								// Trivia - Flag for one time initializing of a random question and its answers
bool draws = true;										// Trivia - Flag for drawing the answer which the mouse hover on in orange
int timert = timer10, tm = 15;								// Trivia - Timers for counting the trivia time
int t_timer = timer2;										// Trivia - Timer for the win / lose music
int ans = 0;											// Trivia - Player answer
int t_verdict = 0;										// Trivia - trivia result = correct / incorrect
int TrivRand = 0;										// Trivia - Random number for bot answer chooseing
int TrivTmRand = 0;										// Trivia - Random timer for the bot clicking on answer
int t_rows;												// Trivia - Getting the number of trivia questions (total rows in sql db)
float pricePercentage = 1.15;	
float priceHalf = 0.5;
float botHousePercentage = 1.35;
float botPriceMustBuy = 0.95;
float botPriceMaxRent = 0.05;
int Nflag[28] = { 0 };									// Negotiations - Properties which are offered by the initiating player 
int Nflag2[28] = { 0 };									// Negotiations - Properties which are desired by the initiating player 
int NegOfferMini[8] = { 0 };							// Negotiations - Array containing maximum 8 properties offered by the initiating player
int NegReceiveMini[8] = { 0 };							// Negotiations - Array containing maximum 8 properties desired by the initiating player
int NegSelectedProperty = 0;							// Negotiations - Indicator for the card number to show on screen (Upon clicking on the mini card)
int neg_stage = 0;										// Negotiations - Stage indicator (0 = offer, 1 = player choose, 2 = receive)
int neg_offer = 0, neg_receive = 0;						// Negotiations - Stage money (offer, receive)
int trans_index = 0;									// Negotiations - Index for the current free slot in the Transaction struct
int trans_id = 0;										// Negotiations - Indicator for the currently "seen" transaction that the user needs to approve / reject
int neg_player_array[3] = { 0 };						// Negotiations - Array containing the token number for the players besides the current player
int neg_selected_p = 0;									// Negotiations - The selected player to negotiate with
int num_offer_prop = 0, num_receive_prop = 0;			// Negotiations - Indicators for the number of properties on both the sides of the transaction
int turnStateBackup = 0;								// ESC MENU - Saving the turnState variable for pausing the game and going to ESC menu
int timerBackup = 0;									// ESC MENU - Saving the timer also
int price = 0, once = 0, card, flag = 0, owner = 0, clearClick = 0, Load_Once = 1;
int loadRows = zeroCheck;

// MySQL DB Connection Parameters
static char *opt_host_name = "localhost";				// HOST
static char *opt_user_name = "root";					// USERNAME
static char *opt_password = "";							// PASSWORD
static char *opt_socket_name = NULL;					// SOCKET NAME
static char *opt_db_name = "projectmonopo";				// DATABASE NAME
static unsigned int opt_port_num = 3306;				// PORT
static unsigned int opt_flags = 0;						// CONNECTION FLAGS
MYSQL *conn = mysql_init(NULL);							// POINTER TO CONNECTION HANDLER & INITIALIZATION
MYSQL_RES *res;											// HOLDS THE RESULT SET
MYSQL_ROW row;

// FMOD Library variables for music playback
FMOD_RESULT			result;
Sound				*sound1, *sound2, *sound3, *sound4;
Channel				*channel = 0, *channel2 = 0, *channel3 = 0;
System				*sys = NULL;
bool				Paused;
float				volume;

// Functions declarations
bool initOpenGL();
void showFPS(GLFWwindow* window);
void getCommunityChest();
void getChance();
void getGoStatus(int Gostate, bool Restrictionsbycards);
void logPrint(int log);
void createLogFile();
void pay(int player, int money);
void auction(int scase, int sum);
void drawHouseHotel();
void loan(int scase);
void save();
void load(int gameid);
void drawTexture(vec3 pos, vec3 size, int texture, int mesh);
void movePlayer();
void endTurn();
void load_Textures(int stage);
void freeLists();
void restartGame();
void tokenChange(int player, int direction);
void buy();
void sell();
void skip();
void removePlayer();
void botAuction();
void updateHighScores(const char *name, int points, int money, int rounds);
int CheckOwnership(char *Color, int player, int mode);
int removeDebt(int money);
int getMaxRent();
int botNegotiation(int mode);
int completeGroup(int pos, int player);

Transaction* checkNegOffer(Transaction *head, int mode);
Transaction* createNegTrans(Transaction *head, int p_receive_id);
Transaction* removeNegTrans(Transaction *head);
Transaction* removeNegTrans(Transaction *head, int id);
Transaction* returnNegOffer(Transaction *head, int direction);
Transaction* acceptOffer(Transaction *head);

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode);
void glfw_onFramebufferSize(GLFWwindow* window, int width, int height);
void glfw_onMouseClick(GLFWwindow* window, int button, int action, int mods);
void glfw_onMouseMove(GLFWwindow* window, double posX, double posY);
void glfw_onWindowIconify(GLFWwindow* window, int iconified);
#include "Main.h"

int main()
{
	if (!initOpenGL())	
		cout << "Whoops! an error occured!" << endl;
	
	double lastTime = glfwGetTime();
	orbitCamera.setPosition(vec3(0.0f, 18.0f, 0.05f)); // Orbit Camera Position

	/////////////////////////////////
	/// For testing purposes only ///
	/////////////////////////////////
	properties[1].Owner = 1;
	properties[1].House_Count = 3;
	properties[6].Owner = 2;
	properties[6].House_Count = 2;
	properties[11].Owner = 2;
	properties[11].Got_Hotel = true;
	properties[24].Owner = 1;
	properties[24].House_Count = 1;
	properties[31].Owner = 2;
	properties[31].House_Count = 3;
	properties[39].Owner = 1;
	properties[39].Got_Hotel = true;
	//////////////////////////////////

	// Main loop
	while (!glfwWindowShouldClose(gWindow))		// We stay in this loop as long as the window does not close
	{
		showFPS(gWindow);

		double currentTime = glfwGetTime();
		double deltaTime = currentTime - lastTime;

		// Poll for and process events
		glfwPollEvents();

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Create the View matrix
		view = orbitCamera.getViewMatrix();
			
		// Create the projection matrix
		projection = glm::perspective(glm::radians(60.0f), (float)gWindowWidth / (float)gWindowHeight, 0.1f, 100.0f);
		
		// Must be called BEFORE setting uniforms because setting uniforms is done
		// on the currently active shader program.
		shaderProgram.use();

		// Pass the matrices to the shader
		shaderProgram.setUniform("view", view);
		shaderProgram.setUniform("projection", projection);

		switch (gameState)
		{
			// gameState = -1 - Loading Screen
			case -1:
			{
				static int LoadCounter = 0;

				// Draw load image
				if (LoadCounter == zeroCheck) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(0);
				}
				if (LoadCounter == 1) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(1);
				}			
				if (LoadCounter == 2) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(2);
				}
				if (LoadCounter == 3) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(3);
				}
				if (LoadCounter == 4) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(4);
				}
				if (LoadCounter == 5) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(5);
				}
				if (LoadCounter == 6) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(6);
				}
				if (LoadCounter == 7) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(7);
				}
				if (LoadCounter == 8) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(8);
				}
				if (LoadCounter == 9) {
					drawTexture(vec3(-3.0f, 1.0f, 0.3f), vec3(13.0f, 0.1f, 10.0f), 1, 0);
					load_Textures(9);
				}

				LoadCounter++;
			} break;

			// gameState = 0 - Main Menu
			case 0:
			{
				// Draw main menu
				drawTexture(vec3(-4.0f, 1.0f, 0.3f), vec3(18.5f, 0.1f, 10.0f), 46, 0);

			} break;

			// gameState = 1 - Settings Menu
			case 1:
			{
				// Draw settings menu
				if (NumberofPlayers == 2)
					drawTexture(vec3(-4.0f, 1.0f, 0.3f), vec3(18.5f, 0.1f, 10.0f), 49, 0);
				else if (NumberofPlayers == 3)
					drawTexture(vec3(-4.0f, 1.0f, 0.3f), vec3(18.5f, 0.1f, 10.0f), 54, 0);
				else if (NumberofPlayers == 4)
					drawTexture(vec3(-4.0f, 1.0f, 0.3f), vec3(18.5f, 0.1f, 10.0f), 55, 0);

				// Draw Players Tokens + Icons (Human / Bot)
				if (NumberofPlayers >= 2)
				{
					// Player 1
					drawTexture(vec3(-10.4f, 1.2f, -3.0f), vec3(1.3f, 0.3f, 1.5f), 92, 0);
					drawTexture(vec3(-10.4f, 1.2f, 1.8f), vec3(1.3f, 0.3f, 2.0f), 72 + pToken[0], 0);

					// Player 2
					if (pIcon[1])
						drawTexture(vec3(-3.6f, 1.2f, -3.0f), vec3(1.3f, 0.3f, 1.5f), 92, 0);
					else drawTexture(vec3(-3.6f, 1.2f, -3.0f), vec3(1.3f, 0.3f, 1.5f), 93, 0);
					drawTexture(vec3(-3.6f, 1.2f, 1.8f), vec3(1.3f, 0.3f, 2.0f), 72 + pToken[1], 0);

					if (NumberofPlayers >= 3)
					{
						// Player 3
						if (pIcon[2])
							drawTexture(vec3(3.1f, 1.2f, -3.0f), vec3(1.3f, 0.3f, 1.5f), 92, 0);
						else drawTexture(vec3(3.1f, 1.2f, -3.0f), vec3(1.3f, 0.3f, 1.5f), 93, 0);
						drawTexture(vec3(3.1f, 1.2f, 1.8f), vec3(1.3f, 0.3f, 2.0f), 72 + pToken[2], 0);

						// Player 4
						if (NumberofPlayers == 4) {
							if (pIcon[3])
								drawTexture(vec3(9.9f, 1.2f, -3.0f), vec3(1.3f, 0.3f, 1.5f), 92, 0);
							else drawTexture(vec3(9.9f, 1.2f, -3.0f), vec3(1.3f, 0.3f, 1.5f), 93, 0);
							drawTexture(vec3(9.9f, 1.2f, 1.8f), vec3(1.3f, 0.3f, 2.0f), 72 + pToken[3], 0);
						}
					}
				}

				vec3 spacing;
				vec3 post = vec3(-11.9f, 1.1f, -5.7f);
				vec3 posq[4] = { post, 
								 post + vec3(6.9f, 0.0f, 0.0f),
								 post + vec3(13.8f, 0.0f, 0.0f),
								 post + vec3(20.1f, 1.0f, 0.35f) };
				vec3 scl = vec3(0.27f, 0.0f, 0.4f) - vec3(0.09f, 0.0f, 0.11f);

				// Drawing the text for the players
				for (int i = 0; i < NumberofPlayers; i++) {
					spacing = vec3(0.3f, 0.0f, 0.0f);
					for (int j = 0; j < (int)strlen(pNames[i]); j++) {
						if (pNames[i][j] >= 'A' && pNames[i][j] <= 'Z')
							drawTexture(posq[i] + spacing, scl, 160 + (pNames[i][j] - 'A'), 0);
						else if (pNames[i][j] >= 'a' && pNames[i][j] <= 'z')
							drawTexture(posq[i] + spacing, scl, 160 + (pNames[i][j] - 'a'), 0);
						else if (pNames[i][j] == ' ')
							drawTexture(posq[i] + spacing, scl, 190, 0);

						spacing += vec3(0.3f, 0.0f, 0.0f);
					}
				}

			} break;

			// gameState = 2 - New Game Game Play
			case 2:
			{
				// Drawing the Board
				drawTexture(vec3(-2.0f, 0.0f, 0.0f), vec3(10.0f, 0.1f, 10.0f), 41, 0);
				
				// Drawing the Table
				drawTexture(vec3(0.0f, -11.65f, -4.0f), vec3(20.0f, 10.0f, 20.0f), 84, 2);
				
				// Drawing the Floor
				drawTexture(vec3(0.0f, -11.65f, 0.0f), vec3(12.0f, 1.0f, 12.0f), 85, 3);
				
				// Drawing the Brick Walls
				for (int j = 0; j < 4; j++) {
					if (j == zeroCheck)
						drawTexture(vec3(-60.0f, 8.0f, 0.0f), vec3(0.5f, 4.0f, 12.0f), 81, 5);
					if (j == 1)
						drawTexture(vec3(0.0f, 8.0f, 60.0f), vec3(12.0f, 4.0f, 0.5f), 81, 6);
					if (j == 2)
						drawTexture(vec3(60.0f, 8.0f, 0.0f), vec3(0.5f, 4.0f, 12.0f), 81, 5);
					if (j == 3)
						drawTexture(vec3(0.0f, 8.0f, -60.0f), vec3(12.0f, 4.0f, 0.5f), 81, 6);
				}

				// Drawing the Players
				for (int j = 0; j < NumberofPlayers; j++)
					drawTexture(Players[j].getPLoc(), vec3(0.5f, 0.5f, 0.5f), 94, 6 + Players[j].getToken());
				
				vec3 spacing;
				vec3 scl = vec3(0.27f, 0.0f, 0.4f) - vec3(0.09f, 0.0f, 0.11f);

				if (turnState != 2) {
					// Drawing the side player indicator
					for (int i = 0, j = 0; j < NumberofPlayers; j++) {
						vec3 post = vec3(-15.0f, 1.1f, -7.0f + 4.2f*j);
						// BG
						if (currentPlayer == Players[j].getID())
							drawTexture(vec3(-15.0f, 0.0f, -7.0f + j * 4.5f), vec3(4.0f, 0.2f, 2.0f), 245, 0);
						else drawTexture(vec3(-15.0f, 0.0f, -7.0f + j * 4.5f), vec3(4.0f, 0.2f, 2.0f), 244, 0);

						// Name:
						// Drawing the text for the players
						spacing = vec3(0.3f, 0.0f, 0.0f);
						//char pTemp[10] = Players[j].getName();
						for (int f = 0; f < (int)strlen(pNames[j]); f++) {
							if (pNames[j][f] >= 'A' && pNames[j][f] <= 'Z')
								drawTexture(post + spacing, scl, 160 + (pNames[j][f] - 'A'), 0);
							else if (pNames[j][f] >= 'a' && pNames[j][f] <= 'z')
								drawTexture(post + spacing, scl, 160 + (pNames[j][f] - 'a'), 0);
							else if (pNames[j][f] == ' ')
								drawTexture(post + spacing, scl, 190, 0);

							spacing += vec3(0.3f, 0.0f, 0.0f);
						}

						// Money:
						spacing = vec3(0.5f, 0.0f, 0.7f);

						for (int t = 0; t < 4; t++) {
							// Displaying the player money
							int tempMoney = This_Player.getMoney();
							int Money[4] = { 0 };
							int spc = 0.0f;
							int k = 3;

							while (tempMoney) {
								Money[k] = tempMoney % 10;
								tempMoney /= 10;
								k--;
							}

							k = 0;

							// Display money numbers
							for (int j = 0; j < 4; j++) {
								drawTexture(post + spacing + vec3(spc, 0.2f, 0.0f), vec3(0.23f, 0.0f, 0.27f), 63 + Money[k++], 0);
								spc += 1.0f;
							}
						}

						// Properties:
						for (int t = 0; t < 4; t++) {
							// Displaying the player money
							spacing = vec3(0.5f, 0.0f, 1.7f);
							int tempProp = This_Player.getProperties();
							int Prop[2] = { 0 };
							int spc = 0.0f;
							int k = 2;

							while (tempProp) {
								Prop[k] = tempProp % 10;
								tempProp /= 10;
								k--;
							}

							k = 0;

							// Display Properties numbers
							for (int j = 0; j < 2; j++) {
								drawTexture(post + spacing + vec3(spc, 0.2f, 0.0f), vec3(0.23f, 0.0f, 0.27f), 63 + Prop[k++], 0);
								spc += 1.0f;
							}
						}

						// Displaying the player token
						spacing = vec3(-1.0f, 0.0f, -0.5f);
						drawTexture(post + spacing + vec3(0.0f, 0.1f, 0.0f), vec3(0.7f, 0.0f, 0.7f), 72 + Players[j].getToken(), 0);

					}
				}


				// Drawing the houses / hotels on the board
				drawHouseHotel();
				
				// turnState = 0 - Before dice roll
				if (turnState == zeroCheck)
				{
					// Going back to board top view
					// Camera Position
					orbitCamera.setPosition(vec3(0.0f, 18.0f, 0.05f));

					// Camera lookAt
					orbitCamera.setLookAt(vec3(0.0f, 0.0f, 0.0f));

					// Display proper massage
					logPrint(1);

					// If the current player is a computer, draw a computer turn massage and make him roll the dice 
					if (This_Player.getIsHuman() == false) {

						if (timer >= 300)
							drawTexture(vec3(0.0f, 1.0f, 5.5f), vec3(1.6f, 0.0f, 1.0f), 237, 0);
						else
							RandButton = true;
					}

					// Else, drawing the roll dice button for the player to click on
					else if (Dicesum == zeroCheck && RandButton == false && timer > 0 && This_Player.getVacationState() == false)
						drawTexture(vec3(0.0f, 1.0f, 5.5f), vec3(1.6f, 0.0f, 1.0f), 138, 0);

					// Drawing the dice
					if ((timer == zeroCheck || RandButton == true) && This_Player.getVacationState() == false)
					{
						// Randomizing every second
						if (Dicefrm % 60 == zeroCheck)
							for (int j = 0; j < 2; j++)
								Dice[j] = rand() % 6 + 1;

						// Drawing the relevent number
						drawTexture(vec3(-2.5f, 1.0f, 0.0f), vec3(1.0f, 0.2f, 1.0f), 55 + Dice[0], 4);
						drawTexture(vec3(-2.5f, 1.0f, 0.0f) + vec3(5, 0, 0), vec3(1.0f, 0.2f, 1.0f), 55 + Dice[1], 4);

						if (Dicefrm > 1)
							Dicefrm--;
						else
						{
							Dicesum = Dice[0] + Dice[1];
							
							// Display proper massage
							logPrint(3);

							RandButton = false;
							turnState = 1;
							memset(allow_print, true, sizeof(allow_print));

							if (Dice[0] == Dice[1]) {
								flagdouble++;

								// Display proper massage
								logPrint(4);
							}

							if (flagdouble == 3) {
								flagdouble = 0;
								memset(Dice, 0, sizeof(Dice));

								// Go to jail
								This_Player.setPLoc(propertyPos[30][This_Player.getID() - 1]);
								This_Player.setJailTime(1);
								This_Player.setPosition(11);
							}
						}
					}

					// If the player is in a vacation
					if (This_Player.getVacationState() == true) {

						// Display proper massage
						logPrint(2);

						// Drawing the card
						drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 149, 0);

						// Drawing the Skip button
						drawTexture(vec3(0.0f, 1.0f, 5.5f), vec3(1.6f, 0.0f, 1.0f), 143, 0);

						if (vacationTimer == zeroCheck) {
							turnState = 3;
							SkipIt = false;
							This_Player.setVacationState(false);
							memset(allow_print, true, sizeof(allow_print));
						}

						vacationTimer--;
					}

					// If the player is currently in jail AND he's got at least 1 get out of jail card
					if (This_Player.getJailTime() > 0 && This_Player.getCardOutJail() > 0) {
						drawTexture(vec3(3.1f, 0.0f, 2.0f), vec3(1.6f, 0.0f, 1.0f), 91, 0);
						getoutbutton = 1;
					}
				}

				// turnState = 1 - Progression on the board
				if (turnState == 1)
				{
					// Calling the player advancment function
					movePlayer();

					// If the current player is not in Jail
					if (This_Player.getJailTime() == zeroCheck)
					{
						// Continues to advance on the board (if he needs to)
						if (frm == timer11 && Dicesum != zeroCheck) {
							PlayerMove = true;
							oneTimeCordDiff = false;
						}
						
						// Else, go to turnstate 2 (Landing)
						if (Dicesum == zeroCheck)
						{
							Dicefrm = timer2;
							turnState = 2;
							memset(allow_print, true, sizeof(allow_print));
						}
					}

					else
					{
						// Display proper massage
						logPrint(5);
						
						// If the current player is in Jail for 3 turns, he gets out automatically
						if (This_Player.getJailTime() == 4) {
							// Display proper massage
							logPrint(6);
							This_Player.setJailTime(0);
						}

						// If the current player rolled double, he gets out of jail
						if (Dice[0] == Dice[1] && Dice[0] != 0) {
							// Display proper massage
							logPrint(7);
							This_Player.setJailTime(0);
							flagdouble = 0;
						}
						else This_Player.setJailTime(This_Player.getJailTime() + 1);

						turnState = 3;
						SkipIt = false;
						memset(allow_print, true, sizeof(allow_print));
					}
				}

				// Landed on a field
				if (turnState == 2)
				{
					// Since the player token are not landing on the same spot, we set a universal line for every one of them
					vec3 camPos = This_Player.getPLoc();

					// Changing camera position and lookat target according to property location; RandValue 17 changes to top view for the trivia state
					if (RandValue != 17) {
						
						// Top properties row view
						if (This_Player.getPosition() >= 1 && This_Player.getPosition() <= 10) {
							camPos[2] = -8.5f;
							orbitCamera.setPosition(camPos + vec3(0.0f, 10.0f, -3.0f));
							orbitCamera.setLookAt(camPos + vec3(0.0f, 0.0f, 2.0f));
						}

						// Right properties row view
						else if (This_Player.getPosition() >= 11 && This_Player.getPosition() <= 20) {
							camPos[0] = 8.4f;
							orbitCamera.setPosition(camPos + vec3(3.0f, 10.0f, 0.0f));
							orbitCamera.setLookAt(camPos + vec3(-2.0f, 0.0f, 0.0f));
						}

						// Buttom properties row view
						else if (This_Player.getPosition() >= 21 && This_Player.getPosition() <= 30) {
							camPos[2] = 7.779f;
							orbitCamera.setPosition(camPos + vec3(0.0f, 10.0f, 3.0f));
							orbitCamera.setLookAt(camPos + vec3(0.0f, 0.0f, -2.0f));
						}

						// Left properties row view
						else if (This_Player.getPosition() >= 31 && This_Player.getPosition() <= 40) {
							camPos[0] = -7.779f;
							orbitCamera.setPosition(camPos + vec3(-3.0f, 10.0f, 0.0f));
							orbitCamera.setLookAt(camPos + vec3(2.0f, 0.0f, 0.0f));
						}
					}

					// Getting the card position
					card = This_Player.getPosition();

					// Price assessment:
					int price = zeroCheck;

					// Changing timers according to the interaction that about to happen
					if (timer == zeroCheck && SkipIt == false) {
						if (Current_Property.Category >= 0 && Current_Property.Category <= 2) {
							if (Current_Property.Owner == This_Player.getID() || Current_Property.Owner == zeroCheck)
								timer = timer1;
							else timer = timer2;
						}
						else timer = timer2;

						SkipIt = true;
					}

					// If time has run out, go to next turn
					if (timer == zeroCheck) {
						turnState = 3;
						SkipIt = false;
						memset(allow_print, true, sizeof(allow_print));
						Payed = false;
					}  

					// Determining the model required
					if (This_Player.getPosition() >= 1 && This_Player.getPosition() <= 10) {
						Mod = 15;
						MoIndex = 0;
					}
					else if (This_Player.getPosition() >= 11 && This_Player.getPosition() <= 20) {
						Mod = 16;
						MoIndex = 1;
					}
					else if (This_Player.getPosition() >= 21 && This_Player.getPosition() <= 30) {
						Mod = 17;
						MoIndex = 2;
					}
					else if (This_Player.getPosition() >= 31 && This_Player.getPosition() <= 40) {
						Mod = 18;
						MoIndex = 3;
					}

					// Drawing the property card we landed upon
					// If the property is a buyable one
					if (Current_Property.Category >= 0 && Current_Property.Category <= 2)
					{
						// Draw property card
						drawTexture(camPos + ModPos[MoIndex][0], ModScl[MoIndex][0], card, Mod);

						// The property belong to someone
						if (Current_Property.Owner != 0)
						{
							// The property belong to the current player
							if (Current_Property.Owner == This_Player.getID())
							{
								// Display proper massage
								logPrint(8);

								// If there are no houses
								if (Current_Property.House_Count == zeroCheck) {

									// If the current player is a human
									if (This_Player.getIsHuman() == true) {

										// Draw skip button
										drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);

										if (dropDir == zeroCheck)
											// Draw buy a house button
											drawTexture(camPos + ModPos[MoIndex][2], ModScl[MoIndex][1], 133, Mod);

										if (dropDir == zeroCheck)
											// Draw sell the property button
											drawTexture(camPos + ModPos[MoIndex][3], ModScl[MoIndex][1], 140, Mod);
									}

									// Else, a computer
									else {

										// NEED TO DO: Always add houses?
										int max = getMaxRent();
										if (This_Player.getMoney() >= (max + (int)(max * 0.05)))
											buy();
									}
								}

								// If there is at least 1 houses and less then 4
								else if (Current_Property.House_Count >= 1 && Current_Property.House_Count <= 3) {

									// If the current player is a human
									if (This_Player.getIsHuman() == true) {

										// Draw skip button
										drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);

										if (dropDir == zeroCheck)
											// Draw buy a house button
											drawTexture(camPos + ModPos[MoIndex][2], ModScl[MoIndex][1], 133, Mod);

										if (dropDir == zeroCheck)
											// Draw sell a house button
											drawTexture(camPos + ModPos[MoIndex][3], ModScl[MoIndex][1], 142, Mod);
									}

									// Else, a computer
									else {

										// NEED TO DO: Always add houses?
										int max = getMaxRent();
										if (This_Player.getMoney() >= (max + (int)(max * 0.05)))
											buy();
									}
								}

								// If there is an hotel
								else if (Current_Property.Got_Hotel == true) {

									// If the current player is a human
									if (This_Player.getIsHuman() == true) {

										// Draw skip button
										drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);

										if (dropDir == zeroCheck)
											// Draw sell a hotel button
											drawTexture(camPos + ModPos[MoIndex][3], ModScl[MoIndex][1], 141, Mod);
									}

									// Else, a computer
									else {

										// NEED TO DO: When will he sell his hotel? does he need to? MONEY??
									}
								}

								// If there are 4 houses and no hotel
								else if (Current_Property.House_Count == 4)
								{
									// If the current player is a human
									if (This_Player.getIsHuman() == true) {

										// Draw skip button
										drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);

										// If the player possess all properties of this same color group (requirement for building an hotel)
										if (CheckOwnership(Current_Property.Color, currentPlayer, 1) == 1)

											if (dropDir == zeroCheck)
												// Draw buy a hotel button
												drawTexture(camPos + ModPos[MoIndex][2], ModScl[MoIndex][1], 132, Mod);

										if (dropDir == zeroCheck)
											// Draw sell a house
											drawTexture(camPos + ModPos[MoIndex][3], ModScl[MoIndex][1], 142, Mod);
									}
									
									// Else, a computer
									else {

										// NEED TO DO: Will always upgrade to hotel? GOT MONEY??
										// If the player possess all properties of this same color group (requirement for building an hotel)
										if (CheckOwnership(Current_Property.Color, currentPlayer, 1) == 1) {
											int max = getMaxRent();
											if (This_Player.getMoney() >= (max + (int)(max * 0.05)))
												buy();
										}
									}
								}
							}

							// The property does not belong to the current player
							else
							{
								// Displaying proper massage
								logPrint(9);

								// If the current player is a human
								if (This_Player.getIsHuman() == true) {

									// Draw skip button
									drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);
								}

								// If the property is a street
								if (Current_Property.Category == zeroCheck) {
									if (Payed == false) {

										// If the property has an hotel
										if (Current_Property.Got_Hotel == true)
											price = Current_Property.With_House[4];

										// If not, add rent amount according to the number of houses present on the property 
										else if (Current_Property.House_Count > 0)
											price = Current_Property.With_House[Current_Property.House_Count - 1];

										// Else, player does not have any houses or hotel
										else price = Current_Property.Rent_Price;

										// If the player has all the property of this Color group
										if (CheckOwnership(Current_Property.Color, Current_Property.Owner, 1) == 1)
											// Double the money
											price *= 2;
									}
								}

								// If the property is a railroad
								else if (Current_Property.Category == 1) {

									// Rent tax according to how many railroads properties the player own
									price = 25 * CheckOwnership(Current_Property.Color, Current_Property.Owner, 2);
								}

								// If the property is a company (Electric / Water Company)
								else if (Current_Property.Category == 2) {

									// If the player has both companies, price is 10 times as shown on dice
									if (CheckOwnership(Current_Property.Color, Current_Property.Owner, 1) == 1)
										price = (Dice[0] + Dice[1]) * 10;

									// If not, price is 4 times as shown on dice
									else price = (Dice[0] + Dice[1]) * 4;
								}

								int k = 3;
								float xShift = 0.0f, zShift = 0.0f;
								float tShift = 0.0f, t2Shift = 0.0f;

								// Getting the tax amount
								if (!globalDebt) {
									globalDebt = price;
									// Displaying the rent tax the player needs to pay
									if (price != 0) {
										while (price) {
											showPrice[k] = price % 10;
											price /= 10;
											k--;
										}
									}
								}

								k = 0;

								// Displaying tax amount
								if (globalDebt != 0) {
									for (int j = 0; j < 4; j++) {
										drawTexture(camPos + ModPos[4][MoIndex] + vec3(xShift, 0.0f, zShift), ModScl[4][0], 63 + showPrice[k++], Mod);
										if (MoIndex == zeroCheck)
											xShift -= 0.4f;
										if (MoIndex == 1)
											zShift -= 0.4f;
										if (MoIndex == 2)
											xShift += 0.4f;
										if (MoIndex == 3)
											zShift += 0.4f;
									}
								}

								// If no trivia cards, take payment straight away
								if (This_Player.getTrivia() == zeroCheck) {
									// Taking payment
									if (Payed == false) {
										pay(This_Player.getID(), -globalDebt);
										pay(Current_Property.Owner, globalDebt);
										Payed = true;
									}
								}
								else if (globalDebt) {
									if (MoIndex == zeroCheck) {
										t2Shift = 1.0f;
										tShift = 1.8f;
									}
									if (MoIndex == 1) {
										t2Shift = 1.8f;
										tShift = -1.0f;
									}
									if (MoIndex == 2) {
										t2Shift = -1.0f;
										tShift = -1.8f;
									}
									if (MoIndex == 3) {
										t2Shift = -1.8f;
										tShift = 1.0f;
									}

									// Display it
									drawTexture(camPos + ModPos[4][MoIndex] + vec3(xShift + tShift, 0.0f, zShift + t2Shift), ModScl[MoIndex][1], 243, Mod);

									if (This_Player.getIsHuman() == false) {
										if (This_Player.getMoney() >= globalDebt * pricePercentage) {
											This_Player.setTrivia(This_Player.getTrivia() - 1);
											turnState = 3;
											SkipIt = false;
											memset(allow_print, true, sizeof(allow_print));
											Payed = false;

											// Display proper massage
											logPrint(32);
										}
									}

									if (timer == 1) {
										if (Payed == false) {
											pay(This_Player.getID(), -globalDebt);
											pay(Current_Property.Owner, globalDebt);
											Payed = true;
										}
									}
								}
							}
						}

						// The property does not belong to anyone
						else
						{
							// Display proper massage
							logPrint(10);

							// If the current player is a human
							if (This_Player.getIsHuman() == true) {

								// Draw skip button
								drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);

								// Draw buy the property
								drawTexture(camPos + ModPos[MoIndex][2], ModScl[MoIndex][1], 131, Mod);
							}

							// Else, a computer
							else {

								// If this is the player first round 
								if (This_Player.getRoundCount() == 1)
									buy();

								// Check if theres a point to buying the property
								else if (This_Player.getRoundCount() > 1) {
									int max = getMaxRent();
									int belongtobot = 0, belongtoplayer = 0; // count 
									int botid = This_Player.getID();
									string currentcolor = Current_Property.Color;
									for (int i = 0; i < 40; i++)
									{
										// find same color to check ownership
										if (currentcolor == properties[i].Color)
										{
											//check owner
											if (properties[i].Owner == botid)
											{
												belongtobot++;
											}
											else if (properties[i].Owner != botid && properties[i].Owner != 0)
											{
												belongtoplayer++;
											}
										}
									}
									// if there is more property belong to the bot he will buy anyway
									if (belongtobot > belongtoplayer)
										buy();
									// if there is less property belong to the bot he will check if he can meet the conditions
									else
										int max = getMaxRent();
									if (This_Player.getMoney() >= (max + (int)(max * 0.05)))
										buy();
								}
							}
						}
					}

					// If the property is a chance / community Chest
					else if (Current_Property.Category == 3 || Current_Property.Category == 4)
					{
						// Getting a random number to pick a card
						if (flag == zeroCheck) {
							if (Current_Property.Category == 3)
								RandValue = rand() % 16 + 1;
							else RandValue = rand() % 17 + 1;
							flag = 1;
						}

						// If we need to go to the trivia state
						if (RandValue == 17) {
							turnState = 9;

							// Going back to board top view
							// Camera Position
							orbitCamera.setPosition(vec3(0.0f, 18.0f, 0.05f));

							// Camera lookAt
							orbitCamera.setLookAt(vec3(0.0f, 0.0f, 0.0f));
						}

						// Else, its any other card
						else {

							// Calling the corrosponding function 
							if (once == zeroCheck && timer == 120) {
								if (Current_Property.Category == 3)
									getChance();
								else if (Current_Property.Category == 4)
									getCommunityChest();
							}

							// Draw Chance OR Community Chest Card (3 = Chance, 4 = Community Chest)
							if (Current_Property.Category == 3 && RandValue != 17) {
								drawTexture(camPos + ModPos[MoIndex][0], vec3(4.0f, 0.0f, 2.5f), 114 + RandValue, Mod);
								// Display proper massage
								logPrint(30);
							}
							else if (Current_Property.Category == 4) {
								drawTexture(camPos + ModPos[MoIndex][0], vec3(4.0f, 0.0f, 2.5f), 97 + RandValue, Mod);
								// Display proper massage
								logPrint(31);
							}
						}
					}

					// If the property is a tax field
					else if (Current_Property.Category == 5)
					{
						// Drawing the card
						drawTexture(camPos + ModPos[MoIndex][0], ModScl[MoIndex][0], card, Mod);

						// If the current player is a human
						if (This_Player.getIsHuman() == true) {
							// Drawing the Skip button
							drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);
						}

						// Displaying the rent tax the player needs to pay
						if (price != 0) {
							int amount[4] = { 0 }, k = 3;

							while (price) {
								amount[k] = price % 10;
								price /= 10;
								k--;
							}

							float xShift = 0.0f;
							for (int j = 0; j < 4; j++) {
								drawTexture(vec3(-0.4f + xShift, 1.0f, 5.6f), vec3(0.27f, 0.0f, 0.4f), 63 + amount[j], 0);
								xShift += 0.5;
							}
						}

						// Notify the player of the fine amount and get payment (no card)
						// Position 5 = Income Tax
						if (This_Player.getPosition() == 5){
							if (Payed == false) {
								pay(This_Player.getID(), -200);
								Payed = true;
							}

							// Displaying proper massage
							logPrint(13);
						}

						// Position 5 = Luxury Tax
						if (This_Player.getPosition() == 39) {
							if (Payed == false) {
								pay(This_Player.getID(), -75);
								Payed = true;
							}
							
							// Displaying proper massage
							logPrint(14);
						}
					}

					// Else, Landed on a special area
					else if (Current_Property.Category == 6)  
					{
						// If the player landed on "FREE PARKING"
						if (card == 21) {

							// Displaying proper massage
							logPrint(16);

							// Drawing the card
							drawTexture(camPos + ModPos[MoIndex][0], ModScl[MoIndex][0], card, Mod);

							// If the current player is a human
							if (This_Player.getIsHuman() == true) {

								// Drawing the Skip button
								drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);
							}

							//drawTexture(modelPositionGP[8], modelScaleGP[8], 149, 0);
							This_Player.setVacationState(true);
						}

						// Else, if we landed on "Go to Jail"
						else if (card == 31) {

							// If time has run out
							if (timer == 1) {

								// Go to jail
								This_Player.setPLoc(propertyPos[10][This_Player.getID() - 1]);
								This_Player.setJailTime(1);
								This_Player.setPosition(11);

								// Displaying proper massage
								logPrint(15);

								endTurn();
							}

							// Drawing the card
							drawTexture(camPos + ModPos[MoIndex][0], ModScl[MoIndex][0], card, Mod);

							// If the current player is a human
							if (This_Player.getIsHuman() == true) {

								// Drawing the Skip button
								drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);
							}
						}

						// Else, if we landed on "Just Visiting"
						else if (card == 11) {

							// Displaying proper massage
							logPrint(19);

							// Drawing the card
							drawTexture(camPos + ModPos[MoIndex][0], ModScl[MoIndex][0], card, Mod);

							// If the current player is a human
							if (This_Player.getIsHuman() == true) {
								// Drawing the Skip button
								drawTexture(camPos + ModPos[MoIndex][1], ModScl[MoIndex][1], 143, Mod);
							}
						}
					}
				}

				// turnState = 3 - Decision time
				// Player Screen
				if (turnState == 3)
				{
					// Going back to board top view
					// Camera Position
					orbitCamera.setPosition(vec3(0.0f, 18.0f, 0.05f));

					// Camera lookAt
					orbitCamera.setLookAt(vec3(0.0f, 0.0f, 0.0f));

					float spc = 0.0f;

					// Automate this stage, less frame time
					if (SkipIt == false) {

						// If the current player is a human
						if (This_Player.getIsHuman() == true)
							timer = timer3;
						
						// Else, a computer
						else {
							timer = timer6;
							// Negotiation starts only in round 2
							if (This_Player.getRoundCount() > 1) {
								// If the bot has negotiations offered to him, approve or reject
								botNegotiation(1);

								// The bot check for possible negotiation offers
								botNegotiation(2);
							}
						}

						SkipIt = true;
					}

					// If time has run out, go to next turn
					if (timer == zeroCheck) {
						endTurn();
						SkipIt = false;
						memset(allow_print, true, sizeof(allow_print));
					}

					// Display proper massage
					logPrint(17);

					// Drawing the player home screen
					// If the player has taken a loan
					if (This_Player.getTakeLoan()) {

						// If the player is a human 
						if (This_Player.getIsHuman() == true)
							drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 47, 0);  
						else
							drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 239, 0);

						// Displaying the player loan sum
						int l = This_Player.getSumLoan();
						int tempLoan = l;
						int Loan[4] = { 0 }, k = 3;

						while (tempLoan) {
							Loan[k] = tempLoan % 10;
							tempLoan /= 10;
							k--;
						}
						
						k = 0;

						// Displaying the loan sum
						for (int j = 34; j < 38; j++) {
							drawTexture(vec3(-1.33f + spc, 1.0f, 0.6f), vec3(0.25f, 0.0f, 0.4f), 63 + Loan[k++], 0);
							spc += 0.97f;
						}

						// Displaying the player loan round
						drawTexture(vec3(0.14f, 1.0f, 3.1f), vec3(0.25f, 0.0f, 0.4f), 63 + This_Player.getLoanCurrentRound(), 0);
					}

					// If the player has not taken a loan
					else {

						// If the player is a human 
						if (This_Player.getIsHuman() == true)
							drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 48, 0);

						// Else, a computer
						else
							drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 238, 0);
					}

					// If the player is a human, show the screen buttons
					if (This_Player.getIsHuman() == true) {

						// Displaying End Turn Button
						drawTexture(vec3(5.0f, 1.0f, 0.3f), vec3(1.6f, 0.0f, 1.0f), 134, 0);

						// Displaying Loan Button
						drawTexture(vec3(5.0f, 1.0f, 5.5f), vec3(1.6f, 0.0f, 1.0f), 135, 0);

						// Displaying Negotiation Button
						drawTexture(vec3(1.5f, 1.0f, 5.5f), vec3(1.6f, 0.0f, 1.0f), 136, 0);

						// If an offer has been made to the player, notify him (via exclamation mark near the negotiation button)
						if (checkNegOffer(t_Head, 1) != NULL)
							drawTexture(vec3(3.0f, 1.0f, 4.5f), vec3(0.5f, 0.1f, 0.5f), 148, 0);

						// Displaying Property Management Button
						drawTexture(vec3(-2.0f, 1.0f, 5.5f), vec3(1.6f, 0.0f, 1.0f), 137, 0);
					}

					// Displaying properties amount
					int tempProp = This_Player.getProperties();
					int Prop[2] = { 0 }, k = 1;
					spc = 0.0f;

					while (tempProp) {
						Prop[k] = tempProp % 10;
						tempProp /= 10;
						k--;
					}

					k = 0;

					// Display property numbers
					for (int i = 0; i < 2; i++) {
						drawTexture(vec3(4.02f + spc, 1.0f, -4.8f), vec3(0.25f, 0.0f, 0.4f), 63 + Prop[k++], 0);
						spc += 1.0f;
					}

					// Displaying total jail free cards
					drawTexture(vec3(0.16f, 1.0f, -1.7f), vec3(0.25f, 0.0f, 0.4f), 63 + This_Player.getCardOutJail(), 0);
					
					// Displaying the player Token
					drawTexture(vec3(-3.75f, 1.0f, -4.9f), vec3(1.04f, 0.0f, 1.04f), 72 + This_Player.getToken(), 0);

					// Displaying total trivia cards
					drawTexture(vec3(4.53f, 1.0f, -1.7f), vec3(0.25f, 0.0f, 0.4f), 63 + This_Player.getTrivia(), 0);
					
					// Displaying the player money
					int tempMoney = This_Player.getMoney();
					int Money[4] = { 0 };
					spc = 0.0f;
					k = 3;

					while (tempMoney) {
						Money[k] = tempMoney % 10;
						tempMoney /= 10;
						k--;
					}
					
					k = 0;

					// Display money numbers
					for (int j = 0; j < 4; j++) {
						drawTexture(vec3(-1.33f + spc, 1.0f, -4.8f), vec3(0.25f, 0.0f, 0.4f), 63 + Money[k++], 0);
						spc += 0.97f;
					}
				}

				// Auction Time (Bidding)
				if (turnState == 4)
				{
					if (ExitBid == 1)
					{
						// Backing up the current player inorder to continue after the bid
						if (!CurrentPlayerBack)
							CurrentPlayerBack = currentPlayer;

						// Saving the current card to display regardless of the other players position
						if (!CurCard)
							CurCard = This_Player.getPosition();

						// Initial bid price = Property Buy Price - 20%
						if (!bidPrice)
							bidPrice = (int)(properties[CurCard - 1].Buy_Price * 0.8);
						int tempPrice = bidPrice;
						int BidPrice[4] = { 0 }, k = 3;

						// Seperating the price into digits for loading the images
						while (tempPrice) {
							BidPrice[k] = tempPrice % 10;
							tempPrice /= 10;
							k--;
						}

						// Displaying the Auction Constants (Bid screen + Player Token + Property Card + Bid Price (divided))
						// Bid Screen
						// If the current player is a human
						if (This_Player.getIsHuman() == true)
							drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 50, 0);
						else {
							drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 241, 0);
							botAuction();
						}

						// Drawing the player Token
						drawTexture(vec3(1.35f, 1.0f, -1.8f), vec3(1.04f, 0.0f, 1.04f), 72 + This_Player.getToken(), 0);
						
						// Drawing the current property card
						drawTexture(vec3(-3.0f, 1.0f, -0.0f), vec3(2.5f, 0.0f, 3.0f), CurCard, 0);

						// Drawing the bid price
						float distance = 0.0f;
						for (int j = 0; j < 4; j++) {
							drawTexture(vec3(-4.08f + distance, 1.0f, 4.4f), vec3(0.25f, 0.0f, 0.4f), 63 + BidPrice[j], 0);
							distance += 0.97f;
						}
					}

					// Outcome of bidding in the auction
					if (ExitBid == 2 || ExitBid == 3)
					{
						// Automate this stage, less frame time
						if (SkipIt == false) {
							timer = timer2;
							SkipIt = true;
						}

						// 2 = Bid Won, 3 = Bid Unsold 
						if (ExitBid == 2)
							drawTexture(vec3(-0.5f, 1.0f, -0.5f), vec3(4.0f, 0.0f, 2.5f), 89, 0);
						else if (ExitBid == 3)
							drawTexture(vec3(-0.5f, 1.0f, -0.5f), vec3(4.0f, 0.0f, 2.5f), 88, 0);

						// Display proper massage
						if (ExitBid == 2)
							logPrint(18);
						else if (ExitBid == 3)
							logPrint(18);

						// Upon massage timeout, procced to the next state
						if (timer == zeroCheck)
						{
							turnState = 3;
							SkipIt = false;
							currentPlayer = CurrentPlayerBack;
							CurrentPlayerBack = 0;
							memset(PlayerInBid, 0, sizeof(PlayerInBid));
							memset(allow_print, true, sizeof(allow_print));
							bidPrice = 0;
							ExitBid = 0;
							aucCompOnly = false;
							botChoiceDelay = false;
						}
					}
					
					// Checking to see if any human players left in the auction. If not, skip
					int flag = 0;

					for (int i = 0; i < NumberofPlayers; i++)
						if (Players[i].getIsHuman() == true)
							if (PlayerInBid[i] == zeroCheck)
								flag = 1;

					if (flag == zeroCheck)
						if (aucCompOnly == false)
							aucCompOnly = true;
				}

				// Debt need to be cleared
				if (turnState == 5)
				{
					// Automate this stage, less frame time
					if (timer == zeroCheck && SkipIt == false) {
						timer = timer2;
						SkipIt = true;
					}

					// If time has run out, go to top view and show loan taking
					if (timer == zeroCheck) {
						turnState = 0;
						SkipIt = false;
						memset(allow_print, true, sizeof(allow_print));
					}
				}

				// turnState = 6 - Loan
				if (turnState == 6)
				{
					// Automate this stage, less frame time
					if (timer == zeroCheck && SkipIt == false) {
						timer = timer4;
						SkipIt = true;
					}

					// If time has run out, go to next turn
					if (timer == zeroCheck) {
						turnState = 0;
						SkipIt = false;
						memset(allow_print, true, sizeof(allow_print));
					}

					// Initial loan price
					if (!loanprice)
						loanprice = 500;

					int tempPrice = loanprice, tempInterest;
					int Loanprice[4] = { 0 }, k = 3, LoanInterest[4] = { 0 };

					while (tempPrice) {
						Loanprice[k] = tempPrice % 10;
						tempPrice /= 10;
						k--;
					}

					k = 3;
					loanInterest = (int)(loanprice * Interest + roundcount * 100);
					tempInterest = loanInterest;
				
					while (tempInterest) {
						LoanInterest[k] = tempInterest % 10;
						tempInterest /= 10;
						k--;
					}

					// Drawing the loan screen
					drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 45, 0);

					// Displaying the loan price
					float xShift = 0.0f;
					for (int j = 0; j < 4; j++) {
						if (j == 3)
							drawTexture(vec3(-1.77f + xShift, 0.5f, -4.35f), vec3(0.27f, 1.1f, 0.4f), 63 + Loanprice[j], 0);
						else
							drawTexture(vec3(-1.77f + xShift, 0.0f, -4.5f), vec3(0.27f, 1.1f, 0.4f), 63 + Loanprice[j], 0);
						xShift += 1.32f;
					}

					// Displaying the loan price with interest
					xShift = 0.0f;
					for (int j = 0; j < 4; j++) {
						if (j == 3)
							drawTexture(vec3(-1.78f + xShift, 0.5f, -1.15f), vec3(0.27f, 1.1f, 0.4f), 63 + LoanInterest[j], 0);
						else
							drawTexture(vec3(-1.78f + xShift, 0.0f, -1.2f), vec3(0.27f, 1.1f, 0.4f), 63 + LoanInterest[j], 0);
						xShift += 1.32f;
					}

					// Drawing the round count
					drawTexture(vec3(3.05f, 0.5f, 2.0f), vec3(0.27f, 1.1f, 0.4f), 63 + roundcount, 0);
				}

				// turnState = 7 - Negotiation
				if (turnState == 7)
				{
					// Drawing the screen
					if (neg_stage == zeroCheck)
						drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 95, 0);
					else if (neg_stage == 1)
						drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 97, 0);
					else if (neg_stage == 2)
						drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 96, 0);

					if (neg_stage == zeroCheck || neg_stage == 2)
					{
						// Stage 0 = offer stage
						if (neg_stage == zeroCheck)
						{
							// Drawing checkboxes for all the properties
							for (int i = 0; i < 28; i++)
							{
								// If the property is owned by the selected player to negotiate with
								if (properties[NFlagRealIndex[i]].Owner == This_Player.getID())
								{
									// If the property is not selected 
									if (Nflag[i] == zeroCheck)
										drawTexture(modelOwnerNum[i] - vec3(0.10f, 0.0f, 0.05f), vec3(0.3f, 0.0f, 0.3f), 145, 0);

									// If the property is selected
									else if (Nflag[i] == 1)
										drawTexture(modelOwnerNum[i] - vec3(0.10f, 0.0f, 0.05f), vec3(0.3f, 0.0f, 0.3f), 146, 0);
								}
							}
						}

						// Stage 2 - receive stage
						if (neg_stage == 2)
						{
							// Drawing checkboxes for all the properties
							for (int i = 0; i < 28; i++)
							{
								// If the property is owned by the selected player to negotiate with
								if (properties[NFlagRealIndex[i]].Owner == neg_selected_p)
								{
									// If the property is not selected 
									if (Nflag2[i] == zeroCheck)
										drawTexture(modelOwnerNum[i] - vec3(0.10f, 0.0f, 0.05f), vec3(0.3f, 0.0f, 0.3f), 145, 0);

									// If the property is selected
									else if (Nflag2[i] == 1)
										drawTexture(modelOwnerNum[i] - vec3(0.10f, 0.0f, 0.05f), vec3(0.3f, 0.0f, 0.3f), 147, 0);
								}
							}
						}

						// Temporary offer sum variables
						int NegPrice[4] = { 0 }, k = 3;
						int tempPrice;

						if (neg_stage == zeroCheck)
							tempPrice = neg_offer;
						else if (neg_stage == 2)
							tempPrice = neg_receive;

						// Seperating the price into digits for loading the images
						while (tempPrice) {
							NegPrice[k] = tempPrice % 10;
							tempPrice /= 10;
							k--;
						}

						// Drawing the price
						float xShift = 0.4f;
						for (int j = 0; j < 4; j++) {
							drawTexture(vec3(-5.4f + xShift, 1.0f, 4.8f), vec3(0.2f, 0.0f, 0.3f), 63 + NegPrice[j], 0);
							xShift += 0.4f;
						}
					}

					// Middle stage - Selecting the player to negotiate with
					else if (neg_stage == 1)
					{
						vec3 t_spc = vec3 (0.0f, 0.0f, 0.0f);
						int p_index = 0;
						
						for (int i = 0; i < NumberofPlayers; i++) {
							if (i != (currentPlayer - 1)) {
								drawTexture(vec3(1.35f, 1.0f, -1.8f) + t_spc - vec3(5.3f, 0.0f, 0.0f), vec3(1.5f, 0.1f, 1.5f), 203 + Players[i].getToken(), 0);
								t_spc += vec3(4.0f, 0.0f, 0.0f);
								neg_player_array[p_index] = i + 1;
								p_index++;
							}
						}
					}	
				}

				// Property Management Screen
				if (turnState == 8)
				{
					// Drawing the screen
					drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 51, 0);

					// Drawing the return button
					drawTexture(vec3(-4.5f, 1.0f, 5.5f), vec3(1.6f, 0.0f, 1.0f), 144, 0);

					// Drawing Numbers
					for (int i = 0; i < 28; i++)
						drawTexture(modelOwnerNum[i] - vec3(0.10f, 0.0f, 0.05f), vec3(0.3f, 0.0f, 0.3f), 63 + properties[NFlagRealIndex[i]].Owner , 0);
				}

				// Trivia Screen 
				if (turnState == 9)
				{
					int qrand = rand() % t_rows;
					char test[70];
					char q[4][20];
					char c_answer[20];
					int linePos = 38;
					vec3 spacing = vec3(0.3f, 0.0f, 0.0f);
					vec3 posq = vec3(-5.55f, 1.0f, 3.6f);
					vec3 posa = posq - vec3(0.0f, 0.0f, -1.5f);
					vec3 scl = vec3(0.18f, 0.0f, 0.29f);
					
					// Getting the trivia question & answers
					if (oneTimeTriv == true) {
						strcpy_s(test, 70, trivia[qrand].question);
						strcpy_s(c_answer, 20, trivia[qrand].correctanswer);
						for (int i = 0; i < 4; i++)
							strcpy_s(q[i], 20, trivia[qrand].answer[i]);
						
						// Dramatic music
						result = sys->playSound(sound2, 0, false, &channel2);
						if (result != FMOD_OK)
							printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));

						TrivRand = rand() % 4 + 1;
						TrivTmRand = rand() % 12 + 3;

						oneTimeTriv = !oneTimeTriv;
					}

					// Drawing the Trivia Screen
					drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 53, 0);

					// Making sure to not cut a word in the middle at the end of the line
					while (test[linePos--] != ' ');
						linePos += 2;

					// Drawing the text for the question
					for (int j = 38, i = 0; i < (int)strlen(test); i++) {
						if (linePos == i) {
							posq += vec3(0.0f, 0.0f, 0.5f);
							spacing = vec3(0.3f, 0.0f, 0.0f);
						}

						if (test[i] >= 'A' && test[i] <= 'Z')
							drawTexture(posq + spacing, scl, 160 + (test[i] - 'A'), 0);
						else if (test[i] >= 'a' && test[i] <= 'z')
							drawTexture(posq + spacing, scl, 160 + (test[i] - 'a'), 0);
						else if (test[i] >= '0' && test[i] <= '9')
							drawTexture(posq + spacing, scl, 63 + (test[i] - '0'), 0);
						else if (test[i] == '"')
							drawTexture(posq + spacing, scl, 186, 0);
						else if (test[i] == ',')
							drawTexture(posq + spacing, scl, 187, 0);
						else if (test[i] == '.')
							drawTexture(posq + spacing, scl, 188, 0);
						else if (test[i] == '?')
							drawTexture(posq + spacing, scl, 189, 0);
						else if (test[i] == ' ')
							drawTexture(posq + spacing, scl, 190, 0);
						else if (test[i] == '-')
							drawTexture(posq + spacing, scl, 191, 0);

						spacing += vec3(0.3f, 0.0f, 0.0f);
					}

					// Drawing the text for the answers
					for (int i = 0; i < 4; i++) 
					{
						spacing = vec3(0.3f, 0.0f, 0.0f);

						for (int j = 0; j < 20; j++) {
							if (q[i][j] >= 'A' && q[i][j] <= 'Z')
								drawTexture(posa + spacing, scl, 160 + (q[i][j] - 'A'), 0);
							else if (q[i][j] >= 'a' && q[i][j] <= 'z')
								drawTexture(posa + spacing, scl, 160 + (q[i][j] - 'a'), 0);
							else if (q[i][j] >= '0' && q[i][j] <= '9')
								drawTexture(posa + spacing, scl, 63 + (q[i][j] - '0'), 0);
							else if (q[i][j] == '"')
								drawTexture(posq + spacing, scl, 186, 0);
							else if (q[i][j] == ',')
								drawTexture(posq + spacing, scl, 187, 0);
							else if (q[i][j] == '.')
								drawTexture(posq + spacing, scl, 188, 0);
							else if (q[i][j] == '?')
								drawTexture(posq + spacing, scl, 189, 0);
							else if (q[i][j] == ' ')
								drawTexture(posq + spacing, scl, 190, 0);
							else if (q[i][j] == '-')
								drawTexture(posq + spacing, scl, 191, 0);

							spacing += vec3(0.3f, 0.0f, 0.0f);
						}

						// Location jumps for the answers
						if (i == zeroCheck)
							posa += vec3(0.0f, 0.0f, 0.9f);
						if (i == 1)
							posa += vec3(6.5f, 0.0f, -0.9f);
						if (i == 2)
							posa += vec3(0.0f, 0.0f, 0.9f);
					}

					// If the current player is a computer, choose a random answer at a random time
					if (This_Player.getIsHuman() == false && TrivTmRand == tm) {
						ans = TrivRand;
						draws = false;
					}

					// Drawing the Hovered answer which the mouse stand upon
					if (draws) {

						timert--;
						if (timert % 60 == zeroCheck && tm != 0) tm--;
						
						if ((lastMousePos.x >= 658 && lastMousePos.y >= 785) && (lastMousePos.x <= 960 && lastMousePos.y <= 826))
							drawTexture(vec3(-1.36f, 0.11f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 192, 0);
						else if ((lastMousePos.x >= 658 && lastMousePos.y >= 834) && (lastMousePos.x <= 960 && lastMousePos.y <= 872))
							drawTexture(vec3(-1.36f, 0.11f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 195, 0);
						else if ((lastMousePos.x >= 991 && lastMousePos.y >= 785) && (lastMousePos.x <= 1298 && lastMousePos.y <= 826))
							drawTexture(vec3(-1.36f, 0.11f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 198, 0);
						else if ((lastMousePos.x >= 991 && lastMousePos.y >= 834) && (lastMousePos.x <= 1298 && lastMousePos.y <= 872))
							drawTexture(vec3(-1.36f, 0.11f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 201, 0);
					}

					// Drawing the Timer countdown
					drawTexture(vec3(-0.55f, 1.2f, 1.9f), vec3(0.57f, 0.0f, 0.9f), (150 + (tm / 10)), 0);
					drawTexture(vec3( 1.05f, 1.2f, 1.9f), vec3(0.57f, 0.0f, 0.9f), (150 + (tm % 10)), 0);

					// Drawing the selected answer (correct or wrong)
					if (!draws) {

						int ct_location[4] = { 193, 196, 199, 202 };
						int wt_location[4] = { 194, 197, 200, 203 };

						// If correct
						if (strcmp(c_answer, q[ans - 1]) == zeroCheck) {
							drawTexture(vec3(-1.36f, 0.11f, -0.1f), vec3(7.25f, 0.1f, 7.25f), ct_location[ans - 1], 0);
							if (!t_verdict) {
								t_verdict = 1;
								result = sys->playSound(sound3, 0, false, &channel3);
							}
						}

						// Else, wrong
						else {
							drawTexture(vec3(-1.36f, 0.11f, -0.1f), vec3(7.25f, 0.1f, 7.25f), wt_location[ans - 1], 0);
							if (!t_verdict) {
								t_verdict = -1;
								result = sys->playSound(sound4, 0, false, &channel3);
							}
						}	
					}

					// Exisiting Trivia Screen
					if (tm == zeroCheck || t_verdict != 0) {

						// Stopping the dramatic music
						result = channel2->setPaused(true);

						if (t_timer > 0)
							t_timer--;
						if (t_timer == zeroCheck) {
							if (t_verdict == 1)
								This_Player.setTrivia(This_Player.getTrivia() + 1);
							else
								result = sys->playSound(sound4, 0, false, &channel3);

							// Reset Trivia variables
							oneTimeTriv = draws = true;
							timert = 1200;
							t_timer = 300;
							tm = 15;
							ans = 0;
							t_verdict = 0;
							TrivRand = 0;
							TrivTmRand = 0;

							SkipIt = false;
							turnState = 3;

							// Stopping the win / lose music
							result = channel3->setPaused(true);
						}
					}
				}

				// turnState = 10 - Player negotiation offers
				if (turnState == 10)
				{
					if (c_ptr != NULL) {
						// Temporary offer sum variables
						int NegPrice[4] = { 0 }, k = 3, i = 0;
						int tempPrice;
						vec3 p_space = vec3(0.4f, 0.0f, 0.0f); 
						vec3 icon_spc = vec3(0.0f, 0.0f, 0.0f);

						// Drawing the screen
						drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 43, 0);

						// Drawing the offering player name
						const char *text = Players[c_ptr->p_offer_id - 1].getName().c_str();
						vec3 spacing = vec3(0.0f, 0.0f, 0.0f);
						vec3 pos_b = vec3(-0.7f, 1.0f, -3.0f);
						vec3 scale = vec3(0.2f, 0.0f, 0.3f);

						for (int i = 0; i < (int)strlen(text); i++) {

							if (*(text + i) >= 'A' && *(text + i) <= 'Z')
								drawTexture(pos_b + spacing, scale, 160 + (*(text + i) - 'A'), 0);
							else if (*(text + i) >= 'a' && *(text + i) <= 'z')
								drawTexture(pos_b + spacing, scale, 160 + (*(text + i) - 'a'), 0);
							else if (*(text + i) == '"')
								drawTexture(pos_b + spacing, scale, 186, 0);
							else if (*(text + i) == ',')
								drawTexture(pos_b + spacing, scale, 187, 0);
							else if (*(text + i) == '.')
								drawTexture(pos_b + spacing, scale, 188, 0);
							else if (*(text + i) == '?')
								drawTexture(pos_b + spacing, scale, 189, 0);
							else if (*(text + i) == ' ')
								drawTexture(pos_b + spacing, scale, 190, 0);
							else if (*(text + i) == '-')
								drawTexture(pos_b + spacing, scale, 191, 0);

							spacing += vec3(0.4f, 0.0f, 0.0f);
						}

						// Seperating the price into digits for loading the images
						tempPrice = c_ptr->t_money_offer;
						while (tempPrice) {
							NegPrice[k] = tempPrice % 10;
							tempPrice /= 10;
							k--;
						}

						// Drawing the offered sum
						for (int j = 0; j < 4; j++) {
							drawTexture(vec3(-4.8f, 1.0f, -0.4f) + p_space, vec3(0.2f, 0.0f, 0.3f), 63 + NegPrice[j], 0);
							p_space += vec3(0.4f, 0.0f, 0.0f);
						}

						// Resetting variables
						memset(NegPrice, 0, sizeof(NegPrice));
						p_space = vec3(0.4f, 0.0f, 0.0f); 
						k = 3;

						// Seperating the price into digits for loading the images
						tempPrice = c_ptr->t_money_receive;
						while (tempPrice) {
							NegPrice[k] = tempPrice % 10;
							tempPrice /= 10;
							k--;
						}

						// Drawing the demanded sum
						for (int j = 0; j < 4; j++) {
							drawTexture(vec3(2.5f, 1.0f, -0.4f) + p_space, vec3(0.2f, 0.0f, 0.3f), 63 + NegPrice[j], 0);
							p_space += vec3(0.4f, 0.0f, 0.0f);
						}

						// Drawing the offered properties
						for (int k = 0; k < 28; k++)
						{
							if (c_ptr->t_prop_offer[k] == 1) {
								if (strcmp(properties[NFlagRealIndex[k]].Color, "Black") == zeroCheck)
									drawTexture(icon_spc + vec3(-5.4f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 212, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Blue") == zeroCheck)
									drawTexture(icon_spc + vec3(-5.4f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 213, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Brown") == zeroCheck)
									drawTexture(icon_spc + vec3(-5.4f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 214, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Green") == zeroCheck)
									drawTexture(icon_spc + vec3(-5.4f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 215, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Light_Blue") == zeroCheck)
									drawTexture(icon_spc + vec3(-5.4f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 216, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Orange") == zeroCheck)
									drawTexture(icon_spc + vec3(-5.4f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 217, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Purple") == zeroCheck)
									drawTexture(icon_spc + vec3(-5.4f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 218, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Red") == zeroCheck)
									drawTexture(icon_spc + vec3(-5.4f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 219, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Yellow") == zeroCheck)
									drawTexture(icon_spc + vec3(-5.4f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 220, 0);

								// Drawing the property number on the icon
								drawTexture(icon_spc + vec3(-5.5f, 1.3f, 2.7f), vec3(0.15f, 0.0f, 0.25f), 63 + ((properties[NFlagRealIndex[k]].Position - 1) / 10), 0);
								drawTexture(icon_spc + vec3(-5.15f, 1.3f, 2.7f), vec3(0.15f, 0.0f, 0.25f), 63 + ((properties[NFlagRealIndex[k]].Position - 1) % 10), 0);

								i++;
								num_offer_prop++;
								if (i == 4)
									icon_spc = vec3(0.0f, 0.0f, 1.2f);
								else
									icon_spc += vec3(1.2f, 0.0f, 0.0f);
							}
						}

						icon_spc = vec3(0.0f, 0.0f, 0.0f);
						i = 0;

						// Drawing the demanded properties
						for (int k = 0; k < 28; k++)
						{
							if (c_ptr->t_prop_receive[k] == 1) {
								if (strcmp(properties[NFlagRealIndex[k]].Color, "Black") == zeroCheck)
									drawTexture(icon_spc + vec3(1.7f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 212, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Blue") == zeroCheck)
									drawTexture(icon_spc + vec3(1.7f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 213, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Brown") == zeroCheck)
									drawTexture(icon_spc + vec3(1.7f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 214, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Green") == zeroCheck)
									drawTexture(icon_spc + vec3(1.7f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 215, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Light_Blue") == zeroCheck)
									drawTexture(icon_spc + vec3(1.7f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 216, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Orange") == zeroCheck)
									drawTexture(icon_spc + vec3(1.7f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 217, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Purple") == zeroCheck)
									drawTexture(icon_spc + vec3(1.7f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 218, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Red") == zeroCheck)
									drawTexture(icon_spc + vec3(1.7f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 219, 0);
								else if (strcmp(properties[NFlagRealIndex[k]].Color, "Yellow") == zeroCheck)
									drawTexture(icon_spc + vec3(1.7f, 1.0f, 2.7f), vec3(0.5f, 0.1f, 0.5f), 220, 0);

								// Drawing the property number on the icon
								drawTexture(icon_spc + vec3(1.55, 1.3f, 2.7f), vec3(0.15f, 0.0f, 0.25f), 63 + ((properties[NFlagRealIndex[k]].Position - 1) / 10), 0);
								drawTexture(icon_spc + vec3(1.9f, 1.3f, 2.7f), vec3(0.15f, 0.0f, 0.25f), 63 + ((properties[NFlagRealIndex[k]].Position - 1) % 10), 0);

								i++;
								num_receive_prop++;
								if (i == 4)
									icon_spc = vec3(0.0f, 0.0f, 1.2f);
								else
									icon_spc += vec3(1.2f, 0.0f, 0.0f);
							}
						}

						// Saving the property numbers for the traded properties to show a large property card upon mouse click
						for (int i = 0, k = 0, j = 0; i < 28; i++) {
							if (c_ptr->t_prop_offer[i] == 1) {
								NegOfferMini[k] = NFlagRealIndex[i];
								k++;
							}

							if (c_ptr->t_prop_receive[i] == 1) {
								NegReceiveMini[j] = NFlagRealIndex[i];
								j++;
							}
						}

						// Displaying the enlarged property card
						if (NegSelectedProperty != 0)
						{
							if (NegSelectedProperty > 0)
								drawTexture(vec3(-0.5f, 1.4f, -1.0f), vec3(4.5f, 0.0f, 5.0f), NegOfferMini[NegSelectedProperty - 1] + 1, 0);
							else if (NegSelectedProperty < 0)
								drawTexture(vec3(-0.5f, 1.4f, -1.0f), vec3(4.5f, 0.0f, 5.0f), NegReceiveMini[(-1)*NegSelectedProperty - 1] + 1, 0);
						}

					}
					else 
						turnState = 3;
				}
				
				// turnState 11 - Game End
				if (turnState == 11) 
				{
					// If time has run out, go to the high scores table 
					if (timer == zeroCheck) {
						// Points calculation: 50 per property, 20 per hotel, 10 per house.
						int points = 0;

						for (int i = 0; i < 40; i++) {
							if (properties[i].Owner == This_Player.getID()) {
								points += 50;
								if (properties[i].Category == zeroCheck) {
									if (properties[i].Got_Hotel == true)
										points += 20;
									if (properties[i].House_Count != 0)
										points += 10 * properties[i].House_Count;
								}
							}
						}

						// Update the highscore if needed
						updateHighScores(Players[0].getName().c_str(), points, Players[0].getMoney(), Players[0].getRoundCount());
						gameState = 4;
					}

					// Draw winner screen
					drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 242, 0);

					// Drawing the offering player name
					string str = Players[0].getName();
					const char *text = str.c_str();
					vec3 spacing = vec3(0.0f, 0.0f, 0.0f);
					vec3 pos_b = vec3(-1.0f, 1.2f, -3.35f);
					vec3 scale = vec3(0.2f, 0.0f, 0.3f);

					for (int i = 0; i < (int)strlen(text); i++) {
						if (*(text + i) >= 'A' && *(text + i) <= 'Z')
							drawTexture(pos_b + spacing, scale, 160 + (*(text + i) - 'A'), 0);
						else if (*(text + i) >= 'a' && *(text + i) <= 'z')
							drawTexture(pos_b + spacing, scale, 160 + (*(text + i) - 'a'), 0);
						else if (*(text + i) == ' ')
							drawTexture(pos_b + spacing, scale, 190, 0);
						else if (*(text + i) == '-')
							drawTexture(pos_b + spacing, scale, 191, 0);

						spacing += vec3(0.4f, 0.0f, 0.0f);
					}
				}

				// turnState 999 - ESC Menu
				if (turnState == 999)
				{
					// Drawing the ESC menu
					drawTexture(vec3(-1.36f, 0.1f, -0.1f), vec3(7.25f, 0.1f, 7.25f), 229, 0);
				}
				
				if (timer > 0)
					timer--;

			} break;

			// gameState = 3 - Load Game Menu
			case 3:
			{
				// Drawing the Load Game Menu
				drawTexture(vec3(-4.0f, 1.0f, 0.3f), vec3(18.5f, 0.1f, 10.0f), 44, 0);

				int state = 0;
				float xmove = 1.8f, zmove = 0.0f, xd = 2.6f;
				char query[2000], date[11] = { 0 };

				sprintf_s(query, sizeof(query), "SELECT * FROM `Savedgamesetting`");	// Making the query string
				state = mysql_query(conn, query);										// Executing it
				res = mysql_store_result(conn);											// Saving the result
				loadRows = (int)mysql_num_rows(res);											/* Casting is used because mysql_num_rows 
																						   return a 64bit integer(ulonglong) */

				// For each saved state:
				for (int i = 0; i < loadRows; i++) {
					row = mysql_fetch_row(res);
					sprintf_s(date, sizeof(date), "%s", row[7]);

					// Drawing Saved Game Button
					drawTexture(vec3(-9.6f + xmove, 1.2f, -5.5f + zmove), vec3(6.0f, 0.0f, 1.0f), 139, 0);

					// Drawing Saved Game Number
					drawTexture(vec3(-11.7f + xmove, 1.3f, -5.5f + zmove - 0.03f), vec3(0.2f, 0.0f, 0.4f), 63 + i, 0);

					// Drawing Date
					for (int k = 0; k < 10; k++) 	{
						// Drawing Date Digits
						if (date[k] == '-')
							drawTexture(vec3(-11.7f + xmove + xd, 1.3f, -5.5f + zmove - 0.03f), vec3(0.2f, 0.0f, 0.4f), 62, 0);
						else
							drawTexture(vec3(-11.7f + xmove + xd, 1.3f, -5.5f + zmove - 0.03f), vec3(0.2f, 0.0f, 0.4f), 63 + (date[k] - '0'), 0);
						xd += 0.4f;
					}
					
					// Drawing Saved Game Number of players
					drawTexture(vec3(-11.7f + xmove + xd + 2.5, 1.3f, -5.5f + zmove - 0.03f), vec3(0.2f, 0.0f, 0.4f), 63 + atoi(row[1]), 0);

					xd = 2.6f;
					zmove += 2.5f;
					if (i == 4) 	{
						xmove += 12.7f;
						zmove -= 12.5;
					}
				}
			} break;

			// gameState = 4 - High Scores Screen
			case 4:
			{
				int i = 0;
				vec3 spacing = vec3(0.0f, 0.0f, 0.0f);
				vec3 charPos = vec3(-11.0f, 1.3f, -4.0f);
				vec3 charScale = vec3(0.25f, 0.0f, 0.4f);

				// Drawing the High Scores Screen
				drawTexture(vec3(-4.0f, 1.0f, 0.3f), vec3(18.5f, 0.1f, 10.0f), 90, 0);

				// CONNECT TO SQL, GET DATA FROM TABLE, COMPARE PLAYER RESULT, ADD HIM IF BETTER
				mysql_query(conn, "SELECT * FROM `High Score`");
				res = mysql_store_result(conn);

				while ((row = mysql_fetch_row(res))) {
					strcpy_s(highscore[i].name, 10, row[1]);
					highscore[i].points = atoi(row[2]);
					highscore[i].rounds = atoi(row[3]);
					highscore[i].money = atoi(row[4]);
					i++;
				}

				if (res != NULL)
					mysql_free_result(res);

				// Displaying each record in the high score sql table
				for (int j = 0; j < 10; j++) {
					if (strlen(highscore[j].name)) {
						// Drawing the player name
						const char *text = highscore[j].name;
						for (int i = 0; i < (int)strlen(text); i++) {
							if (*(text + i) >= 'A' && *(text + i) <= 'Z')
								drawTexture(charPos + spacing, charScale, 160 + (*(text + i) - 'A'), 0);
							else if (*(text + i) >= 'a' && *(text + i) <= 'z')
								drawTexture(charPos + spacing, charScale, 160 + (*(text + i) - 'a'), 0);
							else if (*(text + i) == '"')
								drawTexture(charPos + spacing, charScale, 186, 0);
							else if (*(text + i) == ',')
								drawTexture(charPos + spacing, charScale, 187, 0);
							else if (*(text + i) == '.')
								drawTexture(charPos + spacing, charScale, 188, 0);
							else if (*(text + i) == '?')
								drawTexture(charPos + spacing, charScale, 189, 0);
							else if (*(text + i) == ' ')
								drawTexture(charPos + spacing, charScale, 190, 0);
							else if (*(text + i) == '-')
								drawTexture(charPos + spacing, charScale, 191, 0);

							spacing += vec3(0.4f, 0.0f, 0.0f);
						}

						// Drawing the points
						int points = highscore[j].points;
						int p[4] = { 0 }, k = 3;
						vec3 digitPos = charPos + vec3(6.6f, 0.0f, 0.0f);
						spacing = vec3(0.0f, 0.0f, 0.0f);

						if (points != 0) {
							while (points) {
								p[k--] = points % 10;
								points /= 10;
							}
						}

						for (int i = 0; i < 4; i++) {
							drawTexture(digitPos + spacing, charScale, 63 + p[i], 0);
							spacing += vec3(0.5f, 0.0f, 0.0f);
						}

						// Drawing the rounds
						int rounds = highscore[j].rounds;
						memset(p, 0, sizeof(p));
						k = 3;
						digitPos += vec3(6.3f, 0.0f, 0.0f);
						spacing = vec3(0.0f, 0.0f, 0.0f);

						if (rounds != 0) {
							while (rounds) {
								p[k--] = rounds % 10;
								rounds /= 10;
							}
						}

						for (int i = 0; i < 4; i++) {
							drawTexture(digitPos + spacing, charScale, 63 + p[i], 0);
							spacing += vec3(0.5f, 0.0f, 0.0f);
						}
						
						// Drawing the money
						int money = highscore[j].money;
						memset(p, 0, sizeof(p));
						k = 3;
						digitPos += vec3(6.3f, 0.0f, 0.0f);
						spacing = vec3(0.0f, 0.0f, 0.0f);

						if (money != 0) {
							while (money) {
								p[k--] = money % 10;
								money /= 10;
							}
						}

						for (int i = 0; i < 4; i++) {
							drawTexture(digitPos + spacing, charScale, 63 + p[i], 0);
							spacing += vec3(0.5f, 0.0f, 0.0f);
						}

						spacing = vec3(0.0f, 0.0f, 0.0f);
						charPos += vec3(0.0f, 0.0f, 1.2f);
					}
				}

			} break;

			// gameState = 5 - Credits Screen
			case 5:
			{
				static float zRate = 0.0f;
				static int direction = 1;

				// Drawing the Credits Screen
				drawTexture(vec3(-4.0f, 1.0f, 0.3f), vec3(18.5f, 0.1f, 10.0f), 231, 0);

				// Drawing our names :)
				drawTexture(vec3(-1.0f, 1.1f, 5.5f - zRate), vec3(5.67f, 0.1f, 2.0f), 232, 0);

				if (direction == 1) {
					if (zRate < 10.0f)
						zRate += 0.01f;
					else direction = 0;
				}
				else if (direction == zeroCheck) {
					if (zRate > 0.0f)
						zRate -= 0.01f;
					else direction = 1;
				}

			} break;
		}

		// Swap front and back buffers
		glfwSwapInterval(1);
		glfwSwapBuffers(gWindow);
		lastTime = currentTime;

		result = sys->update();
		if (result != FMOD_OK)
			printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
	}

	// Releasing music
	result = sound1->release();

	// Closing mySQL connection
	mysql_close(conn);

	// Terminating glfw
	glfwTerminate();

	// Closing file pointers and streams
	logout.close();

	// Freeing allocated memory
	freeLists();

	return 0;
}

//-----------------------------------------------------------------------------
// Initialize GLFW and OpenGL
//-----------------------------------------------------------------------------
bool initOpenGL()
{
	srand((unsigned int)time(NULL));
	memset(allow_print, true, sizeof(allow_print));
	createLogFile();

	// CONNECTING TO THE SERVER
	if (!mysql_real_connect(conn, opt_host_name, opt_user_name, opt_password, opt_db_name, opt_port_num, opt_socket_name, opt_flags))
		logPrint(60);
	else
		logPrint(61);

	// Intialize GLFW 
	// GLFW is configured.  Must be called before calling any GLFW functions
	if (!glfwInit()) {
		// An error occured
		std::cerr << "GLFW initialization failed" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	// Setting the minimum OpenGL Major Version 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	// Setting the minimum OpenGL Minor Version .3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	// Forcing the appliCategoryion to create a core profile (cant use old methods)
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);	// We'll be using methods from v3.3 forward only, nothing earlier

	// if gFullscreen = TRUE, create a full screen window 
	if (gFullscreen) {
		GLFWmonitor* pMonitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* pVmode = glfwGetVideoMode(pMonitor);
		if (pVmode != NULL)
			gWindow = glfwCreateWindow(pVmode->width, pVmode->height, APP_TITLE, pMonitor, NULL);
	}
	else 
		gWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, APP_TITLE, NULL, NULL);
	
	if (gWindow == NULL) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	// Making the window the current open one so we can draw on it
	glfwMakeContextCurrent(gWindow);

	// Required. If not, may not set up OpenGL properly
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "GLEW initialization failed" << std::endl;
		glfwTerminate();
		return false;
	}

	// Music playback
	result = FMOD::System_Create(&sys);					// Create the main system object
	if (result != FMOD_OK)
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));

	result = sys->init(512, FMOD_INIT_NORMAL, 0);		// Initialize FMOD
	if (result != FMOD_OK)
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));

	result = sys->createSound("Sounds/Main_Theme.mp3", FMOD_DEFAULT, 0, &sound1);
	result = sys->createSound("Sounds/Effects/Trivia/Dramatic_music.mp3", FMOD_DEFAULT, 0, &sound2);
	result = sys->createSound("Sounds/Effects/Trivia/Correct_answer.mp3", FMOD_DEFAULT, 0, &sound3);
	result = sys->createSound("Sounds/Effects/Trivia/Wrong_answer.mp3", FMOD_DEFAULT, 0, &sound4);
	result = sys->playSound(sound1, 0, true, &channel);
	result = channel->setVolume(0.1f);
	if (result != FMOD_OK)
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));

	// Set the required callback functions
	glfwSetKeyCallback(gWindow, glfw_onKey);
	glfwSetMouseButtonCallback(gWindow, glfw_onMouseClick);
	glfwSetFramebufferSizeCallback(gWindow, glfw_onFramebufferSize);
	glfwSetCursorPosCallback(gWindow, glfw_onMouseMove);
	glfwSetWindowIconifyCallback(gWindow, glfw_onWindowIconify);
	//glfwSetScrollCallback(gWindow, glfw_onMouseScroll);

	// Hides and grabs cursor, unlimited movement
	glfwSetInputMode(gWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	// Responsible for the clear screen Color
	glClearColor(0.23f, 0.38f, 0.47f, 1.0f);	

	// Define the viewport dimensions
	glViewport(0, 0, gWindowWidth, gWindowHeight);
	glEnable(GL_DEPTH_TEST);
	shaderProgram.loadShaders("Shaders/basic.vert", "Shaders/basic.frag");

	// Restarting values for loading game
	restartGame();

	// First Screen Loading texture
	TextureArr[1].loadTexture("Textures/Loading/1.png", true);

	return true;
}

//-----------------------------------------------------------------------------
// Is called whenever a key is pressed/released via GLFW
//-----------------------------------------------------------------------------
void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode)
{	
	// Pausing the game and loading the ESC Menu
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS && (turnState == zeroCheck || turnState == 3 || turnState == 999) && gameState == 2) {
		
		if (turnState == 999) {
			turnState = turnStateBackup;
			timer = timerBackup;
			cout << "Game Unpaused!" << endl;
		}
		else {
			turnStateBackup = turnState;
			timerBackup = timer;
			turnState = 999;
			cout << "Game Paused!" << endl;
		}
	}

	// Pausing / Resuming background music
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		// Get the channel status (paused or not)
		channel->getPaused(&Paused);

		// If paused - play
		if (Paused) {
			result = channel->setPaused(false);
			result = channel->getVolume(&volume);
			if (result != FMOD_OK)
				printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));

			cout << "Background music ON, Volume: " << (int)((volume * 10.0f) / 1) << "0%" << endl;
		}

		// Else, pause
		else {
			result = channel->setPaused(true);
			if (result != FMOD_OK)
				printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));

			cout << "Background music OFF" << endl;
		}
	}

	// Volume Control UP for Ambient music
	if (key == GLFW_KEY_PAGE_UP && action == GLFW_PRESS)
	{
		// Getting paused status and volume
		channel->getPaused(&Paused);
		channel->getVolume(&volume);

		// If the music is paused OR the volume is already at 100% - do not increase volume
		if (!Paused && volume < 1.0f) {
			if (volume < 1.0f)
				channel->setVolume(volume + 0.1f);
			channel->getVolume(&volume);
			cout << "Volume increased to: " << (int)((volume * 10.0f) / 1) << "0%" << endl;
		}
	}

	// Volume Control DOWN for Ambient music
	if (key == GLFW_KEY_PAGE_DOWN && action == GLFW_PRESS)
	{
		// Getting paused status and volume
		channel->getPaused(&Paused);
		channel->getVolume(&volume);

		// If the music is paused OR the volume is 0 - do not decrease volume
		if (!Paused && volume > 0.1f) {
			if (volume > 0.0f)
				channel->setVolume(volume - 0.1f);
			channel->getVolume(&volume);
			if ((int)((volume * 10.0f) / 1) == zeroCheck)
				cout << "Volume muted" << endl;
			else
				cout << "Volume decreased to: " << (int)((volume * 10.0f) / 1) << "0%" << endl;
		}
	}

	// Writing characters to players names
	if (key >= GLFW_KEY_A && key <= GLFW_KEY_Z && action == GLFW_PRESS)
	{
		if (nEdit != -1) {
			if (strlen(pNames[nEdit]) < 9) {
				pNames[nEdit][pNamesIndex[nEdit]] = key;
				pNamesIndex[nEdit]++;
				pNames[nEdit][pNamesIndex[nEdit]] = '\0';
			}
		}
	}

	// Finishes Editing Mode
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
		nEdit = -1;

	// Removal of characters in player names
	if (key == GLFW_KEY_BACKSPACE && action == GLFW_PRESS)
	{
		if (nEdit != -1) {
			if (strlen(pNames[nEdit]) > 0) {
				pNames[nEdit][pNamesIndex[nEdit] - 1] = '\0';
				pNamesIndex[nEdit]--;
			}
		}
	}

	// Change to WireFrame Mode (displays only the lines of the textures and obj files)
	if (key == GLFW_KEY_F1 && action == GLFW_PRESS)
	{
		gWireframe = !gWireframe;
		if (gWireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	// Display Mouse Pointer Coordinates
	if (key == GLFW_KEY_EQUAL && action == GLFW_PRESS)
		cout << "X: " << lastMousePos[0] << ", Y: " << lastMousePos[1] << endl;

	// Clear the console screen
	if (key == GLFW_KEY_MINUS && action == GLFW_PRESS)
		//system("CLS");
		//func();
		This_Player.setTrivia(1);
	
	// Display Players Statistics
	if (key == GLFW_KEY_TAB && action == GLFW_PRESS) {
		cout << "\nCurrent Players: "<< endl;
		for (int i = 0; i < NumberofPlayers; i++) {
			cout << "Player " << Players[i].getID() << ", ";
			if (Players[i].getIsHuman())
				cout << "Human, ";
			else cout << "Bot, ";
			cout << Players[i].getName() << " ,Token: " << Players[i].getToken()
				 << ", Money: " << Players[i].getMoney() << ", Properties: " << Players[i].getProperties() << ", Round Count:" << Players[i].getRoundCount() << endl;
		}
		cout << "Current Player: " << currentPlayer << ". Total Players: " << NumberofPlayers << ". Dice Result: [" << Dice[0] << "][" << Dice[1] << "]" << endl;

		/*

		// Negotiation variables
		cout << endl 
			 << "Negotiation Variables:" << endl
			 << "Neg Stage:" << neg_stage << endl
			 << "Neg Offer Sum:" << neg_offer << endl
			 << "Neg Receive Sum:" << neg_receive << endl
			 << "Trans Index:" << trans_index << endl
			 << "Neg Selected Player:" << neg_selected_p << endl
			 << "Neg Player Array: [" << neg_player_array[0] << ", " << neg_player_array[1] << ", " << neg_player_array[2] << "]" << endl;

		*/
	}
	
	//// Getting orbitCamera values
	//if (glfwGetKey(gWindow, GLFW_KEY_C) == GLFW_PRESS) {
	//	glm::vec3 test = orbitCamera.getPosition();
	//	cout << endl << "Camera Position: " << test[0] << ", " << test[1] << ", " << test[2] << endl;

	//	test = orbitCamera.getTargetPos();
	//	cout << "Target Position (LookAt): " << test[0] << ", " << test[1] << ", " << test[2] << endl;
	//}

	//if (glfwGetKey(gWindow, GLFW_KEY_W) == GLFW_PRESS)
	//	orbitCamera.setPosition(vec3(0.1f, 0.0f, 0.0f));

	//if (glfwGetKey(gWindow, GLFW_KEY_S) == GLFW_PRESS)
	//	orbitCamera.setPosition(vec3(-0.1f, 0.0f, 0.0f));
}

//-----------------------------------------------------------------------------
// Is called whenever a mouse movement occur
//-----------------------------------------------------------------------------
void glfw_onMouseMove(GLFWwindow* window, double posX, double posY)
{
	lastMousePos.x = (float)posX;
	lastMousePos.y = (float)posY;
}

//-----------------------------------------------------------------------------
// Is called when the window is resized
//-----------------------------------------------------------------------------
void glfw_onFramebufferSize(GLFWwindow* window, int width, int height)
{
	gWindowWidth = width;
	gWindowHeight = height;
	glViewport(0, 0, gWindowWidth, gWindowHeight);
}

//-----------------------------------------------------------------------------
// Is called whenever a mouse button is clicked
//-----------------------------------------------------------------------------
void glfw_onMouseClick(GLFWwindow* window, int button, int action, int mods)
{
	// ------------ Main Menu Screen ------------ //
	if (gameState == zeroCheck && clearClick == zeroCheck)
	{
		// New Game Button
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 647 && lastMousePos.y >= 199) && (lastMousePos.x <= 1304 && lastMousePos.y <= 304)) {
			gameState = 1;
			NumberofPlayers = 2;
			tokenChange(NumberofPlayers - 1, 1);
		}

		// Load Game Button
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 625 && lastMousePos.y >= 346) && (lastMousePos.x <= 1326 && lastMousePos.y <= 451))
			gameState = 3;

		// High Score Button
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 622 && lastMousePos.y >= 492) && (lastMousePos.x <= 1330 && lastMousePos.y <= 599))
			gameState = 4;

		// Credits Button
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 732 && lastMousePos.y >= 639) && (lastMousePos.x <= 1218 && lastMousePos.y <= 745))
			gameState = 5;

		// Exit Button
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 784 && lastMousePos.y >= 786) && (lastMousePos.x <= 1164 && lastMousePos.y <= 892))
			glfwSetWindowShouldClose(window, GL_TRUE);

		clearClick = 1;
	}

	// ------------ Settings Screen ------------ //
	if (gameState == 1 && clearClick == zeroCheck)
	{
		// Play Button
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1410 && lastMousePos.y >= 888) && (lastMousePos.x <= 1677 && lastMousePos.y <= 973)) {
			gameState = 2;
			for (int i = 0; i < NumberofPlayers; i++) {
				Players[i] = Player(pNames[i], pIcon[i], pToken[i], 1500, propertyPos[0][i]);
			}
		}

		// Go back button
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 275 && lastMousePos.y >= 888) && (lastMousePos.x <= 539 && lastMousePos.y <= 973)) {
			gameState = 0;
			NumberofPlayers = 2;
		}

		// Add player button
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 844 && lastMousePos.y >= 888) && (lastMousePos.x <= 963 && lastMousePos.y <= 973))
			if (NumberofPlayers >= 2 && NumberofPlayers < 4) {
				NumberofPlayers++;
				tokenChange(NumberofPlayers - 1, 1);
			}

		// Remove player button
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 992 && lastMousePos.y >= 888) && (lastMousePos.x <= 1117 && lastMousePos.y <= 973))
			if (NumberofPlayers > 2 && NumberofPlayers <= 4)
				NumberofPlayers--;

		// Player Token Change
		if (NumberofPlayers >= 2)
		{
			// First Player Token Left
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 266 && lastMousePos.y >= 609) && (lastMousePos.x <= 294 && lastMousePos.y <= 659)) {
				tokenChange(0, -1);
			}

			// First Player Token Right
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 485 && lastMousePos.y >= 609) && (lastMousePos.x <= 505 && lastMousePos.y <= 659)) {
				tokenChange(0, 1);
			}

			// First Player Name Edit
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 495 && lastMousePos.y >= 200) && (lastMousePos.x <= 540 && lastMousePos.y <= 240))
				nEdit = 0;

			// Second Player Token Left
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 652 && lastMousePos.y >= 609) && (lastMousePos.x <= 678 && lastMousePos.y <= 659)) {
				tokenChange(1, -1);
			}

			// Second Player Token Right
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 864 && lastMousePos.y >= 609) && (lastMousePos.x <= 889 && lastMousePos.y <= 659)) {
				tokenChange(1, 1);
			}

			// Second Player Icon Change
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 660 && lastMousePos.y >= 320) && (lastMousePos.x <= 684 && lastMousePos.y <= 365))
				pIcon[1] = !pIcon[1];

			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 870 && lastMousePos.y >= 320) && (lastMousePos.x <= 891 && lastMousePos.y <= 365))
				pIcon[1] = !pIcon[1];

			// Second Player Name Edit
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 867 && lastMousePos.y >= 200) && (lastMousePos.x <= 911 && lastMousePos.y <= 240))
				nEdit = 1;

			if (NumberofPlayers >= 3)
			{
				// Third Player Token Left
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1032 && lastMousePos.y >= 609) && (lastMousePos.x <= 1058 && lastMousePos.y <= 659))
					tokenChange(2, -1);

				// Third Player Token Right
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1243 && lastMousePos.y >= 609) && (lastMousePos.x <= 1270 && lastMousePos.y <= 659))
					tokenChange(2, 1);

				// Third Player Icon Change
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1035 && lastMousePos.y >= 320) && (lastMousePos.x <= 1060 && lastMousePos.y <= 365))
					pIcon[2] = !pIcon[2];

				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1252 && lastMousePos.y >= 320) && (lastMousePos.x <= 1276 && lastMousePos.y <= 365))
					pIcon[2] = !pIcon[2];

				// Third Player Name Edit
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1252 && lastMousePos.y >= 186) && (lastMousePos.x <= 1297 && lastMousePos.y <= 223))
					nEdit = 2;

				if (NumberofPlayers == 4)
				{
					// Fourth Player Token Left
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1418 && lastMousePos.y >= 609) && (lastMousePos.x <= 1445 && lastMousePos.y <= 659))
						tokenChange(3, -1);

					// Fourth Player Token Right
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1629 && lastMousePos.y >= 609) && (lastMousePos.x <= 1653 && lastMousePos.y <= 659))
						tokenChange(3, 1);

					// Fourth Player Icon Change
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1411 && lastMousePos.y >= 320) && (lastMousePos.x <= 1440 && lastMousePos.y <= 365))
						pIcon[3] = !pIcon[3];

					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1634 && lastMousePos.y >= 320) && (lastMousePos.x <= 1658 && lastMousePos.y <= 365))
						pIcon[3] = !pIcon[3];

					// Fourth Player Name Edit
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1630 && lastMousePos.y >= 184) && (lastMousePos.x <= 1678 && lastMousePos.y <= 224))
						nEdit = 3;
				}
			}
		}
	}

	// ------------ Game Play Screen ------------ //
	if (gameState == 2 && clearClick == zeroCheck)
	{
		// ---------- Before dice roll ---------- //
		if (turnState == zeroCheck)
		{
			// Throw dice button
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 892 && lastMousePos.y >= 771) && (lastMousePos.x <= 1066 && lastMousePos.y <= 880) && This_Player.getIsHuman() == true) {
				if (This_Player.getVacationState() == true)
					skip();
				else if (getoutbutton == 1) {
					// Display proper massage
					logPrint(21);
					getoutbutton = 0;
					This_Player.updateJailCard('-');
					This_Player.setJailTime(0);
					turnState = 3;
					SkipIt = false;
					memset(allow_print, true, sizeof(allow_print));
				}
				else
					RandButton = true;
			}
		}

		// --------- Landed on property --------- //
		if (turnState == 2 && clearClick == zeroCheck)
		{
			// ------- Buying / Selling property ------- //
			if (This_Player.getIsHuman() == true)
			{
				// Middle button = Skip
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 789 && lastMousePos.y >= 882) && (lastMousePos.x <= 1136 && lastMousePos.y <= 1043) && clearClick == zeroCheck)
					skip();

				// Left Button = Buy
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 423 && lastMousePos.y >= 882) && (lastMousePos.x <= 766 && lastMousePos.y <= 1043) && clearClick == zeroCheck && isDrop == false)
					buy();

				// Right Button = Sell
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1147 && lastMousePos.y >= 882) && (lastMousePos.x <= 1514 && lastMousePos.y <= 1043) && clearClick == zeroCheck && isDrop == false)
					sell();

				// Use trivia skip card
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 363 && lastMousePos.y >= 368) && (lastMousePos.x <= 661 && lastMousePos.y <= 478) && clearClick == zeroCheck && isDrop == false) {
					This_Player.setTrivia(This_Player.getTrivia() - 1);
					turnState = 3;
					SkipIt = false;
					memset(allow_print, true, sizeof(allow_print));

					// Display proper massage
					logPrint(32);
				}
			}
		}

		// ------------- Player Screen ------------- //
		if (turnState == 3 && clearClick == zeroCheck)
		{
			// If the current player is a human
			if (This_Player.getIsHuman() == true)
			{
				// Quit Game
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1193 && lastMousePos.y >= 660) && (lastMousePos.x <= 1249 && lastMousePos.y <= 717))
					removePlayer();

				// End turn
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1168 && lastMousePos.y >= 480) && (lastMousePos.x <= 1344 && lastMousePos.y <= 588))
					endTurn();

				// Go to Loan Screen
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1168 && lastMousePos.y >= 767) && (lastMousePos.x <= 1344 && lastMousePos.y <= 877))
				{
					// If the player has no active loan
					if (This_Player.getTakeLoan() == false) {
						turnState = 6;
						timer = timer5;	// 5 Min
						memset(allow_print, true, sizeof(allow_print));
					}

					// NEED TO WORK ON HOW TO SHOW THIS
					// Else, if he does
					else {
						drawTexture(vec3(1.5f, 1.2f, 5.5f), vec3(2.0f, 0.0f, 2.0f), 240, 0);
					}

					clearClick = 1;
				}

				// Go to Negotiation Screen
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 975 && lastMousePos.y >= 766) && (lastMousePos.x <= 1150 && lastMousePos.y <= 877)) {
					if ((c_ptr = checkNegOffer(t_Head, 1)) != NULL) {
						trans_id = c_ptr->t_id;
						turnState = 10;
					}
					else {
						turnState = 7;
						timer = timer5;	// 5 Min
						memset(allow_print, true, sizeof(allow_print));
					}

					clearClick = 1;
				}

				// Go to Property Management Screen
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 782 && lastMousePos.y >= 766) && (lastMousePos.x <= 957 && lastMousePos.y <= 875)) {
					turnState = 8;
					timer = timer5;	// 5 Min
					memset(allow_print, true, sizeof(allow_print));

					clearClick = 1;
				}
			}
		}

		// ---------------- Auction ---------------- //
		if (turnState == 4 && clearClick == zeroCheck)
		{
			if (ExitBid == 1)
			{
				// Cancel Participation
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 990 && lastMousePos.y >= 649) && (lastMousePos.x <= 1090 && lastMousePos.y <= 738))
					auction(1, NULL);

				// Increase Bid Price by 1$
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 657 && lastMousePos.y >= 806) && (lastMousePos.x <= 703 && lastMousePos.y <= 855))
					auction(2, 1);

				// Increase Bid Price by 10$
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 793 && lastMousePos.y >= 806) && (lastMousePos.x <= 842 && lastMousePos.y <= 855))
					auction(2, 10);

				// Increase Bid Price by 25$
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 932 && lastMousePos.y >= 806) && (lastMousePos.x <= 981 && lastMousePos.y <= 855))
					auction(2, 25);
			}

			clearClick = 1;
		}

		// -------------- Loan Screen -------------- //
		if (turnState == 6 && clearClick == zeroCheck)
		{
			// If the current player is a human
			if (This_Player.getIsHuman() == true)
			{
				// Increase Loan Amount
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1129 && lastMousePos.y >= 236) && (lastMousePos.x <= 1210 && lastMousePos.y <= 304))
					loan(1);

				// Decrease Loan Amount
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 745 && lastMousePos.y >= 236) && (lastMousePos.x <= 824 && lastMousePos.y <= 304))
					loan(2);

				// Increase Round Count
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1173 && lastMousePos.y >= 601) && (lastMousePos.x <= 1247 && lastMousePos.y <= 667))
					loan(3);

				// Decrease Round Count
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1015 && lastMousePos.y >= 601) && (lastMousePos.x <= 1097 && lastMousePos.y <= 667))
					loan(4);

				// Take Loan
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 833 && lastMousePos.y >= 765) && (lastMousePos.x <= 943 && lastMousePos.y <= 865))
					loan(5);

				// Exit Loan
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1020 && lastMousePos.y >= 765) && (lastMousePos.x <= 1129 && lastMousePos.y <= 865)) {
					turnState = 3;
					SkipIt = false;
					memset(allow_print, true, sizeof(allow_print));
				}
			}

			clearClick = 1;
		}


		// ---------------- Negotiation ---------------- //
		if (turnState == 7 && clearClick == zeroCheck)
		{
			// If the current player is a human
			if (This_Player.getIsHuman() == true)
			{
				// Back button
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 657 && lastMousePos.y >= 815) && (lastMousePos.x <= 782 && lastMousePos.y <= 856)) {
					if (neg_stage == zeroCheck) {
						turnState = 3;
						neg_offer = neg_receive = 0;
						memset(NegOfferMini, 0, sizeof(NegOfferMini));
						memset(NegReceiveMini, 0, sizeof(NegReceiveMini));
						memset(Nflag, 0, sizeof(Nflag));
						memset(Nflag2, 0, sizeof(Nflag2));
						num_offer_prop = 0;
						num_receive_prop = 0;
						NegSelectedProperty = 0;
						neg_selected_p = 0;
					}

					else if (neg_stage == 1) {
						neg_stage = neg_selected_p = 0;
					}

					else if (neg_stage == 2) {
						neg_stage = 1;
						neg_receive = neg_selected_p = 0;
					}

					clearClick = 1;
				}

				// Next button
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 917 && lastMousePos.y >= 815) && (lastMousePos.x <= 1043 && lastMousePos.y <= 856)) {
					if (neg_stage == zeroCheck) {
						int flag = 0;
						for (int j = 0; j < 28; j++)
							if (Nflag[j] != 0)
								flag = 1;

						if (flag || neg_offer != 0)
							neg_stage = 1;
					}

					clearClick = 1;
				}

				// Next 2 button
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1180 && lastMousePos.y >= 814) && (lastMousePos.x <= 1303 && lastMousePos.y <= 857)) {
					if (neg_stage == 1 && neg_selected_p != 0)
						neg_stage = 2;

					clearClick = 1;
				}

				// Finish button
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 904 && lastMousePos.y >= 812) && (lastMousePos.x <= 1056 && lastMousePos.y <= 855)) {
					if (neg_stage == 2) {
						t_Head = createNegTrans(t_Head, neg_selected_p);
						turnState = 3;
						memset(Nflag, 0, sizeof(Nflag));
						memset(Nflag2, 0, sizeof(Nflag2));
						memset(neg_player_array, 0, sizeof(neg_player_array));
						neg_stage = neg_offer = neg_receive = neg_selected_p = 0;
						NegSelectedProperty = 0;
					}

					clearClick = 1;
				}

				// Decrease money button
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 629 && lastMousePos.y >= 770) && (lastMousePos.x <= 668 && lastMousePos.y <= 800)) {
					if (neg_stage == zeroCheck)
						if (neg_offer >= 10)
							neg_offer -= 10;
					if (neg_stage == 2)
						if (neg_receive >= 10)
							neg_receive -= 10;

					clearClick = 1;
				}

				// Add money button
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 769 && lastMousePos.y >= 770) && (lastMousePos.x <= 809 && lastMousePos.y <= 800)) {
					if (neg_stage == zeroCheck)
						if (neg_offer + 10 <= This_Player.getMoney())
							neg_offer += 10;
					if (neg_stage == 2)
						if (neg_receive + 10 <= This_Player.getMoney())
							neg_receive += 10;

					clearClick = 1;
				}

				// Select property checkboxes
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 777 && lastMousePos.y >= 167) && (lastMousePos.x <= 1357 && lastMousePos.y <= 876 && clearClick == zeroCheck)) {
					if (neg_stage == zeroCheck) {
						if (num_offer_prop < 8) {
							for (int i = 0; i < 28; i++) {
								if ((lastMousePos.x >= SposX[i] && lastMousePos.y >= SposY[i]) && (lastMousePos.x <= EposX[i] && lastMousePos.y <= EposY[i])) {
									if (properties[NFlagRealIndex[i]].Owner == This_Player.getID()) {
										if (Nflag[i] == zeroCheck) {
											Nflag[i] = 1;
											num_offer_prop++;
										}
										else {
											Nflag[i] = 0;
											num_offer_prop--;
										}
									}
								}
							}
						}
					}

					else if (neg_stage == 2) {
						if (num_receive_prop < 8) {
							for (int i = 0; i < 28; i++) {
								if ((lastMousePos.x >= SposX[i] && lastMousePos.y >= SposY[i]) && (lastMousePos.x <= EposX[i] && lastMousePos.y <= EposY[i])) {
									if (properties[NFlagRealIndex[i]].Owner == neg_selected_p) {
										if (Nflag2[i] == zeroCheck) {
											Nflag2[i] = 1;
											num_receive_prop++;
										}
										else {
											Nflag2[i] = 0;
											num_receive_prop--;
										}
									}
								}
							}
						}
					}

					clearClick = 1;
				}

				// Player selection
				if (neg_stage == 1)
				{
					// Left Token
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 677 && lastMousePos.y >= 335) && (lastMousePos.x <= 842 && lastMousePos.y <= 500))
						neg_selected_p = neg_player_array[0];

					// Middle Token
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 899 && lastMousePos.y >= 335) && (lastMousePos.x <= 1064 && lastMousePos.y <= 500))
						neg_selected_p = neg_player_array[1];

					// Right Token
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1119 && lastMousePos.y >= 335) && (lastMousePos.x <= 1285 && lastMousePos.y <= 500))
						neg_selected_p = neg_player_array[2];

					clearClick = 1;
				}
			}
		}


		// -- Property Management Screen -- //
		if (turnState == 8 && clearClick == zeroCheck)
		{
			// Go Back Button
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 640 && lastMousePos.y >= 766) && (lastMousePos.x <= 821 && lastMousePos.y <= 876))
				turnState = 3;
		}


		// -------------- Trivia Screen -------------- //
		if (turnState == 9 && clearClick == zeroCheck)
		{
			// If the current player is a human
			if (This_Player.getIsHuman() == true)
			{
				// Click Answer 1
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 658 && lastMousePos.y >= 785) && (lastMousePos.x <= 960 && lastMousePos.y <= 826)) {
					if (tm != 0 && t_verdict == zeroCheck) {
						ans = 1;
						draws = !draws;
					}
				}

				// Click Answer 2
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 658 && lastMousePos.y >= 834) && (lastMousePos.x <= 960 && lastMousePos.y <= 872)) {
					if (tm != 0 && t_verdict == zeroCheck) {
						ans = 2;
						draws = !draws;
					}
				}

				// Click Answer 3
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 991 && lastMousePos.y >= 785) && (lastMousePos.x <= 1298 && lastMousePos.y <= 826)) {
					if (tm != 0 && t_verdict == zeroCheck) {
						ans = 3;
						draws = !draws;
					}
				}

				// Click Answer 4
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 991 && lastMousePos.y >= 834) && (lastMousePos.x <= 1298 && lastMousePos.y <= 872)) {
					if (tm != 0 && t_verdict == zeroCheck) {
						ans = 4;
						draws = !draws;
					}
				}
			}
		}

		// ------------- Negotiation Offers ------------- //
		if (turnState == 10 && clearClick == zeroCheck)
		{
			// Back button
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 658 && lastMousePos.y >= 814) && (lastMousePos.x <= 781 && lastMousePos.y <= 855)) {
				turnState = 3;
				clearClick = 1;
			}

			// Hiding enlarged property icon
			if (NegSelectedProperty) {
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 736 && lastMousePos.y >= 173) && (lastMousePos.x <= 1245 && lastMousePos.y <= 734)) {
					NegSelectedProperty = 0;
					clearClick = 1;
				}
			}
			// Do not allow the player to click on any buttons except Back while viewing an enlarged property icon
			else {
				// Arrow left button (previous)
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 908 && lastMousePos.y >= 769) && (lastMousePos.x <= 969 && lastMousePos.y <= 822)) {
					Transaction *t = returnNegOffer(t_Head, -1);
					if (t) {
						c_ptr = t;
						trans_id = c_ptr->t_id;
					}
				}

				// Arrow right button (next)
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 984 && lastMousePos.y >= 769) && (lastMousePos.x <= 1043 && lastMousePos.y <= 822)) {
					Transaction *t = returnNegOffer(t_Head, 1);
					if (t) {
						c_ptr = t;
						trans_id = c_ptr->t_id;
					}
				}

				// Reject offer button
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1114 && lastMousePos.y >= 773) && (lastMousePos.x <= 1215 && lastMousePos.y <= 872)) {
					t_Head = removeNegTrans(t_Head, trans_id);
					c_ptr = checkNegOffer(t_Head, 1);
					if (!c_ptr) {
						trans_id = 0;
						turnState = 3;
					}
				}

				// Accept offer button
				if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1228 && lastMousePos.y >= 773) && (lastMousePos.x <= 1336 && lastMousePos.y <= 872)) {
					t_Head = acceptOffer(t_Head);
					c_ptr = checkNegOffer(t_Head, 1);
					if (!c_ptr) {
						trans_id = 0;
						turnState = 3;
					}
				}

				// Displaying mini property icon
				if (num_offer_prop && NegSelectedProperty == zeroCheck && clearClick == zeroCheck)
				{
					// Property #1 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 639 && lastMousePos.y >= 642) && (lastMousePos.x <= 694 && lastMousePos.y <= 695) && num_offer_prop >= 1) {
						NegSelectedProperty = 1;
					}

					// Property #2 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 706 && lastMousePos.y >= 642) && (lastMousePos.x <= 761 && lastMousePos.y <= 695) && num_offer_prop >= 2) {
						NegSelectedProperty = 2;
					}

					// Property #3 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 772 && lastMousePos.y >= 642) && (lastMousePos.x <= 828 && lastMousePos.y <= 695) && num_offer_prop >= 3) {
						NegSelectedProperty = 3;
					}

					// Property #4 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 838 && lastMousePos.y >= 642) && (lastMousePos.x <= 893 && lastMousePos.y <= 695) && num_offer_prop >= 4) {
						NegSelectedProperty = 4;
					}

					// Property #5 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 639 && lastMousePos.y >= 708) && (lastMousePos.x <= 694 && lastMousePos.y <= 763) && num_offer_prop >= 5) {
						NegSelectedProperty = 5;
					}

					// Property #6 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 706 && lastMousePos.y >= 708) && (lastMousePos.x <= 761 && lastMousePos.y <= 763) && num_offer_prop >= 6) {
						NegSelectedProperty = 6;
					}

					// Property #7 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 772 && lastMousePos.y >= 708) && (lastMousePos.x <= 828 && lastMousePos.y <= 763) && num_offer_prop >= 7) {
						NegSelectedProperty = 7;
					}

					// Property #8 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 838 && lastMousePos.y >= 708) && (lastMousePos.x <= 893 && lastMousePos.y <= 695) && num_offer_prop >= 8) {
						NegSelectedProperty = 8;
					}
				}

				if (num_receive_prop && NegSelectedProperty == zeroCheck && clearClick == zeroCheck)
				{
					// Property #1 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1033 && lastMousePos.y >= 642) && (lastMousePos.x <= 1087 && lastMousePos.y <= 697) && num_receive_prop >= 1) {
						NegSelectedProperty = -1;
					}

					// Property #2 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1099 && lastMousePos.y >= 642) && (lastMousePos.x <= 1153 && lastMousePos.y <= 697) && num_receive_prop >= 2) {
						NegSelectedProperty = -2;
					}

					// Property #3 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1164 && lastMousePos.y >= 642) && (lastMousePos.x <= 1220 && lastMousePos.y <= 697) && num_receive_prop >= 3) {
						NegSelectedProperty = -3;
					}

					// Property #4 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1232 && lastMousePos.y >= 642) && (lastMousePos.x <= 1286 && lastMousePos.y <= 697) && num_receive_prop >= 4) {
						NegSelectedProperty = -4;
					}

					// Property #5 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1033 && lastMousePos.y >= 706) && (lastMousePos.x <= 1087 && lastMousePos.y <= 763) && num_receive_prop >= 5) {
						NegSelectedProperty = -5;
					}

					// Property #6 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1099 && lastMousePos.y >= 706) && (lastMousePos.x <= 1153 && lastMousePos.y <= 763) && num_receive_prop >= 6) {
						NegSelectedProperty = -6;
					}

					// Property #7 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1164 && lastMousePos.y >= 706) && (lastMousePos.x <= 1220 && lastMousePos.y <= 763) && num_receive_prop >= 7) {
						NegSelectedProperty = -7;
					}

					// Property #8 offer button
					if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 1232 && lastMousePos.y >= 706) && (lastMousePos.x <= 1286 && lastMousePos.y <= 763) && num_receive_prop >= 8) {
						NegSelectedProperty = -8;
					}
				}
			}

			clearClick = 1;
		}

		// ------------- ESC Menu ------------- //
		if (turnState == 999 && clearClick == zeroCheck)
		{
			// Resume playing
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 669 && lastMousePos.y >= 163) && (lastMousePos.x <= 1288 && lastMousePos.y <= 273)) {
				turnState = turnStateBackup;
				timer = timerBackup;
				cout << " Game Unpaused! " << endl;
			}

			// Save game
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 669 && lastMousePos.y >= 304) && (lastMousePos.x <= 1288 && lastMousePos.y <= 414))
				save();

			// Load Game
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 669 && lastMousePos.y >= 446) && (lastMousePos.x <= 1288 && lastMousePos.y <= 556)) {
				restartGame();
				gameState = 3;
			}

			// Exit to menu
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 669 && lastMousePos.y >= 590) && (lastMousePos.x <= 1288 && lastMousePos.y <= 698)) {
				restartGame();
				gameState = 0;
			}

			// Exit
			if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 669 && lastMousePos.y >= 730) && (lastMousePos.x <= 1288 && lastMousePos.y <= 841))
				glfwSetWindowShouldClose(window, GL_TRUE);
			
			clearClick = 1;
		}
	}

	// ------------ Load Game Screen ------------ //
	if (gameState == 3 && clearClick == zeroCheck)
	{
		// Go back to Main Menu
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 841 && lastMousePos.y >= 952) && (lastMousePos.x <= 1101 && lastMousePos.y <= 1036))
			gameState = 0;

		// Saved #0
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 268 && lastMousePos.y >= 156) && (lastMousePos.x <= 938 && lastMousePos.y <= 268) && loadRows >= 1)
			load(1);
			
		// Saved #1
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 268 && lastMousePos.y >= 295) && (lastMousePos.x <= 938 && lastMousePos.y <= 407) && loadRows >= 2)
			load(2);

		// Saved #2
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 268 && lastMousePos.y >= 432) && (lastMousePos.x <= 938 && lastMousePos.y <= 547) && loadRows >= 3)
			load(3);

		// Saved #3
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 268 && lastMousePos.y >= 573) && (lastMousePos.x <= 938 && lastMousePos.y <= 687) && loadRows >= 4)
			load(4);

		// Saved #4
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 268 && lastMousePos.y >= 715) && (lastMousePos.x <= 938 && lastMousePos.y <= 825) && loadRows >= 5)
			load(5);

		// Saved #5
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 976 && lastMousePos.y >= 156) && (lastMousePos.x <= 1645 && lastMousePos.y <= 268) && loadRows >= 6)
			load(6);

		// Saved #6
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 976 && lastMousePos.y >= 295) && (lastMousePos.x <= 1645 && lastMousePos.y <= 407) && loadRows >= 7)
			load(7);

		// Saved #7
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 976 && lastMousePos.y >= 432) && (lastMousePos.x <= 1645 && lastMousePos.y <= 547) && loadRows >= 8)
			load(8);

		// Saved #8
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 976 && lastMousePos.y >= 573) && (lastMousePos.x <= 1645 && lastMousePos.y <= 687) && loadRows >= 9)
			load(9);

		// Saved #9
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 976 && lastMousePos.y >= 715) && (lastMousePos.x <= 1645 && lastMousePos.y <= 825))
			load(10);

		clearClick = 1;
	}

	// ------------ High Scores Screen ------------ //
	if (gameState == 4 && clearClick == zeroCheck)
	{
		// Go back to Main Menu
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 840 && lastMousePos.y >= 954) && (lastMousePos.x <= 1106 && lastMousePos.y <= 1048))
			gameState = 0;

		clearClick = 1;
	}

	// ------------ Credits Screen ------------ //
	if (gameState == 5 && clearClick == zeroCheck)
	{
		// Go back to Main Menu
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && (lastMousePos.x >= 840 && lastMousePos.y >= 954) && (lastMousePos.x <= 1106 && lastMousePos.y <= 1048))
			gameState = 0;

		clearClick = 1;
	}

	clearClick = 0;
}

//-----------------------------------------------------------------------------
// Responsible for minimizing / maximizing the window
//-----------------------------------------------------------------------------
void glfw_onWindowIconify(GLFWwindow* window, int iconified)
{
	if (iconified) {
		// The window was iconified
		cout << "minimized attempt!" << endl;
		glfwIconifyWindow(window);

	}

	else 	{
		// The window was restored
		cout << "maximized attempt!" << endl;
		glfwRestoreWindow(window);
	}
}

//-----------------------------------------------------------------------------
// Code computes the average frames per second, and also the average time it takes
// to render one frame.  These stats are appended to the window caption bar.
//-----------------------------------------------------------------------------
void showFPS(GLFWwindow* window)
{
	static double previousSeconds = 0.0;
	static int frameCount = 0;
	double elapsedSeconds;
	double currentSeconds = glfwGetTime(); // returns number of seconds since GLFW started, as double float

	elapsedSeconds = currentSeconds - previousSeconds;

	// Limit text updates to 4 times per second
	if (elapsedSeconds > 0.25)
	{
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		double msPerFrame = 1000.0 / fps;

		// The C++ way of setting the window title
		std::ostringstream outs;
		outs.precision(3);	// decimal places
		outs << std::fixed
			<< APP_TITLE << "    "
			<< "FPS: " << fps << "    "
			<< "Frame Time: " << msPerFrame << " (ms)";
		glfwSetWindowTitle(window, outs.str().c_str());

		// Reset for next average.
		frameCount = 0;
	}

	frameCount++;
}

//-----------------------------------------------------------------------------
// Check if the player has all the property fields of the same Color group
//-----------------------------------------------------------------------------
int CheckOwnership(char *Color, int player, int mode)
{
	int flag = 0, count = 0;

	// mode = 1 - checking for ownership of all the properties of this color group
	if (mode == 1) {
		for (int i = 0; i < Num_Of_Properties; i++)
			if (strcmp(properties[i].Color, Color) == zeroCheck)
				if (properties[i].Owner != player)
					return 0;
		return 1;
	}

	// mode = 2 - checking for railroad quantity
	else if (mode == 2) {
		for (int i = 0; i < Num_Of_Properties; i++)
			if (strcmp(properties[i].Color, Color) == zeroCheck)
				if (properties[i].Owner == player)
					count++;
		return count;
	}

	return -1;
}

//-----------------------------------------------------------------------------
// Responsible for community chest
//-----------------------------------------------------------------------------
void getCommunityChest()
{
	// Displaying proper massage
	logPrint(36);

	switch (RandValue)
	{
		// Advance to "Start"
		case 1: {
			// Move the player to position 1 (GO)
			This_Player.setPLoc(propertyPos[0][This_Player.getID() - 1]);
			This_Player.setPosition(1);

			// Display proper massage
			logPrint(36);

			// Collect 200$
			getGoStatus(1, false);

		} break;

		// Add / Remove money	
		case 2:case 3:case 4:case 8:case 9:case 11:case 12:case 13:case 14: case 16: case 17: {
			int price = communitychests[RandValue].Operation;

			// Display proper massage
			logPrint(36);

			if (Payed == false) {
				pay(This_Player.getID(), price);
				Payed = true;
			}

		} break;

		// Get out of jail free card
		case 5: {
			// Display proper massage
			logPrint(36);
			This_Player.updateJailCard('+');
			
		} break;

		// Go to jail
		case 6: {
			This_Player.setPLoc(propertyPos[10][This_Player.getID() - 1]);
			This_Player.setJailTime(1);
			This_Player.setPosition(11);	
		} break;

		// Get money from other players
		case 7:case 10: {
			for (int i = 0; i < NumberofPlayers; i++) {
				if (Players[i].getID() != This_Player.getID()) {
					if (RandValue == 7) {
						pay(This_Player.getID(), 50);
						pay(Players[i].getID(), -50);
						Payed = true;
					}
					else if (RandValue == 10) {
						pay(This_Player.getID(), 10);
						pay(Players[i].getID(), -10);
					}
				}
			}

		} break;

		// Tax according to each house / hotel repair sum
		case 15: {
			int price = 0;
			int HouseRepairCounter = 0, HotelRepairCounter = 0;

			// Counting all of the player houses and hotels
			for (int i = 0; i < 40; i++) {
				if (properties[i].Owner == This_Player.getID()) 	{
					if (properties[i].Got_Hotel == true)
						HotelRepairCounter++;
					else HouseRepairCounter += properties[i].House_Count;
				}
			}

			price += (HouseRepairCounter * 25) + (HotelRepairCounter * 110);

			if (Payed == false){
				pay(This_Player.getID(), -price);
				Payed = true;
			}
		} break;
	}

	once = 1;
}

//-----------------------------------------------------------------------------
// Responsible for chance cards
//-----------------------------------------------------------------------------
void getChance()
{
	// Displaying proper massage
	logPrint(39);

	switch (RandValue)
	{
		// Advance to "Start"
		case 1: {
			// Move the player to position 1 (GO)
			This_Player.setPLoc(propertyPos[0][This_Player.getID() - 1]);
			This_Player.setPosition(1);

			// Display proper massage
			logPrint(39);

			// Collect 200$
			getGoStatus(1, false);

		} break;

		// Illinois Ave
		case 2: {
			// Move player position to "Illionis Ave"
			This_Player.setPLoc(propertyPos[24][This_Player.getID() - 1]);

			if (This_Player.getPosition() > 25)
				// Collect 100$
				getGoStatus(2, false);

			This_Player.setPosition(25);

		} break;

		// St. Charles Place
		case 3: {
			// Move player position to "St. Charles Place"
			This_Player.setPLoc(propertyPos[11][This_Player.getID() - 1]);

			if (This_Player.getPosition() > 12)
				// Collect 100$
				getGoStatus(2, false);

			This_Player.setPosition(12);

		} break;

		// Nearest Utility
		case 4: {
			// Move player position to "Electric Company"
			if (This_Player.getPosition() == 8) {
				This_Player.setPLoc(propertyPos[12][This_Player.getID() - 1]);
				This_Player.setPosition(13);
			}

			// Move player position to "Electric Company"
			if (This_Player.getPosition() == 23) {
				This_Player.setPLoc(propertyPos[28][This_Player.getID() - 1]);
				This_Player.setPosition(29);
			}

			// Move player position to "Electric Company" While passing go
			if (This_Player.getPosition() == 37) {
				This_Player.setPLoc(propertyPos[12][This_Player.getID() - 1]);
				This_Player.setPosition(13);

				// Collect 100$
				getGoStatus(2, false);
			}

		} break;

		// Go to nearest Railroad
		case 5: {
			// Go to pennysilvania Railroad
			if (This_Player.getPosition() == 8) {
				This_Player.setPLoc(propertyPos[15][This_Player.getID() - 1]);
				This_Player.setPosition(16);
				timer = timer2;
			}

			// Go to B & O Railroad
			if (This_Player.getPosition() == 23) {
				This_Player.setPLoc(propertyPos[25][This_Player.getID() - 1]);
				This_Player.setPosition(26);
				timer = timer2;
			}

			// Go to B & O Railroad
			if (This_Player.getPosition() == 37) {
				This_Player.setPLoc(propertyPos[5][This_Player.getID() - 1]);
				This_Player.setPosition(6);
				timer = timer2;

				// Collect 100$
				getGoStatus(2, false);

				// Display proper massage
				logPrint(40);
			}

		} break;

		// Go back 3 spaces
		case 8: {
			if (This_Player.getPosition() == 8) {
				This_Player.setPLoc(propertyPos[4][This_Player.getID() - 1]);
				This_Player.setPosition(5);
			}

			if (This_Player.getPosition() == 23) {
				This_Player.setPLoc(propertyPos[19][This_Player.getID() - 1]);
				This_Player.setPosition(20);
			}

			if (This_Player.getPosition() == 37) {
				This_Player.setPLoc(propertyPos[33][This_Player.getID() - 1]);
				This_Player.setPosition(34);
			}

		} break;

		// Go to Reading Railroad
		case 12: {				
			This_Player.setPLoc(propertyPos[5][This_Player.getID() - 1]);
			This_Player.setPosition(6);

			// Collect 100$
			getGoStatus(2, false);

			// Display proper massage
			logPrint(40);

		} break;

		// Go to Broad Walk
		case 13: {
			This_Player.setPLoc(propertyPos[39][This_Player.getID() - 1]);
			This_Player.setPosition(40);

		} break;

		// Give OR Take money from the / to the player
		case 6: case 11: case 15: case 16: {
			int price = chance[RandValue - 1].Operation;

			// Display proper massage
			logPrint(39);

			if (Payed == false) {
				pay(This_Player.getID(), price);
				Payed = true;
			}
		} break;

		// Get out of jail free card
		case 7: {
			// Display proper massage
			logPrint(39);
			This_Player.updateJailCard('+');
		} break;

		// Go to jail
		case 9: {
			This_Player.setPLoc(propertyPos[10][This_Player.getID() - 1]);
			This_Player.setPosition(11);
			This_Player.setJailTime(1);
		} break;

		// Tax according to each house / hotel repair sum
		case 10: {
			int price = 0;
			int HouseRepairCounter = 0, HotelRepairCounter = 0;

			// Counting all of the player houses and hotels
			for (int i = 0; i < 40; i++) {
				if (properties[i].Owner == This_Player.getID()) {
					if (properties[i].Got_Hotel == true)
						HotelRepairCounter++;
					else HouseRepairCounter += properties[i].House_Count;
				}
			}

			price += (HouseRepairCounter * 25) + (HotelRepairCounter * 110);

			if (Payed == false) {
				pay(This_Player.getID(), -price);
				Payed = true;
			}	
		} break;

		// Give each player 50$
		case 14: {
			if (Payed == false) {
				for (int i = 0; i < NumberofPlayers; i++)
					if (Players[i].getID() != This_Player.getID())
						pay(Players[i].getID(), -50);		
				Payed = true;
			}

			price = chance[RandValue].Operation;
		} break;

		// Go to trivia
		case 17: {
			turnState = 9;
		} break;
	}
}


//-----------------------------------------------------------------------------
// Check to see if the player has landed on go or passed it
//-----------------------------------------------------------------------------
void getGoStatus(int Gostate, bool Restrictionsbycards)
{
	if (Restrictionsbycards == false)
	{
		if (Gostate == 2) // land on go
		{
			if (Payed == false)
			{
				pay(currentPlayer, 200);
				Payed = true;
			}
			if (This_Player.getLoanCurrentRound() > 0)
				This_Player.setLoanCurrentRound(This_Player.getLoanCurrentRound() - 1);
			if (This_Player.getTakeLoan() == true && This_Player.getLoanCurrentRound() == zeroCheck)
			{
				pay(currentPlayer, (-This_Player.getSumLoan()));
				This_Player.setTakeLoan(false);
				This_Player.setSumLoan(0);
			}
		}
		if (Gostate == 1) // just pass go
		{
			if (Payed == false)
			{
				pay(currentPlayer, 100);
				Payed = true;
			}
			if (This_Player.getLoanCurrentRound() > 0)
				This_Player.setLoanCurrentRound(This_Player.getLoanCurrentRound() - 1);
			if (This_Player.getTakeLoan() == true && This_Player.getLoanCurrentRound() == zeroCheck)
			{
				pay(currentPlayer, (-This_Player.getSumLoan()));
				This_Player.setTakeLoan(false);
				This_Player.setSumLoan(0);
			}
		}

		This_Player.setRoundCount(This_Player.getRoundCount() + 1);
	}
}

//-----------------------------------------------------------------------------
// Responsible for taking / giving the player money
//-----------------------------------------------------------------------------
void pay(int player, int money)
{
	for (int i = 0; i < NumberofPlayers; i++) {
		if (Players[i].getID() == player) {

			int res = Players[i].updateMoney(money);

			if (res == 1)
				cout << "Player " << player << ", Money: " << Players[i].getMoney() << ", Line: " << __LINE__ << endl;
			else if (res == -1) {
				cout << "Player " << player << ", Money: " << Players[i].getMoney() << ", WARNING: Founds depleted! Your'e in debt! Line : " << __LINE__ << endl;
				// If the player already has a loan.. He's done.. no saving him
				if (This_Player.getTakeLoan() == true)
					removePlayer();

				// Else, if the player hasnt taken a loan, but maybe he can be saved
				else if (This_Player.getTakeLoan() == false) {
					if (removeDebt(money) == 1) {
						This_Player.setMinusCount(This_Player.getMinusCount() + 1);
						SkipIt = false;
						memset(allow_print, true, sizeof(allow_print));
						turnState = 3;
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------------------------
// Responsible for auction participation / cancellation
//-----------------------------------------------------------------------------
void auction(int scase, int sum)
{
	int flag = 0, count = 0;
	s_sum = sum;	// Initializing a global variable so that we could use him in displaying a proper massage
	
	// scase 1 = Cancel participation 
	if (scase == 1) {
		// Display proper massage
		allow_print[38] = true;
		logPrint(38);
		PlayerInBid[currentPlayer - 1] = 1;
	}

	// scase 2 = Increase bid by 'sum' amount
	else if (scase == 2) {

		if (bidPrice + s_sum >= This_Player.getMoney()) {
			// Display proper massage
			logPrint(41);

			PlayerInBid[currentPlayer - 1] = 1; // Canceling player participation
		}

		else {
			// Display proper massage
			allow_print[42] = true;
			logPrint(42);

			bidPrice += s_sum;
			HighestBidder = currentPlayer;
		}
	}

	// Rotation between players in the auction
	for (int i = currentPlayer; i <= NumberofPlayers && flag == zeroCheck; i++) 
	{
		// If the current player is not the last in this rotation
		if (i < NumberofPlayers)
		{
			// And the next player is still participating (i instead of i-1)
			if (PlayerInBid[i] == zeroCheck)
			{
				// Advance to the next player
				currentPlayer++;
				flag++;
			}
			else 
				i++;
		}
		else
		{
			int j = 0;
			while (PlayerInBid[j] == 1)
				j++;

			currentPlayer = j + 1;
			flag++;
		}

		// Counting all the players that have canceled their participation OR do not possess suffecient amount
		for (int j = 0; j < NumberofPlayers; j++)
			if (PlayerInBid[j] == 1)
				count++;
		
		// If all player have are out
		if (count == NumberofPlayers)
			flag = 1;
	}

	// Display Bid not sold picture
	if (count == NumberofPlayers) {
		// Display proper massage
		logPrint(43);

		ExitBid = 3;
	}

	// Display winning picture
	else if ((count == (NumberofPlayers - 1)) && HighestBidder != 0)
	{
		// Display proper massage
		logPrint(44);

		This_Player.setMoney(This_Player.getMoney() - bidPrice);
		properties[CurCard - 1].Owner = This_Player.getID();
		ExitBid = 2;
	}

	if (ExitBid == 2 || ExitBid == 3)
		timer = timer6;	// 3 seconds
	else timer = timer2;	// 5 seconds
}

//-----------------------------------------------------------------------------
// Responsible for drawing all the houses / hotels each property has
//-----------------------------------------------------------------------------
void drawHouseHotel() {

	int index = 0;
	vec3 temp;

	// Drawing all the properties houses
	for (int i = 0; i < 40; i++) {

		if (properties[i].Category == zeroCheck) {

			// Counting the property houses / hotel
			int HCount = properties[i].House_Count;
			bool Hotel = properties[i].Got_Hotel;
			if (Hotel)
				HCount = 1;

			if (isDrop == true && i == (pHouse - 1)) {

				// Down
				if (dropDir == 1) {

					// Drop a house
					if (HCount <= 3) {
						temp = modelPosHouse[index][HCount] + dropCord;
						drawTexture(temp, vec3(0.45f, 0.5f, 0.45f), 87, 19);
					}

					// Drop a hotel
					else {
						temp = modelPosHouse[index][1] + dropCord;
						drawTexture(temp, vec3(0.45f, 0.8f, 0.45f), 86, 19);
					}

					// Continuing to drop it downward
					if (dropCord[1] > 0.2f)
						dropCord[1] -= 0.1f;

					// Finished dropping
					else {
						if (HCount <= 3)
							properties[i].House_Count++;
						else
							properties[i].Got_Hotel = true;

						isDrop = false;
						pHouse = 0;
						dropDir = 0;
						dropCord = vec3(0.0f, 10.0f, 0.0f);
						turnState = 3;
						SkipIt = false;
						memset(allow_print, true, sizeof(allow_print));
					}
				}

				// Up
				else if (dropDir == 2) {
					
					// Pull a hotel
					if (pHouseBack == -1) {
						temp = modelPosHouse[index][1] + dropCord;
						drawTexture(temp, vec3(0.45f, 0.7f, 0.45f), 86, 19);
					}

					// Pull a house
					else {
						temp = modelPosHouse[index][pHouseBack - 1] + dropCord;
						drawTexture(temp, vec3(0.45f, 0.5f, 0.45f), 87, 19);
					}

					// Continuing to pull it upward
					if (dropCord[1] < 10.0f)
						dropCord[1] += 0.1f;

					// Finished pulling
					else {
						isDrop = false;
						pHouse = 0;
						dropDir = 0;
						dropCord = vec3(0.0f, 10.0f, 0.0f);
						turnState = 3;
						SkipIt = false;
						memset(allow_print, true, sizeof(allow_print));
					}
				}
			}

			// Counting the property houses / hotel
			HCount = properties[i].House_Count;
			Hotel = properties[i].Got_Hotel;
			if (Hotel)
				HCount = 1;

			for (int j = 0; j < HCount; j++) {

				if (j == zeroCheck && Hotel)
					temp = modelPosHouse[index][1];
				else if (j == zeroCheck)
					temp = modelPosHouse[index][0];
				if (j == 1) temp = modelPosHouse[index][1];
				if (j == 2) temp = modelPosHouse[index][2];
				if (j == 3) temp = modelPosHouse[index][3];

				if (Hotel)
					drawTexture(temp, vec3(0.45f, 0.9f, 0.45f), 86, 19);
				else
					drawTexture(temp, vec3(0.45f, 0.5f, 0.45f), 87, 19);
			}

			index++;
		}
	}
}

//-----------------------------------------------------------------------------
// Responsible for the loan taking process and each part of it
//-----------------------------------------------------------------------------
void loan(int scase)
{
	switch (scase)
	{
	case 1:
	{
		loanprice += 50;
		if (loanprice >= 3550)
			loanprice = 50;
	} break;

	case 2:
	{
		loanprice -= 50;
	} break;

	case 3:
	{
		roundcount++;
		if (roundcount > 6)
			roundcount = 2;
	} break;

	case 4:
	{
		roundcount--;
		if (roundcount < 2)
			roundcount = 6;
	} break;

	case 5:
	{
		if (Payed == false) {
			pay(This_Player.getID(), loanprice);
			Payed = true;
		}
		This_Player.setTakeLoan(true);
		This_Player.setSumLoan(loanInterest);
		This_Player.setLoanCurrentRound(roundcount);
		int j = This_Player.getLoanCurrentRound();
		turnState = 3;	// Return to player screen
		SkipIt = false;
		memset(allow_print, true, sizeof(allow_print));
	} break;
	}
}

//------------------------------------------------------------------------------------------------
// Function that preserves the current game mode
//------------------------------------------------------------------------------------------------
void save()
{
	const char *var = NULL;
	char query[2000], fulldate[100];
	int state = 0, GameID = 0;
	string name;
	SYSTEMTIME st;

	GetLocalTime(&st);
	sprintf_s(fulldate, sizeof(fulldate), "%d-%d-%d", st.wYear, st.wMonth, st.wDay);

	if (turnState == 3 && This_Player.getMoney() > 0) {
		if (currentPlayer < NumberofPlayers) 
			currentPlayer++;
		else 
			currentPlayer = 1;
	}
	
	// Getting the number of saved games
	mysql_query(conn, "SELECT * FROM `Savedgamesetting`");
	res = mysql_store_result(conn);
	GameID = (int)mysql_num_rows(res);

	if (GameID == 10) {
		sprintf_s(query, sizeof(query), "DELETE FROM `savedgamesetting` WHERE `GameID` = 1");
		state = mysql_query(conn, query);
		if (state != 0)
			cout << mysql_error(conn) << endl;

		sprintf_s(query, sizeof(query), "DELETE FROM `PlayerSaved` WHERE `GameID` = 1");
		state = mysql_query(conn, query);
		if (state != 0)
			cout << mysql_error(conn) << endl;

		sprintf_s(query, sizeof(query), "DELETE FROM `propertysaved` WHERE `GameID` = 1");
		state = mysql_query(conn, query);
		if (state != 0)
			cout << mysql_error(conn) << endl;

		GameID = 0;
	}
	
	if (GameID < 10)
	{
		GameID++;
		if (NumberofPlayers == 2)
			sprintf_s(query, sizeof(query), "INSERT INTO Savedgamesetting(GameID, players, turn, p1round, p2round, p3round, p4round, date) VALUES(%d,%d, %d, %d, %d, %d, %d,'%s')", GameID, NumberofPlayers, currentPlayer, Players[0].getRoundCount(), Players[1].getRoundCount(), 0, 0, fulldate);
		else if (NumberofPlayers == 3)
			sprintf_s(query, sizeof(query), "INSERT INTO Savedgamesetting(GameID, players, turn, p1round, p2round, p3round, p4round, date) VALUES(%d,%d, %d, %d, %d, %d, %d,'%s')", GameID, NumberofPlayers, currentPlayer, Players[0].getRoundCount(), Players[1].getRoundCount(), Players[2].getRoundCount(), 0, fulldate);
		else if (NumberofPlayers == 4)
			sprintf_s(query, sizeof(query), "INSERT INTO Savedgamesetting(GameID, players, turn, p1round, p2round, p3round, p4round, date) VALUES(%d,%d, %d, %d, %d, %d, %d,'%s')", GameID, NumberofPlayers, currentPlayer, Players[0].getRoundCount(), Players[1].getRoundCount(), Players[2].getRoundCount(), Players[3].getRoundCount(), fulldate);
		
		state = mysql_query(conn, query);
		if (state != 0)
			cout << mysql_error(conn) << endl;
		else {
			for (int i = 0; i < NumberofPlayers; i++) {
				name = '"' + Players[i].getName() + '"';
				var = name.c_str();
				sprintf_s(query, sizeof(query), "INSERT INTO PlayerSaved(GameID, name, ishuman, id, token, money, position, properties, jailtime, cardoutjail, sumloan, loancurrentround, currentround, trivia, minuscount, vacationstate, takeloan) VALUES(%d, %s, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d)", GameID, var, Players[i].getIsHuman(), Players[i].getID(), Players[i].getToken(), Players[i].getMoney(), Players[i].getPosition(), Players[i].getProperties(), Players[i].getJailTime(), Players[i].getCardOutJail(), Players[i].getSumLoan(), Players[i].getLoanCurrentRound(), Players[i].getRoundCount(), Players[i].getTrivia(), Players[i].getMinusCount(), Players[i].getVacationState(), Players[i].getTakeLoan());
				state = mysql_query(conn, query);
			}

			if (state != 0)
				cout << mysql_error(conn) << endl;
			else {
				for (int i = 0; i < 40; i++) {
					if (properties[i].Owner > 0 && properties[i].Owner <= 4) {
						sprintf_s(query, sizeof(query), "INSERT INTO propertysaved(GameID, position, owner, houses, hotel) VALUES(%d, %d, %d, %d, %d)", GameID, properties[i].Position, properties[i].Owner, properties[i].House_Count, properties[i].Got_Hotel);
						state = mysql_query(conn, query);
						if (state != 0)
							cout << mysql_error(conn) << endl;
					}
				}
			}
		}

		cout << "Game saved with Game ID #" << GameID << endl;
	}
}

//------------------------------------------------------------------------------------------------
// Function that reload the saved game mode
//------------------------------------------------------------------------------------------------
void load(int GameIDd)
{
	int j = 0, state = 0, GameID = GameIDd;
	char query[2000];

	gameState = 2;
	sprintf_s(query, sizeof(query), "SELECT * FROM `Savedgamesetting` WHERE `GameID`= %d", GameID);
	state = mysql_query(conn, query);
	if (state != 0) {
		printf(mysql_error(conn));

		// Display proper massage
		cout << "Game number: " << GameID << " couldn't be loaded" << endl;
	}
	else {
		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res))) {
			NumberofPlayers = atoi(row[1]);
			currentPlayer = atoi(row[2]);
			for (int i = 0; i < NumberofPlayers; i++)
				Players[i].setRoundCount(atoi(row[3 + i]));
		}

		sprintf_s(query, sizeof(query), "SELECT * FROM `PlayerSaved` WHERE `GameID`= %d", GameID);
		state = mysql_query(conn, query);
		if (state != 0) {
			printf(mysql_error(conn));

			// Display proper massage
			cout << "Game number: " << GameID << " couldn't be loaded" << endl;
		}
		else {
			res = mysql_store_result(conn);
			while ((row = mysql_fetch_row(res))) {
				Players[j].setName(row[1]);
				Players[j].setIsHuman(row[2]);
				Players[j].setID(atoi(row[3]));
				Players[j].setToken(atoi(row[4]));
				Players[j].setMoney(atoi(row[5]));
				Players[j].setPosition(atoi(row[6]));
				Players[j].setProperties(atoi(row[7]));
				Players[j].setJailTime(atoi(row[8]));
				Players[j].setCardOutJail(atoi(row[9]));
				Players[j].setSumLoan(atoi(row[10]));
				Players[j].setLoanCurrentRound(atoi(row[11]));
				Players[j].setRoundCount(atoi(row[12]));
				Players[j].setTrivia(atoi(row[13]));
				Players[j].setMinusCount(atoi(row[14]));
				Players[j].setVacationState(atoi(row[15]));
				Players[j].setTakeLoan(atoi(row[16]));
				Players[j].setPLoc(propertyPos[atoi(row[6]) - 1][j]);
				j++;
			}

			sprintf_s(query, sizeof(query), "SELECT * FROM `propertysaved` WHERE `GameID`= %d", GameID);
			state = mysql_query(conn, query);
			if (state != 0) {
				printf(mysql_error(conn));

				// Display proper massage
				cout << "Game number: " << GameID << " couldn't be loaded" << endl;
			}
			else {
				res = mysql_store_result(conn);
				while ((row = mysql_fetch_row(res))) {
					for (int i = 0; i < 40; i++) {
						if (properties[i].Position == atoi(row[1])) {
							properties[i].Owner = atoi(row[2]);
							properties[i].House_Count = atoi(row[3]);
							properties[i].Got_Hotel = atoi(row[4]);
						}
					}
				}
			}
		}

		// Display proper massage
		cout << "Game number: " << GameID << " loaded" << endl;
	}
}

//------------------------------------------------------------------------------------------------
// Responsible for drawing every texture in the game
//------------------------------------------------------------------------------------------------
void drawTexture(vec3 pos, vec3 size, int texture, int mesh)
{
	// Drawing the texture
	model = translate(mat4(), pos) * scale(mat4(), size);
	shaderProgram.setUniform("model", model);

	TextureArr[texture].bind(0);
	MeshArr[mesh].draw();
	TextureArr[texture].unbind(0);
}

//------------------------------------------------------------------------------------------------
// Responsible for moving the player token
//------------------------------------------------------------------------------------------------
void movePlayer()
{
	if (PlayerMove == true && frm != 0 && gameState == 2)
	{
		orbitCamera.setLookAt(This_Player.getPLoc() + vec3(0.0f, -This_Player.getPLoc()[1], 0.0f));

		// Calculating jump differnce
		if (oneTimeCordDiff == false) {
			int nextPropPos = (This_Player.getPosition() == 40) ? 1 : (This_Player.getPosition() + 1);
			vec3 currentProperty = propertyPos[This_Player.getPosition() - 1][This_Player.getID() - 1];
			vec3 nextProperty = propertyPos[nextPropPos - 1][This_Player.getID() - 1];

			cordDiff =  -(currentProperty + (-nextProperty));
			cordDiff /= 60.0f;
			oneTimeCordDiff = true;
		}

		// Advancing the player token in "Jumps"
		if (frm > 30)
			This_Player.setPLoc(This_Player.getPLoc() + cordDiff + vec3(0.0f, 0.09f, 0.0f));
		else
			This_Player.setPLoc(This_Player.getPLoc() + cordDiff - vec3(0.0f, 0.09f, 0.0f));

		frm--;
		if (frm == zeroCheck)
		{
			// Updating player location
			This_Player.setPLoc(vec3(This_Player.getPLoc()[0], 0.0f, This_Player.getPLoc()[2]));
			
			// If the player position is the last one on the board (40)
			if (This_Player.getPosition() < Num_Of_Properties)
				This_Player.setPosition(This_Player.getPosition() + 1);
					
			// Else, return to position 1
			else {
				// If we just passed GO
				if (Dicesum != 0)
					getGoStatus(1, false);	// 100$
				This_Player.setPosition(1);
			}
		
			PlayerMove = false;
			frm = timer11;
			Dicesum--;
			if (Dicesum == zeroCheck) {
		
				// Returns the view to above the board upon finishing progression
				orbitCamera.setLookAt(vec3(0.0f, 0.0f, 0.0f));
				turnState = 2;
				SkipIt = false;
				memset(allow_print, true, sizeof(allow_print));
		
				// If we finished moving and landed on GO
				if (This_Player.getPosition() == 1)
					getGoStatus(2, false);		// 200$
			}
		}
	}
}

//------------------------------------------------------------------------------------------------
// Responsible for ending the current player turn
//------------------------------------------------------------------------------------------------
void endTurn()
{
	if (!pQuit)
		// Display proper massage
		logPrint(33);

	// If the player had a "double" shot, let him play again, else - switch players
	if (flagdouble == zeroCheck || (Dice[0] != Dice[1])) {
		if (currentPlayer < NumberofPlayers) 
			currentPlayer++;
		else {
			currentPlayer = 1;
			roundcount++;
		}
	}

	flagdouble = zeroCheck;
	price = zeroCheck;
	flag = zeroCheck;
	timer = timer1;	// 10 seconds
	RandButton = false;
	turnState = zeroCheck;
	Dicefrm = timer2;
	frm = timer11;
	once = zeroCheck;
	owner = zeroCheck;
	Payed = false;
	SkipIt = false;
	bidPrice = zeroCheck;
	memset(Dice, zeroCheck, sizeof(Dice));
	memset(allow_print, true, sizeof(allow_print));
	Dicesum = zeroCheck;
	loanInterest = zeroCheck;
	loanprice = zeroCheck;
	RandValue = zeroCheck;
	vacationTimer = timer2;
	pQuit = false;
}

//------------------------------------------------------------------------------------------------
// Responsible for loading the mesh (objectes) and textures (images)
//------------------------------------------------------------------------------------------------
void load_Textures(int stage)
{
	switch (stage)
	{
		case 0: {
			cout << "Loading OBJ Files..." << endl;

			// --- OBJ Loading --- //
			MeshArr[0].loadOBJ("Models/Plane.obj");
			MeshArr[1].loadOBJ("Models/Pawn.obj");
			MeshArr[2].loadOBJ("Models/Table.obj");
			MeshArr[3].loadOBJ("Models/Floor.obj");
			MeshArr[4].loadOBJ("Models/Dice.obj");
			MeshArr[5].loadOBJ("Models/Wall.obj");
			MeshArr[6].loadOBJ("Models/Wall2.obj");
			TextureArr[1].loadTexture("Textures/Loading/2.png", true);

		} break;

		case 1: {
			// Tokens OBJ files
			MeshArr[7].loadOBJ("Models/Wheelbarrow.obj");
			MeshArr[8].loadOBJ("Models/Hat.obj");
			MeshArr[9].loadOBJ("Models/Thimble.obj");
			MeshArr[10].loadOBJ("Models/Dog.obj");
			MeshArr[11].loadOBJ("Models/Car.obj");
			MeshArr[12].loadOBJ("Models/Iron.obj");
			MeshArr[13].loadOBJ("Models/Shoe.obj");
			MeshArr[14].loadOBJ("Models/Ship.obj");
			MeshArr[15].loadOBJ("Models/Top.obj");
			MeshArr[16].loadOBJ("Models/CardRight.obj");
			MeshArr[17].loadOBJ("Models/Buttom.obj");
			MeshArr[18].loadOBJ("Models/CardLeft.obj");
			MeshArr[19].loadOBJ("Models/House.obj");

			cout << "OBJ Files Loaded Successfully" << endl
				 << "Loading Essential Files..." << endl;

			TextureArr[1].loadTexture("Textures/Loading/3.png", true);
		} break;

		case 2: {
			cout << "Pre-loading textures Started" << endl;

			// Card Textures
			TextureArr[2].loadTexture("Textures/Property_Cards/2.png", true);
			TextureArr[4].loadTexture("Textures/Property_Cards/4.png", true);
			TextureArr[5].loadTexture("Textures/Property_Cards/5.png", true);
			TextureArr[6].loadTexture("Textures/Property_Cards/6.png", true);
			TextureArr[7].loadTexture("Textures/Property_Cards/7.png", true);
			TextureArr[9].loadTexture("Textures/Property_Cards/9.png", true);
			TextureArr[10].loadTexture("Textures/Property_Cards/10.png", true);
			TextureArr[11].loadTexture("Textures/Property_Cards/11.png", true);
			TextureArr[12].loadTexture("Textures/Property_Cards/12.png", true);
			TextureArr[13].loadTexture("Textures/Property_Cards/13.png", true);
			TextureArr[14].loadTexture("Textures/Property_Cards/14.png", true);
			TextureArr[15].loadTexture("Textures/Property_Cards/15.png", true);
			TextureArr[16].loadTexture("Textures/Property_Cards/16.png", true);
			TextureArr[17].loadTexture("Textures/Property_Cards/17.png", true);
			TextureArr[19].loadTexture("Textures/Property_Cards/19.png", true);
			TextureArr[20].loadTexture("Textures/Property_Cards/20.png", true);
			TextureArr[21].loadTexture("Textures/Property_Cards/21.png", true);
			TextureArr[22].loadTexture("Textures/Property_Cards/22.png", true);
			TextureArr[24].loadTexture("Textures/Property_Cards/24.png", true);
			TextureArr[25].loadTexture("Textures/Property_Cards/25.png", true);
			TextureArr[26].loadTexture("Textures/Property_Cards/26.png", true);
			TextureArr[27].loadTexture("Textures/Property_Cards/27.png", true);
			TextureArr[28].loadTexture("Textures/Property_Cards/28.png", true);
			TextureArr[29].loadTexture("Textures/Property_Cards/29.png", true);
			TextureArr[30].loadTexture("Textures/Property_Cards/30.png", true);
			TextureArr[31].loadTexture("Textures/Property_Cards/31.png", true);
			TextureArr[32].loadTexture("Textures/Property_Cards/32.png", true);
			TextureArr[33].loadTexture("Textures/Property_Cards/33.png", true);
			TextureArr[35].loadTexture("Textures/Property_Cards/35.png", true);
			TextureArr[36].loadTexture("Textures/Property_Cards/36.png", true);
			TextureArr[38].loadTexture("Textures/Property_Cards/38.png", true);
			TextureArr[39].loadTexture("Textures/Property_Cards/39.png", true);
			TextureArr[40].loadTexture("Textures/Property_Cards/40.png", true);

			TextureArr[1].loadTexture("Textures/Loading/4.png", true);

		} break;

		case 3: {
			// Screens Textures
			TextureArr[41].loadTexture("Textures/Screens/Board.png", true);
			TextureArr[42].loadTexture("Textures/Screens/In_Jail.png", true);
			TextureArr[43].loadTexture("Textures/Screens/Negotiation_check.png", true);
			TextureArr[44].loadTexture("Textures/Screens/Load.png", true);
			TextureArr[45].loadTexture("Textures/Screens/Loan.png", true);
			TextureArr[46].loadTexture("Textures/Screens/Main.png", true);
			TextureArr[47].loadTexture("Textures/Screens/Player_Loan.png", true);
			TextureArr[48].loadTexture("Textures/Screens/Player_No_Loan.png", true);
			TextureArr[49].loadTexture("Textures/Screens/Settings_2.png", true);
			TextureArr[50].loadTexture("Textures/Screens/Auction_Human.png", true);
			TextureArr[51].loadTexture("Textures/Screens/Managment.png", true);
			TextureArr[52].loadTexture("Textures/Screens/Out_of_Jail.png", true);
			TextureArr[53].loadTexture("Textures/Screens/Trivia.png", true);
			TextureArr[54].loadTexture("Textures/Screens/Settings_3.png", true);
			TextureArr[55].loadTexture("Textures/Screens/Settings_4.png", true);

			// Dice Textures
			TextureArr[56].loadTexture("Textures/Dice/1.png", true);
			TextureArr[57].loadTexture("Textures/Dice/2.png", true);
			TextureArr[58].loadTexture("Textures/Dice/3.png", true);
			TextureArr[59].loadTexture("Textures/Dice/4.png", true);
			TextureArr[60].loadTexture("Textures/Dice/5.png", true);
			TextureArr[61].loadTexture("Textures/Dice/6.png", true);

			// NumPad Textures
			TextureArr[62].loadTexture("Textures/NumPad/-.png", true);
			TextureArr[63].loadTexture("Textures/NumPad/0.png", true);
			TextureArr[64].loadTexture("Textures/NumPad/1.png", true);
			TextureArr[65].loadTexture("Textures/NumPad/2.png", true);
			TextureArr[66].loadTexture("Textures/NumPad/3.png", true);
			TextureArr[67].loadTexture("Textures/NumPad/4.png", true);
			TextureArr[68].loadTexture("Textures/NumPad/5.png", true);
			TextureArr[69].loadTexture("Textures/NumPad/6.png", true);
			TextureArr[70].loadTexture("Textures/NumPad/7.png", true);
			TextureArr[71].loadTexture("Textures/NumPad/8.png", true);
			TextureArr[72].loadTexture("Textures/NumPad/9.png", true);

			TextureArr[1].loadTexture("Textures/Loading/5.png", true);
		} break;

		case 4: {
			// Token Textures
			TextureArr[73].loadTexture("Textures/Tokens/1.png", true);
			TextureArr[74].loadTexture("Textures/Tokens/2.png", true);
			TextureArr[75].loadTexture("Textures/Tokens/3.png", true);
			TextureArr[76].loadTexture("Textures/Tokens/4.png", true);
			TextureArr[77].loadTexture("Textures/Tokens/5.png", true);
			TextureArr[78].loadTexture("Textures/Tokens/6.png", true);
			TextureArr[79].loadTexture("Textures/Tokens/7.png", true);
			TextureArr[80].loadTexture("Textures/Tokens/8.png", true);

			// Materials Textures
			TextureArr[81].loadTexture("Textures/Material/BrickWall.jpg", true);
			TextureArr[82].loadTexture("Textures/Material/Concrete.jpg", true);
			TextureArr[83].loadTexture("Textures/Material/Floor_Deck.jpg", true);
			TextureArr[84].loadTexture("Textures/Material/Table_Wood.jpg", true);
			TextureArr[85].loadTexture("Textures/Material/WhiteWood.jpg", true);

			// Gameplay Textures
			TextureArr[86].loadTexture("Textures/Gameplay/Hotel.png", true);
			TextureArr[87].loadTexture("Textures/Gameplay/House.png", true);
			TextureArr[88].loadTexture("Textures/Gameplay/Not_Sold.png", true);
			TextureArr[89].loadTexture("Textures/Gameplay/Sold.png", true);
			TextureArr[90].loadTexture("Textures/Screens/Highscores.png", true);
			TextureArr[91].loadTexture("Textures/Gameplay/usecard.png", true);
			TextureArr[92].loadTexture("Textures/Screens/Icon_P.png", true);
			TextureArr[93].loadTexture("Textures/Screens/Icon_AI.png", true);
			TextureArr[94].loadTexture("Textures/Material/Gold.jpg", true);
			TextureArr[95].loadTexture("Textures/Screens/Negotiation_1.png", true);
			TextureArr[96].loadTexture("Textures/Screens/Negotiation_2.png", true);
			TextureArr[97].loadTexture("Textures/Screens/Negotiation_pselect.png", true);

			TextureArr[1].loadTexture("Textures/Loading/6.png", true);

		} break;

		case 5: {
			// Community Chest Textures
			TextureArr[98].loadTexture("Textures/Community_Chest/1.png", true);
			TextureArr[99].loadTexture("Textures/Community_Chest/2.png", true);
			TextureArr[100].loadTexture("Textures/Community_Chest/3.png", true);
			TextureArr[101].loadTexture("Textures/Community_Chest/4.png", true);
			TextureArr[102].loadTexture("Textures/Community_Chest/5.png", true);
			TextureArr[103].loadTexture("Textures/Community_Chest/6.png", true);
			TextureArr[104].loadTexture("Textures/Community_Chest/7.png", true);
			TextureArr[105].loadTexture("Textures/Community_Chest/8.png", true);
			TextureArr[106].loadTexture("Textures/Community_Chest/9.png", true);
			TextureArr[107].loadTexture("Textures/Community_Chest/10.png", true);
			TextureArr[108].loadTexture("Textures/Community_Chest/11.png", true);
			TextureArr[109].loadTexture("Textures/Community_Chest/12.png", true);
			TextureArr[110].loadTexture("Textures/Community_Chest/13.png", true);
			TextureArr[111].loadTexture("Textures/Community_Chest/14.png", true);
			TextureArr[112].loadTexture("Textures/Community_Chest/15.png", true);
			TextureArr[113].loadTexture("Textures/Community_Chest/16.png", true);
			TextureArr[114].loadTexture("Textures/Community_Chest/17.png", true);

			// Chance Textures
			TextureArr[115].loadTexture("Textures/Chance/1.png", true);
			TextureArr[116].loadTexture("Textures/Chance/2.png", true);
			TextureArr[117].loadTexture("Textures/Chance/3.png", true);
			TextureArr[118].loadTexture("Textures/Chance/4.png", true);
			TextureArr[119].loadTexture("Textures/Chance/5.png", true);
			TextureArr[120].loadTexture("Textures/Chance/6.png", true);
			TextureArr[121].loadTexture("Textures/Chance/7.png", true);
			TextureArr[122].loadTexture("Textures/Chance/8.png", true);
			TextureArr[123].loadTexture("Textures/Chance/9.png", true);
			TextureArr[124].loadTexture("Textures/Chance/10.png", true);
			TextureArr[125].loadTexture("Textures/Chance/11.png", true);
			TextureArr[126].loadTexture("Textures/Chance/12.png", true);
			TextureArr[127].loadTexture("Textures/Chance/13.png", true);
			TextureArr[128].loadTexture("Textures/Chance/14.png", true);
			TextureArr[129].loadTexture("Textures/Chance/15.png", true);
			TextureArr[130].loadTexture("Textures/Chance/16.png", true);

			TextureArr[1].loadTexture("Textures/Loading/7.png", true);
		} break;

		case 6: {

			// Buttons Textures
			TextureArr[131].loadTexture("Textures/Buttons/Buy.png", true);
			TextureArr[132].loadTexture("Textures/Buttons/Buy_Hotel.png", true);
			TextureArr[133].loadTexture("Textures/Buttons/Buy_House.png", true);
			TextureArr[134].loadTexture("Textures/Buttons/End_Turn.png", true);
			TextureArr[135].loadTexture("Textures/Buttons/Loan.png", true);
			TextureArr[136].loadTexture("Textures/Buttons/Negotiation.png", true);
			TextureArr[137].loadTexture("Textures/Buttons/Property_Managment.png", true);
			TextureArr[138].loadTexture("Textures/Buttons/Roll_Dice.png", true);
			TextureArr[139].loadTexture("Textures/Buttons/Save.png", true);
			TextureArr[140].loadTexture("Textures/Buttons/Sell.png", true);
			TextureArr[141].loadTexture("Textures/Buttons/Sell_Hotel.png", true);
			TextureArr[142].loadTexture("Textures/Buttons/Sell_House.png", true);
			TextureArr[143].loadTexture("Textures/Buttons/Skip.png", true);
			TextureArr[144].loadTexture("Textures/Buttons/Back.png", true);
			TextureArr[145].loadTexture("Textures/Gameplay/checkbox.png", true);
			TextureArr[146].loadTexture("Textures/Gameplay/checkbox_g.png", true);
			TextureArr[147].loadTexture("Textures/Gameplay/checkbox_r.png", true);
			TextureArr[148].loadTexture("Textures/Gameplay/qmark.png", true);
			TextureArr[149].loadTexture("Textures/Screens/Free_Parking.png", true);

			// Countdown Digits for the Trivia
			TextureArr[150].loadTexture("Textures/Countdown_Digits/0.png", true);
			TextureArr[151].loadTexture("Textures/Countdown_Digits/1.png", true);
			TextureArr[152].loadTexture("Textures/Countdown_Digits/2.png", true);
			TextureArr[153].loadTexture("Textures/Countdown_Digits/3.png", true);
			TextureArr[154].loadTexture("Textures/Countdown_Digits/4.png", true);
			TextureArr[155].loadTexture("Textures/Countdown_Digits/5.png", true);
			TextureArr[156].loadTexture("Textures/Countdown_Digits/6.png", true);
			TextureArr[157].loadTexture("Textures/Countdown_Digits/7.png", true);
			TextureArr[158].loadTexture("Textures/Countdown_Digits/8.png", true);
			TextureArr[159].loadTexture("Textures/Countdown_Digits/9.png", true);

			TextureArr[1].loadTexture("Textures/Loading/8.png", true);
		} break;

		case 7: {

			// ABC Letters for the Trivia
			TextureArr[160].loadTexture("Textures/ABC_Letters/a.png", true);
			TextureArr[161].loadTexture("Textures/ABC_Letters/b.png", true);
			TextureArr[162].loadTexture("Textures/ABC_Letters/c.png", true);
			TextureArr[163].loadTexture("Textures/ABC_Letters/d.png", true);
			TextureArr[164].loadTexture("Textures/ABC_Letters/e.png", true);
			TextureArr[165].loadTexture("Textures/ABC_Letters/f.png", true);
			TextureArr[166].loadTexture("Textures/ABC_Letters/g.png", true);
			TextureArr[167].loadTexture("Textures/ABC_Letters/h.png", true);
			TextureArr[168].loadTexture("Textures/ABC_Letters/i.png", true);
			TextureArr[169].loadTexture("Textures/ABC_Letters/j.png", true);
			TextureArr[170].loadTexture("Textures/ABC_Letters/k.png", true);
			TextureArr[171].loadTexture("Textures/ABC_Letters/l.png", true);
			TextureArr[172].loadTexture("Textures/ABC_Letters/m.png", true);
			TextureArr[173].loadTexture("Textures/ABC_Letters/n.png", true);
			TextureArr[174].loadTexture("Textures/ABC_Letters/o.png", true);
			TextureArr[175].loadTexture("Textures/ABC_Letters/p.png", true);
			TextureArr[176].loadTexture("Textures/ABC_Letters/q.png", true);
			TextureArr[177].loadTexture("Textures/ABC_Letters/r.png", true);
			TextureArr[178].loadTexture("Textures/ABC_Letters/s.png", true);
			TextureArr[179].loadTexture("Textures/ABC_Letters/t.png", true);
			TextureArr[180].loadTexture("Textures/ABC_Letters/u.png", true);
			TextureArr[181].loadTexture("Textures/ABC_Letters/v.png", true);
			TextureArr[182].loadTexture("Textures/ABC_Letters/w.png", true);
			TextureArr[183].loadTexture("Textures/ABC_Letters/x.png", true);
			TextureArr[184].loadTexture("Textures/ABC_Letters/y.png", true);
			TextureArr[185].loadTexture("Textures/ABC_Letters/z.png", true);
			TextureArr[186].loadTexture("Textures/ABC_Letters/bracket.png", true);
			TextureArr[187].loadTexture("Textures/ABC_Letters/comma.png", true);
			TextureArr[188].loadTexture("Textures/ABC_Letters/dot.png", true);
			TextureArr[189].loadTexture("Textures/ABC_Letters/question.png", true);
			TextureArr[190].loadTexture("Textures/ABC_Letters/space.png", true);
			TextureArr[191].loadTexture("Textures/ABC_Letters/-.png", true);

			TextureArr[1].loadTexture("Textures/Loading/9.png", true);
		} break;

		case 8: {
			TextureArr[192].loadTexture("Textures/Trivia_Answers/1s.png", true);
			TextureArr[193].loadTexture("Textures/Trivia_Answers/1c.png", true);
			TextureArr[194].loadTexture("Textures/Trivia_Answers/1w.png", true);
			TextureArr[195].loadTexture("Textures/Trivia_Answers/2s.png", true);
			TextureArr[196].loadTexture("Textures/Trivia_Answers/2c.png", true);
			TextureArr[197].loadTexture("Textures/Trivia_Answers/2w.png", true);
			TextureArr[198].loadTexture("Textures/Trivia_Answers/3s.png", true);
			TextureArr[199].loadTexture("Textures/Trivia_Answers/3c.png", true);
			TextureArr[200].loadTexture("Textures/Trivia_Answers/3w.png", true);
			TextureArr[201].loadTexture("Textures/Trivia_Answers/4s.png", true);
			TextureArr[202].loadTexture("Textures/Trivia_Answers/4c.png", true);
			TextureArr[203].loadTexture("Textures/Trivia_Answers/4w.png", true);

			TextureArr[1].loadTexture("Textures/Loading/10.png", true);

		} break;

		case 9: {
			TextureArr[204].loadTexture("Textures/Tokens/1b.png", true);
			TextureArr[205].loadTexture("Textures/Tokens/2b.png", true);
			TextureArr[206].loadTexture("Textures/Tokens/3b.png", true);
			TextureArr[207].loadTexture("Textures/Tokens/4b.png", true);
			TextureArr[208].loadTexture("Textures/Tokens/5b.png", true);
			TextureArr[209].loadTexture("Textures/Tokens/6b.png", true);
			TextureArr[210].loadTexture("Textures/Tokens/7b.png", true);
			TextureArr[211].loadTexture("Textures/Tokens/8b.png", true);
			TextureArr[212].loadTexture("Textures/Mini_Cards/Black.png", true);
			TextureArr[213].loadTexture("Textures/Mini_Cards/Blue.png", true);
			TextureArr[214].loadTexture("Textures/Mini_Cards/Brown.png", true);
			TextureArr[215].loadTexture("Textures/Mini_Cards/Green.png", true);
			TextureArr[216].loadTexture("Textures/Mini_Cards/Light_Blue.png", true);
			TextureArr[217].loadTexture("Textures/Mini_Cards/Orange.png", true);
			TextureArr[218].loadTexture("Textures/Mini_Cards/Purple.png", true);
			TextureArr[219].loadTexture("Textures/Mini_Cards/Red.png", true);
			TextureArr[220].loadTexture("Textures/Mini_Cards/Yellow.png", true);
			TextureArr[229].loadTexture("Textures/Screens/Small_Main.png", true);
			TextureArr[230].loadTexture("Textures/Screens/In_Rest.png", true);
			TextureArr[231].loadTexture("Textures/Screens/Credits.png", true);
			TextureArr[232].loadTexture("Textures/Screens/Names.png", true);
			TextureArr[233].loadTexture("Textures/Gameplay/Chance.png", true);
			TextureArr[234].loadTexture("Textures/Buttons/End_Player.png", true);
			TextureArr[235].loadTexture("Textures/Buttons/Passed_Go.png", true);
			TextureArr[236].loadTexture("Textures/Buttons/Land_Go.png", true);
			TextureArr[237].loadTexture("Textures/Buttons/Computer_Roll.png", true);
			TextureArr[238].loadTexture("Textures/Screens/Player_Computer.png", true);
			TextureArr[239].loadTexture("Textures/Screens/Player_Computer_Loan.png", true);
			TextureArr[240].loadTexture("Textures/Buttons/No_More_Loan.png", true);
			TextureArr[241].loadTexture("Textures/Screens/Auction_Computer.png", true);
			TextureArr[242].loadTexture("Textures/Screens/Winner.png", true);
			TextureArr[243].loadTexture("Textures/Buttons/Trivia.png", true);
			TextureArr[244].loadTexture("Textures/Screens/Side_Players.png", true);
			TextureArr[245].loadTexture("Textures/Screens/Side_Players_nodice.png", true);

			cout << "Pre-loading textures Finished" << endl;
			gameState = 0;

		} break;
	}
}

//------------------------------------------------------------------------------------------------
// Responsible for
//------------------------------------------------------------------------------------------------
void logPrint(int log)
{
	if (allow_print[log])
	{
		switch (log)
		{
			case 1: msg << endl << "---------- " << This_Player.getName() << " turn ----------" << endl << "State: before dice roll" << endl; break;
			case 2: msg << "Oh no no no! Your'e in vacation mate!" << endl; break;
			case 3: msg << "State: Dice rolled, Result: " << Dicesum << endl; break;
			case 4: msg << "You've got Double!: " << endl; break;
			case 5: msg << "Your'e still in jail! Turn: " << This_Player.getJailTime() << endl; break;
			case 6: msg << "You've done your time! Your'e out of jail!" << endl; break;
			case 7: msg << "Luck is on your side! Your'e out of jail!" << endl; break;
			case 8: msg << "State: Landed on property." << endl << "Property \"" << Current_Property.Name << "\" is owned by you (" << This_Player.getName() << ")" << endl; break;
			case 9: msg << "State: Landed on property." << endl << "Property \"" << Current_Property.Name << "\" is owned by: " << Players[Current_Property.Owner - 1].getName() << endl; break;
			case 10: msg << "State: Landed on property." << endl << "Property \"" << Current_Property.Name << "\" is not owned by anyone" << endl; break;
			case 11: msg << "CASE " << log << " EMPTY" << endl; break;
			case 12: msg << "Transaction #" << trans_id << " approved! Money & Properties transferred" << endl; break;
			case 13: msg << "State: Landed on property \"" << Current_Property.Name << "\": Life's been rough to you... you've lost 200$!" << endl; break;
			case 14: msg << "State: Landed on property \"" << Current_Property.Name << "\": Jewelry ain't gonna buy itself huh?... you've lost 75$" << endl; break;
			case 15: msg << "State: Landed on property \"" << Current_Property.Name << "\": Bummer... You're going to jail! " << endl; break;
			case 16: msg << "State: Landed on property." << endl << "Property \"" << Current_Property.Name << "\" is a special field" << endl; break;
			case 17: msg << "State: In player screen" << endl; break;
			case 18: msg << "timer: " << timer << endl; break;
			case 19: msg << "State: Visiting jail" << endl; break;
			case 20: msg << "Channel Paused" << endl; break;
			case 21: msg << This_Player.getName() << " choose to quit the game" << endl << "All his properties were liquidated to the bank!" << endl; break;
			case 22: msg << This_Player.getName() << " bought property: \"" << Current_Property.Name << "\"" << endl; break;
			case 23: msg << This_Player.getName() << " bought a house on property: \"" << Current_Property.Name << "\"" << endl; break;
			case 24: msg << This_Player.getName() << " sold his hotel on property \"" << Current_Property.Name << "\"" << endl; break;
			case 25: msg << This_Player.getName() << " sold a house on property: \"" << Current_Property.Name << "\"" << endl; break;
			case 26: msg << This_Player.getName() << " choose not to buy \"" << Current_Property.Name << "\". The property is up for auction!" << endl; break;
			case 27: msg << This_Player.getName() << " sold his property \"" << Current_Property.Name << "\" to the bank" << endl; break;
			case 28: msg << This_Player.getName() << " choose not to upgrade his property: \"" << Current_Property.Name << "\" to the bank" << endl; break;
			case 29: msg << This_Player.getName() << " bought a hotel on property \"" << Current_Property.Name << "\"" << endl; break;
			case 30: msg << "State: Landed on a Chance card" << endl; break;
			case 31: msg << "State: Landed on a Community Chest card" << endl; break;
			case 32: msg << This_Player.getName() << " used his trivia card to escape payment!" << endl; break;
			case 33: msg << This_Player.getName() << " turn has ended" << endl ; break;
			case 34: msg << "CASE " << log << " EMPTY" << endl; break;
			case 35: msg << "CASE " << log << " EMPTY" << endl; break;
			case 36: msg << "Text: " << communitychests[RandValue].CardText << endl; break;
			case 37: msg << "CASE " << log << " EMPTY" << endl; break;
			case 38: msg << This_Player.getName() << "canceled his participation in the bid" << endl; break;
			case 39: msg << "Text: " << chance[RandValue].CardText << endl; break;
			case 40: msg << This_Player.getName() << " has just passed GO and got $100!" << endl; break;
			case 41: msg << "ERROR: Insufficient founds! Required sum: " << bidPrice + s_sum << ", avaliable: " << This_Player.getMoney() << endl; break;
			case 42: msg << This_Player.getName() << " has raised the bid by $" << s_sum << " to $" << bidPrice << endl; break;
			case 43: msg << "All players have canceled their participation in the auction, the property is left unowned" << endl; break;
			case 44: msg << This_Player.getName() << " has won the bid! Final bid sum: " << bidPrice << endl; break;
			case 45: msg << "CASE " << log << " EMPTY" << endl; break;
			case 46: msg << Players[0].getName() << " is the winner! Congratulations!" << endl; break;
			case 60: msg << "Failed to connect to database: Error: %s\n" << mysql_error(conn) << endl; break;
			case 61: msg << "Successfully connected to MySQL DataBase" << endl; break;
		}

		if (allow_print[log]) {
			cout << msg.str();
			logout << msg.rdbuf();
			msg.str(std::string());	// Emptying the content of the stringstream msg
			allow_print[log] = false;
		}
	}
}

//------------------------------------------------------------------------------------------------
// Responsible for
//------------------------------------------------------------------------------------------------
void createLogFile()
{
	time_t rawtime = time(nullptr);
	struct tm time_info;
	char filename[255];					// Log file name holder
	char buffer[255];					// Date and time holder

	localtime_s(&time_info, &rawtime);
	asctime_s(buffer, 255, &time_info);
	strftime(filename, sizeof(filename), "Logs/Log %Y-%m-%d %H-%M-%S.txt", &time_info);

	// Open for read if exists
	logout.open(filename);
	if (logout.is_open()) {
		msg << "-----------------------------------------------------" << endl 
			<< buffer << "Creating LOG file: \'" << filename << "\'" << endl
			<< "-----------------------------------------------------" << endl;
		cout << msg.str();
		logout << msg.rdbuf();
		msg.str(std::string());	// Emptying the content of the stringstream msg
	}
}

//------------------------------------------------------------------------------------------------
// Responsible for creating a new transaction node and incorporating it in the linked list
//------------------------------------------------------------------------------------------------
Transaction* createNegTrans(Transaction *head, int p_receive_id)
{
	Transaction *t_ptr = head, *node = NULL;

	node = (Transaction*)malloc(1 * sizeof(Transaction));
	if (!node)
		exit(1);

	node->t_id = ++trans_index;
	node->p_offer_id = This_Player.getID();
	node->p_receive_id = p_receive_id;
	node->t_money_offer = neg_offer;
	node->t_money_receive = neg_receive;
	node->Next = NULL;

	for (int i = 0; i < 28; i++) {
		node->t_prop_offer[i] = Nflag[i];
		node->t_prop_receive[i] = Nflag2[i];
	}

	// If this Transaction is the first:
	if (t_ptr == NULL) {
		node->Prev = NULL;
		head = node;
	}

	// If not:
	else {
		while (t_ptr->Next != NULL)
			t_ptr = t_ptr->Next;
		t_ptr->Next = node;
		node->Prev = t_ptr;
	}

	cout << endl << "Negotiation Transaction #" << trans_index << ":" << endl;
	cout << "Offering player: " << This_Player.getName() << endl << "Receiving player: " << Players[p_receive_id - 1].getName() << endl;
	cout << "Money offered: " << node->t_money_offer << endl << "Money demended: " << node->t_money_receive << endl;
	cout << "Properties offered: " << endl;
	
	return head;
}

//------------------------------------------------------------------------------------------------
// Responsible for removing a transaction from the linked list given its id
//------------------------------------------------------------------------------------------------
Transaction* removeNegTrans(Transaction *head)
{
	Transaction *t_ptr = head, *next = NULL;
	int flag = 0;

	// If the struct is empty
	if (!t_ptr) {
		cout << "Negotiation Transaction array is empty!" << endl;
		return NULL;
	}

	// If the desired node is first
	else if (t_ptr->p_offer_id == currentPlayer || t_ptr->p_receive_id) {
		// If the node is has a following node
		if (t_ptr->Next != NULL) {
			next = t_ptr;
			t_ptr = t_ptr->Next;
			t_ptr->Prev = t_ptr;
			free(next);
		}
		// If the node is the first and only one in the struct
		else {
			free(t_ptr);
			t_ptr = NULL;
		}

		flag = 1;
	}

	// If the desired node is somewhere in the struct
	else {
		while (t_ptr->Next != NULL) {
			if (t_ptr->Next->p_offer_id == currentPlayer || t_ptr->Next->p_receive_id) {
				next = t_ptr->Next;
				t_ptr->Next = t_ptr->Next->Next;
				if (t_ptr->Next != NULL)
					t_ptr->Next->Prev = t_ptr;
				free(next);
				flag = 1;
			}
			else t_ptr = t_ptr->Next;
		}
	}

	if (flag)
		cout << "All negotiation offers for player: " << This_Player.getName() << " were removed!" << endl;
	else
		cout << "Failed to remove negotiation offers for player: " << This_Player.getName() << endl;

	return t_ptr;
}

Transaction* removeNegTrans(Transaction *head, int id)
{
	Transaction *t_ptr = head, *next = NULL;
	int flag = 0;

	// If the struct is empty
	if (!t_ptr) {
		cout << "Negotiation Transaction array is empty!" << endl;
		return head;
	}

	// if the desired node is first
	else if (t_ptr->t_id == id) {
		// If the node is has a following node
		if (t_ptr->Next != NULL) {
			next = t_ptr;
			t_ptr = t_ptr->Next;
			t_ptr->Prev = t_ptr;
			free(next);
		}
		// If the node is the first and only one in the struct
		else {
			free(t_ptr);
			t_ptr = NULL;
		}

		flag = 1;
	}

	// If the desired node is somewhere in the struct
	else {
		while (t_ptr->Next != NULL) {
			if (t_ptr->Next->t_id == id) {
				next = t_ptr->Next;
				t_ptr->Next = t_ptr->Next->Next;
				if (t_ptr->Next != NULL)
					t_ptr->Next->Prev = t_ptr;
				free(next);
				flag = 1;
			}
			else t_ptr = t_ptr->Next;
		}
	}

	if (flag)
		cout << "Transaction #" << id << " was removed!" << endl;
	else
		cout << "Transaction #" << id << " was NOT found!" << endl;

	return t_ptr;
}

//------------------------------------------------------------------------------------------------
// Responsible for checking if the current user has a transaction offer, if so - return a pointer to it
//------------------------------------------------------------------------------------------------
Transaction* checkNegOffer(Transaction *head, int mode)
{
	Transaction *t_ptr = head;

	while (t_ptr != NULL) {
		if (mode == 1) {
			if (t_ptr->p_receive_id == This_Player.getID())
				return t_ptr;
			else t_ptr = t_ptr->Next;
		}

		else if (mode == 2) {
			if (t_ptr->p_receive_id == This_Player.getID() || t_ptr->p_offer_id == This_Player.getID())
				return t_ptr;
			else t_ptr = t_ptr->Next;
		}
	}

	return NULL;
}

//------------------------------------------------------------------------------------------------
// Responsible for checking if the current user has a transaction offer, if so - return a pointer to it
//------------------------------------------------------------------------------------------------
Transaction* acceptOffer(Transaction *head)
{
	// Trading Money
	Players[c_ptr->p_offer_id - 1].updateMoney(-c_ptr->t_money_offer + c_ptr->t_money_receive);
	Players[c_ptr->p_receive_id - 1].updateMoney(-c_ptr->t_money_receive + c_ptr->t_money_offer);

	// Trading Properties
	for (int i = 0; i < 28; i++) {

		// Offer -> Receive 
		if (c_ptr->t_prop_offer[i]) {
			properties[NFlagRealIndex[i]].Owner = c_ptr->p_receive_id;
			Players[c_ptr->p_offer_id - 1].updateProperty('-');
			Players[c_ptr->p_receive_id - 1].updateProperty('+');
		}

		// Receive -> Offer
		if (c_ptr->t_prop_receive[i]) {
			properties[NFlagRealIndex[i]].Owner = c_ptr->p_offer_id;
			Players[c_ptr->p_receive_id - 1].updateProperty('-');
			Players[c_ptr->p_offer_id - 1].updateProperty('+');
		}
	}

	// Display proper massage
	logPrint(12);

	return removeNegTrans(head, c_ptr->t_id);
}

//------------------------------------------------------------------------------------------------
// Responsible for traversal in both way inside the linked list and finding the prev / next trans
//------------------------------------------------------------------------------------------------
Transaction* returnNegOffer(Transaction *head, int direction)
{
	Transaction *t_ptr = head, *t_back;

	// If the struct is empty
	if (t_ptr == NULL) {
		cout << "Negotiation Transaction array is empty!" << endl;
		return NULL;
	}

	// If the current user has an offer
	if (trans_id != 0) {

		// If not, reach the current transaction (id)
		while (t_ptr->t_id != trans_id)
			t_ptr = t_ptr->Next;

		// Saving the current transaction location
		t_back = t_ptr;

		// If the direction is: previous
		if (direction == -1) {
			while (t_ptr->Prev != NULL) {
				t_ptr = t_ptr->Prev;
				if (t_ptr->p_receive_id == currentPlayer)
					return t_ptr;
			}

			// If no other transaction was found
			return t_back;
		}

		// If the direction is: next
		else if (direction == 1) {
			while (t_ptr->Next != NULL) {
				t_ptr = t_ptr->Next;
				if (t_ptr->p_receive_id == currentPlayer)
					return t_ptr;
			}

			// If no other transaction was found
			return t_back;
		}

		// If the direction is not 1 or -1
		return t_back;
	}
	// If there are no offers
	else return NULL;
}

//------------------------------------------------------------------------------------------------
// Responsible for freeing all dynamically allocated structs or arrrays while the program ends
//------------------------------------------------------------------------------------------------
void freeLists()
{
	Transaction *temp;

	while (t_Head != NULL) {
		temp = t_Head;
		t_Head = t_Head->Next;
		free(temp);
	}
}

//------------------------------------------------------------------------------------------------
// Responsible for
//------------------------------------------------------------------------------------------------
void restartGame()
{
	if (gameState != -1) {
		gameState = 0;
		endTurn();
	}

	// GET PROPERTY CARDS
	int i = 0;
	mysql_query(conn, "SELECT * FROM `property`");
	res = mysql_store_result(conn);
	while (row = mysql_fetch_row(res))
	{
		properties[i].Position = atoi(row[0]);
		properties[i].Buy_Price = atoi(row[1]);
		properties[i].Rent_Price = atoi(row[2]);
		properties[i].House_Price = atoi(row[3]);
		properties[i].Hotel_Price = atoi(row[4]);
		properties[i].Owner = atoi(row[5]);
		properties[i].Category = atoi(row[6]);
		properties[i].With_House[0] = atoi(row[7]);
		properties[i].With_House[1] = atoi(row[8]);
		properties[i].With_House[2] = atoi(row[9]);
		properties[i].With_House[3] = atoi(row[10]);
		properties[i].With_House[4] = atoi(row[11]);
		strcpy_s(properties[i].Color, 50, row[12]);
		strcpy_s(properties[i].Name, 50, row[13]);
		i++;
	}

	if (res != NULL)
		mysql_free_result(res);

	// GET CHANCE CARDS
	mysql_query(conn, "SELECT * FROM `chance`");
	res = mysql_store_result(conn);
	i = 0;
	while (row = mysql_fetch_row(res))
	{
		chance[i].ID = atoi(row[0]);
		strcpy_s(chance[1 + i].CardText, 255, row[1]);
		chance[i + 1].Operation = atoi(row[2]);
		i++;
	}

	if (res != NULL)
		mysql_free_result(res);

	// GET COMMUNITY CHEST CARDS
	mysql_query(conn, "SELECT * FROM `communitychest`");
	res = mysql_store_result(conn);
	i = 0;
	while ((row = mysql_fetch_row(res)))
	{
		communitychests[i + 1].ID = atoi(row[0]);
		strcpy_s(communitychests[1 + i].CardText, 255, row[1]);
		communitychests[i + 1].Operation = atoi(row[2]);
		i++;
	}

	if (res != NULL)
		mysql_free_result(res);

	// GET TRIVIA QUESTIONS
	mysql_query(conn, "SELECT * FROM `Trivia`");
	res = mysql_store_result(conn);
	i = 0;
	t_rows = (int)mysql_num_rows(res);
	while ((row = mysql_fetch_row(res)))
	{
		trivia[i].ID = atoi(row[0]);
		strcpy_s(trivia[i].question, 70, row[1]);
		for (int t = 2; t <= 5; t++)
			strcpy_s(trivia[i].answer[t - 2], 20, row[t]);
		strcpy_s(trivia[i].correctanswer, 20, row[6]);
		i++;
	}

	if (res != NULL)
		mysql_free_result(res);

	currentPlayer = 1;
	Payed = false;
	SkipIt = false;
	RandButton = false;
	pQuit = false;
	timer = timer1;	
	Dicefrm = timer2;
	memset(Dice, 0, sizeof(Dice));
	memset(allow_print, true, sizeof(allow_print));
}

//------------------------------------------------------------------------------------------------
// Responsible for
//------------------------------------------------------------------------------------------------
void tokenChange(int player, int direction)
{
	if (direction == -1)
	{
		int flag = 0;

		if (pToken[player] == 1)
			pToken[player] = 8;
		else pToken[player]--;

		for (int i = 0; i < NumberofPlayers; i++) {
			if (flag == 1) {
				if (pToken[player] == 1)
					pToken[player] = 8;
				else pToken[player]--;
				flag = 0;
			}

			for (int j = 0; j < NumberofPlayers && flag == zeroCheck; j++) {
				if (j != player && pToken[player] == pToken[j])
					flag = 1;
			}
		}
	}

	else if (direction == 1)
	{
		int flag = 0;

		if (pToken[player] == 8)
			pToken[player] = 1;
		else pToken[player]++;

		for (int i = 0; i < NumberofPlayers; i++) {
			if (flag == 1) {
				if (pToken[player] == 8)
					pToken[player] = 1;
				else pToken[player]++;
				flag = 0;
			}

			for (int j = 0; j < NumberofPlayers && flag == zeroCheck; j++) {
				if (j != player && pToken[player] == pToken[j])
					flag = 1;
			}
		}
	}
}

void buy() {
	
	// If no one owns the property, buy property button
	if (Current_Property.Owner == zeroCheck)
	{
		if (Payed == false) {
			pay(This_Player.getID(), -Current_Property.Buy_Price);
			Payed = true;
		}

		// Display proper massage
		logPrint(22); 

		Current_Property.Owner = This_Player.getID();
		This_Player.updateProperty('+');
		turnState = 3;
		SkipIt = false;
		Dicefrm = timer2;
		memset(allow_print, true, sizeof(allow_print));
		Payed = false;
	}

	// Player own the property
	else if (Current_Property.Owner == This_Player.getID())
	{
		// If the player has no houses = BUY HOUSE
		if (Current_Property.House_Count >= 0 && Current_Property.House_Count <= 3 && clearClick == zeroCheck)
		{
			if (Payed == false) {
				pay(This_Player.getID(), -Current_Property.House_Price);
				Payed = true;
			}

			// Display proper massage
			logPrint(23);

			timer = timer2;
			isDrop = true;
			pHouse = Current_Property.Position;
			dropDir = 1;
		}

		// If the player has 4 houses = BUY HOTEL
		else if (Current_Property.House_Count == 4 && Current_Property.Got_Hotel == false && clearClick == zeroCheck)
		{
			// If the player has all the property of the same color group
			if (CheckOwnership(Current_Property.Color, currentPlayer, 1) == 1)
			{
				if (Payed == false) {
					pay(This_Player.getID(), -Current_Property.Hotel_Price);
					Payed = true;
				}

				// Display proper massage
				logPrint(29);

				timer = timer2;
				isDrop = true;
				pHouse = Current_Property.Position;
				dropDir = 1;
			}
		}
	}

	clearClick = 1;
}

void sell() {

	// If the player has an hotel = SELL HOTEL
	if (Current_Property.Got_Hotel == true)
	{
		if (Payed == false) {
			pay(This_Player.getID(), (int)(Current_Property.Hotel_Price * priceHalf));
			Payed = true;
		}

		// Display proper massage
		logPrint(24);

		// Update property house count
		Current_Property.Got_Hotel = false;

		timer = timer7;
		isDrop = true;
		pHouse = Current_Property.Position;
		pHouseBack = -1;
		dropDir = 2;
		dropCord = vec3(0.0f, 0.2f, 0.0f);
	}

	// If the player has 1 to  4 houses = SELL HOUSE
	else if (Current_Property.House_Count >= 1 && Current_Property.House_Count <= 4)
	{
		if (Payed == false) {
			pay(This_Player.getID(), (int)(Current_Property.Hotel_Price * priceHalf));
			Payed = true;
		}

		// Display proper massage
		logPrint(25);

		// Saving the current house location
		pHouseBack = Current_Property.House_Count;

		// Update property house count
		Current_Property.House_Count--;

		timer = timer7;
		isDrop = true;
		pHouse = Current_Property.Position;
		dropDir = 2;
		dropCord = vec3(0.0f, 0.2f, 0.0f);
	}

	// If the player has no houses = SELL PROPERTY
	else if (Current_Property.House_Count == zeroCheck)
	{
		if (Payed == false) {
			pay(This_Player.getID(), (int)(Current_Property.Buy_Price * priceHalf));
			Payed = true;
		}

		// Display proper massage
		logPrint(27);

		Current_Property.Owner = zeroCheck;
		turnState = 3;
		SkipIt = false;
		memset(allow_print, true, sizeof(allow_print));
	}
}

void skip() {

	// Skip buying the property will lead to auction
	if (Current_Property.Owner == zeroCheck) {

		// Going back to board top view
		// Camera Position
		orbitCamera.setPosition(vec3(0.0f, 18.0f, 0.05f));

		// Camera lookAt
		orbitCamera.setLookAt(vec3(0.0f, 0.0f, 0.0f));

		// Display proper massage
		logPrint(26);

		timer = timer1;
		turnState = 4;
		SkipIt = false;
		ExitBid = 1;
		memset(allow_print, true, sizeof(allow_print));	
		Payed = false;
	}

	// Else, The property is already owned
	else {

		// If owned by the current player
		if (Current_Property.Owner == This_Player.getID())
			logPrint(28); 

		// Taking payment
		if (Payed == false && timer > 2) {
			pay(This_Player.getID(), -globalDebt);
			pay(Current_Property.Owner, globalDebt);
			Payed = true;
		}

		turnState = 3;
		SkipIt = false;
		memset(allow_print, true, sizeof(allow_print));
		Payed = false;
	}

	clearClick = 1;
}

int getMaxRent() {

	int max = zeroCheck, temp = zeroCheck;

	for (int i = 0; i < 40; i++) {
		if (properties[i].Owner != 0) {
			if (properties[i].Category == zeroCheck) {
				if (properties[i].Got_Hotel == true) {
					temp = properties[i].With_House[4];
					max = (max > temp) ? max : temp;
				}

				else if (properties[i].House_Count != 0) {
					temp = properties[i].With_House[properties[i].House_Count - 1];
					max = (max > temp) ? max : temp;
				}

				else {
					temp = properties[i].Rent_Price;
					max = (max > temp) ? max : temp;
				}
			}

			else if (properties[i].Category == 1) {
				temp = CheckOwnership(properties[i].Color, currentPlayer, 2);
				if (temp >= 1 && temp <= 2)
					max = (max > temp * 25) ? max : temp * 25;

				else if (temp == 3)
					max = (max > 100) ? max : 100;

				else if (temp == 4)
					max = (max > 200) ? max : 200;
			}

			else if (properties[i].Category == 2) {
				temp = CheckOwnership(properties[i].Color, currentPlayer, 2);
				if (temp == 1)
					max = (max > 50) ? max : 50;

				else if (temp == 2)
					max = (max > 120) ? max : 120;
			}
		}
	}

	return max;
}

void removePlayer() {

	int i;

	// Removing all assets owned by the current player
	for (i = 0; i < 40; i++) {
		if (properties[i].Category >= 0 && properties[i].Category <= 2) {
			if (properties[i].Owner == This_Player.getID()) {
				properties[i].Owner = 0;
				properties[i].House_Count = 0;
				properties[i].Got_Hotel = false;
			}
		}
	}

	// Removing any negotiation offers the player might have offer or received
	while (checkNegOffer(t_Head, 2) != NULL)
		t_Head = removeNegTrans(checkNegOffer(t_Head, 2));

	// Display proper massage
	logPrint(21);

	// Updating the players array
	for (i = currentPlayer - 1; i < NumberofPlayers - 1; i++)
		Players[i] = Players[i + 1];

	Players[i] = Player();
	NumberofPlayers--;
	currentPlayer--;

	// Checking to see if theres only 1 player left
	if (NumberofPlayers == 1) {
		turnState = 11;
		timer = timer1;

		// Display proper massage
		logPrint(46);
	}
	else {
		pQuit = true;
		endTurn();
	}
}

int botNegotiation(int mode) 
{

	int fFlag = 0, f2Flag = 0, bPos = 0, pPos = 0, rPos = 0, oCount = 0, rCount = 0, advanceCount = 0;
	int totalSum = 0;
	char color[50];

	// Approve / reject offered Negotiations
	if (mode == 1)
	{
		c_ptr = checkNegOffer(t_Head, 1);

		// If there is an offer
		while (c_ptr != NULL)
		{
			// Update the transaction id var
			trans_id = c_ptr->t_id;

			// Counting the properties offered and received
			for (int i = 0; i < 28; i++) {
				if (c_ptr->t_prop_offer[i] == 1)
					oCount++;
				if (c_ptr->t_prop_receive[i] == 1)
					rCount++;
			}

			// If the player tries to take advantage of the bot by asking for money only while not giving him less or not at all = REJECT OFFER
			if (c_ptr->p_receive_id > c_ptr->p_offer_id)
				t_Head = removeNegTrans(t_Head, trans_id);

			// If at least one property is offered
			if (oCount)
			{
				for (int i = 0; i < 28; i++)
				{
					// If we found a property offer
					if (c_ptr->t_prop_offer[i] == 1)
					{
						// If the property complete one of our color group.. ("Head to Head")
						if (completeGroup(NFlagRealIndex[i], This_Player.getID()) == 1)
						{
							// Checking to see what the offering player wants in return
							for (int j = 0; j < 28; j++)
							{
								if (c_ptr->t_prop_receive[j] == 1) {
									;
								}

								else if (completeGroup(NFlagRealIndex[i], This_Player.getID()) == -1) {
									// Else, the property only advance our color group possession
									;
								}
							}
						}
					}
				}
			}

			// Else, if at least one property is demended
			else if (rCount) 
			{	
				for (int i = 0; i < 28; i++) 
				{
					if (c_ptr->t_prop_receive[i] == 1) 
					{
						// Do not trade "Green" / "Blue" (LVL 4) Properties... These are key properties and the most expensive ones = REJECT OFFER
						if (strcmp(properties[NFlagRealIndex[i]].Color, "Blue") == zeroCheck || strcmp(properties[NFlagRealIndex[i]].Color, "Green") == zeroCheck)
							t_Head = removeNegTrans(t_Head, trans_id);
						
						// Else, If its another property  then 50% of the properties as to not BREAK IT
						else {
							// If the bot has a complete color group OR more then 50% of the properties = REJECT OFFER
							if (CheckOwnership(properties[NFlagRealIndex[i]].Color, This_Player.getID(), 1) == 1 ||
								CheckOwnership(properties[NFlagRealIndex[i]].Color, This_Player.getID(), 2) > 1)
								t_Head = removeNegTrans(t_Head, trans_id);

							// Else
							else {
								// Does this transaction complete the player color group, if so = REJECT OFFER
								if (completeGroup(NFlagRealIndex[i], c_ptr->p_offer_id) == 1)
									t_Head = removeNegTrans(t_Head, trans_id);

								// Else, does it advance him? If so, accept only with an added 35% more money then the cards worth (hotel and houses included) (Calculated at end)
								else if (completeGroup(NFlagRealIndex[i], c_ptr->p_offer_id) == zeroCheck)
									advanceCount++;
							}
						}
					}
				}			
			}	

			// Calculate payment and conditions //
			// If this transaction advance more then 1 of the offering player color groups = REJECT OFFER
			if (advanceCount >= 2)
				t_Head = removeNegTrans(t_Head, trans_id);
			else
			{
				// Get a total worth sum of all the properties the other player wants from the bot
				for (int i = 0; i < 28; i++)
					if (c_ptr->t_prop_receive[i] == 1)
						totalSum += (int)((properties[NFlagRealIndex[i]].Buy_Price + (properties[NFlagRealIndex[i]].House_Price * properties[NFlagRealIndex[i]].House_Count)) * botHousePercentage);

				// If the other player tries to trick the bot by offering a lot of money AND demending money in return (less then the properties worth) = REJECT OFFER
				if (c_ptr->t_money_offer >= (c_ptr->t_money_receive + totalSum))
					t_Head = removeNegTrans(t_Head, trans_id);
			}
			
			// Checking to see if there are other offers
			c_ptr = checkNegOffer(t_Head, 1);
			if (!c_ptr)
				trans_id = 0;
		}
	}
	
	// Make Negotiations
	else if (mode == 2)
	{
		// Finding a color group that require only one more property to finish for this current player
		for (int i = 0; i < 40 && fFlag != 1; i++) {
			if (properties[i].Owner == This_Player.getID()) {
				for (int j = 0; j < 40; j++) {
					if (strcmp(properties[i].Color, properties[j].Color) == zeroCheck && properties[j].Owner != This_Player.getID()) {
						if (properties[j].Owner == zeroCheck)
							fFlag--;
						else {
							fFlag++;
							pPos = j;
							bPos = i;
							strcpy_s(color, 50, properties[i].Color);
						}
					}
				}

				if (fFlag != 1) {
					fFlag = 0;
					bPos = 0;
					pPos = 0;
				}
			}
		}

		// If the above succeeded
		if (fFlag == 1)
		{
			fFlag = 0;

			// Finding a color group that require only one more property to finish other player	
			for (int i = 0; i < 40 && fFlag == zeroCheck; i++) {
				if (properties[i].Owner == properties[pPos].Owner && strcmp(color, properties[i].Color) != 0) {
					for (int j = 0; j < 40; j++) {
						if (strcmp(properties[i].Color, properties[j].Color) == zeroCheck && properties[j].Owner != properties[pPos].Owner) {
							if (properties[j].Owner == properties[bPos].Owner) {
								f2Flag++;
								rPos = j;
							}
							else
								f2Flag--;
						}
					}

					// "Head to Head" - If we complete the other player color group too
					if (f2Flag == 1)
					{
						fFlag = 1;

						int index = 0;

						// No money involved in "Head to Head"
						neg_offer = 0;
						neg_receive = 0;

						// Getting the properties
						for (int m = 0; m < 28; m++) {

							// Desired property
							if (NFlagRealIndex[m] == pPos)
								Nflag2[m] = 1;

							// Offered property
							if (NFlagRealIndex[m] == rPos)
								Nflag[m] = 1;
						}

						// Create the transaction
						t_Head = createNegTrans(t_Head, properties[pPos].Owner);
						memset(Nflag, 0, sizeof(Nflag));
						memset(Nflag2, 0, sizeof(Nflag2));
						neg_offer = neg_receive = 0;
						return 1;
					}

					// "Advance Only" - bot complete a color group, other player gets another property only (and not complete his color group)
					else if (f2Flag == zeroCheck) {
						fFlag = 1;

						int index = 0;

						// Money compensation for not completing the other player color group
						neg_receive = 0;
						neg_offer = (int)((properties[pPos].Buy_Price + (properties[pPos].House_Price * properties[pPos].House_Count)) * pricePercentage);

						// Getting the properties
						for (int m = 0; m < 28; m++) {

							// Desired property
							if (NFlagRealIndex[m] == pPos)
								Nflag2[m] = 1;

							// Offered property
							if (NFlagRealIndex[m] == rPos)
								Nflag[m] = 1;
						}

						// Create the transaction
						t_Head = createNegTrans(t_Head, properties[pPos].Owner);
						memset(Nflag, 0, sizeof(Nflag));
						memset(Nflag2, 0, sizeof(Nflag2));
						neg_offer = neg_receive = 0;
						return 1;
					}

					// "Money Only" - bot complete a color group, other player gets only money
					else if (f2Flag <= -1)
					{
						fFlag = 0;
						int index = 0;

						// Money compensation for not completing the other player color group
						neg_receive = 0;
						neg_offer = (int)((properties[pPos].Buy_Price + (properties[pPos].House_Price * properties[pPos].House_Count)) * botHousePercentage);

						// Getting the properties
						for (int m = 0; m < 28; m++) {

							// Desired property
							if (NFlagRealIndex[m] == pPos)
								Nflag2[m] = 1;
						}

						// Create the transaction
						t_Head = createNegTrans(t_Head, properties[pPos].Owner);
						memset(Nflag, 0, sizeof(Nflag));
						memset(Nflag2, 0, sizeof(Nflag2));
						neg_offer = neg_receive = 0;
						return 1;
					}
				}
			}
		}
	}

	return -1;
}

int completeGroup(int pos, int player) 
{
	// Checking to see if the card whos position was received complete a color group
	int flag = 0, pCount = 0;

	for (int i = 0; i < 40; i++) {
		if (strcmp(properties[i].Color, properties[pos - 1].Color) == zeroCheck) {
			pCount++;
			if (properties[i].Owner == player)
				flag++;
		}
	}

	// If it is the only property were missing from this color group = COMPLETE COLOR GROUP
	if (pCount - flag == 1)
		return 1;

	// Else, it will advance us only = ADVANCE COLOR GROUP
	else if (flag == 1)
		return 0;
	
	return -1;
}

void botAuction()
{
	// If there are only computer players, make the timer low so that the auction would end fast
	if (aucCompOnly == true) {
		if (botChoiceDelay == false) {
			timer = timer9;		// Pretty low	
			botChoiceDelay = true;
		}
	}

	// Else, continue as usual
	else {
		if (botChoiceDelay == false) {
			timer = timer8;	// 2 seconds	
			botChoiceDelay = true;
		}
	}

	// Bot conditions for participating in the auction according to various states and properties
	if (timer == zeroCheck) {
		int priority = completeGroup(CurCard, currentPlayer);

		// Top priority = BUY AT ALL COST, biggest jumps
		if (priority == 1 && bidPrice <= (int)(This_Player.getMoney() * botPriceMustBuy))
			auction(2, 25);

		// Second top priority = BUY, big jumps
		else if (priority == zeroCheck && bidPrice <= (int)(This_Player.getMoney() * priceHalf))
			auction(2, 10);

		// Not a priority, but try to get nonetheless (until 40% of avaliable money AND if you can pay the biggest rent on board)
		else if (bidPrice <= (int)(This_Player.getMoney() * priceHalf) && This_Player.getMoney() >= (getMaxRent() + (int)(getMaxRent() * botPriceMaxRent)))
			auction(2, 1);

		// Else, quit participating
		else auction(1, NULL);

		botChoiceDelay = false;
	}
}

void updateHighScores(const char *name, int points, int money, int rounds) {	
	int i = 0, pMin = -1, error = 0;
	char query[256];

	// CONNECT TO SQL, GET DATA FROM TABLE
	mysql_query(conn, "SELECT * FROM `High Score`");
	res = mysql_store_result(conn);

	while ((row = mysql_fetch_row(res))) {
		strcpy_s(highscore[i].name, 10, row[1]);
		highscore[i].points = atoi(row[2]);
		highscore[i].rounds = atoi(row[3]);
		highscore[i].money = atoi(row[4]);
		i++;
	}

	if (res != NULL)
		mysql_free_result(res);
	
	i = 0;

	// If there is at least one record in the table
	if (strlen(highscore[i].name)) {
		
		// Searching for the player which has a score below our current player
		while ((strlen(highscore[i].name) != 0) && i < 10) {
			if (highscore[i].points <= points) {
				pMin = i;
				i = 11;
			}

			i++;
		}

		// If the player who just won has more points then one of the other listed
		// Else, no need to add the player to the high scores
		if (pMin != -1) {

			for (int i = 8; i >= pMin; i--) {
				if (strlen(highscore[i].name)) {
					strcpy_s(highscore[i + 1].name, 10, highscore[i].name);
					highscore[i + 1].money = highscore[i].money;
					highscore[i + 1].points = highscore[i].points;
					highscore[i + 1].rounds = highscore[i].rounds;
				}
			}

			// Inserting the new record
			strcpy_s(highscore[pMin].name, 10, name);
			highscore[pMin].money = money;
			highscore[pMin].points = points;
			highscore[pMin].rounds = rounds;
		}

		// Emptying the table
		sprintf_s(query, sizeof(query), "DELETE FROM `High Score`");
		error = mysql_query(conn, query);
		if (error != NULL)
			cout << mysql_error(conn) << endl;
		else {
			// Updating the SQL Table
			for (i = 0; i < 10; i++) {
				if (strlen(highscore[i].name)) {
					sprintf_s(query, sizeof(query), "INSERT INTO `High Score`(id, name, points, rounds, money) VALUES(%d, '%s', %d, %d, %d)", (i + 1) , highscore[i].name, highscore[i].points, highscore[i].rounds, highscore[i].money);
					error = mysql_query(conn, query);
					if (error != NULL)
						cout << mysql_error(conn) << endl;
				}
			}
		}
	}

	// Else, this is the first record
	else {
		sprintf_s(query, sizeof(query), "INSERT INTO `High Score`(id, name, points, rounds, money) VALUES(%d, '%s', %d, %d, %d)", (i + 1), highscore[i].name, highscore[i].points, highscore[i].rounds, highscore[i].money);
		error = mysql_query(conn, query);
		if (error != NULL)
			cout << mysql_error(conn) << endl;
	}
}

int removeDebt(int money) {

	int pMoney = 0;

	// Checking to see if the player will have enough money after selling his properties to cover his debt
	for (int i = 39; i >= 0; i--) {
		if (properties[i].Owner == This_Player.getID()) {
			if (properties[i].Category == zeroCheck) {
				pMoney += (int)(properties[i].Buy_Price * priceHalf);
				if (properties[i].Got_Hotel == true)
					pMoney += (int)(properties[i].Hotel_Price * priceHalf);
				pMoney += (int)(properties[i].House_Price * properties[i].House_Count * priceHalf);
			}
			else if (properties[i].Category == 1 || properties[i].Category == 2)
				pMoney += (int)(properties[i].Buy_Price * priceHalf);
		}
	}

	// If the player has enough money after selling some properties
	if (pMoney >= money) {
		while (pMoney >= money) {
			for (int i = 39; i >= 0; i--) {
				if (properties[i].Owner == This_Player.getID()) {
					if (properties[i].Category == zeroCheck) {
						if (properties[i].Got_Hotel == true)
							pMoney -= (int)(properties[i].Hotel_Price * priceHalf);
						pMoney -= (int)(properties[i].House_Price * properties[i].House_Count * priceHalf);
						pMoney -= (int)(properties[i].Buy_Price * priceHalf);
						properties[i].Owner = 0;
						properties[i].Got_Hotel = false;
						properties[i].House_Count = 0;
					}
					else if (properties[i].Category == 1 || properties[i].Category == 2) {
						pMoney -= (int)(properties[i].Buy_Price * priceHalf);
						properties[i].Owner = 0;
					}
				}
			}
		}

		// Pay the player
		pay(This_Player.getID(), pMoney);
	}

	// Else, not enough money even if we sell all the property
	else {
		// Remove the player from the game
		removePlayer();
		return 0;
	}

	return 1;
}
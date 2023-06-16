CST8237 Lab 2

1) Study the provided class Diagram.

2) The Classes have been created for you. Implement the TODO's in the following classes .cpp file:
    ASimplePawn
    ACustomMovementPawn
    AMyPlayerController
    And Study UCustomMovementComponent

3) Create Blueprints for each class in the Editor after you have compiled and run the editor from visual studio.
   The blueprints to create are:
   Class: AUELab2GameModeBase and name it BP_UELab2GameModeBase 
   Class: ASimplePawn and name it BP_SimplePawn and set it up by setting the Mesh.
   Class: ACustomMovementPawn and name it BP_CustomMovementPawn and set it up by setting the Mesh.
   Class: AMyPlayerController and name it BP_MyPlayerController

   Place them into a folder named Blueprints.

4) Open the BP_UELab2GameModeBase and set a Default Pawn Class to either BP_SimplePawn or BP_CustomMovementPawn. Also set the Player Controller Class to BP_MyPlayerController. Once you have setup the Game Mode   associate it with the game by setting the global game mode it Edit->Project Settings->Maps and Modes.

5) Create a Level and save it. Add a few different types of Pawns i.e 3 Simple Pawns and 3 Custom Movement Pawns. Set the Level as the "Editor Startup Map"

6) Create the Input bindings in the editor. You will need:
    Action Mappings:
    "ChangePawn" bound to the space bar button (Or a button of your choice)

    Axis Mappings
    "MoveForward" has two bindings, one to move forward (1.0) and one to move backward (-1.0)

    "MoveRight" has two bindings, one to move right (1.0) and one to move left (-1.0)

    "LookUp" has one binding which is bound to a single mouse axis

    "LookRight" has one binding which is bound to a single mouse axis

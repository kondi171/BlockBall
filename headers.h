#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
/// <h1>Brick Class describe a block coordinates in Game</h1>
   class Brick {
    public:
        int x1; /*!< x1 describe point x1 of block - xStart */
        int x2; /*!< x2 describe point x2 of block - xEnd */
        int y1; /*!< y1 describe point y1 of block - yStart */
        int y2; /*!< y2 describe point y2 of block - yEnd */
    };
/// <h1>Hide a console window</h1>
void Stealth();
/// <h1>Initialize Allegro Library</h1> @return always 0
int InitializeLibrary();
/** <h1>Initialize Main Window</h1>
    @param ScreenWidth set a Screen Width of window
    @param ScreenHeight set a Screen Height of window
    @param FullScreen set a statement full screen or windowed
    @return window to display or 0
*/
ALLEGRO_DISPLAY *DisplayWindow(int ScreenWidth,int ScreenHight, bool FullScreen);
/** <h1>Destroy elements of Allegro Library</h1>
    @param EventQueue destroy Event Queue
    @param BaseFont destroy Base font
    @param FirstFont destroy First Font
    @param SecondFont destroy Second Font
    @param MicroFont destroy Micro Font
    @param Display destroy Allegro window
    @param Heart destroy heart bitmap
    @param BreakHeart destroy break heart bitmap
*/
void AllDestroy(ALLEGRO_EVENT_QUEUE *EventQueue, ALLEGRO_FONT * BaseFont, ALLEGRO_FONT * FirstFont,
               ALLEGRO_FONT * SecondFont,ALLEGRO_FONT * MicroFont, ALLEGRO_DISPLAY * Display, ALLEGRO_BITMAP * Heart,ALLEGRO_BITMAP * BreakHeart);
/** <h1>Destroy Allegro Samples</h1>
    @param BallBlock destroy Ball-Block impact sample
    @param WallImpact destroy Ball-Wall impact sample
    @param PaddleImpact destroy Ball-Paddle impact sample
    @param LostLife destroy lost life sample
    @param End destroy endgame sample
    @param MainMusic destroy main music sample
    @param MenuMusic destroy menu music sample
*/
void DestroySounds(ALLEGRO_SAMPLE* BallBlock,ALLEGRO_SAMPLE * WallImpact,ALLEGRO_SAMPLE * PaddleImpact,
                    ALLEGRO_SAMPLE * LostLife, ALLEGRO_SAMPLE * End, ALLEGRO_SAMPLE * MainMusic, ALLEGRO_SAMPLE * MenuMusic);
/** <h1>Destroy Allegro Timers</h1>
    @param MainTimer destroy main timer
    @param BallImpactTimer destroy Ball of first player impacts timer
    @param BallTwoImpactTimer destroy Ball of second player impacts timer
    @param PaddleOneImpactTimer destroy paddle of first player impacts timer
    @param PaddleTwoImpactTimer destroy paddle of second player impacts timer
*/
void DestroyTimers(ALLEGRO_TIMER * MainTimer,ALLEGRO_TIMER * BallOneImpactTimer,ALLEGRO_TIMER * BallTwoImpactTimer,
                   ALLEGRO_TIMER * PaddleOneImpactTimer,ALLEGRO_TIMER * PaddleTwoImpactTimer);
/** <h1>Draw The Main Menu</h1>
    @param BaseFont function range increase of Base Font
    @param FirstFont function range increase of First font
    @param FirstColor function range increase of First Color
    @param TitleColor function range increase of Title Color
    @param ScreenWidth function range increase a Screen Width of window
    @param ScreenHeight function range increase a Screen Height of window
    @param Option store which option in main menu has been chosen
    @param FullScreen check which of display mode is chosen: FullScreen or Windowed
*/
void Intro(ALLEGRO_FONT *BaseFont,ALLEGRO_FONT *FirstFont,const int FirstColor[],const int TitleColor[],
           int ScreenWidth,int ScreenHight, int Option, bool Fullscreen);
/** <h1>Draw The Main Game </h1>
    @param ScreenWidth function range increase a Screen Width of window
    @param ScreenHeight function range increase a Screen Height of window
    @param TitleColor function range increase of Title Color
    @param FirstColor function range increase of First Color
    @param BaseFont function range increase of Base Font
    @param FirstFont function range increase of First font
    @param SecondFont function range increase of Second font
    @param HelpFont function range increase of Micro font
    @param PlayerOneScore show actual score of first player
    @param PlayerTwoScore show actual score of second player
    @param PlayerOneLife show actual lives of first player
    @param PlayerTwoLife show actual lives of second player
    @param PlayerOneSpeedBall show actual ball multiplier of first player
    @param PlayerTwoSpeedBall show actual ball multiplier of second player
    @param PlayerOneBlock show destroyed block of first player
    @param PlayerTwoBlock show destroyed block of second player
    @param Heart range increase of heart bitmap
    @param BreakHeart range increase of break heart bitmap
    @param Exit statement of pause (in pause we can quit the game)
    @param GameOver statement if true end game else continue game
    @param MainMusic play the main music sample
*/
void DrawBoard(int ScreenWidth,int ScreenHeight,int TitleColor[],int FirstColor[],ALLEGRO_FONT * BaseFont,
               ALLEGRO_FONT * FirstFont,ALLEGRO_FONT * SecondFont,ALLEGRO_FONT * HelpFont,int PlayerOneScore, int PlayerTwoScore,
               int PlayerOneLife, int PlayerTwoLife,float PlayerOneSpeedBall,float PlayerTwoSpeedBall,int PlayerOneBlock,
               int PlayerTwoBlock,ALLEGRO_BITMAP * Heart, ALLEGRO_BITMAP * BreakHeart, bool Exit,bool GameOver,ALLEGRO_SAMPLE * MainMusic);
/** <h1>Implements Collision of block</h1>
    @param NewBlock[] values of blocks Co-ordinates
    @param Index value of actual block
    @param BallBlock sample of Ball-Block impact
    @return true if collision happened or false if not
*/
bool BlockCollision(Brick NewBlock[],int Index,ALLEGRO_SAMPLE * BallBlock);
/** <h1>Check what coordinates are colliding</h1>
    @param BallY Ball Y position
    @param BallX Ball X position
    @param ReverseBall actual side ball moves on for Reverse
    @param NewBlock[] increase range of Blocks
    @param BallBlock sample of Ball-Block impact
    @return true if collision happened or false if not
*/
bool CheckCollision(int BallY, int BallX,bool ReverseBall,Brick NewBlock[],ALLEGRO_SAMPLE * BallBlock);
/** <h1>Show players lives</h1>
    @param PlayerOneLife show actual lives of first player
    @param PlayerTwoLife show actual lives of second player
    @param Heart range increase of heart bitmap
    @param BreakHeart range increase of break heart bitmap
*/
void ShowLife(int PlayerOneLife, int PlayerTwoLife, ALLEGRO_BITMAP * Heart, ALLEGRO_BITMAP * BreakHeart);
/** <h1>Set the menu pointer</h1>
    @param ScreenWidth increase range a Screen Width of window
    @param ScreenHeight increase range a Screen Height of window
    @param Option store which option in main menu has been chosen
*/
void Set(int Option, int ScreenHeight, int ScreenWidth);
/** <h1>Setting Fullscreen/Windowed option</h1>
    @param Option store which option in main menu has been chosen
    @param Select if true accept the change of window displaying
    @param Display Allegro window
*/
void Outro(ALLEGRO_FONT *FirstFont, ALLEGRO_FONT *SecondFont, int FirstColor[],int TitleColor[],
           int ScreenWidth,int ScreenHight, int Option);
/** <h1>Select Game Mode State</h1>
    @param BaseFont function range increase of Second font
    @param FirstFont function range increase of First font
    @param SecondFont function range increase of Second font
    @param TitleColor function range increase of Title Color
    @param FirstColor function range increase of First Color
    @param ScreenWidth increase range a Screen Width of window
    @param ScreenHeight increase range a Screen Height of window
    @param Option store which option in main menu has been chosen
*/
void SelectMode(ALLEGRO_FONT *BaseFont,ALLEGRO_FONT *FirstFont,ALLEGRO_FONT * SecondFont,int FirstColor[],int TitleColor[],
                int ScreenWidth,int ScreenHight, int Option);
/** <h1>Help State</h1>
    @param FirstFont function range increase of First font
    @param SecondFont function range increase of Second font
    @param ScreenWidth increase range a Screen Width of window
    @param ScreenHeight increase range a Screen Height of window
    @param FirstColor function range increase of First Color
    @param TitleColor function range increase of Title Color
    @param Option store which option in main menu has been chosen
*/
void Help(ALLEGRO_FONT * FirstFont,ALLEGRO_FONT * SecondFont, int ScreenWidth, int ScreenHeight,int FirstColor[],
           int TitleColor[], int Option);
/** <h1>Credits State</h1>
    @param FirstFont function range increase of First font
    @param SecondFont function range increase of Second font
    @param BaseFont function range increase of Base Font
    @param ScreenWidth increase range a Screen Width of window
    @param ScreenHeight increase range a Screen Height of window
    @param FirstColor function range increase of First Color
    @param TitleColor function range increase of Title Color
    @param Option store which option in main menu has been chosen
*/
void Credits(ALLEGRO_FONT * FirstFont, ALLEGRO_FONT * SecondFont, ALLEGRO_FONT * BaseFont,
              int ScreenWidth, int ScreenHeight,int FirstColor[], int TitleColor[], int Option);
/** <h1>Increase ball speed</h1>
    @param CurrentSpeed actual ball speed
    @param DifficultLevel set difficult level thanks to this function can multiply ball speed
    @return multiplied ball speed
*/
float ImproveBallSpeed(float CurrentSpeed, int DifficultLevel);
/** <h1>Reverse ball move</h1>
    @param CurrentBall which ball to reverse
    @return reversed move of ball
*/
float ReverseBall(float CurrentBall);
/** <h1>Counting ball speed</h1>
    @param Speed actual speed of ball
    @return speed ball
*/
float BallSpeed(float Speed);

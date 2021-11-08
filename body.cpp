#include "headers.h"
/// <h1>Hide a console window</h1>
void Stealth(){
 HWND Stealth;
 AllocConsole();
 Stealth = FindWindowA("ConsoleWindowClass", NULL);
 ShowWindow(Stealth,0);
}
/** <h1>Initialize Allegro Library</h1>
    <p>if initialization false show error statement else initialize library</p>
    <ul>
        <li>Fonts</li>
        <li>TTF formats for fonts</li>
        <li>Primitives</li>
        <li>Keyboard listeners</li>
        <li>Audio</li>
        <li>Codecs for Audio</li>
    </ul>
*/
int InitializeLibrary(){
    al_init();
    if(!al_init()){
        al_show_native_message_box(NULL,"Error",NULL,"Couldn't initialize a library!",NULL,NULL);
        return 0;
    } else {
        al_init_font_addon();
        al_init_ttf_addon();
        al_init_primitives_addon();
        al_init_image_addon();
        al_install_keyboard();
        al_install_audio();
        al_init_acodec_addon();
        return 0;
    }
}
/** <h1>Initialize Main Window</h1>
    <p>if initialization false show error statement else initialize Allegro window</p>
    <p>if Fullscreen equals true display full screen else display windowed</p>
    @param ScreenWidth set a Screen Width of window
    @param ScreenHeight set a Screen Height of window
    @param FullScreen set a statement full screen or windowed
    @return window to display or 0
*/
ALLEGRO_DISPLAY *DisplayWindow(int ScreenWidth,int ScreenHeight, bool FullScreen){
    if(FullScreen) al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    else al_set_new_display_flags(ALLEGRO_WINDOWED);
    ALLEGRO_DISPLAY *Display  = al_create_display(ScreenWidth,ScreenHeight);
    al_set_window_title(Display,"BlockBall");
    if(!Display){
        al_show_native_message_box(Display, "Creating fail", "Error!", "Failed to create display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }
    al_hide_mouse_cursor(Display);
    return Display;
}
/** <h1>Set the menu pointer</h1>
    <p> draw a pointer (circle primitive) where the option is currently set </p>
    <h4>If statement</h4>
    <ul>
        <li>if Option equals 1 then pointer is on "Start Game"</li>
        <li>if Option equals 2 then pointer is on "Set Fullscreen/Windowed"</li>
        <li>if Option equals 3 then pointer is on "How to play?"</li>
        <li>if Option equals 4 then pointer is on "Credits"</li>
        <li>if Option equals 5 then pointer is on "Quit Game"</li>
        <li>if Option equals 6 then pointer is on "Easy Mode" in select state</li>
        <li>if Option equals 7 then pointer is on "Medium Mode" in select state</li>
        <li>if Option equals 8 then pointer is on "Hard Mode" in select state</li>
        <li>if Option equals 9 then pointer is on "Versus Mode" in select state</li>
        <li>if Option equals 10 then pointer is on "Back to Menu" in Help state/Credits state</li>
        <li>if Option equals 11 then pointer is on "No!" in endgame state</li>
        <li>if Option equals 12 then pointer is on "Yes!" in endgame state</li>
    </ul>
    @param ScreenWidth increase range a Screen Width of window
    @param ScreenHeight increase range a Screen Height of window
    @param Option store which option in main menu has been chosen
*/
void Set(int Option, int ScreenHeight, int ScreenWidth){
    int x = 0;
    float y = 0;
    if(Option == 1 && (Option != 11 || Option != 12)){
        x = 305;
        y = ScreenHeight / 2.9;
    }
    else if(Option == 2 && (Option != 11 || Option != 12)){
        x = 280;
        y = ScreenHeight / 2.44;
    }
    else if(Option == 3 && (Option != 11 || Option != 12)){
        x = 290;
        y = ScreenHeight / 2.1;
    }
    else if(Option == 4 && (Option != 11 || Option != 12)){
        x = 322;
        y = ScreenHeight / 1.84;
    }
    else if(Option == 5 && (Option != 11 || Option != 12)){
        x = 310;
        y = ScreenHeight / 1.64;
    }
    else if(Option == 6 && (Option != 11 || Option != 12)){
        x = 295;
        y = ScreenHeight / 2.9;
    }
    else if(Option == 7 && (Option != 11 || Option != 12)){
        x = 275;
        y = ScreenHeight / 2.3 - 5;
    }
    else if(Option == 8 && (Option != 11 || Option != 12)){
        x = 275;
        y = ScreenHeight / 2 + 7;
    }
    else if(Option == 9 && (Option != 11 || Option != 12)){
        x = 275;
        y = ScreenHeight / 2 + 55;
    }
    else if(Option == 10){
        x = ScreenWidth/2.58;
        y = ScreenHeight / 1.095;
    }
    else if(Option == 11){
        x = 250;
        y = ScreenHeight / 1.98;
    }
    else if(Option == 12){
        x = 460;
        y = ScreenHeight / 1.98;
    }

    al_draw_filled_circle(x, y + 6, 8, al_map_rgb(255, 100, 40));
    al_flip_display();
}
/** <h1>Draw The Main Menu</h1>
    <p>Function draw a options in main menu and calls <b>Set()</b> for setting pointer</p>
    @param BaseFont function range increase of Base Font
    @param FirstFont function range increase of First font
    @param FirstColor function range increase of First Color
    @param TitleColor function range increase of Title Color
    @param ScreenWidth function range increase a Screen Width of window
    @param ScreenHeight function range increase a Screen Height of window
    @param Option store which option in main menu has been chosen
    @param FullScreen check which of display mode is chosen: FullScreen or Windowed
*/
void Intro(ALLEGRO_FONT *BaseFont,ALLEGRO_FONT *FirstFont,const int FirstColor[],const int TitleColor[],int ScreenWidth,int ScreenHeight, int Option, bool Fullscreen){
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(BaseFont, al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]), ScreenWidth/2,ScreenHeight/10, ALLEGRO_ALIGN_CENTER, "BlockBall");
    al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/3, ALLEGRO_ALIGN_CENTER, "START GAME");
    if(!Fullscreen) al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/2.51, ALLEGRO_ALIGN_CENTER, "SET FULLSCREEN");
    if(Fullscreen) al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/2.51, ALLEGRO_ALIGN_CENTER, "SET WINDOWED");
    al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/2.15, ALLEGRO_ALIGN_CENTER, "HOW TO PLAY?");
    al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/1.88, ALLEGRO_ALIGN_CENTER, "CREDITS");
    al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/1.67, ALLEGRO_ALIGN_CENTER, "QUIT GAME");
    Set(Option, ScreenHeight, ScreenWidth);

}
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
                 ALLEGRO_FONT * SecondFont, ALLEGRO_FONT * MicroFont, ALLEGRO_DISPLAY * Display, ALLEGRO_BITMAP * Heart,ALLEGRO_BITMAP * BreakHeart){
    al_destroy_event_queue(EventQueue);
    al_destroy_font(BaseFont);
    al_destroy_font(FirstFont);
    al_destroy_font(SecondFont);
    al_destroy_font(MicroFont);
    al_destroy_display(Display);
    al_destroy_bitmap(Heart);
    al_destroy_bitmap(BreakHeart);
}
/** <h1>Destroy Allegro Samples</h1>
    @param BallBlock destroy Ball-Block impact sample
    @param WallImpact destroy Ball-Wall impact sample
    @param PaddleImpact destroy Ball-Paddle impact sample
    @param LostLife destroy lost life sample
    @param End destroy endgame sample
    @param MainMusic destroy main music sample
    @param MenuMusic destroy menu music sample
*/
void DestroySounds(ALLEGRO_SAMPLE* BallBlock,ALLEGRO_SAMPLE * WallImpact,ALLEGRO_SAMPLE * PaddleImpact, ALLEGRO_SAMPLE * LostLife, ALLEGRO_SAMPLE * End, ALLEGRO_SAMPLE * MainMusic,ALLEGRO_SAMPLE * MenuMusic){
    al_destroy_sample(BallBlock);
    al_destroy_sample(WallImpact);
    al_destroy_sample(PaddleImpact);
    al_destroy_sample(LostLife);
    al_destroy_sample(End);
    al_destroy_sample(MainMusic);
    al_destroy_sample(MenuMusic);
}
/** <h1>Destroy Allegro Timers</h1>
    @param MainTimer destroy main timer
    @param BallImpactTimer destroy Ball of first player impacts timer
    @param BallTwoImpactTimer destroy Ball of second player impacts timer
    @param PaddleOneImpactTimer destroy paddle of first player impacts timer
    @param PaddleTwoImpactTimer destroy paddle of second player impacts timer
*/
void DestroyTimers(ALLEGRO_TIMER * MainTimer,ALLEGRO_TIMER * BallOneImpactTimer,ALLEGRO_TIMER * BallTwoImpactTimer,
                   ALLEGRO_TIMER * PaddleOneImpactTimer,ALLEGRO_TIMER * PaddleTwoImpactTimer){
    al_destroy_timer(MainTimer);
    al_destroy_timer(BallOneImpactTimer);
    al_destroy_timer(BallTwoImpactTimer);
    al_destroy_timer(PaddleOneImpactTimer);
    al_destroy_timer(PaddleTwoImpactTimer);

}
/** <h1>Draw The Main Game Board</h1>
    @param BaseFont function range increase of Base Font
    @param FirstFont function range increase of First font
    @param FirstColor function range increase of First Color
    @param TitleColor function range increase of Title Color
    @param ScreenWidth function range increase a Screen Width of window
    @param ScreenHeight function range increase a Screen Height of window
    @param Option store which option in main menu has been chosen
    @param FullScreen check which of display mode is chosen: FullScreen or Windowed
    <p>This Function draw all content of main game like:</p>
    <ul>
        <li>Balls</li>
        <li>Paddles</li>
        <li>
            Statistics
            <ol>
                <li>Lives - call <b>ShowLife()</b></li>
                <li>Scores</li>
                <li>Ball Multiplier</li>
                <li>Destroyed Blocks</li>
            </ol>
        </li>
        <li>Blocks</li>
        <li>All board contours</li>
        <li>Pause State</li>
    </ul>
    <p>Function count number of lives (add points for destroyed life) and make a decision of end game. </p>
*/
void DrawBoard(int ScreenWidth,int ScreenHeight,int TitleColor[],int FirstColor[],ALLEGRO_FONT * BaseFont,
               ALLEGRO_FONT * FirstFont,ALLEGRO_FONT * SecondFont,ALLEGRO_FONT * HelpFont,int PlayerOneScore, int PlayerTwoScore,
               int PlayerOneLife, int PlayerTwoLife,float PlayerOneSpeedBall,float PlayerTwoSpeedBall,int PlayerOneBlock,int PlayerTwoBlock,ALLEGRO_BITMAP * Heart, ALLEGRO_BITMAP * BreakHeart,
               bool Exit,bool GameOver,ALLEGRO_SAMPLE * MainMusic){

    al_draw_line(100,0,100,600,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),5);
    al_draw_line(700,0,700,600,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),5);

    al_draw_filled_rectangle(0,0,100,600,al_map_rgb(30,30,30));
    al_draw_filled_rectangle(800,0,700,600,al_map_rgb(60,60,60));

    al_draw_line(100,0,100,600,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),5);
    al_draw_line(700,0,700,600,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),5);

    al_draw_filled_rectangle(0,0,100,600,al_map_rgb(30,30,30));
    al_draw_filled_rectangle(800,0,700,600,al_map_rgb(30,30,30));

    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight/50,ALLEGRO_ALIGN_CENTER,"PLAYER 1");
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight/50,ALLEGRO_ALIGN_CENTER,"PLAYER 2");
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight/8,ALLEGRO_ALIGN_CENTER,"SCORE:");
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight/8,ALLEGRO_ALIGN_CENTER,"SCORE:");
    al_draw_textf(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight/5,ALLEGRO_ALIGN_CENTER,"%d",PlayerOneScore);
    al_draw_textf(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight/5,ALLEGRO_ALIGN_CENTER,"%d",PlayerTwoScore);

    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight/3.5,ALLEGRO_ALIGN_CENTER,"BALL");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight/3.1,ALLEGRO_ALIGN_CENTER,"MULTIPLIER:");
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight/3.5,ALLEGRO_ALIGN_CENTER,"BALL");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight/3.1,ALLEGRO_ALIGN_CENTER,"MULTIPLIER:");
    al_draw_textf(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight/2.5,ALLEGRO_ALIGN_CENTER,"x %.2f",PlayerTwoSpeedBall);
    al_draw_textf(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight/2.5,ALLEGRO_ALIGN_CENTER,"x %.2f",PlayerOneSpeedBall);

    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight/2,ALLEGRO_ALIGN_CENTER,"DESTROYED");
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight/1.9,ALLEGRO_ALIGN_CENTER,"BLOCKS:");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight/2,ALLEGRO_ALIGN_CENTER,"DESTROYED");
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight/1.9,ALLEGRO_ALIGN_CENTER,"BLOCKS:");
    al_draw_textf(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight/1.5,ALLEGRO_ALIGN_CENTER,"%d",PlayerTwoBlock);
    al_draw_textf(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight/1.5,ALLEGRO_ALIGN_CENTER,"%d",PlayerOneBlock);

    al_draw_line(100,40,0,40,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),3);
    al_draw_line(700,40,800,40,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),3);

    al_draw_line(100,500,0,500,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),3);
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/15,ScreenHeight-90,ALLEGRO_ALIGN_CENTER,"LIFE:");
    al_draw_line(100,540,0,540,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),3);

    al_draw_line(700,500,800,500,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),3);
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.07,ScreenHeight-90,ALLEGRO_ALIGN_CENTER,"LIFE:");
    al_draw_line(700,540,800,540,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),3);
    ShowLife(PlayerOneLife,PlayerTwoLife,Heart,BreakHeart);
    if(Exit){
        al_draw_text(BaseFont, al_map_rgb(TitleColor[0], TitleColor[0], TitleColor[0]), ScreenWidth/2, ScreenHeight/2.9, ALLEGRO_ALIGN_CENTER, "PAUSE");
        al_draw_text(SecondFont, al_map_rgb(TitleColor[0], TitleColor[0], TitleColor[0]), ScreenWidth/2, ScreenHeight/2, ALLEGRO_ALIGN_CENTER, "If you want to quit press ENTER, if not press SPACE!");
        al_draw_text(SecondFont, al_map_rgb(TitleColor[0], TitleColor[0], TitleColor[0]), ScreenWidth/2, ScreenHeight/1.5, ALLEGRO_ALIGN_CENTER, "P - Save Game");
        al_draw_text(SecondFont, al_map_rgb(TitleColor[0], TitleColor[0], TitleColor[0]), ScreenWidth/2, ScreenHeight/1.4, ALLEGRO_ALIGN_CENTER, "O - Load Game");
        Exit = false;
    }
    if(GameOver) {
        al_clear_to_color(al_map_rgb(0,0,0));
        if(PlayerOneLife == 3)   PlayerTwoScore += 3000;
        else if(PlayerOneLife == 2) PlayerTwoScore += 2000;
        else if(PlayerOneLife == 1) PlayerTwoScore += 1000;

        if(PlayerTwoLife == 3)   PlayerOneScore += 3000;
        else if(PlayerTwoLife == 2) PlayerOneScore += 2000;
        else if(PlayerTwoLife == 1) PlayerOneScore += 1000;

        if(PlayerOneScore < PlayerTwoScore) al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/2,ScreenHeight/2,ALLEGRO_ALIGN_CENTER,"PLAYER 1 WINS!");
        if(PlayerOneScore > PlayerTwoScore) al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/2,ScreenHeight/2,ALLEGRO_ALIGN_CENTER,"PLAYER 2 WINS!");
        al_draw_text(BaseFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/2,ScreenHeight/5,ALLEGRO_ALIGN_CENTER,"GAME OVER");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/13,ScreenHeight/10,ALLEGRO_ALIGN_CENTER,"PLAYER 1");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.1,ScreenHeight/10,ALLEGRO_ALIGN_CENTER,"PLAYER 2");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/13,ScreenHeight/5,ALLEGRO_ALIGN_CENTER,"SCORE:");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.1,ScreenHeight/5,ALLEGRO_ALIGN_CENTER,"SCORE:");
        al_draw_textf(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/1.1,ScreenHeight/4,ALLEGRO_ALIGN_CENTER,"%d",PlayerOneScore);
        al_draw_textf(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/13,ScreenHeight/4,ALLEGRO_ALIGN_CENTER,"%d",PlayerTwoScore);
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/13,ScreenHeight/2.3,ALLEGRO_ALIGN_CENTER,"BALL");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/13,ScreenHeight/2,ALLEGRO_ALIGN_CENTER,"MULTIPLIER:");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.1,ScreenHeight/2.3,ALLEGRO_ALIGN_CENTER,"BALL");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.1,ScreenHeight/2,ALLEGRO_ALIGN_CENTER,"MULTIPLIER:");
        al_draw_textf(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/1.1,ScreenHeight/1.7,ALLEGRO_ALIGN_CENTER,"x %.2f",PlayerTwoSpeedBall);
        al_draw_textf(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/13,ScreenHeight/1.7,ALLEGRO_ALIGN_CENTER,"x %.2f",PlayerOneSpeedBall);

        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/13,ScreenHeight/1.5,ALLEGRO_ALIGN_CENTER,"DESTROYED");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/13,ScreenHeight/1.4,ALLEGRO_ALIGN_CENTER,"BLOCKS:");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.1,ScreenHeight/1.5,ALLEGRO_ALIGN_CENTER,"DESTROYED");
        al_draw_text(FirstFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.1,ScreenHeight/1.4,ALLEGRO_ALIGN_CENTER,"BLOCKS:");
        al_draw_textf(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/1.1,ScreenHeight/1.3,ALLEGRO_ALIGN_CENTER,"%d",PlayerTwoBlock);
        al_draw_textf(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/13,ScreenHeight/1.3,ALLEGRO_ALIGN_CENTER,"%d",PlayerOneBlock);
        al_draw_text(FirstFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/2,ScreenHeight/1.6,ALLEGRO_ALIGN_CENTER,"Press ENTER to Exit!");
        al_destroy_sample(MainMusic);
    }
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
}
/** <h1>Implements Collision of block</h1>
    <p>if coordinates of current block equals -100 on x(or another coordinates, but application check x and is enough) then return false, because collision not happen else set -100 to every coordinates of this block</p>
    @param NewBlock[] values of blocks Co-ordinates
    @param Index value of actual block
    @param BallBlock sample of Ball-Block impact
    @return true if collision happened or false if not
*/
bool BlockCollision(Brick NewBlock[],int Index,ALLEGRO_SAMPLE * BallBlock){
    if(NewBlock[Index].x1 == -100){
        return false;
    } else {
        al_play_sample(BallBlock,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
        NewBlock[Index].x1 = -100;
        NewBlock[Index].x2 = -100;
        NewBlock[Index].y1 = -100;
        NewBlock[Index].y2 = -100;
        return true;
    }
}
/** <h1>Check what coordinates are colliding</h1>
    <p>if ball is on block coordinates then call <b>BlockCollision()</b> and set ReverseBall depending on collision exist or not</p>
    @param BallY Ball Y position
    @param BallX Ball X position
    @param ReverseBall actual side ball moves on for Reverse
    @param NewBlock[] increase range of Blocks
    @param BallBlock sample of Ball-Block impact
    @return true if collision happened or false if not
*/
bool CheckCollision(int BallY, int BallX,bool ReverseBall,Brick NewBlock[],ALLEGRO_SAMPLE * BallBlock){
    if((BallY >= 190 && BallY <= 230) && (BallX >= 105 && BallX <= 185))   ReverseBall = BlockCollision(NewBlock,0,BallBlock);
    if((BallY >= 190 && BallY <= 230) && (BallX >= 190 && BallX <= 270))   ReverseBall = BlockCollision(NewBlock,1,BallBlock);
    if((BallY >= 190 && BallY <= 230) && (BallX >= 275 && BallX <= 355))   ReverseBall = BlockCollision(NewBlock,2,BallBlock);
    if((BallY >= 190 && BallY <= 230) && (BallX >= 360 && BallX <= 440))   ReverseBall = BlockCollision(NewBlock,3,BallBlock);
    if((BallY >= 190 && BallY <= 230) && (BallX >= 445 && BallX <= 525))   ReverseBall = BlockCollision(NewBlock,4,BallBlock);
    if((BallY >= 190 && BallY <= 230) && (BallX >= 530 && BallX <= 610))   ReverseBall = BlockCollision(NewBlock,5,BallBlock);
    if((BallY >= 190 && BallY <= 230) && (BallX >= 615 && BallX <= 695))   ReverseBall = BlockCollision(NewBlock,6,BallBlock);

    if((BallY >= 235 && BallY <= 275) && (BallX >= 105 && BallX <= 185))   ReverseBall = BlockCollision(NewBlock,7,BallBlock);
    if((BallY >= 235 && BallY <= 275) && (BallX >= 190 && BallX <= 270))   ReverseBall = BlockCollision(NewBlock,8,BallBlock);
    if((BallY >= 235 && BallY <= 275) && (BallX >= 275 && BallX <= 355))   ReverseBall = BlockCollision(NewBlock,9,BallBlock);
    if((BallY >= 235 && BallY <= 275) && (BallX >= 360 && BallX <= 440))   ReverseBall = BlockCollision(NewBlock,10,BallBlock);
    if((BallY >= 235 && BallY <= 275) && (BallX >= 445 && BallX <= 525))   ReverseBall = BlockCollision(NewBlock,11,BallBlock);
    if((BallY >= 235 && BallY <= 275) && (BallX >= 530 && BallX <= 610))   ReverseBall = BlockCollision(NewBlock,12,BallBlock);
    if((BallY >= 235 && BallY <= 275) && (BallX >= 615 && BallX <= 695))   ReverseBall = BlockCollision(NewBlock,13,BallBlock);

    if((BallY >= 280 && BallY <= 320) && (BallX >= 105 && BallX <= 185))   ReverseBall = BlockCollision(NewBlock,14,BallBlock);
    if((BallY >= 280 && BallY <= 320) && (BallX >= 190 && BallX <= 270))   ReverseBall = BlockCollision(NewBlock,15,BallBlock);
    if((BallY >= 280 && BallY <= 320) && (BallX >= 275 && BallX <= 355))   ReverseBall = BlockCollision(NewBlock,16,BallBlock);
    if((BallY >= 280 && BallY <= 320) && (BallX >= 360 && BallX <= 440))   ReverseBall = BlockCollision(NewBlock,17,BallBlock);
    if((BallY >= 280 && BallY <= 320) && (BallX >= 445 && BallX <= 525))   ReverseBall = BlockCollision(NewBlock,18,BallBlock);
    if((BallY >= 280 && BallY <= 320) && (BallX >= 530 && BallX <= 610))   ReverseBall = BlockCollision(NewBlock,19,BallBlock);
    if((BallY >= 280 && BallY <= 320) && (BallX >= 615 && BallX <= 695))   ReverseBall = BlockCollision(NewBlock,20,BallBlock);

    if((BallY >= 325 && BallY <= 365) && (BallX >= 105 && BallX <= 185))   ReverseBall = BlockCollision(NewBlock,21,BallBlock);
    if((BallY >= 325 && BallY <= 365) && (BallX >= 190 && BallX <= 270))   ReverseBall = BlockCollision(NewBlock,22,BallBlock);
    if((BallY >= 325 && BallY <= 365) && (BallX >= 275 && BallX <= 355))   ReverseBall = BlockCollision(NewBlock,23,BallBlock);
    if((BallY >= 325 && BallY <= 365) && (BallX >= 360 && BallX <= 440))   ReverseBall = BlockCollision(NewBlock,24,BallBlock);
    if((BallY >= 325 && BallY <= 365) && (BallX >= 445 && BallX <= 525))   ReverseBall = BlockCollision(NewBlock,25,BallBlock);
    if((BallY >= 325 && BallY <= 365) && (BallX >= 530 && BallX <= 610))   ReverseBall = BlockCollision(NewBlock,26,BallBlock);
    if((BallY >= 325 && BallY <= 365) && (BallX >= 615 && BallX <= 695))   ReverseBall = BlockCollision(NewBlock,27,BallBlock);

    if((BallY >= 370 && BallY <= 410) && (BallX >= 105 && BallX <= 185))   ReverseBall = BlockCollision(NewBlock,28,BallBlock);
    if((BallY >= 370 && BallY <= 410) && (BallX >= 190 && BallX <= 270))   ReverseBall = BlockCollision(NewBlock,29,BallBlock);
    if((BallY >= 370 && BallY <= 410) && (BallX >= 275 && BallX <= 355))   ReverseBall = BlockCollision(NewBlock,30,BallBlock);
    if((BallY >= 370 && BallY <= 410) && (BallX >= 360 && BallX <= 440))   ReverseBall = BlockCollision(NewBlock,31,BallBlock);
    if((BallY >= 370 && BallY <= 410) && (BallX >= 445 && BallX <= 525))   ReverseBall = BlockCollision(NewBlock,32,BallBlock);
    if((BallY >= 370 && BallY <= 410) && (BallX >= 530 && BallX <= 610))   ReverseBall = BlockCollision(NewBlock,33,BallBlock);
    if((BallY >= 370 && BallY <= 410) && (BallX >= 615 && BallX <= 695))   ReverseBall = BlockCollision(NewBlock,34,BallBlock);
    return ReverseBall;
}
/** <h1>Setting End Game State</h1>
    <p>Draw a end game state and call <b>Set()</b>
    @param FirstFont function range increase of First font
    @param SecondFont function range increase of Second font
    @param TitleColor function range increase of Title Color
    @param FirstColor function range increase of First Color
    @param ScreenWidth increase range a Screen Width of window
    @param ScreenHeight increase range a Screen Height of window
    @param Option store which option in main menu has been chosen
*/
void Outro(ALLEGRO_FONT *FirstFont, ALLEGRO_FONT *SecondFont,int FirstColor[],int TitleColor[],int ScreenWidth,int ScreenHeight, int Option){
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/2.9, ALLEGRO_ALIGN_CENTER, "Are you sure you want to quit?");
    al_draw_text(SecondFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/1.6, ScreenHeight/2, ALLEGRO_ALIGN_CENTER, "Yes!");
    al_draw_text(SecondFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2.8, ScreenHeight/2, ALLEGRO_ALIGN_CENTER, "No!");
    Set(Option, ScreenHeight, ScreenWidth);
}
/** <h1>Select Game Mode State</h1>
    <p>Draw a Select game state mode and call <b>Set()</b> for setting a pointer.</p>
    @param BaseFont function range increase of Second font
    @param FirstFont function range increase of First font
    @param SecondFont function range increase of Second font
    @param TitleColor function range increase of Title Color
    @param FirstColor function range increase of First Color
    @param ScreenWidth increase range a Screen Width of window
    @param ScreenHeight increase range a Screen Height of window
    @param Option store which option in main menu has been chosen
*/
void SelectMode(ALLEGRO_FONT *BaseFont,ALLEGRO_FONT *FirstFont,ALLEGRO_FONT * SecondFont,int FirstColor[],int TitleColor[],int ScreenWidth,int ScreenHeight, int Option){
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(BaseFont, al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]), ScreenWidth/2,ScreenHeight/10, ALLEGRO_ALIGN_CENTER, "BlockBall");
    al_draw_text(SecondFont, al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]), ScreenWidth/2,ScreenHeight/1.4, ALLEGRO_ALIGN_CENTER, "Destroy your Opponent and have fun!");
    al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/3, ALLEGRO_ALIGN_CENTER, "Easy mode");
    al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/3 + 50, ALLEGRO_ALIGN_CENTER, "Medium mode");
    al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/3 + 100, ALLEGRO_ALIGN_CENTER, "Hard mode");
    al_draw_text(FirstFont, al_map_rgb(FirstColor[0], FirstColor[1], FirstColor[2]), ScreenWidth/2, ScreenHeight/3 + 150, ALLEGRO_ALIGN_CENTER, "Versus mode");
    Set(Option, ScreenHeight, ScreenWidth);
}
/** <h1>Show players lives</h1>
    <p>Draw a number of lives depend on how many lives player have</p>
    @param PlayerOneLife show actual lives of first player
    @param PlayerTwoLife show actual lives of second player
    @param Heart range increase of heart bitmap
    @param BreakHeart range increase of break heart bitmap
*/
void ShowLife(int PlayerOneLife, int PlayerTwoLife, ALLEGRO_BITMAP * Heart, ALLEGRO_BITMAP * BreakHeart){
    if(PlayerOneLife == 0){
        al_draw_bitmap(BreakHeart,5,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,35,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,65,560,ALLEGRO_FLIP_HORIZONTAL);
    }
    if(PlayerOneLife == 1){
        al_draw_bitmap(Heart,5,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,35,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,65,560,ALLEGRO_FLIP_HORIZONTAL);
    }
    if(PlayerOneLife == 2){
        al_draw_bitmap(Heart,5,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(Heart,35,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,65,560,ALLEGRO_FLIP_HORIZONTAL);
    }
    if(PlayerOneLife == 3){
        al_draw_bitmap(Heart,5,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(Heart,35,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(Heart,65,560,ALLEGRO_FLIP_HORIZONTAL);
    }
    if(PlayerTwoLife == 0){
        al_draw_bitmap(BreakHeart,705,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,735,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,65,560,ALLEGRO_FLIP_HORIZONTAL);
    }
    if(PlayerTwoLife == 1){
        al_draw_bitmap(Heart,705,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,735,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,765,560,ALLEGRO_FLIP_HORIZONTAL);
    }
    if(PlayerTwoLife == 2){
        al_draw_bitmap(Heart,705,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(Heart,735,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(BreakHeart,765,560,ALLEGRO_FLIP_HORIZONTAL);
    }
    if(PlayerTwoLife == 3){
        al_draw_bitmap(Heart,705,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(Heart,735,560,ALLEGRO_FLIP_HORIZONTAL);
        al_draw_bitmap(Heart,765,560,ALLEGRO_FLIP_HORIZONTAL);
    }
}
/** <h1>Help State</h1>
    <p>Draw a help state. Game rules etc.</p>
    @param FirstFont function range increase of First font
    @param SecondFont function range increase of Second font
    @param ScreenWidth increase range a Screen Width of window
    @param ScreenHeight increase range a Screen Height of window
    @param FirstColor function range increase of First Color
    @param TitleColor function range increase of Title Color
    @param Option store which option in main menu has been chosen
*/
void Help(ALLEGRO_FONT * FirstFont, ALLEGRO_FONT * HelpFont, int ScreenWidth, int ScreenHeight,int FirstColor[], int TitleColor[], int Option){
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(FirstFont,al_map_rgb(TitleColor[0],TitleColor[1],TitleColor[2]),ScreenWidth / 2,ScreenHeight - 560,ALLEGRO_ALIGN_CENTER,"Welcome to Game Rules!");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),10,ScreenHeight - 540,ALLEGRO_ALIGN_LEFT,"1. Controls:");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 520,ALLEGRO_ALIGN_LEFT,"    1P: LEFT button to move left, RIGHT button to move right, UP button to Start Ball");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 500,ALLEGRO_ALIGN_LEFT,"    2P: A button to move left, D button to move right, S button to Start Ball");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 480,ALLEGRO_ALIGN_LEFT,"    MENU: ENTER button to accept, ESCAPE button to reject or back");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),10,ScreenHeight - 460,ALLEGRO_ALIGN_LEFT,"2. When your ball hit on opponent dead field:");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 440,ALLEGRO_ALIGN_LEFT,"    - You gain 1000 points");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 420,ALLEGRO_ALIGN_LEFT,"    - Opponent lose his one life");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),10,ScreenHeight - 400,ALLEGRO_ALIGN_LEFT,"3. When opponent ball hit on your dead field:");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 380,ALLEGRO_ALIGN_LEFT,"    - Opponent gain 1000 points");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 360,ALLEGRO_ALIGN_LEFT,"    - You lose one life");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),10,ScreenHeight - 340,ALLEGRO_ALIGN_LEFT,"4. You both have 3 lives and 2x ball multiplier on start");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),10,ScreenHeight - 320,ALLEGRO_ALIGN_LEFT,"5. Attention for:");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 300,ALLEGRO_ALIGN_LEFT,"    - Opponent Paddle: every hit take your 150 points");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 280,ALLEGRO_ALIGN_LEFT,"    - Blocks: hit as much as you can, every block give you 100 points");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 260,ALLEGRO_ALIGN_LEFT,"              otherwise, every broken block speed up your ball");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 240,ALLEGRO_ALIGN_LEFT,"    - Multiplier: show your actual ball speed");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),10,ScreenHeight - 220,ALLEGRO_ALIGN_LEFT,"6. When Someone lose all lives:");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 200,ALLEGRO_ALIGN_LEFT,"    - Win this player who has more points");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 180,ALLEGRO_ALIGN_LEFT,"    - if both players has same number of points there is a draw");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 160,ALLEGRO_ALIGN_LEFT,"    - Every life which you keep when your opponent lost all lives,");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 140,ALLEGRO_ALIGN_LEFT,"            give you 1000 points");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 120,ALLEGRO_ALIGN_LEFT,"    - So, if you have 3 lives you get a 3000 points, if 2 lives");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 100,ALLEGRO_ALIGN_LEFT,"            you get 2000 points, if 1 life you get 1000 points to your score");
    al_draw_text(HelpFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),10,ScreenHeight - 80,ALLEGRO_ALIGN_LEFT,"    -  Saved own lives, broken opponent lives and destroyed blocks is your all score");
    al_draw_text(FirstFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth / 2,ScreenHeight - 60,ALLEGRO_ALIGN_CENTER,"BACK TO MENU");
    al_draw_filled_rounded_rectangle(100, ScreenHeight / 1.07, 200, (ScreenHeight / 1.07) + 20,12,12,al_map_rgb(60,60,60));
    al_draw_filled_rounded_rectangle(600, 20,700, 40,12,12,al_map_rgb(60,60,60));
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0],TitleColor[1],TitleColor[2]),150,562,ALLEGRO_ALIGN_CENTER,"Player 1");
    al_draw_text(HelpFont,al_map_rgb(TitleColor[0],TitleColor[1],TitleColor[2]),650,21,ALLEGRO_ALIGN_CENTER,"Player 2");
    al_draw_filled_circle(650,50, 8, al_map_rgb(255, 100, 90));
    al_draw_filled_circle(150, 550, 8, al_map_rgb(255, 100, 40));
    Set(Option, ScreenHeight, ScreenWidth);
}
/** <h1>Credits State</h1>
    <p>Draw a credits state. Authors sound and images source etc.</p>
    @param FirstFont function range increase of First font
    @param SecondFont function range increase of Second font
    @param BaseFont function range increase of Base Font
    @param ScreenWidth increase range a Screen Width of window
    @param ScreenHeight increase range a Screen Height of window
    @param FirstColor function range increase of First Color
    @param TitleColor function range increase of Title Color
    @param Option store which option in main menu has been chosen
*/
void Credits(ALLEGRO_FONT * FirstFont, ALLEGRO_FONT * SecondFont, ALLEGRO_FONT * BaseFont, int ScreenWidth, int ScreenHeight,int FirstColor[], int TitleColor[], int Option){
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(BaseFont, al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]), ScreenWidth/2,ScreenHeight/10, ALLEGRO_ALIGN_CENTER, "BlockBall");
    al_draw_text(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/2,ScreenHeight/4,ALLEGRO_ALIGN_CENTER,"Game Created By:");
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/6,ScreenHeight/2.5,ALLEGRO_ALIGN_CENTER,"Konrad Nowak");
    al_draw_text(SecondFont,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]),ScreenWidth/1.23,ScreenHeight/2.5,ALLEGRO_ALIGN_CENTER,"Kamil Wypych");
    al_draw_text(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/2,ScreenHeight/2,ALLEGRO_ALIGN_CENTER,"Sounds Effects: soundible.com");
    al_draw_text(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/2,ScreenHeight/1.8,ALLEGRO_ALIGN_CENTER,"Game Music: ericskiff.com");
    al_draw_text(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/2,ScreenHeight - 140,ALLEGRO_ALIGN_CENTER,"All rights reserved. Copying contents without");
    al_draw_text(SecondFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth/2,ScreenHeight - 120,ALLEGRO_ALIGN_CENTER," the owner's express consent is forbidden.");
    al_draw_text(FirstFont,al_map_rgb(FirstColor[0],FirstColor[1],FirstColor[2]),ScreenWidth / 2,ScreenHeight - 60,ALLEGRO_ALIGN_CENTER,"BACK TO MENU");
    Set(Option, ScreenHeight, ScreenWidth);
}
/** <h1>Increase ball speed</h1>
    <p>if current speed of ball is bigger than 0, it means ball is going to down board. To speed up the ball, this function adds or subtracts to the 0.1 multiplier, and multiply by difficult Level.</p>
    @param CurrentSpeed actual ball speed
    @param DifficultLevel set difficult level thanks to this function can multiply ball speed
    @return multiplied ball speed
*/
float ImproveBallSpeed(float CurrentSpeed, int DifficultLevel){
    float BallSpeed = 0;
    if(CurrentSpeed > 0){
        BallSpeed = CurrentSpeed + (DifficultLevel * 0.1);
    } else {
        BallSpeed = CurrentSpeed - (DifficultLevel * 0.1);
    }
    return BallSpeed;
}
/** <h1>Reverse ball move</h1>
    <p>if CurrentBall is bigger than 0, it determinant where ball is going (up/down) then reverse direction</p>
    @param CurrentBall which ball to reverse
    @return reversed move of ball
*/
float ReverseBall(float CurrentBall){
    float Ball = 0;
    if(CurrentBall > 0) {
        Ball = CurrentBall *= (-1);
    } else if (CurrentBall < 0) {
        Ball = CurrentBall *= (-1);
    }
    return Ball;
}
/** <h1>Counting ball speed</h1>
    @param Speed actual speed of ball
    @return speed ball
*/
float BallSpeed(float Speed){
    if(Speed < 0) return Speed * (-1);
    else return Speed;
}


#include "headers.h"
/** <h1>Main Game</h1>
    <p>That is the heart of game. Here are declaration of variables and main game loop</p>
    <h3>C++ Variables</h3>
    <ul>
        <li><b>float FPS</b> - Number of frames per second </li>
        <li><b>int ScreenWidth</b> - Window width</li>
        <li><b>int ScreenHeight</b> - Window height</li>
        <li><b>bool Done</b> - Start main loop</li>
        <li><b>bool Draw</b> - Draw statement</li>
        <li><b>bool ReverseBallOne</b> - Reverse first player ball</li>
        <li><b>bool ReverseBallTwo</b> - Reverse second player ball</li>
        <li><b>bool StartBallOne</b> - Start first player ball</li>
        <li><b>bool StartBallTwo</b> - Start second player ball</li>
        <li><b>bool Select</b> - Select Mode</li>
        <li><b>bool Exit</b> - Exit state</li>
        <li><b>bool EndGame</b> - End Game state</li>
        <li><b>bool ShowHelp</b> - Help state</li>
        <li><b>int PaddleOne</b> - Coordinates of first player paddle</li>
        <li><b>int PaddleTwo</b> - Coordinates of second player paddle</li>
        <li><b>int MoveSpeed</b> - Paddle speed</li>
        <li><b>int TitleColor[3]</b> - Title color in array</li>
        <li><b>int BallOneDirection</b> - Direction of first ball</li>
        <li><b>int BallTwoDirection</b> - Direction of second ball</li>
        <li><b>int BallTwoX</b> - X-Coordinate second ball</li>
        <li><b>int BallTwoY</b> - Y-Coordinate second ball</li>
        <li><b>int BallOneX</b> - X-Coordinate first ball</li>
        <li><b>int BallOneY</b> - Y-Coordinate first ball</li>
        <li><b>float BallTwoMoveX</b> - X-Speed second ball</li>
        <li><b>float BallTwoMoveY</b> - Y-Speed second ball</li>
        <li><b>float BallOneMoveX</b> - X-Speed first ball</li>
        <li><b>float BallOneMoveY</b> - Y-Speed first ball</li>
        <li><b>int PlayerOneScore</b> - Score of first player</li>
        <li><b>int PlayerTwoScore</b> - Score of second player</li>
        <li><b>int PlayerOneBlock</b> - Destroyed blocks of first player</li>
        <li><b>int PlayerTwoBlock</b> - Destroyed blocks of second player</li>
        <li><b>int PlayerOneLife</b> - First player life counter</li>
        <li><b>int PlayerTwoLife</b> - Second player life counter</li>
        <li><b>int Option</b> - Choose mode</li>
        <li><b>bool FullScreen</b> - Fullscreen or window</li>
        <li><b>bool OnePlayerMode</b> - One player Mode flag</li>
        <li><b>bool MenuState</b> - Menu state flag</li>
        <li><b>bool SaveLoad</b> - Ability to save or load game</li>
        <li><b>bool Load</b> - End of loading</li>
        <li><b>int DifficultLevel</b> - Difficult level depend on game mode</li>
        <li><b>int LoadedBricks[35]</b> - coordinates of bricks loaded from a file</li>
        <li><b>Brick NewBlock[35] </b> - Current game blocks. Original Coordinates of blocks</li>
        <li><b>Brick ConstBlock[35]</b> - Copied blocks from file</li>
    </ul>
    <h3>Allegro Variables</h3>
    <ul>
        <li><b>ALLEGRO_KEYBOARD_STATE KeyState</b> - Keyboard Listener</li>
        <li><b>ALLEGRO_DISPLAY * Display</b> - Window</li>
        <li><b>ALLEGRO_FONT * BaseFont</b> - Main font</li>
        <li><b>ALLEGRO_FONT * FirstFont</b> - Another font</li>
        <li><b>ALLEGRO_FONT * SecondFont</b> - Another Font</li>
        <li><b>ALLEGRO_FONT * MicroFont</b> - Font like second font but smaller</li>
        <li><b>ALLEGRO_TIMER * MainTimer</b> - Main game timer</li>
        <li><b>ALLEGRO_TIMER * BallOneImpactTimer</b> - Timer for ball one impact with wall</li>
        <li><b>ALLEGRO_TIMER * BallTwoImpactTimer</b> - Timer for ball two impact with wall</li>
        <li><b>ALLEGRO_TIMER * PaddleOneImpactTimer</b> - Timer for ball one paddles</li>
        <li><b>ALLEGRO_TIMER * PaddleTwoImpactTimer</b> - Timer for ball two paddles</li>
        <li><b>ALLEGRO_EVENT_QUEUE * EventQueue</b> - Event Queue</li>
        <li><b>ALLEGRO_BITMAP * Heart</b> - Heart bitmap</li>
        <li><b>ALLEGRO_BITMAP * BreakHeart</b> - Broken heart bitmap</li>
        <li><b>ALLEGRO_SAMPLE * BallBlock</b> - Impact ball-block audio</li>
        <li><b>ALLEGRO_SAMPLE * WallImpact</b> - Impact ball-wall audio</li>
        <li><b>ALLEGRO_SAMPLE * PaddleImpact</b> - Impact ball-paddle audio</li>
        <li><b>ALLEGRO_SAMPLE * LostLife</b> - Lost life audio</li>
        <li><b>ALLEGRO_SAMPLE * End</b> - End game music</li>
        <li><b>ALLEGRO_SAMPLE * MainMusic</b> - Main game music</li>
        <li><b>ALLEGRO_SAMPLE * MenuMusic</b> - Menu music</li>
    </ul>
*/
int main(){
    Stealth();
    const float FPS = 60.0;
    const short int ScreenWidth = 800;
    const short int ScreenHeight = 600;
    bool Done = false;
    bool Draw = true;
    bool ReverseBallOne = false, ReverseBallTwo = false;
    bool StartBallOne = false, StartBallTwo = false;
    bool Select = false, Exit = false,EndGame = false;
    bool ShowHelp = false;
    int PaddleOne = 350,PaddleTwo = 350, MoveSpeed = 10;
    int TitleColor[3] = {250,150,25}, FirstColor[3] = {100,100,100};
    short int BallOneDirection =  1;
    short int BallTwoDirection =  1;
    int BallTwoX = PaddleTwo + 50;
    int BallTwoY = 48;
    int BallOneX = PaddleOne + 50;
    int BallOneY = 548;
    float BallTwoMoveX = 2;
    float BallTwoMoveY = 2;
    float BallOneMoveX = 2;
    float BallOneMoveY = 2;
    int PlayerOneScore = 0;
    int PlayerTwoScore = 0;
    short int PlayerOneBlock = 0;
    short int PlayerTwoBlock = 0;
    short int PlayerOneLife = 3;
    short int PlayerTwoLife = 3;
    short int Option = 1;
    bool FullScreen = false;
    bool OnePlayerMode = true;
    bool MenuState = true;
    bool SaveLoad = false;
    bool Load = false;
    short int DifficultLevel = 1;
    int LoadedBricks[35];
    Brick NewBlock[35] =   {{105,185,190,230},
                            {190,270,190,230},
                            {275,355,190,230},
                            {360,440,190,230},
                            {445,525,190,230},
                            {530,610,190,230},
                            {615,695,190,230},
                            {105,185,235,275},
                            {190,270,235,275},
                            {275,355,235,275},
                            {360,440,235,275},
                            {445,525,235,275},
                            {530,610,235,275},
                            {615,695,235,275},
                            {105,185,280,320},
                            {190,270,280,320},
                            {275,355,280,320},
                            {360,440,280,320},
                            {445,525,280,320},
                            {530,610,280,320},
                            {615,695,280,320},
                            {105,185,325,365},
                            {190,270,325,365},
                            {275,355,325,365},
                            {360,440,325,365},
                            {445,525,325,365},
                            {530,610,325,365},
                            {615,695,325,365},
                            {105,185,370,410},
                            {190,270,370,410},
                            {275,355,370,410},
                            {360,440,370,410},
                            {445,525,370,410},
                            {530,610,370,410},
                            {615,695,370,410}};
    Brick ConstBlock[35];
    for(int i = 0; i < 35; i++){
        ConstBlock[i] = NewBlock[i];
    }
    RestartScreen:
    InitializeLibrary();
    ALLEGRO_KEYBOARD_STATE KeyState;
    ALLEGRO_DISPLAY * Display = DisplayWindow(ScreenWidth,ScreenHeight, FullScreen);
    ALLEGRO_FONT * BaseFont = al_load_font("fonts/Quantify.ttf", 64, NULL);
    ALLEGRO_FONT * FirstFont = al_load_font("fonts/Nozty.ttf", 32, NULL);
    ALLEGRO_FONT * SecondFont = al_load_font("fonts/Gameplay.ttf", 16, NULL);
    ALLEGRO_FONT * MicroFont = al_load_font("fonts/Gameplay.ttf", 12, NULL);
    ALLEGRO_TIMER * MainTimer = al_create_timer(1.0/FPS);
    ALLEGRO_TIMER * BallOneImpactTimer = al_create_timer(1.0/FPS);
    ALLEGRO_TIMER * BallTwoImpactTimer = al_create_timer(1.0/FPS);
    ALLEGRO_TIMER * PaddleOneImpactTimer = al_create_timer(1.0/FPS);
    ALLEGRO_TIMER * PaddleTwoImpactTimer = al_create_timer(1.0/FPS);
    ALLEGRO_EVENT_QUEUE * EventQueue = al_create_event_queue();
    ALLEGRO_BITMAP * Heart = al_load_bitmap("img/heart.png");
    ALLEGRO_BITMAP * BreakHeart = al_load_bitmap("img/break_heart.png");
    ALLEGRO_SAMPLE * BallBlock = al_load_sample("sounds/Block_Impact.wav");
    ALLEGRO_SAMPLE * WallImpact = al_load_sample("sounds/Wall_Impact.wav");
    ALLEGRO_SAMPLE * PaddleImpact = al_load_sample("sounds/Paddle_Impact.wav");
    ALLEGRO_SAMPLE * LostLife = al_load_sample("sounds/Lost_Life.wav");
    ALLEGRO_SAMPLE * End = al_load_sample("sounds/End.ogg");
    ALLEGRO_SAMPLE * MainMusic = al_load_sample("sounds/Music.ogg");
    ALLEGRO_SAMPLE * MenuMusic = al_load_sample("sounds/Prologue.wav");
    al_reserve_samples(7);
    al_register_event_source(EventQueue,al_get_keyboard_event_source());
    al_register_event_source(EventQueue,al_get_timer_event_source(MainTimer));
    al_start_timer(MainTimer);
    al_start_timer(BallOneImpactTimer);
    al_start_timer(BallTwoImpactTimer);
    al_start_timer(PaddleOneImpactTimer);
    al_start_timer(PaddleTwoImpactTimer);
    while(!Done){
        ALLEGRO_EVENT Events;
        al_wait_for_event(EventQueue,&Events);
        al_play_sample(MenuMusic,0.5,0.0,1.0,ALLEGRO_PLAYMODE_LOOP,0);
        if(Events.type == ALLEGRO_EVENT_KEY_UP){
            if ((Option >= 1 && Option <= 10)){
                switch(Events.keyboard.keycode){
                case ALLEGRO_KEY_DOWN:
                    if(Option >= 6 && Option <= 9) {
                        Option++;
                        if (Option >= 9) Option = 9;
                    }
                    else if (Option >= 1 && Option <= 5){
                        Option++;
                        if (Option > 5) Option = 5;
                        Select = false;
                    }
                    break;
                case ALLEGRO_KEY_UP:
                    if(Option > 6 && Option < 10) Option--;
                    if (Option >= 1 && Option <= 5){
                        Option--;
                        if (Option < 1) Option = 1;
                        Select = false;
                    }
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    if ((Option >= 6 && Option <= 9) || Option == 10){
                        Option = 1;
                        Exit = false;
                        Select = false;
                        ShowHelp = false;
                    }   else   {
                        Select = false;
                        Exit = true;
                        Option = 11;
                    }
                    break;
                case ALLEGRO_KEY_ENTER:
                    Select = true;
                    ShowHelp = false;
                    break;
                }
            }   else   {
                if(Events.type == ALLEGRO_EVENT_KEY_UP){
                    switch(Events.keyboard.keycode){
                        case ALLEGRO_KEY_LEFT:
                            Option = 11;
                            Select = false;
                            break;
                        case ALLEGRO_KEY_RIGHT:
                            Option = 12;
                            Select = false;
                            break;
                        case ALLEGRO_KEY_ENTER:
                            Select = true;
                            break;
                        case ALLEGRO_KEY_ESCAPE:
                            ShowHelp = false;
                            Select = false;
                            Exit = false;
                            Option = 1;
                            break;
                    }
                }
            }
            if (Option == 5 && Select == true){
                Select = false;
                Exit = true;
                Option = 11;
            }
            if (Option == 11 && Select == true){
                    Exit = false;
                    Option = 1;
                    Select = false;
            }
            if (Option == 12 && Select == true) Done = true;
            if (Option == 10 && Select == true){
                Option = 1;
                Select = false;
            }
            if (Option == 1 && Select == true){
                Option = 6;
                Select = false;
                Exit = false;
            }
            if (Option == 2 && Select == true){
                al_destroy_sample(MenuMusic);
                if(FullScreen) FullScreen = false;
                else if(!FullScreen) FullScreen = true;
                al_destroy_display(Display);
                goto RestartScreen;
                Select = false;
            }
            if (Option == 6 && Select == true){
                OnePlayerMode = true;
                GameMode:
                SaveLoad = true;
                MenuState = false;
                al_destroy_sample(MenuMusic);
                al_play_sample(MainMusic,0.5,0.0,1.0,ALLEGRO_PLAYMODE_LOOP,0);
                while(!Done){
                    ALLEGRO_EVENT Events;
                    al_wait_for_event(EventQueue,&Events);
                    if(Events.type == ALLEGRO_EVENT_TIMER){
                        al_get_keyboard_state(&KeyState);
                        if(!Exit){
                            if(al_key_down(&KeyState, ALLEGRO_KEY_RIGHT)){
                                if(PaddleOne >= 600) PaddleOne = 600;
                                else PaddleOne += MoveSpeed;
                            }
                            if(al_key_down(&KeyState, ALLEGRO_KEY_LEFT)){
                                if(PaddleOne <= 100) PaddleOne = 100;
                                else PaddleOne -= MoveSpeed;
                            }
                            if(al_key_down(&KeyState, ALLEGRO_KEY_UP))StartBallOne = true;
                            if(OnePlayerMode) {
                                PaddleTwo = BallTwoX - 50;
                                if(PaddleTwo >= 600) PaddleTwo = 600;
                                if(PaddleTwo <= 100) PaddleTwo = 100;
                                StartBallTwo = true;
                            } else if (!OnePlayerMode) {
                                if(al_key_down(&KeyState, ALLEGRO_KEY_D)){
                                    if(PaddleTwo >= 600) PaddleTwo = 600;
                                    else PaddleTwo += MoveSpeed;
                                }
                                if(al_key_down(&KeyState, ALLEGRO_KEY_A)){
                                    if(PaddleTwo <= 100) PaddleTwo = 100;
                                    else PaddleTwo -= MoveSpeed;
                                }
                                if(al_key_down(&KeyState, ALLEGRO_KEY_S))StartBallTwo = true;
                                DifficultLevel = 1;
                            }
                        }
                        if(al_key_down(&KeyState, ALLEGRO_KEY_ESCAPE))   Exit = true;
                        if(al_key_down(&KeyState, ALLEGRO_KEY_SPACE))    Exit = false;
                        if(al_key_down(&KeyState, ALLEGRO_KEY_P) && SaveLoad)   {
                            ofstream SavedFile;
                            if(DifficultLevel == 1 && OnePlayerMode) SavedFile.open("data/EasyModeSave.txt");
                            if(DifficultLevel == 2 && OnePlayerMode) SavedFile.open("data/MediumModeSave.txt");
                            if(DifficultLevel == 3 && OnePlayerMode) SavedFile.open("data/HardModeSave.txt");
                            if(!OnePlayerMode) SavedFile.open("data/VersusModeSave.txt");
                            SavedFile << PlayerOneScore << endl << PlayerTwoScore << endl;
                            SavedFile << PlayerOneLife << endl << PlayerTwoLife << endl;
                            SavedFile << BallOneMoveX << endl << BallTwoMoveX  << endl;
                            SavedFile << PlayerOneBlock << endl << PlayerTwoBlock << endl;
                            SavedFile << BallOneX << endl << BallTwoX << endl;
                            SavedFile << BallOneY << endl << BallTwoY << endl;
                            SavedFile << PaddleOne << endl << PaddleTwo << endl;
                            SavedFile << BallOneMoveY << endl << BallTwoDirection << endl;
                            SavedFile << StartBallOne << endl << StartBallTwo << endl;
                            for(int i = 0; i <= 34; i++) {
                                if(NewBlock[i].x1 < 0) SavedFile << 0 << endl;
                                else SavedFile << 1 << endl;
                            }
                            SavedFile.close();
                            al_draw_text(BaseFont, al_map_rgb(20,190,20), ScreenWidth/2,ScreenHeight/1.2, ALLEGRO_ALIGN_CENTER, "Zapisano!");
                        }
                        if(al_key_down(&KeyState, ALLEGRO_KEY_O) && SaveLoad){
                            Load = true;
                            ifstream LoadedFile;
                            if(DifficultLevel == 1 && OnePlayerMode) LoadedFile.open("data/EasyModeSave.txt");
                            if(DifficultLevel == 2 && OnePlayerMode) LoadedFile.open("data/MediumModeSave.txt");
                            if(DifficultLevel == 3 && OnePlayerMode) LoadedFile.open("data/HardModeSave.txt");
                            if(!OnePlayerMode) LoadedFile.open("data/VersusModeSave.txt");
                            string FileLine, DataArray[53];
                            stringstream Parse[53];
                            stringstream ParseBlocks[35];
                            int i = 0;
                            if(LoadedFile.is_open()){
                                while(getline(LoadedFile,FileLine)){
                                    DataArray[i] = FileLine;
                                    i++;
                                }
                                LoadedFile.close();
                                Parse[0] << DataArray[0]; Parse[0] >> PlayerOneScore; Parse[1] << DataArray[1]; Parse[1] >> PlayerTwoScore;
                                Parse[2] << DataArray[2]; Parse[2] >> PlayerOneLife; Parse[3] << DataArray[3]; Parse[3] >> PlayerTwoLife;
                                Parse[4] << DataArray[4]; Parse[4] >> BallOneMoveX; Parse[5] << DataArray[5]; Parse[5] >> BallTwoMoveX;
                                Parse[6] << DataArray[6]; Parse[6] >> PlayerOneBlock; Parse[7] << DataArray[7]; Parse[7] >> PlayerTwoBlock;
                                Parse[8] << DataArray[8]; Parse[8] >> BallOneX; Parse[9] << DataArray[9]; Parse[9] >> BallTwoX;
                                Parse[10] << DataArray[10]; Parse[10] >> BallOneY; Parse[11] << DataArray[11]; Parse[11] >> BallTwoY;
                                Parse[12] << DataArray[12]; Parse[12] >> PaddleOne; Parse[13] << DataArray[13]; Parse[13] >> PaddleTwo;
                                Parse[14] << DataArray[14]; Parse[14] >> BallOneMoveY; Parse[15] << DataArray[15]; Parse[15] >> BallTwoMoveY;
                                (DataArray[16] == "1") ? StartBallOne = true : StartBallOne = false;
                                (DataArray[17] == "1") ? StartBallTwo = true : StartBallTwo = false;
                                for(int i = 0; i <= 34; i++){
                                    ParseBlocks[i] << DataArray[i + 18]; ParseBlocks[i] >> LoadedBricks[i];
                                }
                            }
                            al_draw_text(BaseFont, al_map_rgb(20,190,20), ScreenWidth/2,ScreenHeight/1.2, ALLEGRO_ALIGN_CENTER, "Odczytano!");
                        }
                        if(al_key_down(&KeyState, ALLEGRO_KEY_ENTER) && (Exit || EndGame)) Done = true;
                        Draw = true;
                    }
                    if(Draw && !Exit && !EndGame){
                        Draw = false;
                        if(StartBallOne == true){
                            if(!ReverseBallOne){
                                BallOneY += BallOneMoveY;
                                BallOneX += BallOneMoveX * BallOneDirection;
                                ReverseBallOne = CheckCollision(BallOneY,BallOneX,ReverseBallOne,NewBlock,BallBlock);
                                if(ReverseBallOne == true){
                                    BallOneX += BallOneMoveX * BallOneDirection;
                                    BallOneMoveX = ImproveBallSpeed(BallOneMoveX,1);
                                    BallOneMoveY = ImproveBallSpeed(BallOneMoveY,1);
                                    BallOneMoveY = ReverseBall(BallOneMoveY);
                                    PlayerOneScore += 100;
                                    PlayerOneBlock++;
                                }
                            }
                            else if(ReverseBallOne){
                                BallOneY -= BallOneMoveY;
                                BallOneX += BallOneMoveX * BallOneDirection;
                                ReverseBallOne = CheckCollision(BallOneY,BallOneX,ReverseBallOne,NewBlock,BallBlock);
                            }
                            if(BallOneX >= 690 || BallOneX <= 110){
                                if(al_get_timer_count(BallOneImpactTimer) >= 3){
                                    al_set_timer_count(BallOneImpactTimer,0);
                                    al_play_sample(WallImpact,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                                    BallOneMoveX = ReverseBall(BallOneMoveX);
                                }
                            }
                            if(BallOneY >= 620 || BallOneY <= -20) StartBallOne = false;
                        }
                        if(StartBallTwo == true){
                            if(!ReverseBallTwo){
                                BallTwoY -= BallTwoMoveY;
                                BallTwoX -= BallTwoMoveX * BallTwoDirection;
                                ReverseBallTwo = CheckCollision(BallTwoY,BallTwoX,ReverseBallTwo,NewBlock,BallBlock);
                                if(ReverseBallTwo == true){
                                    BallTwoX += BallTwoMoveX * BallTwoDirection;
                                    BallTwoMoveX = ImproveBallSpeed(BallTwoMoveX,DifficultLevel);
                                    BallTwoMoveY = ImproveBallSpeed(BallTwoMoveY,DifficultLevel);
                                    BallTwoMoveY = ReverseBall(BallTwoMoveY);
                                    PlayerTwoScore += 100;
                                    PlayerTwoBlock++;
                                }
                            }
                            else if (ReverseBallTwo){
                                BallTwoY += BallTwoMoveY;
                                BallTwoX -= BallTwoMoveX * BallTwoDirection;
                                ReverseBallTwo = CheckCollision(BallTwoY,BallTwoX,ReverseBallTwo,NewBlock,BallBlock);
                            }
                            if(BallTwoX >= 690 || BallTwoX <= 110){
                                if(al_get_timer_count(BallTwoImpactTimer) >= 3){
                                    al_set_timer_count(BallTwoImpactTimer,0);
                                    al_play_sample(WallImpact,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                                    al_play_sample(WallImpact,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                                    BallTwoMoveX = ReverseBall(BallTwoMoveX);
                                }
                            }
                            if(BallTwoY >= 620 || BallTwoY <= -20) StartBallTwo = false;
                        }
                        if(!StartBallOne) BallOneMoveY = -2;
                        if(!StartBallTwo) BallTwoMoveY = -2;
                        if((BallOneY >= 43 && BallOneY <= 46) && (BallOneX >= PaddleTwo && BallOneX <= PaddleTwo+100)){
                            if(al_get_timer_count(PaddleOneImpactTimer) >= 3){
                                al_set_timer_count(PaddleOneImpactTimer,0);
                                al_play_sample(PaddleImpact,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                                BallOneX += BallOneMoveX * BallOneDirection;
                                BallOneMoveY = ReverseBall(BallOneMoveY);
                                PlayerOneScore -= 150;
                            }
                        }
                        if((BallOneY >= 550 && BallOneY <= 553) && (BallOneX >= PaddleOne && BallOneX <= PaddleOne+100 )){
                            if(al_get_timer_count(PaddleOneImpactTimer) >= 3){
                                al_set_timer_count(PaddleOneImpactTimer,0);
                                al_play_sample(PaddleImpact,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                                BallOneX += BallOneMoveX * BallOneDirection;
                                BallOneMoveY = ReverseBall(BallOneMoveY);
                            }
                        }
                        if((BallTwoY >= 43 && BallTwoY <= 47) && (BallTwoX >= PaddleTwo && BallTwoX <= PaddleTwo + 100 )){
                            if(al_get_timer_count(PaddleTwoImpactTimer) >= 3){
                                al_set_timer_count(PaddleTwoImpactTimer,0);
                                al_play_sample(PaddleImpact,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                                BallTwoX += BallTwoMoveX * BallTwoDirection;
                                BallTwoMoveY = ReverseBall(BallTwoMoveY);
                            }
                        }
                        if((BallTwoY >= 550 && BallTwoY <= 556) && (BallTwoX >= PaddleOne && BallTwoX <= PaddleOne+100)){
                            if(al_get_timer_count(PaddleTwoImpactTimer) >= 3){
                                al_set_timer_count(PaddleTwoImpactTimer,0);
                                al_play_sample(PaddleImpact,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                                BallTwoX += BallTwoMoveX * BallTwoDirection;
                                BallTwoMoveY = ReverseBall(BallTwoMoveY);
                                PlayerTwoScore -= 150;
                            }
                        }
                    }
                    DrawBoard(ScreenWidth,ScreenHeight,TitleColor,FirstColor,BaseFont,FirstFont,SecondFont,MicroFont,PlayerTwoScore,PlayerOneScore,PlayerOneLife,PlayerTwoLife,BallSpeed(BallOneMoveX),
                              BallSpeed(BallTwoMoveX),PlayerOneBlock,PlayerTwoBlock,Heart,BreakHeart,Exit,EndGame,MainMusic);
                    if (StartBallOne == false){
                        if(BallOneY >= 620){
                            PlayerOneLife--;
                            al_play_sample(LostLife,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                            if(PlayerOneLife <= 0){
                                BallOneY = 0;
                                BallTwoY = 0;
                                EndGame = true;
                                al_play_sample(End,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                            }
                            BallOneY = 548;
                        }
                        else if(BallOneY <= -20){
                            PlayerOneScore += 1000;
                            PlayerTwoLife --;
                            al_play_sample(LostLife,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                            BallOneY = 548;
                            if(PlayerTwoLife <= 0){
                                BallOneY = 0;
                                BallTwoY = 0;
                                EndGame = true;
                                al_play_sample(End,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                            }
                        }
                        BallOneX = PaddleOne + 50;
                        al_draw_filled_circle(BallOneX, BallOneY+4, 8, al_map_rgb(255, 100, 40));
                    }
                    else    al_draw_filled_circle(BallOneX, BallOneY, 8, al_map_rgb(255, 100, 40));
                    if (StartBallTwo == false){
                        if(BallTwoY >= 620){
                            PlayerOneLife--;
                            al_play_sample(LostLife,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                            PlayerTwoScore += 1000;
                            if(PlayerOneLife <= 0){
                                BallOneY = 0;
                                BallTwoY = 0;
                                EndGame = true;
                                al_play_sample(End,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                            }
                            BallTwoY = 48;
                        }
                        else if(BallTwoY <= -20){
                            PlayerTwoLife--;
                            al_play_sample(LostLife,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                            if(PlayerTwoLife <= 0){
                                BallOneY = 0;
                                BallTwoY = 0;
                                EndGame = true;
                                al_play_sample(End,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,0);
                            }
                            BallTwoY = 48;
                        }
                        BallTwoX = PaddleTwo + 50;
                        al_draw_filled_circle(BallTwoX, BallTwoY + 2, 8, al_map_rgb(255, 100, 90));
                    }
                    else    al_draw_filled_circle(BallTwoX, BallTwoY + 2, 8, al_map_rgb(255, 100, 90));
                    if(EndGame) SaveLoad = false;
                    al_draw_filled_rounded_rectangle(PaddleOne, ScreenHeight / 1.07, PaddleOne + 100, (ScreenHeight / 1.07) + 20,12,12,al_map_rgb(60,60,60));
                    al_draw_filled_rounded_rectangle(PaddleTwo, 20, PaddleTwo + 100, 40,12,12,al_map_rgb(60,60,60));
                    if(Load){
                        for(int i = 0; i < 35; i++){
                            if(LoadedBricks[i] == 1)  {
                                NewBlock[i].x1 = ConstBlock[i].x1;
                                NewBlock[i].x2 = ConstBlock[i].x2;
                                NewBlock[i].y1 = ConstBlock[i].y1;
                                NewBlock[i].y2 = ConstBlock[i].y2;
                            } else if(LoadedBricks[i] == 0){
                                NewBlock[i].x1 = -100;
                                NewBlock[i].x2 = -100;
                                NewBlock[i].y1 = -100;
                                NewBlock[i].y2 = -100;
                            }
                            if(i == 34) Load = false;
                        }
                    }
                    for(int i = 0; i < 35; i++) al_draw_filled_rectangle(NewBlock[i].x1,NewBlock[i].y1,NewBlock[i].x2,NewBlock[i].y2,al_map_rgb(TitleColor[0], TitleColor[1], TitleColor[2]));
                }
            }
            if(Option == 7 && Select == true){
                    OnePlayerMode = true;
                    Select = false;
                    DifficultLevel = 2;
                    goto GameMode;
            }
            if(Option == 8 && Select == true){
                    OnePlayerMode = true;
                    Select = false;
                    DifficultLevel = 3;
                    goto GameMode;
            }
            if(Option == 9 && Select == true){
                    OnePlayerMode = false;
                    Select = false;
                    goto GameMode;
            }
        }
        if (Option == 3 && Select){
            ShowHelp = true;
            Select = false;
            Option = 10;
            Help(FirstFont, MicroFont, ScreenWidth, ScreenHeight, FirstColor, TitleColor, Option);
        }
        if (Option == 4 && Select){
            ShowHelp = true;
            Select = false;
            Option = 10;
            Credits(FirstFont, SecondFont, BaseFont, ScreenWidth, ScreenHeight, FirstColor, TitleColor, Option);
        }
        if(Option >= 6 && Option <= 9){
                SelectMode(BaseFont,FirstFont,SecondFont,FirstColor,TitleColor,ScreenWidth,ScreenHeight, Option);
                Select = false;
        }
        if(Exit && MenuState)   Outro(FirstFont, SecondFont, FirstColor, TitleColor, ScreenWidth, ScreenHeight, Option);
        if(!Exit && Option <= 5 && !ShowHelp)  Intro(BaseFont,FirstFont,FirstColor,TitleColor,ScreenWidth,ScreenHeight, Option,FullScreen);
        if(Events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)  Done = true;
    }
    AllDestroy(EventQueue,BaseFont,FirstFont,SecondFont,MicroFont,Display,Heart,BreakHeart);
    DestroyTimers(MainTimer,BallOneImpactTimer,BallTwoImpactTimer,PaddleOneImpactTimer,PaddleTwoImpactTimer);
    DestroySounds(BallBlock,WallImpact,PaddleImpact,LostLife,End,MainMusic,MenuMusic);
    return 0;
}

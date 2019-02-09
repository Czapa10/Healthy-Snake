#pragma once

namespace Textures
{
    enum ID
    {
        ///splash state
        companyLogo,
        madeBy,

        ///menu state
        menuBackground1,
        menuBackground2,
        menuBackground3,
        menuBackground4,
        menuBackground5,
        menuButtons,

        ///game sprites
        gameBackground,

        snakeStraightBody,
        snakeTurnBody,
        /////////8x11
        snakeTail,
        snakeHead,
        snakeHeadOpenMouth,
        snakeHeadClosedEyes,
        snakeHeadTounge,
        snakeHeadBigEyesWhileDying,
        snakeHeadClosedEyesWhileDying,
        /////////8x8
        snakeTail8x8,
        snakeHead8x8,
        snakeHeadOpenMouth8x8,
        snakeHeadClosedEyes8x8,
        snakeHeadTounge8x8,
        snakeHeadBigEyesWhileDying8x8,
        snakeHeadClosedEyesWhileDying8x8,

        appleRed,
        appleYellow,
        cherry,
        hamburger,
        meat,
        iceCream,
        donut,
        frites,

        statisticsBar,
        numbers,
        minus,

        gameover,

        pause,

        difficultyChoiseButtons,

        nothing
    };

    ID operator!(ID);
}

namespace Fonts
{
    enum ID
    {
        pooh
    };
}

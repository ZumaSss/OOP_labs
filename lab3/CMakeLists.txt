project(marksAndZeros)

set(CMAKE_CXX_STANDARD 14)

add_executable(marksAndZeros main.cpp Player.h RealPlayer.h RealPlayer.cpp BotI.cpp BotI.h Bot.h NewGame.h NewGame.cpp Context.h Model.cpp View.cpp Controller.cpp MoveException.h Bot.cpp)
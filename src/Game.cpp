#include <../inc/Game.hpp>
#include <../inc/GameStatus.hpp>
#include <../inc/InputValidation.hpp>
#include <../inc/ScoreInCompleted.hpp>
#include <../inc/Exceptions.hpp>
#include <memory>
#include <iostream>
#include <fstream>

Game::Game(const std::string& pathToFile_) :
    pathToFile(pathToFile_)
{
}

std::string Game::getGameStatus()
{
    checkInputData();
    if(correctnessOfInputData)
    {
    auto gameStatus = std::make_unique<Status>(playersResult);
    return gameStatus->getStatus();
    }
    return "";
}

void Game::openFile()
{
    std::ifstream inFile(pathToFile);
    std::string longLine;
    if (inFile.is_open())
    {
    while (std::getline(inFile,longLine))
    {
        //auto inputValidation = std::make_shared<InputValidation>(oneLine);
        std::string oneLine = longLine.substr(0,longLine.size() - 1);
        InputValidation inputValidation(oneLine);
        std::cout<<"ile literek: "<<oneLine.size()<<std::endl;
        std::cout<<"substring:"<<oneLine.substr(0,oneLine.size() - 1)<<std::endl;
        std::cout<<"status: "<<inputValidation.checkInputData()<<std::endl; //why false ?
        if(!(inputValidation.checkInputData()) && oneLine != "")
        {
            correctnessOfInputData = false;
            throw IncorrectInputData(oneLine);
        }
        else playersResult.emplace_back(oneLine);
    }
    correctnessOfInputData = true;
    }
    else throw InvalidFile(pathToFile);
}

void Game::checkInputData()
{
    try
    {
        openFile();
    }
    catch (InvalidFile& exception)
    {
        std::cout<<exception.what()<<std::endl;
    }
    catch (IncorrectInputData& exception)
    {
        std::cout<<exception.what()<<std::endl;
    }
}

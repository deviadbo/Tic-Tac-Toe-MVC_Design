#include "GameController.h"

void GameController::Play()
{

	GameState status;
	Move move;
	ui->print(game->getGameBase());

	do
	{
		ui->printLine("X - Player turn\n");
		ui->printLine("Dear player, choose a slot for X\n");
		move = (ui->getPlayerMove());
		if (game->setPlayerMove(move) == Success)
		{
			game->updateGameState();
			ui->print(game->getGameBase());
			status = game->getGameState();
			switch (status)
			{
			case ComputerWin:
				ui->printLine("Computer Win!\n");
				ui->printLine("Bye Bye\n");
				return;
				break;

			case PlayerWin:
				ui->printLine("You Win!\n");
				ui->printLine("Bye Bye\n");
				return;
				break;

			case Tie:
				ui->printLine("Game ended with tie\n");
				ui->printLine("Bye Bye\n");
				return;
				break;
			default:  //inGame
				break;
			}
			ui->printLine("O - Computer Player turn\n");
			game->getComputerMove();
			game->updateGameState();
			ui->print(game->getGameBase());
			status = game->getGameState();
			switch (status)
			{
			case ComputerWin:
				ui->printLine("Computer Win!\n");
				ui->printLine("Bye Bye\n");
				return;
				break;

			case PlayerWin:
				ui->printLine("You Win!\n");
				ui->printLine("Bye Bye\n");
				return;
				break;

			case Tie:
				ui->printLine("Game ended with tie\n");
				ui->printLine("Bye Bye\n");
				return;
				break;
			default:  //inGame
				break;
			}
		}
		else
		{
			ui->printLine("Worng move!\n");
			ui->printLine("Dear player, choose a slot for X\n");
			move = (ui->getPlayerMove());
		}
	} while (status == inGame);
	ui->printLine("Bye Bye\n");

}

#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::Draw()
{
	grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
	grid.setValue(row, column, value);
}

int Simulation::CountLiveNeighbor(int row, int column)
{
	int liveNeighbors = 0;
	std::vector<std::pair<int, int>> neighborOffsets = {
		{-1,0},
		{1,0},
		{0,-1},
		{0,1},
		{-1,-1},
		{-1,1},
		{1,-1},
		{1,1}
	};
	for (const auto& offset : neighborOffsets)
	{
		int neighborRow = (row + offset.first) % grid.GetRows();
		int neighborColumn = (column + offset.second) % grid.GetColumns();
		liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
	}
	return liveNeighbors;
}

void Simulation::Update()
{
	if (IsRunning())
	{
		for (int row = 0; row < grid.GetRows(); row++)
		{
			for (int column = 0; column < grid.GetColumns(); column++)
			{
				int liveNeighbors = CountLiveNeighbor(row, column);
				int cellValue = grid.GetValue(row, column);

				if (cellValue == 1)
				{
					if (liveNeighbors > 3 || liveNeighbors < 2)
					{
						tempGrid.setValue(row, column, 0);
					}
					else
					{
						tempGrid.setValue(row, column, 1);
					}
				}
				else
				{
					if (liveNeighbors == 3)
					{
						tempGrid.setValue(row, column, 1);
					}
					else
					{
						tempGrid.setValue(row, column, 0);
					}
				}
			}
		}
		grid = tempGrid;
	}
}

void Simulation::ClearGrid()
{
	if (!IsRunning())
	{
		grid.Clear();
	}
}

void Simulation::CreateRandomnState()
{
	if (!IsRunning())
	{
		grid.FillRandom();
	}
}

void Simulation::ToggleCell(int row, int column)
{
	if (!IsRunning())
	{
		grid.ToggleCell(row, column);
	}
}

#include "grid.hpp"

class Simulation
{
	public:
		Simulation(int width,int height, int cellSize)
			: grid(width, height, cellSize), tempGrid(width, height, cellSize), run(false)
		{

		};
		void Draw();
		void SetCellValue(int row, int colum, int value);
		int CountLiveNeighbor(int row, int column);
		void Update();
		bool IsRunning() { return run; }
		void Start() { run = true; }
		void Stop() { run = false; }
		void ClearGrid();
		void CreateRandomnState();
		void ToggleCell(int row, int column);
	private:
		Grid grid;
		Grid tempGrid;
		bool run;
};
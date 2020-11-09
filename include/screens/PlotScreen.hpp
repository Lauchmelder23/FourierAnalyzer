#pragma once
#include <mutex>
#include <vector>
#include <SDL.h>
#include "../Screen.hpp"
#include "Signal.hpp"

typedef struct {
	double x, y, w, h;
} fRect;

class PlotScreen : public Screen
{
public:
	PlotScreen(SDL_Renderer* renderer, Signal* dataSource,
		int x, int y, int w, int h, 
		double minX, double minY, double maxX, double maxY);
	~PlotScreen();

	void Update() override;
	void Render(SDL_Renderer* renderer) override;

private:
	void SignalToSampleList(std::vector<Sample>& container, uint32_t maxSamples = 0);
	void SampleListToPointList(const std::vector<Sample>& source, std::vector<SDL_Point>& container);

	fRect plotRect;
	Signal* dataSource;
};
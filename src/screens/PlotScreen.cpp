#include "screens/PlotScreen.hpp"
#include <vector>
#include <SDL.h>
#include "Signal.hpp"

#define MAP(A, B, a, b, val) ((val - A)*(b-a)/(B-A) + a)

PlotScreen::PlotScreen(SDL_Renderer* renderer, Signal* dataSource, int x, int y, int w, int h, double minX, double minY, double maxX, double maxY) :
	Screen(renderer, x, y, w, h), dataSource(dataSource),
	plotRect{ minX, minY, maxX, maxY }
{

}

PlotScreen::~PlotScreen()
{
}

void PlotScreen::Update()
{
}

void PlotScreen::Render(SDL_Renderer* renderer)
{
	std::vector<Sample> samples;
	SignalToSampleList(samples);
	std::vector<SDL_Point> points;
	SampleListToPointList(samples, points);

	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLines(renderer, points.data(), points.size());

	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, texture, NULL, screenSpace);

	for (int i = 0; i < 1000; i++)
	{
		(*dataSource) << Sample{ i / 10.0f, sin(i / 10.0f) };
	}
}

void PlotScreen::SignalToSampleList(std::vector<Sample>& container, uint32_t maxSamples)
{
	Sample s;
	(*dataSource) >> s;
	while (s.valid)
	{
		container.push_back(s);
		if (container.size() == maxSamples)
			return;
		(*dataSource) >> s;
	}
}

void PlotScreen::SampleListToPointList(const std::vector<Sample>& source, std::vector<SDL_Point>& container)
{
	for (const Sample& sample : source)
	{
		container.push_back({
			(int)std::floor((sample.t - plotRect.x) * screenSpace->w / (plotRect.w - plotRect.x)),
			(int)std::floor(-(sample.val.real() + plotRect.y) * screenSpace->h / (plotRect.h - plotRect.y))
			});
	}
}
#include <SDL.h>
// квадрат летит в сторону мыши, если зажата ЛКМ, и от мыши, если зажата ПКМ.
int main(int argc, char* argv[]) {
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Square", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	int FPS = 30;

	SDL_Event event;
	int mouseX = 50, mouseY = 50;
	float cubic_x = 1080 / 2;
	float cubic_y = 800 / 2;
	int lmbDown = 0, rmbDown = 0;
	float speed = 2.0f;
	SDL_Rect square = { 20, 20, mouseX, mouseY };







	while (1) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				SDL_Quit();
				return 0;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) {
					lmbDown = 1;
				}
				if (event.button.button == SDL_BUTTON_RIGHT) {
					rmbDown = 1;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT) {
					lmbDown = 0;
				}
				if (event.button.button == SDL_BUTTON_RIGHT) {
					rmbDown = 0;
				}
				break;
			case SDL_MOUSEMOTION:
				mouseX = event.motion.x;
				mouseY = event.motion.y;
				break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		if (lmbDown) {
			float x = mouseX - cubic_x;
			float y = mouseY - cubic_y;
			float len = sqrt(x * x + y * y);
			if (len >= 3)
			{
				if (len == 0) len = 1;
				x /= len;
				y /= len;
				cubic_x += x * speed / FPS;
				cubic_y += y * speed / FPS;

				square.x = cubic_x;
				square.y = cubic_y;
			}
		}

		if (rmbDown) {
			float x = mouseX - cubic_x;
			float y = mouseY - cubic_y;
			float len = sqrt(x * x + y * y);
			if (len == 0) len = 1;
			x /= len;
			y /= len;
			cubic_x -= x * speed / FPS;
			cubic_y -= y * speed / FPS;

			square.x = cubic_x;
			square.y = cubic_y;
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &square);

		SDL_RenderPresent(renderer);
	}
}
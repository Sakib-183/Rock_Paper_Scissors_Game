#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

const int W = 600;
const int H = 400;

/* ────── texture helper ────── */
SDL_Texture *LoadTexture(SDL_Renderer *r, const std::string &path)
{
    SDL_Surface *s = IMG_Load(path.c_str());
    if (!s)
    {
        std::cerr << "IMG " << path << " : " << IMG_GetError() << '\n';
        return nullptr;
    }
    SDL_Texture *t = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    SDL_SetTextureBlendMode(t, SDL_BLENDMODE_BLEND);
    return t;
}

/* ────── text helper ────── */
void RenderText(SDL_Renderer *r, TTF_Font *f,
                const std::string &msg, int x, int y,
                SDL_Color c = {0, 0, 0, 255})
{
    SDL_Surface *s = TTF_RenderText_Blended(f, msg.c_str(), c);
    SDL_Texture *t = SDL_CreateTextureFromSurface(r, s);
    SDL_Rect dst{x, y, s->w, s->h};
    SDL_RenderCopy(r, t, nullptr, &dst);
    SDL_FreeSurface(s);
    SDL_DestroyTexture(t);
}

/* ────── main ────── */
int SDL_main(int, char **)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ||
        IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG ||
        TTF_Init() == -1)
    {
        std::cerr << "SDL/IMG/TTF init failed : " << SDL_GetError() << '\n';
        return 1;
    }
    SDL_Window *win = SDL_CreateWindow("Rock Paper Scissors",
                                       SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                       W, H, SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font *font = TTF_OpenFont("ALGER.TTF", 20);
    if (!font)
    {
        std::cerr << "Font: " << TTF_GetError() << '\n';
        return 1;
    }

    SDL_Texture *rock = LoadTexture(ren, "rock-removebg.png");
    SDL_Texture *paper = LoadTexture(ren, "paper-removebg.png");
    SDL_Texture *scissors = LoadTexture(ren, "scissors-removebg.png");
    SDL_Texture *crock = LoadTexture(ren, "crock-removebg.png");
    SDL_Texture *cpaper = LoadTexture(ren, "cpaper-removebg.png");
    SDL_Texture *cscissors = LoadTexture(ren, "cscissour-removebg.png");

    SDL_Texture *hands[3]{rock, paper, scissors};
    SDL_Texture *chands[3]{crock, cpaper, cscissors};

    /* Game Test */
    bool quit = false, reveal = false;
    int pPick = -1, cPick = -1, pScore = 0, cScore = 0;
    std::srand(static_cast<unsigned>(time(nullptr)));

    SDL_Rect rBtn{70, 300, 60, 60};
    SDL_Rect pBtn{270, 300, 60, 60};
    SDL_Rect sBtn{470, 300, 60, 60};

    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
                if (reveal)
                {
                    reveal = false;
                    pPick = cPick = -1;
                    continue;
                }

                int mx = e.button.x, my = e.button.y;
                if (my >= 300 && my <= 360)
                {
                    if (mx >= rBtn.x && mx <= rBtn.x + rBtn.w)
                        pPick = 0;
                    else if (mx >= pBtn.x && mx <= pBtn.x + pBtn.w)
                        pPick = 1;
                    else if (mx >= sBtn.x && mx <= sBtn.x + sBtn.w)
                        pPick = 2;
                }
                if (pPick != -1)
                {
                    cPick = std::rand() % 3;
                    for (int i = 0; i < 3; ++i)
                    {
                        SDL_SetRenderDrawColor(ren, 220, 220, 220, 255);
                        SDL_RenderClear(ren);
                        SDL_Rect pR{140, 110, 100, 100};
                        SDL_Rect cR{360, 110, 100, 100};
                        SDL_RenderCopy(ren, hands[i], nullptr, &pR);
                        SDL_RenderCopy(ren, chands[i], nullptr, &cR);
                        SDL_RenderPresent(ren);
                        SDL_Delay(350);
                    }
                    if (pPick != cPick)
                    {
                        bool win = (pPick == 0 && cPick == 2) || (pPick == 1 && cPick == 0) || (pPick == 2 && cPick == 1);
                        if (win)
                            ++pScore;
                        else
                            ++cScore;
                    }
                    reveal = true;
                }
            }
        }

        SDL_SetRenderDrawColor(ren, 220, 220, 220, 255);
        SDL_RenderClear(ren);

        std::string score = "Player: " + std::to_string(pScore) + "   Computer: " + std::to_string(cScore);
        RenderText(ren, font, score, (W - (int)score.size() * 10) / 2, 20);

        if (reveal && pPick != -1)
        {
            SDL_Rect pR{140, 110, 100, 100};
            SDL_Rect cR{360, 110, 100, 100};
            SDL_RenderCopy(ren, hands[pPick], nullptr, &pR);
            SDL_RenderCopy(ren, chands[cPick], nullptr, &cR);

            std::string outcome = (pPick == cPick) ? "Draw!" : ((pPick == 0 && cPick == 2) || (pPick == 1 && cPick == 0) || (pPick == 2 && cPick == 1)) ? "You Win!"
                                                                                                                                                        : "Computer Wins!";
            RenderText(ren, font, outcome, (W - (int)outcome.size() * 10) / 2, 70);
            RenderText(ren, font, "Click to play again", (W - 180) / 2, 230);
        }

        RenderText(ren, font, "Choose your hand", (W - 160) / 2, 270);
        SDL_RenderCopy(ren, rock, nullptr, &rBtn);
        SDL_RenderCopy(ren, paper, nullptr, &pBtn);
        SDL_RenderCopy(ren, scissors, nullptr, &sBtn);

        SDL_RenderPresent(ren);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}

# Rock Paper Scissors — SDL2/C++  

A desktop Rock Paper Scissors game written in modern C++17 and rendered with SDL2.  
Play against the computer, enjoy smooth sprite animations, and learn basic SDL event handling all in one lightweight project.

---

## 📂 Project Structure

*Runtime DLLs and built executables are **not** tracked—grab them from the Releases page or build locally (instructions below).*

---

## 🛠️ Build Instructions

### Prerequisites
| Platform | Packages to install |
|----------|--------------------|
| **Windows (MSYS2/MinGW-w64)** | `pacman -Syu` → restart shell → `pacman -S make mingw-w64-x86_64-gcc mingw-w64-x86_64-SDL2 mingw-w64-x86_64-SDL2_image mingw-w64-x86_64-SDL2_ttf` |
| **Ubuntu/Debian** | `sudo apt update && sudo apt install build-essential make libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev` |
| **Arch Linux** | `sudo pacman -S base-devel sdl2 sdl2_image sdl2_ttf` |
| **macOS (Homebrew)** | `brew install sdl2 sdl2_image sdl2_ttf` |

### Build & Run


### Create a Windows Release ZIP
Upload the ZIP under **GitHub → Releases** so players can run the game without compiling.

---

## 🎮 How to Play
1. Launch the game—window opens at 640 × 480.
2. Click **Rock**, **Paper**, or **Scissors** sprite.
3. The computer reveals its pick; result text shows *You Win!*, *Draw!*, or *Computer Wins!*.
4. Click anywhere to start the next round.

---

## ✨ Features
- SDL2 rendering & event loop
- TrueType font text rendering (SDL_ttf)
- PNG assets loaded via SDL_image
- Resize-safe coordinate math
- Clean, cross-platform Makefile

---

## 📄 License
This project is released under the MIT License—see `LICENSE` for details.

Happy hacking! 🔨

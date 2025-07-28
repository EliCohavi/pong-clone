# 🎮 Pong Clone

A simple, two-player Pong game built using **C++** and the **SFML** (Simple and Fast Multimedia Library). Inspired by the classic arcade game, this project was originally created as a personal learning exercise and has since been revived and modernized with improved structure and visuals.

---

## 🕹️ Gameplay

- **Player 1** (Left): Use `W` and `S` to move up and down.
- **Player 2** (Right): Use the `↑` and `↓` arrow keys.
- Ball speeds up over time to increase difficulty.
- Basic scoring system and win condition (optional, if implemented).

---

## 📦 Features

- Simple 2D rendering using SFML
- Real-time collision detection
- Paddle and ball movement
- Text rendering using custom fonts
- (Optional) Background music using SFML Audio

---

## 🧰 Tech Stack

- **Language**: C++
- **Graphics & Audio**: [SFML](https://www.sfml-dev.org/) (v2.5 or later)
- **IDE**: Visual Studio Code
- **Platform**: Windows (also compatible with macOS/Linux with configuration)

---

## 🚀 Getting Started

### Prerequisites

- [SFML installed](https://www.sfml-dev.org/download.php)
- A C++ compiler (e.g., MinGW on Windows or `g++` on macOS/Linux)
- VS Code with the C/C++ extension

### Build Instructions

1. Clone the repository:

   ```bash
   git clone https://github.com/YOUR_USERNAME/pong-clone.git
   cd pong-clone
``

2. Compile the code (replace paths with your actual SFML location):

   ```bash
   g++ main.cpp -IC:/Path/To/SFML/include -LC:/Path/To/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o pong.exe
   ```

3. Run the game:

   ```bash
   ./pong.exe
   ```

> ⚠️ Make sure the required SFML `.dll` files are in the same directory as `pong.exe` if you're not statically linking.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

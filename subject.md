# cub3D

## 📘 Project Overview

**cub3D** is a 3D graphics project from the 42 curriculum inspired by the legendary Wolfenstein 3D game. The goal is to create a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective using ray-casting principles with the miniLibX library.

> **Disclaimer:**  
> This document is an unofficial summary written for educational and documentation purposes.  
> It is not affiliated with or endorsed by 42 or its partners.  
> All 42 students are responsible for adhering to the academic integrity policy.  
> You may **not** publish or share any part of the official subject PDF, evaluation scripts, or Moulinette content.

---

## Contents

- [Goals](#goals)
- [General Requirements](#general-requirements)
- [Mandatory Part](#mandatory-part)
- [Map Configuration](#map-configuration)
- [Controls](#controls)
- [Bonus Part](#bonus-part)
- [Submission Guidelines](#submission-guidelines)

---

## Goals

- Explore ray-casting algorithms and 3D graphics programming.
- Learn to work with the miniLibX graphics library.
- Understand mathematical applications in game development.
- Implement window management, colors, events, and shape rendering.
- Create a playable first-person perspective maze game.

---

## General Requirements

- Written in **C**, following the **42 Norm**.
- No memory leaks, segmentation faults, or undefined behavior.
- All files must compile with `-Wall -Wextra -Werror` using `cc`.
- Global variables are **forbidden**.
- Must use **miniLibX** (system version or from sources).
- If using libft, copy sources to a `libft` folder with its Makefile.

### Makefile

Must include rules:
- `all`, `clean`, `fclean`, `re`, `$(NAME)`
- `bonus` rule for bonus implementation

### External Functions Allowed

- **Standard:** `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`, `gettimeofday`
- **Math library:** All functions (`-lm`)
- **miniLibX:** All functions

---

## Mandatory Part

### Program Execution

```bash
./cub3D map.cub
```

The program takes a scene description file with `.cub` extension as argument.

### Core Features

- **3D Ray-casting:** Create realistic 3D maze representation
- **Texture Mapping:** Different wall textures based on direction (N, S, E, W)
- **Floor/Ceiling Colors:** Configurable RGB colors
- **Smooth Window Management:** Handle window switching, minimizing, etc.
- **Real-time Rendering:** Smooth movement and rotation

---

## Map Configuration

### Map File Format (.cub)

The configuration file must contain:

#### Texture Paths
```
NO ./path_to_north_texture
SO ./path_to_south_texture  
WE ./path_to_west_texture
EA ./path_to_east_texture
```

#### Colors (RGB format 0-255)
```
F 220,100,0    # Floor color
C 225,30,0     # Ceiling color
```

#### Map Layout
```
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Map Rules

- **Valid characters:**
  - `0`: Empty space
  - `1`: Wall
  - `N`, `S`, `E`, `W`: Player spawn position and orientation

- **Map requirements:**
  - Must be closed/surrounded by walls
  - Map content must be last in the file
  - Spaces are valid and must be handled
  - Each element can be separated by empty lines
  - Parsing order flexible (except map at end)

### Error Handling

If any misconfiguration is found, program must exit with:
```
Error
[Explicit error message]
```

---

## Controls

### Movement
- **W, A, S, D**: Move through the maze
- **Left/Right arrows**: Look left and right

### Program Control
- **ESC**: Close window and exit program
- **Red X**: Close window and exit program

---

## Bonus Part

> **Note:** Bonuses are only evaluated if the mandatory part is **PERFECT**.

### Available Bonuses

- **Wall Collisions:** Prevent walking through walls
- **Minimap System:** Real-time map display
- **Interactive Doors:** Doors that can open/close
- **Animated Sprites:** Moving game elements
- **Mouse Rotation:** Rotate view with mouse
- **Additional Features:** HUD, health bars, weapons, floor/ceiling textures

### Bonus Implementation

- Bonus functions must be in `_bonus.{c/h}` files
- You may modify the scene file format for bonuses
- Additional map symbols allowed for bonus features
- Use of additional functions permitted if justified

---

## Submission Guidelines

- Submit to assigned Git repository
- Only repository content will be evaluated
- Evaluation includes peer reviews and automated testing
- Code must pass norm checks and runtime tests
- Project files should have correct naming

---

## Technical Notes

### Ray-casting Principles

This project implements the same ray-casting technique used in:
- **Wolfenstein 3D (1992)** - First true FPS game
- **Doom (1993)** - Id Software milestone  
- **Duke Nukem 3D (1996)** - 3D Realms classic
- **Quake (1996)** - Advanced 3D engine

### Mathematical Applications

The project serves as a practical exploration of:
- Trigonometry and vector mathematics
- 2D to 3D projection algorithms
- Performance optimization techniques
- Real-time graphics programming

---

## Testing

While not required, comprehensive testing is recommended for:
- Map parsing validation
- Error handling scenarios
- Performance with different map sizes
- Memory leak detection
- Cross-platform compatibility

Consider testing with various map configurations and edge cases to ensure robust implementation.

---

## Final Note

cub3D bridges the gap between mathematical theory and practical application, providing hands-on experience with graphics programming concepts that form the foundation of modern game engines. The project teaches essential skills in 3D mathematics, memory management, and real-time rendering optimization.

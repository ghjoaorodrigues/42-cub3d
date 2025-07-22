# cub3D

![42 Badge](https://img.shields.io/badge/42-cub3D-brightgreen)
![C Badge](https://img.shields.io/badge/Language-C-blue)
![Status Badge](https://img.shields.io/badge/Status-Completed-success)
![Graphics Badge](https://img.shields.io/badge/Graphics-Ray--casting-orange)

## What I Learned

Through this challenging graphics programming project at 42 School, I developed advanced programming skills and deep understanding of:

- **Ray-casting algorithms** - Implemented the core mathematical principles behind 3D rendering from 2D maps
- **3D graphics programming** - Gained hands-on experience with perspective projection and depth perception
- **Mathematical applications** - Applied trigonometry, vector mathematics, and linear algebra in real-time rendering
- **Memory management optimization** - Handled texture loading and efficient buffer management for smooth performance
- **Event-driven programming** - Implemented responsive keyboard input handling and window management
- **Parser development** - Built robust file parsing with comprehensive error handling for map configurations
- **Collaborative development** - Worked effectively in a team environment with clear module separation
- **Performance optimization** - Balanced visual quality with real-time rendering requirements
- **Cross-platform graphics** - Utilized miniLibX for portable graphics programming
- **Algorithm optimization** - Implemented efficient DDA (Digital Differential Analyzer) for ray-wall intersection

This project significantly enhanced my understanding of computer graphics fundamentals, mathematical problem-solving, and low-level optimization techniques essential for game development.

## About the Project

cub3D is a 3D first-person perspective game inspired by the legendary Wolfenstein 3D. Using ray-casting techniques, it renders a realistic 3D view of a 2D maze where players can navigate and explore. The project demonstrates the mathematical elegance behind early 3D game engines and provides deep insights into graphics programming fundamentals.

## Team Collaboration

This project was developed collaboratively:
- **@joao-alm** - Map parsing, input validation, and configuration handling
- **[@fabiosilva24](https://github.com/fabiosilva24)** - Ray-casting engine, rendering, and graphics pipeline

## Implementation Details

The game engine consists of several well-architected modules:

### Core Architecture

```
src/
├── main/           # Game initialization and lifecycle management
├── input/          # Map parsing and validation system
├── graphic/        # Ray-casting engine and rendering pipeline
└── keyhook/        # Input handling and player movement
```

### Map Parsing System

**File Format Support (.cub)**
- Texture path validation for all four directions (NO, SO, WE, EA)
- RGB color parsing for floor and ceiling (F, C)
- Robust map matrix parsing with comprehensive error checking
- Player spawn position detection and orientation setup

**Key Features:**
- **Filename validation** - Ensures proper .cub extension
- **Configuration parsing** - Validates texture paths and color values
- **Map validation** - Checks for closed walls and valid characters
- **Flood fill algorithm** - Ensures map integrity and player accessibility
- **Memory-safe parsing** - Proper cleanup on error conditions

### Ray-casting Engine

**Core Algorithm Implementation:**
- **DDA Algorithm** - Efficient ray-wall intersection detection
- **Perspective projection** - Converts 3D world to 2D screen coordinates
- **Texture mapping** - Applies wall textures based on hit direction
- **Distance calculations** - Accurate depth perception for realistic rendering

**Rendering Pipeline:**
- **Ray generation** - Casts rays for each screen column
- **Wall detection** - Identifies wall hits and calculates distances
- **Texture sampling** - Maps wall textures to screen pixels
- **Floor/ceiling rendering** - Fills remaining screen space with configured colors

### Input System

**Movement Controls:**
- **W, A, S, D** - Directional movement with collision detection
- **Arrow keys** - Camera rotation for looking around
- **ESC** - Clean program termination
- **Window close** - Proper cleanup on window events

**Technical Features:**
- **Smooth movement** - Configurable movement and rotation speeds
- **Real-time input** - Responsive key handling without lag
- **State management** - Tracks multiple simultaneous key presses

## Configuration

### Game Settings
```c
#define FOV 0.9              // Field of view angle
#define WIN_HEIGHT 720       // Window height
#define WIN_RATIO 16/9       // Aspect ratio
#define ROT_SPEED 0.025      // Rotation sensitivity
#define MOVE_SPEED 0.06      // Movement speed
#define TEXTURE_SIZE 512     // Texture resolution
```

### Map Format Example
```
NO ./asset/north_wall.xpm
SO ./asset/south_wall.xpm
WE ./asset/west_wall.xpm
EA ./asset/east_wall.xpm

F 220,100,0
C 225,30,0

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

## Usage

```bash
# Compile the project
make

# Run with a map file
./cub3D map/valid/map.cub

# Clean object files
make clean

# Remove all generated files
make fclean

# Rebuild everything
make re
```

## Technical Challenges Overcome

- **Mathematical precision** - Implementing accurate ray-casting calculations with floating-point arithmetic
- **Performance optimization** - Achieving smooth 60fps rendering with efficient algorithms
- **Memory management** - Proper handling of image data and texture loading without leaks
- **Error handling** - Comprehensive validation for malformed map files and edge cases
- **Coordinate systems** - Managing transformations between world, screen, and texture coordinates
- **Texture mapping** - Accurate wall texture sampling based on ray intersection points
- **Input responsiveness** - Smooth movement and rotation without input lag or stuttering

## Dependencies

- **miniLibX** - Graphics library for window management and pixel manipulation
- **JAL Library** - Custom utility library for memory management and string operations
- **Math Library** - Standard math functions for trigonometric calculations
- **X11** - Linux window system support

## Project Structure

```
cub3d/
├── Makefile              # Build configuration
├── include/              # Header files
│   ├── game.h           # Core game structures
│   ├── graphic.h        # Rendering function declarations
│   ├── input.h          # Parsing function declarations
│   └── keyhook.h        # Input handling declarations
├── src/                 # Source code
│   ├── main/            # Game initialization
│   ├── input/           # Map parsing system
│   ├── graphic/         # Ray-casting engine
│   └── keyhook/         # Input handling
├── lib/                 # External libraries
│   ├── jal/             # Custom utility library
│   └── mlx/             # miniLibX graphics library
├── asset/               # Texture files (.xpm)
└── map/                 # Test maps
    ├── valid/           # Valid map configurations
    └── error/           # Error test cases
```

## Testing

The project includes comprehensive testing infrastructure:

- **Valid maps** - Various map configurations testing different scenarios
- **Error cases** - Invalid maps testing parser robustness
- **Memory leak detection** - Valgrind-clean implementation
- **Performance testing** - Smooth rendering with complex maps
- **Edge case handling** - Boundary conditions and malformed inputs

---

*This project was completed as part of the 42 School curriculum, demonstrating proficiency in graphics programming, mathematical applications, and collaborative software development. It showcases the practical implementation of computer graphics fundamentals and real-time rendering techniques.*

---

## License

This project is licensed under the [MIT License](./LICENSE).

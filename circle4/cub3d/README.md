# cub3d

A 3D first-person maze rendered in real time using a raycasting engine, inspired by Wolfenstein 3D. Built in C with MiniLibX.

## Build

Requires MiniLibX and X11 (Linux).

```sh
# mandatory
cd cub3d_mandatory
make

# bonus
cd cub3d_bonus
make
```

## Run

```sh
./cub3d path/to/map.cub
```

## Map format (`.cub`)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0        # floor colour (R,G,B)
C 225,30,0         # ceiling colour

111111
100001
1N0001
111111
```

| Character | Meaning |
|-----------|---------|
| `1` | wall |
| `0` | empty space |
| `N/S/E/W` | player spawn + facing direction |

## Features

**Mandatory**
- Raycasting engine with textured walls (one texture per cardinal direction)
- Configurable floor and ceiling colours
- Mouse and keyboard movement

**Bonus**
- Animated door (`F` tile — press `E` to open/close)
- Enemy sprites with simple patrol AI
- Minimap overlay

## Controls

| Key | Action |
|-----|--------|
| W/A/S/D | move |
| ← / → | rotate view |
| E | interact (door) |
| ESC | quit |

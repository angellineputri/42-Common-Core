# so_long

A small 2D tile-based game written in C using MiniLibX. Navigate a character through a map, collect all collectibles, and reach the exit.

## Map format (`.ber`)

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

| Character | Meaning |
|-----------|---------|
| `1` | wall |
| `0` | empty floor |
| `P` | player start |
| `E` | exit |
| `C` | collectible |

## Build

Requires MiniLibX and X11 (Linux).

```sh
make          # builds ./so_long
make bonus    # builds ./so_long_bonus
make clean
make fclean
make re
```

## Run

```sh
./so_long maps/valid_map/map.ber
```

## Controls

| Key | Action |
|-----|--------|
| W / ↑ | move up |
| S / ↓ | move down |
| A / ← | move left |
| D / → | move right |
| ESC | quit |

## Features

- Map validation (closed walls, at least one P, E, C, reachable path)
- Move counter displayed in terminal
- **Bonus**: animated sprites, enemy patrols, on-screen move counter

<div align="center">

# HeroTower

**A fantasy multiplayer game concept spanning competitive arenas and cooperative survival.**

![Engine](https://img.shields.io/badge/engine-Godot-478CBF?logo=godotengine&logoColor=white)
![Genre](https://img.shields.io/badge/genre-fantasy%20action-6f42c1)
![Modes](https://img.shields.io/badge/modes-PvP%20%7C%20PvE-0A7F8C)
![Status](https://img.shields.io/badge/status-development%20project-orange)

</div>

## Contents

- [Project overview](#project-overview)
- [Game modes](#game-modes)
- [Gameplay systems](#gameplay-systems)
- [Art and content direction](#art-and-content-direction)
- [Project structure](#project-structure)
- [Open the project](#open-the-project)
- [Development roadmap](#development-roadmap)
- [Current status](#current-status)
- [License](#license)

## Project overview

HeroTower is a fantasy game-development project whose design backlog describes competitive PvP modes and cooperative PvE survival. Its planned systems include weapons, spells, armor, character attributes, damage calculations, monsters, and multiplayer-oriented features.

The repository currently contains a Godot project directory and a design/development backlog. Features described below are planned unless they can be confirmed in the current game build.

## Game modes

### Player versus Player

| Mode | Planned format |
|---|---|
| Battle Royale | Multiple players or teams; last player/team standing |
| Boss Battle 5v5 | Two teams compete around a boss encounter |
| Arena 2v2 | Small-team elimination |
| Arena 1v1 | Duel |

### Player versus Environment

- **Invasion Survival:** cooperative survival for up to five players, with escalating waves and a boss encounter every ten rounds.

The backlog also describes ranked play, monthly open championships, and larger seasonal or annual esports events.

## Gameplay systems

The design notes identify these areas:

- Weapon and spell systems
- Heavy, light, and magical armor categories
- Character attributes and derived combat values
- Physical and magical damage calculations
- Attacks, spells, blocking, and parrying
- Monster races and enemy behavior
- Login, registration, menus, settings, and match flow
- Match logging and server-side support

## Art and content direction

The art backlog describes modular character sprites and animations, including idle, run, jump, fall, hit, death, win, attacks, and spells. Planned environments include castles, mountains, forests, dungeons, deserts, caves, and ships.

## Project structure

```text
HeroTower/
├── TileDungeon/  # Godot project
└── TODO.txt      # Design and development backlog
```

## Open the project

1. Clone the repository.
2. Install a Godot version compatible with the project files.
3. Open Godot Project Manager.
4. Import the `TileDungeon/` directory.
5. Open the project and inspect its configured main scene.

The repository does not currently document a release build, complete multiplayer server setup, or export pipeline.

## Development roadmap

The [TODO.txt](TODO.txt) file is the primary source for planned gameplay, code, and art tasks.

## Current status

HeroTower should be presented as an in-development project with a design backlog. The planned modes, online features, and progression systems should not be described as released or complete without checking the current build.

## License

No `LICENSE` file is currently included. Unless a license is added, reuse and redistribution permissions are not granted by this repository.

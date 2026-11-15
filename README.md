<div align="center">

# HeroTower

**A fantasy multiplayer game project with competitive PvP and cooperative PvE modes.**

![Engine](https://img.shields.io/badge/engine-Godot-478CBF?logo=godotengine&logoColor=white)
![Genre](https://img.shields.io/badge/genre-fantasy%20action-6f42c1)
![Modes](https://img.shields.io/badge/modes-PvP%20%7C%20PvE-0A7F8C)
![Status](https://img.shields.io/badge/status-development%20project-orange)

</div>

## Overview

HeroTower is a fantasy game-development project whose planning notes describe competitive arenas, team-based boss battles, battle royale, and cooperative survival. The design also covers character equipment, weapons, spells, attributes, and combat.

The repository currently contains a Godot project directory and a development/design backlog. The modes and systems described here are planning material unless their implementation can be confirmed in the current build.

## Planned game modes

### Player versus Player

| Mode | Design outline |
|---|---|
| Battle Royale | Multiple players or teams, with one life per player |
| Boss Battle 5v5 | Two teams fight while dealing with a boss encounter |
| Arena 2v2 | Small-team elimination match |
| Arena 1v1 | Duel between two players |

### Player versus Environment

- **Invasion Survival:** cooperative survival for a small group, with escalating waves and periodic boss encounters.

The planning notes also mention rankings, recurring championships, and competitive reward structures.

## Gameplay systems

The design backlog identifies the following systems:

- Weapon and spell systems
- Armor categories and equipment slots
- Character attributes and derived combat values
- Physical and magical damage calculations
- Attacks, defensive actions, and character abilities
- Monster races and enemy behavior
- Menus, login, registration, and client settings
- Match logging and server-side support

## Art direction

The art backlog describes modular character sprites and animations, including idle, run, jump, fall, hit, death, win, attacks, and spells. Planned environments include castles, mountains, forests, dungeons, deserts, caves, and other fantasy settings.

## Repository structure

```text
.
├── TileDungeon/  # Godot project directory
└── TODO.txt      # Game design and development backlog
```

## Getting started

### Requirements

- Godot Engine compatible with the project files

### Open the project

1. Clone the repository.
2. Open Godot Project Manager.
3. Import or scan the `TileDungeon/` directory.
4. Open the project and inspect its configured main scene.

The repository does not currently document a release build or a complete server setup procedure.

## Development status

The current README reflects the available project notes and backlog. It does not imply that the listed game modes, networking features, or progression systems are fully implemented.

## License

No license file was identified in the repository. Contact the author before redistributing or reusing project materials.

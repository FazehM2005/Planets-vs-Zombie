# Plants vs. Zombies Clone

This project is a clone of the famous Plants vs. Zombies game, developed using C++ and the SFML graphics library. It was implemented as Computer Assignment #5 for the Advanced Programming course, focusing heavily on Object-Oriented Design and Event-Driven Programming.

## Features

* **Gameplay:** Tower Defense style game where players defend their home against waves of zombies across multiple parallel lanes.
* **Economy System:** Collect "Sun" currency falling from the sky or produced by Sunflowers to purchase and plant defenses.
* **Plant Varieties:**
  * **Offensive:** Peashooters, Snow Peas (which halve zombie movement speed), and Melon-pults (featuring parabolic projectile physics).
  * **Economy:** Sunflowers.
  * **Defensive:** High-health plants (like Wall-nuts) to stall zombie progression.
* **Zombie Varieties:** Includes Regular zombies and Gargantuars (with higher health and damage).
* **Dynamic Configuration:** Game mechanics such as zombie attack intensity, spawn intervals, entity health, speed, and prices can be customized via an external configuration file.
* **Audio:** Includes background music during gameplay.

## Tech Stack

* **Language:** C++ (C++20 Standard)
* **Graphics & Audio:** SFML (Simple and Fast Multimedia Library)
* **Architecture:** Multi-file project design
* **Build System:** Makefile

## How to Run

To run this game locally, ensure you have a C++ compiler and the SFML library installed on your system.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/](https://github.com/)<username>/<repository_name>.git
